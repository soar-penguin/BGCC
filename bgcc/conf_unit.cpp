/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "conf_unit.h"

namespace bgcc {

    ConfUnit::ConfUnit(unit_type_t type) : _type(type) {
        if (UT_BOOL == type) {
            _union.b = true;
        }
        else if (UT_INT32 == type) {
            _union.i = 0;
        }
        else if (UT_INT64 == type) {
            _union.l = 0;
        }
        else if (UT_DOUBLE == type) {
            _union.d = 0.0;
        }
    }

    ConfUnit::ConfUnit(bool b) : _type(UT_BOOL) {
        _union.b = b;
    }

    ConfUnit::ConfUnit(int32_t i) : _type(UT_INT32) {
        _union.i = i;
    }

    ConfUnit::ConfUnit(int64_t l) : _type(UT_INT64) {
        _union.l = l;
    }

    ConfUnit::ConfUnit(double d) : _type(UT_DOUBLE) {
        _union.d = d;
    }

    ConfUnit::ConfUnit(const char* str) : _type(UT_STRING), _string(str) {
    }

    ConfUnit::ConfUnit(const std::string& str) : _type(UT_STRING), _string(str) {
    }

    ConfUnit::~ConfUnit() {
        if (is_array()) {
            iterator itr;
            for (itr = _vector.begin(); itr != _vector.end(); ++itr) {
                if (*itr) {
                    delete (*itr);
                }
            }
            _vector.clear();
        }
        else if (is_group()) {
            std::map<std::string, ConfUnit*>::iterator itr;
            for (itr = _map.begin(); itr != _map.end(); ++itr) {
                if (itr->second) {
                    delete itr->second;
                }
            }
            _map.clear();
        }
    }

    int32_t ConfUnit::get_type() const {
        return (int32_t)_type;
    }

    bool ConfUnit::is_bool() const {
        return UT_BOOL == _type;
    }

    bool ConfUnit::is_int32() const {
        return UT_INT32 == _type;
    }

    bool ConfUnit::is_int64() const {
        return UT_INT64 == _type;
    }

    bool ConfUnit::is_double() const {
        return UT_DOUBLE == _type;
    }

    bool ConfUnit::is_string() const {
        return UT_STRING == _type;
    }

    bool ConfUnit::is_array() const {
        return UT_ARRAY == _type;
    }

    bool ConfUnit::is_group() const {
        return UT_GROUP == _type;
    }

    bool ConfUnit::to_bool() const {
        if (is_bool()) {
            return _union.b;
        }
        else {
            throw std::exception();
        }
    }

    int32_t ConfUnit::to_int32() const {
        if (is_int32()) {
            return _union.i;
        }
        else {
            throw std::exception();
        }
    }

    int64_t ConfUnit::to_int64() const {
        if (is_int32()) {
            return (int64_t)_union.i;
        }
        else if (is_int64()) {
            return _union.l;
        }
        else {
            throw std::exception();
        }
    }

    double ConfUnit::to_double() const {
        if (is_int32()) {
            return (double)_union.i;
        }
        else if (is_int64()) {
            return (double)_union.l;
        }
        else if (is_double()) {
            return _union.d;
        }
        else {
            throw std::exception();
        }
    }

    std::string ConfUnit::to_string() const {
        if (is_string()) {
            return _string;
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::set_bool(bool b) {
        if (is_bool()) {
            _union.b = b;
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::set_int32(int32_t i) {
        if (is_int32()) {
            _union.i = i;
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::set_int64(int64_t l) {
        if (is_int64()) {
            _union.l = l;
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::set_double(double d) {
        if (is_double()) {
            _union.d = d;
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::set_string(const std::string& str) {
        if (is_string()) {
            _string = str;
        }
        else {
            throw std::exception();
        }
    }


    ConfUnit::const_iterator ConfUnit::begin() const {
        if (is_array()) {
            return _vector.begin();
        }
        else {
            throw std::exception();
        }
    }

    ConfUnit::const_iterator ConfUnit::end() const {
        if (is_array()) {
            return _vector.end();
        }
        else {
            throw std::exception();
        }
    }

    ConfUnit* ConfUnit::operator[](const std::string& index) {
        if (is_group()) {
            std::map<std::string, ConfUnit*>::iterator itr;
            itr = _map.find(index);
            if (itr != _map.end()) {
                return itr->second;
            }
            else {
                return NULL;
            }
        }
        else {
            throw std::exception();
        }
    }

    ConfUnit* ConfUnit::push_back(ConfUnit* punit) {
        if (is_array()) {
            _vector.push_back(punit);
            return punit;
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::pop_back() {
        if (is_array()) {
            if (_vector.size() > 0) {
                ConfUnit* pson = NULL;
                pson = _vector.back();
                _vector.pop_back();
                if (NULL != pson) {
                    delete pson;
                }
            }
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::insert(const std::string& key, ConfUnit* punit) {
        if (is_group()) {
            _map.insert(std::make_pair(key, punit));
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::erase(const std::string& key) {
        if (is_group()) {
            std::map<std::string, ConfUnit*>::iterator itr;
            itr = _map.find(key);
            if (itr != _map.end()) {
                if (NULL != itr->second) {
                    delete itr->second;
                }
                _map.erase(itr);
            }
        }
        else {
            throw std::exception();
        }
    }

    void ConfUnit::clear() {
        if (is_array()) {
            std::vector<ConfUnit*>::iterator itr;
            for (itr = _vector.begin(); itr != _vector.end(); ++itr) {
                if (NULL != *itr) {
                    delete *itr;
                }
            }
            _vector.clear();
        }
        else if (is_group()) {
            std::map<std::string, ConfUnit*>::iterator itr;
            for (itr = _map.begin(); itr != _map.end(); ++itr) {
                if (NULL != itr->second) {
                    delete itr->second;
                }
            }
            _map.clear();
        }
        else {
            throw std::exception();
        }
    }

    int32_t ConfUnit::size() const {
        if (is_array()) {
            return (int32_t)_vector.size();
        }
        else if (is_group()) {
            return (int32_t)_map.size();
        }
        else {
            return 0;
        }
    }
}

