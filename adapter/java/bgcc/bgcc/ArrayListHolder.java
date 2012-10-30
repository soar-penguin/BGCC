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
 * @file     ArrayListHolder.java
 * @brief    byte类型的Holder类,用于传递out ,all类型的byte参数 
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时04分09秒
 *  
 **/

package bgcc;

public final class ArrayListHolder {

    public ArrayListHolder() {
    }

    public ArrayListHolder(java.util.ArrayList value) {
        this.value = value;
    }

    public java.util.ArrayList value = null;
}

