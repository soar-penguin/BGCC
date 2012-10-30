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
 * @file     ListHolder.java
 * @brief    LinkedList的holder类用于all, out参数
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时26分35秒
 *  
 **/

package bgcc;

public final class ListHolder {

    public ListHolder() {
    }

    public ListHolder(java.util.List value) {
        this.value = value;
    }

    public java.util.List value = null;
}

