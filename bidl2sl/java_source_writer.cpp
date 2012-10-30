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
 * @file     java_source_writer.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月04日 12时21分11秒
 *  
 **/

#include <sys/stat.h>
#include <sys/types.h>
#include <iomanip>
#include "util.h"
#include "java_source_writer.h"

JavaSourceWriter::JavaSourceWriter(const std::string& bidl) {
}

JavaSourceWriter::~JavaSourceWriter() {
}

void JavaSourceWriter::write_header(const BidlType* bt) {
    //do nothing. Java代码不需要创建头文件
}

void JavaSourceWriter::write_implement(const BidlType* bt) {
    if (!bt) {
        return;
    }

    if (!GlobalParser::is_dir_exist(g_parser.get_outdir())) {
        mkdir(g_parser.get_outdir().c_str(), 0777);
    }
    write_implement_recursive(bt);
}

void JavaSourceWriter::write_implement_recursive(const BidlType* bt) {
    if (!bt) {
        return;
    }

    const BidlNamespace* ns = dynamic_cast<const BidlNamespace*>(bt);
    if (!ns) {
        return;
    }

    const std::vector<BidlType*>&children = ns->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        switch((*citr)->get_type_id()) {
        case BidlType::CONST:
            output_implement_const(*citr);
            break;
        case BidlType::STRUCT:
            output_implement_struct(*citr);
            break;
        case BidlType::ENUM:
            output_implement_enum(*citr);
            break;
        case BidlType::NAMESPACE:
            write_implement_recursive(*citr);
            break;
        case BidlType::CLASS:
            output_implement_class(*citr);
            break;
        default:
            break;
        }
    }
}

void JavaSourceWriter::output_implement_class(const BidlType* bt) {
    const BidlClass* t = dynamic_cast<const BidlClass*>(bt);
    if (!t) {
        return;
    }

    std::string class_name = bt->get_name();
    std::vector<std::string> name_parts;
    split_string(bt->_symtab_name, ".", name_parts);
    if (name_parts.size() < 2) {
        return;
    }

    std::string fullpath = mkpath(name_parts);

    std::string package_clause;
    std::vector<std::string>::const_iterator citr;
    citr = name_parts.begin() + 1; //filter "global"
    if (name_parts.size() > 2) {
        package_clause.append("package ");
    }

    for (; citr != name_parts.end() - 1; ++citr) {
        package_clause.append(*citr);
        if (citr != name_parts.end() - 2) {
            package_clause.append(".");
        }
    }
    
    if (name_parts.size() > 2) {
        package_clause.append(";\n");
    }

    //output class
    std::ofstream of((fullpath + class_name + ".java").c_str());
    if (!of.is_open()) {
        myerror("open %s failed", fullpath.c_str());
        return;
    }
    of << package_clause << "\n";

    of << "import bgcc.*;\n";
    of << "import java.util.*;\n\n";
    of << "public class " << class_name << " {\n\n";

    output_implement_class_interface(bt, 1, of);
    output_implement_class_args(bt, 1, of);
    output_implement_class_result(bt, 1, of);
    output_implement_class_proxy(bt, 1, of);
    output_implement_class_processor(bt, 1, of);

    of << "}\n\n";
}

void JavaSourceWriter::output_implement_class_processor(const BidlType* bt, int32_t level, std::ofstream& of) {
    if (!bt) {
        return;
    }

    of << get_indent(level) << "public static class Processor extends BaseProcessor {\n\n";
    //constructor
    of << get_indent(level + 1) << "public Processor(Intf intf) {\n";
    of << get_indent(level + 2) << "_intf = intf;\n";
    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    //output functoins
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        of << get_indent(level + 2) << "_processMap.put(\"" << f->get_name() << "\", new " << f->get_name() << "());\n";
    }
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public java.lang.String getName() {\n";
    of << get_indent(level + 2) << "return \"" << bt->_symtab_name << "\";\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "private Intf _intf;\n\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }

        of << get_indent(level + 1) << "private class " << f->get_name() << " implements ProcessFunction {\n";
        of << get_indent(level + 2) << "public int process(long request, int request_len, Protocol out,\n";
        of << get_indent(level + 3) << "java.lang.String fname, int seqid) {\n";
        of << get_indent(level + 3) << "int ret;\n";
        of << get_indent(level + 3) << "int nread = 0;\n\n";
        of << get_indent(level + 3) << "StringHolder xxHolder = new StringHolder();\n";
        of << get_indent(level + 3) << "ret = out.readString(request + nread, request_len - nread, xxHolder);\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 3) << "nread += ret;\n";
        of << "\n";
        of << get_indent(level + 3) << f->get_name() << "_args args = new " << f->get_name() << "_args();\n";
        of << get_indent(level + 3) << "ret = args.read(out, request + nread, request_len - nread);\n";
        of << get_indent(level + 3) << "out.readMessageEnd();\n";
        of << "\n";
        of << get_indent(level + 3) << f->get_name() << "_result result = new " << f->get_name() << "_result();\n";

        of << get_indent(level + 3);

        if (!return_type->is_void()) {
            of << "result.return_value.value = ";
        }
        of << "_intf." << f->get_name() << "(";
        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction() ||
                     (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                of << "args." << ff->get_name() << ".value";
            }
            else if (ff->get_field_direction() && 
                    (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                of << "args." << ff->get_name();
            }
            else if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                      || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                of << "result." << ff->get_name();
            }

            if (citr2 + 1 != children.end()) {
                of << ", ";
            }
        }
        of << ");\n";

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction() && 
                    (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                of << get_indent(level + 3) << "result." << ff->get_name() << " = args." << ff->get_name() << ";\n";
            }
        }

        of << get_indent(level + 3) << "out.writeMessageBegin(\""
            << bt->_symtab_name << "\", \"" << f->get_name() << "\", bgcc.MessageType.REPLY, 0);\n";
        of << get_indent(level + 3) << "result.write(out);\n";
        of << get_indent(level + 3) << "out.writeMessageEnd();\n";
        of << get_indent(level + 3) << "return 0;\n";
        of << get_indent(level + 2) << "}\n";
        of << get_indent(level + 1) << "}\n";
    }
    of << get_indent(level) << "}\n\n";
}

void JavaSourceWriter::output_implement_class_proxy(const BidlType* bt, int32_t level, std::ofstream& of) {
    if (!bt) {
        return;
    }

    of << get_indent(level) << "public static class Proxy extends BaseProxy {\n";
    of << get_indent(level + 1) << "public Proxy(ServerInfo serverInfo) {\n";
    of << get_indent(level + 2) << "super(serverInfo);\n";
    of << get_indent(level + 2) << "setWhoAmI(\"" + bt->_symtab_name << "\");\n";
    of << get_indent(level + 1) << "}\n\n";

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    //output functoins
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }

        //output function with last = false
        of << get_indent(level + 1) << "public "
            << return_type->get_return_type_name() << " "
            << f->get_name() << "(";
        //args
        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            if (b_in) {
                of << ftype->get_real_type()->get_return_type_name();
            }
            else {
                of << ftype->get_real_type()->get_holder_type_name();
            }

            of << " " << ff->get_name();
            if (citr2 + 1 != children.end()) {
                of << ", ";
            }
        }

        of << ") {\n";

        of << get_indent(level + 2);
        if (!f->get_return_type()->is_void()) {
            of << "return ";
        }
        of << "this." << f->get_name() << "(";

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            of << ff->get_name() << ", ";
        }
        of << "false);\n";

        of << get_indent(level + 1) << "}\n\n";

        //output function
        of << get_indent(level + 1) << "public "
            << return_type->get_return_type_name() << " "
            << f->get_name() << "(";
        //args
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            if (b_in) {
                of << ftype->get_real_type()->get_return_type_name();
            }
            else {
                of << ftype->get_real_type()->get_holder_type_name();
            }

            of << " " << ff->get_name() << ", ";
        }

        of << "boolean last) {\n";

        if (!return_type->is_void()) {
            of << get_indent(level + 2) << return_type->get_real_type()->get_return_type_name() 
                << " return_value = " << return_type->get_real_type()->get_init_clause() << ";\n";
        }

        of << get_indent(level + 2) << "IntHolder seqHolder = new IntHolder(0);\n";
        of << get_indent(level + 2) << "Protocol protocol = getProtocol();\n";
        of << get_indent(level + 2) << "if (protocol == null) { return ";
        if (!f->get_return_type()->is_void()) {
            of << "return_value";
        }
        of << ";}\n";

        of << "\n";
        of << get_indent(level + 2) << "int ret = getTicketId(\""
            << f->get_name() << "\", seqHolder, last, protocol, protocol);\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ";
        if (!f->get_return_type()->is_void()) {
            of << "return_value";
        }
        of << ";}\n";


        //call send_*
        of << get_indent(level + 2) << "send_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }
            of << ff->get_name();

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                of << ".value";
            }

            of << ", ";
        }
        of << "seqHolder.value, protocol);\n";

        //call recv_*

        of << get_indent(level + 2);
        if (!f->get_return_type()->is_void()) {
            of << "return_value = ";
        }
        of << "recv_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                of << ff->get_name() << ", ";
            }
        }
        of << "protocol);\n";

        of << get_indent(level + 2) << "putProtocol(protocol);\n";

        if (!f->get_return_type()->is_void()) {
            of << get_indent(level + 2) << "return return_value;\n";
        }

        of << get_indent(level + 1) << "}\n\n";

        //send function
        of << get_indent(level + 1) <<  "void send_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }
            of << ftype->get_real_type()->get_return_type_name() << " " << ff->get_name() << ", ";
        }
        of << "int seqid, Protocol protocol) {\n";
        of << get_indent(level + 2) << "protocol.writeMessageBegin(getWhoAmI(), \""
            << f->get_name() << "\", bgcc.MessageType.CALL, seqid);\n";

        of << get_indent(level + 2) << "protocol.writeString(getName());\n";
        of << get_indent(level + 2) << f->get_name() << "_args args = new " << f->get_name() << "_args();\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }
            of << get_indent(level + 2) << "args." << ff->get_name() << ".value = " << ff->get_name() << ";\n";
        }

        of << get_indent(level + 2) << "args.write(protocol);\n";
        of << get_indent(level + 2) << "protocol.writeMessageEnd();\n";
        of << get_indent(level + 1) <<  "}\n\n";

        //recv function
        of << get_indent(level + 1);
        if (!return_type->is_void()) {
            of << return_type->get_real_type()->get_return_type_name();
        }
        else {
            of << "void";
        }

        of << " recv_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                of << ftype->get_real_type()->get_holder_type_name() << " " << ff->get_name() << ", ";
            }
        }
        of << "Protocol protocol) {\n";
        of << get_indent(level + 2) << "StringHolder fname = new StringHolder();\n";
        of << get_indent(level + 2) << "IntHolder seqid = new IntHolder();\n";
        of << get_indent(level + 2) << "MessageTypeHolder msgtype= new MessageTypeHolder();\n";
        of << "\n";
        of << get_indent(level + 2) << "protocol.readMessageBegin(fname, msgtype, seqid);\n";
        of << "\n";
        of << get_indent(level + 2) << f->get_name() << "_result _result = new " << f->get_name() << "_result();\n";
        of << get_indent(level + 2) << "_result.read(protocol);\n";
        of << get_indent(level + 2) << "protocol.readMessageEnd();\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                of << get_indent(level + 2) << ff->get_name() << ".value = _result." << ff->get_name() << ".value;\n";
            }
        }

        if (!return_type->is_void()) {
            of << get_indent(level + 2) << "return _result.return_value.value;\n";
        }
        of << get_indent(level + 1) <<  "}\n\n";
    }
    of << get_indent(level) << "}\n";
}

void JavaSourceWriter::output_implement_class_result(const BidlType* bt, int32_t level, std::ofstream& of) {
    if (!bt) {
        return;
    }

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }

        std::string class_name = f->get_name() + "_result";

        of << get_indent(level) << "public static class "
            << class_name << " {\n\n";

        if (!f->get_return_type()->is_void()) {
            of << get_indent(level + 1) << "public " << return_type->get_real_type()->get_holder_type_name() << " return_value;\n\n";
        }

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction() && 
                    ((dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                    ||(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()
                    )) {

                of << get_indent(level + 1) << "public "
                    << ftype->get_real_type()->get_holder_type_name()
                    << " " << ff->get_name() << ";\n";
            }
        }

        of << get_indent(level + 1) << "public " << class_name
            << "() {\n";
        if (!f->get_return_type()->is_void()) {
            of << get_indent(level + 2) << "return_value = new " << return_type->get_real_type()->get_holder_type_name() << "();\n";
        }
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction() && 
                    ((dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                    ||(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()
                    )) {
                of << get_indent(level + 2) << "this." << ff->get_name()
                    << " = new "
                    << ftype->get_real_type()->get_holder_type_name()
                    << "();\n";
            }
        }
        of << get_indent(level + 1) << "}\n\n";
        
        //write
        of << get_indent(level + 1) << "public int write(Protocol protocol) {\n";
        of << get_indent(level + 2) << "int ret = 0;\n";
        of << get_indent(level + 2) << "ret = protocol.writeStructBegin(\"" << class_name << "\");\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";

        if (!return_type->is_void()) {
            of << get_indent(level + 2) << "ret = protocol.writeFieldBegin(\"return_value\", ";
            
            of << return_type->get_real_type()->get_bgcc_type_name("java");
            of << ", 0);\n";
            of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";

            output_implement_struct_write_clause(return_type->get_real_type(), level + 2, "return_value", of);

            of << get_indent(level + 2) << "ret = protocol.writeFieldEnd();\n";
            of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";
        }

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction() && 
                    ((dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                    ||(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()
                    )) {
                of << get_indent(level + 2) << "ret = protocol.writeFieldBegin(\"" << ff->get_name() << "\", ";
                of << ftype->get_real_type()->get_bgcc_type_name("java");
                of << ", " << (citr2 - children.begin() + 1) << ");\n";
                of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";

                output_implement_struct_write_clause(ftype->get_real_type(), level + 2, ff->get_name(), of);

                of << get_indent(level + 2) << "ret = protocol.writeFieldEnd();\n";
                of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";
            }
        }
        of << get_indent(level + 2) << "ret = protocol.writeFieldStop();\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";
        of << get_indent(level + 2) << "return protocol.writeStructEnd();\n"; 
        of << get_indent(level + 1) << "}\n\n";

        //read
        of << get_indent(level + 1) << "public int read(Protocol protocol) {\n";
        of << get_indent(level + 2) << "int ret = 0;\n";
        of << get_indent(level + 2) << "StringHolder fname = new StringHolder();\n";
        of << get_indent(level + 2) << "DataTypeHolder ftype = new DataTypeHolder();\n";
        of << get_indent(level + 2) << "IntHolder fid = new IntHolder();\n";

        of << "\n";
        of << get_indent(level + 2) << "ret = protocol.readStructBegin(fname);\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";

        of << "\n";
        of << get_indent(level + 2) << "while (true) {\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldBegin(fname, ftype, fid);\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n\n";
        of << get_indent(level + 3) << "if (ftype.value == DataType.IDSTOP) {\n";
        of << get_indent(level + 4) << "break;\n";
        of << get_indent(level + 3) << "}\n";

        of << "\n";
        of << get_indent(level + 3) << "switch(fid.value) {\n";

        if (!return_type->is_void()) {
            of << get_indent(level + 3) << "case " << "0:\n";
            output_implement_struct_read_clause(return_type->get_real_type(), level + 4, "return_value", of);
            of << get_indent(level + 3) << "break;\n";
        }

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction() && 
                    ((dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                    ||(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()
                    )) {
                of << get_indent(level + 3) << "case " << (citr2 - children.begin() + 1) << ":\n";
                output_implement_struct_read_clause(ftype->get_real_type(), level + 4, ff->get_name(), of);
                of << get_indent(level + 4) << "break;\n";

            }
        }
        of << get_indent(level + 3) << "}\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldEnd();\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 2) << "}\n\n";
        of << get_indent(level + 2) << "return protocol.readStructEnd();\n";
        of << get_indent(level + 1) << "}\n\n";

        //read from buffer
        of << get_indent(level + 1) << "public int read(Protocol protocol, long request, int request_len) {\n";
        of << get_indent(level + 2) << "int ret = 0;\n";
        of << get_indent(level + 2) << "int nread = 0;\n";
        of << get_indent(level + 2) << "StringHolder fname = new StringHolder();\n";
        of << get_indent(level + 2) << "DataTypeHolder ftype = new DataTypeHolder();\n";
        of << get_indent(level + 2) << "IntHolder fid = new IntHolder();\n";

        of << "\n";
        of << get_indent(level + 2) << "ret = protocol.readStructBegin(request + nread, request_len - nread, fname);\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 2) << "nread += ret;\n";

        of << "\n";
        of << get_indent(level + 2) << "while (true) {\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldBegin(request + nread, request_len - nread, fname, ftype, fid);\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 3) << "nread += ret;\n\n";
        of << get_indent(level + 3) << "if (ftype.value == DataType.IDSTOP) {\n";
        of << get_indent(level + 4) << "break;\n";
        of << get_indent(level + 3) << "}\n";

        of << "\n";
        of << get_indent(level + 3) << "switch(fid.value) {\n";

        if (!return_type->is_void()) {
            of << get_indent(level + 3) << "case " << "0:\n";
            output_implement_struct_read_clause_from_buffer(return_type->get_real_type(), level + 4, "return_value", of);
            of << get_indent(level + 3) << "break;\n";
        }

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction() && 
                    ((dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                    ||(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()
                    )) {
                of << get_indent(level + 3) << "case " << (citr2 - children.begin() + 1) << ":\n";
                output_implement_struct_read_clause_from_buffer(ftype->get_real_type(), level + 4, ff->get_name(), of);
                of << get_indent(level + 4) << "break;\n";

            }
        }
        of << get_indent(level + 3) << "}\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldEnd();\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 2) << "}\n\n";
        of << get_indent(level + 2) << "return protocol.readStructEnd();\n";
        of << get_indent(level + 1) << "}\n\n";

        of << get_indent(level) << "}\n\n";

    }
}

void JavaSourceWriter::output_implement_class_args(const BidlType* bt, int32_t level, std::ofstream& of) {
    if (!bt) {
        return;
    }

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }

        std::string class_name = f->get_name() + "_args";

        of << get_indent(level) << "public static class "
            << class_name << " {\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }

            of << get_indent(level + 1) << "public "
                << ftype->get_real_type()->get_holder_type_name()
                << " " << ff->get_name() << ";\n";
        }

        of << get_indent(level + 1) << "public " << f->get_name()
            << "_args() {\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }
            of << get_indent(level + 2) << "this." << ff->get_name()
                << " = new "
                << ftype->get_real_type()->get_holder_type_name()
                << "();\n";
        }
        of << get_indent(level + 1) << "}\n\n";

        //write
        of << get_indent(level + 1) << "public int write(Protocol protocol) {\n";
        of << get_indent(level + 2) << "int ret = 0;\n";
        of << get_indent(level + 2) << "ret = protocol.writeStructBegin(\"" << class_name << "\");\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }
            of << get_indent(level + 2) << "ret = protocol.writeFieldBegin(\"" << ff->get_name() << "\", ";
            of << ftype->get_real_type()->get_bgcc_type_name("java");
            of << ", " << (citr2 - children.begin() + 1) << ");\n";
            of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";

            output_implement_struct_write_clause(ftype->get_real_type(), level + 2, ff->get_name(), of);

            of << get_indent(level + 2) << "ret = protocol.writeFieldEnd();\n";
            of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";
        }
        of << get_indent(level + 2) << "ret = protocol.writeFieldStop();\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";
        of << get_indent(level + 2) << "return protocol.writeStructEnd();\n\n";

        of << get_indent(level + 1) << "}\n\n";

        //read
        of << get_indent(level + 1) << "public int read(Protocol protocol) {\n";
        of << get_indent(level + 2) << "int ret = 0;\n";
        of << get_indent(level + 2) << "StringHolder fname = new StringHolder();\n";
        of << get_indent(level + 2) << "DataTypeHolder ftype = new DataTypeHolder();\n";
        of << get_indent(level + 2) << "IntHolder fid = new IntHolder();\n";

        of << "\n";
        of << get_indent(level + 2) << "ret = protocol.readStructBegin(fname);\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";

        of << "\n";
        of << get_indent(level + 2) << "while (true) {\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldBegin(fname, ftype, fid);\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n\n";
        of << get_indent(level + 3) << "if (ftype.value == DataType.IDSTOP) {\n";
        of << get_indent(level + 4) << "break;\n";
        of << get_indent(level + 3) << "}\n";

        of << "\n";
        of << get_indent(level + 3) << "switch(fid.value) {\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }
            of << get_indent(level + 3) << "case " << (citr2 - children.begin() + 1) << ":\n";
            output_implement_struct_read_clause(ftype->get_real_type(), level + 4, ff->get_name(), of);
            of << get_indent(level + 4) << "break;\n";
        }
        of << get_indent(level + 3) << "}\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldEnd();\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 2) << "}\n\n";
        of << get_indent(level + 2) << "return protocol.readStructEnd();\n";
        of << get_indent(level + 1) << "}\n\n";

        //read from buffer
        of << get_indent(level + 1) << "public int read(Protocol protocol, long request, int request_len) {\n";
        of << get_indent(level + 2) << "int ret = 0;\n";
        of << get_indent(level + 2) << "int nread = 0;\n";
        of << get_indent(level + 2) << "StringHolder fname = new StringHolder();\n";
        of << get_indent(level + 2) << "DataTypeHolder ftype = new DataTypeHolder();\n";
        of << get_indent(level + 2) << "IntHolder fid = new IntHolder();\n";

        of << "\n";
        of << get_indent(level + 2) << "ret = protocol.readStructBegin(request + nread, request_len - nread, fname);\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 2) << "nread += ret;\n";

        of << "\n";
        of << get_indent(level + 2) << "while (true) {\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldBegin(request + nread, request_len - nread, fname, ftype, fid);\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 3) << "nread += ret;\n\n";
        of << get_indent(level + 3) << "if (ftype.value == DataType.IDSTOP) {\n";
        of << get_indent(level + 4) << "break;\n";
        of << get_indent(level + 3) << "}\n";

        of << "\n";
        of << get_indent(level + 3) << "switch(fid.value) {\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }
            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }
            of << get_indent(level + 3) << "case " << (citr2 - children.begin() + 1) << ":\n";
            output_implement_struct_read_clause_from_buffer(ftype->get_real_type(), level + 4, ff->get_name(), of);
            of << get_indent(level + 4) << "break;\n";
        }
        of << get_indent(level + 3) << "}\n";
        of << get_indent(level + 3) << "ret = protocol.readFieldEnd();\n";
        of << get_indent(level + 3) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 3) << "nread += ret;\n\n";
        of << get_indent(level + 2) << "}\n\n";
        of << get_indent(level + 2) << "ret = protocol.readStructEnd();\n";
        of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level + 2) << "nread += ret;\n\n";
        of << get_indent(level + 2) << "return nread;\n";
        of << get_indent(level + 1) << "}\n\n";

        of << get_indent(level) << "}\n\n";
    }
}

void JavaSourceWriter::output_implement_class_interface(const BidlType* bt, int32_t level, std::ofstream& of) {
    if (!bt) {
        return;
    }

    of << get_indent(level) << "public interface Intf {\n";

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }

        of << get_indent(level + 1) << "public "
            << return_type->get_return_type_name() << " "
            << f->get_name() << "(";

        //args
        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            if (b_in) {
                of << ftype->get_real_type()->get_return_type_name();
            }
            else {
                of << ftype->get_real_type()->get_holder_type_name();
            }

            of << " " << ff->get_name();
            if (citr2 + 1 != children.end()) {
                of << ", ";
            }
        }

        of << ");\n";
    }
    of << get_indent(level) << "}\n\n";
}

void JavaSourceWriter::output_implement_struct(const BidlType* bt) {
    if (!bt) {
        return;
    }

    const BidlStruct* e = dynamic_cast<const BidlStruct*>(bt);
    if (!e) {
        return;
    }

    std::string class_name = bt->get_name();
    std::string holder_name = class_name + "Holder";

    std::vector<std::string> name_parts;
    split_string(bt->_symtab_name, ".", name_parts);
    if (name_parts.size() < 2) {
        return;
    }

    std::string fullpath = mkpath(name_parts);

    std::string package_clause;
    std::vector<std::string>::const_iterator name_parts_citr;
    name_parts_citr = name_parts.begin() + 1; //filter "global"
    if (name_parts.size() > 2) {
        package_clause.append("package ");
    }

    for (; name_parts_citr != name_parts.end() - 1; ++name_parts_citr) {
        package_clause.append(*name_parts_citr);
        if (name_parts_citr != name_parts.end() - 2) {
            package_clause.append(".");
        }
    }
    
    if (name_parts.size() > 2) {
        package_clause.append(";\n");
    }
    //output Holder
    std::ofstream of((fullpath + holder_name + ".java").c_str());
    if (!of.is_open()) {
        myerror("open %s failed", fullpath.c_str());
        return;
    }

    int32_t level = 0;
    of << package_clause;

    of << "public final class " << holder_name << " {\n\n";
    of << get_indent(level + 1) << "public " << holder_name << "() {\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public " << holder_name << "(" << class_name << " value) {\n";
    of << get_indent(level + 2) << "this.value = value;\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public " << class_name << " value;\n";

    of << "}\n\n";
    of.close();

    //struct
    of.open((fullpath + class_name + ".java").c_str());
    if (!of.is_open()) {
        myerror("open %s failed", fullpath.c_str());
        return;
    }

    of << package_clause << "\n\n";

    of << "import bgcc.*;\n";
    of << "import java.util.*;\n\n";
    of << "public class " << class_name << " {\n\n";

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        of << get_indent(level + 1) << "protected " 
            << f->get_field_type()->get_real_type()->get_holder_type_name()
            << " " << f->get_name() << ";\n";
    }

    of << "\n";
    of << get_indent(level + 1) << "public " << class_name << "() {\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        of << get_indent(level + 2) << "this." << f->get_name() << " = "
            << "new " << f->get_field_type()->get_real_type()->get_holder_type_name()
            << "();\n";
    }
    of << get_indent(level + 1) << "}\n\n";

    of << "\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }

        std::string r_name = f->get_field_type()->get_real_type()->get_return_type_name();
        std::string p_name = f->get_field_type()->get_real_type()->get_parameter_type_name();

        of << get_indent(level + 1) << "public " << r_name << " get" << get_java_identifier(f->get_name()) << "() {\n";
        of << get_indent(level + 2) << "return this." << f->get_name() << ".value;\n";
        of << get_indent(level + 1) << "}\n\n";

        of << get_indent(level + 1) << "public void set" << get_java_identifier(f->get_name())
            << "(" << p_name << " " << f->get_name() << ") {\n";
        of << get_indent(level + 2) << "this." << f->get_name() << ".value = " << f->get_name() << ";\n";
        of << get_indent(level + 1) << "}\n\n";
    }

    output_implement_struct_function_write(bt, of);
    output_implement_struct_function_read(bt, of);
    output_implement_struct_function_read_from_buffer(bt, of);

    of << "}\n\n";
}

void JavaSourceWriter::output_implement_struct_function_read_from_buffer(const BidlType* bt, std::ofstream& of) {
    if (!bt) {
        return;
    }

    const BidlStruct* e = dynamic_cast<const BidlStruct*>(bt);
    if (!e) {
        return;
    }
    std::string class_name = bt->get_name();

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    int level = 1;
    of << get_indent(level) << "public int read(Protocol protocol, long request, int request_len) {\n";
    of << get_indent(level + 1) << "int ret = 0;\n";
    of << get_indent(level + 1) << "int nread = 0;\n";
    of << get_indent(level + 1) << "StringHolder fname = new StringHolder();\n";
    of << get_indent(level + 1) << "DataTypeHolder ftype = new DataTypeHolder();\n";
    of << get_indent(level + 1) << "IntHolder fid = new IntHolder();\n";

    of << "\n";
    of << get_indent(level + 1) << "ret = protocol.readStructBegin(request + nread, request_len - nread, fname);\n";
    of << get_indent(level + 1) << "if (ret < 0) { return ret; }\n";
    of << get_indent(level + 1) << "nread += ret;\n";

    of << "\n";
    of << get_indent(level + 1) << "while (true) {\n";
    of << get_indent(level + 2) << "ret = protocol.readFieldBegin(request + nread, request_len - nread, fname, ftype, fid);\n";
    of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n";
    of << get_indent(level + 2) << "nread += ret;\n\n";
    of << get_indent(level + 2) << "if (ftype.value == DataType.IDSTOP) {\n";
    of << get_indent(level + 3) << "break;\n";
    of << get_indent(level + 2) << "}\n";
    
    of << "\n";
    of << get_indent(level + 2) << "switch(fid.value) {\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        of << get_indent(level + 2) << "case " << f->get_field_id() << ":\n";
        output_implement_struct_read_clause_from_buffer(f->get_field_type()->get_real_type(), level + 3, f->get_name(), of);
        of << get_indent(level + 3) << "break;\n";
    }
    of << get_indent(level + 2) << "}\n";
    of << get_indent(level + 1) << "}\n\n";
    
    of << get_indent(level + 1) << "ret = protocol.readFieldEnd();\n";
    of << get_indent(level + 1) << "if (ret < 0) { return ret; }\n";
    of << get_indent(level + 1) << "nread += ret;\n";
    of << get_indent(level + 1) << "return nread;\n";
    of << get_indent(level) << "}\n\n";
}

void JavaSourceWriter::output_implement_struct_function_read(const BidlType* bt, std::ofstream& of) {
    if (!bt) {
        return;
    }

    const BidlStruct* e = dynamic_cast<const BidlStruct*>(bt);
    if (!e) {
        return;
    }
    std::string class_name = bt->get_name();

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    int level = 1;
    of << get_indent(level) << "public int read(Protocol protocol) {\n";
    of << get_indent(level + 1) << "int ret = 0;\n";
    of << get_indent(level + 1) << "StringHolder fname = new StringHolder();\n";
    of << get_indent(level + 1) << "DataTypeHolder ftype = new DataTypeHolder();\n";
    of << get_indent(level + 1) << "IntHolder fid = new IntHolder();\n";

    of << "\n";
    of << get_indent(level + 1) << "ret = protocol.readStructBegin(fname);\n";
    of << get_indent(level + 1) << "if (ret < 0) { return ret; }\n";

    of << "\n";
    of << get_indent(level + 1) << "while (true) {\n";
    of << get_indent(level + 2) << "ret = protocol.readFieldBegin(fname, ftype, fid);\n";
    of << get_indent(level + 2) << "if (ret < 0) { return ret; }\n\n";
    of << get_indent(level + 2) << "if (ftype.value == DataType.IDSTOP) {\n";
    of << get_indent(level + 3) << "break;\n";
    of << get_indent(level + 2) << "}\n";
    
    of << "\n";
    of << get_indent(level + 2) << "switch(fid.value) {\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        of << get_indent(level + 2) << "case " << f->get_field_id() << ":\n";
        output_implement_struct_read_clause(f->get_field_type()->get_real_type(), level + 3, f->get_name(), of);
        of << get_indent(level + 3) << "break;\n";
    }
    of << get_indent(level + 2) << "}\n";
    of << get_indent(level + 1) << "}\n\n";
    
    of << get_indent(level + 1) << "return protocol.readFieldEnd();\n";
    of << get_indent(level) << "}\n\n";
}

void JavaSourceWriter::output_implement_struct_read_clause_from_buffer(const BidlType* bt, int32_t level,
        const std::string& field_name, std::ofstream& of, bool member) {
    if (!bt) {
        return;
    }

    switch(bt->get_type_id()) {
    case BidlType::BOOLEAN:
        of << get_indent(level) << "ret = protocol.readBool(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::INT8:
        of << get_indent(level) << "ret = protocol.readByte(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::INT16:
        of << get_indent(level) << "ret = protocol.readShort(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::INT32:
        of << get_indent(level) << "ret = protocol.readInt(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::INT64:
        of << get_indent(level) << "ret = protocol.readLong(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::FLOAT:
        of << get_indent(level) << "ret = protocol.readFloat(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::STRING:
        of << get_indent(level) << "ret = protocol.readString(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::BINARY:
        of << get_indent(level) << "ret = protocol.readBinary(request + nread, request_len - nread, ";
        if (member) {
            of << "this.";
        }
        of << field_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::ENUM:
        {
        std::string tmp_enum_var_name = "ele_" + g_parser.get_tmp_var();
        of << get_indent(level) << "IntHolder " << tmp_enum_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "ret = protocol.readInt(request + nread, request_len - nread, "
            << tmp_enum_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        of << get_indent(level) << field_name << ".value = "
            << bt->get_return_type_name() << ".findByValue(" << tmp_enum_var_name
            << ".value);\n";
        }
        break;
    case BidlType::STRUCT:
        of << get_indent(level) << field_name
            << ".value = new " << bt->get_return_type_name() << "();\n";
        of << get_indent(level) << "ret = " << field_name
            << ".value.read(protocol, request + nread, request_len - nread);\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        break;
    case BidlType::SET:
        {
        const BidlSet* bidl_set = dynamic_cast<const BidlSet*>(bt);
        if (!bidl_set) {
            return;
        }

        const BidlType* sub_type = bidl_set->get_sub_type();
        if (!sub_type) {
            return;
        }

        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        of << get_indent(level) << "IntHolder " << set_size_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "DataTypeHolder " << ele_var_name
            << " = new DataTypeHolder();\n\n";
        of << get_indent(level) << "ret = protocol.readSetBegin(request + nread, request_len - nread, "
            << ele_var_name << ", " << set_size_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";

        std::string var_i = "i" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (int " << var_i << " = 0; " << var_i << " < "
            << set_size_var_name << ".value; ++" << var_i << ") {\n";

        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        of << get_indent(level + 1) << sub_type->get_real_type()->get_holder_type_name() << " "
            << value_value_var_name << " = new " << sub_type->get_real_type()->get_holder_type_name()
            << "();\n";
        output_implement_struct_read_clause_from_buffer(sub_type->get_real_type(), level + 1,
                value_value_var_name, of, false);
        of << get_indent(level + 1) << "if (" << field_name << ".value == null) {\n";
        of << get_indent(level + 2) << field_name << ".value = " << bt->get_init_clause() << ";\n";
        of << get_indent(level + 1) << "}\n";
        of << get_indent(level + 1) << field_name << ".value.add(" << value_value_var_name << ".value);\n";

        of << get_indent(level) << "}\n";

        of << get_indent(level) << "ret = protocol.readSetEnd();\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";

        }
        break;
    case BidlType::SEQUENCE: {
        const BidlSequence* bidl_sequence = dynamic_cast<const BidlSequence*>(bt);
        if (!bidl_sequence) {
            return;
        }

        const BidlType* sub_type = bidl_sequence->get_sub_type();
        if (!sub_type) {
            return;
        }

        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        of << get_indent(level) << "IntHolder " << set_size_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "DataTypeHolder " << ele_var_name
            << " = new DataTypeHolder();\n\n";
        of << get_indent(level) << "ret = protocol.readListBegin(request + nread, request_len - nread, "
            << ele_var_name << ", " << set_size_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";

        std::string var_i = "i" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (int " << var_i << " = 0; " << var_i << " < "
            << set_size_var_name << ".value; ++" << var_i << ") {\n";

        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        of << get_indent(level + 1) << sub_type->get_real_type()->get_holder_type_name() << " "
            << value_value_var_name << " = new " << sub_type->get_real_type()->get_holder_type_name()
            << "();\n";
        output_implement_struct_read_clause_from_buffer(sub_type->get_real_type(), level + 1,
                value_value_var_name, of, false);
        of << get_indent(level + 1) << "if (" << field_name << ".value == null) {\n";
        of << get_indent(level + 2) << field_name << ".value = " << bt->get_init_clause() << ";\n";
        of << get_indent(level + 1) << "}\n";
        of << get_indent(level + 1) << field_name << ".value.add(" << value_value_var_name << ".value);\n";

        of << get_indent(level) << "}\n";

        of << get_indent(level) << "ret = protocol.readListEnd();\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";
        }
        break;
    case BidlType::MAP:
        {
        const BidlMap* bidl_map = dynamic_cast<const BidlMap*>(bt);
        if (!bidl_map) {
            return;
        }

        const BidlType* key_type = bidl_map->get_key_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = bidl_map->get_value_type();
        if (!value_type) {
            return;
        }

        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string key_var_name = "key_" + g_parser.get_tmp_var();
        std::string value_var_name = "vlaue_" + g_parser.get_tmp_var();

        of << get_indent(level) << "IntHolder " << set_size_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "DataTypeHolder " << key_var_name
            << " = new DataTypeHolder();\n\n";
        of << get_indent(level) << "DataTypeHolder " << value_var_name
            << " = new DataTypeHolder();\n\n";

        of << get_indent(level) << " ret = protocol.readMapBegin(request + nread, request_len - nread, "
            << key_var_name << ", " << value_var_name << ", "
            << set_size_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "nread += ret;\n";

        std::string var_i = "i" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (int " << var_i << " = 0; " << var_i << " < "
            << set_size_var_name << ".value; ++" << var_i << ") {\n";

        std::string key_value_var_name = "key_" + g_parser.get_tmp_var();
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        of << get_indent(level + 1) << key_type->get_real_type()->get_holder_type_name() << " "
            << key_value_var_name << " = new " << key_type->get_real_type()->get_holder_type_name()
            << "();\n";
        of << get_indent(level + 1) << value_type->get_real_type()->get_holder_type_name() << " "
            << value_value_var_name << " = new " << value_type->get_real_type()->get_holder_type_name()
            << "();\n";
        output_implement_struct_read_clause_from_buffer(key_type->get_real_type(), level + 1,
                key_value_var_name, of, false);
        output_implement_struct_read_clause_from_buffer(value_type->get_real_type(), level + 1,
                value_value_var_name, of, false);

        of << get_indent(level + 1) << "if (" << field_name << ".value == null) {\n";
        of << get_indent(level + 2) << field_name << ".value = " << bt->get_init_clause() << ";\n";
        of << get_indent(level + 1) << "}\n";
        of << get_indent(level + 1) << field_name << ".value.put("
            << key_value_var_name << ".value, "
            << value_value_var_name << ".value);\n";

        of << get_indent(level) << "ret = protocol.readMapEnd();\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "}\n";
        }
        break;
    default:
        break;
    }
}

void JavaSourceWriter::output_implement_struct_read_clause(const BidlType* bt, int32_t level,
        const std::string& field_name, std::ofstream& of, bool member) {
    if (!bt) {
        return;
    }

    switch(bt->get_type_id()) {
    case BidlType::BOOLEAN:
        of << get_indent(level) << "ret = protocol.readBool(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::INT8:
        of << get_indent(level) << "ret = protocol.readByte(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::INT16:
        of << get_indent(level) << "ret = protocol.readShort(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::INT32:
        of << get_indent(level) << "ret = protocol.readInt(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::INT64:
        of << get_indent(level) << "ret = protocol.readLong(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::FLOAT:
        of << get_indent(level) << "ret = protocol.readFloat(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::STRING:
        of << get_indent(level) << "ret = protocol.readString(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::BINARY:
        of << get_indent(level) << "ret = protocol.readBinary(";
        if (member) {
            of << "this." << field_name << ");\n";
        }
        else {
            of << field_name << ");\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::ENUM:
        {
        std::string tmp_enum_var_name = "ele_" + g_parser.get_tmp_var();
        of << get_indent(level) << "IntHolder " << tmp_enum_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "ret = protocol.readInt(" << tmp_enum_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << field_name << ".value = "
            << bt->get_return_type_name() << ".findByValue(" << tmp_enum_var_name
            << ".value);\n";
        }
        break;
    case BidlType::STRUCT:
        of << get_indent(level) << field_name
            << ".value = new " << bt->get_return_type_name() << "();\n";
        of << get_indent(level) << "ret = " << field_name
            << ".value.read(protocol);\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::SET:
        {
        const BidlSet* bidl_set = dynamic_cast<const BidlSet*>(bt);
        if (!bidl_set) {
            return;
        }

        const BidlType* sub_type = bidl_set->get_sub_type();
        if (!sub_type) {
            return;
        }

        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        of << get_indent(level) << "IntHolder " << set_size_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "DataTypeHolder " << ele_var_name
            << " = new DataTypeHolder();\n\n";
        of << get_indent(level) << " ret = protocol.readSetBegin("
            << ele_var_name << ", " << set_size_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";

        std::string var_i = "i" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (int " << var_i << " = 0; " << var_i << " < "
            << set_size_var_name << ".value; ++" << var_i << ") {\n";

        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();

        of << get_indent(level + 1) << sub_type->get_real_type()->get_holder_type_name() << " "
            << value_value_var_name << " = new " << sub_type->get_real_type()->get_holder_type_name()
            << "();\n";

        output_implement_struct_read_clause(sub_type->get_real_type(), level + 1,
                value_value_var_name, of, false);
        of << get_indent(level + 1) << "if (" << field_name << ".value == null) {\n";
        of << get_indent(level + 2) << field_name << ".value = " << bt->get_init_clause() << ";\n";
        of << get_indent(level + 1) << "}\n";
        of << get_indent(level + 1) << field_name << ".value.add(" << value_value_var_name << ".value);\n";


        of << get_indent(level) << "}\n";

        of << get_indent(level) << "ret = protocol.readSetEnd();\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";

        }
        break;
    case BidlType::SEQUENCE:
        {
        const BidlSequence* bidl_sequence = dynamic_cast<const BidlSequence*>(bt);
        if (!bidl_sequence) {
            return;
        }

        const BidlType* sub_type = bidl_sequence->get_sub_type();
        if (!sub_type) {
            return;
        }

        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        of << get_indent(level) << "IntHolder " << set_size_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "DataTypeHolder " << ele_var_name
            << " = new DataTypeHolder();\n\n";
        of << get_indent(level) << " ret = protocol.readListBegin("
            << ele_var_name << ", " << set_size_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";

        std::string var_i = "i" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (int " << var_i << " = 0; " << var_i << " < "
            << set_size_var_name << ".value; ++" << var_i << ") {\n";

        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();

        of << get_indent(level + 1) << sub_type->get_real_type()->get_holder_type_name() << " "
            << value_value_var_name << " = new " << sub_type->get_real_type()->get_holder_type_name()
            << "();\n";

        output_implement_struct_read_clause(sub_type->get_real_type(), level + 1,
                value_value_var_name, of, false);
        of << get_indent(level + 1) << "if (" << field_name << ".value == null) {\n";
        of << get_indent(level + 2) << field_name << ".value = " << bt->get_init_clause() << ";\n";
        of << get_indent(level + 1) << "}\n";
        of << get_indent(level + 1) << field_name << ".value.add(" << value_value_var_name << ".value);\n";


        of << get_indent(level) << "}\n";

        of << get_indent(level) << "ret = protocol.readListEnd();\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        }
        break;
    case BidlType::MAP:
        {
        const BidlMap* bidl_map = dynamic_cast<const BidlMap*>(bt);
        if (!bidl_map) {
            return;
        }

        const BidlType* key_type = bidl_map->get_key_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = bidl_map->get_value_type();
        if (!value_type) {
            return;
        }

        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string key_var_name = "key_" + g_parser.get_tmp_var();
        std::string value_var_name = "vlaue_" + g_parser.get_tmp_var();

        of << get_indent(level) << "IntHolder " << set_size_var_name
            << " = new IntHolder();\n";
        of << get_indent(level) << "DataTypeHolder " << key_var_name
            << " = new DataTypeHolder();\n\n";
        of << get_indent(level) << "DataTypeHolder " << value_var_name
            << " = new DataTypeHolder();\n\n";

        of << get_indent(level) << " ret = protocol.readMapBegin("
            << key_var_name << ", " << value_var_name << ", "
            << set_size_var_name << ");\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";

        std::string var_i = "i" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (int " << var_i << " = 0; " << var_i << " < "
            << set_size_var_name << ".value; ++" << var_i << ") {\n";

        std::string key_value_var_name = "key_" + g_parser.get_tmp_var();
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        of << get_indent(level + 1) << key_type->get_real_type()->get_holder_type_name() << " "
            << key_value_var_name << " = new " << key_type->get_real_type()->get_holder_type_name()
            << "();\n";
        of << get_indent(level + 1) << value_type->get_real_type()->get_holder_type_name() << " "
            << value_value_var_name << " = new " << value_type->get_real_type()->get_holder_type_name()
            << "();\n";
        output_implement_struct_read_clause(key_type->get_real_type(), level + 1,
                key_value_var_name, of, false);
        output_implement_struct_read_clause(value_type->get_real_type(), level + 1,
                value_value_var_name, of, false);

        of << get_indent(level + 1) << "if (" << field_name << ".value == null) {\n";
        of << get_indent(level + 2) << field_name << ".value = " << bt->get_init_clause() << ";\n";
        of << get_indent(level + 1) << "}\n";
        of << get_indent(level + 1) << field_name << ".value.put("
            << key_value_var_name << ".value, "
            << value_value_var_name << ".value);\n";

        of << get_indent(level) << "ret = protocol.readMapEnd();\n";
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";
        of << get_indent(level) << "}\n";
        }
        break;
    default:
        break;
    }
}

void JavaSourceWriter::output_implement_struct_function_write(const BidlType* bt, std::ofstream& of) {
    if (!bt) {
        return;
    }

    const BidlStruct* e = dynamic_cast<const BidlStruct*>(bt);
    if (!e) {
        return;
    }
    std::string class_name = bt->get_name();

    of << get_indent(1) << "public int write(Protocol protocol) {\n";
    of << get_indent(2) << "int ret = 0;\n";
    of << get_indent(2) << "ret = protocol.writeStructBegin(\"" << class_name << "\");\n";
    of << get_indent(2) << "if (ret < 0) { return ret; }\n\n";

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        of << get_indent(2) << "ret = protocol.writeFieldBegin(\"" << f->get_name() << "\", ";
        const BidlType* field_type = f->get_field_type();
        if (!field_type) {
            return;
        }

        of << field_type->get_real_type()->get_bgcc_type_name("java");

        of << ", " << f->get_field_id() << ");\n";
        of << get_indent(2) << "if (ret < 0) { return ret; }\n";

        output_implement_struct_write_clause(field_type->get_real_type(), 2, f->get_name(), of);
        of << get_indent(2) << "ret = protocol.writeFieldEnd();\n";
        of << get_indent(2) << "if (ret < 0) { return ret; }\n\n";
    }

    of << get_indent(2) << "ret = protocol.writeFieldStop();\n";
    of << get_indent(2) << "if (ret < 0) { return ret; }\n\n";
    of << get_indent(2) << "return protocol.writeStructEnd();\n\n";

    of << get_indent(1) << "}\n\n";
}

void JavaSourceWriter::output_implement_struct_write_clause(
        const BidlType* bt,
        int32_t level,
        const std::string& field_name,
        std::ofstream& of, 
        bool member) {
    if (!bt) {
        return;
    }

    switch(bt->get_type_id()) {
    case BidlType::BOOLEAN:
        of << get_indent(level) << "ret = protocol.writeBool(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;
    case BidlType::INT8:
        of << get_indent(level) << "ret = protocol.writeByte(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;
    case BidlType::INT16:
        of << get_indent(level) << "ret = protocol.writeShort(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;;
    case BidlType::INT32:
        of << get_indent(level) << "ret = protocol.writeInt(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;
    case BidlType::ENUM:
        of << get_indent(level) << "ret = protocol.writeInt(";
        if (member) {
            of << "this." << field_name << ".value.getValue());\n";
        }
        else {
            of << field_name << ".getValue());\n";
        }
        break;
    case BidlType::INT64:
        of << get_indent(level) << "ret = protocol.writeLong(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;
    case BidlType::STRING:
        of << get_indent(level) << "ret = protocol.writeString(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;
    case BidlType::FLOAT:
        of << get_indent(level) << "ret = protocol.writeFloat(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;
    case BidlType::BINARY:
        of << get_indent(level) << "ret = protocol.writeBinary(";
        if (member) {
            of << "this." << field_name << ".value);\n";
        }
        else {
            of << field_name << ");\n";
        }
        break;
    case BidlType::STRUCT:
        of << get_indent(level) << "ret = " << field_name;
        if (member) {
            of << ".value";
        }
        of << ".write(protocol);\n";
        break;
    case BidlType::SET:
        {
        const BidlSet* bidl_set = dynamic_cast<const BidlSet*>(bt);
        if (!bidl_set) {
            return;
        }

        const BidlType* set_value_type = bidl_set->get_sub_type();
        if (!set_value_type) {
            return;
        }

        of << get_indent(level) << "ret = protocol.writeSetBegin("
            << set_value_type->get_real_type()->get_bgcc_type_name("java");
        if (member) {
            of << ", this." << field_name << ".value.size());\n";
        }
        else {
            of << ", " << field_name << ".size());\n";
        }

        of << get_indent(level) << "if (ret < 0) { return ret; }\n";

        std::string itr_name = "itr_" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (" << set_value_type->get_real_type()->get_return_type_name() << " "
            << itr_name;
        if (member) {
            of << " : this." << field_name << ".value) {\n";
        }
        else {
            of << " : " << field_name << ") {\n";
        }

        output_implement_struct_write_clause(set_value_type->get_real_type(), level + 1, itr_name, of, false);

        of << get_indent(level) << "}\n";

        of << get_indent(level) << "ret = protocol.writeSetEnd();\n";
        }
        break;
    case BidlType::MAP:
        {
        const BidlMap* bidl_map = dynamic_cast<const BidlMap*>(bt);
        if (!bidl_map) {
            return;
        }

        const BidlType* key_type = bidl_map->get_key_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = bidl_map->get_value_type();
        if (!value_type) {
            return;
        }

        of << get_indent(level) << "ret = protocol.writeMapBegin("
            << key_type->get_real_type()->get_bgcc_type_name("java")
            << ", " << value_type->get_real_type()->get_bgcc_type_name("java")
            << ", ";
        if (member) {
            of << "this." << field_name << ".value.size());\n";
        }
        else {
            of << field_name << ".size());\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";

        std::string itr_name = "citr_" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (Map.Entry<"
            << key_type->get_real_type()->get_general_type_name() << ", "
            << value_type->get_real_type()->get_general_type_name() << "> "
            << itr_name << " : ";
        if (member) {
            of << "this." << field_name << ".value.entrySet()) {\n";
        }
        else {
            of << field_name << ".entrySet()) {\n";
        }
        output_implement_struct_write_clause(key_type->get_real_type(), level + 1, itr_name + ".getKey()", of, false);
        output_implement_struct_write_clause(value_type->get_real_type(), level + 1, itr_name + ".getValue()", of, false);

        of << get_indent(level) << "}\n";
        of << get_indent(level) << "ret = protocol.writeMapEnd();\n";

        }
        break;
    case BidlType::SEQUENCE:
        {
        const BidlSequence* bidl_sequence = dynamic_cast<const BidlSequence*>(bt);
        if (!bidl_sequence) {
            return;
        }

        const BidlType* sequence_value_type = bidl_sequence->get_sub_type();
        if (!sequence_value_type) {
            return;
        }

        of << get_indent(level) << "ret = protocol.writeListBegin("
            << sequence_value_type->get_real_type()->get_bgcc_type_name("java");
        if (member) {
            of << ", this." << field_name << ".value.size());\n";
        }
        else {
            of << ", " << field_name << ".size());\n";
        }
        of << get_indent(level) << "if (ret < 0) { return ret; }\n";

        std::string itr_name = "itr_" + g_parser.get_tmp_var();
        of << get_indent(level) << "for (" << sequence_value_type->get_real_type()->get_return_type_name() << " "
            << itr_name;

        if (member) {
            of << " : this." << field_name << ".value) {\n";
        }
        else {
            of << " : " << field_name << ") {\n";
        }

        output_implement_struct_write_clause(sequence_value_type->get_real_type(), level + 1, itr_name, of, false);

        of << get_indent(level) << "}\n";

        of << get_indent(level) << "ret = protocol.writeListEnd();\n";
        }
        break;
    default:
        break;
    }
    
    of << get_indent(level) << "if (ret < 0) { return ret; }\n";
}

std::string JavaSourceWriter::mkpath(const std::vector<std::string>& name_parts) {
    std::vector<std::string>::const_iterator citr;

    std::string path;
    if (!GlobalParser::is_dir_exist(g_parser.get_outdir())) {
        mkdir(g_parser.get_outdir().c_str(), 0777);
    }
    path.append(g_parser.get_outdir());

    if (name_parts.size() > 2) {
        citr = name_parts.begin() + 1;
        for (; citr != name_parts.end() - 1; ++citr) {
            path.append(*citr + "/");
            mkdir(path.c_str(), 0777);
        }
    }
    return path;
}

void JavaSourceWriter::output_implement_enum(const BidlType* bt) {
    if (!bt) {
        return;
    }

    const BidlEnum* e = dynamic_cast<const BidlEnum*>(bt);
    if (!e) {
        return;
    }

    std::string class_name = bt->get_name();
    std::string holder_name = class_name + "Holder";

    std::vector<std::string> name_parts;
    split_string(bt->_symtab_name, ".", name_parts);
    if (name_parts.size() < 2) {
        return;
    }

    std::string fullpath = mkpath(name_parts);

    std::string package_clause;
    std::vector<std::string>::const_iterator name_parts_citr;
    name_parts_citr = name_parts.begin() + 1; //filter "global"
    if (name_parts.size() > 2) {
        package_clause.append("package ");
    }

    for (; name_parts_citr != name_parts.end() - 1; ++name_parts_citr) {
        package_clause.append(*name_parts_citr);
        if (name_parts_citr != name_parts.end() - 2) {
            package_clause.append(".");
        }
    }
    
    if (name_parts.size() > 2) {
        package_clause.append(";\n");
    }

    //output Holder
    std::ofstream of((fullpath + holder_name + ".java").c_str());
    if (!of.is_open()) {
        myerror("open %s failed", fullpath.c_str());
        return;
    }

    int32_t level = 0;
    of << package_clause;

    of << "public final class " << holder_name << " {\n\n";
    of << get_indent(level + 1) << "public " << holder_name << "() {\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public " << holder_name << "(" << class_name << " value) {\n";
    of << get_indent(level + 2) << "this.value = value;\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public " << class_name << " value;\n";

    of << "}\n\n";
    of.close();
    
    //enum
    of.open((fullpath + class_name + ".java").c_str());
    if (!of.is_open()) {
        myerror("open %s failed", fullpath.c_str());
        return;
    }

    of << package_clause << "\n";
    of << "public enum " << class_name << " {\n\n";

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlEnumField* f = dynamic_cast<const BidlEnumField*>(*citr);
        if (!f) {
            continue;
        }
        of << get_indent(level + 1) << f->get_name() << "(" << f->get_value() << ", \""
            << class_name << "::" << f->get_name() << "\")";
        if (citr + 1 != children.end()) {
            of << ",";
        }
        else {
            of << ";";
        }
        of << "\n\n";
    }

    of << get_indent(level + 1) << "private final int value;\n\n";
    of << get_indent(level + 1) << "private final java.lang.String desc;\n\n";

    of << get_indent(level + 1) << "private " << class_name << "(int value, java.lang.String desc) {\n";
    of << get_indent(level + 2) << "this.value = value;\n";
    of << get_indent(level + 2) << "this.desc = desc;\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public int getValue() {\n";
    of << get_indent(level + 2) << "return value;\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public java.lang.String getDescription() {\n";
    of << get_indent(level + 2) << "return desc;\n";
    of << get_indent(level + 1) << "}\n\n";

    of << get_indent(level + 1) << "public static " << class_name << " findByValue(int value) {\n";
    of << get_indent(level + 2) << "for (" << class_name << " temp : " << class_name << ".values()) {\n";
    of << get_indent(level + 3) << "if (value == temp.getValue()) {\n";
    of << get_indent(level + 4) << "return temp;\n";
    of << get_indent(level + 3) << "}\n";
    of << get_indent(level + 2) << "}\n";
    of << get_indent(level + 2) << "return null;\n";
    of << get_indent(level + 1) << "}\n\n";

    of << "}\n\n";

    of.close();

}

void JavaSourceWriter::output_implement_const(const BidlType* bt) {
    if (!bt) {
        return;
    }

    const BidlConst* c = dynamic_cast<const BidlConst*>(bt);
    if (!c) {
        return;
    }

    const BidlType* field_type = c->get_field_type();
    if (!field_type) {
        return;
    }

    const BidlType* value = c->get_value();
    if (!value) {
        return;
    }

    std::vector<std::string> name_parts;
    split_string(bt->_symtab_name, ".", name_parts);
    if (name_parts.size() < 2) {
        return;
    }

    std::string fullpath = mkpath(name_parts);

    fullpath.append(c->get_name() + ".java");
    std::ofstream of(fullpath.c_str());
    if (!of.is_open()) {
        myerror("open %s failed", fullpath.c_str());
        return;
    }

    std::vector<std::string>::const_iterator citr;
    citr = name_parts.begin() + 1; //filter "global"
    if (name_parts.size() > 2) {
        of << "package ";
    }

    for (; citr != name_parts.end() - 1; ++citr) {
        of << *citr;
        if (citr != name_parts.end() - 2) {
            of << ".";
        }
    }
    
    if (name_parts.size() > 2) {
        of << ";\n";
    }

    of << "import java.util.*;\n";
    of << "import java.lang.*;\n";

    int32_t level = 1;
    of << "public final class " << bt->get_name() << " {\n";
    if (!field_type->get_real_type()->is_container()) {
        of << get_indent(level) << "public static final " << field_type->get_real_type()->get_tag(this)
            << " value = " << value->get_tag();
        of << ";\n";
    }
    else {
        of << get_indent(level) << "public static final " << field_type->get_real_type()->get_return_type_name()
            << " value = create();\n\n";

        of << get_indent(level) << "private static " << field_type->get_real_type()->get_return_type_name()
           << " create() {\n"; 
        std::string tmp_name;
        output_container_const_value(field_type->get_real_type(), value, level + 1, tmp_name, of);
        of << get_indent(level + 1) << "return " << tmp_name << ";\n";
        of << get_indent(level) << "}\n";
    }
    of << "}\n\n";
}

void JavaSourceWriter::output_container_const_value(
        const BidlType* field_type, 
        const BidlType* value, 
        int32_t level, 
        std::string& name,
        std::ofstream& of) {
    if (!field_type || !value) {
        return;
    }

    name = "tmp_" + g_parser.get_tmp_var();

    of << get_indent(level) << field_type->get_return_type_name() << " " << name << " = "
        << field_type->get_init_clause() << ";\n\n";

    if (field_type->is_sequence()) {
        const BidlType* sub_type = dynamic_cast<const BidlSequence*>(field_type)->get_sub_type();
        if (!sub_type) {
            return;
        }
        sub_type = sub_type->get_real_type();
        if (!sub_type) {
            return;
        }
        
        const std::vector<BidlType*>& children_value = value->get_children();
        std::vector<BidlType*>::const_iterator citr;
        if (!sub_type->is_container()) {
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                of << get_indent(level) << name << ".add(" << (*citr)->get_tag();
                of << ");\n";
            }
        }
        else {
            std::string child_name;
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                output_container_const_value(sub_type, *citr, level, child_name, of);
                of << get_indent(level) << name << ".add(" << child_name << ");\n";
            }
        }
        of << "\n";
    }
    else if (field_type->is_set()) {
        const BidlType* sub_type = dynamic_cast<const BidlSet*>(field_type)->get_sub_type();
        if (!sub_type) {
            return;
        }
        sub_type = sub_type->get_real_type();
        if (!sub_type) {
            return;
        }
        
        const std::vector<BidlType*>& children_value = value->get_children();
        std::vector<BidlType*>::const_iterator citr;
        if (!sub_type->is_container()) {
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                of << get_indent(level) << name << ".add(" << (*citr)->get_tag();
                of << ");\n";
            }
        }
        else {
            std::string child_name;
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                output_container_const_value(sub_type, *citr, level, child_name, of);
                of << get_indent(level) << name << ".add(" << child_name << ");\n";
            }
        }
        of << "\n";
    }
    else if (field_type->is_map()) {
        const BidlType* key_type = dynamic_cast<const BidlMap*>(field_type)->get_key_type();
        if (!key_type) {
            return;
        }
        key_type = key_type->get_real_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = dynamic_cast<const BidlMap*>(field_type)->get_value_type();
        if (!value_type) {
            return;
        }
        value_type = value_type->get_real_type();
        if (!value_type) {
            return;
        }
        
        const std::vector<BidlType*>& children_value = value->get_children();
        std::vector<BidlType*>::const_iterator itr;
        if (!key_type->is_container() && !value_type->is_container()) {
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                of << get_indent(level) << name << ".put(" 
                    << tmp_map->get_key_type()->get_tag() << ", " << tmp_map->get_value_type()->get_tag() << ");\n";
            }
        }
        else if (!key_type->is_container() && value_type->is_container()) {
            std::string child_name;
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                output_container_const_value(value_type, tmp_map->get_value_type(), level, child_name, of);
                of << get_indent(level) << name << ".put(" 
                    << tmp_map->get_key_type()->get_tag() << ", " << child_name << ");\n";
            }
        }
        else if (key_type->is_container() && !value_type->is_container()) {
            std::string child_name;
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                output_container_const_value(key_type, tmp_map->get_key_type(), level, child_name, of);
                of << get_indent(level) << name << ".put(" 
                    << child_name << ", " << tmp_map->get_value_type()->get_tag() << ");\n";
            }
        }
        else if (key_type->is_container() && value_type->is_container()) {
            std::string key_child_name;
            std::string value_child_name;
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                output_container_const_value(key_type, tmp_map->get_key_type(), level, key_child_name, of);
                output_container_const_value(value_type, tmp_map->get_value_type(), level, value_child_name, of);
                of << get_indent(level) << name << ".put(" 
                    << key_child_name << ", " << value_child_name << ");\n";
            }
        }
        of << "\n";
    }
}

std::string JavaSourceWriter::get_identifier_tag(const std::string& id) const {
    return id;
}
