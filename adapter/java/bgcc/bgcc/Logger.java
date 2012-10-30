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
 * @file     Logger.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 13时25分00秒
 *  
 **/

package bgcc;

public class Logger {

    public Logger(java.lang.String conf) {
        open(conf);
    }

    private native int open(java.lang.String conf);

    public native int close();

    public native void trace(java.lang.String device, java.lang.String content);
    public native void debug(java.lang.String device, java.lang.String content);
    public native void notice(java.lang.String device, java.lang.String content);
    public native void warn(java.lang.String device, java.lang.String content);
    public native void fatal(java.lang.String device, java.lang.String content);


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
            logger.trace("LXB", "This is a trace");
            logger.debug("LXB", "This is a debug");
            logger.notice("LXB", "This is a notice");
            logger.warn("LXB", "This is a warn");
            logger.fatal("LXB", "This is a fatal");

            logger.trace("bgcc", "This is a trace");
            logger.debug("bgcc", "This is a debug");
            logger.notice("bgcc", "This is a notice");
            logger.warn("bgcc", "This is a warn");
            logger.fatal("bgcc", "This is a fatal");
        } finally {
            if (logger != null) {
                logger.close();
            }
        }
    }
}

