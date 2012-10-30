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
 * @file     bgcc_ServiceManager.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 10时55分32秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_ServiceManager.h"

using namespace bgcc;

/*
 * Class:     bgcc_ServiceManager
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_ServiceManager_create
  (JNIEnv *env, jobject serviceManager) {
      BGCC_TRACE("bgcc", "ServiceManager::create begin");
      jclass serviceManagerCls = env->GetObjectClass(serviceManager);
      jfieldID serviceManagerAddressFid = env->GetFieldID(serviceManagerCls, "serviceManagerAddress", "J");

      ServiceManager* pServiceManager = new ServiceManager;
      jlong addr = (jlong)pServiceManager;
      env->SetLongField(serviceManager, serviceManagerAddressFid, addr);
      BGCC_TRACE("bgcc", "ServiceManager::create end\n");
      return 0;
  }

/*
 * Class:     bgcc_ServiceManager
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_ServiceManager_destroy
  (JNIEnv *env, jobject serviceManager) {
      BGCC_TRACE("bgcc", "ServiceManager::destroy begin");
      jclass serviceManagerCls = env->GetObjectClass(serviceManager);
      jfieldID serviceManagerAddressFid = env->GetFieldID(serviceManagerCls, "serviceManagerAddress", "J");
      
      ServiceManager* pServiceManager = (ServiceManager*)env->GetLongField(serviceManager, serviceManagerAddressFid);
      if (pServiceManager) {
          delete pServiceManager;
          pServiceManager = NULL;
          env->SetLongField(serviceManager, serviceManagerAddressFid, 0);
      }
      BGCC_TRACE("bgcc", "ServiceManager::destroy end\n");
      return 0;
  }

/*
 * Class:     bgcc_ServiceManager
 * Method:    addService
 * Signature: (Lbgcc/Processor;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_ServiceManager_addService
  (JNIEnv *env, jobject serviceManager, jobject processor) {
      BGCC_TRACE("bgcc", "ServiceManager::addService begin");
      if (!processor) {
          BGCC_WARN("bgcc", "ServiceManager::addService: processor is null\n");
          return -1;
      }

      jclass serviceManagerCls = env->GetObjectClass(serviceManager);
      jfieldID serviceManagerAddressFid = env->GetFieldID(serviceManagerCls, "serviceManagerAddress", "J");
      
      ServiceManager* pServiceManager = (ServiceManager*)env->GetLongField(serviceManager, serviceManagerAddressFid);
      if (pServiceManager) {
          jclass processorCls = env->GetObjectClass(processor);
          jfieldID processorFid = env->GetFieldID(processorCls, "processorAddress", "J");

          SharedPointer<IProcessor>* pProcessor = (SharedPointer<IProcessor>*)env->GetLongField(processor, processorFid);
          if (NULL == pProcessor || !pProcessor->is_valid()) {
              BGCC_WARN("bgcc", "ServiceManager::addService: processor is invalid\n");
              return -1;
          }

          BGCC_TRACE("bgcc", "Before call C++ Interface add_service");
          pServiceManager->add_service(*pProcessor);
          BGCC_TRACE("bgcc", "End call C++ Interface add_service");
      }
      BGCC_TRACE("bgcc", "ServiceManager::addService end\n");
      return 0;
  }

