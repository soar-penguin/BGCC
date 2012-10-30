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
 * @file     ServiceManager.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月30日 15时55分04秒
 *  
 **/

package bgcc;

public class ServiceManager {

    public ServiceManager() {
        create();
    }

    public native int destroy();

    public native int addService(Processor processor);

    private native int create();

    private long serviceManagerAddress;

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

            serviceManager = new ServiceManager();
            try {
                serviceManager.addService(processor);
                serviceManager.addService(processor);
            } finally {
                if (serviceManager != null) {
                    serviceManager.destroy();
                    serviceManager = null;
                }
            }
        } finally {
            if (logger != null) {
                logger.close();
            }
        }
    }
}

