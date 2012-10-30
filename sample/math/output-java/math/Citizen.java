package math;


import bgcc.*;
import java.util.*;

public class Citizen {

    protected StringHolder name;
    protected IntHolder age;
    protected math.GenderHolder gender;
    protected common.AddressHolder address;
    protected Holder<List<String>> children;
    protected Holder<Set<Integer>> xxx;
    protected Holder<Map<Byte, Boolean>> kkk;

    public Citizen() {
        this.name = new StringHolder();
        this.age = new IntHolder();
        this.gender = new math.GenderHolder();
        this.address = new common.AddressHolder();
        this.children = new Holder<List<String>>();
        this.xxx = new Holder<Set<Integer>>();
        this.kkk = new Holder<Map<Byte, Boolean>>();
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

    public math.Gender getGender() {
        return this.gender.value;
    }

    public void setGender(math.Gender gender) {
        this.gender.value = gender;
    }

    public common.Address getAddress() {
        return this.address.value;
    }

    public void setAddress(common.Address address) {
        this.address.value = address;
    }

    public List<String> getChildren() {
        return this.children.value;
    }

    public void setChildren(List<String> children) {
        this.children.value = children;
    }

    public Set<Integer> getXxx() {
        return this.xxx.value;
    }

    public void setXxx(Set<Integer> xxx) {
        this.xxx.value = xxx;
    }

    public Map<Byte, Boolean> getKkk() {
        return this.kkk.value;
    }

    public void setKkk(Map<Byte, Boolean> kkk) {
        this.kkk.value = kkk;
    }

    public int write(Protocol protocol) {
        int ret = 0;
        ret = protocol.writeStructBegin("Citizen");
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

        ret = protocol.writeFieldBegin("gender", DataType.IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = protocol.writeInt(this.gender.value.getValue());
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("address", DataType.IDSTRUCT, 4);
        if (ret < 0) { return ret; }
        ret = address.value.write(protocol);
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("children", DataType.IDLIST, 5);
        if (ret < 0) { return ret; }
        ret = protocol.writeListBegin(DataType.IDSTR, this.children.value.size());
        if (ret < 0) { return ret; }
        for (String itr_var22 : this.children.value) {
            ret = protocol.writeString(itr_var22);
            if (ret < 0) { return ret; }
        }
        ret = protocol.writeListEnd();
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("xxx", DataType.IDSET, 6);
        if (ret < 0) { return ret; }
        ret = protocol.writeSetBegin(DataType.IDINT32, this.xxx.value.size());
        if (ret < 0) { return ret; }
        for (int itr_var23 : this.xxx.value) {
            ret = protocol.writeInt(itr_var23);
            if (ret < 0) { return ret; }
        }
        ret = protocol.writeSetEnd();
        if (ret < 0) { return ret; }
        ret = protocol.writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = protocol.writeFieldBegin("kkk", DataType.IDMAP, 7);
        if (ret < 0) { return ret; }
        ret = protocol.writeMapBegin(DataType.IDBYTE, DataType.IDBOOL, this.kkk.value.size());
        if (ret < 0) { return ret; }
        for (Map.Entry<Byte, Boolean> citr_var24 : this.kkk.value.entrySet()) {
            ret = protocol.writeByte(citr_var24.getKey());
            if (ret < 0) { return ret; }
            ret = protocol.writeBool(citr_var24.getValue());
            if (ret < 0) { return ret; }
        }
        ret = protocol.writeMapEnd();
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
            case 3:
                IntHolder ele_var25 = new IntHolder();
                ret = protocol.readInt(ele_var25);
                if (ret < 0) { return ret; }
                gender.value = math.Gender.findByValue(ele_var25.value);
                break;
            case 4:
                address.value = new common.Address();
                ret = address.value.read(protocol);
                if (ret < 0) { return ret; }
                break;
            case 5:
                IntHolder size_var26 = new IntHolder();
                DataTypeHolder etype_var27 = new DataTypeHolder();

                 ret = protocol.readListBegin(etype_var27, size_var26);
                if (ret < 0) { return ret; }
                for (int ivar28 = 0; ivar28 < size_var26.value; ++ivar28) {
                    StringHolder value_var29 = new StringHolder();
                    ret = protocol.readString(value_var29);
                    if (ret < 0) { return ret; }
                    if (children.value == null) {
                        children.value = new ArrayList<String>();
                    }
                    children.value.add(value_var29.value);
                }
                ret = protocol.readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 6:
                IntHolder size_var30 = new IntHolder();
                DataTypeHolder etype_var31 = new DataTypeHolder();

                 ret = protocol.readSetBegin(etype_var31, size_var30);
                if (ret < 0) { return ret; }
                for (int ivar32 = 0; ivar32 < size_var30.value; ++ivar32) {
                    IntHolder value_var33 = new IntHolder();
                    ret = protocol.readInt(value_var33);
                    if (ret < 0) { return ret; }
                    if (xxx.value == null) {
                        xxx.value = new HashSet<Integer>();
                    }
                    xxx.value.add(value_var33.value);
                }
                ret = protocol.readSetEnd();
                if (ret < 0) { return ret; }
                break;
            case 7:
                IntHolder size_var34 = new IntHolder();
                DataTypeHolder key_var35 = new DataTypeHolder();

                DataTypeHolder vlaue_var36 = new DataTypeHolder();

                 ret = protocol.readMapBegin(key_var35, vlaue_var36, size_var34);
                if (ret < 0) { return ret; }
                for (int ivar37 = 0; ivar37 < size_var34.value; ++ivar37) {
                    ByteHolder key_var38 = new ByteHolder();
                    BooleanHolder value_var39 = new BooleanHolder();
                    ret = protocol.readByte(key_var38);
                    if (ret < 0) { return ret; }
                    ret = protocol.readBool(value_var39);
                    if (ret < 0) { return ret; }
                    if (kkk.value == null) {
                        kkk.value = new HashMap<Byte, Boolean>();
                    }
                    kkk.value.put(key_var38.value, value_var39.value);
                ret = protocol.readMapEnd();
                if (ret < 0) { return ret; }
                }
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
            case 3:
                IntHolder ele_var40 = new IntHolder();
                ret = protocol.readInt(request + nread, request_len - nread, ele_var40);
                if (ret < 0) { return ret; }
                nread += ret;
                gender.value = math.Gender.findByValue(ele_var40.value);
                break;
            case 4:
                address.value = new common.Address();
                ret = address.value.read(protocol, request + nread, request_len - nread);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 5:
                IntHolder size_var41 = new IntHolder();
                DataTypeHolder etype_var42 = new DataTypeHolder();

                ret = protocol.readListBegin(request + nread, request_len - nread, etype_var42, size_var41);
                if (ret < 0) { return ret; }
                nread += ret;
                for (int ivar43 = 0; ivar43 < size_var41.value; ++ivar43) {
                    StringHolder value_var44 = new StringHolder();
                    ret = protocol.readString(request + nread, request_len - nread, value_var44);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    if (children.value == null) {
                        children.value = new ArrayList<String>();
                    }
                    children.value.add(value_var44.value);
                }
                ret = protocol.readListEnd();
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 6:
                IntHolder size_var45 = new IntHolder();
                DataTypeHolder etype_var46 = new DataTypeHolder();

                ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var46, size_var45);
                if (ret < 0) { return ret; }
                nread += ret;
                for (int ivar47 = 0; ivar47 < size_var45.value; ++ivar47) {
                    IntHolder value_var48 = new IntHolder();
                    ret = protocol.readInt(request + nread, request_len - nread, value_var48);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    if (xxx.value == null) {
                        xxx.value = new HashSet<Integer>();
                    }
                    xxx.value.add(value_var48.value);
                }
                ret = protocol.readSetEnd();
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 7:
                IntHolder size_var49 = new IntHolder();
                DataTypeHolder key_var50 = new DataTypeHolder();

                DataTypeHolder vlaue_var51 = new DataTypeHolder();

                 ret = protocol.readMapBegin(request + nread, request_len - nread, key_var50, vlaue_var51, size_var49);
                if (ret < 0) { return ret; }
                nread += ret;
                for (int ivar52 = 0; ivar52 < size_var49.value; ++ivar52) {
                    ByteHolder key_var53 = new ByteHolder();
                    BooleanHolder value_var54 = new BooleanHolder();
                    ret = protocol.readByte(request + nread, request_len - nread, key_var53);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    ret = protocol.readBool(request + nread, request_len - nread, value_var54);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    if (kkk.value == null) {
                        kkk.value = new HashMap<Byte, Boolean>();
                    }
                    kkk.value.put(key_var53.value, value_var54.value);
                ret = protocol.readMapEnd();
                if (ret < 0) { return ret; }
                }
                break;
            }
        }

        ret = protocol.readFieldEnd();
        if (ret < 0) { return ret; }
        nread += ret;
        return nread;
    }

}

