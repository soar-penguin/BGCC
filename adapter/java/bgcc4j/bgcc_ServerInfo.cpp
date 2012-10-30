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
 * @file     bgcc_ServerInfo.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月01日 15时30分13秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_ServerInfo.h"

using namespace bgcc;

/*
 * Class:     bgcc_ServerInfo
 * Method:    create
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_ServerInfo_create
  (JNIEnv *env, jobject serverInfo, jstring host, jint port) {
      BGCC_TRACE("bgcc", "ServerInfo::create begin");
      jclass serverInfoCls = env->GetObjectClass(serverInfo);
      jfieldID serverInfoAddressFid = env->GetFieldID(serverInfoCls, "serverInfoAddress", "J");

      const char* pHost = env->GetStringUTFChars(host, NULL);
      if (pHost == NULL) {
          BGCC_WARN("bgcc", "ServerInfo::create: allocate string failed");
          return -1;
      }

      ServerInfo* pServerInfo = new(std::nothrow) ServerInfo(pHost, (int32_t)port);
      env->ReleaseStringUTFChars(host, pHost);
      if (!pServerInfo) {
          BGCC_WARN("bgcc", "Create ServerInfo failed");
          return -1;
      }
      
      jlong addr = (jlong)pServerInfo;
      env->SetLongField(serverInfo, serverInfoAddressFid, addr);
      BGCC_TRACE("bgcc", "ServerInfo::create end\n");
      return 0;
  }

/*
 * Class:     bgcc_ServerInfo
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_ServerInfo_destroy
  (JNIEnv *env, jobject serverInfo) {
      BGCC_TRACE("bgcc", "ServerInfo::destroy begin");
      jclass serverInfoCls = env->GetObjectClass(serverInfo);
      jfieldID serverInfoAddressFid = env->GetFieldID(serverInfoCls, "serverInfoAddress", "J");

      ServerInfo* pServerInfo = (ServerInfo*)env->GetLongField(serverInfo, serverInfoAddressFid);
      if (!pServerInfo) {
          delete pServerInfo;
          pServerInfo = NULL;
      }
      
      BGCC_TRACE("bgcc", "ServerInfo::destroy end\n");
      return 0;
  }


