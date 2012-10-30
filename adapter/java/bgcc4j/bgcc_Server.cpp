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
 * @file     bgcc_Server.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月01日 12时59分05秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_Server.h"

using namespace bgcc;

/*
 * Class:     bgcc_Server
 * Method:    serve
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Server_serve
  (JNIEnv *env, jobject server) {
      BGCC_TRACE("bgcc", "Server::serve begin");
      jclass serverCls = env->GetObjectClass(server);
      jfieldID serverAddressFid = env->GetFieldID(serverCls, "serverAddress", "J");
      
      Server* pServer = (Server*)env->GetLongField(server, serverAddressFid);
      int32_t ret = -1;
      if (pServer) {
          ret = pServer->serve();
      }
      BGCC_TRACE("bgcc", "Server::serve end\n");
      return ret;
  }

/*
 * Class:     bgcc_Server
 * Method:    stop
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Server_stop
  (JNIEnv *env, jobject server) {
      BGCC_TRACE("bgcc", "Server::stop begin");
      jclass serverCls = env->GetObjectClass(server);
      jfieldID serverAddressFid = env->GetFieldID(serverCls, "serverAddress", "J");
      
      Server* pServer = (Server*)env->GetLongField(server, serverAddressFid);
      int32_t ret = -1;
      if (pServer) {
          ret = pServer->stop();
      }
      BGCC_TRACE("bgcc", "Server::stop end\n");
      return ret;
  }

/*
 * Class:     bgcc_Server
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Server_destroy
  (JNIEnv *env, jobject server) {
      BGCC_TRACE("bgcc", "Server::destroy begin");
      jclass serverCls = env->GetObjectClass(server);
      jfieldID serverAddressFid = env->GetFieldID(serverCls, "serverAddress", "J");
      
      Server* pServer = (Server*)env->GetLongField(server, serverAddressFid);
      if (pServer) {
          delete pServer;
          pServer = NULL;
          env->SetLongField(server, serverAddressFid, 0);
      }
      BGCC_TRACE("bgcc", "Server::destroy end\n");
      return 0;
  }

/*
 * Class:     bgcc_Server
 * Method:    create
 * Signature: (Lbgcc/ServiceManager;Lbgcc/ThreadPool;ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Server_create
  (JNIEnv *env, jobject server, jobject serviceManager, jobject threadPool, jint port, jstring node) {
      BGCC_TRACE("bgcc", "Server::create begin");
      jclass serverCls = env->GetObjectClass(server);
      jfieldID serverAddressFid = env->GetFieldID(serverCls, "serverAddress", "J");

      jclass serviceManagerCls = env->GetObjectClass(serviceManager);
      jfieldID serviceManagerAddressFid = env->GetFieldID(serviceManagerCls, "serviceManagerAddress", "J");

      jclass threadPoolCls = env->GetObjectClass(threadPool);
      jfieldID threadPoolAddressFid = env->GetFieldID(threadPoolCls, "threadPoolAddress", "J");

      ServiceManager* pServiceManager = (ServiceManager*)env->GetLongField(serviceManager, serviceManagerAddressFid);
      if (NULL == pServiceManager) {
          BGCC_WARN("bgcc", "Server::create: serviceManager is null");
          return -1;
      }

      ThreadPool* pThreadPool = (ThreadPool*)env->GetLongField(threadPool, threadPoolAddressFid);
      if (NULL == pThreadPool) {
          BGCC_WARN("bgcc", "Server::create: threadPool is null");
          return -1;
      }

      const char* pNode = env->GetStringUTFChars(node, NULL);
      if (pNode == NULL) {
          BGCC_WARN("bgcc", "Allocate node failed");
          return -1;
      }

      Server* pServer = new(std::nothrow) Server(pServiceManager, pThreadPool, (int32_t)port, pNode);
      env->ReleaseStringUTFChars(node, pNode);
      if (NULL == pServer) {
          BGCC_WARN("bgcc", "Server::create: create server failed");
          return -1;
      }

      jlong addr = (jlong)pServer;
      env->SetLongField(server, serverAddressFid, addr);

      BGCC_TRACE("bgcc", "Server::create end\n");
      return 0;
  }


