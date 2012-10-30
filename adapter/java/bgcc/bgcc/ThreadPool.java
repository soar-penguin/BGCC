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
 * @file     ThreadPool.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 10时15分58秒
 *  
 **/

package bgcc;

public class ThreadPool {
    public ThreadPool(int nThread) {
        create(nThread);
    }

    private long threadPoolAddress = 0;

    private native int create(int nThread);

    public native int destroy();

    static {
        try {
            System.loadLibrary("bgcc4j");
        } catch(UnsatisfiedLinkError e) {
            System.err.println( "Cannot load bgcc library:\n " + e.toString());
        }
    }

    public static void main(java.lang.String[] args) {
        Logger logger = null;

        try {
            logger = new Logger("bgcc.cfg");
            ThreadPool threadPool = null;

            try {
                threadPool = new ThreadPool(10);
            } finally {
                if (threadPool != null) {
                    threadPool.destroy();
                    threadPool = null;
                }
            }
        } finally {
            if (logger != null) {
                logger.close();
            }
        }
    }
}

