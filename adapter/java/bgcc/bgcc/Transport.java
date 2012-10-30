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
 * @file     Transport.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 09时51分03秒
 *  
 **/

package bgcc;

public final class Transport {

    public Transport(java.lang.String host, int port) {
        create(host, port);
    }

    public void finalize() {
        destroy();
    }

    static {
        try {
            System.loadLibrary("bgcc4j");
        } catch(UnsatisfiedLinkError e) {
            System.err.println( "Cannot load bgcc library:\n " + e.toString());
        }
    }

    private long transportAddress = 0;

	public native int create(java.lang.String host, int port);
	public native int destroy();

	public native int open();
	public native boolean isOpen();
	public native int close();
}

