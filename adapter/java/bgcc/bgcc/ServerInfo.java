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
 * @file     ServerInfo.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 10时29分38秒
 *  
 **/

package bgcc;

public class ServerInfo {
    public ServerInfo(java.lang.String host, int port) {
        create(host, port);
    }

    public void finalize() {
        destroy();
    }

    private long serverInfoAddress = 0;

    private native int create(java.lang.String host, int port);

    private native int destroy();

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
            ServerInfo serverInfo = null;
            try {
                serverInfo = new ServerInfo("localhost", 8503);
            } finally {
                if (serverInfo != null) {
                    serverInfo.destroy();
                    serverInfo = null;
                }
            }
        } finally {
            if (logger != null) {
                logger.close();
            }
        }
    }
}

