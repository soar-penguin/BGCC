/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

/**
 * @file     bidl_field_direction.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月10日 10时39分30秒
 *  
 **/
#ifndef _BIDL2SL_FIELD_DIRECTION_H_
#define _BIDL2SL_FIELD_DIRECTION_H_

#include "bidl_type.h"

class BidlFieldDirection : public BidlType {
public:
    enum {
        IN,
        OUT,
        ALL
    };

    BidlFieldDirection() : BidlType(), _direction(IN) {
        _type_id = FIELDDIRECTION;
    }

    virtual ~BidlFieldDirection() {
    }

    virtual std::string get_tag() const {
        switch(_direction) {
        case IN:
            return "[in]";
            break;
        case OUT:
            return "[out]";
            break;
        case ALL:
            return "[all]";
            break;
        default:
            return "unknown direction";
        }
    }

    virtual std::string get_tag(const SourceWriter* sw) const {
        return sw->get_direction_tag(_direction);
    }

    void set_direction(int direction) {
        _direction = direction;
    }

    int get_direction() const {
        return _direction;
    }

    bool is_in() const {
        return IN == _direction;
    }

    bool is_out() const {
        return OUT == _direction;
    }

    bool is_all() const {
        return ALL == _direction;
    }

private:
    int _direction;
};
#endif // _BIDL2SL_FIELD_DIRECTION_H_

