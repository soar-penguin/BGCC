/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "thread_group.h"

namespace bgcc {

    ThreadGroup::ThreadGroup() {
    }

    ThreadGroup::~ThreadGroup() {
    }

    bool ThreadGroup::addThread(SharedPointer<Thread> thread) {
        try {
            _threads.push_back(thread);
        } catch(std::bad_alloc& ) {
            return false;
        }
        return true;
    }

    bool ThreadGroup::join() {
        citr_type citr;

        for (citr = _threads.begin(); citr != _threads.end(); ++citr) {
            (*citr)->join();
        }

        _threads.clear();

        return true;
    }

    size_t ThreadGroup::size() {
        return _threads.size();
    }

    bool ThreadGroup::terminateAll() {
        citr_type citr;

        for (citr = _threads.begin(); citr != _threads.end(); ++citr) {
            (*citr)->stop();
        }

        return true;
    }

}

