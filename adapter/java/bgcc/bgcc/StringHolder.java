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
 * @file     StringHolder.java
 * @brief    String的holder类, 用于bgcc  out/all类型参数
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时19分58秒
 *  
 **/

package bgcc;

public final class StringHolder {

    public StringHolder() {
    }

    public StringHolder(java.lang.String value) {
        this.value = value;
    }

    public java.lang.String value = new java.lang.String();
}

