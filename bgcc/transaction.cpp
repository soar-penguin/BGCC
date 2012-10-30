/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <iostream>
#include <vector>

#include "transaction.h"
#include "protocol.h"
#include "transport.h"
#include "time_util.h"
#include "guard.h"
#include "peer_info.h"
#include "bgcc_error.h"
#include "server_peer_socket.h"
#include "stl_util.h"
#include "log.h"

namespace bgcc {

    class IntervalClearRunner : public Runnable {
        public:
            IntervalClearRunner(Transaction* parent) : _parent(parent) {
            }

            virtual int32_t operator()(void*) {
                while (true) {
                    TimeUtil::safe_sleep_s(60);
                    _parent->intervalClear();
                }
                return 0;
            }
        private:
            Transaction *_parent;
    };

    Transaction* Transaction::get_instance() {
        static Transaction trans;
        return &trans;
    }

    Transaction::Transaction() : _counter(0) {
        SharedPointer<Runnable> runner(new IntervalClearRunner(this));
        _intervalClearThread = SharedPointer<Thread>(new Thread(runner));
        _intervalClearThread->start();
    }

    Transaction::~Transaction() {
        if (_intervalClearThread.is_valid()) {
            _intervalClearThread->stop();
        }
    }

    TicketIdType Transaction::getTicketId(ProtocolSharedPointer protocol, ThreadIdType threadId, std::string funcName) {
        std::string ip;
        PortType port;
        int32_t errCode;

        errCode = getIpAndPort(protocol, ip, port);
        if (0 != errCode) {
            return 0;
        } else {
            return _getTicketId(ip, port, threadId, funcName);
        }
    }

    TicketIdType Transaction::getCurrentTicketId(ProtocolSharedPointer protocol, ThreadIdType threadId, std::string funcName) {
        
        static Mutex mutex;
        Guard<Mutex> guard(&mutex);



        std::string ip;
        PortType port;
        int32_t errCode;

        errCode = getIpAndPort(protocol, ip, port);
        if (0 != errCode) {
            return 0;
        } else {
            return _getCurrentTicketId(ip, port, threadId, funcName);
        }
    }

    int32_t Transaction::getIpAndPort(ProtocolSharedPointer protocol, std::string& ip, PortType& port) {
        typedef SharedPointer<ITransport> TransportSharedPointer;
        typedef SharedPointer<PeerInfo> PeerInfoSharedPointer;

        if (!protocol.is_valid()) {
            return E_BGCC_NULL_POINTER;
        }

        TransportSharedPointer trans = protocol->getTransport();

        if (!trans.is_valid()) {
            return E_BGCC_NULL_POINTER;
        } 


        ServerPeerSocket *serverPeerSocket = dynamic_cast<ServerPeerSocket*>(trans.get());
		if (NULL == serverPeerSocket) {
			return E_BGCC_NULL_POINTER;
		}

        PeerInfoSharedPointer peerInfo = serverPeerSocket->GetPeerInfo();
        if (!peerInfo.is_valid()) {
            return E_BGCC_NULL_POINTER;
        }

        ip = peerInfo->GetHost();
        port = peerInfo->GetPort();

        return 0;
    }

    TicketIdType Transaction::_getTicketId(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName) {
        TicketMapKeyType key;
        TicketKey2TicketValueMap::iterator itr;
        TicketIdType ticketId;

        key = makeKey(ip, port, threadId, funcName);
        ticketId = getNextTicketId();

        {

            /** 将key与ticketId的对应关系更新或加入，以在getCurrentTicketId中使用 */
            typedef Guard<Mutex> ScopedMutex;
            ScopedMutex guard(&_mutex);
			if (guard.is_locked()) {
				itr = _tickets.find(key);

				if (_tickets.end() != itr) {
					itr->second.ticketId = ticketId;
				} else {
					TicketMapValueType value;
					value.ticketId = ticketId;
					value.storeTime = time(NULL);

					_tickets.insert(std::make_pair(key, value));
				}
			}
        }

        return ticketId;

    }

    TicketIdType Transaction::_getCurrentTicketId(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName) {
        bool bFind = false;
        TicketIdType ticketId;
        TicketMapKeyType key;
        TicketKey2TicketValueMap::const_iterator citr;

        key = makeKey(ip, port, threadId, funcName);
        {
            typedef Guard<Mutex> ScopedMutex;
            ScopedMutex guard(&_mutex);

            citr = _tickets.find(key);
            if (_tickets.end() != citr) {
                ticketId = citr->second.ticketId;
                bFind = true;
            }
        }

        if (!bFind) {
            ticketId = _getTicketId(ip, port, threadId, funcName);
        }

        return ticketId;
    }

    TicketIdType Transaction::getNextTicketId() {
        typedef Guard<Mutex> ScopedMutex;

        ScopedMutex guard(&_mutex);
        return ++_counter;
    }


    TicketMapKeyType Transaction::makeKey(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName) {
        TicketMapKeyType key;

        key.ip = ip;
        key.port = port;
        key.threadId = threadId;
        key.funcName = funcName;

        return key;
    }


    int32_t Transaction::retrieveDataCopyByTicketId(TicketIdType ticketId, void** data, int32_t& size) {
        TicketId2DataMap::const_iterator citr;
        typedef Guard<Mutex> ScopedMutex;

        ScopedMutex guard(&_mutex);
        citr = _data.find(ticketId);
        if (_data.end() != citr) {
            return citr->second->get_data_copy(data, size);
        } else {
            return -1;
        }
    }

    int32_t Transaction::saveDataByTicketId(TicketIdType ticketId, void* data, int32_t size) {
        TicketId2DataMap::iterator itr;
        typedef Guard<Mutex> ScopedMutex;
        int32_t ret;
        SharedPointer<NBDataBuffer> d(new NBDataBuffer);

        ret = d->append(data, size);
        if (0 != ret) {
            return ret;
        }

        ScopedMutex guard(&_mutex);
        itr = _data.find(ticketId);
        if (_data.end() != itr) {
            itr->second = d;
        } else {
            _data.insert(std::make_pair(ticketId, d));
        }
        return 0;
    }

    int32_t Transaction::intervalClear() {
        std::vector<TicketIdType> timedoutTicketIds;
        std::vector<TicketIdType>::iterator timedoutTicketIdsItr;

        typedef Guard<Mutex> ScopedMutex;
        ScopedMutex guard(&_mutex);

        xremove_if(_tickets, timedoutTicketIds, TimedoutPredicate<TicketKey2TicketValueMap>());

        for (timedoutTicketIdsItr = timedoutTicketIds.begin();
                timedoutTicketIdsItr != timedoutTicketIds.end();
                ++timedoutTicketIdsItr) {
            _data.erase(*timedoutTicketIdsItr);
        }

        return 0;
    }

    bool operator<(const TicketMapKeyType& lhs, const TicketMapKeyType& rhs) {
        if (lhs.ip != rhs.ip) {
            return lhs.ip < rhs.ip;
        } else if (lhs.port != rhs.port) {
            return lhs.port < rhs.port;
        } else if (lhs.threadId != rhs.threadId) {
            return lhs.threadId < rhs.threadId;
        } else {
            return lhs.funcName < rhs.funcName;
        }   
    }   
}
