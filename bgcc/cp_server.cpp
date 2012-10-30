/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifdef _WIN32

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <string.h>
#include <sstream>
#include <iostream>

#include "time_util.h"
#include "cp_server.h"
#include "binary_protocol.h"
#include "server_task.h"
#include "log.h"
#include "connection_manager.h"
#include "sema.h"

namespace bgcc {

	class CClientContext {
	private:
		OVERLAPPED      *m_pol;
		WSABUF          *m_pwbuf;
		int             m_nTotalBytes;
		int             m_nOKBytes;
		SOCKET          m_Socket;
		int             m_nOpCode;
		char*	        m_szBuffer;
		int             m_nBufferLen;

	public:
		enum {
			S_READ_HRAD,
			S_READ_BODY
		};

		void SetOpCode(int n) {
			m_nOpCode = n;
		}

		int GetOpCode() {
			return m_nOpCode;
		}

		void SetTotalBytes(int n) {
			m_nTotalBytes = n;
		}

		int GetTotalBytes() {
			return m_nTotalBytes;
		}

		void SetOKBytes(int n) {
			m_nOKBytes = n;
		}

		void IncrOKBytes(int n) {
			m_nOKBytes += n;
		}

		int GetOKBytes() {
			return m_nOKBytes;
		}

		void SetSocket(SOCKET s) {
			m_Socket = s;
		}

		SOCKET GetSocket() {
			return m_Socket;
		}

		void SetBuffer(int size) {
			if (m_szBuffer) {
				delete[] m_szBuffer;
			}
			m_szBuffer = new char[size];
			m_nBufferLen = size;
			ZeroBuffer();
		}

		void GetBuffer(char *szBuffer) {
			strcpy(szBuffer, m_szBuffer);
		}

		char* GetBuffer() {
			return m_szBuffer;
		}

		void ZeroBuffer() {
			ZeroMemory(m_szBuffer, m_nBufferLen);
		}

		void SetWSABUFLength(int nLength) {
			m_pwbuf->len = nLength;
		}

		int GetWSABUFLength() {
			return m_pwbuf->len;
		}

		WSABUF* GetWSABUFPtr() {
			return m_pwbuf;
		}

		OVERLAPPED* GetOVERLAPPEDPtr() {
			return m_pol;
		}

		void ResetWSABUF() {
			m_pwbuf->buf = m_szBuffer;
			m_pwbuf->len = m_nBufferLen;
		}

		int GetBufferLen() {
			return m_nBufferLen;
		}

		CClientContext() {
			m_pol = new OVERLAPPED;
			m_pwbuf = new WSABUF;

			ZeroMemory(m_pol, sizeof(OVERLAPPED));

			m_Socket =  SOCKET_ERROR;

			m_szBuffer = NULL;
			m_nBufferLen = 0;

			m_pwbuf->buf = NULL;
			m_pwbuf->len = 0;

			m_nOpCode = S_READ_HRAD;
			m_nTotalBytes = 0;
			m_nOKBytes = 0;
		}

		~CClientContext()
		{
			delete m_pol;
			delete m_pwbuf;

			if (m_szBuffer) {
				delete[] m_szBuffer;
			}
		}
	};

	static bool associate_with_iocp(CClientContext* Contex, CpServer* server) {
		HANDLE hTemp = CreateIoCompletionPort((HANDLE)Contex->GetSocket(), 
			server->get_iocp(), (ULONG_PTR)Contex, 0);

		if (NULL == hTemp) {
			return false;
		}
		else {
			return true;
		}
	}

	static void accept_connection(SOCKET ListenSocket, CpServer* server) {
		sockaddr_in ClientAddress;
		int nClientLength = sizeof(ClientAddress);

		SOCKET Socket = accept(ListenSocket, (sockaddr*)&ClientAddress, &nClientLength);
		int32_t tv = 5000;
        setsockopt(Socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(int32_t));

		if (INVALID_SOCKET == Socket) {
			return;
		}

		CClientContext* context = new CClientContext();
		context->SetSocket(Socket);

		if (true == associate_with_iocp(context, server))
		{
			WSABUF *p_wbuf = context->GetWSABUFPtr();
			OVERLAPPED *p_ol = context->GetOVERLAPPEDPtr();
			context->SetBuffer(20);
			context->SetTotalBytes(20);
			context->ResetWSABUF();

			//Get data.
			DWORD dwFlags = 0;
			DWORD dwBytes = 0;

			int nBytesRecv = WSARecv(context->GetSocket(), p_wbuf, 1, 
				&dwBytes, &dwFlags, p_ol, NULL);
		}
	}

	static DWORD WINAPI accept_thread_func(LPVOID lParam)
	{
		CpServer* server = (CpServer*)lParam;
		SOCKET ListenSocket = server->get_listen_socket();
		HANDLE shutdown_event = server->get_shutdown_event();
		WSAEVENT accept_event = server->get_accept_event();

		WSANETWORKEVENTS WSAEvents;

		while(WAIT_OBJECT_0 != WaitForSingleObject(shutdown_event, 0))
		{
			if (WSA_WAIT_TIMEOUT != WSAWaitForMultipleEvents(1, &accept_event, FALSE, 100, FALSE))
			{
				WSAEnumNetworkEvents(ListenSocket, accept_event, &WSAEvents);
				if ((WSAEvents.lNetworkEvents & FD_ACCEPT) && (0 == WSAEvents.iErrorCode[FD_ACCEPT_BIT]))
				{
					accept_connection(ListenSocket, server);
				}
			}
		}

		return 0;
	}

	static void enroll_proxy(const std::string& proxy_name, socket_t fd) {
		BGCC_TRACE("bgcc", "enroll_proxy name %s, %d", proxy_name.c_str(), fd);
        bgcc::ConnectionManager::get_instance()->enroll(proxy_name, fd);
    }

	static DWORD WINAPI worker_thread(LPVOID lpParam) {
		CpServer* server = (CpServer*)lpParam;

		void *lpContext = NULL;
		OVERLAPPED       *pOverlapped = NULL;
		CClientContext   *pClientContext = NULL;
		DWORD            dwBytesTransfered = 0;
		int nBytesRecv = 0;
		int nBytesSent = 0;
		DWORD             dwBytes = 0, dwFlags = 0;

		while (WAIT_OBJECT_0 != WaitForSingleObject(server->get_shutdown_event(), 0)) {
			BOOL bReturn = GetQueuedCompletionStatus(
				server->get_iocp(),
				&dwBytesTransfered,
				(LPDWORD)&lpContext,
				&pOverlapped,
				INFINITE);

			BGCC_TRACE("bgcc", "got a status");

			if (NULL == lpContext) {	//Òì³£´¦Àí
				BGCC_DEBUG("bgcc", "contest is null");
				break;
			}

			pClientContext = (CClientContext *)lpContext;
			WSABUF *p_wbuf = pClientContext->GetWSABUFPtr();
			OVERLAPPED *p_ol = pClientContext->GetOVERLAPPEDPtr();

			if ((FALSE == bReturn) || ((TRUE == bReturn) && (0 == dwBytesTransfered))) {
				closesocket(pClientContext->GetSocket());
				delete pClientContext;
				BGCC_DEBUG("bgcc", "GetQueuedCompletionStatus end");
				continue;
			}

			BGCC_DEBUG("bgcc", "dwBytesTransfered : %d", dwBytesTransfered);
			pClientContext->IncrOKBytes(dwBytesTransfered);

			if (pClientContext->GetOKBytes() < pClientContext->GetTotalBytes()) {
				p_wbuf->buf = pClientContext->GetBuffer() + pClientContext->GetOKBytes();
				p_wbuf->len = pClientContext->GetBufferLen() - pClientContext->GetOKBytes();

				BGCC_DEBUG("bgcc", "read %s again, ok: %d, total: %d", (pClientContext->GetOpCode() == CClientContext::S_READ_HRAD ?
					"head" : "body"), pClientContext->GetOKBytes(), pClientContext->GetTotalBytes());
				dwFlags = 0;
				nBytesRecv = WSARecv(pClientContext->GetSocket(), p_wbuf, 1, 
					&dwBytes, &dwFlags, p_ol, NULL);
				if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
				{
					closesocket(pClientContext->GetSocket());
					delete pClientContext;
				}
				continue;
			}

			if (pClientContext->GetOpCode() == CClientContext::S_READ_HRAD) {
				pClientContext->SetOpCode(CClientContext::S_READ_BODY);
				char* phead = pClientContext->GetBuffer();
				int32_t ndata = (int32_t)ntohl(*(uint32_t*)(phead + 16));
				BGCC_DEBUG("bgcc", "ndata: %d", ndata);

				pClientContext->SetBuffer(ndata);
				pClientContext->SetTotalBytes(ndata);
				pClientContext->SetOKBytes(0);

                pClientContext->ResetWSABUF();

                dwFlags = 0;
                nBytesRecv = WSARecv(pClientContext->GetSocket(), p_wbuf, 1, 
                        &dwBytes, &dwFlags, p_ol, NULL);
                if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
                {
                    closesocket(pClientContext->GetSocket());
                    delete pClientContext;
                }

                continue;
            }

			BGCC_DEBUG("bgcc", "op code :%d", pClientContext->GetOpCode());
			char* szBuffer = pClientContext->GetBuffer();

			char* p_item_data = szBuffer;
			int32_t processor_name_len = (int32_t)ntohl(*(uint32_t*)(p_item_data));
			BGCC_DEBUG("bgcc", "processor_name_len: %d", processor_name_len);
			std::string processor_name(p_item_data + 4, processor_name_len);
			
			if (processor_name == "bgcc::BaseProcessor_enroll") {
				int32_t func_name_len = (int32_t)ntohl(*(uint32_t*)(
					p_item_data + 4 + processor_name_len + 8));
				
				int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)(
					p_item_data + 4 + processor_name_len + 8
					+ 4 + func_name_len));

				std::string proxy_name(p_item_data + 4 + processor_name_len + 8
					+ 4 + func_name_len + 4, proxy_name_len);
				
				enroll_proxy(proxy_name, pClientContext->GetSocket());
				continue;
			}
			SharedPointer<IProcessor> processor = server->get_service_manager()->get_service(processor_name);
			if (processor.is_valid()) {
				BGCC_TRACE("bgcc", "create a task. processor name %s", processor_name.c_str());
				SharedPointer<ITransport> trans(new ServerPeerSocket(pClientContext->GetSocket()));
				SharedPointer<IProtocol> proto(new BinaryProtocol(trans));
				int32_t body_size = pClientContext->GetTotalBytes();
				char* p = (char*)bgcc::Mempool::get_instance()->get_mem_block(body_size);
				memmove(p, p_item_data, body_size);
				BGCC_DEBUG("bgcc", "server body size %d", body_size);
				SharedPointer<Runnable> task(new ServerTask(processor, p, body_size, proto));
				server->get_thread_pool()->addTask(task);
			}
			else {
				BGCC_TRACE("bgcc", "Cannot find processor `%s`. Try to find ._baseservice_2012", processor_name.c_str());
				processor = server->get_service_manager()->get_service("._baseservice_2012");
				if (processor.is_valid()) {
					BGCC_TRACE("bgcc", "find ._baseservice_2012");
					SharedPointer<BinaryProtocol> bp(new BinaryProtocol(SharedPointer<ITransport>(NULL)));

					bp->writeMessageBegin("xx", "__service_not_found", bgcc::CALL, 0); 
					bp->writeInt32(0);
					bp->writeString("__service_not_found");
					bp->writeBool(false);

					NBDataBuffer* db = bp->get_data_buffer();

					void* data = NULL;
					int32_t size;
					db->get_data(&data, size);

					char* p = (char*)bgcc::Mempool::get_instance()->get_mem_block(size - 20);
					memmove(p, ((char*)data) + 20, size - 20);

					SharedPointer<ITransport> trans(new ServerPeerSocket(pClientContext->GetSocket()));
					SharedPointer<IProtocol> proto(new BinaryProtocol(trans));
					SharedPointer<Runnable> task(new ServerTask(processor, p, size - 20, proto));
					server->get_thread_pool()->addTask(task);
				}   
			}   

			pClientContext->SetBuffer(20);
			pClientContext->SetTotalBytes(20);
			pClientContext->ResetWSABUF();
			pClientContext->SetOKBytes(0);
			pClientContext->SetOpCode(CClientContext::S_READ_HRAD);

			DWORD dwFlags = 0;
			DWORD dwBytes = 0;
			int nBytesRecv = WSARecv(pClientContext->GetSocket(), p_wbuf, 1, 
				&dwBytes, &dwFlags, p_ol, NULL);
			if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
			{
				closesocket(pClientContext->GetSocket());
				delete pClientContext;
				continue;
			}
		}
		return 0;
	}

	CpServer::CpServer(ServiceManager* service_manager,
		ThreadPool* thread_pool,
		uint16_t port,
		const std::string& node) 
		:_service_manager(service_manager),
		_thread_pool(thread_pool),
		_port(port),
		_state(S_UNINIT),
		_hiocp(NULL),
		_haccept_thread(NULL),
		_hshutdown_event(NULL),
		_node(node)
	{
	}

	int32_t CpServer::init() {
#ifndef _WIN32
        signal(SIGPIPE, SIG_IGN);
#endif
		if (S_UNINIT != _state) {
			return E_BGCC_SERVER_ALREADY_INIT;
		}

		WSADATA wsaData;

		int ret;
		ret = WSAStartup(MAKEWORD(2,2), &wsaData);
		if (NO_ERROR != ret) {
			return -1;
		}

		ret = init_iocp();
		if (0 != ret) {
			return -1;
		}

		_hshutdown_event = CreateEvent(NULL, TRUE, FALSE, NULL);

		_state = S_INIT;
		return 0;
	}

	int32_t CpServer::init_iocp() {
		_hiocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0 );

		if ( NULL == _hiocp) {
			return -1;
		}

		DWORD nThreadID;

		CreateThread(0, 0, worker_thread, (void *)this, 0, &nThreadID);

		return 0;
	}

	int32_t CpServer::socket_init() {
		struct sockaddr_in ServerAddress;

		_listen_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

		if (INVALID_SOCKET == _listen_socket) {
			return -1;
		}
		
		ZeroMemory((char *)&ServerAddress, sizeof(ServerAddress));

		ServerAddress.sin_family = AF_INET;
		ServerAddress.sin_addr.s_addr = inet_addr(_node.c_str());
		ServerAddress.sin_port = htons(_port);

		if (SOCKET_ERROR == bind(_listen_socket, (struct sockaddr *) &ServerAddress, sizeof(ServerAddress))) {
			closesocket(_listen_socket);
			return -1;
		}

		if (SOCKET_ERROR == listen(_listen_socket, SOMAXCONN)) {
			closesocket(_listen_socket);
			return -1;
		}

		_haccept_event = WSACreateEvent();
		if (WSA_INVALID_EVENT == _haccept_event) {
			return -1;
		}

		if (SOCKET_ERROR == WSAEventSelect(_listen_socket, _haccept_event, FD_ACCEPT)) {
			WSACloseEvent(_haccept_event);
			return -1;
		}

		DWORD nThreadID;
		_haccept_thread = CreateThread(0, 0, accept_thread_func, (void *)this, 0, &nThreadID);
		return 0;
	}

	int32_t CpServer::serve() {
		int32_t ret;
		if (0 != (ret = init())) {
			return ret;
		}

		if (S_INIT != _state) {
			return E_BGCC_SERVER_NEED_INIT;
		}

		ret = socket_init();
		if (0 != ret) {
			return E_BGCC_SERVER_CREATE_LISTENFD_FAILED;
		}

		WaitForSingleObject(_haccept_thread, INFINITE);

		_state = S_SERVE;
		return 0;
	}

	SOCKET CpServer::get_listen_socket() {
		return _listen_socket;
	}

	WSAEVENT CpServer::get_accept_event() {
		return _haccept_event;
	}

	HANDLE CpServer::get_shutdown_event(){
		return _hshutdown_event;
	}

	int32_t CpServer::stop() {
		if (S_SERVE != _state) {
			return -1;
		}

		SetEvent(_hshutdown_event);

		if (INVALID_SOCKET != _listen_socket) {
			closesocket(_listen_socket);
			_listen_socket = INVALID_SOCKET;
		}

		return 0;
	}

	HANDLE CpServer::get_iocp() {
		return _hiocp;
	}

	ServiceManager* CpServer::get_service_manager() {
		return _service_manager;
	}

	ThreadPool* CpServer::get_thread_pool() {
		return _thread_pool;
	}
}

#endif  //_WIN32
