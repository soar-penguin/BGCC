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
 * @file     MessageType.java
 * @brief    MessageType枚举类
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 18时58分14秒
 *  
 **/

package bgcc;

public enum MessageType {

	NONE(-1, "NONE"),
    CALL(1, "CALL"),
    REPLY(2, "REPLY"),
    EXCEPTION(3, "EXCEPTION"),
    ONEWAY(4, "ONEWAY");

	MessageType(int value) {
		this.value = value;
	}

	MessageType(int value, String desc) {
		this.value = value;
		this.desc = desc;
	}

	public int getValue() {
		return this.value;
	}
	
	public java.lang.String getDesc() {
		return this.desc;
	}
	
    public static MessageType getByValue(int value) {
        for (MessageType tmp : MessageType.values()) {
            if (tmp.getValue() == value) {
                return tmp;
            }
        }
        return null;
    }	

	private int value;
	private java.lang.String desc;
}

