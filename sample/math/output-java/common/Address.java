package common;


import bgcc.*;
import java.util.*;

public class Address {

    protected StringHolder city;
    protected StringHolder road;
    protected IntHolder number;

    public Address() {
        this.city = new StringHolder();
        this.road = new StringHolder();
        this.number = new IntHolder();
    }


    public String getCity() {
        return this.city.value;
    }

    public void setCity(String city) {
        this.city.value = city;
    }

    public String getRoad() {
        return this.road.value;
    }

    public void setRoad(String road) {
        this.road.value = road;
    }

    public int getNumber() {
        return this.number.value;
    }

    public void setNumber(int number) {
        this.number.value = number;
    }

    public int write(Protocol protocol) {
        int ret = 0;
        ret = protocol.writeStructBegin("Address");
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("city", DataType.IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = protocol.writeString(this.city.value);
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("road", DataType.IDSTR, 2);
        if (ret < 0) { return ret; }
        ret = protocol.writeString(this.road.value);
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("number", DataType.IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = protocol.writeInt(this.number.value);
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
                ret = protocol.readString(this.city);
                if (ret < 0) { return ret; }
                break;
            case 2:
                ret = protocol.readString(this.road);
                if (ret < 0) { return ret; }
                break;
            case 3:
                ret = protocol.readInt(this.number);
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
                ret = protocol.readString(request + nread, request_len - nread, this.city);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = protocol.readString(request + nread, request_len - nread, this.road);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = protocol.readInt(request + nread, request_len - nread, this.number);
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

