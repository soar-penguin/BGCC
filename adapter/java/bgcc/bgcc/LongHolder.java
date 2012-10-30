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
 * @file     LongHolder.java
 * @brief    Long类型的Holder类
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时14分06秒
 *  
 **/

package bgcc;

public final class LongHolder {

    public LongHolder() {
    }

    public LongHolder(long value) {
        this.value = value;
    }

    public long value = 0;
}

