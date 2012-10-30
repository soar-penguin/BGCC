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
 * @file     cpp_source_writer.h
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月10日 13时24分33秒
 *  
 **/
#ifndef _BIDL2SL_CPP_SOURCE_WRITER_H_
#define _BIDL2SL_CPP_SOURCE_WRITER_H_

#include <string>
#include <fstream>
#include <iostream>
#include "common.h"
#include "source_writer.h"

class CppSourceWriter : public SourceWriter {
public:
    CppSourceWriter(const std::string& bidl);
    virtual ~CppSourceWriter();

    virtual void write_header(const BidlType* bt);
    virtual void write_implement(const BidlType* bt);

private:
    std::string _bidl;
    std::ofstream _f;

private:
    std::string get_bidl_base() const;
    void write_header_include();
    void write_header_include_end();
    void write_header_recursive(const BidlType* bt, int32_t level);

    void output_header_const(const BidlType* bt, int32_t level);
    void output_header_include(const BidlType* bt, int32_t level);
    void output_header_typedef(const BidlType* bt, int32_t level);
    void output_header_enum(const BidlType* bt, int32_t level);
    void output_header_struct(const BidlType* bt, int32_t level);
    void output_header_class(const BidlType* t, int32_t level);

    void output_header_class_service(const BidlClass* t, int32_t level);
    void output_header_class_args(const BidlClass* t, int32_t level);
    void output_header_class_pargs(const BidlClass* t, int32_t level);
    void output_header_class_result(const BidlClass* t, int32_t level);
    void output_header_class_presult(const BidlClass* t, int32_t level);
    void output_header_class_proxy(const BidlClass* t, int32_t level);
    void output_header_class_processor(const BidlClass* t, int32_t level);

    void write_implement_recursive(const BidlType* bt, int32_t level);

    void output_implement_const(const BidlType* bt, int32_t level);
    void output_container_const_value(const BidlType* field_type, const BidlType* value, int32_t level, std::string& name);
    void output_implement_enum(const BidlType* bt, int32_t level);
    void output_implement_struct(const BidlType* bt, int32_t level);
    void output_implement_class(const BidlType* bt, int32_t level);

    void output_implement_struct_constructor_destructor_operators(const BidlType* bt, int32_t level);
    void output_implement_struct_function_read(const BidlType* bt, int32_t level);
    void output_implement_struct_read_clause(const BidlType* bt, int32_t level, const std::string& field_name);
    void output_implement_struct_function_read_from_buffer(const BidlType* bt, int32_t level);
    void output_implement_struct_read_clause_from_buffer(const BidlType* bt, int32_t level, const std::string& field_name);
    void output_implement_struct_function_write(const BidlType* bt, int32_t level);
    void output_implement_struct_write_clause(const BidlType* bt, int32_t level, const std::string& field_name);

    void output_implement_class_args(const BidlType* t, int32_t level);
    void output_implement_class_args_read(const BidlType* bt, int32_t level, const std::string& field_name);
    void output_implement_class_pargs(const BidlType* t, int32_t level);
    void output_implement_class_pargs_write(const BidlType* bt, int32_t level, const std::string& field_name);
    void output_implement_class_result(const BidlType* t, int32_t level);
    void output_implement_class_result_write(const BidlType* bt, int32_t level, const std::string& field_name);
    void output_implement_class_presult(const BidlType* t, int32_t level);
    void output_implement_class_presult_read(const BidlType* bt, int32_t level, const std::string& field_name);

    void output_implement_class_proxy(const BidlType* t, int32_t level);
    void output_implement_class_processor(const BidlType* t, int32_t level);
public:
    virtual std::string get_class_tag()     const {
        return "class";
    }

    virtual std::string get_int8_tag()      const {
        return "int8_t";
    }

    virtual std::string get_int16_tag()     const {
        return "int16_t";
    }

    virtual std::string get_int32_tag()     const {
        return "int32_t";
    }

    virtual std::string get_int64_tag()     const {
        return "int64_t";
    }

    virtual std::string get_boolean_tag()   const {
        return "bool";
    }

    virtual std::string get_float_tag()     const {
        return "float";
    }

    virtual std::string get_double_tag()    const {
        return "double";
    }

    virtual std::string get_string_tag()    const {
        return "std::string";
    }

    virtual std::string get_binary_tag()    const {
        return "std::string";
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
};
#endif // _BIDL2SL_CPP_SOURCE_WRITER_H_

