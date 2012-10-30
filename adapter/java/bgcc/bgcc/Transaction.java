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
 * @file     Transaction.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月02日 10时24分32秒
 *  
 **/

package bgcc;

public class Transaction {
    private Transaction() {
        create();
    }

    private static Transaction _transaction = null;

    public static synchronized Transaction getInstance() {
        if (null == _transaction) {
            _transaction = new Transaction();
        }
        return _transaction;
    }

    private long transactionAddress = 0;

    private native int create();
    
    public native int destroy();

    public native int getCurrentTicketId(Protocol protocol, int threadId, java.lang.String fnName);

    public native int getTicketId(Protocol protocol, int threadId, java.lang.String fnName);
}

