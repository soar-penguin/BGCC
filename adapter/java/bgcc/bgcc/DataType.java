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
 * @file     DataType.java
 * @brief    DataType枚举，定义协议中的数据类型
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 18时40分40秒
 *  
 **/

package bgcc;

public enum DataType {

	IDSTOP(0),
	IDVOID(1),
	IDBOOL(2),
	IDBYTE(3),
	IDINT16(4),
	IDINT32(5),
	IDINT64(6),
	IDFLOAT(7),
	IDSTR(8),
	IDBIN(9),
	IDSTRUCT(10),
	IDMAP(11),
	IDSET(12),
	IDLIST(13),
	IDFIELD(14),
	IDSERVICE(15),
	IDMSG(16);

	DataType(int val) {
		this.value = val;
	}

	public int getValue() {
		return this.value;
	}

    public static DataType getByValue(int value) {
        for (DataType tmp : DataType.values()) {
            if(tmp.getValue() == value){
                return tmp;
            }
        }
        return null;
    }

    private int value;
}


