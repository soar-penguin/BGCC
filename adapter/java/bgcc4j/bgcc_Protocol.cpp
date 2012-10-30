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
 * @file     bgcc_Protocol.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月02日 15时17分19秒
 *  
 **/

#include <bgcc.h>
#include "bgcc_Protocol.h"

using namespace bgcc;

///*
// * Class:     bgcc_Protocol
// * Method:    create
// * Signature: (Lbgcc/Transport;)I
// */
//JNIEXPORT jint JNICALL Java_bgcc_Protocol_create
//  (JNIEnv *env, jobject protocol, jobject transport) {
//      jclass transportCls = env->GetObjectClass(transport);
//      jfieldID transportAddressFid = env->GetFieldID(transportCls, "transportAddress", "J");
//
//      SharedPointer<ITransport>* pTransport =
//          (SharedPointer<ITransport>*)env->GetLongField(transport, transportAddressFid);
//      if (!pTransport || !pTransport->is_valid()) {
//          return -1;
//      }
//
//      jclass protocolCls = env->GetObjectClass(protocol);
//      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");
//
//      SharedPointer<IProtocol>* pProtocol =
//          new(std::nothrow) SharedPointer<IProtocol>(
//                  new(std::nothrow) BinaryProtocol(*pTransport));
//      if (!pProtocol || !pProtocol->is_valid()) {
//          return -1;
//      }
//
//      jlong addr = (jlong)pProtocol;
//      env->SetLongField(protocol, protocolAddressFid, addr);
//      return 0;
//  }

/*
 * Class:     bgcc_Protocol
 * Method:    destroy
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_destroy
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          delete pProtocol;
          env->SetLongField(protocol, protocolAddressFid, 0);
          pProtocol = NULL;
      }
      return 0;
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeBool
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeBool
  (JNIEnv *env, jobject protocol, jboolean value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
		  return (*pProtocol)->writeBool(value ? true: false);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readBool
 * Signature: (Lbgcc/BooleanHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readBool__Lbgcc_BooleanHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          bool b = false;
          int32_t ret = (*pProtocol)->readBool(b);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "Z");
              jboolean jb = (b ? JNI_TRUE : JNI_FALSE);
              env->SetBooleanField(valueHolder, valueFid, jb);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readBool
 * Signature: (JILbgcc/BooleanHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readBool__JILbgcc_BooleanHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          bool b = false;
          int32_t ret = (*pProtocol)->readBool((char*)request, (int32_t)request_len, b);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "Z");
              jboolean jb = (b ? JNI_TRUE : JNI_FALSE);
              env->SetBooleanField(valueHolder, valueFid, jb);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeByte
 * Signature: (B)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeByte
  (JNIEnv *env, jobject protocol, jbyte value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeByte(value);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readByte
 * Signature: (Lbgcc/ByteHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readByte__Lbgcc_ByteHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jbyte j_b = 0;
		  int8_t b = 0;
          int32_t ret = (*pProtocol)->readByte(b);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "B");
			  j_b = b;
              env->SetByteField(valueHolder, valueFid, j_b);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readByte
 * Signature: (JILbgcc/ByteHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readByte__JILbgcc_ByteHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jbyte j_b = 0;
		  int8_t b = 0;
          int32_t ret = (*pProtocol)->readByte((char*)request, (int32_t)request_len, b);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "B");
			  j_b = b;
              env->SetByteField(valueHolder, valueFid, j_b);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeShort
 * Signature: (S)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeShort
  (JNIEnv *env, jobject protocol, jshort value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeInt16(value);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readShort
 * Signature: (Lbgcc/ShortHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readShort__Lbgcc_ShortHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jshort s = 0;
          int32_t ret = (*pProtocol)->readInt16(s);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "S");
              env->SetShortField(valueHolder, valueFid, s);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readShort
 * Signature: (JILbgcc/ShortHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readShort__JILbgcc_ShortHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jshort s = 0;
          int32_t ret = (*pProtocol)->readInt16((char*)request, (int32_t)request_len, s);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "S");
              env->SetShortField(valueHolder, valueFid, s);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeInt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeInt
  (JNIEnv *env, jobject protocol, jint value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeInt32(value);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readInt
 * Signature: (Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readInt__Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jint j_i = 0;
		  int i = 0;
          int32_t ret = (*pProtocol)->readInt32(i);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "I");
			  j_i = i;
              env->SetIntField(valueHolder, valueFid, j_i);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readInt
 * Signature: (JILbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readInt__JILbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      BGCC_TRACE("bgcc", "Enter jni readInt");
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jint i = 0;
          int32_t xx;
          int32_t ret = (*pProtocol)->readInt32((char*)request, (int32_t)request_len, xx);
          BGCC_TRACE("bgcc", "read a int %d", xx);
          i = xx;
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "I");
              env->SetIntField(valueHolder, valueFid, i);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeLong
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeLong
  (JNIEnv *env, jobject protocol, jlong value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeInt64(value);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readLong
 * Signature: (Lbgcc/LongHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readLong__Lbgcc_LongHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jlong l = 0;
          int32_t ret = (*pProtocol)->readInt64(l);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "J");
              env->SetLongField(valueHolder, valueFid, l);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readLong
 * Signature: (JILbgcc/LongHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readLong__JILbgcc_LongHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jlong l = 0;
          int32_t ret = (*pProtocol)->readInt64((char*)request, (int32_t)request_len, l);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "J");
              env->SetLongField(valueHolder, valueFid, l);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeString
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeString
  (JNIEnv *env, jobject protocol, jstring value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          const char* str = env->GetStringUTFChars(value, JNI_FALSE);
          int32_t ret = (*pProtocol)->writeString(str);
          env->ReleaseStringUTFChars(value, str);
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readString
 * Signature: (Lbgcc/StringHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readString__Lbgcc_StringHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string str;
          int32_t ret = (*pProtocol)->readString(str);
          if (ret >= 0) {
              jstring j_str = env->NewStringUTF(str.c_str());
              if (j_str == NULL) {
                  return -1;
              }
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(valueHolder, valueFid, j_str);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readString
 * Signature: (JILbgcc/StringHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readString__JILbgcc_StringHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string str;
          int32_t ret = (*pProtocol)->readString((char*)request, (int32_t)request_len, str);
          if (ret >= 0) {
              jstring j_str = env->NewStringUTF(str.c_str());
              if (j_str == NULL) {
                  return -1;
              }
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(valueHolder, valueFid, j_str);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeBinary
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeBinary
  (JNIEnv *env, jobject protocol, jstring value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          const char* str = env->GetStringUTFChars(value, JNI_FALSE);
          int32_t ret = (*pProtocol)->writeString(str);
          env->ReleaseStringUTFChars(value, str);
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readBinary
 * Signature: (Lbgcc/StringHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readBinary__Lbgcc_StringHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string str;
          int32_t ret = (*pProtocol)->readString(str);
          if (ret >= 0) {
              jstring j_str = env->NewStringUTF(str.c_str());
              if (j_str == NULL) {
                  return -1;
              }
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(valueHolder, valueFid, j_str);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readBinary
 * Signature: (JILbgcc/StringHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readBinary__JILbgcc_StringHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string str;
          int32_t ret = (*pProtocol)->readString((char*)request, (int32_t)request_len, str);
          if (ret >= 0) {
              jstring j_str = env->NewStringUTF(str.c_str());
              if (j_str == NULL) {
                  return -1;
              }
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(valueHolder, valueFid, j_str);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeFloat
 * Signature: (F)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeFloat
  (JNIEnv *env, jobject protocol, jfloat value) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeFloat(value);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readFloat
 * Signature: (Lbgcc/FloatHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readFloat__Lbgcc_FloatHolder_2
  (JNIEnv *env, jobject protocol, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jfloat f = 0;
          int32_t ret = (*pProtocol)->readFloat(f);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "F");
              env->SetFloatField(valueHolder, valueFid, f);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readFloat
 * Signature: (JILbgcc/FloatHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readFloat__JILbgcc_FloatHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject valueHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jfloat f = 0;
          int32_t ret = (*pProtocol)->readFloat((char*)request, (int32_t)request_len, f);
          if (ret >= 0) {
              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueFid = env->GetFieldID(valueHolderCls, "value", "F");
              env->SetFloatField(valueHolder, valueFid, f);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeMessageBegin
 * Signature: (Ljava/lang/String;Ljava/lang/String;Lbgcc/MessageType;I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeMessageBegin
  (JNIEnv *env, jobject protocol, jstring processorName, jstring fnName, jobject msgType, jint seqno) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          const char* pProcessorName = env->GetStringUTFChars(processorName, NULL);
          if (!pProcessorName) {
              return -1;
          }

          const char* pFnName = env->GetStringUTFChars(fnName, NULL);
          if (!pFnName) {
              return -1;
          }

          jclass msgTypeCls = env->GetObjectClass(msgType);
          jmethodID getValueMethodId = env->GetMethodID(msgTypeCls, "getValue", "()I");
          MsgTypeID msgTypeValue = (MsgTypeID)env->CallIntMethod(msgType, getValueMethodId);

          int32_t ret = (*pProtocol)->writeMessageBegin(pProcessorName, pFnName, msgTypeValue, (int32_t)seqno);
          env->ReleaseStringUTFChars(fnName, pFnName);
          env->ReleaseStringUTFChars(processorName, pProcessorName);
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readMessageBegin
 * Signature: (Lbgcc/StringHolder;Lbgcc/MessageTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readMessageBegin__Lbgcc_StringHolder_2Lbgcc_MessageTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jobject nameHolder, jobject msgTypeHolder, jobject seqNoHolder) {
      BGCC_TRACE("bgcc", "Enter Protocol::readMessageBegin");
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string name;
          MsgTypeID msgType;
          int32_t seqNo;

          BGCC_TRACE("bgcc", "Before call C++ Interface readMessageBegin");
          int32_t ret = (*pProtocol)->readMessageBegin(name, msgType, seqNo);
          BGCC_TRACE("bgcc", "End call C++ Interface readMessageBegin. retvalue: %d", ret);
          if (ret >= 0) {
              jstring j_name = env->NewStringUTF(name.c_str());
              if (j_name == NULL) {
                  return -1;
              }
              jclass nameHolderCls = env->GetObjectClass(nameHolder);
              jfieldID nameValueFid = env->GetFieldID(nameHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(nameHolder, nameValueFid, j_name);

              jclass msgTypeCls = env->FindClass("bgcc/MessageType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(msgTypeCls, "getByValue",
                      "(I)Lbgcc/MessageType;");
              jobject j_msgType = env->CallStaticObjectMethod(msgTypeCls, getByValueMethodId, (int32_t)msgType);

              jclass msgTypeHolderCls = env->GetObjectClass(msgTypeHolder);
              jfieldID msgTypeValueFid = env->GetFieldID(msgTypeHolderCls, "value", "Lbgcc/MessageType;");
              env->SetObjectField(msgTypeHolder, msgTypeValueFid, j_msgType);

              jint j_seqno = (jint)seqNo;
              jclass seqNoHolderCls = env->GetObjectClass(seqNoHolder);
              jfieldID seqNoValueFid = env->GetFieldID(seqNoHolderCls, "value", "I");
              env->SetIntField(seqNoHolder, seqNoValueFid, j_seqno);
          }
          return ret;
      }
      else {
          BGCC_TRACE("bgcc", "Leave Protocol::readMessageBegin. protocol is null");
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readMessageBegin
 * Signature: (JILbgcc/StringHolder;Lbgcc/MessageTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readMessageBegin__JILbgcc_StringHolder_2Lbgcc_MessageTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject nameHolder, jobject msgTypeHolder, jobject seqNoHolder) {
      BGCC_TRACE("bgcc", "Enter Protocol::readMessageBegin(from request)");
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string name;
          MsgTypeID msgType;
          int32_t seqNo;

          BGCC_TRACE("bgcc", "Before call C++ Interface protocol::readMessageBegin");
          int32_t ret = (*pProtocol)->readMessageBegin((char*)request, (int32_t)request_len, name, msgType, seqNo);
          BGCC_TRACE("bgcc", "End call C++ Interface protocol::readMessageBegin. retvalue: %d %s", ret, name.c_str());
		 
          if (ret >= 0) {
              jstring j_name = env->NewStringUTF(name.c_str());
              if (j_name == NULL) {
                  return -1;
              }
              jclass nameHolderCls = env->GetObjectClass(nameHolder);
              jfieldID nameValueFid = env->GetFieldID(nameHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(nameHolder, nameValueFid, j_name);

              jclass msgTypeCls = env->FindClass("bgcc/MessageType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(msgTypeCls, "getByValue",
                      "(I)Lbgcc/MessageType;");
              jobject j_msgType = env->CallStaticObjectMethod(msgTypeCls, getByValueMethodId, (int32_t)msgType);

              jclass msgTypeHolderCls = env->GetObjectClass(msgTypeHolder);
              jfieldID msgTypeValueFid = env->GetFieldID(msgTypeHolderCls, "value", "Lbgcc/MessageType;");
              env->SetObjectField(msgTypeHolder, msgTypeValueFid, j_msgType);

              jint j_seqno = (jint)seqNo;
              jclass seqNoHolderCls = env->GetObjectClass(seqNoHolder);
              jfieldID seqNoValueFid = env->GetFieldID(seqNoHolderCls, "value", "I");
              env->SetIntField(seqNoHolder, seqNoValueFid, j_seqno);
          }
          BGCC_TRACE("bgcc", "Leave Protocol::readMessageBegin(from request) %s", name.c_str());
          return ret;
      }
      else {
		  BGCC_TRACE("bgcc", "dddddd pProtocol is null");
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeMessageEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeMessageEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeMessageEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readMessageEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readMessageEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->readMessageEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeStructBegin
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeStructBegin
  (JNIEnv *env, jobject protocol, jstring name) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          const char* str = env->GetStringUTFChars(name, JNI_FALSE);
          int32_t ret = (*pProtocol)->writeStructBegin(str);
          env->ReleaseStringUTFChars(name, str);
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readStructBegin
 * Signature: (Lbgcc/StringHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readStructBegin__Lbgcc_StringHolder_2
  (JNIEnv *env, jobject protocol, jobject nameHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string name;

          int32_t ret = (*pProtocol)->readStructBegin(name);
          if (ret >= 0) {
              jstring j_name = env->NewStringUTF(name.c_str());
              if (j_name == NULL) {
                  return -1;
              }
              jclass nameHolderCls = env->GetObjectClass(nameHolder);
              jfieldID nameValueFid = env->GetFieldID(nameHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(nameHolder, nameValueFid, j_name);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readStructBegin
 * Signature: (JILbgcc/StringHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readStructBegin__JILbgcc_StringHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject nameHolder) {
      BGCC_TRACE("bgcc", "Enter readStructBegin");
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string name;

          BGCC_TRACE("bgcc", " before readStructBegin c++  : %d", request_len);
          int32_t ret = (*pProtocol)->readStructBegin((char*)request, (int32_t)request_len, name);
          BGCC_TRACE("bgcc", " readStructBegin c++ ret value : %d %s", ret, name.c_str());
          if (ret >= 0) {
              jstring j_name = env->NewStringUTF(name.c_str());
              if (j_name == NULL) {
                  return -1;
              }
              jclass nameHolderCls = env->GetObjectClass(nameHolder);
              jfieldID nameValueFid = env->GetFieldID(nameHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(nameHolder, nameValueFid, j_name);
          }
          return ret;
      }
      else {
          BGCC_TRACE("bgcc", "Leave readStructBegin. protocol is null");
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeStructEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeStructEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeStructEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readStructEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readStructEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->readStructEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeFieldBegin
 * Signature: (Ljava/lang/String;Lbgcc/DataType;I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeFieldBegin
  (JNIEnv *env, jobject protocol, jstring name, jobject fieldType, jint fieldId) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          const char* pName = env->GetStringUTFChars(name, JNI_FALSE);
          if (!pName) {
              return -1;
          }

          jclass fieldTypeCls = env->GetObjectClass(fieldType);
          jmethodID getValueMethodId = env->GetMethodID(fieldTypeCls, "getValue", "()I");
          DataTypeID fieldTypeValue = (DataTypeID)env->CallIntMethod(fieldType, getValueMethodId);

          int32_t ret = (*pProtocol)->writeFieldBegin(pName, fieldTypeValue, (int32_t)fieldId);
          env->ReleaseStringUTFChars(name, pName);
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeFieldEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeFieldEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeFieldEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readFieldBegin
 * Signature: (Lbgcc/StringHolder;Lbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readFieldBegin__Lbgcc_StringHolder_2Lbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jobject nameHolder, jobject dataTypeHolder, jobject fieldIdHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string name;
          DataTypeID dataType;
          int32_t fieldId;

          int32_t ret = (*pProtocol)->readFieldBegin(name, dataType, fieldId);
          if (ret >= 0) {
              jstring j_name = env->NewStringUTF(name.c_str());
              if (j_name == NULL) {
                  return -1;
              }
              jclass nameHolderCls = env->GetObjectClass(nameHolder);
              jfieldID nameValueFid = env->GetFieldID(nameHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(nameHolder, nameValueFid, j_name);

              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_dataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, dataType);

              jclass dataTypeHolderCls = env->GetObjectClass(dataTypeHolder);
              jfieldID dataTypeValueFid = env->GetFieldID(dataTypeHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(dataTypeHolder, dataTypeValueFid, j_dataType);

              jclass fieldIdHolderCls = env->GetObjectClass(fieldIdHolder);
              jfieldID fieldIdValueFid = env->GetFieldID(fieldIdHolderCls, "value", "I");
              env->SetIntField(fieldIdHolder, fieldIdValueFid, (int32_t)fieldId);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readFieldBegin
 * Signature: (JILbgcc/StringHolder;Lbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readFieldBegin__JILbgcc_StringHolder_2Lbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject nameHolder, jobject dataTypeHolder, jobject fieldIdHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          std::string name;
          DataTypeID dataType;
          int32_t fieldId;

          BGCC_TRACE("bgcc", "Before call C++ Interface readFieldBegin[request_len: %d]", request_len);
          int32_t ret = (*pProtocol)->readFieldBegin((char*)request, (int32_t)request_len, name, dataType, fieldId);
          BGCC_TRACE("bgcc", "End call C++ Interface readFieldBegin[ret: %d, name: %s, dataType: %d, fieldId: %d]", ret,
                  name.c_str(), (int32_t)dataType, fieldId);
          if (ret >= 0) {
              jstring j_name = env->NewStringUTF(name.c_str());
              if (j_name == NULL) {
                  return -1;
              }
              jclass nameHolderCls = env->GetObjectClass(nameHolder);
              jfieldID nameValueFid = env->GetFieldID(nameHolderCls, "value", "Ljava/lang/String;");
              env->SetObjectField(nameHolder, nameValueFid, j_name);

              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_dataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, (int32_t)dataType);

              jclass dataTypeHolderCls = env->GetObjectClass(dataTypeHolder);
              jfieldID dataTypeValueFid = env->GetFieldID(dataTypeHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(dataTypeHolder, dataTypeValueFid, j_dataType);

              jclass fieldIdHolderCls = env->GetObjectClass(fieldIdHolder);
              jfieldID fieldIdValueFid = env->GetFieldID(fieldIdHolderCls, "value", "I");
              env->SetIntField(fieldIdHolder, fieldIdValueFid, (int32_t)fieldId);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readFieldEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readFieldEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->readFieldEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeFieldStop
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeFieldStop
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeFieldStop();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeMapBegin
 * Signature: (Lbgcc/DataType;Lbgcc/DataType;I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeMapBegin
  (JNIEnv *env, jobject protocol, jobject key, jobject value, jint size) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jclass keyCls = env->GetObjectClass(key);
          jmethodID keyGetValueMethodId = env->GetMethodID(keyCls, "getValue", "()I");
          DataTypeID keyValue = (DataTypeID)env->CallIntMethod(key, keyGetValueMethodId);

          jclass valueCls = env->GetObjectClass(value);
          jmethodID valueGetValueMethodId = env->GetMethodID(valueCls, "getValue", "()I");
          DataTypeID valueValue = (DataTypeID)env->CallIntMethod(value, valueGetValueMethodId);

          return (*pProtocol)->writeMapBegin(keyValue, valueValue, (int32_t)size);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeMapEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeMapEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeMapEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readMapBegin
 * Signature: (Lbgcc/DataTypeHolder;Lbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readMapBegin__Lbgcc_DataTypeHolder_2Lbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jobject keyHolder, jobject valueHolder, jobject sizeHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          DataTypeID keyDataType;
          DataTypeID valueDataType;
          int32_t size;

          int32_t ret = (*pProtocol)->readMapBegin(keyDataType, valueDataType, size);
          if (ret >= 0) {
              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_keyDataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, keyDataType);
              jobject j_valueDataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, valueDataType);

              jclass keyHolderCls = env->GetObjectClass(keyHolder);
              jfieldID keyValueFid = env->GetFieldID(keyHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(keyHolder, keyValueFid, j_keyDataType);

              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueValueFid = env->GetFieldID(valueHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(valueHolder, valueValueFid, j_valueDataType);

              jint j_size = (jint)size;
              jclass sizeHolderCls = env->GetObjectClass(sizeHolder);
              jfieldID sizeValueFid = env->GetFieldID(sizeHolderCls, "value", "I");
              env->SetIntField(sizeHolder, sizeValueFid, j_size);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readMapBegin
 * Signature: (JILbgcc/DataTypeHolder;Lbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readMapBegin__JILbgcc_DataTypeHolder_2Lbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject keyHolder, jobject valueHolder, jobject sizeHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          DataTypeID keyDataType;
          DataTypeID valueDataType;
          int32_t size;

          int32_t ret = (*pProtocol)->readMapBegin((char*)request, (int32_t)request_len, keyDataType, valueDataType, size);
          if (ret >= 0) {
              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_keyDataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, keyDataType);
              jobject j_valueDataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, valueDataType);

              jclass keyHolderCls = env->GetObjectClass(keyHolder);
              jfieldID keyValueFid = env->GetFieldID(keyHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(keyHolder, keyValueFid, j_keyDataType);

              jclass valueHolderCls = env->GetObjectClass(valueHolder);
              jfieldID valueValueFid = env->GetFieldID(valueHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(valueHolder, valueValueFid, j_valueDataType);

              jint j_size = (jint)size;
              jclass sizeHolderCls = env->GetObjectClass(sizeHolder);
              jfieldID sizeValueFid = env->GetFieldID(sizeHolderCls, "value", "I");
              env->SetIntField(sizeHolder, sizeValueFid, j_size);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readMapEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readMapEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->readMapEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeSetBegin
 * Signature: (Lbgcc/DataType;I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeSetBegin
  (JNIEnv *env, jobject protocol, jobject elemType, jint size) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jclass elemTypeCls = env->GetObjectClass(elemType);
          jmethodID getValueMethodId = env->GetMethodID(elemTypeCls, "getValue", "()I");
          DataTypeID elemTypeValue = (DataTypeID)env->CallIntMethod(elemType, getValueMethodId);

          return (*pProtocol)->writeSetBegin(elemTypeValue, (int32_t)size);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readSetBegin
 * Signature: (Lbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readSetBegin__Lbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jobject dataTypeHolder, jobject sizeHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          DataTypeID dataType;
          int32_t size;

          int32_t ret = (*pProtocol)->readSetBegin(dataType, size);
          if (ret >= 0) {
              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_dataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, dataType);

              jclass dataTypeHolderCls = env->GetObjectClass(dataTypeHolder);
              jfieldID valueFid = env->GetFieldID(dataTypeHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(dataTypeHolder, valueFid, j_dataType);

              jint j_size = (jint)size;
              jclass sizeHolderCls = env->GetObjectClass(sizeHolder);
              jfieldID sizeValueFid = env->GetFieldID(sizeHolderCls, "value", "I");
              env->SetIntField(sizeHolder, sizeValueFid, j_size);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readSetBegin
 * Signature: (JILbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readSetBegin__JILbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject dataTypeHolder, jobject sizeHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          DataTypeID dataType;
          int32_t size;

          int32_t ret = (*pProtocol)->readSetBegin((char*)request, (int32_t)request_len, dataType, size);
          if (ret >= 0) {
              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_dataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, dataType);

              jclass dataTypeHolderCls = env->GetObjectClass(dataTypeHolder);
              jfieldID valueFid = env->GetFieldID(dataTypeHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(dataTypeHolder, valueFid, j_dataType);

              jint j_size = (jint)size;
              jclass sizeHolderCls = env->GetObjectClass(sizeHolder);
              jfieldID sizeValueFid = env->GetFieldID(sizeHolderCls, "value", "I");
              env->SetIntField(sizeHolder, sizeValueFid, j_size);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeSetEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeSetEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeSetEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readSetEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readSetEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->readSetEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeListBegin
 * Signature: (Lbgcc/DataType;I)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeListBegin
  (JNIEnv *env, jobject protocol, jobject elemType, jint size) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          jclass elemTypeCls = env->GetObjectClass(elemType);
          jmethodID getValueMethodId = env->GetMethodID(elemTypeCls, "getValue", "()I");
          DataTypeID elemTypeValue = (DataTypeID)env->CallIntMethod(elemType, getValueMethodId);

          return (*pProtocol)->writeSetBegin(elemTypeValue, (int32_t)size);
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readListBegin
 * Signature: (Lbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readListBegin__Lbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jobject dataTypeHolder, jobject sizeHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          DataTypeID dataType;
          int32_t size;

          int32_t ret = (*pProtocol)->readListBegin(dataType, size);
          if (ret >= 0) {
              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_dataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, dataType);

              jclass dataTypeHolderCls = env->GetObjectClass(dataTypeHolder);
              jfieldID valueFid = env->GetFieldID(dataTypeHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(dataTypeHolder, valueFid, j_dataType);

              jint j_size = (jint)size;
              jclass sizeHolderCls = env->GetObjectClass(sizeHolder);
              jfieldID sizeValueFid = env->GetFieldID(sizeHolderCls, "value", "I");
              env->SetIntField(sizeHolder, sizeValueFid, j_size);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readListBegin
 * Signature: (JILbgcc/DataTypeHolder;Lbgcc/IntHolder;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readListBegin__JILbgcc_DataTypeHolder_2Lbgcc_IntHolder_2
  (JNIEnv *env, jobject protocol, jlong request, jint request_len, jobject dataTypeHolder, jobject sizeHolder) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          DataTypeID dataType;
          int32_t size;

          BGCC_TRACE("bgcc", "Before readListBegin[request_len: %d]", (int32_t)request_len);
          int32_t ret = (*pProtocol)->readListBegin((char*)request, (int32_t)request_len, dataType, size);
          BGCC_TRACE("bgcc", "After readListBegin ret: %d, dataType: %d, size: %d", ret,
                  (int32_t)dataType, size);
          if (ret >= 0) {
              jclass dataTypeCls = env->FindClass("bgcc/DataType");
              jmethodID getByValueMethodId = env->GetStaticMethodID(dataTypeCls, "getByValue",
                      "(I)Lbgcc/DataType;");
              jobject j_dataType = env->CallStaticObjectMethod(dataTypeCls, getByValueMethodId, dataType);

              jclass dataTypeHolderCls = env->GetObjectClass(dataTypeHolder);
              jfieldID valueFid = env->GetFieldID(dataTypeHolderCls, "value", "Lbgcc/DataType;");
              env->SetObjectField(dataTypeHolder, valueFid, j_dataType);

              jint j_size = (jint)size;
              jclass sizeHolderCls = env->GetObjectClass(sizeHolder);
              jfieldID sizeValueFid = env->GetFieldID(sizeHolderCls, "value", "I");
              env->SetIntField(sizeHolder, sizeValueFid, j_size);
          }
          return ret;
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    writeListEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_writeListEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->writeListEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    readListEnd
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_readListEnd
  (JNIEnv *env, jobject protocol) {
      jclass protocolCls = env->GetObjectClass(protocol);
      jfieldID protocolAddressFid = env->GetFieldID(protocolCls, "protocolAddress", "J");

      SharedPointer<IProtocol>* pProtocol = 
          (SharedPointer<IProtocol>*)env->GetLongField(protocol, protocolAddressFid);
      if (pProtocol) {
          return (*pProtocol)->readListEnd();
      }
      else {
          return -1;
      }
  }

/*
 * Class:     bgcc_Protocol
 * Method:    skip
 * Signature: (Lbgcc/DataType;)I
 */
JNIEXPORT jint JNICALL Java_bgcc_Protocol_skip
  (JNIEnv *, jobject, jobject);
