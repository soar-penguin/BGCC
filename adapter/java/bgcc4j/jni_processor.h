/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

/***************************************************************************
 * 
 * Copyright (c) 2011 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file bgcc_jni_processor.h
 * @author liujian03(liujian03@baidu.com)
 * @date 2011/09/26 01:47:15
 * @version $Revision$ 
 * @brief 实现runtime的processor类，处理runtime的类似回调功能
 *  
 **/


#ifndef  __BGCC_JNI_PROCESSOR_H_
#define  __BGCC_JNI_PROCESSOR_H_

#include <jni.h>
#include <bgcc.h>

using namespace bgcc;

class jni_processor_t : public IProcessor
{
public:
	jni_processor_t(JavaVM* jvm, jobject obj):
		_jvm(jvm),
		_obj(obj)
	{
	}

	~jni_processor_t(){
		if (_jvm){
			JNIEnv *env = NULL;
			_jvm->AttachCurrentThread((void **)&env, NULL);
			env->DeleteGlobalRef(_obj);
		}

	}

	virtual int32_t process(char* request,
			int32_t request_len,
			SharedPointer<IProtocol> out) {
		BGCC_TRACE("bgcc", "Enter jni_processor_t::process");

		JNIEnv* env = NULL;
		_jvm->AttachCurrentThread((void**)&env, NULL);

		jclass protocolCls = env->FindClass("bgcc/Protocol");
		if (protocolCls == NULL){
			BGCC_WARN("bgcc", "bgcc/Protocol class not found");
			return -1;
		}

		jmethodID protocolConstructorId = env->GetMethodID(protocolCls, "<init>","(J)V");
		if (protocolConstructorId == NULL){
			BGCC_WARN("bgcc", "bgcc/Protocol class constructor not found");
			return -1;
		}
		
		SharedPointer<IProtocol> out_cpy = out;
		jobject protocol = env->NewObject(protocolCls, protocolConstructorId, (jlong)&out_cpy); 

	    jclass processorCls = env->GetObjectClass(_obj);
		if (processorCls == NULL){
			return -1;
		}

    	jmethodID processMethodId = env->GetMethodID(processorCls,
				"process", "(JILbgcc/Protocol;)I");
		if (processMethodId == NULL){
			return -1;
		}

		jint requestLen = (jint)request_len;
		BGCC_TRACE("bgcc", "Before call Java Interface process[request_len: %d]", requestLen);
    	int32_t ret = env->CallIntMethod(_obj, processMethodId, (jlong)request, requestLen, protocol);
		BGCC_TRACE("bgcc", "End call Java Interface process, ret value : %d", ret);

//		env->DeleteLocalRef(protocol);

		BGCC_TRACE("bgcc", "Leave jni_processor::process");
		return ret;
	}

	virtual std::string get_name() const {
		JNIEnv* env = NULL;
		_jvm->AttachCurrentThread((void**)&env, NULL);

	    jclass processorCls = env->GetObjectClass(_obj);
		if (processorCls == NULL){
			return "";
		}

    	jmethodID getNameMethodId = env->GetMethodID(processorCls,
				"getName", "()Ljava/lang/String;");
		if (getNameMethodId == NULL){
			return "";
		}

    	jstring name = (jstring)env->CallObjectMethod(_obj, getNameMethodId);

		const char* str = env->GetStringUTFChars(name, NULL);
		std::string ret_name(str);
		env->ReleaseStringUTFChars(name, str);
		return ret_name;
	}

private:
	JavaVM*		_jvm;
	jobject    _obj;
};
		
















#endif  //__BGCC_JNI_PROCESSOR_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
