/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_LOG_DEVICE_H_
#define _BGCC2_LOG_DEVICE_H_

#include <stdio.h>      // for FILE
#include <vector>

#ifndef _WIN32
#include <pthread.h>    // for pthread_mutex_t
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#include "time_util.h"
#include "mutex.h"

#define MAX_DEVICE_NAME_LEN  512
#define MAX_FILE_PATH_LEN    512
#define MAX_LOG_FORMAT_LEN   512

#define BGCC_LOG_SPLIT_POLICY_BY_TIME   0x0
#define BGCC_LOG_SPLIT_POLICY_BY_SIZE   0x1

namespace bgcc {

    /**
     * @brief 用于表示传输到日志设备的日志信息
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 11时05分26秒
     */
    struct log_message_t {
        int32_t loglevel;          /** 日志级别*/
        const char* content;       /** 日志内容，在格式串中用%C表示*/
        const char* loglevel_name; /** 日志级别名称，在格式串中用%N表示*/
        const char* filename;      /** 日志所在文件的文件名，在格式串中用%F表示*/
        const char* line;          /** 日志所在的行号，在格式串中用%L表示*/
		struct ::timeval tv;         /** 日志产生的日期时间，在格式串中用%D表示*/
        long long tid;       /** 线程ID，在格式串中用%T表示*/
    };

    /**
     * @brief 日志设备接口。此类规定了日志设备所具有的公共方法
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 11时06分24秒
     */
    class ILogDevice {
    public:
        /**
         * @brief ~ILogDevice 日志设备接口析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时06分37秒
         */
        virtual ~ILogDevice() {
        }

        /**
         * @brief is_opened 判断日志设备是否已打开
         *
         * @return  若日志设备已打开则返回true；否则返回false。
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时06分53秒
         */
        virtual bool is_opened() const = 0;

        /**
         * @brief open 打开日志设备
         *
         * @param param 保留参数
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时07分09秒
         */
        virtual int32_t open(void* param = NULL) = 0;

        /**
         * @brief close 关闭日志设备
         *
         * @param param 保留参数
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时07分49秒
         */
        virtual int32_t close(void* param = NULL) = 0;

        /**
         * @brief write 写日志
         *
         * @param log_message 日志信息
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时08分32秒
         */
        virtual int32_t write(const struct log_message_t& log_message) = 0;

        /**
         * @brief get_name 返回日志设备名称
         *
         * @return 日志设备名称
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时08分57秒
         */
        virtual const char* get_name() const = 0;

        /**
         * @brief get_loglevel 返回日志设备级别
         *
         * @return 日志设备级别
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时09分15秒
         */
        virtual int32_t get_loglevel() const = 0;

        /**
         * @brief get_split_policy 返回日志设备分割策略
         *
         * @return 日志设备分割策略
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时09分34秒
         */
        virtual int32_t get_split_policy() const = 0;

        /**
         * @brief get_max_size 返回日志设备文件最大值（单位为字节）
         *
         * @return  日志文件最大字节数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时10分04秒
         */
        virtual off_t get_max_size() const = 0;

        /**
         * @brief get_max_record_interval 返回日志设备文件记录最大时长（单位为秒）
         *
         * @return  日志文件记录最大时长
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时10分20秒
         */
        virtual int32_t get_max_record_interval() const = 0;

        /**
         * @brief get_log_format 获取日志设备的日志格式控制串
         *
         * @return  日志设备的日志格式控制串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时10分39秒
         */
        virtual const char* get_log_format() const = 0;
    };

    /**
     * @brief 日志设备的抽象类。此类定义的日志设备的通用方法
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 11时11分09秒
     */
    class AbstractLogDevice : public ILogDevice {
    public:
        /**
         * @brief AbstractLogDevice 构造函数
         *
         * @param name 日志设备名
         * @param loglevel 设备日志级别
         * @param split_policy 设备分割策略
         * @param max_size 日志文件最大字节数
         * @param max_record_interval 日志文件记录最大时长
         * @param log_format 日志格式控制串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时12分24秒
         */
        AbstractLogDevice(
                const char* name,
                int32_t loglevel,
                int32_t split_policy,
                off_t max_size,
                int32_t max_record_interval,
                const char* log_format);

        /**
         * @brief ~AbstractLogDevice 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时13分12秒
         */
        virtual ~AbstractLogDevice();

        /**
         * @brief get_name 返回日志设备名称
         *
         * @return 日志设备名称
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时08分57秒
         */
        virtual const char* get_name() const;

        /**
         * @brief get_loglevel 返回日志设备级别
         *
         * @return 日志设备级别
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时09分15秒
         */
        virtual int32_t get_loglevel() const;

        /**
         * @brief get_split_policy 返回日志设备分割策略
         *
         * @return 日志设备分割策略
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时09分34秒
         */
        virtual int32_t get_split_policy() const;

        /**
         * @brief get_max_size 返回日志设备文件最大值（单位为字节）
         *
         * @return  日志文件最大字节数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时10分04秒
         */
        virtual off_t get_max_size() const;

        /**
         * @brief get_max_record_interval 返回日志设备文件记录最大时长（单位为秒）
         *
         * @return  日志文件记录最大时长
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时10分20秒
         */
        virtual int32_t get_max_record_interval() const;

        /**
         * @brief get_log_format 获取日志设备的日志格式控制串
         *
         * @return  日志设备的日志格式控制串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时10分39秒
         */
        virtual const char* get_log_format() const;

    protected:
        char    _name[MAX_DEVICE_NAME_LEN]; /** 设备名称*/
        int32_t _loglevel;                  /** 设备日志等级*/
        int32_t _split_policy;              /** 分割策略*/
        int32_t _max_size;                  /** 文件最大长度(单位字节)*/
        int32_t _max_record_interval;       /** 文件最大记录周期(单位秒)*/
        char    _log_format[MAX_LOG_FORMAT_LEN]; /** 日志设备的日志格式控制串*/
    };

    /**
     * @brief 文件日志设备类
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 11时16分46秒
     */
    class FileLogDevice : public AbstractLogDevice {
    public:
        /**
         * @brief FileLogDevice 构造函数
         *
         * @param file_path 文件日志设备文件路径
         * @param name 日志设备名
         * @param loglevel 设备日志级别
         * @param split_policy 设备分割策略
         * @param max_size 日志文件最大字节数
         * @param max_record_interval 日志文件记录最大时长
         * @param log_format 日志格式控制串
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时16分56秒
         */
        FileLogDevice(
                const char* file_path,
                const char* name,
                int32_t loglevel,
                int32_t split_policy,
                off_t max_size,
                int32_t max_record_interval,
                const char* log_format);

        /**
         * @brief ~FileLogDevice 析构函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时17分43秒
         */
        virtual ~FileLogDevice();

        /**
         * @brief is_opened 判断日志设备是否已打开
         *
         * @return  若日志设备已打开则返回true；否则返回false。
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时06分53秒
         */
        virtual bool is_opened() const;

        /**
         * @brief open 打开日志设备
         *
         * @param param 保留参数
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时07分09秒
         */
        virtual int32_t open(void* param = NULL);

        /**
         * @brief close 关闭日志设备
         *
         * @param param 保留参数
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时07分49秒
         */
        virtual int32_t close(void* param = NULL);

        /**
         * @brief write 写日志
         *
         * @param log_message 日志信息
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时08分32秒
         */
        virtual int32_t write(const struct log_message_t& log_message);

    private:
        /**
         * @brief exec_time_split_policy 运行time分割策略，满足条件时生成新的日志文件
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时18分31秒
         */
        int32_t exec_time_split_policy();

        /**
         * @brief exec_size_split_policy 运行size分割策略，满足条件时生成新的日志文件
         *
         * @param len 待写入的日志内容字符串字符数
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时18分44秒
         */
        int32_t exec_size_split_policy(size_t len);

        /**
         * @brief get_file_stat 获取日志文件的文件状态
         *
         * @param state 文件状态
         *
         * @return  成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时19分19秒
         */
        int32_t get_file_stat(struct stat& state) const;

        /**
         * @brief format_log_message 格式化日志信息
         *
         * @param logbuf 日志信息接收缓冲区
         * @param logbufsiz 日志信息缓冲区大小
         * @param log_message 日志信息结构体
         *
         * @return 返回格式化后的字节数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月12日 11时20分34秒
         */
        int32_t format_log_message(char* logbuf, int32_t logbufsiz,
                const struct log_message_t& log_message);

    private:
        std::string create_filename_suffix();

        char _file_path[MAX_FILE_PATH_LEN]; /** 文件全路径名*/
        FILE* _fp;  /** 文件指针*/
        Mutex _mutex;
		struct ::timeval _create_time;  /** 文件的创建时间, 用于按time日志分割策略, 采用此成员的原因是通过fstat得到的stat变量无法表示文件创建时间？*/
        off_t _file_size; /** 存放当前日志文件大小*/

    };
}
#endif // _BGCC2_LOG_DEVICE_H_

