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
 * @file     Server.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月31日 10时08分02秒
 *  
 **/

package bgcc;

public class Server {
    private ServiceManager  serviceManager;

    private ThreadPool      threadPool;

    private int port;

    private java.lang.String node;

    public Server(ServiceManager serviceManager, ThreadPool threadPool, int port) {
        this(serviceManager, threadPool, port, "");
    }

    public Server(ServiceManager serviceManager, ThreadPool threadPool, int port, java.lang.String node) {
        this.serviceManager = serviceManager;
        this.threadPool = threadPool;
        this.node = node;
        create(serviceManager, threadPool, port, node);
    }

    private long serverAddress;

    public native int serve();

    public native int stop();

    public native int destroy();

    private native int create(ServiceManager serviceManager, ThreadPool threadPool, int port, java.lang.String node);

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

            ServiceManager serviceManager = null;
            Processor processor = null;
            ThreadPool threadPool = null;
            Server server = null;

            try {
                serviceManager = new ServiceManager();
                threadPool = new ThreadPool(10);
                server = new Server(serviceManager, threadPool, 8503);
                server.serve();
                server.stop();
                server.destroy();
            } finally {
                if (serviceManager != null) {
                    serviceManager.destroy();
                    serviceManager = null;
                }

                if (threadPool != null) {
                    threadPool.destroy();
                    threadPool = null;
                }

                if (server != null) {
                    server.destroy();
                    server = null;
                }
            }
        } finally {
            if (logger != null) {
                logger.close();
            }
        }
    }
}


