/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <getopt.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "cpp_source_writer.h"
#include "global_parser.h"

void usage() {
    std::cerr <<
        "Usage: bidl2sl [options] files... \n"
        "Options:\n"
        "-h, --help                 Show this messages.\n"
        "-v, --version              Show version.\n"
        "-I DIR, --include DIR      Append DIR in the include bidl file search path.\n"
        "-O DIR, --output DIR       Change output directory to DIR.\n"   
        "                           (default: ./output-LANG)\n" 
        "-g LANG, --gen LANG        Generate source code with LANG language.\n" 
        "                           (default: cpp)\n" 
        "                           (support: cpp java)\n" 
        "-d, --debug                Print debug message to stderr.\n"
        << std::endl;
}

void version() {
    std::cerr << "bidl2sl version "VERSION << std::endl;
}

ParseResult* g_parseresult;

std::list<std::string> g_input_bidl_files;
std::vector<std::string> g_success_parsed_bidl_files;
std::list<std::string> g_fail_parsed_bidl_files;

std::string g_cur_bidl_file_name;
BidlNamespace* g_cur_bidl_namespace;

std::vector<std::string> g_include_bidl_files;
std::map<std::string, BidlType*> g_filename2typeptr;

GlobalParser g_parser;

int main(int argc, char* argv[]) {
    opterr = 1;

    while (true) {
        static struct option long_options[] = {
            {"help",    0, 0, 0},
            {"version", 0, 0, 1},
            {"include", 1, 0, 2},
            {"output",  1, 0, 3},
            {"gen",     1, 0, 4},
            {"debug",   0, 0, 5},
            {NULL,      0, 0, 0}
        };

        int32_t ret = getopt_long(argc, argv, "hvg:I:O:d",
                long_options, NULL);
        if (ret == -1)
            break;

        switch(ret) {
        case 0:
        case 'h':
            usage();
            return 0;
            break;

        case 1:
        case 'v':
            version();
            return 0;
            break;

        case 2:
        case 'I':
            g_parser.add_bidl_include_dir(optarg);
            break;

        case 3:
        case 'O':
            if (g_parser.is_outdir_setted() && g_parser.get_outdir() != optarg) {
                yyerror("Output directories occur in two different argv-elements.");
                exit(0);
            }
            g_parser.set_outdir(optarg);
            break;

        case 4:
        case 'g':
            if (g_parser.is_lang_setted() && g_parser.get_language() != optarg) {
                myerror("Languages occur in two different argv-elements.");
            }
            g_parser.set_language(optarg);
            break;

        case 5:
        case 'd':
            g_parser.set_debuged();
            break;

        default:
            usage();
            return 0;
            break;
        }
    }

    if (optind < argc) {
        while (optind < argc) {
            g_parser.add_bidl(argv[optind++]);
        }
    }
    g_parser.parse();

    return 0;
}

