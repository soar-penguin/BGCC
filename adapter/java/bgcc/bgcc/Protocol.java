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
 * @file     Protocol.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 09时22分18秒
 *  
 **/

package bgcc;

public final class Protocol {

	public Protocol(long address) {
		this.protocolAddress = address;
	}
	
	static {
        try {
            System.loadLibrary("bgcc4j");
        } catch(UnsatisfiedLinkError e) {
            System.err.println( "Cannot load bgcc library:\n " + e.toString());
        }
    }

	public long protocolAddress = 0;

	private native int destroy();

	public native int writeBool(boolean value);
	public native int readBool(BooleanHolder value);
    public native int readBool(long request, int requestLen, BooleanHolder value);

    public native int writeByte(byte value);
	public native int readByte(ByteHolder value);
	public native int readByte(long request, int requestLen, ByteHolder value);

    public native int writeShort(short value);
	public native int readShort(ShortHolder value);
	public native int readShort(long request, int requestLen, ShortHolder value);

    public native int writeInt(int value);
	public native int readInt(IntHolder value);
	public native int readInt(long request, int requestLen, IntHolder value);

    public native int writeLong(long value);
	public native int readLong(LongHolder value);
	public native int readLong(long request, int requestLen, LongHolder value);

    public native int writeString(String value);
	public native int readString(StringHolder value);
	public native int readString(long request, int requestLen, StringHolder value);

    public native int writeBinary(String value);
	public native int readBinary(StringHolder value);
	public native int readBinary(long request, int requestLen, StringHolder value);

    public native int writeFloat(float value);
	public native int readFloat(FloatHolder value);
	public native int readFloat(long request, int requestLen, FloatHolder value);
	

	public native int writeMessageBegin(java.lang.String processorName, java.lang.String functionName, MessageType msgType, int seqNo);	
	public native int readMessageBegin(StringHolder functionName, MessageTypeHolder msgType, IntHolder seqNo);
	public native int readMessageBegin(long request, int requestLen, StringHolder functionName, MessageTypeHolder msgType, IntHolder seqNo);
	public native int writeMessageEnd();
	public native int readMessageEnd();

	public native int writeStructBegin(java.lang.String name);
	public native int readStructBegin(StringHolder name);
	public native int readStructBegin(long request, int requestLen, StringHolder name);
	public native int writeStructEnd();
	public native int readStructEnd();

	public native int writeFieldBegin(String name, DataType ftype, int field);
	public native int writeFieldEnd();
	public native int readFieldBegin(StringHolder name, DataTypeHolder etype, IntHolder fid);
	public native int readFieldBegin(long request, int requestLen, StringHolder name, DataTypeHolder etype, IntHolder fid);
	public native int readFieldEnd();
	public native int writeFieldStop();


	public native int writeMapBegin(DataType ktype, DataType vtype, int size);
	public native int writeMapEnd();
	public native int readMapBegin(DataTypeHolder ktype, DataTypeHolder vtype, IntHolder size);
	public native int readMapBegin(long request, int requestLen, DataTypeHolder ktype, DataTypeHolder vtype, IntHolder size);
	public native int readMapEnd();

    public native int writeSetBegin(DataType etype, int size);
	public native int readSetBegin(DataTypeHolder etype, IntHolder size);
	public native int readSetBegin(long request, int requestLen, DataTypeHolder etype, IntHolder size);
    public native int writeSetEnd();
	public native int readSetEnd();

    public native int writeListBegin(DataType etype, int size);
	public native int readListBegin(DataTypeHolder etype, IntHolder size);
	public native int readListBegin(long request, int requestLen, DataTypeHolder etype, IntHolder size);
    public native int writeListEnd();
	public native int readListEnd();

	public native int skip(DataType dtype);
}

