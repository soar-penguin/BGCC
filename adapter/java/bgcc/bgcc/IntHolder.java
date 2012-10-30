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
 * @file     IntHolder.java
 * @brief    int类型的holder类，用于bgcc的out , all类型参数
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时25分19秒
 *  
 **/

package bgcc;

public final class IntHolder {

    public IntHolder() {
    }

    public IntHolder(int value) {
        this.value = value;
    }

    public int value = 0;
}

