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
 * @file     bidl_map.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月09日 16时22分13秒
 *  
 **/
#ifndef _BIDL2SL_MAP_H_
#define _BIDL2SL_MAP_H_

#include "bidl_type.h"

class BidlMap : public BidlType {
    public:
        BidlMap() : BidlType(), _key_type(NULL), _value_type(NULL) {
            _type_id = MAP;
        }

        virtual ~BidlMap() {
            if (_key_type) {
                delete _key_type;
            }

            if (_value_type) {
                delete _value_type;
            }
        }

        virtual std::string get_tag(const SourceWriter* sw) const {
            std::string str;
            str.append(sw->get_map_tag());
            str.append("<");
            if (_key_type) {
                str.append(_key_type->get_tag(sw));
            }
            str.append(", ");
            if (_value_type) {
                str.append((_value_type->get_tag(sw)));
            }
            str.append("> ");
            return str;
        }

        void set_key_type(BidlType* bt) {
            _key_type = bt;
        }

        void set_value_type(BidlType* bt) {
            _value_type = bt;
        }

        const BidlType* get_key_type() const {
            return _key_type;
        }

        const BidlType* get_value_type() const {
            return _value_type;
        }

        virtual std::string get_bgcc_type_name(const std::string& lang = "cpp") const {
            if ("cpp" == lang) {
                return "bgcc::IDMAP";
            }
            else {
                return "DataType.IDMAP";
            }
        }

        /**
         * @brief get_return_type_name 
         * 返回在生成Java代码时，本类型作为返回值类型的字符串表示
         *
         * @return 类型字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年09月08日 14时32分23秒
         */
        virtual std::string get_return_type_name() const {
            std::string str;
            str.append("Map<");
            if (_key_type) {
                str.append(_key_type->get_real_type()->get_general_type_name());
            }
            else {
                str.append("null");
            }
            str.append(", ");
            if (_value_type) {
                str.append(_value_type->get_real_type()->get_general_type_name());
            }
            else {
                str.append("null");
            }
            str.append(">");
            return str;
        }

        /**
         * @brief get_parameter_type_name 
         * 返回在生成Java代码时，本类型作为参数类型的字符串表示
         *
         * @return 类型字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年09月08日 14时37分33秒
         */
        virtual std::string get_parameter_type_name() const {
            return get_return_type_name();
        }

        /**
         * @brief get_general_type_name 
         * 返回在生成Java代码时，本类型作为泛型类型的字符串表示
         *
         * @return 类型字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年09月08日 14时38分19秒
         */
        virtual std::string get_general_type_name() const {
            return get_return_type_name();
        }

        /**
         * @brief get_holder_type_name 
         * 返回在生成Java代码时，本类型作为传出类型的字符串表示
         *
         * @return 类型字符串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年09月08日 14时45分41秒
         */
        virtual std::string get_holder_type_name() const {
            std::string str;
            str.append("Holder<");
            str.append(this->get_return_type_name());
            str.append(">");
            return str;
        }

        /**
         * @brief get_init_clause 
         * 返回在生成Java代码时，本类型的初始化语句
         *
         * @return 类型初始化语句
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年09月08日 14时41分00秒
         */
        virtual std::string get_init_clause() const {
            std::string str;
            str.append("new HashMap<");
            if (_key_type) {
                str.append(_key_type->get_real_type()->get_general_type_name());
            }
            else {
                str.append("null");
            }
            str.append(", ");
            if (_value_type) {
                str.append(_value_type->get_real_type()->get_general_type_name());
            }
            else {
                str.append("null");
            }
            str.append(">()");
            return str;
        }
    private:
        BidlType* _key_type;
        BidlType* _value_type;
};

#endif // _BIDL2SL_MAP_H_

