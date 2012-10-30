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
 * @file     bgcc_Logger.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 13时38分51秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_Logger.h"

using namespace bgcc;

/*
 * Class:     bgcc_Logger
 * Method:    open
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Logger_open
  (JNIEnv *env, jobject obj, jstring conf) {
      const char* str;
      str = env->GetStringUTFChars(conf, NULL);
      if (str == NULL) {
          return -1;
      }

      log_open(str);
      env->ReleaseStringUTFChars(conf, str);
      return 0;
  }

/*
 * Class:     bgcc_Logger
 * Method:    close
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Logger_close
  (JNIEnv *, jobject) {
      return log_close();
  }

/*
 * Class:     bgcc_Logger
 * Method:    trace
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bgcc_Logger_trace
  (JNIEnv *env, jobject obj, jstring device, jstring content) {
      const char* pDevice = env->GetStringUTFChars(device, NULL);
      if (pDevice == NULL) {
          return;
      }

      const char* pContent = env->GetStringUTFChars(content, NULL);
      if (pContent == NULL) {
          env->ReleaseStringUTFChars(device, pDevice);
          return;
      }

      BGCC_TRACE(pDevice, pContent);

      env->ReleaseStringUTFChars(device, pDevice);
      env->ReleaseStringUTFChars(content, pContent);
  }

/*
 * Class:     bgcc_Logger
 * Method:    debug
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bgcc_Logger_debug
  (JNIEnv *env, jobject obj, jstring device, jstring content) {
      const char* pDevice = env->GetStringUTFChars(device, NULL);
      if (pDevice == NULL) {
          return;
      }

      const char* pContent = env->GetStringUTFChars(content, NULL);
      if (pContent == NULL) {
          env->ReleaseStringUTFChars(device, pDevice);
          return;
      }

      BGCC_DEBUG(pDevice, pContent);

      env->ReleaseStringUTFChars(device, pDevice);
      env->ReleaseStringUTFChars(content, pContent);
  }

/*
 * Class:     bgcc_Logger
 * Method:    notice
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bgcc_Logger_notice
  (JNIEnv *env, jobject obj, jstring device, jstring content) {
      const char* pDevice = env->GetStringUTFChars(device, NULL);
      if (pDevice == NULL) {
          return;
      }

      const char* pContent = env->GetStringUTFChars(content, NULL);
      if (pContent == NULL) {
          env->ReleaseStringUTFChars(device, pDevice);
          return;
      }

      BGCC_NOTICE(pDevice, pContent);

      env->ReleaseStringUTFChars(device, pDevice);
      env->ReleaseStringUTFChars(content, pContent);
  }

/*
 * Class:     bgcc_Logger
 * Method:    warn
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bgcc_Logger_warn
  (JNIEnv *env, jobject obj, jstring device, jstring content) {
      const char* pDevice = env->GetStringUTFChars(device, NULL);
      if (pDevice == NULL) {
          return;
      }

      const char* pContent = env->GetStringUTFChars(content, NULL);
      if (pContent == NULL) {
          env->ReleaseStringUTFChars(device, pDevice);
          return;
      }

      BGCC_WARN(pDevice, pContent);

      env->ReleaseStringUTFChars(device, pDevice);
      env->ReleaseStringUTFChars(content, pContent);
  }

/*
 * Class:     bgcc_Logger
 * Method:    fatal
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bgcc_Logger_fatal
  (JNIEnv *env, jobject obj, jstring device, jstring content) {
      const char* pDevice = env->GetStringUTFChars(device, NULL);
      if (pDevice == NULL) {
          return;
      }

      const char* pContent = env->GetStringUTFChars(content, NULL);
      if (pContent == NULL) {
          env->ReleaseStringUTFChars(device, pDevice);
          return;
      }

      BGCC_FATAL(pDevice, pContent);

      env->ReleaseStringUTFChars(device, pDevice);
      env->ReleaseStringUTFChars(content, pContent);
  }
