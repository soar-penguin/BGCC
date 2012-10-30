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
 * @file     bgcc_Processor.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月02日 13时56分47秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_Processor.h"
#include "jni_processor.h"

using namespace bgcc;

/*
 * Class:     bgcc_Processor
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Processor_create
  (JNIEnv *env, jobject processor) {
      jclass processorCls = env->GetObjectClass(processor);
      jfieldID processorAddressFid = env->GetFieldID(processorCls, "processorAddress", "J");
      jobject g_processor = env->NewGlobalRef(processor);
      JavaVM* jvm = NULL;
      env->GetJavaVM(&jvm);
      SharedPointer<IProcessor>* pProcessor = 
          new(std::nothrow) SharedPointer<IProcessor>(
                  new(std::nothrow) jni_processor_t(jvm, g_processor));
      if (!pProcessor || !pProcessor->is_valid()) {
          return -1;
      }
      
      jlong addr = (jlong)pProcessor;
      env->SetLongField(processor, processorAddressFid, addr);
      return 0;
  }

/*
 * Class:     bgcc_Processor
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Processor_destroy
  (JNIEnv *env, jobject processor) {
      jclass processorCls = env->GetObjectClass(processor);
      jfieldID processorAddressFid = env->GetFieldID(processorCls, "processorAddress", "J");

      jni_processor_t* pProcessor = (jni_processor_t*)env->GetLongField(processor, processorAddressFid);
      if (pProcessor) {
          delete pProcessor;
          pProcessor = NULL;
          env->SetLongField(processor, processorAddressFid, 0);
      }
      return 0;
  }

