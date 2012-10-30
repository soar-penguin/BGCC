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
 * @file     MapHolder.java
 * @brief    list的holder，用于out , all类型参数
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时27分48秒
 *  
 **/

package bgcc;

public final class MapHolder {

    public MapHolder() {
    }

    public MapHolder(java.util.Map value) {
        this.value = value;
    }

    public java.util.Map value;
}

