/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _WIN32

#include <string.h>
#include "event_poll.h"

namespace bgcc {

    EventLoop::EventLoop() :
        _state(S_UNINIT), _stopped(true), _epfd(-1) {
        }

    int32_t EventLoop::create() {
        if (S_UNINIT != _state) {
            return -1;
        }

        _epfd = epoll_create(MAXNFD);

        if (-1 == _epfd) {
            return -1;
        }
        else {
            _state = S_INIT;
            return 0;
        }
    }

    int32_t EventLoop::destroy() {
        close(_epfd);
        _state = S_DESTROYED;
        return 0;
    }

    int32_t EventLoop::add_event(Event* event) {
        if (S_INIT != _state && S_LOOP != _state) {
            return -1;
        }

        if (NULL == event) {
            return 0;
        }

        int32_t fd = event->fd;
        uint32_t mask = event->mask;

        int32_t op;
        if (EVENT_NONE == _events[fd].mask) {
            op = EPOLL_CTL_ADD;
        }
        else {
            op = EPOLL_CTL_MOD;
            mask |= _events[fd].mask;
        }
        _events[fd].mask = mask;

        struct epoll_event ee;

        // To fix valgrind error: Syscall param epoll_ctl(event) points to uninitialised byte(s)
        memset(&ee.data, 0, sizeof(ee.data));

        ee.data.fd = fd;
        ee.events = 0;

        if (mask & EVENT_READ) {
            ee.events |= EPOLLIN;
            _events[fd].read_cb = event->read_cb;
            _events[fd].read_cb_arg = event->read_cb_arg;
        }

        if (mask & EVENT_WRITE) {
            ee.events |= EPOLLOUT;
            _events[fd].write_cb = event->write_cb;
            _events[fd].write_cb_arg = event->write_cb_arg;
        }

        if (mask & EVENT_ERROR) {
            ee.events |= EPOLLERR;
            _events[fd].error_cb = event->error_cb;
            _events[fd].error_cb_arg = event->error_cb_arg;
        }

        return epoll_ctl(_epfd, op, fd, &ee);
    }

    int32_t EventLoop::del_event(Event* event) {
        if (S_INIT != _state && S_LOOP != _state) {
            return -1;
        }

        if (NULL == event) {
            return 0;
        }

        int32_t fd = event->fd;
        uint32_t mask = _events[fd].mask & (~event->mask);
        _events[fd].mask = mask;

        struct epoll_event ee;
        ee.data.fd = fd;
        ee.events = 0;
        if (mask & EVENT_READ) ee.events |= EPOLLIN;
        if (mask & EVENT_WRITE) ee.events |= EPOLLOUT;

        int32_t op;
        if (mask != EVENT_NONE) {
            op = EPOLL_CTL_MOD;
        } else {
            op = EPOLL_CTL_DEL;
        }

        return epoll_ctl(_epfd, op, fd, &ee);
    }

    int32_t EventLoop::loop() {
        if (S_INIT != _state) {
            return -1;
        }
        _state = S_LOOP;
        _stopped = false;

        while (!_stopped) {
            int32_t numevents;
            numevents = epoll_wait(_epfd, _ep_events, MAXNFD, 10);

            if (numevents > 0) {
                int j;

                for (j = 0; j < numevents; j++) {
                    struct epoll_event* e = _ep_events + j;
                    int32_t fd = e->data.fd;

                    if (e->events & EPOLLIN) {
                        if (_events[fd].read_cb)
                            (_events[fd].read_cb)(this, fd, _events[fd].read_cb_arg);
                    }
                    if (e->events & EPOLLOUT) {
                        if (_events[fd].write_cb)
                            (_events[fd].write_cb)(this, fd, _events[fd].write_cb_arg);
                    }
                    if (e->events & EPOLLERR) {
                        if (_events[fd].error_cb)
                            (_events[fd].error_cb)(this, fd, _events[fd].error_cb_arg);
                    }
                }
            }
        }
        _state = S_STOP;
        return 0;
    }

    int32_t EventLoop::unloop() {
        _stopped = true;
        return 0;
    }

    bool EventLoop::is_stopped() const {
        return _stopped;
    }
}

#endif

