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
 * @file     java_source_writer.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月04日 12时20分24秒
 *  
 **/
#ifndef _BIDL2SL_JAVA_SOURCE_WRITER_H_
#define _BIDL2SL_JAVA_SOURCE_WRITER_H_

#include <string>
#include <fstream>
#include <iostream>
#include "common.h"
#include "source_writer.h"

class JavaSourceWriter : public SourceWriter {
public:
    JavaSourceWriter(const std::string& bidl);
    virtual ~JavaSourceWriter();

    virtual void write_header(const BidlType* bt);
    virtual void write_implement(const BidlType* bt);
public:
    virtual std::string get_class_tag()     const {
        return "class";
    }

    virtual std::string get_int8_tag()      const {
        return "byte";
    }

    virtual std::string get_int16_tag()     const {
        return "short";
    }

    virtual std::string get_int32_tag()     const {
        return "int";
    }

    virtual std::string get_int64_tag()     const {
        return "long";
    }

    virtual std::string get_boolean_tag()   const {
        return "boolean";
    }

    virtual std::string get_float_tag()     const {
        return "float";
    }

    virtual std::string get_double_tag()    const {
        return "double";
    }

    virtual std::string get_string_tag()    const {
        return "java.lang.String";
    }

    virtual std::string get_binary_tag()    const {
        return "java.lang.String";
    }

    virtual std::string get_sequence_tag()  const {
        return "std::vector";
    }

    virtual std::string get_set_tag()       const {
        return "std::set";
    }

    virtual std::string get_map_tag()       const {
        return "std::map";
    }

    virtual std::string get_const_tag()     const {
        return "const";
    }

    virtual std::string get_namespace_tag() const {
        return "namespace";
    }

    virtual std::string get_void_tag() const {
        return "void";
    }

    virtual std::string get_direction_tag(int32_t dir) const {
        if (BidlFieldDirection::IN == dir) {
            return "";
        }
        else {
            return "&";
        }
    }

    virtual std::string get_identifier_tag(const std::string& id) const;

private:
    void write_implement_recursive(const BidlType* bt);
    void output_implement_const(const BidlType* bt);
    void output_container_const_value(const BidlType* field_type, const BidlType* value, 
            int32_t level, std::string& name, std::ofstream& of);
    void output_implement_enum(const BidlType* bt);
    void output_implement_struct(const BidlType* bt);
    void output_implement_struct_function_write(const BidlType* bt, std::ofstream& of);
    void output_implement_struct_write_clause(const BidlType* bt, int32_t level,
            const std::string& field_name, std::ofstream& of, bool member = true);

    void output_implement_struct_function_read(const BidlType* bt, std::ofstream& of);
    void output_implement_struct_read_clause(const BidlType* bt, int32_t level,
            const std::string& field_name, std::ofstream& of, bool member = true);
    void output_implement_struct_function_read_from_buffer(const BidlType* bt, std::ofstream& of);
    void output_implement_struct_read_clause_from_buffer(const BidlType* bt, int32_t level,
            const std::string& field_name, std::ofstream& of, bool member = true);

    void output_implement_class(const BidlType* bt);
    void output_implement_class_interface(const BidlType* bt, int32_t level, std::ofstream& of);
    void output_implement_class_args(const BidlType* bt, int32_t level, std::ofstream& of);
    void output_implement_class_result(const BidlType* bt, int32_t level, std::ofstream& of);
    void output_implement_class_proxy(const BidlType* bt, int32_t level, std::ofstream& of);
    void output_implement_class_processor(const BidlType* bt, int32_t level, std::ofstream& of);

    /**
     * @brief mkpath 创建目录，如a/b/c
     *
     * @param name_parts
     *
     * @return 
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年09月08日 16时11分18秒
     */
    std::string mkpath(const std::vector<std::string>& name_parts);
};

#endif // _BIDL2SL_JAVA_SOURCE_WRITER_H_

