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
 * @file     Holder.java
 * @brief    普通Holder类，用于bgcc in/all 类型的参数的传递
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 16时11分01秒
 *  
 **/

package bgcc;

public class Holder<T> {

    public Holder() {
    }

    public Holder(T value) {
        this.value = value;
    }

    public T value;
}

