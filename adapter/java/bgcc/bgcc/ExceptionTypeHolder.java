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
 * @file     ExceptionTypeHolder.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 18时55分12秒
 *  
 **/

package bgcc;

public final class ExceptionTypeHolder {

    public ExceptionTypeHolder() {
    }

    public ExceptionTypeHolder(ExceptionType value) {
        this.value = value;
    }

    public ExceptionType value = ExceptionType.getByValue(0);
}

