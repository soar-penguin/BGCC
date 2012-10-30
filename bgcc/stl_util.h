/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_STLUTIL_H_
#define _BGCC_STLUTIL_H_

#include <math.h>

namespace bgcc {
    template <typename CheckedContainer, typename ResultContainer, typename Predicate>
        void xremove_if(CheckedContainer& checkedContainer, ResultContainer& resultContainer, Predicate predicate) {
            typedef typename CheckedContainer::iterator iterator;
            iterator first = checkedContainer.begin();
            iterator last = checkedContainer.end();

            while (first != last) {
                if (predicate(*first)) {
                    resultContainer.push_back(first->second.ticketId);
                    checkedContainer.erase(first++);
                } else {
                    ++first;
                }
            }
        }

    template <typename Map>
        class TimedoutPredicate {
        public:
            bool operator()(const typename Map::value_type& value) {
                time_t storeTime = value.second.storeTime;
                time_t now = time(NULL);

                double delta = fabs(difftime(storeTime, now));
                double interval = 60;

                //TODO: get interval from GlobalConf

                if (delta > interval) {
                    return true;
                } else {
                    return false;
                }
            }
        };
}
#endif

