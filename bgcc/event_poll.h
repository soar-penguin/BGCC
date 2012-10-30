/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_EVENT_POLL_H_
#define _BGCC2_EVENT_POLL_H_

#ifndef _WIN32

#include <sys/epoll.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXNFD 10000

namespace bgcc {

    /**
     * @brief 事件类型标识
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月14日 20时02分50秒
     */
    enum {
        EVENT_NONE  = 0x0,  /** 无事件*/
        EVENT_READ  = 0x1,  /** 读事件*/
        EVENT_WRITE = 0x2,  /** 写事件*/
        EVENT_ERROR = 0x4   /** 错误事件*/
    };

    class EventLoop;    /** 前置声明*/

    /**
     * @brief  事件处理回调函数类型
     *
     * @param el 事件循环队列
     * @param fd 文件描述符
     * @param arg 参数
     *
     * @return 
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月14日 20时01分17秒
     */
    typedef void (*callback_func_t)(EventLoop* el, int32_t fd, void* arg);

    /**
     * @brief 封装事件及事件处理函数
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月14日 20时00分59秒
     */
    struct Event {
        /**
         * @brief Event 事件类
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月14日 20时04分59秒
         */
        Event() :
            fd(-1),
            mask(EVENT_NONE),
            read_cb(NULL),
            write_cb(NULL),
            error_cb(NULL),
            read_cb_arg(NULL),
            write_cb_arg(NULL),
            error_cb_arg(NULL) {
            }

        int32_t fd; /** 事件对应的fd*/
        uint32_t mask;  /** 事件标识位*/
        callback_func_t read_cb;    /** 读回调*/
        callback_func_t write_cb;   /** 写回调*/
        callback_func_t error_cb;   /** 错误回调*/
        void* read_cb_arg;
        void* write_cb_arg;
        void* error_cb_arg;
    };

    /**
     * @brief 事件循环
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月14日 20时05分36秒
     */
    class EventLoop {
    public:
        /**
         * @brief EventLoop 构造函数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月14日 20时19分50秒
         */
        EventLoop();

        /**
         * @brief create 创建内部epoll
         *
         * @return 成功返回0
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月14日 20时19分59秒
         */
        int32_t create();
        int32_t destroy();

        int32_t add_event(Event* event);
        int32_t del_event(Event* event);

        int32_t loop();
        int32_t unloop();
        bool is_stopped() const;
    private:
        enum state_t {
            S_UNINIT,
            S_INIT,
            S_LOOP,
            S_STOP,
            S_DESTROYED
        };
    private:
        state_t _state;
        mutable bool _stopped;
        int32_t _epfd;
        struct epoll_event _ep_events[MAXNFD];
        Event _events[MAXNFD];
    };
}

#endif

#endif // _BGCC2_EVENT_POLL_H_

