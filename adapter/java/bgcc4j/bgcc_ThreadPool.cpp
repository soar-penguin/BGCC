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
 * @file     bgcc_ThreadPool.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月01日 13时17分05秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_ThreadPool.h"

using namespace bgcc;
/*
 * Class:     bgcc_ThreadPool
 * Method:    create
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_ThreadPool_create
  (JNIEnv *env, jobject threadPool, jint nThread) {
      BGCC_TRACE("bgcc", "ThreadPool::create begin");
      jclass threadPoolCls = env->GetObjectClass(threadPool);
      jfieldID threadPoolAddressFid = env->GetFieldID(threadPoolCls, "threadPoolAddress", "J");

      ThreadPool* pThreadPool = new(std::nothrow) ThreadPool;
      if (!pThreadPool) {
          BGCC_WARN("bgcc", "Create ThreadPool failed");
          return -1;
      }
      pThreadPool->init((int32_t)nThread);
      jlong addr = (jlong)pThreadPool;
      env->SetLongField(threadPool, threadPoolAddressFid, addr);
      BGCC_TRACE("bgcc", "ThreadPool::create end\n");
      return 0;
  }

/*
 * Class:     bgcc_ThreadPool
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_ThreadPool_destroy
  (JNIEnv *env, jobject threadPool) {
      BGCC_TRACE("bgcc", "ThreadPool::destroy begin");
      jclass threadPoolCls = env->GetObjectClass(threadPool);
      jfieldID threadPoolAddressFid = env->GetFieldID(threadPoolCls, "threadPoolAddress", "J");

      ThreadPool* pThreadPool = (ThreadPool*)env->GetLongField(threadPool, threadPoolAddressFid);
      if (pThreadPool) {
          delete pThreadPool;
          pThreadPool = NULL;
          env->SetLongField(threadPool, threadPoolAddressFid, 0);
      }
      BGCC_TRACE("bgcc", "ThreadPool::destroy end\n");
      return 0;
  }

