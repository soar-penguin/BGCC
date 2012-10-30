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
 * @file     BooleanHolder.java
 * @brief    boolean 类型的holder类
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时22分46秒
 *  
 **/

package bgcc;

public final class BooleanHolder {

    public BooleanHolder() {
    }

    public BooleanHolder(boolean value) {
        this.value = value;
    }

    public boolean value = true;
}

