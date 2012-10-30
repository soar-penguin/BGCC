/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <fstream>
#include "conf_loader.h"
#include "conf_unit.h"
#include "bgcc_error.h"
#include "string_util.h"

namespace bgcc {

    const int32_t ConfLoader::MAX_LINE_LEN = 512;

    ConfUnit* ConfLoader::load_conf(const char* conf_filename) {
        std::ifstream conf_file(conf_filename, std::ifstream::in);
        if (conf_file.fail()) {
            return NULL;
        }

        char line[MAX_LINE_LEN];
        ConfUnit* root = new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP);
        if (NULL != root) {
            ConfUnit* current = root;
            while (conf_file.good()) {
                conf_file.getline(line, MAX_LINE_LEN);

                if (is_white_line(line) || is_comment_line(line)) {
                    continue;
                }

                if (0 != handle_line(line, root, current)) {
                    delete root;
                    root = NULL;
                    break;
                }
            }
        }

        conf_file.close();
        return root;
    }

    bool ConfLoader::is_white_line(const char* line) {
        if (NULL == line) {
            return false;
        }
        else {
            return StringUtil::trim(line).empty();
        }
    }

    bool ConfLoader::is_comment_line(const char* line) {
        if (NULL == line) {
            return false;
        }
        else {
            std::string line_trimed = StringUtil::ltrim(line);
            return !line_trimed.empty() && ('#' == line_trimed[0]);
        }
    }

    int32_t ConfLoader::handle_line(const char* line, ConfUnit* root, ConfUnit*& current) {
        if (NULL == root || NULL == current) {
            return E_BGCC_NULL_POINTER;
        }

        std::vector<std::string> paths;
        std::string key;
        std::string value;

        if (0 == handle_as_section(line, paths)) {
            if (0 == paths.size()) {
                return E_BGCC_CONF_ERROR;
            }
            current = push_section(root, paths);
            if (NULL == current) {
                return E_BGCC_CONF_ERROR;
            }
        }
        else if (0 == handle_as_item(line, key, value)) {
            if (0 != push_item(current, key, value)) {
                return E_BGCC_CONF_ERROR;
            }
        }
        else {
            return E_BGCC_CONF_ERROR;
        }

        return 0;
    }

    int32_t ConfLoader::handle_as_section(const char* line, std::vector<std::string>& paths) {
        paths.clear();
        std::string line_trimed = StringUtil::trim(line);
        int32_t size = (int32_t)line_trimed.size();

        if (size < 2
                || '[' != line_trimed[0]
                || ']' != line_trimed[size - 1]) { 
            return E_BGCC_CONF_ERROR;
        }

        line_trimed = line_trimed.substr(1, size - 2);
        size -= 2;

        std::vector<std::string> v;
        StringUtil::split_string(line_trimed, ".", v, /*filter_empty = */false);
        if (0 == v.size()) {
            return E_BGCC_CONF_ERROR;
        }

        std::vector<std::string>::iterator itr;
        for (itr = v.begin(); itr != v.end(); ++itr) {
            std::string s = StringUtil::trim(*itr);

            if (s.empty()) {
                return E_BGCC_CONF_ERROR;
            }
            else {
                paths.push_back(s);
            }
        }

        std::vector<std::string>::reverse_iterator ritr;
        ritr = paths.rbegin();
        if (ritr != paths.rend()) {
            ++ritr;
            while (ritr != paths.rend()) {
                if ('@' == (*ritr)[0]) {
                    paths.clear();
                    return E_BGCC_CONF_ERROR;
                }
                ++ritr;
            }
        }
        return 0;
    }

    int32_t ConfLoader::handle_as_item(const char* line, std::string& key, std::string& value) {
        std::string line_trimed = StringUtil::trim(line);
        std::string::size_type pos = line_trimed.find_first_of('=');
        if (std::string::npos == pos) {
            return E_BGCC_CONF_ERROR;
        }
        else {
            key = StringUtil::trim(line_trimed.substr(0, pos));
            if (key.empty()) {
                return E_BGCC_CONF_ERROR;
            }

            if (pos != line_trimed.size() - 1) {
                value = StringUtil::trim(line_trimed.substr(pos + 1));
            }
            else {
                value = "";
            }

            return 0;
        }
    }

    ConfUnit* ConfLoader::push_section(ConfUnit* root, const std::vector<std::string>& paths) {
        int32_t size = (int32_t)paths.size();
        if (0 == size) {
            return NULL;
        }

        ConfUnit* current = root;
        ConfUnit* son = NULL;
        for (int32_t i = 0; i < size - 1; ++i) {
            if (!current->is_group() || '@' == paths[i][0]) {
                return NULL;
            }
            son = (*current)[paths[i]];

            if (NULL == son) { //不存在，则插入
                current->insert(paths[i], new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
                son = (*current)[paths[i]];
                if (NULL == son) {
                    return NULL;
                }
            }
            current = son;
        }

        if (!current->is_group()) {
            return NULL;
        }

        if ('@' == paths[size - 1][0]) { //array
            std::string p = paths[size - 1].substr(1);
            son = (*current)[p];
            if (NULL != son) { //array已存在
                if (!son->is_array()) { //array不是UT_ARRAY
                    return NULL;
                }
                return son->push_back(new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
            }

            current->insert(p, new(std::nothrow) ConfUnit(ConfUnit::UT_ARRAY));
            son = (*current)[p];
            if (NULL == son || !son->is_array()) {
                return NULL;
            }
            return son->push_back(new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
        }
        else {
            son = (*current)[paths[size - 1]];
            if (NULL != son) { //居然存在?
                return NULL;
            }
            current->insert(paths[size - 1], new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
            son = (*current)[paths[size - 1]];
            return son;
        }
    }

    int32_t ConfLoader::push_item(ConfUnit* current, const std::string& key,
            const std::string& value) {
        if (NULL == current) {
            return E_BGCC_CONF_ERROR;
        }

        ConfUnit* tmp = (*current)[StringUtil::trim(key)];
        if (NULL != tmp) {
            return E_BGCC_CONF_ERROR;
        }

        current->insert(StringUtil::trim(key), new(std::nothrow) ConfUnit(StringUtil::trim(value)));
        return 0;
    }
}
