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
 * @file     source_writer.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月10日 14时03分42秒
 *  
 **/
#ifndef _BIDL2SL_SOURCE_WRITER_H_
#define _BIDL2SL_SOURCE_WRITER_H_

#include <string>
#include <stdint.h>

class BidlType;

class SourceWriter {
public:
    virtual ~SourceWriter(){ };
    /**
     * @brief make_source_writer 工厂方法
     * 根据目标语言生成SourceWriter子类对象
     *
     * @param bidl 目标语言，可选值为cpp和java。
     * 如果bidl非法，则在标准输出上给出错误提示，并退出程序。
     *
     * @return SourceWriter子类对象指针
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月28日 17时26分01秒
     */
    static SourceWriter* make_source_writer(const std::string& bidl);

    /**
     * @brief write_header 输出目标语言代码的头文件
     *
     * @param bt 经BidlParser解释后的BidlType类型指针
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月28日 17时28分46秒
     */
    virtual void write_header(const BidlType* bt) = 0;

    /**
     * @brief write_implement 输出目标语言代码的实现文件
     *
     * @param bt 经BidlParser解释后的BidlType类型指针
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月28日 17时30分00秒
     */
    virtual void write_implement(const BidlType* bt) = 0;

    virtual std::string get_class_tag()     const = 0;
    virtual std::string get_int8_tag()      const = 0;
    virtual std::string get_int16_tag()     const = 0;
    virtual std::string get_int32_tag()     const = 0;
    virtual std::string get_int64_tag()     const = 0;
    virtual std::string get_boolean_tag()   const = 0;
    virtual std::string get_float_tag()     const = 0;
    virtual std::string get_double_tag()    const = 0;
    virtual std::string get_string_tag()    const = 0;
    virtual std::string get_binary_tag()    const = 0;
    virtual std::string get_sequence_tag()  const = 0;
    virtual std::string get_set_tag()       const = 0;
    virtual std::string get_map_tag()       const = 0;
    virtual std::string get_const_tag()     const = 0;
    virtual std::string get_namespace_tag() const = 0;
    virtual std::string get_void_tag() const = 0;
    virtual std::string get_direction_tag(int32_t dir) const = 0;
    virtual std::string get_identifier_tag(const std::string& id) const = 0;

protected:
    static std::string get_indent(int level);
};
#endif // _BIDL2SL_SOURCE_WRITER_H_

