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
 * @file     Processor.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 09时16分43秒
 *  
 **/

package bgcc;

public abstract class Processor {

    public Processor() {
        create();
    }

    public Processor(long addr) {
        processorAddress = addr;
    }

    public void finalize() {
        destroy();
    }

    public abstract int process(long request, int request_len, Protocol out);
    
    public abstract java.lang.String getName();

    public long processorAddress = 0;

    protected native int create();

    protected native int destroy();

    static {
        try {
            System.loadLibrary("bgcc4j");
        } catch(UnsatisfiedLinkError e) {
            System.err.println( "Cannot load bgcc library:\n " + e.toString());
        }
    }
}

