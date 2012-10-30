/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_LOG_H_
#define _BGCC2_LOG_H_

#include <sstream>
#ifndef _WIN32
#include <pthread.h>
#include <sys/time.h>
#endif

#include "log_device_manager.h"
#include "thread_util.h"
#include "time_util.h"



#define STR(x) STR2(x)
#define STR2(x) #x
#ifdef _WIN32
#define GETTIMEOFDAY bgcc::gettimeofday
#else
#define GETTIMEOFDAY gettimeofday
#endif

#define BGCC_RAW_WRITE(DEVICE, LOGLEVEL, LOGLEVEL_NAME, CONTENT) \
    do { \
        int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(DEVICE); \
        if (___device_log_level <= LOGLEVEL) { \
            struct timeval ___tv; \
            GETTIMEOFDAY(&___tv, NULL); \
            struct bgcc::log_message_t log_message = { \
                LOGLEVEL, \
                CONTENT, \
                LOGLEVEL_NAME, \
                __FILE__, \
                STR(__LINE__), \
                ___tv, \
				bgcc::ThreadUtil::self_id() \
            }; \
            bgcc::LogDeviceManager::get_instance()->write(DEVICE, log_message); \
        } \
    } while(0)

#define BGCC_RAW_TRACE(DEVICE,  CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_TRACE,  "trace",  CONTENT)
#define BGCC_RAW_DEBUG(DEVICE,  CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_DEBUG,  "debug",  CONTENT)
#define BGCC_RAW_NOTICE(DEVICE, CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_NOTICE, "notice", CONTENT)
#define BGCC_RAW_WARN(DEVICE,   CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_WARN,   "warn",   CONTENT)
#define BGCC_RAW_FATAL(DEVICE,  CONTENT)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_FATAL,  "fatal",  CONTENT)

#define BGCC_STREAM_WRITE(DEVICE, LOGLEVEL, LOGLEVEL_NAME, CONTENT) \
	do { \
	int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(DEVICE); \
	if (___device_log_level <= LOGLEVEL) { \
	std::ostringstream ___ss; \
	___ss << CONTENT; \
	std::string ___str = ___ss.str(); \
struct timeval ___tv; \
	GETTIMEOFDAY(&___tv, NULL); \
struct bgcc::log_message_t log_message = { \
	LOGLEVEL, \
	___str.c_str(), \
	LOGLEVEL_NAME, \
	__FILE__, \
	STR(__LINE__), \
	___tv, \
	bgcc::ThreadUtil::self_id() \
}; \
	bgcc::LogDeviceManager::get_instance()->write(DEVICE, log_message); \
	} \
	} while(0)

#define BGCC_STREAM_TRACE(DEVICE,  MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_TRACE,  "trace",   MESSAGE)
#define BGCC_STREAM_DEBUG(DEVICE,  MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_DEBUG,  "debug",   MESSAGE)
#define BGCC_STREAM_NOTICE(DEVICE, MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_NOTICE, "notice",  MESSAGE)
#define BGCC_STREAM_WARN(DEVICE,   MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_WARN,   "warn",    MESSAGE)
#define BGCC_STREAM_FATAL(DEVICE,  MESSAGE)    BGCC_STREAM_WRITE(DEVICE, BGCC_LOGLEVEL_FATAL,  "fatal",   MESSAGE)

#ifndef _WIN32

#define BGCC_WRITE(DEVICE, LOGLEVEL, LOGLEVEL_NAME, FORMAT_AND_CONTENT...) \
    do { \
        int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(DEVICE); \
        if (___device_log_level <= LOGLEVEL) { \
            char ___buffer[1024]; \
            snprintf(___buffer, 1024, FORMAT_AND_CONTENT); \
            struct timeval ___tv; \
            gettimeofday(&___tv, NULL); \
            struct bgcc::log_message_t log_message = { \
                LOGLEVEL, \
                ___buffer, \
                LOGLEVEL_NAME, \
                __FILE__, \
                STR(__LINE__), \
                ___tv, \
                bgcc::ThreadUtil::self_id() \
            }; \
            bgcc::LogDeviceManager::get_instance()->write(DEVICE, log_message); \
        } \
    } while(0)

#define BGCC_TRACE(DEVICE,  FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_TRACE,  "trace",  ##FORMAT)
#define BGCC_DEBUG(DEVICE,  FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_DEBUG,  "debug",  ##FORMAT)
#define BGCC_NOTICE(DEVICE, FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_NOTICE, "notic", ##FORMAT)
#define BGCC_WARN(DEVICE,   FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_WARN,   "warn ",   ##FORMAT)
#define BGCC_FATAL(DEVICE,  FORMAT...)    BGCC_WRITE(DEVICE, BGCC_LOGLEVEL_FATAL,  "fatal",  ##FORMAT)

#else

class CTraceFileAndLineInfo
{
public:
	CTraceFileAndLineInfo(
		const char* file_name,
		int32_t line_no,
		int32_t log_level,
		const char* log_level_name)
		: _file_name(file_name), _line_no(line_no),
		_log_level(log_level), _log_level_name(log_level_name)
	{}

	
	void __cdecl operator()(const char* device_name, const char* fmt, ...) const
	{
		std::stringstream ss;
		ss << _line_no;
		std::string line_no;
		ss >> line_no;
		va_list ptr; va_start(ptr, fmt);
		int32_t ___device_log_level = bgcc::LogDeviceManager::get_instance()->get_device_loglevel(device_name);
		if (___device_log_level <= _log_level) {
			char ___buffer[1024];
			_vsnprintf(___buffer, 1024, fmt, ptr);
			struct ::timeval ___tv;
			bgcc::gettimeofday(&___tv, NULL);
			struct bgcc::log_message_t log_message = {
				_log_level,
				___buffer,
				_log_level_name,
				_file_name,
				line_no.c_str(),
				___tv, \
				bgcc::ThreadUtil::self_id()
			};
			bgcc::LogDeviceManager::get_instance()->write(device_name, log_message);
		}
		va_end(ptr);
	}

private:
	const char* const _file_name;
	int32_t _line_no;
	int32_t _log_level;
	const char* const _log_level_name;
};

#define BGCC_TRACE CTraceFileAndLineInfo(__FILE__, __LINE__, BGCC_LOGLEVEL_TRACE, "trace")
#define BGCC_DEBUG CTraceFileAndLineInfo(__FILE__, __LINE__, BGCC_LOGLEVEL_DEBUG, "debug")
#define BGCC_NOTICE CTraceFileAndLineInfo(__FILE__, __LINE__, BGCC_LOGLEVEL_NOTICE, "notice")
#define BGCC_WARN CTraceFileAndLineInfo(__FILE__, __LINE__, BGCC_LOGLEVEL_WARN, "warn")
#define BGCC_FATAL CTraceFileAndLineInfo(__FILE__, __LINE__, BGCC_LOGLEVEL_FATAL, "fatal")


#endif
#endif // _BGCC2_LOG_H_

