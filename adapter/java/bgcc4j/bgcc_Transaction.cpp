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
 * @file     bgcc_Transaction.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月02日 10时33分00秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_Transaction.h"

using namespace bgcc;

/*
 * Class:     bgcc_Transaction
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Transaction_create
  (JNIEnv *env, jobject transaction) {
      BGCC_TRACE("bgcc", "Transaction::create begin");
      jclass transactionCls = env->GetObjectClass(transaction);
      jfieldID transactionAddressFid = env->GetFieldID(transactionCls, "transactionAddress", "J");

      Transaction* pTransaction = Transaction::get_instance();
      if (!pTransaction) {
          BGCC_WARN("bgcc", "Create Transaction singleton failed");
          return -1;
      }
      
      jlong addr = (jlong)pTransaction;
      env->SetLongField(transaction, transactionAddressFid, addr);
      BGCC_TRACE("bgcc", "Transaction::create end\n");
      return 0;
  }

/*
 * Class:     bgcc_Transaction
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Transaction_destroy
  (JNIEnv *env, jobject transaction) {
      BGCC_TRACE("bgcc", "Transaction::destroy begin");
      jclass transactionCls = env->GetObjectClass(transaction);
      jfieldID transactionAddressFid = env->GetFieldID(transactionCls, "transactionAddress", "J");

      Transaction* pTransaction = (Transaction*)env->GetLongField(transaction, transactionAddressFid);
      if (pTransaction) {
          delete pTransaction;
          pTransaction = NULL;
          env->SetLongField(transaction, transactionAddressFid, 0);
      }
      BGCC_TRACE("bgcc", "Transaction::destroy end\n");
      return 0;
  }

/*
 * Class:     bgcc_Transaction
 * Method:    getCurrentTicketId
 * Signature: (Lbgcc/Protocol;ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Transaction_getCurrentTicketId
  (JNIEnv *env, jobject transaction, jobject protocol, jint threadId, jstring fnName) {
      BGCC_TRACE("bgcc", "Transaction::getCurrentTicketId begin");
      jclass transactionCls = env->GetObjectClass(transaction);
      jfieldID transactionAddressFid = env->GetFieldID(transactionCls, "transactionAddress", "J");

      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol =
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (!pProtocol || pProtocol->is_valid()) {
          BGCC_WARN("bgcc", "protocol is null");
          return 0;
      }

      const char* pFnName = env->GetStringUTFChars(fnName, NULL);
      if (pFnName == NULL) {
          BGCC_WARN("bgcc", "Allocate fnName failed");
          return 0;
      }

      Transaction* pTransaction = (Transaction*)env->GetLongField(transaction, transactionAddressFid);
      if (!pTransaction) {
          BGCC_WARN("bgcc", "transaction is null");
          return 0;
      }
      int32_t ticketId = pTransaction->getCurrentTicketId(*pProtocol, (int32_t)threadId, pFnName);
      env->ReleaseStringUTFChars(fnName, pFnName);

      BGCC_TRACE("bgcc", "Transaction::getCurrentTicketId end\n");
      return ticketId;
  }

/*
 * Class:     bgcc_Transaction
 * Method:    getTicketId
 * Signature: (Lbgcc/Protocol;ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Transaction_getTicketId
  (JNIEnv *env, jobject transaction, jobject protocol, jint threadId, jstring fnName) {
      BGCC_TRACE("bgcc", "Transaction::getTicketId begin");
      jclass transactionCls = env->GetObjectClass(transaction);
      jfieldID transactionAddressFid = env->GetFieldID(transactionCls, "transactionAddress", "J");

      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol =
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (!pProtocol || pProtocol->is_valid()) {
          BGCC_WARN("bgcc", "protocol is null");
          return 0;
      }

      const char* pFnName = env->GetStringUTFChars(fnName, NULL);
      if (pFnName == NULL) {
          BGCC_WARN("bgcc", "Allocate fnName failed");
          return 0;
      }

      Transaction* pTransaction = (Transaction*)env->GetLongField(transaction, transactionAddressFid);
      if (!pTransaction) {
          BGCC_WARN("bgcc", "transaction is null");
          return 0;
      }
      int32_t ticketId = pTransaction->getTicketId(*pProtocol, (int32_t)threadId, pFnName);
      env->ReleaseStringUTFChars(fnName, pFnName);

      BGCC_TRACE("bgcc", "Transaction::getTicketId end\n");
      return ticketId;
  }

