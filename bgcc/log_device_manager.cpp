/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <iostream>
#include <string.h>
#include "log_device_manager.h"
#include "log_device.h"
#include "conf_loader.h"
#include "conf_unit.h"
#include "bgcc_error.h"
#include "string_util.h"

namespace bgcc {

    void load_default_device() {
        char buffer[BUFSIZ];
        int32_t ret;

        LogDeviceManager* manager = LogDeviceManager::get_instance();
        if (NULL == manager) {
            std::cerr << "Get LogDeviceManager singlton failed" << std::endl;
            exit(0);
        }

        ILogDevice* default_device = new(std::nothrow) FileLogDevice(
                "./bgcc.log", "bgcc", BGCC_LOGLEVEL_WARN,
                BGCC_LOG_SPLIT_POLICY_BY_SIZE, 500*1024*1024, -1,
                "%D [%N] %T {%F(%L)} %C");
        if (NULL == default_device) {
            std::cerr << "Create default device `bgcc' failed." << std::endl;
            exit(0);
        }

        ret = default_device->open();
        if (0 != ret) {
            std::cerr << "Open default device failed: " << bgcc_strerror_r(ret, buffer, BUFSIZ) << std::endl;
            delete default_device;
            exit(0);
        }

        if (0 != manager->add_device(default_device)) {
            std::cerr << "Add device `bgcc' failed" << std::endl;
            delete default_device;
            exit(0);
        }
    }

    static int32_t get_loglevel_from_logdev_confunit(ConfUnit* logdev) {
        if (NULL == logdev) {
            std::cerr << "logdev is null" << std::endl;
            exit(0);
        }

        ConfUnit* level = (*logdev)["level"];
        if (NULL == level || ConfUnit::UT_STRING != level->get_type()) {
            std::cerr << "no level variable in logdev" << std::endl;
            exit(0);
        }

        std::string level_valstr = level->to_string();
        int32_t level_value;
        if ("TRACE" == level_valstr) {
            level_value = BGCC_LOGLEVEL_TRACE;
        }
        else if ("DEBUG" == level_valstr) {
            level_value = BGCC_LOGLEVEL_DEBUG;
        }
        else if ("NOTICE" == level_valstr) {
            level_value = BGCC_LOGLEVEL_NOTICE;
        }
        else if ("WARN" == level_valstr) {
            level_value = BGCC_LOGLEVEL_WARN;
        }
        else if ("FATAL" == level_valstr) {
            level_value = BGCC_LOGLEVEL_FATAL;
        }
        else {
            std::cerr << "specify an invalid log level string " << level_valstr << std::endl;
            exit(0);
        }

        return level_value;
    }

    static std::string get_device_name_from_logdev_confunit(ConfUnit* logdev) {
        if (NULL == logdev) {
            std::cerr << "logdev is null" << std::endl;
            exit(0);
        }

        ConfUnit* device_name = (*logdev)["device_name"];
        if (NULL == device_name || ConfUnit::UT_STRING != device_name->get_type()) {
            std::cerr << "no device_name variable in logdev" << std::endl;
            exit(0);
        }
        return device_name->to_string();
    }

    static std::string get_filepath_from_logdev_confunit(ConfUnit* logdev) {
        if (NULL == logdev) {
            std::cerr << "logdev is null" << std::endl;
            exit(0);
        }

        ConfUnit* filepath = (*logdev)["filepath"];
        if (NULL == filepath || ConfUnit::UT_STRING != filepath->get_type()) {
            std::cerr << "no filepath variable in logdev" << std::endl;
            exit(0);
        }
        return filepath->to_string();
    }

    static int32_t get_split_policy_from_logdev_confunit(ConfUnit* logdev) {
        if (NULL == logdev) {
            std::cerr << "logdev is null" << std::endl;
            exit(0);
        }

        ConfUnit* split_policy = (*logdev)["split_policy"];
        if (NULL == split_policy || ConfUnit::UT_STRING != split_policy->get_type()) {
            std::cerr << "no split_policy variable in logdev" << std::endl;
            exit(0);
        }
        std::string split_policy_valstr = split_policy->to_string();
        int32_t split_policy_value;
        if ("SIZE" == split_policy_valstr) {
            split_policy_value = BGCC_LOG_SPLIT_POLICY_BY_SIZE;
        }
        else if ("TIME" == split_policy_valstr) {
            split_policy_value = BGCC_LOG_SPLIT_POLICY_BY_TIME;
        }
        else {
            std::cerr << "specify an invalid log split policy string " << split_policy_valstr << std::endl;
            exit(0);
        }

        return split_policy_value;
    }

    static int64_t get_maxsize_from_logdev_confunit(ConfUnit* logdev, int32_t split_policy) {
        if (NULL == logdev) {
            std::cerr << "logdev is null" << std::endl;
            exit(0);
        }

        int64_t maxsize_value = 0;
        if (split_policy == BGCC_LOG_SPLIT_POLICY_BY_SIZE) {
            ConfUnit* max_size = (*logdev)["max_size"];
            if (NULL == max_size || ConfUnit::UT_STRING != max_size->get_type()) {
                std::cerr << "no max_size variable in logdev" << std::endl;
                exit(0);
            }
            std::string max_size_valstr = max_size->to_string();
            if (false == StringUtil::str2int64(max_size_valstr.c_str(), maxsize_value)) {
                std::cerr << "invalid max_size number " << max_size_valstr << std::endl;
                exit(0);
            }
        }
        return maxsize_value;
    }

    static int32_t get_life_circle_from_logdev_confunit(ConfUnit* logdev, int32_t split_policy) {
        if (NULL == logdev) {
            std::cerr << "logdev is null" << std::endl;
            exit(0);
        }

        int32_t life_circle_value = 0;
        if (split_policy == BGCC_LOG_SPLIT_POLICY_BY_TIME) {
            ConfUnit* life_circle = (*logdev)["life_circle"];
            if (NULL == life_circle || ConfUnit::UT_STRING != life_circle->get_type()) {
                std::cerr << "no life_circle variable in logdev" << std::endl;
                exit(0);
            }
            std::string life_circle_valstr = life_circle->to_string();
            if (false == StringUtil::str2int32(life_circle_valstr.c_str(), life_circle_value)) {
                std::cerr << "invalid life_circle number " << life_circle_valstr << std::endl;
                exit(0);
            }
        }
        return life_circle_value;
    }

    static std::string get_layout_from_logdev_confunit(ConfUnit* logdev) {
        if (NULL == logdev) {
            std::cerr << "logdev is null" << std::endl;
            exit(0);
        }

        ConfUnit* layout = (*logdev)[std::string("layout")];
        if (NULL == layout || ConfUnit::UT_STRING != layout->get_type()) {
            std::cerr << "no layout variable in logdev" << std::endl;
            exit(0);
        }
        return layout->to_string();
    }

    void load_conf_device(const char* conf_filepath) {
        char buffer[BUFSIZ];
        int32_t ret;
        ConfUnit* root = ConfLoader::load_conf(conf_filepath);
        if (NULL == root) {
            std::cerr << "ConfLoader::load_conf return a NULL ConfUnit pointer" << std::endl;
            exit(0);
        }

        ConfUnit* logdevs = (*root)["log_devices"];

        if (NULL == logdevs) {
            std::cerr << "Not find log_devices section" << std::endl;
            exit(0);
        }

        if (ConfUnit::UT_ARRAY != logdevs->get_type()) {
            std::cerr << "log_devices is not an array" << std::endl;
            exit(0);
        }

        LogDeviceManager* manager = LogDeviceManager::get_instance();
        if (NULL == manager) {
            std::cerr << "Get LogDeviceManager singlton failed" << std::endl;
            exit(0);
        }

        ConfUnit::const_iterator citr;
        int32_t i;
        for (citr = logdevs->begin(), i = 1; citr != logdevs->end(); ++citr, ++i) {
            ConfUnit* logdev = *citr;
            if (NULL == logdev || ConfUnit::UT_GROUP != logdev->get_type()) {
                std::cerr << "counter a non log device group in logdev" << std::endl;
                exit(0);
            }

            int32_t level_value = get_loglevel_from_logdev_confunit(logdev);
            std::string device_name_valstr = get_device_name_from_logdev_confunit(logdev);
            std::string filepath_valstr = get_filepath_from_logdev_confunit(logdev);
            int32_t split_policy_value = get_split_policy_from_logdev_confunit(logdev);
            int64_t maxsize_value = get_maxsize_from_logdev_confunit(logdev, split_policy_value);
            int32_t life_circle_value = get_life_circle_from_logdev_confunit(logdev, split_policy_value);
            std::string layout_valstr = get_layout_from_logdev_confunit(logdev);

            ILogDevice* device = new(std::nothrow) FileLogDevice(
                    filepath_valstr.c_str(), device_name_valstr.c_str(), level_value,
                    split_policy_value, (off_t)maxsize_value, life_circle_value,
                    layout_valstr.c_str());
            if (NULL == device ) {
                std::cerr << "Create device " << i << " failed." << std::endl;
                exit(0);
            }

            if (0 != (ret = device->open())) {
                std::cerr << "Open device " << i << " failed: " << bgcc_strerror_r(ret, buffer, BUFSIZ) << std::endl;
                exit(0);
            }

            if (0 != manager->add_device(device)) {
                std::cerr << "Add device " << i << " failed" << std::endl;
                exit(0);
            }
        }

        delete root;
    }

    void log_open(const char* conf_filepath) {
        if (NULL != conf_filepath) {
            load_conf_device(conf_filepath);
        }

        LogDeviceManager* manager = LogDeviceManager::get_instance();
        if (NULL == manager) {
            std::cerr << "Get LogDeviceManager singlton failed" << std::endl;
            exit(0);
        }

        if (false == manager->is_device_exist("bgcc")) {
            load_default_device();
        }
    }

    int32_t log_close() {
        return 0;
    }

    LogDeviceManager::LogDeviceManager() {
    }

    LogDeviceManager* LogDeviceManager::get_instance() {
        static LogDeviceManager logger;
        return &logger;
    }

    LogDeviceManager::~LogDeviceManager() {
        std::vector<ILogDevice*>::iterator itr;
        for (itr = _devices.begin(); itr != _devices.end(); ++itr) {
            delete *itr;
        }
        _devices.clear();
    }

    bool LogDeviceManager::is_device_exist(const char* device_name) {
        return get_device(device_name) != NULL;
    }

    int32_t LogDeviceManager::add_device(ILogDevice* device) {
        if (is_device_exist(device->get_name())) {
            return -1;
        }

        _devices.push_back(device);
        return 0;
    }

    int32_t LogDeviceManager::get_device_loglevel(const char* device_name) {
        ILogDevice* device = get_device(device_name);

        if (NULL == device) {
            device = get_device("bgcc");
        }

        if (NULL != device) {
            return device->get_loglevel();
        }
        else {
            return BGCC_LOGLEVEL_NOLOG;
        }
    }

    ILogDevice* LogDeviceManager::get_device(const char* device_name) {
        std::vector<ILogDevice*>::iterator itr;
        for (itr = _devices.begin(); itr != _devices.end(); ++itr) {
            if (strcmp((*itr)->get_name(), device_name) == 0) {
                return *itr;
            }
        }
        return NULL;
    }

    int32_t LogDeviceManager::write(const char* device_name,
            const struct log_message_t& log_message) {
        ILogDevice* device = get_device(device_name);

        if (NULL == device) {
            device = get_device("bgcc");
        }

        if (NULL != device) {
            return device->write(log_message);
        }
        else {
            return -1;
        }
    }
}

