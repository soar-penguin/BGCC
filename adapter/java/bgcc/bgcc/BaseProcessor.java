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
 * @file     BaseProcessor.java
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年09月01日 23时02分22秒
 *  
 **/

package bgcc;

import java.util.HashMap;

public class BaseProcessor extends Processor {

    public BaseProcessor() {
        _processMap.put("__get_ticket_id", new __get_ticket_id());
        _processMap.put("__service_not_found", new __service_not_found());
    }

    protected static interface ProcessFunction {
        public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid);
    }

    protected final HashMap<java.lang.String, ProcessFunction> _processMap = 
        new HashMap<java.lang.String, ProcessFunction>();

    public int process(long request, int request_len, Protocol out) {
        StringHolder fname = new StringHolder();
        MessageTypeHolder msgType = new MessageTypeHolder();
        IntHolder seqid = new IntHolder();
        int ret = 0;
        int nread = 0;
        
        Global.instance().getLogger().trace("bgcc", "Before readMessageBegin request_len " + request_len);
        ret = out.readMessageBegin(request + nread, request_len - nread, fname, msgType, seqid);
        Global.instance().getLogger().trace("bgcc", "End readMessageBegin " + ret);

        if (ret < 0) {
            System.err.println("read MessageBegin error: " + ret);
            return ret;
        }
        nread += ret;

        Global.instance().getLogger().trace("bgcc", "Get a request to " + fname.value + " " + msgType.value
                + " " + seqid.value);
        ProcessFunction fn = _processMap.get(fname.value);
        if (fn == null) {
            return -1;
        }
        else {
            return fn.process(request + nread, request_len - nread, out, fname.value, seqid.value);
        }
    }

    public java.lang.String getName() {
        return "._baseservice_2012";
    }

    private class __get_ticket_id implements ProcessFunction {
        public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
            Global.instance().getLogger().trace("bgcc", "Enter __get_ticket_id request_len " + request_len);

            IntHolder threadId = new IntHolder();
            StringHolder fnName = new StringHolder();
            BooleanHolder last = new BooleanHolder();
            int ret;
            int nread = 0;

            Global.instance().getLogger().trace("bgcc", "threadId: " + threadId.value);
            ret = out.readInt(request + nread, request_len - nread, threadId);
            if (ret < 0) {
                Global.instance().getLogger().trace("bgcc", "Leave __get_ticket_id. failed to read threadId with retvalue " + ret);
                return ret;
            }
            nread += ret;
            Global.instance().getLogger().trace("bgcc", "retvalue : " + ret + " threadId: " + threadId.value);

            ret = out.readString(request + nread, request_len - nread, fnName);
            if (ret < 0) {
                return ret;
            }
            nread += ret;
            Global.instance().getLogger().trace("bgcc", "retvalue : " + ret + " fnName: " + fnName.value);

            ret = out.readBool(request + nread, request_len - nread, last);
            if (ret < 0) {
                return ret;
            }
            nread += ret;
            Global.instance().getLogger().trace("bgcc", "retvalue : " + ret + " last: " + last.value);

            ret = out.readMessageEnd();
            if (ret < 0) {
                return ret;
            }
            nread += ret;

            int ticketId = 100;
            if (last.value) {
                ticketId = Transaction.getInstance().getCurrentTicketId(out, threadId.value, fnName.value);
            } else {
                ticketId = Transaction.getInstance().getTicketId(out, threadId.value, fnName.value);
            }


            ret = out.writeMessageBegin("xxx", "__get_ticket_id", MessageType.REPLY, 0);
            if (ret < 0) {
                return ret;
            }

            ret = out.writeInt(ticketId);
            if (ret < 0) {
                return ret;
            }

            ret = out.writeMessageEnd();
            return ret;
        }
    }

    private class __service_not_found implements ProcessFunction {
        public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
            int ret;

            ret = out.writeMessageBegin("", "", MessageType.EXCEPTION, 0);
            if (ret < 0) {
                return ret;
            }

            ret = out.writeInt(ExceptionType.SERVICENOTFOUND.getValue());
            if (ret < 0) {
                return ret;
            }

            ret = out.writeMessageEnd();
            return ret;
        }
    }
}

