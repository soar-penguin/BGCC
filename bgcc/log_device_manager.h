/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_LOG_DEVICE_MANAGER_H_
#define _BGCC2_LOG_DEVICE_MANAGER_H_

#include <vector>
#include "log_device.h"
#include "bgcc_stdint.h"

//BGCC log level definition
#define BGCC_LOGLEVEL_TRACE  0x0
#define BGCC_LOGLEVEL_DEBUG  0x1
#define BGCC_LOGLEVEL_NOTICE 0x2
#define BGCC_LOGLEVEL_WARN   0x3
#define BGCC_LOGLEVEL_FATAL  0x4
#define BGCC_LOGLEVEL_NOLOG  0x10

namespace bgcc {

    /**
     * @brief log_open 1. 加载BGCC配置文件，打开BGCC日志对象 2. 加载BGCC内置日志对象"bgcc"
     *
     * @param conf_filepath BGCC日志配置文件路径
     * @see
     * @note 当配置文件不存在或者配置文件有误时将给出错误提示并直接退出程序的执行
     * 请在main函数入口处调用该函数
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 10时39分56秒
     */
    void log_open(const char* conf_filepath = NULL);

    /**
     * @brief log_close 关闭BGCC日志对象
     *
     * @return 
     * @see
     * @note
     * 请在main函数结束前调用该函数
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 10时47分16秒
     */
    int32_t log_close();

    /**
     * @brief 日志对象类
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 10时50分39秒
     */
    class LogDeviceManager {
    public:
        /**
         * @brief get_instance 获取日志对象单例
         *
         * @return  日志对象单例
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时51分00秒
         */
        static LogDeviceManager* get_instance();

        /**
         * @brief ~LogDeviceManager 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时51分19秒
         */
        ~LogDeviceManager();

        /**
         * @brief is_device_exist 判断指定设备device_name是否存在
         *
         * @param device_name 设备名称
         *
         * @return 当设备存在时返回true；否则返回false
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时51分48秒
         */
        bool is_device_exist(const char* device_name);

        /**
         * @brief get_device_loglevel 获取指定设备的日志级别
         *
         * @param device_name 设备名称
         *
         * @return 日志级别。当设备名称指定的设备不存在时，返回BGCC_LOGLEVEL_NOLOG
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时52分34秒
         */
        int32_t get_device_loglevel(const char* device_name);

        /**
         * @brief write 将日志写入设备device_name中
         *
         * @param device_name 设备名称
         * @param log_message 日志信息
         *
         * @return 成功则返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时55分28秒
         */
        int32_t write(const char* device_name, const struct log_message_t& log_message);

    private:
        /**
         * @brief add_device 将新设备添加到设备列表中
         *
         * @param device 新设备
         *
         * @return 操作成功返回0。当新设备名称与已有设备名称相同时，则认为添加失败，返回非0值
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时57分33秒
         */
        int32_t add_device(ILogDevice* device);

        /**
         * @brief get_device 根据设备名称获取设备
         *
         * @param device_name 设备名称
         *
         * @return 设备指针。当指定设备不存在时返回NULL
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时58分33秒
         */
        ILogDevice* get_device(const char* device_name);

        std::vector<ILogDevice*> _devices;

        /**
         * @brief LogDeviceManager 禁用显示构造
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时57分04秒
         */
        LogDeviceManager();

        /**
         * @brief operator= 禁用拷贝构造
         *
         * @param LogDeviceManager
         *
         * @return 
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 10时57分15秒
         */
        LogDeviceManager& operator=(const LogDeviceManager&);

    private:
        friend void load_default_device();
        friend void load_conf_device(const char*);
    };
}
#endif // _BGCC2_LOG_DEVICE_MANAGER_H_

