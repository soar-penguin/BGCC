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
 * @file     ObjectHolder.java
 * @brief    Object 的holder
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时15分55秒
 *  
 **/

package bgcc;

public final class ObjectHolder {

    public ObjectHolder() {
    }

    public ObjectHolder(java.lang.Object value) {
        this.value = value;
    }

    public Object value = null;
}

