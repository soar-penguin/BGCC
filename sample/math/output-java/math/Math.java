package math;

import bgcc.*;
import java.util.*;

public class Math {

    public interface Intf {
        public void ping();
        public math.AddResult add(int a, int b, IntHolder sum);
        public math.Citizen test_citizen(math.Citizen ins, math.CitizenHolder outs, math.CitizenHolder alls);
        public boolean get_boolean();
        public byte get_int8();
        public short get_int16();
        public int get_int32();
        public long get_int64();
        public float get_float();
        public String get_string();
        public String get_binary();
        public math.Color get_color();
        public List<Integer> get_sequence();
        public Set<String> get_string_set();
        public Map<Long, String> get_int_str_map();
        public List<Set<Boolean>> get_bool_set_sequence();
        public math.Person get_person();
        public List<math.Person> get_persons();
        public Set<math.Person> get_persons2();
        public Map<math.Person, math.Person> get_persons3();
        public List<Set<math.Person>> get_persons4();
        public void send_bool(boolean value);
        public void send_int8(byte value);
        public void send_int16(short value);
        public void send_int32(int value);
        public void send_int64(long value);
        public void send_float(float value);
        public void send_string(String value);
        public void send_binary(String value);
        public void send_color(math.Color color);
        public void send_person(math.Person person);
        public void send_int32_sequence(List<Integer> numbers);
        public void send_persons(List<math.Person> persons);
        public void send_persons2(Set<math.Person> persons);
        public void send_int32_set_seq(List<Set<Integer>> xx);
        public void send_persons3(Map<math.Person, math.Person> persons);
        public void send_person_vec_set(Set<List<math.Person>> xxx);
        public void out_boolean(BooleanHolder value);
        public void out_int8(ByteHolder value);
        public void out_int16(ShortHolder value);
        public void out_int32(IntHolder value);
        public void out_int64(LongHolder value);
        public void out_float(FloatHolder value);
        public void out_string(StringHolder value);
        public void out_binary(StringHolder value);
        public void out_person(math.PersonHolder person);
        public void out_seq(Holder<List<Integer>> xxx);
        public void out_string_set(Holder<Set<String>> xxx);
        public void out_int16_float_map(Holder<Map<Short, Float>> xxx);
        public void out_int_vec_set(Holder<Set<List<Integer>>> xxx);
        public void all_boolean(BooleanHolder value);
        public void all_int8(ByteHolder value);
        public void all_int16(ShortHolder value);
        public void all_int32(IntHolder value);
        public void all_int64(LongHolder value);
        public void all_float(FloatHolder value);
        public void all_string(StringHolder value);
        public void all_binary(StringHolder value);
        public void all_int32_seq(Holder<List<Integer>> value);
        public void all_person(math.PersonHolder value);
        public void all_int32_set(Holder<Set<Integer>> value);
        public void all_person_seq(Holder<List<math.Person>> value);
        public void all_int32_person_map(Holder<Map<Integer, math.Person>> value);
        public void color_out_all(math.ColorHolder color1, math.ColorHolder color2);
        public List<math.Color> color_xx(Set<math.Color> color1, Holder<List<math.Color>> color2, Holder<Map<math.Color, math.Color>> color3);
    }

    public static class ping_args {
        public ping_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("ping_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class add_args {
        public IntHolder a;
        public IntHolder b;
        public add_args() {
            this.a = new IntHolder();
            this.b = new IntHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("add_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("a", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.a.value);
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("b", DataType.IDINT32, 2);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.b.value);
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
                    ret = protocol.readInt(this.a);
                    if (ret < 0) { return ret; }
                    break;
                case 2:
                    ret = protocol.readInt(this.b);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readInt(request + nread, request_len - nread, this.a);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                case 2:
                    ret = protocol.readInt(request + nread, request_len - nread, this.b);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class test_citizen_args {
        public math.CitizenHolder ins;
        public math.CitizenHolder alls;
        public test_citizen_args() {
            this.ins = new math.CitizenHolder();
            this.alls = new math.CitizenHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("test_citizen_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("ins", DataType.IDSTRUCT, 1);
            if (ret < 0) { return ret; }
            ret = ins.value.write(protocol);
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("alls", DataType.IDSTRUCT, 3);
            if (ret < 0) { return ret; }
            ret = alls.value.write(protocol);
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
                    ins.value = new math.Citizen();
                    ret = ins.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                case 3:
                    alls.value = new math.Citizen();
                    ret = alls.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ins.value = new math.Citizen();
                    ret = ins.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                case 3:
                    alls.value = new math.Citizen();
                    ret = alls.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_boolean_args {
        public get_boolean_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_boolean_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_int8_args {
        public get_int8_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int8_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_int16_args {
        public get_int16_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int16_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_int32_args {
        public get_int32_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int32_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_int64_args {
        public get_int64_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int64_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_float_args {
        public get_float_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_float_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_string_args {
        public get_string_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_string_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_binary_args {
        public get_binary_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_binary_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_color_args {
        public get_color_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_color_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_sequence_args {
        public get_sequence_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_sequence_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_string_set_args {
        public get_string_set_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_string_set_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_int_str_map_args {
        public get_int_str_map_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int_str_map_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_bool_set_sequence_args {
        public get_bool_set_sequence_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_bool_set_sequence_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_person_args {
        public get_person_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_person_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_persons_args {
        public get_persons_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_persons2_args {
        public get_persons2_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons2_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_persons3_args {
        public get_persons3_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons3_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class get_persons4_args {
        public get_persons4_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons4_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_bool_args {
        public BooleanHolder value;
        public send_bool_args() {
            this.value = new BooleanHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_bool_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBOOL, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBool(this.value.value);
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
                    ret = protocol.readBool(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBool(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_int8_args {
        public ByteHolder value;
        public send_int8_args() {
            this.value = new ByteHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int8_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBYTE, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeByte(this.value.value);
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
                    ret = protocol.readByte(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readByte(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_int16_args {
        public ShortHolder value;
        public send_int16_args() {
            this.value = new ShortHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int16_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT16, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeShort(this.value.value);
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
                    ret = protocol.readShort(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readShort(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_int32_args {
        public IntHolder value;
        public send_int32_args() {
            this.value = new IntHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int32_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.value.value);
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
                    ret = protocol.readInt(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readInt(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_int64_args {
        public LongHolder value;
        public send_int64_args() {
            this.value = new LongHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int64_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT64, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeLong(this.value.value);
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
                    ret = protocol.readLong(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readLong(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_float_args {
        public FloatHolder value;
        public send_float_args() {
            this.value = new FloatHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_float_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDFLOAT, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeFloat(this.value.value);
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
                    ret = protocol.readFloat(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readFloat(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_string_args {
        public StringHolder value;
        public send_string_args() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_string_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSTR, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeString(this.value.value);
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
                    ret = protocol.readString(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readString(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_binary_args {
        public StringHolder value;
        public send_binary_args() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_binary_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBIN, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBinary(this.value.value);
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
                    ret = protocol.readBinary(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBinary(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_color_args {
        public math.ColorHolder color;
        public send_color_args() {
            this.color = new math.ColorHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_color_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.color.value.getValue());
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
                    IntHolder ele_var55 = new IntHolder();
                    ret = protocol.readInt(ele_var55);
                    if (ret < 0) { return ret; }
                    color.value = math.Color.findByValue(ele_var55.value);
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder ele_var56 = new IntHolder();
                    ret = protocol.readInt(request + nread, request_len - nread, ele_var56);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color.value = math.Color.findByValue(ele_var56.value);
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_person_args {
        public math.PersonHolder person;
        public send_person_args() {
            this.person = new math.PersonHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_person_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("person", DataType.IDSTRUCT, 1);
            if (ret < 0) { return ret; }
            ret = person.value.write(protocol);
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
                    person.value = new math.Person();
                    ret = person.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    person.value = new math.Person();
                    ret = person.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_int32_sequence_args {
        public Holder<List<Integer>> numbers;
        public send_int32_sequence_args() {
            this.numbers = new Holder<List<Integer>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int32_sequence_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("numbers", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDINT32, this.numbers.value.size());
            if (ret < 0) { return ret; }
            for (int itr_var57 : this.numbers.value) {
                ret = protocol.writeInt(itr_var57);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var58 = new IntHolder();
                    DataTypeHolder etype_var59 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var59, size_var58);
                    if (ret < 0) { return ret; }
                    for (int ivar60 = 0; ivar60 < size_var58.value; ++ivar60) {
                        IntHolder value_var61 = new IntHolder();
                        ret = protocol.readInt(value_var61);
                        if (ret < 0) { return ret; }
                        if (numbers.value == null) {
                            numbers.value = new ArrayList<Integer>();
                        }
                        numbers.value.add(value_var61.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var62 = new IntHolder();
                    DataTypeHolder etype_var63 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var63, size_var62);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar64 = 0; ivar64 < size_var62.value; ++ivar64) {
                        IntHolder value_var65 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, value_var65);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (numbers.value == null) {
                            numbers.value = new ArrayList<Integer>();
                        }
                        numbers.value.add(value_var65.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_persons_args {
        public Holder<List<math.Person>> persons;
        public send_persons_args() {
            this.persons = new Holder<List<math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_persons_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("persons", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDSTRUCT, this.persons.value.size());
            if (ret < 0) { return ret; }
            for (math.Person itr_var66 : this.persons.value) {
                ret = itr_var66.write(protocol);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var67 = new IntHolder();
                    DataTypeHolder etype_var68 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var68, size_var67);
                    if (ret < 0) { return ret; }
                    for (int ivar69 = 0; ivar69 < size_var67.value; ++ivar69) {
                        math.PersonHolder value_var70 = new math.PersonHolder();
                        value_var70.value = new math.Person();
                        ret = value_var70.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (persons.value == null) {
                            persons.value = new ArrayList<math.Person>();
                        }
                        persons.value.add(value_var70.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var71 = new IntHolder();
                    DataTypeHolder etype_var72 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var72, size_var71);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar73 = 0; ivar73 < size_var71.value; ++ivar73) {
                        math.PersonHolder value_var74 = new math.PersonHolder();
                        value_var74.value = new math.Person();
                        ret = value_var74.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (persons.value == null) {
                            persons.value = new ArrayList<math.Person>();
                        }
                        persons.value.add(value_var74.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_persons2_args {
        public Holder<Set<math.Person>> persons;
        public send_persons2_args() {
            this.persons = new Holder<Set<math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_persons2_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("persons", DataType.IDSET, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDSTRUCT, this.persons.value.size());
            if (ret < 0) { return ret; }
            for (math.Person itr_var75 : this.persons.value) {
                ret = itr_var75.write(protocol);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                    IntHolder size_var76 = new IntHolder();
                    DataTypeHolder etype_var77 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var77, size_var76);
                    if (ret < 0) { return ret; }
                    for (int ivar78 = 0; ivar78 < size_var76.value; ++ivar78) {
                        math.PersonHolder value_var79 = new math.PersonHolder();
                        value_var79.value = new math.Person();
                        ret = value_var79.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (persons.value == null) {
                            persons.value = new HashSet<math.Person>();
                        }
                        persons.value.add(value_var79.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var80 = new IntHolder();
                    DataTypeHolder etype_var81 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var81, size_var80);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar82 = 0; ivar82 < size_var80.value; ++ivar82) {
                        math.PersonHolder value_var83 = new math.PersonHolder();
                        value_var83.value = new math.Person();
                        ret = value_var83.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (persons.value == null) {
                            persons.value = new HashSet<math.Person>();
                        }
                        persons.value.add(value_var83.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_int32_set_seq_args {
        public Holder<List<Set<Integer>>> xx;
        public send_int32_set_seq_args() {
            this.xx = new Holder<List<Set<Integer>>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int32_set_seq_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("xx", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDSET, this.xx.value.size());
            if (ret < 0) { return ret; }
            for (Set<Integer> itr_var84 : this.xx.value) {
                ret = protocol.writeSetBegin(DataType.IDINT32, itr_var84.size());
                if (ret < 0) { return ret; }
                for (int itr_var85 : itr_var84) {
                    ret = protocol.writeInt(itr_var85);
                    if (ret < 0) { return ret; }
                }
                ret = protocol.writeSetEnd();
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var86 = new IntHolder();
                    DataTypeHolder etype_var87 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var87, size_var86);
                    if (ret < 0) { return ret; }
                    for (int ivar88 = 0; ivar88 < size_var86.value; ++ivar88) {
                        Holder<Set<Integer>> value_var89 = new Holder<Set<Integer>>();
                        IntHolder size_var90 = new IntHolder();
                        DataTypeHolder etype_var91 = new DataTypeHolder();

                         ret = protocol.readSetBegin(etype_var91, size_var90);
                        if (ret < 0) { return ret; }
                        for (int ivar92 = 0; ivar92 < size_var90.value; ++ivar92) {
                            IntHolder value_var93 = new IntHolder();
                            ret = protocol.readInt(value_var93);
                            if (ret < 0) { return ret; }
                            if (value_var89.value == null) {
                                value_var89.value = new HashSet<Integer>();
                            }
                            value_var89.value.add(value_var93.value);
                        }
                        ret = protocol.readSetEnd();
                        if (ret < 0) { return ret; }
                        if (xx.value == null) {
                            xx.value = new ArrayList<Set<Integer>>();
                        }
                        xx.value.add(value_var89.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var94 = new IntHolder();
                    DataTypeHolder etype_var95 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var95, size_var94);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar96 = 0; ivar96 < size_var94.value; ++ivar96) {
                        Holder<Set<Integer>> value_var97 = new Holder<Set<Integer>>();
                        IntHolder size_var98 = new IntHolder();
                        DataTypeHolder etype_var99 = new DataTypeHolder();

                        ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var99, size_var98);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        for (int ivar100 = 0; ivar100 < size_var98.value; ++ivar100) {
                            IntHolder value_var101 = new IntHolder();
                            ret = protocol.readInt(request + nread, request_len - nread, value_var101);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            if (value_var97.value == null) {
                                value_var97.value = new HashSet<Integer>();
                            }
                            value_var97.value.add(value_var101.value);
                        }
                        ret = protocol.readSetEnd();
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (xx.value == null) {
                            xx.value = new ArrayList<Set<Integer>>();
                        }
                        xx.value.add(value_var97.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_persons3_args {
        public Holder<Map<math.Person, math.Person>> persons;
        public send_persons3_args() {
            this.persons = new Holder<Map<math.Person, math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_persons3_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("persons", DataType.IDMAP, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDSTRUCT, DataType.IDSTRUCT, this.persons.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<math.Person, math.Person> citr_var102 : this.persons.value.entrySet()) {
                ret = citr_var102.getKey().write(protocol);
                if (ret < 0) { return ret; }
                ret = citr_var102.getValue().write(protocol);
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
                    IntHolder size_var103 = new IntHolder();
                    DataTypeHolder key_var104 = new DataTypeHolder();

                    DataTypeHolder vlaue_var105 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var104, vlaue_var105, size_var103);
                    if (ret < 0) { return ret; }
                    for (int ivar106 = 0; ivar106 < size_var103.value; ++ivar106) {
                        math.PersonHolder key_var107 = new math.PersonHolder();
                        math.PersonHolder value_var108 = new math.PersonHolder();
                        key_var107.value = new math.Person();
                        ret = key_var107.value.read(protocol);
                        if (ret < 0) { return ret; }
                        value_var108.value = new math.Person();
                        ret = value_var108.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (persons.value == null) {
                            persons.value = new HashMap<math.Person, math.Person>();
                        }
                        persons.value.put(key_var107.value, value_var108.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var109 = new IntHolder();
                    DataTypeHolder key_var110 = new DataTypeHolder();

                    DataTypeHolder vlaue_var111 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var110, vlaue_var111, size_var109);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar112 = 0; ivar112 < size_var109.value; ++ivar112) {
                        math.PersonHolder key_var113 = new math.PersonHolder();
                        math.PersonHolder value_var114 = new math.PersonHolder();
                        key_var113.value = new math.Person();
                        ret = key_var113.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var114.value = new math.Person();
                        ret = value_var114.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (persons.value == null) {
                            persons.value = new HashMap<math.Person, math.Person>();
                        }
                        persons.value.put(key_var113.value, value_var114.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class send_person_vec_set_args {
        public Holder<Set<List<math.Person>>> xxx;
        public send_person_vec_set_args() {
            this.xxx = new Holder<Set<List<math.Person>>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_person_vec_set_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("xxx", DataType.IDSET, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDLIST, this.xxx.value.size());
            if (ret < 0) { return ret; }
            for (List<math.Person> itr_var115 : this.xxx.value) {
                ret = protocol.writeListBegin(DataType.IDSTRUCT, itr_var115.size());
                if (ret < 0) { return ret; }
                for (math.Person itr_var116 : itr_var115) {
                    ret = itr_var116.write(protocol);
                    if (ret < 0) { return ret; }
                }
                ret = protocol.writeListEnd();
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                    IntHolder size_var117 = new IntHolder();
                    DataTypeHolder etype_var118 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var118, size_var117);
                    if (ret < 0) { return ret; }
                    for (int ivar119 = 0; ivar119 < size_var117.value; ++ivar119) {
                        Holder<List<math.Person>> value_var120 = new Holder<List<math.Person>>();
                        IntHolder size_var121 = new IntHolder();
                        DataTypeHolder etype_var122 = new DataTypeHolder();

                         ret = protocol.readListBegin(etype_var122, size_var121);
                        if (ret < 0) { return ret; }
                        for (int ivar123 = 0; ivar123 < size_var121.value; ++ivar123) {
                            math.PersonHolder value_var124 = new math.PersonHolder();
                            value_var124.value = new math.Person();
                            ret = value_var124.value.read(protocol);
                            if (ret < 0) { return ret; }
                            if (value_var120.value == null) {
                                value_var120.value = new ArrayList<math.Person>();
                            }
                            value_var120.value.add(value_var124.value);
                        }
                        ret = protocol.readListEnd();
                        if (ret < 0) { return ret; }
                        if (xxx.value == null) {
                            xxx.value = new HashSet<List<math.Person>>();
                        }
                        xxx.value.add(value_var120.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var125 = new IntHolder();
                    DataTypeHolder etype_var126 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var126, size_var125);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar127 = 0; ivar127 < size_var125.value; ++ivar127) {
                        Holder<List<math.Person>> value_var128 = new Holder<List<math.Person>>();
                        IntHolder size_var129 = new IntHolder();
                        DataTypeHolder etype_var130 = new DataTypeHolder();

                        ret = protocol.readListBegin(request + nread, request_len - nread, etype_var130, size_var129);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        for (int ivar131 = 0; ivar131 < size_var129.value; ++ivar131) {
                            math.PersonHolder value_var132 = new math.PersonHolder();
                            value_var132.value = new math.Person();
                            ret = value_var132.value.read(protocol, request + nread, request_len - nread);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            if (value_var128.value == null) {
                                value_var128.value = new ArrayList<math.Person>();
                            }
                            value_var128.value.add(value_var132.value);
                        }
                        ret = protocol.readListEnd();
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (xxx.value == null) {
                            xxx.value = new HashSet<List<math.Person>>();
                        }
                        xxx.value.add(value_var128.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_boolean_args {
        public out_boolean_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_boolean_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_int8_args {
        public out_int8_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int8_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_int16_args {
        public out_int16_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int16_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_int32_args {
        public out_int32_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int32_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_int64_args {
        public out_int64_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int64_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_float_args {
        public out_float_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_float_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_string_args {
        public out_string_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_string_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_binary_args {
        public out_binary_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_binary_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_person_args {
        public out_person_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_person_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_seq_args {
        public out_seq_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_seq_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_string_set_args {
        public out_string_set_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_string_set_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_int16_float_map_args {
        public out_int16_float_map_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int16_float_map_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class out_int_vec_set_args {
        public out_int_vec_set_args() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int_vec_set_args");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_boolean_args {
        public BooleanHolder value;
        public all_boolean_args() {
            this.value = new BooleanHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_boolean_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBOOL, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBool(this.value.value);
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
                    ret = protocol.readBool(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBool(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_int8_args {
        public ByteHolder value;
        public all_int8_args() {
            this.value = new ByteHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int8_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBYTE, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeByte(this.value.value);
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
                    ret = protocol.readByte(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readByte(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_int16_args {
        public ShortHolder value;
        public all_int16_args() {
            this.value = new ShortHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int16_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT16, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeShort(this.value.value);
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
                    ret = protocol.readShort(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readShort(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_int32_args {
        public IntHolder value;
        public all_int32_args() {
            this.value = new IntHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.value.value);
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
                    ret = protocol.readInt(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readInt(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_int64_args {
        public LongHolder value;
        public all_int64_args() {
            this.value = new LongHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int64_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT64, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeLong(this.value.value);
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
                    ret = protocol.readLong(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readLong(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_float_args {
        public FloatHolder value;
        public all_float_args() {
            this.value = new FloatHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_float_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDFLOAT, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeFloat(this.value.value);
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
                    ret = protocol.readFloat(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readFloat(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_string_args {
        public StringHolder value;
        public all_string_args() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_string_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSTR, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeString(this.value.value);
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
                    ret = protocol.readString(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readString(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_binary_args {
        public StringHolder value;
        public all_binary_args() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_binary_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBIN, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBinary(this.value.value);
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
                    ret = protocol.readBinary(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBinary(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_int32_seq_args {
        public Holder<List<Integer>> value;
        public all_int32_seq_args() {
            this.value = new Holder<List<Integer>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_seq_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDINT32, this.value.value.size());
            if (ret < 0) { return ret; }
            for (int itr_var133 : this.value.value) {
                ret = protocol.writeInt(itr_var133);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var134 = new IntHolder();
                    DataTypeHolder etype_var135 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var135, size_var134);
                    if (ret < 0) { return ret; }
                    for (int ivar136 = 0; ivar136 < size_var134.value; ++ivar136) {
                        IntHolder value_var137 = new IntHolder();
                        ret = protocol.readInt(value_var137);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new ArrayList<Integer>();
                        }
                        value.value.add(value_var137.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var138 = new IntHolder();
                    DataTypeHolder etype_var139 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var139, size_var138);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar140 = 0; ivar140 < size_var138.value; ++ivar140) {
                        IntHolder value_var141 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, value_var141);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new ArrayList<Integer>();
                        }
                        value.value.add(value_var141.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_person_args {
        public math.PersonHolder value;
        public all_person_args() {
            this.value = new math.PersonHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_person_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSTRUCT, 1);
            if (ret < 0) { return ret; }
            ret = value.value.write(protocol);
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
                    value.value = new math.Person();
                    ret = value.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    value.value = new math.Person();
                    ret = value.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_int32_set_args {
        public Holder<Set<Integer>> value;
        public all_int32_set_args() {
            this.value = new Holder<Set<Integer>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_set_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSET, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDINT32, this.value.value.size());
            if (ret < 0) { return ret; }
            for (int itr_var142 : this.value.value) {
                ret = protocol.writeInt(itr_var142);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                    IntHolder size_var143 = new IntHolder();
                    DataTypeHolder etype_var144 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var144, size_var143);
                    if (ret < 0) { return ret; }
                    for (int ivar145 = 0; ivar145 < size_var143.value; ++ivar145) {
                        IntHolder value_var146 = new IntHolder();
                        ret = protocol.readInt(value_var146);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new HashSet<Integer>();
                        }
                        value.value.add(value_var146.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var147 = new IntHolder();
                    DataTypeHolder etype_var148 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var148, size_var147);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar149 = 0; ivar149 < size_var147.value; ++ivar149) {
                        IntHolder value_var150 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, value_var150);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new HashSet<Integer>();
                        }
                        value.value.add(value_var150.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_person_seq_args {
        public Holder<List<math.Person>> value;
        public all_person_seq_args() {
            this.value = new Holder<List<math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_person_seq_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDSTRUCT, this.value.value.size());
            if (ret < 0) { return ret; }
            for (math.Person itr_var151 : this.value.value) {
                ret = itr_var151.write(protocol);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var152 = new IntHolder();
                    DataTypeHolder etype_var153 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var153, size_var152);
                    if (ret < 0) { return ret; }
                    for (int ivar154 = 0; ivar154 < size_var152.value; ++ivar154) {
                        math.PersonHolder value_var155 = new math.PersonHolder();
                        value_var155.value = new math.Person();
                        ret = value_var155.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new ArrayList<math.Person>();
                        }
                        value.value.add(value_var155.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var156 = new IntHolder();
                    DataTypeHolder etype_var157 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var157, size_var156);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar158 = 0; ivar158 < size_var156.value; ++ivar158) {
                        math.PersonHolder value_var159 = new math.PersonHolder();
                        value_var159.value = new math.Person();
                        ret = value_var159.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new ArrayList<math.Person>();
                        }
                        value.value.add(value_var159.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class all_int32_person_map_args {
        public Holder<Map<Integer, math.Person>> value;
        public all_int32_person_map_args() {
            this.value = new Holder<Map<Integer, math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_person_map_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDMAP, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDINT32, DataType.IDSTRUCT, this.value.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<Integer, math.Person> citr_var160 : this.value.value.entrySet()) {
                ret = protocol.writeInt(citr_var160.getKey());
                if (ret < 0) { return ret; }
                ret = citr_var160.getValue().write(protocol);
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
                    IntHolder size_var161 = new IntHolder();
                    DataTypeHolder key_var162 = new DataTypeHolder();

                    DataTypeHolder vlaue_var163 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var162, vlaue_var163, size_var161);
                    if (ret < 0) { return ret; }
                    for (int ivar164 = 0; ivar164 < size_var161.value; ++ivar164) {
                        IntHolder key_var165 = new IntHolder();
                        math.PersonHolder value_var166 = new math.PersonHolder();
                        ret = protocol.readInt(key_var165);
                        if (ret < 0) { return ret; }
                        value_var166.value = new math.Person();
                        ret = value_var166.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new HashMap<Integer, math.Person>();
                        }
                        value.value.put(key_var165.value, value_var166.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var167 = new IntHolder();
                    DataTypeHolder key_var168 = new DataTypeHolder();

                    DataTypeHolder vlaue_var169 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var168, vlaue_var169, size_var167);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar170 = 0; ivar170 < size_var167.value; ++ivar170) {
                        IntHolder key_var171 = new IntHolder();
                        math.PersonHolder value_var172 = new math.PersonHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, key_var171);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var172.value = new math.Person();
                        ret = value_var172.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new HashMap<Integer, math.Person>();
                        }
                        value.value.put(key_var171.value, value_var172.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class color_out_all_args {
        public math.ColorHolder color1;
        public color_out_all_args() {
            this.color1 = new math.ColorHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("color_out_all_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color1", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.color1.value.getValue());
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
                    IntHolder ele_var173 = new IntHolder();
                    ret = protocol.readInt(ele_var173);
                    if (ret < 0) { return ret; }
                    color1.value = math.Color.findByValue(ele_var173.value);
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder ele_var174 = new IntHolder();
                    ret = protocol.readInt(request + nread, request_len - nread, ele_var174);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color1.value = math.Color.findByValue(ele_var174.value);
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class color_xx_args {
        public Holder<Set<math.Color>> color1;
        public Holder<Map<math.Color, math.Color>> color3;
        public color_xx_args() {
            this.color1 = new Holder<Set<math.Color>>();
            this.color3 = new Holder<Map<math.Color, math.Color>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("color_xx_args");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color1", DataType.IDSET, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDINT32, this.color1.value.size());
            if (ret < 0) { return ret; }
            for (math.Color itr_var175 : this.color1.value) {
                ret = protocol.writeInt(itr_var175.getValue());
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color3", DataType.IDMAP, 3);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDINT32, DataType.IDINT32, this.color3.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<math.Color, math.Color> citr_var176 : this.color3.value.entrySet()) {
                ret = protocol.writeInt(citr_var176.getKey().getValue());
                if (ret < 0) { return ret; }
                ret = protocol.writeInt(citr_var176.getValue().getValue());
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
                    IntHolder size_var177 = new IntHolder();
                    DataTypeHolder etype_var178 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var178, size_var177);
                    if (ret < 0) { return ret; }
                    for (int ivar179 = 0; ivar179 < size_var177.value; ++ivar179) {
                        math.ColorHolder value_var180 = new math.ColorHolder();
                        IntHolder ele_var181 = new IntHolder();
                        ret = protocol.readInt(ele_var181);
                        if (ret < 0) { return ret; }
                        value_var180.value = math.Color.findByValue(ele_var181.value);
                        if (color1.value == null) {
                            color1.value = new HashSet<math.Color>();
                        }
                        color1.value.add(value_var180.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    break;
                case 3:
                    IntHolder size_var182 = new IntHolder();
                    DataTypeHolder key_var183 = new DataTypeHolder();

                    DataTypeHolder vlaue_var184 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var183, vlaue_var184, size_var182);
                    if (ret < 0) { return ret; }
                    for (int ivar185 = 0; ivar185 < size_var182.value; ++ivar185) {
                        math.ColorHolder key_var186 = new math.ColorHolder();
                        math.ColorHolder value_var187 = new math.ColorHolder();
                        IntHolder ele_var188 = new IntHolder();
                        ret = protocol.readInt(ele_var188);
                        if (ret < 0) { return ret; }
                        key_var186.value = math.Color.findByValue(ele_var188.value);
                        IntHolder ele_var189 = new IntHolder();
                        ret = protocol.readInt(ele_var189);
                        if (ret < 0) { return ret; }
                        value_var187.value = math.Color.findByValue(ele_var189.value);
                        if (color3.value == null) {
                            color3.value = new HashMap<math.Color, math.Color>();
                        }
                        color3.value.put(key_var186.value, value_var187.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var190 = new IntHolder();
                    DataTypeHolder etype_var191 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var191, size_var190);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar192 = 0; ivar192 < size_var190.value; ++ivar192) {
                        math.ColorHolder value_var193 = new math.ColorHolder();
                        IntHolder ele_var194 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, ele_var194);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var193.value = math.Color.findByValue(ele_var194.value);
                        if (color1.value == null) {
                            color1.value = new HashSet<math.Color>();
                        }
                        color1.value.add(value_var193.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                case 3:
                    IntHolder size_var195 = new IntHolder();
                    DataTypeHolder key_var196 = new DataTypeHolder();

                    DataTypeHolder vlaue_var197 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var196, vlaue_var197, size_var195);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar198 = 0; ivar198 < size_var195.value; ++ivar198) {
                        math.ColorHolder key_var199 = new math.ColorHolder();
                        math.ColorHolder value_var200 = new math.ColorHolder();
                        IntHolder ele_var201 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, ele_var201);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        key_var199.value = math.Color.findByValue(ele_var201.value);
                        IntHolder ele_var202 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, ele_var202);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var200.value = math.Color.findByValue(ele_var202.value);
                        if (color3.value == null) {
                            color3.value = new HashMap<math.Color, math.Color>();
                        }
                        color3.value.put(key_var199.value, value_var200.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
                nread += ret;

            }

            ret = protocol.readStructEnd();
            if (ret < 0) { return ret; }
            nread += ret;

            return nread;
        }

    }

    public static class ping_result {

        public ping_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("ping_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class add_result {

        public math.AddResultHolder return_value;

        public IntHolder sum;
        public add_result() {
            return_value = new math.AddResultHolder();
            this.sum = new IntHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("add_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDINT32, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.return_value.value.getValue());
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("sum", DataType.IDINT32, 3);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.sum.value);
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
                case 0:
                    IntHolder ele_var203 = new IntHolder();
                    ret = protocol.readInt(ele_var203);
                    if (ret < 0) { return ret; }
                    return_value.value = math.AddResult.findByValue(ele_var203.value);
                break;
                case 3:
                    ret = protocol.readInt(this.sum);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder ele_var204 = new IntHolder();
                    ret = protocol.readInt(request + nread, request_len - nread, ele_var204);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    return_value.value = math.AddResult.findByValue(ele_var204.value);
                break;
                case 3:
                    ret = protocol.readInt(request + nread, request_len - nread, this.sum);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class test_citizen_result {

        public math.CitizenHolder return_value;

        public math.CitizenHolder outs;
        public math.CitizenHolder alls;
        public test_citizen_result() {
            return_value = new math.CitizenHolder();
            this.outs = new math.CitizenHolder();
            this.alls = new math.CitizenHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("test_citizen_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDSTRUCT, 0);
            if (ret < 0) { return ret; }
            ret = return_value.value.write(protocol);
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("outs", DataType.IDSTRUCT, 2);
            if (ret < 0) { return ret; }
            ret = outs.value.write(protocol);
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("alls", DataType.IDSTRUCT, 3);
            if (ret < 0) { return ret; }
            ret = alls.value.write(protocol);
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
                case 0:
                    return_value.value = new math.Citizen();
                    ret = return_value.value.read(protocol);
                    if (ret < 0) { return ret; }
                break;
                case 2:
                    outs.value = new math.Citizen();
                    ret = outs.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                case 3:
                    alls.value = new math.Citizen();
                    ret = alls.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    return_value.value = new math.Citizen();
                    ret = return_value.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                case 2:
                    outs.value = new math.Citizen();
                    ret = outs.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                case 3:
                    alls.value = new math.Citizen();
                    ret = alls.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_boolean_result {

        public BooleanHolder return_value;

        public get_boolean_result() {
            return_value = new BooleanHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_boolean_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDBOOL, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeBool(this.return_value.value);
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
                case 0:
                    ret = protocol.readBool(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readBool(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_int8_result {

        public ByteHolder return_value;

        public get_int8_result() {
            return_value = new ByteHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int8_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDBYTE, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeByte(this.return_value.value);
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
                case 0:
                    ret = protocol.readByte(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readByte(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_int16_result {

        public ShortHolder return_value;

        public get_int16_result() {
            return_value = new ShortHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int16_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDINT16, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeShort(this.return_value.value);
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
                case 0:
                    ret = protocol.readShort(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readShort(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_int32_result {

        public IntHolder return_value;

        public get_int32_result() {
            return_value = new IntHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int32_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDINT32, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.return_value.value);
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
                case 0:
                    ret = protocol.readInt(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readInt(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_int64_result {

        public LongHolder return_value;

        public get_int64_result() {
            return_value = new LongHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int64_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDINT64, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeLong(this.return_value.value);
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
                case 0:
                    ret = protocol.readLong(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readLong(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_float_result {

        public FloatHolder return_value;

        public get_float_result() {
            return_value = new FloatHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_float_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDFLOAT, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeFloat(this.return_value.value);
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
                case 0:
                    ret = protocol.readFloat(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readFloat(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_string_result {

        public StringHolder return_value;

        public get_string_result() {
            return_value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_string_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDSTR, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeString(this.return_value.value);
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
                case 0:
                    ret = protocol.readString(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readString(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_binary_result {

        public StringHolder return_value;

        public get_binary_result() {
            return_value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_binary_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDBIN, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeBinary(this.return_value.value);
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
                case 0:
                    ret = protocol.readBinary(this.return_value);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    ret = protocol.readBinary(request + nread, request_len - nread, this.return_value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_color_result {

        public math.ColorHolder return_value;

        public get_color_result() {
            return_value = new math.ColorHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_color_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDINT32, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.return_value.value.getValue());
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
                case 0:
                    IntHolder ele_var205 = new IntHolder();
                    ret = protocol.readInt(ele_var205);
                    if (ret < 0) { return ret; }
                    return_value.value = math.Color.findByValue(ele_var205.value);
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder ele_var206 = new IntHolder();
                    ret = protocol.readInt(request + nread, request_len - nread, ele_var206);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    return_value.value = math.Color.findByValue(ele_var206.value);
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_sequence_result {

        public Holder<List<Integer>> return_value;

        public get_sequence_result() {
            return_value = new Holder<List<Integer>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_sequence_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDLIST, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDINT32, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (int itr_var207 : this.return_value.value) {
                ret = protocol.writeInt(itr_var207);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                case 0:
                    IntHolder size_var208 = new IntHolder();
                    DataTypeHolder etype_var209 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var209, size_var208);
                    if (ret < 0) { return ret; }
                    for (int ivar210 = 0; ivar210 < size_var208.value; ++ivar210) {
                        IntHolder value_var211 = new IntHolder();
                        ret = protocol.readInt(value_var211);
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<Integer>();
                        }
                        return_value.value.add(value_var211.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var212 = new IntHolder();
                    DataTypeHolder etype_var213 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var213, size_var212);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar214 = 0; ivar214 < size_var212.value; ++ivar214) {
                        IntHolder value_var215 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, value_var215);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<Integer>();
                        }
                        return_value.value.add(value_var215.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_string_set_result {

        public Holder<Set<String>> return_value;

        public get_string_set_result() {
            return_value = new Holder<Set<String>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_string_set_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDSET, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDSTR, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (String itr_var216 : this.return_value.value) {
                ret = protocol.writeString(itr_var216);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                case 0:
                    IntHolder size_var217 = new IntHolder();
                    DataTypeHolder etype_var218 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var218, size_var217);
                    if (ret < 0) { return ret; }
                    for (int ivar219 = 0; ivar219 < size_var217.value; ++ivar219) {
                        StringHolder value_var220 = new StringHolder();
                        ret = protocol.readString(value_var220);
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new HashSet<String>();
                        }
                        return_value.value.add(value_var220.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var221 = new IntHolder();
                    DataTypeHolder etype_var222 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var222, size_var221);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar223 = 0; ivar223 < size_var221.value; ++ivar223) {
                        StringHolder value_var224 = new StringHolder();
                        ret = protocol.readString(request + nread, request_len - nread, value_var224);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new HashSet<String>();
                        }
                        return_value.value.add(value_var224.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_int_str_map_result {

        public Holder<Map<Long, String>> return_value;

        public get_int_str_map_result() {
            return_value = new Holder<Map<Long, String>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_int_str_map_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDMAP, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDINT64, DataType.IDSTR, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<Long, String> citr_var225 : this.return_value.value.entrySet()) {
                ret = protocol.writeLong(citr_var225.getKey());
                if (ret < 0) { return ret; }
                ret = protocol.writeString(citr_var225.getValue());
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
                case 0:
                    IntHolder size_var226 = new IntHolder();
                    DataTypeHolder key_var227 = new DataTypeHolder();

                    DataTypeHolder vlaue_var228 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var227, vlaue_var228, size_var226);
                    if (ret < 0) { return ret; }
                    for (int ivar229 = 0; ivar229 < size_var226.value; ++ivar229) {
                        LongHolder key_var230 = new LongHolder();
                        StringHolder value_var231 = new StringHolder();
                        ret = protocol.readLong(key_var230);
                        if (ret < 0) { return ret; }
                        ret = protocol.readString(value_var231);
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new HashMap<Long, String>();
                        }
                        return_value.value.put(key_var230.value, value_var231.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var232 = new IntHolder();
                    DataTypeHolder key_var233 = new DataTypeHolder();

                    DataTypeHolder vlaue_var234 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var233, vlaue_var234, size_var232);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar235 = 0; ivar235 < size_var232.value; ++ivar235) {
                        LongHolder key_var236 = new LongHolder();
                        StringHolder value_var237 = new StringHolder();
                        ret = protocol.readLong(request + nread, request_len - nread, key_var236);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        ret = protocol.readString(request + nread, request_len - nread, value_var237);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new HashMap<Long, String>();
                        }
                        return_value.value.put(key_var236.value, value_var237.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_bool_set_sequence_result {

        public Holder<List<Set<Boolean>>> return_value;

        public get_bool_set_sequence_result() {
            return_value = new Holder<List<Set<Boolean>>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_bool_set_sequence_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDLIST, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDSET, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (Set<Boolean> itr_var238 : this.return_value.value) {
                ret = protocol.writeSetBegin(DataType.IDBOOL, itr_var238.size());
                if (ret < 0) { return ret; }
                for (boolean itr_var239 : itr_var238) {
                    ret = protocol.writeBool(itr_var239);
                    if (ret < 0) { return ret; }
                }
                ret = protocol.writeSetEnd();
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                case 0:
                    IntHolder size_var240 = new IntHolder();
                    DataTypeHolder etype_var241 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var241, size_var240);
                    if (ret < 0) { return ret; }
                    for (int ivar242 = 0; ivar242 < size_var240.value; ++ivar242) {
                        Holder<Set<Boolean>> value_var243 = new Holder<Set<Boolean>>();
                        IntHolder size_var244 = new IntHolder();
                        DataTypeHolder etype_var245 = new DataTypeHolder();

                         ret = protocol.readSetBegin(etype_var245, size_var244);
                        if (ret < 0) { return ret; }
                        for (int ivar246 = 0; ivar246 < size_var244.value; ++ivar246) {
                            BooleanHolder value_var247 = new BooleanHolder();
                            ret = protocol.readBool(value_var247);
                            if (ret < 0) { return ret; }
                            if (value_var243.value == null) {
                                value_var243.value = new HashSet<Boolean>();
                            }
                            value_var243.value.add(value_var247.value);
                        }
                        ret = protocol.readSetEnd();
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<Set<Boolean>>();
                        }
                        return_value.value.add(value_var243.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var248 = new IntHolder();
                    DataTypeHolder etype_var249 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var249, size_var248);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar250 = 0; ivar250 < size_var248.value; ++ivar250) {
                        Holder<Set<Boolean>> value_var251 = new Holder<Set<Boolean>>();
                        IntHolder size_var252 = new IntHolder();
                        DataTypeHolder etype_var253 = new DataTypeHolder();

                        ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var253, size_var252);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        for (int ivar254 = 0; ivar254 < size_var252.value; ++ivar254) {
                            BooleanHolder value_var255 = new BooleanHolder();
                            ret = protocol.readBool(request + nread, request_len - nread, value_var255);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            if (value_var251.value == null) {
                                value_var251.value = new HashSet<Boolean>();
                            }
                            value_var251.value.add(value_var255.value);
                        }
                        ret = protocol.readSetEnd();
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<Set<Boolean>>();
                        }
                        return_value.value.add(value_var251.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_person_result {

        public math.PersonHolder return_value;

        public get_person_result() {
            return_value = new math.PersonHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_person_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDSTRUCT, 0);
            if (ret < 0) { return ret; }
            ret = return_value.value.write(protocol);
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
                case 0:
                    return_value.value = new math.Person();
                    ret = return_value.value.read(protocol);
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    return_value.value = new math.Person();
                    ret = return_value.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_persons_result {

        public Holder<List<math.Person>> return_value;

        public get_persons_result() {
            return_value = new Holder<List<math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDLIST, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDSTRUCT, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (math.Person itr_var256 : this.return_value.value) {
                ret = itr_var256.write(protocol);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                case 0:
                    IntHolder size_var257 = new IntHolder();
                    DataTypeHolder etype_var258 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var258, size_var257);
                    if (ret < 0) { return ret; }
                    for (int ivar259 = 0; ivar259 < size_var257.value; ++ivar259) {
                        math.PersonHolder value_var260 = new math.PersonHolder();
                        value_var260.value = new math.Person();
                        ret = value_var260.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<math.Person>();
                        }
                        return_value.value.add(value_var260.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var261 = new IntHolder();
                    DataTypeHolder etype_var262 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var262, size_var261);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar263 = 0; ivar263 < size_var261.value; ++ivar263) {
                        math.PersonHolder value_var264 = new math.PersonHolder();
                        value_var264.value = new math.Person();
                        ret = value_var264.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<math.Person>();
                        }
                        return_value.value.add(value_var264.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_persons2_result {

        public Holder<Set<math.Person>> return_value;

        public get_persons2_result() {
            return_value = new Holder<Set<math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons2_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDSET, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDSTRUCT, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (math.Person itr_var265 : this.return_value.value) {
                ret = itr_var265.write(protocol);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                case 0:
                    IntHolder size_var266 = new IntHolder();
                    DataTypeHolder etype_var267 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var267, size_var266);
                    if (ret < 0) { return ret; }
                    for (int ivar268 = 0; ivar268 < size_var266.value; ++ivar268) {
                        math.PersonHolder value_var269 = new math.PersonHolder();
                        value_var269.value = new math.Person();
                        ret = value_var269.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new HashSet<math.Person>();
                        }
                        return_value.value.add(value_var269.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var270 = new IntHolder();
                    DataTypeHolder etype_var271 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var271, size_var270);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar272 = 0; ivar272 < size_var270.value; ++ivar272) {
                        math.PersonHolder value_var273 = new math.PersonHolder();
                        value_var273.value = new math.Person();
                        ret = value_var273.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new HashSet<math.Person>();
                        }
                        return_value.value.add(value_var273.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_persons3_result {

        public Holder<Map<math.Person, math.Person>> return_value;

        public get_persons3_result() {
            return_value = new Holder<Map<math.Person, math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons3_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDMAP, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDSTRUCT, DataType.IDSTRUCT, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<math.Person, math.Person> citr_var274 : this.return_value.value.entrySet()) {
                ret = citr_var274.getKey().write(protocol);
                if (ret < 0) { return ret; }
                ret = citr_var274.getValue().write(protocol);
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
                case 0:
                    IntHolder size_var275 = new IntHolder();
                    DataTypeHolder key_var276 = new DataTypeHolder();

                    DataTypeHolder vlaue_var277 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var276, vlaue_var277, size_var275);
                    if (ret < 0) { return ret; }
                    for (int ivar278 = 0; ivar278 < size_var275.value; ++ivar278) {
                        math.PersonHolder key_var279 = new math.PersonHolder();
                        math.PersonHolder value_var280 = new math.PersonHolder();
                        key_var279.value = new math.Person();
                        ret = key_var279.value.read(protocol);
                        if (ret < 0) { return ret; }
                        value_var280.value = new math.Person();
                        ret = value_var280.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new HashMap<math.Person, math.Person>();
                        }
                        return_value.value.put(key_var279.value, value_var280.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var281 = new IntHolder();
                    DataTypeHolder key_var282 = new DataTypeHolder();

                    DataTypeHolder vlaue_var283 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var282, vlaue_var283, size_var281);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar284 = 0; ivar284 < size_var281.value; ++ivar284) {
                        math.PersonHolder key_var285 = new math.PersonHolder();
                        math.PersonHolder value_var286 = new math.PersonHolder();
                        key_var285.value = new math.Person();
                        ret = key_var285.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var286.value = new math.Person();
                        ret = value_var286.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new HashMap<math.Person, math.Person>();
                        }
                        return_value.value.put(key_var285.value, value_var286.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class get_persons4_result {

        public Holder<List<Set<math.Person>>> return_value;

        public get_persons4_result() {
            return_value = new Holder<List<Set<math.Person>>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("get_persons4_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDLIST, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDSET, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (Set<math.Person> itr_var287 : this.return_value.value) {
                ret = protocol.writeSetBegin(DataType.IDSTRUCT, itr_var287.size());
                if (ret < 0) { return ret; }
                for (math.Person itr_var288 : itr_var287) {
                    ret = itr_var288.write(protocol);
                    if (ret < 0) { return ret; }
                }
                ret = protocol.writeSetEnd();
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                case 0:
                    IntHolder size_var289 = new IntHolder();
                    DataTypeHolder etype_var290 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var290, size_var289);
                    if (ret < 0) { return ret; }
                    for (int ivar291 = 0; ivar291 < size_var289.value; ++ivar291) {
                        Holder<Set<math.Person>> value_var292 = new Holder<Set<math.Person>>();
                        IntHolder size_var293 = new IntHolder();
                        DataTypeHolder etype_var294 = new DataTypeHolder();

                         ret = protocol.readSetBegin(etype_var294, size_var293);
                        if (ret < 0) { return ret; }
                        for (int ivar295 = 0; ivar295 < size_var293.value; ++ivar295) {
                            math.PersonHolder value_var296 = new math.PersonHolder();
                            value_var296.value = new math.Person();
                            ret = value_var296.value.read(protocol);
                            if (ret < 0) { return ret; }
                            if (value_var292.value == null) {
                                value_var292.value = new HashSet<math.Person>();
                            }
                            value_var292.value.add(value_var296.value);
                        }
                        ret = protocol.readSetEnd();
                        if (ret < 0) { return ret; }
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<Set<math.Person>>();
                        }
                        return_value.value.add(value_var292.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var297 = new IntHolder();
                    DataTypeHolder etype_var298 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var298, size_var297);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar299 = 0; ivar299 < size_var297.value; ++ivar299) {
                        Holder<Set<math.Person>> value_var300 = new Holder<Set<math.Person>>();
                        IntHolder size_var301 = new IntHolder();
                        DataTypeHolder etype_var302 = new DataTypeHolder();

                        ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var302, size_var301);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        for (int ivar303 = 0; ivar303 < size_var301.value; ++ivar303) {
                            math.PersonHolder value_var304 = new math.PersonHolder();
                            value_var304.value = new math.Person();
                            ret = value_var304.value.read(protocol, request + nread, request_len - nread);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            if (value_var300.value == null) {
                                value_var300.value = new HashSet<math.Person>();
                            }
                            value_var300.value.add(value_var304.value);
                        }
                        ret = protocol.readSetEnd();
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<Set<math.Person>>();
                        }
                        return_value.value.add(value_var300.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_bool_result {

        public send_bool_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_bool_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_int8_result {

        public send_int8_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int8_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_int16_result {

        public send_int16_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int16_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_int32_result {

        public send_int32_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int32_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_int64_result {

        public send_int64_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int64_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_float_result {

        public send_float_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_float_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_string_result {

        public send_string_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_string_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_binary_result {

        public send_binary_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_binary_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_color_result {

        public send_color_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_color_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_person_result {

        public send_person_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_person_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_int32_sequence_result {

        public send_int32_sequence_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int32_sequence_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_persons_result {

        public send_persons_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_persons_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_persons2_result {

        public send_persons2_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_persons2_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_int32_set_seq_result {

        public send_int32_set_seq_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_int32_set_seq_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_persons3_result {

        public send_persons3_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_persons3_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class send_person_vec_set_result {

        public send_person_vec_set_result() {
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("send_person_vec_set_result");
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_boolean_result {

        public BooleanHolder value;
        public out_boolean_result() {
            this.value = new BooleanHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_boolean_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBOOL, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBool(this.value.value);
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
                    ret = protocol.readBool(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBool(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_int8_result {

        public ByteHolder value;
        public out_int8_result() {
            this.value = new ByteHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int8_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBYTE, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeByte(this.value.value);
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
                    ret = protocol.readByte(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readByte(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_int16_result {

        public ShortHolder value;
        public out_int16_result() {
            this.value = new ShortHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int16_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT16, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeShort(this.value.value);
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
                    ret = protocol.readShort(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readShort(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_int32_result {

        public IntHolder value;
        public out_int32_result() {
            this.value = new IntHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int32_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.value.value);
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
                    ret = protocol.readInt(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readInt(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_int64_result {

        public LongHolder value;
        public out_int64_result() {
            this.value = new LongHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int64_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT64, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeLong(this.value.value);
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
                    ret = protocol.readLong(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readLong(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_float_result {

        public FloatHolder value;
        public out_float_result() {
            this.value = new FloatHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_float_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDFLOAT, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeFloat(this.value.value);
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
                    ret = protocol.readFloat(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readFloat(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_string_result {

        public StringHolder value;
        public out_string_result() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_string_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSTR, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeString(this.value.value);
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
                    ret = protocol.readString(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readString(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_binary_result {

        public StringHolder value;
        public out_binary_result() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_binary_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBIN, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBinary(this.value.value);
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
                    ret = protocol.readBinary(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBinary(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_person_result {

        public math.PersonHolder person;
        public out_person_result() {
            this.person = new math.PersonHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_person_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("person", DataType.IDSTRUCT, 1);
            if (ret < 0) { return ret; }
            ret = person.value.write(protocol);
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
                    person.value = new math.Person();
                    ret = person.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    person.value = new math.Person();
                    ret = person.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_seq_result {

        public Holder<List<Integer>> xxx;
        public out_seq_result() {
            this.xxx = new Holder<List<Integer>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_seq_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("xxx", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDINT32, this.xxx.value.size());
            if (ret < 0) { return ret; }
            for (int itr_var305 : this.xxx.value) {
                ret = protocol.writeInt(itr_var305);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var306 = new IntHolder();
                    DataTypeHolder etype_var307 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var307, size_var306);
                    if (ret < 0) { return ret; }
                    for (int ivar308 = 0; ivar308 < size_var306.value; ++ivar308) {
                        IntHolder value_var309 = new IntHolder();
                        ret = protocol.readInt(value_var309);
                        if (ret < 0) { return ret; }
                        if (xxx.value == null) {
                            xxx.value = new ArrayList<Integer>();
                        }
                        xxx.value.add(value_var309.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var310 = new IntHolder();
                    DataTypeHolder etype_var311 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var311, size_var310);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar312 = 0; ivar312 < size_var310.value; ++ivar312) {
                        IntHolder value_var313 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, value_var313);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (xxx.value == null) {
                            xxx.value = new ArrayList<Integer>();
                        }
                        xxx.value.add(value_var313.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_string_set_result {

        public Holder<Set<String>> xxx;
        public out_string_set_result() {
            this.xxx = new Holder<Set<String>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_string_set_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("xxx", DataType.IDSET, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDSTR, this.xxx.value.size());
            if (ret < 0) { return ret; }
            for (String itr_var314 : this.xxx.value) {
                ret = protocol.writeString(itr_var314);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                    IntHolder size_var315 = new IntHolder();
                    DataTypeHolder etype_var316 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var316, size_var315);
                    if (ret < 0) { return ret; }
                    for (int ivar317 = 0; ivar317 < size_var315.value; ++ivar317) {
                        StringHolder value_var318 = new StringHolder();
                        ret = protocol.readString(value_var318);
                        if (ret < 0) { return ret; }
                        if (xxx.value == null) {
                            xxx.value = new HashSet<String>();
                        }
                        xxx.value.add(value_var318.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var319 = new IntHolder();
                    DataTypeHolder etype_var320 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var320, size_var319);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar321 = 0; ivar321 < size_var319.value; ++ivar321) {
                        StringHolder value_var322 = new StringHolder();
                        ret = protocol.readString(request + nread, request_len - nread, value_var322);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (xxx.value == null) {
                            xxx.value = new HashSet<String>();
                        }
                        xxx.value.add(value_var322.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_int16_float_map_result {

        public Holder<Map<Short, Float>> xxx;
        public out_int16_float_map_result() {
            this.xxx = new Holder<Map<Short, Float>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int16_float_map_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("xxx", DataType.IDMAP, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDINT16, DataType.IDFLOAT, this.xxx.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<Short, Float> citr_var323 : this.xxx.value.entrySet()) {
                ret = protocol.writeShort(citr_var323.getKey());
                if (ret < 0) { return ret; }
                ret = protocol.writeFloat(citr_var323.getValue());
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
                    IntHolder size_var324 = new IntHolder();
                    DataTypeHolder key_var325 = new DataTypeHolder();

                    DataTypeHolder vlaue_var326 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var325, vlaue_var326, size_var324);
                    if (ret < 0) { return ret; }
                    for (int ivar327 = 0; ivar327 < size_var324.value; ++ivar327) {
                        ShortHolder key_var328 = new ShortHolder();
                        FloatHolder value_var329 = new FloatHolder();
                        ret = protocol.readShort(key_var328);
                        if (ret < 0) { return ret; }
                        ret = protocol.readFloat(value_var329);
                        if (ret < 0) { return ret; }
                        if (xxx.value == null) {
                            xxx.value = new HashMap<Short, Float>();
                        }
                        xxx.value.put(key_var328.value, value_var329.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var330 = new IntHolder();
                    DataTypeHolder key_var331 = new DataTypeHolder();

                    DataTypeHolder vlaue_var332 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var331, vlaue_var332, size_var330);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar333 = 0; ivar333 < size_var330.value; ++ivar333) {
                        ShortHolder key_var334 = new ShortHolder();
                        FloatHolder value_var335 = new FloatHolder();
                        ret = protocol.readShort(request + nread, request_len - nread, key_var334);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        ret = protocol.readFloat(request + nread, request_len - nread, value_var335);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (xxx.value == null) {
                            xxx.value = new HashMap<Short, Float>();
                        }
                        xxx.value.put(key_var334.value, value_var335.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class out_int_vec_set_result {

        public Holder<Set<List<Integer>>> xxx;
        public out_int_vec_set_result() {
            this.xxx = new Holder<Set<List<Integer>>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("out_int_vec_set_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("xxx", DataType.IDSET, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDLIST, this.xxx.value.size());
            if (ret < 0) { return ret; }
            for (List<Integer> itr_var336 : this.xxx.value) {
                ret = protocol.writeListBegin(DataType.IDINT32, itr_var336.size());
                if (ret < 0) { return ret; }
                for (int itr_var337 : itr_var336) {
                    ret = protocol.writeInt(itr_var337);
                    if (ret < 0) { return ret; }
                }
                ret = protocol.writeListEnd();
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                    IntHolder size_var338 = new IntHolder();
                    DataTypeHolder etype_var339 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var339, size_var338);
                    if (ret < 0) { return ret; }
                    for (int ivar340 = 0; ivar340 < size_var338.value; ++ivar340) {
                        Holder<List<Integer>> value_var341 = new Holder<List<Integer>>();
                        IntHolder size_var342 = new IntHolder();
                        DataTypeHolder etype_var343 = new DataTypeHolder();

                         ret = protocol.readListBegin(etype_var343, size_var342);
                        if (ret < 0) { return ret; }
                        for (int ivar344 = 0; ivar344 < size_var342.value; ++ivar344) {
                            IntHolder value_var345 = new IntHolder();
                            ret = protocol.readInt(value_var345);
                            if (ret < 0) { return ret; }
                            if (value_var341.value == null) {
                                value_var341.value = new ArrayList<Integer>();
                            }
                            value_var341.value.add(value_var345.value);
                        }
                        ret = protocol.readListEnd();
                        if (ret < 0) { return ret; }
                        if (xxx.value == null) {
                            xxx.value = new HashSet<List<Integer>>();
                        }
                        xxx.value.add(value_var341.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var346 = new IntHolder();
                    DataTypeHolder etype_var347 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var347, size_var346);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar348 = 0; ivar348 < size_var346.value; ++ivar348) {
                        Holder<List<Integer>> value_var349 = new Holder<List<Integer>>();
                        IntHolder size_var350 = new IntHolder();
                        DataTypeHolder etype_var351 = new DataTypeHolder();

                        ret = protocol.readListBegin(request + nread, request_len - nread, etype_var351, size_var350);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        for (int ivar352 = 0; ivar352 < size_var350.value; ++ivar352) {
                            IntHolder value_var353 = new IntHolder();
                            ret = protocol.readInt(request + nread, request_len - nread, value_var353);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            if (value_var349.value == null) {
                                value_var349.value = new ArrayList<Integer>();
                            }
                            value_var349.value.add(value_var353.value);
                        }
                        ret = protocol.readListEnd();
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (xxx.value == null) {
                            xxx.value = new HashSet<List<Integer>>();
                        }
                        xxx.value.add(value_var349.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_boolean_result {

        public BooleanHolder value;
        public all_boolean_result() {
            this.value = new BooleanHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_boolean_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBOOL, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBool(this.value.value);
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
                    ret = protocol.readBool(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBool(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_int8_result {

        public ByteHolder value;
        public all_int8_result() {
            this.value = new ByteHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int8_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBYTE, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeByte(this.value.value);
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
                    ret = protocol.readByte(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readByte(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_int16_result {

        public ShortHolder value;
        public all_int16_result() {
            this.value = new ShortHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int16_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT16, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeShort(this.value.value);
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
                    ret = protocol.readShort(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readShort(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_int32_result {

        public IntHolder value;
        public all_int32_result() {
            this.value = new IntHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.value.value);
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
                    ret = protocol.readInt(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readInt(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_int64_result {

        public LongHolder value;
        public all_int64_result() {
            this.value = new LongHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int64_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDINT64, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeLong(this.value.value);
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
                    ret = protocol.readLong(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readLong(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_float_result {

        public FloatHolder value;
        public all_float_result() {
            this.value = new FloatHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_float_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDFLOAT, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeFloat(this.value.value);
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
                    ret = protocol.readFloat(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readFloat(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_string_result {

        public StringHolder value;
        public all_string_result() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_string_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSTR, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeString(this.value.value);
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
                    ret = protocol.readString(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readString(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_binary_result {

        public StringHolder value;
        public all_binary_result() {
            this.value = new StringHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_binary_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDBIN, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeBinary(this.value.value);
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
                    ret = protocol.readBinary(this.value);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    ret = protocol.readBinary(request + nread, request_len - nread, this.value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_int32_seq_result {

        public Holder<List<Integer>> value;
        public all_int32_seq_result() {
            this.value = new Holder<List<Integer>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_seq_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDINT32, this.value.value.size());
            if (ret < 0) { return ret; }
            for (int itr_var354 : this.value.value) {
                ret = protocol.writeInt(itr_var354);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var355 = new IntHolder();
                    DataTypeHolder etype_var356 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var356, size_var355);
                    if (ret < 0) { return ret; }
                    for (int ivar357 = 0; ivar357 < size_var355.value; ++ivar357) {
                        IntHolder value_var358 = new IntHolder();
                        ret = protocol.readInt(value_var358);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new ArrayList<Integer>();
                        }
                        value.value.add(value_var358.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var359 = new IntHolder();
                    DataTypeHolder etype_var360 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var360, size_var359);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar361 = 0; ivar361 < size_var359.value; ++ivar361) {
                        IntHolder value_var362 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, value_var362);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new ArrayList<Integer>();
                        }
                        value.value.add(value_var362.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_person_result {

        public math.PersonHolder value;
        public all_person_result() {
            this.value = new math.PersonHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_person_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSTRUCT, 1);
            if (ret < 0) { return ret; }
            ret = value.value.write(protocol);
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
                    value.value = new math.Person();
                    ret = value.value.read(protocol);
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    value.value = new math.Person();
                    ret = value.value.read(protocol, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_int32_set_result {

        public Holder<Set<Integer>> value;
        public all_int32_set_result() {
            this.value = new Holder<Set<Integer>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_set_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDSET, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeSetBegin(DataType.IDINT32, this.value.value.size());
            if (ret < 0) { return ret; }
            for (int itr_var363 : this.value.value) {
                ret = protocol.writeInt(itr_var363);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeSetEnd();
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
                    IntHolder size_var364 = new IntHolder();
                    DataTypeHolder etype_var365 = new DataTypeHolder();

                     ret = protocol.readSetBegin(etype_var365, size_var364);
                    if (ret < 0) { return ret; }
                    for (int ivar366 = 0; ivar366 < size_var364.value; ++ivar366) {
                        IntHolder value_var367 = new IntHolder();
                        ret = protocol.readInt(value_var367);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new HashSet<Integer>();
                        }
                        value.value.add(value_var367.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var368 = new IntHolder();
                    DataTypeHolder etype_var369 = new DataTypeHolder();

                    ret = protocol.readSetBegin(request + nread, request_len - nread, etype_var369, size_var368);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar370 = 0; ivar370 < size_var368.value; ++ivar370) {
                        IntHolder value_var371 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, value_var371);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new HashSet<Integer>();
                        }
                        value.value.add(value_var371.value);
                    }
                    ret = protocol.readSetEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_person_seq_result {

        public Holder<List<math.Person>> value;
        public all_person_seq_result() {
            this.value = new Holder<List<math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_person_seq_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDLIST, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDSTRUCT, this.value.value.size());
            if (ret < 0) { return ret; }
            for (math.Person itr_var372 : this.value.value) {
                ret = itr_var372.write(protocol);
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
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
                    IntHolder size_var373 = new IntHolder();
                    DataTypeHolder etype_var374 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var374, size_var373);
                    if (ret < 0) { return ret; }
                    for (int ivar375 = 0; ivar375 < size_var373.value; ++ivar375) {
                        math.PersonHolder value_var376 = new math.PersonHolder();
                        value_var376.value = new math.Person();
                        ret = value_var376.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new ArrayList<math.Person>();
                        }
                        value.value.add(value_var376.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var377 = new IntHolder();
                    DataTypeHolder etype_var378 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var378, size_var377);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar379 = 0; ivar379 < size_var377.value; ++ivar379) {
                        math.PersonHolder value_var380 = new math.PersonHolder();
                        value_var380.value = new math.Person();
                        ret = value_var380.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new ArrayList<math.Person>();
                        }
                        value.value.add(value_var380.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class all_int32_person_map_result {

        public Holder<Map<Integer, math.Person>> value;
        public all_int32_person_map_result() {
            this.value = new Holder<Map<Integer, math.Person>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("all_int32_person_map_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("value", DataType.IDMAP, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDINT32, DataType.IDSTRUCT, this.value.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<Integer, math.Person> citr_var381 : this.value.value.entrySet()) {
                ret = protocol.writeInt(citr_var381.getKey());
                if (ret < 0) { return ret; }
                ret = citr_var381.getValue().write(protocol);
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
                    IntHolder size_var382 = new IntHolder();
                    DataTypeHolder key_var383 = new DataTypeHolder();

                    DataTypeHolder vlaue_var384 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var383, vlaue_var384, size_var382);
                    if (ret < 0) { return ret; }
                    for (int ivar385 = 0; ivar385 < size_var382.value; ++ivar385) {
                        IntHolder key_var386 = new IntHolder();
                        math.PersonHolder value_var387 = new math.PersonHolder();
                        ret = protocol.readInt(key_var386);
                        if (ret < 0) { return ret; }
                        value_var387.value = new math.Person();
                        ret = value_var387.value.read(protocol);
                        if (ret < 0) { return ret; }
                        if (value.value == null) {
                            value.value = new HashMap<Integer, math.Person>();
                        }
                        value.value.put(key_var386.value, value_var387.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder size_var388 = new IntHolder();
                    DataTypeHolder key_var389 = new DataTypeHolder();

                    DataTypeHolder vlaue_var390 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var389, vlaue_var390, size_var388);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar391 = 0; ivar391 < size_var388.value; ++ivar391) {
                        IntHolder key_var392 = new IntHolder();
                        math.PersonHolder value_var393 = new math.PersonHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, key_var392);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var393.value = new math.Person();
                        ret = value_var393.value.read(protocol, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        if (value.value == null) {
                            value.value = new HashMap<Integer, math.Person>();
                        }
                        value.value.put(key_var392.value, value_var393.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class color_out_all_result {

        public math.ColorHolder color1;
        public math.ColorHolder color2;
        public color_out_all_result() {
            this.color1 = new math.ColorHolder();
            this.color2 = new math.ColorHolder();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("color_out_all_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color1", DataType.IDINT32, 1);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.color1.value.getValue());
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color2", DataType.IDINT32, 2);
            if (ret < 0) { return ret; }
            ret = protocol.writeInt(this.color2.value.getValue());
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
                    IntHolder ele_var394 = new IntHolder();
                    ret = protocol.readInt(ele_var394);
                    if (ret < 0) { return ret; }
                    color1.value = math.Color.findByValue(ele_var394.value);
                    break;
                case 2:
                    IntHolder ele_var395 = new IntHolder();
                    ret = protocol.readInt(ele_var395);
                    if (ret < 0) { return ret; }
                    color2.value = math.Color.findByValue(ele_var395.value);
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                    IntHolder ele_var396 = new IntHolder();
                    ret = protocol.readInt(request + nread, request_len - nread, ele_var396);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color1.value = math.Color.findByValue(ele_var396.value);
                    break;
                case 2:
                    IntHolder ele_var397 = new IntHolder();
                    ret = protocol.readInt(request + nread, request_len - nread, ele_var397);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color2.value = math.Color.findByValue(ele_var397.value);
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class color_xx_result {

        public Holder<List<math.Color>> return_value;

        public Holder<List<math.Color>> color2;
        public Holder<Map<math.Color, math.Color>> color3;
        public color_xx_result() {
            return_value = new Holder<List<math.Color>>();
            this.color2 = new Holder<List<math.Color>>();
            this.color3 = new Holder<Map<math.Color, math.Color>>();
        }

        public int write(Protocol protocol) {
            int ret = 0;
            ret = protocol.writeStructBegin("color_xx_result");
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("return_value", DataType.IDLIST, 0);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDINT32, this.return_value.value.size());
            if (ret < 0) { return ret; }
            for (math.Color itr_var398 : this.return_value.value) {
                ret = protocol.writeInt(itr_var398.getValue());
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color2", DataType.IDLIST, 2);
            if (ret < 0) { return ret; }
            ret = protocol.writeListBegin(DataType.IDINT32, this.color2.value.size());
            if (ret < 0) { return ret; }
            for (math.Color itr_var399 : this.color2.value) {
                ret = protocol.writeInt(itr_var399.getValue());
                if (ret < 0) { return ret; }
            }
            ret = protocol.writeListEnd();
            if (ret < 0) { return ret; }
            ret = protocol.writeFieldEnd();
            if (ret < 0) { return ret; }

            ret = protocol.writeFieldBegin("color3", DataType.IDMAP, 3);
            if (ret < 0) { return ret; }
            ret = protocol.writeMapBegin(DataType.IDINT32, DataType.IDINT32, this.color3.value.size());
            if (ret < 0) { return ret; }
            for (Map.Entry<math.Color, math.Color> citr_var400 : this.color3.value.entrySet()) {
                ret = protocol.writeInt(citr_var400.getKey().getValue());
                if (ret < 0) { return ret; }
                ret = protocol.writeInt(citr_var400.getValue().getValue());
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
                case 0:
                    IntHolder size_var401 = new IntHolder();
                    DataTypeHolder etype_var402 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var402, size_var401);
                    if (ret < 0) { return ret; }
                    for (int ivar403 = 0; ivar403 < size_var401.value; ++ivar403) {
                        math.ColorHolder value_var404 = new math.ColorHolder();
                        IntHolder ele_var405 = new IntHolder();
                        ret = protocol.readInt(ele_var405);
                        if (ret < 0) { return ret; }
                        value_var404.value = math.Color.findByValue(ele_var405.value);
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<math.Color>();
                        }
                        return_value.value.add(value_var404.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                break;
                case 2:
                    IntHolder size_var406 = new IntHolder();
                    DataTypeHolder etype_var407 = new DataTypeHolder();

                     ret = protocol.readListBegin(etype_var407, size_var406);
                    if (ret < 0) { return ret; }
                    for (int ivar408 = 0; ivar408 < size_var406.value; ++ivar408) {
                        math.ColorHolder value_var409 = new math.ColorHolder();
                        IntHolder ele_var410 = new IntHolder();
                        ret = protocol.readInt(ele_var410);
                        if (ret < 0) { return ret; }
                        value_var409.value = math.Color.findByValue(ele_var410.value);
                        if (color2.value == null) {
                            color2.value = new ArrayList<math.Color>();
                        }
                        color2.value.add(value_var409.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    break;
                case 3:
                    IntHolder size_var411 = new IntHolder();
                    DataTypeHolder key_var412 = new DataTypeHolder();

                    DataTypeHolder vlaue_var413 = new DataTypeHolder();

                     ret = protocol.readMapBegin(key_var412, vlaue_var413, size_var411);
                    if (ret < 0) { return ret; }
                    for (int ivar414 = 0; ivar414 < size_var411.value; ++ivar414) {
                        math.ColorHolder key_var415 = new math.ColorHolder();
                        math.ColorHolder value_var416 = new math.ColorHolder();
                        IntHolder ele_var417 = new IntHolder();
                        ret = protocol.readInt(ele_var417);
                        if (ret < 0) { return ret; }
                        key_var415.value = math.Color.findByValue(ele_var417.value);
                        IntHolder ele_var418 = new IntHolder();
                        ret = protocol.readInt(ele_var418);
                        if (ret < 0) { return ret; }
                        value_var416.value = math.Color.findByValue(ele_var418.value);
                        if (color3.value == null) {
                            color3.value = new HashMap<math.Color, math.Color>();
                        }
                        color3.value.put(key_var415.value, value_var416.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
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
                case 0:
                    IntHolder size_var419 = new IntHolder();
                    DataTypeHolder etype_var420 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var420, size_var419);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar421 = 0; ivar421 < size_var419.value; ++ivar421) {
                        math.ColorHolder value_var422 = new math.ColorHolder();
                        IntHolder ele_var423 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, ele_var423);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var422.value = math.Color.findByValue(ele_var423.value);
                        if (return_value.value == null) {
                            return_value.value = new ArrayList<math.Color>();
                        }
                        return_value.value.add(value_var422.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                break;
                case 2:
                    IntHolder size_var424 = new IntHolder();
                    DataTypeHolder etype_var425 = new DataTypeHolder();

                    ret = protocol.readListBegin(request + nread, request_len - nread, etype_var425, size_var424);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar426 = 0; ivar426 < size_var424.value; ++ivar426) {
                        math.ColorHolder value_var427 = new math.ColorHolder();
                        IntHolder ele_var428 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, ele_var428);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var427.value = math.Color.findByValue(ele_var428.value);
                        if (color2.value == null) {
                            color2.value = new ArrayList<math.Color>();
                        }
                        color2.value.add(value_var427.value);
                    }
                    ret = protocol.readListEnd();
                    if (ret < 0) { return ret; }
                    nread += ret;
                    break;
                case 3:
                    IntHolder size_var429 = new IntHolder();
                    DataTypeHolder key_var430 = new DataTypeHolder();

                    DataTypeHolder vlaue_var431 = new DataTypeHolder();

                     ret = protocol.readMapBegin(request + nread, request_len - nread, key_var430, vlaue_var431, size_var429);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    for (int ivar432 = 0; ivar432 < size_var429.value; ++ivar432) {
                        math.ColorHolder key_var433 = new math.ColorHolder();
                        math.ColorHolder value_var434 = new math.ColorHolder();
                        IntHolder ele_var435 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, ele_var435);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        key_var433.value = math.Color.findByValue(ele_var435.value);
                        IntHolder ele_var436 = new IntHolder();
                        ret = protocol.readInt(request + nread, request_len - nread, ele_var436);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var434.value = math.Color.findByValue(ele_var436.value);
                        if (color3.value == null) {
                            color3.value = new HashMap<math.Color, math.Color>();
                        }
                        color3.value.put(key_var433.value, value_var434.value);
                    ret = protocol.readMapEnd();
                    if (ret < 0) { return ret; }
                    }
                    break;
                }
                ret = protocol.readFieldEnd();
                if (ret < 0) { return ret; }
            }

            return protocol.readStructEnd();
        }

    }

    public static class Proxy extends BaseProxy {
        public Proxy(ServerInfo serverInfo) {
            super(serverInfo);
            setWhoAmI("global.math.Math");
        }

        public void ping() {
            this.ping(false);
        }

        public void ping(boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("ping", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_ping(seqHolder.value, protocol);
            recv_ping(protocol);
            putProtocol(protocol);
        }

        void send_ping(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "ping", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            ping_args args = new ping_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_ping(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            ping_result _result = new ping_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public math.AddResult add(int a, int b, IntHolder sum) {
            return this.add(a, b, sum, false);
        }

        public math.AddResult add(int a, int b, IntHolder sum, boolean last) {
            math.AddResult return_value = AddResult.findByValue(0);
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("add", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_add(a, b, seqHolder.value, protocol);
            return_value = recv_add(sum, protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_add(int a, int b, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "add", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            add_args args = new add_args();
            args.a.value = a;
            args.b.value = b;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        math.AddResult recv_add(IntHolder sum, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            add_result _result = new add_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            sum.value = _result.sum.value;
            return _result.return_value.value;
        }

        public math.Citizen test_citizen(math.Citizen ins, math.CitizenHolder outs, math.CitizenHolder alls) {
            return this.test_citizen(ins, outs, alls, false);
        }

        public math.Citizen test_citizen(math.Citizen ins, math.CitizenHolder outs, math.CitizenHolder alls, boolean last) {
            math.Citizen return_value = new Citizen();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("test_citizen", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_test_citizen(ins, alls.value, seqHolder.value, protocol);
            return_value = recv_test_citizen(outs, alls, protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_test_citizen(math.Citizen ins, math.Citizen alls, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "test_citizen", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            test_citizen_args args = new test_citizen_args();
            args.ins.value = ins;
            args.alls.value = alls;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        math.Citizen recv_test_citizen(math.CitizenHolder outs, math.CitizenHolder alls, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            test_citizen_result _result = new test_citizen_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            outs.value = _result.outs.value;
            alls.value = _result.alls.value;
            return _result.return_value.value;
        }

        public boolean get_boolean() {
            return this.get_boolean(false);
        }

        public boolean get_boolean(boolean last) {
            boolean return_value = true;
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_boolean", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_boolean(seqHolder.value, protocol);
            return_value = recv_get_boolean(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_boolean(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_boolean", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_boolean_args args = new get_boolean_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        boolean recv_get_boolean(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_boolean_result _result = new get_boolean_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public byte get_int8() {
            return this.get_int8(false);
        }

        public byte get_int8(boolean last) {
            byte return_value = 0;
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_int8", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_int8(seqHolder.value, protocol);
            return_value = recv_get_int8(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_int8(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_int8", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_int8_args args = new get_int8_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        byte recv_get_int8(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_int8_result _result = new get_int8_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public short get_int16() {
            return this.get_int16(false);
        }

        public short get_int16(boolean last) {
            short return_value = 0;
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_int16", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_int16(seqHolder.value, protocol);
            return_value = recv_get_int16(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_int16(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_int16", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_int16_args args = new get_int16_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        short recv_get_int16(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_int16_result _result = new get_int16_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public int get_int32() {
            return this.get_int32(false);
        }

        public int get_int32(boolean last) {
            int return_value = 0;
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_int32", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_int32(seqHolder.value, protocol);
            return_value = recv_get_int32(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_int32(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_int32", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_int32_args args = new get_int32_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        int recv_get_int32(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_int32_result _result = new get_int32_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public long get_int64() {
            return this.get_int64(false);
        }

        public long get_int64(boolean last) {
            long return_value = 0;
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_int64", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_int64(seqHolder.value, protocol);
            return_value = recv_get_int64(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_int64(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_int64", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_int64_args args = new get_int64_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        long recv_get_int64(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_int64_result _result = new get_int64_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public float get_float() {
            return this.get_float(false);
        }

        public float get_float(boolean last) {
            float return_value = 0.0f;
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_float", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_float(seqHolder.value, protocol);
            return_value = recv_get_float(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_float(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_float", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_float_args args = new get_float_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        float recv_get_float(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_float_result _result = new get_float_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public String get_string() {
            return this.get_string(false);
        }

        public String get_string(boolean last) {
            String return_value = new String();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_string", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_string(seqHolder.value, protocol);
            return_value = recv_get_string(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_string(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_string", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_string_args args = new get_string_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        String recv_get_string(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_string_result _result = new get_string_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public String get_binary() {
            return this.get_binary(false);
        }

        public String get_binary(boolean last) {
            String return_value = new String();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_binary", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_binary(seqHolder.value, protocol);
            return_value = recv_get_binary(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_binary(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_binary", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_binary_args args = new get_binary_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        String recv_get_binary(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_binary_result _result = new get_binary_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public math.Color get_color() {
            return this.get_color(false);
        }

        public math.Color get_color(boolean last) {
            math.Color return_value = Color.findByValue(0);
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_color", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_color(seqHolder.value, protocol);
            return_value = recv_get_color(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_color(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_color", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_color_args args = new get_color_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        math.Color recv_get_color(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_color_result _result = new get_color_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public List<Integer> get_sequence() {
            return this.get_sequence(false);
        }

        public List<Integer> get_sequence(boolean last) {
            List<Integer> return_value = new ArrayList<Integer>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_sequence", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_sequence(seqHolder.value, protocol);
            return_value = recv_get_sequence(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_sequence(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_sequence", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_sequence_args args = new get_sequence_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        List<Integer> recv_get_sequence(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_sequence_result _result = new get_sequence_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public Set<String> get_string_set() {
            return this.get_string_set(false);
        }

        public Set<String> get_string_set(boolean last) {
            Set<String> return_value = new HashSet<String>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_string_set", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_string_set(seqHolder.value, protocol);
            return_value = recv_get_string_set(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_string_set(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_string_set", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_string_set_args args = new get_string_set_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        Set<String> recv_get_string_set(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_string_set_result _result = new get_string_set_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public Map<Long, String> get_int_str_map() {
            return this.get_int_str_map(false);
        }

        public Map<Long, String> get_int_str_map(boolean last) {
            Map<Long, String> return_value = new HashMap<Long, String>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_int_str_map", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_int_str_map(seqHolder.value, protocol);
            return_value = recv_get_int_str_map(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_int_str_map(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_int_str_map", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_int_str_map_args args = new get_int_str_map_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        Map<Long, String> recv_get_int_str_map(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_int_str_map_result _result = new get_int_str_map_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public List<Set<Boolean>> get_bool_set_sequence() {
            return this.get_bool_set_sequence(false);
        }

        public List<Set<Boolean>> get_bool_set_sequence(boolean last) {
            List<Set<Boolean>> return_value = new ArrayList<Set<Boolean>>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_bool_set_sequence", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_bool_set_sequence(seqHolder.value, protocol);
            return_value = recv_get_bool_set_sequence(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_bool_set_sequence(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_bool_set_sequence", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_bool_set_sequence_args args = new get_bool_set_sequence_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        List<Set<Boolean>> recv_get_bool_set_sequence(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_bool_set_sequence_result _result = new get_bool_set_sequence_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public math.Person get_person() {
            return this.get_person(false);
        }

        public math.Person get_person(boolean last) {
            math.Person return_value = new Person();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_person", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_person(seqHolder.value, protocol);
            return_value = recv_get_person(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_person(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_person", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_person_args args = new get_person_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        math.Person recv_get_person(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_person_result _result = new get_person_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public List<math.Person> get_persons() {
            return this.get_persons(false);
        }

        public List<math.Person> get_persons(boolean last) {
            List<math.Person> return_value = new ArrayList<math.Person>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_persons", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_persons(seqHolder.value, protocol);
            return_value = recv_get_persons(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_persons(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_persons", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_persons_args args = new get_persons_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        List<math.Person> recv_get_persons(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_persons_result _result = new get_persons_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public Set<math.Person> get_persons2() {
            return this.get_persons2(false);
        }

        public Set<math.Person> get_persons2(boolean last) {
            Set<math.Person> return_value = new HashSet<math.Person>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_persons2", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_persons2(seqHolder.value, protocol);
            return_value = recv_get_persons2(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_persons2(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_persons2", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_persons2_args args = new get_persons2_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        Set<math.Person> recv_get_persons2(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_persons2_result _result = new get_persons2_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public Map<math.Person, math.Person> get_persons3() {
            return this.get_persons3(false);
        }

        public Map<math.Person, math.Person> get_persons3(boolean last) {
            Map<math.Person, math.Person> return_value = new HashMap<math.Person, math.Person>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_persons3", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_persons3(seqHolder.value, protocol);
            return_value = recv_get_persons3(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_persons3(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_persons3", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_persons3_args args = new get_persons3_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        Map<math.Person, math.Person> recv_get_persons3(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_persons3_result _result = new get_persons3_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public List<Set<math.Person>> get_persons4() {
            return this.get_persons4(false);
        }

        public List<Set<math.Person>> get_persons4(boolean last) {
            List<Set<math.Person>> return_value = new ArrayList<Set<math.Person>>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("get_persons4", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_get_persons4(seqHolder.value, protocol);
            return_value = recv_get_persons4(protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_get_persons4(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "get_persons4", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            get_persons4_args args = new get_persons4_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        List<Set<math.Person>> recv_get_persons4(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            get_persons4_result _result = new get_persons4_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            return _result.return_value.value;
        }

        public void send_bool(boolean value) {
            this.send_bool(value, false);
        }

        public void send_bool(boolean value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_bool", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_bool(value, seqHolder.value, protocol);
            recv_send_bool(protocol);
            putProtocol(protocol);
        }

        void send_send_bool(boolean value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_bool", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_bool_args args = new send_bool_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_bool(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_bool_result _result = new send_bool_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_int8(byte value) {
            this.send_int8(value, false);
        }

        public void send_int8(byte value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_int8", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_int8(value, seqHolder.value, protocol);
            recv_send_int8(protocol);
            putProtocol(protocol);
        }

        void send_send_int8(byte value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_int8", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_int8_args args = new send_int8_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_int8(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_int8_result _result = new send_int8_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_int16(short value) {
            this.send_int16(value, false);
        }

        public void send_int16(short value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_int16", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_int16(value, seqHolder.value, protocol);
            recv_send_int16(protocol);
            putProtocol(protocol);
        }

        void send_send_int16(short value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_int16", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_int16_args args = new send_int16_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_int16(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_int16_result _result = new send_int16_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_int32(int value) {
            this.send_int32(value, false);
        }

        public void send_int32(int value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_int32", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_int32(value, seqHolder.value, protocol);
            recv_send_int32(protocol);
            putProtocol(protocol);
        }

        void send_send_int32(int value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_int32", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_int32_args args = new send_int32_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_int32(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_int32_result _result = new send_int32_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_int64(long value) {
            this.send_int64(value, false);
        }

        public void send_int64(long value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_int64", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_int64(value, seqHolder.value, protocol);
            recv_send_int64(protocol);
            putProtocol(protocol);
        }

        void send_send_int64(long value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_int64", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_int64_args args = new send_int64_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_int64(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_int64_result _result = new send_int64_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_float(float value) {
            this.send_float(value, false);
        }

        public void send_float(float value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_float", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_float(value, seqHolder.value, protocol);
            recv_send_float(protocol);
            putProtocol(protocol);
        }

        void send_send_float(float value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_float", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_float_args args = new send_float_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_float(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_float_result _result = new send_float_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_string(String value) {
            this.send_string(value, false);
        }

        public void send_string(String value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_string", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_string(value, seqHolder.value, protocol);
            recv_send_string(protocol);
            putProtocol(protocol);
        }

        void send_send_string(String value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_string", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_string_args args = new send_string_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_string(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_string_result _result = new send_string_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_binary(String value) {
            this.send_binary(value, false);
        }

        public void send_binary(String value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_binary", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_binary(value, seqHolder.value, protocol);
            recv_send_binary(protocol);
            putProtocol(protocol);
        }

        void send_send_binary(String value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_binary", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_binary_args args = new send_binary_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_binary(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_binary_result _result = new send_binary_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_color(math.Color color) {
            this.send_color(color, false);
        }

        public void send_color(math.Color color, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_color", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_color(color, seqHolder.value, protocol);
            recv_send_color(protocol);
            putProtocol(protocol);
        }

        void send_send_color(math.Color color, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_color", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_color_args args = new send_color_args();
            args.color.value = color;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_color(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_color_result _result = new send_color_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_person(math.Person person) {
            this.send_person(person, false);
        }

        public void send_person(math.Person person, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_person", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_person(person, seqHolder.value, protocol);
            recv_send_person(protocol);
            putProtocol(protocol);
        }

        void send_send_person(math.Person person, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_person", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_person_args args = new send_person_args();
            args.person.value = person;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_person(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_person_result _result = new send_person_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_int32_sequence(List<Integer> numbers) {
            this.send_int32_sequence(numbers, false);
        }

        public void send_int32_sequence(List<Integer> numbers, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_int32_sequence", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_int32_sequence(numbers, seqHolder.value, protocol);
            recv_send_int32_sequence(protocol);
            putProtocol(protocol);
        }

        void send_send_int32_sequence(List<Integer> numbers, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_int32_sequence", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_int32_sequence_args args = new send_int32_sequence_args();
            args.numbers.value = numbers;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_int32_sequence(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_int32_sequence_result _result = new send_int32_sequence_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_persons(List<math.Person> persons) {
            this.send_persons(persons, false);
        }

        public void send_persons(List<math.Person> persons, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_persons", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_persons(persons, seqHolder.value, protocol);
            recv_send_persons(protocol);
            putProtocol(protocol);
        }

        void send_send_persons(List<math.Person> persons, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_persons", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_persons_args args = new send_persons_args();
            args.persons.value = persons;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_persons(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_persons_result _result = new send_persons_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_persons2(Set<math.Person> persons) {
            this.send_persons2(persons, false);
        }

        public void send_persons2(Set<math.Person> persons, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_persons2", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_persons2(persons, seqHolder.value, protocol);
            recv_send_persons2(protocol);
            putProtocol(protocol);
        }

        void send_send_persons2(Set<math.Person> persons, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_persons2", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_persons2_args args = new send_persons2_args();
            args.persons.value = persons;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_persons2(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_persons2_result _result = new send_persons2_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_int32_set_seq(List<Set<Integer>> xx) {
            this.send_int32_set_seq(xx, false);
        }

        public void send_int32_set_seq(List<Set<Integer>> xx, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_int32_set_seq", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_int32_set_seq(xx, seqHolder.value, protocol);
            recv_send_int32_set_seq(protocol);
            putProtocol(protocol);
        }

        void send_send_int32_set_seq(List<Set<Integer>> xx, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_int32_set_seq", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_int32_set_seq_args args = new send_int32_set_seq_args();
            args.xx.value = xx;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_int32_set_seq(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_int32_set_seq_result _result = new send_int32_set_seq_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_persons3(Map<math.Person, math.Person> persons) {
            this.send_persons3(persons, false);
        }

        public void send_persons3(Map<math.Person, math.Person> persons, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_persons3", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_persons3(persons, seqHolder.value, protocol);
            recv_send_persons3(protocol);
            putProtocol(protocol);
        }

        void send_send_persons3(Map<math.Person, math.Person> persons, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_persons3", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_persons3_args args = new send_persons3_args();
            args.persons.value = persons;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_persons3(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_persons3_result _result = new send_persons3_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void send_person_vec_set(Set<List<math.Person>> xxx) {
            this.send_person_vec_set(xxx, false);
        }

        public void send_person_vec_set(Set<List<math.Person>> xxx, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("send_person_vec_set", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_send_person_vec_set(xxx, seqHolder.value, protocol);
            recv_send_person_vec_set(protocol);
            putProtocol(protocol);
        }

        void send_send_person_vec_set(Set<List<math.Person>> xxx, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "send_person_vec_set", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            send_person_vec_set_args args = new send_person_vec_set_args();
            args.xxx.value = xxx;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_send_person_vec_set(Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            send_person_vec_set_result _result = new send_person_vec_set_result();
            _result.read(protocol);
            protocol.readMessageEnd();
        }

        public void out_boolean(BooleanHolder value) {
            this.out_boolean(value, false);
        }

        public void out_boolean(BooleanHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_boolean", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_boolean(seqHolder.value, protocol);
            recv_out_boolean(value, protocol);
            putProtocol(protocol);
        }

        void send_out_boolean(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_boolean", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_boolean_args args = new out_boolean_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_boolean(BooleanHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_boolean_result _result = new out_boolean_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_int8(ByteHolder value) {
            this.out_int8(value, false);
        }

        public void out_int8(ByteHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_int8", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_int8(seqHolder.value, protocol);
            recv_out_int8(value, protocol);
            putProtocol(protocol);
        }

        void send_out_int8(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_int8", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_int8_args args = new out_int8_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_int8(ByteHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_int8_result _result = new out_int8_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_int16(ShortHolder value) {
            this.out_int16(value, false);
        }

        public void out_int16(ShortHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_int16", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_int16(seqHolder.value, protocol);
            recv_out_int16(value, protocol);
            putProtocol(protocol);
        }

        void send_out_int16(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_int16", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_int16_args args = new out_int16_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_int16(ShortHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_int16_result _result = new out_int16_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_int32(IntHolder value) {
            this.out_int32(value, false);
        }

        public void out_int32(IntHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_int32", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_int32(seqHolder.value, protocol);
            recv_out_int32(value, protocol);
            putProtocol(protocol);
        }

        void send_out_int32(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_int32", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_int32_args args = new out_int32_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_int32(IntHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_int32_result _result = new out_int32_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_int64(LongHolder value) {
            this.out_int64(value, false);
        }

        public void out_int64(LongHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_int64", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_int64(seqHolder.value, protocol);
            recv_out_int64(value, protocol);
            putProtocol(protocol);
        }

        void send_out_int64(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_int64", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_int64_args args = new out_int64_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_int64(LongHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_int64_result _result = new out_int64_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_float(FloatHolder value) {
            this.out_float(value, false);
        }

        public void out_float(FloatHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_float", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_float(seqHolder.value, protocol);
            recv_out_float(value, protocol);
            putProtocol(protocol);
        }

        void send_out_float(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_float", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_float_args args = new out_float_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_float(FloatHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_float_result _result = new out_float_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_string(StringHolder value) {
            this.out_string(value, false);
        }

        public void out_string(StringHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_string", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_string(seqHolder.value, protocol);
            recv_out_string(value, protocol);
            putProtocol(protocol);
        }

        void send_out_string(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_string", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_string_args args = new out_string_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_string(StringHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_string_result _result = new out_string_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_binary(StringHolder value) {
            this.out_binary(value, false);
        }

        public void out_binary(StringHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_binary", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_binary(seqHolder.value, protocol);
            recv_out_binary(value, protocol);
            putProtocol(protocol);
        }

        void send_out_binary(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_binary", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_binary_args args = new out_binary_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_binary(StringHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_binary_result _result = new out_binary_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void out_person(math.PersonHolder person) {
            this.out_person(person, false);
        }

        public void out_person(math.PersonHolder person, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_person", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_person(seqHolder.value, protocol);
            recv_out_person(person, protocol);
            putProtocol(protocol);
        }

        void send_out_person(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_person", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_person_args args = new out_person_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_person(math.PersonHolder person, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_person_result _result = new out_person_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            person.value = _result.person.value;
        }

        public void out_seq(Holder<List<Integer>> xxx) {
            this.out_seq(xxx, false);
        }

        public void out_seq(Holder<List<Integer>> xxx, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_seq", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_seq(seqHolder.value, protocol);
            recv_out_seq(xxx, protocol);
            putProtocol(protocol);
        }

        void send_out_seq(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_seq", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_seq_args args = new out_seq_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_seq(Holder<List<Integer>> xxx, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_seq_result _result = new out_seq_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            xxx.value = _result.xxx.value;
        }

        public void out_string_set(Holder<Set<String>> xxx) {
            this.out_string_set(xxx, false);
        }

        public void out_string_set(Holder<Set<String>> xxx, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_string_set", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_string_set(seqHolder.value, protocol);
            recv_out_string_set(xxx, protocol);
            putProtocol(protocol);
        }

        void send_out_string_set(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_string_set", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_string_set_args args = new out_string_set_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_string_set(Holder<Set<String>> xxx, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_string_set_result _result = new out_string_set_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            xxx.value = _result.xxx.value;
        }

        public void out_int16_float_map(Holder<Map<Short, Float>> xxx) {
            this.out_int16_float_map(xxx, false);
        }

        public void out_int16_float_map(Holder<Map<Short, Float>> xxx, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_int16_float_map", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_int16_float_map(seqHolder.value, protocol);
            recv_out_int16_float_map(xxx, protocol);
            putProtocol(protocol);
        }

        void send_out_int16_float_map(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_int16_float_map", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_int16_float_map_args args = new out_int16_float_map_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_int16_float_map(Holder<Map<Short, Float>> xxx, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_int16_float_map_result _result = new out_int16_float_map_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            xxx.value = _result.xxx.value;
        }

        public void out_int_vec_set(Holder<Set<List<Integer>>> xxx) {
            this.out_int_vec_set(xxx, false);
        }

        public void out_int_vec_set(Holder<Set<List<Integer>>> xxx, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("out_int_vec_set", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_out_int_vec_set(seqHolder.value, protocol);
            recv_out_int_vec_set(xxx, protocol);
            putProtocol(protocol);
        }

        void send_out_int_vec_set(int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "out_int_vec_set", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            out_int_vec_set_args args = new out_int_vec_set_args();
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_out_int_vec_set(Holder<Set<List<Integer>>> xxx, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            out_int_vec_set_result _result = new out_int_vec_set_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            xxx.value = _result.xxx.value;
        }

        public void all_boolean(BooleanHolder value) {
            this.all_boolean(value, false);
        }

        public void all_boolean(BooleanHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_boolean", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_boolean(value.value, seqHolder.value, protocol);
            recv_all_boolean(value, protocol);
            putProtocol(protocol);
        }

        void send_all_boolean(boolean value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_boolean", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_boolean_args args = new all_boolean_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_boolean(BooleanHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_boolean_result _result = new all_boolean_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_int8(ByteHolder value) {
            this.all_int8(value, false);
        }

        public void all_int8(ByteHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_int8", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_int8(value.value, seqHolder.value, protocol);
            recv_all_int8(value, protocol);
            putProtocol(protocol);
        }

        void send_all_int8(byte value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_int8", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_int8_args args = new all_int8_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_int8(ByteHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_int8_result _result = new all_int8_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_int16(ShortHolder value) {
            this.all_int16(value, false);
        }

        public void all_int16(ShortHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_int16", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_int16(value.value, seqHolder.value, protocol);
            recv_all_int16(value, protocol);
            putProtocol(protocol);
        }

        void send_all_int16(short value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_int16", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_int16_args args = new all_int16_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_int16(ShortHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_int16_result _result = new all_int16_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_int32(IntHolder value) {
            this.all_int32(value, false);
        }

        public void all_int32(IntHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_int32", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_int32(value.value, seqHolder.value, protocol);
            recv_all_int32(value, protocol);
            putProtocol(protocol);
        }

        void send_all_int32(int value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_int32", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_int32_args args = new all_int32_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_int32(IntHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_int32_result _result = new all_int32_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_int64(LongHolder value) {
            this.all_int64(value, false);
        }

        public void all_int64(LongHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_int64", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_int64(value.value, seqHolder.value, protocol);
            recv_all_int64(value, protocol);
            putProtocol(protocol);
        }

        void send_all_int64(long value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_int64", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_int64_args args = new all_int64_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_int64(LongHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_int64_result _result = new all_int64_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_float(FloatHolder value) {
            this.all_float(value, false);
        }

        public void all_float(FloatHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_float", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_float(value.value, seqHolder.value, protocol);
            recv_all_float(value, protocol);
            putProtocol(protocol);
        }

        void send_all_float(float value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_float", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_float_args args = new all_float_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_float(FloatHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_float_result _result = new all_float_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_string(StringHolder value) {
            this.all_string(value, false);
        }

        public void all_string(StringHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_string", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_string(value.value, seqHolder.value, protocol);
            recv_all_string(value, protocol);
            putProtocol(protocol);
        }

        void send_all_string(String value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_string", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_string_args args = new all_string_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_string(StringHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_string_result _result = new all_string_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_binary(StringHolder value) {
            this.all_binary(value, false);
        }

        public void all_binary(StringHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_binary", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_binary(value.value, seqHolder.value, protocol);
            recv_all_binary(value, protocol);
            putProtocol(protocol);
        }

        void send_all_binary(String value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_binary", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_binary_args args = new all_binary_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_binary(StringHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_binary_result _result = new all_binary_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_int32_seq(Holder<List<Integer>> value) {
            this.all_int32_seq(value, false);
        }

        public void all_int32_seq(Holder<List<Integer>> value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_int32_seq", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_int32_seq(value.value, seqHolder.value, protocol);
            recv_all_int32_seq(value, protocol);
            putProtocol(protocol);
        }

        void send_all_int32_seq(List<Integer> value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_int32_seq", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_int32_seq_args args = new all_int32_seq_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_int32_seq(Holder<List<Integer>> value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_int32_seq_result _result = new all_int32_seq_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_person(math.PersonHolder value) {
            this.all_person(value, false);
        }

        public void all_person(math.PersonHolder value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_person", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_person(value.value, seqHolder.value, protocol);
            recv_all_person(value, protocol);
            putProtocol(protocol);
        }

        void send_all_person(math.Person value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_person", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_person_args args = new all_person_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_person(math.PersonHolder value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_person_result _result = new all_person_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_int32_set(Holder<Set<Integer>> value) {
            this.all_int32_set(value, false);
        }

        public void all_int32_set(Holder<Set<Integer>> value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_int32_set", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_int32_set(value.value, seqHolder.value, protocol);
            recv_all_int32_set(value, protocol);
            putProtocol(protocol);
        }

        void send_all_int32_set(Set<Integer> value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_int32_set", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_int32_set_args args = new all_int32_set_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_int32_set(Holder<Set<Integer>> value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_int32_set_result _result = new all_int32_set_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_person_seq(Holder<List<math.Person>> value) {
            this.all_person_seq(value, false);
        }

        public void all_person_seq(Holder<List<math.Person>> value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_person_seq", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_person_seq(value.value, seqHolder.value, protocol);
            recv_all_person_seq(value, protocol);
            putProtocol(protocol);
        }

        void send_all_person_seq(List<math.Person> value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_person_seq", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_person_seq_args args = new all_person_seq_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_person_seq(Holder<List<math.Person>> value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_person_seq_result _result = new all_person_seq_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void all_int32_person_map(Holder<Map<Integer, math.Person>> value) {
            this.all_int32_person_map(value, false);
        }

        public void all_int32_person_map(Holder<Map<Integer, math.Person>> value, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("all_int32_person_map", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_all_int32_person_map(value.value, seqHolder.value, protocol);
            recv_all_int32_person_map(value, protocol);
            putProtocol(protocol);
        }

        void send_all_int32_person_map(Map<Integer, math.Person> value, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "all_int32_person_map", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            all_int32_person_map_args args = new all_int32_person_map_args();
            args.value.value = value;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_all_int32_person_map(Holder<Map<Integer, math.Person>> value, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            all_int32_person_map_result _result = new all_int32_person_map_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            value.value = _result.value.value;
        }

        public void color_out_all(math.ColorHolder color1, math.ColorHolder color2) {
            this.color_out_all(color1, color2, false);
        }

        public void color_out_all(math.ColorHolder color1, math.ColorHolder color2, boolean last) {
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return ;}

            int ret = getTicketId("color_out_all", seqHolder, last, protocol, protocol);
            if (ret < 0) { return ;}
            send_color_out_all(color1.value, seqHolder.value, protocol);
            recv_color_out_all(color1, color2, protocol);
            putProtocol(protocol);
        }

        void send_color_out_all(math.Color color1, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "color_out_all", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            color_out_all_args args = new color_out_all_args();
            args.color1.value = color1;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        void recv_color_out_all(math.ColorHolder color1, math.ColorHolder color2, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            color_out_all_result _result = new color_out_all_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            color1.value = _result.color1.value;
            color2.value = _result.color2.value;
        }

        public List<math.Color> color_xx(Set<math.Color> color1, Holder<List<math.Color>> color2, Holder<Map<math.Color, math.Color>> color3) {
            return this.color_xx(color1, color2, color3, false);
        }

        public List<math.Color> color_xx(Set<math.Color> color1, Holder<List<math.Color>> color2, Holder<Map<math.Color, math.Color>> color3, boolean last) {
            List<math.Color> return_value = new ArrayList<math.Color>();
            IntHolder seqHolder = new IntHolder(0);
            Protocol protocol = getProtocol();
            if (protocol == null) { return return_value;}

            int ret = getTicketId("color_xx", seqHolder, last, protocol, protocol);
            if (ret < 0) { return return_value;}
            send_color_xx(color1, color3.value, seqHolder.value, protocol);
            return_value = recv_color_xx(color2, color3, protocol);
            putProtocol(protocol);
            return return_value;
        }

        void send_color_xx(Set<math.Color> color1, Map<math.Color, math.Color> color3, int seqid, Protocol protocol) {
            protocol.writeMessageBegin(getWhoAmI(), "color_xx", bgcc.MessageType.CALL, seqid);
            protocol.writeString(getName());
            color_xx_args args = new color_xx_args();
            args.color1.value = color1;
            args.color3.value = color3;
            args.write(protocol);
            protocol.writeMessageEnd();
        }

        List<math.Color> recv_color_xx(Holder<List<math.Color>> color2, Holder<Map<math.Color, math.Color>> color3, Protocol protocol) {
            StringHolder fname = new StringHolder();
            IntHolder seqid = new IntHolder();
            MessageTypeHolder msgtype= new MessageTypeHolder();

            protocol.readMessageBegin(fname, msgtype, seqid);

            color_xx_result _result = new color_xx_result();
            _result.read(protocol);
            protocol.readMessageEnd();
            color2.value = _result.color2.value;
            color3.value = _result.color3.value;
            return _result.return_value.value;
        }

    }
    public static class Processor extends BaseProcessor {

        public Processor(Intf intf) {
            _intf = intf;
            _processMap.put("ping", new ping());
            _processMap.put("add", new add());
            _processMap.put("test_citizen", new test_citizen());
            _processMap.put("get_boolean", new get_boolean());
            _processMap.put("get_int8", new get_int8());
            _processMap.put("get_int16", new get_int16());
            _processMap.put("get_int32", new get_int32());
            _processMap.put("get_int64", new get_int64());
            _processMap.put("get_float", new get_float());
            _processMap.put("get_string", new get_string());
            _processMap.put("get_binary", new get_binary());
            _processMap.put("get_color", new get_color());
            _processMap.put("get_sequence", new get_sequence());
            _processMap.put("get_string_set", new get_string_set());
            _processMap.put("get_int_str_map", new get_int_str_map());
            _processMap.put("get_bool_set_sequence", new get_bool_set_sequence());
            _processMap.put("get_person", new get_person());
            _processMap.put("get_persons", new get_persons());
            _processMap.put("get_persons2", new get_persons2());
            _processMap.put("get_persons3", new get_persons3());
            _processMap.put("get_persons4", new get_persons4());
            _processMap.put("send_bool", new send_bool());
            _processMap.put("send_int8", new send_int8());
            _processMap.put("send_int16", new send_int16());
            _processMap.put("send_int32", new send_int32());
            _processMap.put("send_int64", new send_int64());
            _processMap.put("send_float", new send_float());
            _processMap.put("send_string", new send_string());
            _processMap.put("send_binary", new send_binary());
            _processMap.put("send_color", new send_color());
            _processMap.put("send_person", new send_person());
            _processMap.put("send_int32_sequence", new send_int32_sequence());
            _processMap.put("send_persons", new send_persons());
            _processMap.put("send_persons2", new send_persons2());
            _processMap.put("send_int32_set_seq", new send_int32_set_seq());
            _processMap.put("send_persons3", new send_persons3());
            _processMap.put("send_person_vec_set", new send_person_vec_set());
            _processMap.put("out_boolean", new out_boolean());
            _processMap.put("out_int8", new out_int8());
            _processMap.put("out_int16", new out_int16());
            _processMap.put("out_int32", new out_int32());
            _processMap.put("out_int64", new out_int64());
            _processMap.put("out_float", new out_float());
            _processMap.put("out_string", new out_string());
            _processMap.put("out_binary", new out_binary());
            _processMap.put("out_person", new out_person());
            _processMap.put("out_seq", new out_seq());
            _processMap.put("out_string_set", new out_string_set());
            _processMap.put("out_int16_float_map", new out_int16_float_map());
            _processMap.put("out_int_vec_set", new out_int_vec_set());
            _processMap.put("all_boolean", new all_boolean());
            _processMap.put("all_int8", new all_int8());
            _processMap.put("all_int16", new all_int16());
            _processMap.put("all_int32", new all_int32());
            _processMap.put("all_int64", new all_int64());
            _processMap.put("all_float", new all_float());
            _processMap.put("all_string", new all_string());
            _processMap.put("all_binary", new all_binary());
            _processMap.put("all_int32_seq", new all_int32_seq());
            _processMap.put("all_person", new all_person());
            _processMap.put("all_int32_set", new all_int32_set());
            _processMap.put("all_person_seq", new all_person_seq());
            _processMap.put("all_int32_person_map", new all_int32_person_map());
            _processMap.put("color_out_all", new color_out_all());
            _processMap.put("color_xx", new color_xx());
        }

        public java.lang.String getName() {
            return "global.math.Math";
        }

        private Intf _intf;

        private class ping implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                ping_args args = new ping_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                ping_result result = new ping_result();
                _intf.ping();
                out.writeMessageBegin("global.math.Math", "ping", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class add implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                add_args args = new add_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                add_result result = new add_result();
                result.return_value.value = _intf.add(args.a.value, args.b.value, result.sum);
                out.writeMessageBegin("global.math.Math", "add", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class test_citizen implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                test_citizen_args args = new test_citizen_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                test_citizen_result result = new test_citizen_result();
                result.return_value.value = _intf.test_citizen(args.ins.value, result.outs, args.alls);
                result.alls = args.alls;
                out.writeMessageBegin("global.math.Math", "test_citizen", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_boolean implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_boolean_args args = new get_boolean_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_boolean_result result = new get_boolean_result();
                result.return_value.value = _intf.get_boolean();
                out.writeMessageBegin("global.math.Math", "get_boolean", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_int8 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_int8_args args = new get_int8_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_int8_result result = new get_int8_result();
                result.return_value.value = _intf.get_int8();
                out.writeMessageBegin("global.math.Math", "get_int8", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_int16 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_int16_args args = new get_int16_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_int16_result result = new get_int16_result();
                result.return_value.value = _intf.get_int16();
                out.writeMessageBegin("global.math.Math", "get_int16", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_int32 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_int32_args args = new get_int32_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_int32_result result = new get_int32_result();
                result.return_value.value = _intf.get_int32();
                out.writeMessageBegin("global.math.Math", "get_int32", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_int64 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_int64_args args = new get_int64_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_int64_result result = new get_int64_result();
                result.return_value.value = _intf.get_int64();
                out.writeMessageBegin("global.math.Math", "get_int64", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_float implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_float_args args = new get_float_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_float_result result = new get_float_result();
                result.return_value.value = _intf.get_float();
                out.writeMessageBegin("global.math.Math", "get_float", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_string implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_string_args args = new get_string_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_string_result result = new get_string_result();
                result.return_value.value = _intf.get_string();
                out.writeMessageBegin("global.math.Math", "get_string", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_binary implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_binary_args args = new get_binary_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_binary_result result = new get_binary_result();
                result.return_value.value = _intf.get_binary();
                out.writeMessageBegin("global.math.Math", "get_binary", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_color implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_color_args args = new get_color_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_color_result result = new get_color_result();
                result.return_value.value = _intf.get_color();
                out.writeMessageBegin("global.math.Math", "get_color", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_sequence implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_sequence_args args = new get_sequence_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_sequence_result result = new get_sequence_result();
                result.return_value.value = _intf.get_sequence();
                out.writeMessageBegin("global.math.Math", "get_sequence", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_string_set implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_string_set_args args = new get_string_set_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_string_set_result result = new get_string_set_result();
                result.return_value.value = _intf.get_string_set();
                out.writeMessageBegin("global.math.Math", "get_string_set", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_int_str_map implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_int_str_map_args args = new get_int_str_map_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_int_str_map_result result = new get_int_str_map_result();
                result.return_value.value = _intf.get_int_str_map();
                out.writeMessageBegin("global.math.Math", "get_int_str_map", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_bool_set_sequence implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_bool_set_sequence_args args = new get_bool_set_sequence_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_bool_set_sequence_result result = new get_bool_set_sequence_result();
                result.return_value.value = _intf.get_bool_set_sequence();
                out.writeMessageBegin("global.math.Math", "get_bool_set_sequence", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_person implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_person_args args = new get_person_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_person_result result = new get_person_result();
                result.return_value.value = _intf.get_person();
                out.writeMessageBegin("global.math.Math", "get_person", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_persons implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_persons_args args = new get_persons_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_persons_result result = new get_persons_result();
                result.return_value.value = _intf.get_persons();
                out.writeMessageBegin("global.math.Math", "get_persons", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_persons2 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_persons2_args args = new get_persons2_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_persons2_result result = new get_persons2_result();
                result.return_value.value = _intf.get_persons2();
                out.writeMessageBegin("global.math.Math", "get_persons2", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_persons3 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_persons3_args args = new get_persons3_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_persons3_result result = new get_persons3_result();
                result.return_value.value = _intf.get_persons3();
                out.writeMessageBegin("global.math.Math", "get_persons3", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class get_persons4 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                get_persons4_args args = new get_persons4_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                get_persons4_result result = new get_persons4_result();
                result.return_value.value = _intf.get_persons4();
                out.writeMessageBegin("global.math.Math", "get_persons4", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_bool implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_bool_args args = new send_bool_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_bool_result result = new send_bool_result();
                _intf.send_bool(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_bool", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_int8 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_int8_args args = new send_int8_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_int8_result result = new send_int8_result();
                _intf.send_int8(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_int8", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_int16 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_int16_args args = new send_int16_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_int16_result result = new send_int16_result();
                _intf.send_int16(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_int16", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_int32 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_int32_args args = new send_int32_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_int32_result result = new send_int32_result();
                _intf.send_int32(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_int32", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_int64 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_int64_args args = new send_int64_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_int64_result result = new send_int64_result();
                _intf.send_int64(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_int64", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_float implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_float_args args = new send_float_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_float_result result = new send_float_result();
                _intf.send_float(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_float", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_string implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_string_args args = new send_string_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_string_result result = new send_string_result();
                _intf.send_string(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_string", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_binary implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_binary_args args = new send_binary_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_binary_result result = new send_binary_result();
                _intf.send_binary(args.value.value);
                out.writeMessageBegin("global.math.Math", "send_binary", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_color implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_color_args args = new send_color_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_color_result result = new send_color_result();
                _intf.send_color(args.color.value);
                out.writeMessageBegin("global.math.Math", "send_color", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_person implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_person_args args = new send_person_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_person_result result = new send_person_result();
                _intf.send_person(args.person.value);
                out.writeMessageBegin("global.math.Math", "send_person", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_int32_sequence implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_int32_sequence_args args = new send_int32_sequence_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_int32_sequence_result result = new send_int32_sequence_result();
                _intf.send_int32_sequence(args.numbers.value);
                out.writeMessageBegin("global.math.Math", "send_int32_sequence", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_persons implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_persons_args args = new send_persons_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_persons_result result = new send_persons_result();
                _intf.send_persons(args.persons.value);
                out.writeMessageBegin("global.math.Math", "send_persons", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_persons2 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_persons2_args args = new send_persons2_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_persons2_result result = new send_persons2_result();
                _intf.send_persons2(args.persons.value);
                out.writeMessageBegin("global.math.Math", "send_persons2", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_int32_set_seq implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_int32_set_seq_args args = new send_int32_set_seq_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_int32_set_seq_result result = new send_int32_set_seq_result();
                _intf.send_int32_set_seq(args.xx.value);
                out.writeMessageBegin("global.math.Math", "send_int32_set_seq", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_persons3 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_persons3_args args = new send_persons3_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_persons3_result result = new send_persons3_result();
                _intf.send_persons3(args.persons.value);
                out.writeMessageBegin("global.math.Math", "send_persons3", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class send_person_vec_set implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                send_person_vec_set_args args = new send_person_vec_set_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                send_person_vec_set_result result = new send_person_vec_set_result();
                _intf.send_person_vec_set(args.xxx.value);
                out.writeMessageBegin("global.math.Math", "send_person_vec_set", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_boolean implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_boolean_args args = new out_boolean_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_boolean_result result = new out_boolean_result();
                _intf.out_boolean(result.value);
                out.writeMessageBegin("global.math.Math", "out_boolean", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_int8 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_int8_args args = new out_int8_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_int8_result result = new out_int8_result();
                _intf.out_int8(result.value);
                out.writeMessageBegin("global.math.Math", "out_int8", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_int16 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_int16_args args = new out_int16_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_int16_result result = new out_int16_result();
                _intf.out_int16(result.value);
                out.writeMessageBegin("global.math.Math", "out_int16", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_int32 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_int32_args args = new out_int32_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_int32_result result = new out_int32_result();
                _intf.out_int32(result.value);
                out.writeMessageBegin("global.math.Math", "out_int32", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_int64 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_int64_args args = new out_int64_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_int64_result result = new out_int64_result();
                _intf.out_int64(result.value);
                out.writeMessageBegin("global.math.Math", "out_int64", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_float implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_float_args args = new out_float_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_float_result result = new out_float_result();
                _intf.out_float(result.value);
                out.writeMessageBegin("global.math.Math", "out_float", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_string implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_string_args args = new out_string_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_string_result result = new out_string_result();
                _intf.out_string(result.value);
                out.writeMessageBegin("global.math.Math", "out_string", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_binary implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_binary_args args = new out_binary_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_binary_result result = new out_binary_result();
                _intf.out_binary(result.value);
                out.writeMessageBegin("global.math.Math", "out_binary", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_person implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_person_args args = new out_person_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_person_result result = new out_person_result();
                _intf.out_person(result.person);
                out.writeMessageBegin("global.math.Math", "out_person", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_seq implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_seq_args args = new out_seq_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_seq_result result = new out_seq_result();
                _intf.out_seq(result.xxx);
                out.writeMessageBegin("global.math.Math", "out_seq", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_string_set implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_string_set_args args = new out_string_set_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_string_set_result result = new out_string_set_result();
                _intf.out_string_set(result.xxx);
                out.writeMessageBegin("global.math.Math", "out_string_set", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_int16_float_map implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_int16_float_map_args args = new out_int16_float_map_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_int16_float_map_result result = new out_int16_float_map_result();
                _intf.out_int16_float_map(result.xxx);
                out.writeMessageBegin("global.math.Math", "out_int16_float_map", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class out_int_vec_set implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                out_int_vec_set_args args = new out_int_vec_set_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                out_int_vec_set_result result = new out_int_vec_set_result();
                _intf.out_int_vec_set(result.xxx);
                out.writeMessageBegin("global.math.Math", "out_int_vec_set", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_boolean implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_boolean_args args = new all_boolean_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_boolean_result result = new all_boolean_result();
                _intf.all_boolean(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_boolean", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_int8 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_int8_args args = new all_int8_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_int8_result result = new all_int8_result();
                _intf.all_int8(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_int8", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_int16 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_int16_args args = new all_int16_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_int16_result result = new all_int16_result();
                _intf.all_int16(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_int16", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_int32 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_int32_args args = new all_int32_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_int32_result result = new all_int32_result();
                _intf.all_int32(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_int32", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_int64 implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_int64_args args = new all_int64_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_int64_result result = new all_int64_result();
                _intf.all_int64(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_int64", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_float implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_float_args args = new all_float_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_float_result result = new all_float_result();
                _intf.all_float(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_float", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_string implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_string_args args = new all_string_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_string_result result = new all_string_result();
                _intf.all_string(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_string", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_binary implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_binary_args args = new all_binary_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_binary_result result = new all_binary_result();
                _intf.all_binary(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_binary", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_int32_seq implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_int32_seq_args args = new all_int32_seq_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_int32_seq_result result = new all_int32_seq_result();
                _intf.all_int32_seq(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_int32_seq", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_person implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_person_args args = new all_person_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_person_result result = new all_person_result();
                _intf.all_person(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_person", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_int32_set implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_int32_set_args args = new all_int32_set_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_int32_set_result result = new all_int32_set_result();
                _intf.all_int32_set(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_int32_set", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_person_seq implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_person_seq_args args = new all_person_seq_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_person_seq_result result = new all_person_seq_result();
                _intf.all_person_seq(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_person_seq", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class all_int32_person_map implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                all_int32_person_map_args args = new all_int32_person_map_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                all_int32_person_map_result result = new all_int32_person_map_result();
                _intf.all_int32_person_map(args.value);
                result.value = args.value;
                out.writeMessageBegin("global.math.Math", "all_int32_person_map", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class color_out_all implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                color_out_all_args args = new color_out_all_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                color_out_all_result result = new color_out_all_result();
                _intf.color_out_all(args.color1, result.color2);
                result.color1 = args.color1;
                out.writeMessageBegin("global.math.Math", "color_out_all", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
        private class color_xx implements ProcessFunction {
            public int process(long request, int request_len, Protocol out,
                java.lang.String fname, int seqid) {
                int ret;
                int nread = 0;

                StringHolder xxHolder = new StringHolder();
                ret = out.readString(request + nread, request_len - nread, xxHolder);
                if (ret < 0) { return ret; }
                nread += ret;

                color_xx_args args = new color_xx_args();
                ret = args.read(out, request + nread, request_len - nread);
                out.readMessageEnd();

                color_xx_result result = new color_xx_result();
                result.return_value.value = _intf.color_xx(args.color1.value, result.color2, args.color3);
                result.color3 = args.color3;
                out.writeMessageBegin("global.math.Math", "color_xx", bgcc.MessageType.REPLY, 0);
                result.write(out);
                out.writeMessageEnd();
                return 0;
            }
        }
    }

}

