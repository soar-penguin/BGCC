/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "thread_manager.h"

namespace bgcc {

    SharedPointer<Thread> ThreadManager::createThread(SharedPointer<Runnable> pr) {
        SharedPointer<Thread> t(new Thread(pr));
        bool bOk = t->start();
        return bOk ? t : SharedPointer<Thread>(NULL);
    }

}

