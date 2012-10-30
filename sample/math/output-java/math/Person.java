package math;


import bgcc.*;
import java.util.*;

public class Person {

    protected StringHolder name;
    protected IntHolder age;

    public Person() {
        this.name = new StringHolder();
        this.age = new IntHolder();
    }


    public String getName() {
        return this.name.value;
    }

    public void setName(String name) {
        this.name.value = name;
    }

    public int getAge() {
        return this.age.value;
    }

    public void setAge(int age) {
        this.age.value = age;
    }

    public int write(Protocol protocol) {
        int ret = 0;
        ret = protocol.writeStructBegin("Person");
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("name", DataType.IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = protocol.writeString(this.name.value);
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("age", DataType.IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = protocol.writeInt(this.age.value);
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldStop();
        if (ret < 0) { return ret; }

        return protocol.writeStructEnd();

    }

    public int read(Protocol protocol) {
        int ret = 0;
        StringHolder fname = new StringHolder();
        DataTypeHolder ftype = new DataTypeHolder();
        IntHolder fid = new IntHolder();

        ret = protocol.readStructBegin(fname);
        if (ret < 0) { return ret; }

        while (true) {
            ret = protocol.readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype.value == DataType.IDSTOP) {
                break;
            }

            switch(fid.value) {
            case 1:
                ret = protocol.readString(this.name);
                if (ret < 0) { return ret; }
                break;
            case 2:
                ret = protocol.readInt(this.age);
                if (ret < 0) { return ret; }
                break;
            }
        }

        return protocol.readFieldEnd();
    }

    public int read(Protocol protocol, long request, int request_len) {
        int ret = 0;
        int nread = 0;
        StringHolder fname = new StringHolder();
        DataTypeHolder ftype = new DataTypeHolder();
        IntHolder fid = new IntHolder();

        ret = protocol.readStructBegin(request + nread, request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = protocol.readFieldBegin(request + nread, request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype.value == DataType.IDSTOP) {
                break;
            }

            switch(fid.value) {
            case 1:
                ret = protocol.readString(request + nread, request_len - nread, this.name);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = protocol.readInt(request + nread, request_len - nread, this.age);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
        }

        ret = protocol.readFieldEnd();
        if (ret < 0) { return ret; }
        nread += ret;
        return nread;
    }

}

