/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "service_manager.h"
#include "log.h"
#include "guard.h"
#include "base_processor.h"

namespace bgcc {

    ServiceManager::ServiceManager() {
        add_service(SharedPointer<IProcessor>(new BaseProcessor));
    }

    int32_t ServiceManager::add_service(SharedPointer<IProcessor> processor) {
        BGCC_TRACE("bgcc", "Enter ServiceManager::add_service");
        std::string name;
        bool exist;
     
        if (processor.is_valid()) {
            name = processor->get_name();
        }
        else {
            BGCC_NOTICE("bgcc", "Failed to add service, because param is NULL");
            return -1;
        }

        BGCC_TRACE("bgcc", "Before Lock");
        Guard<Mutex> guard(&_mutex);
        if (!guard.is_locked()) {
            BGCC_WARN("bgcc", "Failed to lock mutex");
            return -1;
        }
        BGCC_TRACE("bgcc", "End Lock");

        exist = _name2service.find(name) != _name2service.end();
        if (!exist) {
            std::pair<name2service_map::iterator, bool> v =
                _name2service.insert(std::make_pair(name, processor));

            if (false == v.second) {
                return -1;
            }
        }

        return 0;
    }

    int32_t ServiceManager::remove_service(const std::string& name) {
        BGCC_TRACE("bgcc", "Enter ServiceManager::remove_service");
        Guard<Mutex> guard(&_mutex);
        if (!guard.is_locked()) {
            return -1;
        }
        name2service_map::iterator itr = _name2service.find(name);

        if (_name2service.end() != itr) {
            _name2service.erase(itr);
        }
        BGCC_TRACE("bgcc", "Leave ServiceManager::remove_service");
        return 0;
    }

    int32_t ServiceManager::remove_service(SharedPointer<IProcessor> processor) {
        //NOTE: 本函数不用加锁
        std::string name;
        if (processor.is_valid()) {
            name = processor->get_name();
        }
        else {
            return -1;
        }
        return remove_service(name);
    }

    int32_t ServiceManager::remove_all_service() {
        Guard<Mutex> guard(&_mutex);
        if (!guard.is_locked()) {
            return -1;
        }
        _name2service.clear();
        return 0;
    }

    SharedPointer<IProcessor> ServiceManager::get_service(const std::string& name) const {
        Guard<Mutex> guard(&_mutex);
        if (!guard.is_locked()) {
            return SharedPointer<IProcessor>(NULL);
        }
        name2service_map::const_iterator citr = 
            _name2service.find(name);

        if (_name2service.end() != citr) {
            return citr->second;
        }
        else {
            return SharedPointer<IProcessor>(NULL);
        }
    }

    bool ServiceManager::is_service_exist(const std::string& name) const {
        Guard<Mutex> guard(&_mutex);
        if (!guard.is_locked()) {
            return false;
        }
        return _name2service.end() != _name2service.find(name);
    }

    int32_t ServiceManager::get_service_count() const {
        Guard<Mutex> guard(&_mutex);
        if (!guard.is_locked()) {
            return -1;
        }
        return (int32_t)_name2service.size();
    }
}

