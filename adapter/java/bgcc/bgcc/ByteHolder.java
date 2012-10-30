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
 * @file     ByteHolder.java
 * @brief    byte类型的Holder类,用于传递out ,all类型的byte参数 
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时09分16秒
 *  
 **/

package bgcc;

public final class ByteHolder {

    public ByteHolder() {
    }

    public ByteHolder(byte value) {
        this.value = value;
    }

    public byte value = 0;
}

