/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "guard.h"
#include "shareable.h"

namespace bgcc {
    typedef Guard<Mutex> ScopedGuard;

    Shareable::Shareable() : _count(0) { }

    void Shareable::inc() {
        ScopedGuard guard(&_mutex);
        ++_count;
    }

    int32_t Shareable::dec() {
        ScopedGuard guard(&_mutex);

        if (_count > 0) {
            --_count;
        }
        return _count;
    }

    int32_t Shareable::get_count() {
        ScopedGuard guard(&_mutex);
        return _count;
    }
}

