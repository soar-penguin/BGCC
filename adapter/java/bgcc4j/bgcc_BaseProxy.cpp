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
 * @file     bgcc_BaseProxy.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月03日 13时29分59秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_BaseProxy.h"

using namespace bgcc;

/*
 * Class:     bgcc_BaseProxy
 * Method:    create
 * Signature: (Lbgcc/ServerInfo;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_BaseProxy_create
  (JNIEnv *env, jobject baseProxy, jobject serverInfo) {
      jclass serverInfoCls = env->GetObjectClass(serverInfo);
      jfieldID serverInfoAddressFid = env->GetFieldID(serverInfoCls, "serverInfoAddress", "J");

      ServerInfo* pServerInfo = (ServerInfo*)env->GetLongField(serverInfo, serverInfoAddressFid);
      if (!pServerInfo) {
          return -1;
      }

      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = new(std::nothrow) BaseProxy(*pServerInfo, 3);
	  pBaseProxy->set_errno(BgccSockGetLastError());
      jlong addr = (jlong)pBaseProxy;
      env->SetLongField(baseProxy, proxyAddressFid, addr);
      return 0;
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_BaseProxy_destroy
  (JNIEnv *env, jobject baseProxy) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      if (pBaseProxy) {
          delete pBaseProxy;
          pBaseProxy = NULL;
          env->SetLongField(baseProxy, proxyAddressFid, 0);
      }
      return 0;
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    getErrno
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_BaseProxy_getErrno
  (JNIEnv *env, jobject baseProxy) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      SharedPointer<BinaryProtocol>* pProtocol = new SharedPointer<BinaryProtocol>();
      if (pBaseProxy) {
          jint j_e = pBaseProxy->get_errno();
          return j_e;
      }
      return -1;
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    setErrno
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_BaseProxy_setErrno
  (JNIEnv *env, jobject baseProxy, jint j_e) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      SharedPointer<BinaryProtocol>* pProtocol = new SharedPointer<BinaryProtocol>();
      if (pBaseProxy) {
          pBaseProxy->set_errno(j_e);
      }
	  return 0;
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    getProtocol
 * Signature: ()Lbgcc/Protocol;
 */
JNIEXPORT jobject JNICALL Java_bgcc_BaseProxy_getProtocol
  (JNIEnv *env, jobject baseProxy) {
      BGCC_TRACE("bgcc", "Enter BaseProxy::getProtocol");
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      SharedPointer<BinaryProtocol>* pProtocol = new SharedPointer<BinaryProtocol>();
      if (pBaseProxy) {
          if (0 != pBaseProxy->_protocols.get(*pProtocol, 1000)) {
              return NULL;
          }

          jclass protocolCls = env->FindClass("bgcc/Protocol");
          if (protocolCls == NULL){
              return NULL;
          }

          jmethodID protocolConstructorId = env->GetMethodID(protocolCls, "<init>","(J)V");
          if (protocolConstructorId == NULL){
              return NULL;
          }

          jobject j_protocol = env->NewObject(protocolCls, protocolConstructorId, (jlong)pProtocol); 
          BGCC_TRACE("bgcc", "Leave BaseProxy::getProtocol");
          return j_protocol;
      }
      return NULL;
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    putProtocol
 * Signature: (Lbgcc/Protocol;)V
 */
JNIEXPORT void JNICALL Java_bgcc_BaseProxy_putProtocol
  (JNIEnv *env, jobject baseProxy, jobject protocol) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      if (pBaseProxy) {
          jclass protocolCls = env->GetObjectClass(protocol);
          jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");
          SharedPointer<BinaryProtocol>* pProtocol =
              (SharedPointer<BinaryProtocol>*)env->GetLongField(protocol, protocolAddressFid);
          if (pProtocol) {
              pBaseProxy->_protocols.put(*pProtocol);
              pProtocol = NULL;
              env->SetLongField(protocol, protocolAddressFid, 0);
          }
      }
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    getName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_bgcc_BaseProxy_getName
  (JNIEnv *env, jobject baseProxy) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      if (pBaseProxy) {
          std::string name = pBaseProxy->get_name();
          jstring j_name = env->NewStringUTF(name.c_str());
          return j_name;
      }
      return NULL;
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    setName
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bgcc_BaseProxy_setName
  (JNIEnv *env, jobject baseProxy, jstring name) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      if (pBaseProxy) {
          const char* str = env->GetStringUTFChars(name, JNI_FALSE);
          pBaseProxy->set_name(str);
          env->ReleaseStringUTFChars(name, str);
      }
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    getWhoAmI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_bgcc_BaseProxy_getWhoAmI
  (JNIEnv *env, jobject baseProxy) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      if (pBaseProxy) {
          std::string whoami = pBaseProxy->get_whoami();
          jstring j_whoami = env->NewStringUTF(whoami.c_str());
          return j_whoami;
      }
      return NULL;
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    setWhoAmI
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_bgcc_BaseProxy_setWhoAmI
  (JNIEnv *env, jobject baseProxy, jstring whoami) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      if (pBaseProxy) {
          const char* str = env->GetStringUTFChars(whoami, JNI_FALSE);
          pBaseProxy->set_whoami(str);
          env->ReleaseStringUTFChars(whoami, str);
      }
  }

/*
 * Class:     bgcc_BaseProxy
 * Method:    getTicketId
 * Signature: (Ljava/lang/String;Lbgcc/IntHolder;ZLbgcc/Protocol;Lbgcc/Protocol;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_BaseProxy_getTicketId
  (JNIEnv *env, jobject baseProxy, jstring fnName, jobject ticketIdHolder, jboolean last, jobject inProtocol, jobject outProtocol) {
      jclass baseProxyCls = env->GetObjectClass(baseProxy);
      jfieldID proxyAddressFid = env->GetFieldID(baseProxyCls, "proxyAddress", "J");

      BaseProxy* pBaseProxy = (BaseProxy*)env->GetLongField(baseProxy, proxyAddressFid);
      if (!pBaseProxy) {
          return -1;
      }

      const char* name_str = env->GetStringUTFChars(fnName, JNI_FALSE);
      int32_t ticketId = 0;

      jclass inProtocolCls = env->GetObjectClass(inProtocol);
      jfieldID inProtocolValueFid = env->GetFieldID(inProtocolCls, "protocolAddress", "J");
      SharedPointer<BinaryProtocol>* pInProtocol
          = (SharedPointer<BinaryProtocol>*)env->GetLongField(inProtocol, inProtocolValueFid);
      if (!pInProtocol || !pInProtocol->is_valid()) {
          return -1;
      }

      jclass outProtocolCls = env->GetObjectClass(outProtocol);
      jfieldID outProtocolValueFid = env->GetFieldID(outProtocolCls, "protocolAddress", "J");
      SharedPointer<IProtocol>* pOutProtocol
          = (SharedPointer<IProtocol>*)env->GetLongField(outProtocol, outProtocolValueFid);
      if (!pOutProtocol || !pOutProtocol->is_valid()) {
          return -1;
      }

      BGCC_TRACE("bgcc", "Before call C++ Interface __get_ticket_id");
	  pBaseProxy->__get_ticket_id(name_str, ticketId, last ? true : false, *pInProtocol, *pOutProtocol);
      BGCC_TRACE("bgcc", "End call C++ Interface __get_ticket_id: ticketId: %d", ticketId);

      jclass ticketIdHolderCls = env->GetObjectClass(ticketIdHolder);
      jfieldID ticketIdValueFid = env->GetFieldID(ticketIdHolderCls, "value", "I");
      env->SetIntField(ticketIdHolder, ticketIdValueFid, ticketId);

      env->ReleaseStringUTFChars(fnName, name_str);
      return 0;
  }


