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
 * @file     ExceptionType.java
 * @brief    ExceptionType枚举类
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 18时50分41秒
 *  
 **/

package bgcc;

public enum ExceptionType {
        OPERSUCCESS(0, "OPERSUCCESS"),
        BUFFERISNULL(-1, "BUFFERISNULL"),
        SOCKETNOTOPEN(-2, "SOCKETNOTOPEN"),
        SETSOCKOPTFAIL(-3, "SETSOCKOPTFAIL"),
        PEEREXCEPTION(-4, "PEEREXCEPTION"),
        CREATESOCKETFAIL(-5, "CREATESOCKETFAIL"),
        WRITEEXCEPTION(-6, "WRITEEXCEPTION"),
        READEXCEPTION(-7, "READEXCEPTION"),
        CONNECTSERVERFAIL(-8, "CONNECTSERVERFAIL"),
        GETADDRFAIL(-9, "GETADDRFAIL"),
        PORTINVALID(-10, "PORTINVALID"),
        BINDSOCKETFAIL(-11, "BINDSOCKETFAIL"),
        LISTENFAIL(-12, "LISTENFAIL"),
        SOCKETINVALID(-13, "SOCKETINVALID"),
        GETPEERNAMEFAIL(-14, "GETPEERNAMEFAIL"),
        CLOSESOCKETFAIL(-15, "CLOSESOCKETFAIL"),
        SOCKETINTERRUPT(-16, "SOCKETINTERRUPT"),
        CREATEINTERSOCKFAIL(-17, "CREATEINTERSOCKFAIL"),

        SERVICENOTFOUND(-100, "SERVICENOTFOUND"),

        /*以下错误码为windows下专用*/
        WSACLEANUPERROR(-18, "WSACLEANUPERROR"),
        WSASTARTUPERROR(-19, "WSASTARTUPERROR"),
		INVALID_METHOD(-20, "INVALID_METHOD"),
		MISS_REQUIRED_FILED(-21, "MISS_REQUIRED_FILED");

	ExceptionType(int value) {
		this.value = value;
	}

	ExceptionType(int value, String desc) {
		this.value = value;
		this.desc = desc;
	}

	public int getValue() {
		return this.value;
	}
	
	public java.lang.String getDesc() {
		return this.desc;
	}
	
    public static ExceptionType getByValue(int value) {
        for (ExceptionType tmp : ExceptionType.values()) {
            if (tmp.getValue() == value){
                return tmp;
            }
        }
        return null;
    }

	private int value;
	private java.lang.String desc;
}

