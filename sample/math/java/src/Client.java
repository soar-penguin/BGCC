import bgcc.*;
import math.*;
import common.*;
import java.util.*;
import java.lang.*;

public final class Client {
    public static void main(String[] args) {
        ServerInfo serverInfo = new ServerInfo("localhost", 8503);
        math.Math.Proxy proxy = new math.Math.Proxy(serverInfo);

        {
            Set<Color> in = new HashSet<Color>();
            in.add(Color.RED);
            in.add(Color.GREEN);
            in.add(Color.BLUE);

            Holder<List<Color>> out = new Holder<List<Color>>();

            Holder<Map<Color, Color>> all = new Holder<Map<Color, Color>>();
            all.value = new HashMap<Color, Color>();
            all.value.put(Color.GREEN, Color.GREEN);

            proxy.color_xx(in, out, all);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_xx failed");
                return;
            } else {
                System.err.println("Call send_xx success.");
                System.err.println(out.value);
                System.err.println(all.value);
            }
        }
        {
            Color color = Color.GREEN;
            proxy.send_color(color);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_color failed");
                return;
            } else {
                System.err.println("Call send_color success.");
            }
        }

        {
            ColorHolder color1 = new ColorHolder(Color.RED);
            ColorHolder color2 = new ColorHolder();

            proxy.color_out_all(color1, color2);
            if (0 != proxy.getErrno()) {
                System.err.println("Call color_out_all failed");
                return;
            } else {
                System.err.println("Call color_out_all success. all: " + color1.value + " out: " + color2.value);
            }
        }
        {
            Color color = proxy.get_color();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_color failed");
                return;
            } else {
                System.err.println("Call get_color success: color: " + color);
            }

        }

        {
            proxy.ping();
            if (0 != proxy.getErrno()) {
                System.err.println("Call ping failed");
                return;
            } else {
                System.err.println("Call ping success");
            }
        }

        {
            int a = 24;
            int b = 7;
            IntHolder sum = new IntHolder(0);
            proxy.add(a, b, sum);
            if (0 != proxy.getErrno()) {
                System.err.println("Call add failed");
                return;
            } else {
                System.err.println("Call add success value: " + sum.value);
            }
        }

        {
            byte number = proxy.get_int8();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_short failed");
                return;
            }
            else {
                System.err.println("Call get_short success. value: " + number);
            }
        }

        {
            short number = proxy.get_int16();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_int16 failed");
                return;
            }
            else {
                System.err.println("Call get_int16 success. value: " + number);
            }
        }

        {
            int number = proxy.get_int32();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_int32 failed");
                return;
            }
            else {
                System.err.println("Call get_int32 success. value: " + number);
            }
        }

        {
            long number = proxy.get_int64();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_int64 failed");
                return;
            }
            else {
                System.err.println("Call get_int64 success. value: " + number);
            }
        }

        {
            String string = proxy.get_string();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_string failed");
                return;
            }
            else {
                System.err.println("Call get_string success. value: " + string);
            }
        }

        {
            boolean b = proxy.get_boolean();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_boolean failed");
                return;
            }
            else {
                System.err.println("Call get_boolean success. value: " + b);
            }
        }

        {
            float f = proxy.get_float();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_float failed");
                return;
            }
            else {
                System.err.println("Call get_float success. value: " + f);
            }
        }

        {
            String string = proxy.get_binary();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_binary failed");
                return;
            }
            else {
                System.err.println("Call get_binary success. value: " + string);
            }
        }

        {
            List<Integer> list = proxy.get_sequence();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_sequence failed");
                return;
            }
            else {
                System.err.println("Call get_sequence success. value: " + list);
            }
        }

        {
            Set<String> set = proxy.get_string_set();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_string_set failed");
                return;
            }
            else {
                System.err.println("Call get_string_set success. value: " + set);
            }
        }

        {
            Map<Long, String> map = proxy.get_int_str_map();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_int_str_map failed");
                return;
            }
            else {
                System.err.println("Call get_int_str_map success. value: " + map);
            }
        }

        {
            List<Set<Boolean>> bool_set_list = proxy.get_bool_set_sequence();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_bool_set_sequence failed");
                return;
            }
            else {
                System.err.println("Call get_bool_set_sequence success. value: " + bool_set_list);
            }
        }

        {
            Person person = proxy.get_person();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_person failed");
                return;
            }
            else {
                System.err.println("Call get_person success. value: " + person);
            }
        }

        {
            List<Person> persons = proxy.get_persons();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_persons failed");
                return;
            }
            else {
                System.err.println("Call get_persons success. value: " + persons);
            }
        }

        {
            Set<Person> persons = proxy.get_persons2();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_persons2 failed");
                return;
            }
            else {
                System.err.println("Call get_persons2 success. value: " + persons);
            }
        }

        {
            Map<Person, Person> persons = proxy.get_persons3();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_persons3 failed");
                return;
            }
            else {
                System.err.println("Call get_persons3 success. value: " + persons);
            }
        }

        {
            List<Set<Person>> persons = proxy.get_persons4();
            if (0 != proxy.getErrno()) {
                System.err.println("Call get_persons4 failed");
                return;
            }
            else {
                System.err.println("Call get_persons4 success. value: " + persons);
            }
        }

        {
            BooleanHolder holder = new BooleanHolder();
            proxy.out_boolean(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_boolean failed");
                return;
            }
            else {
                System.err.println("Call out_boolean success. value: " + holder.value);
            }
        }

        {
            ByteHolder holder = new ByteHolder();
            proxy.out_int8(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_int8 failed");
                return;
            }
            else {
                System.err.println("Call out_int8 success. value: " + holder.value);
            }
        }


        {
            ShortHolder holder = new ShortHolder();
            proxy.out_int16(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_int16 failed");
                return;
            }
            else {
                System.err.println("Call out_int16 success. value: " + holder.value);
            }
        }

        {
            IntHolder holder = new IntHolder();
            proxy.out_int32(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_int32 failed");
                return;
            }
            else {
                System.err.println("Call out_int32 success. value: " + holder.value);
            }
        }

        {
            LongHolder holder = new LongHolder();
            proxy.out_int64(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_int64 failed");
                return;
            }
            else {
                System.err.println("Call out_int64 success. value: " + holder.value);
            }
        }

        {
            StringHolder holder = new StringHolder();
            proxy.out_string(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_string failed");
                return;
            }
            else {
                System.err.println("Call out_string success. value: " + holder.value);
            }
        }

        {
            StringHolder holder = new StringHolder();
            proxy.out_binary(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_binary failed");
                return;
            }
            else {
                System.err.println("Call out_binary success. value: " + holder.value);
            }
        }

        {
            FloatHolder holder = new FloatHolder();
            proxy.out_float(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_float failed");
                return;
            }
            else {
                System.err.println("Call out_float success. value: " + holder.value);
            }
        }

        {
            Holder<List<Integer>> holder = new Holder<List<Integer>>();
            proxy.out_seq(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_seq failed");
                return;
            }
            else {
                System.err.println("Call out_seq success. value: " + holder.value);
            }
        }

        {
            Holder<Set<String>> holder = new Holder<Set<String>>();
            proxy.out_string_set(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_string_set failed");
                return;
            }
            else {
                System.err.println("Call out_string_set success. value: " + holder.value);
            }
        }

        {
            Holder<Map<Short, Float>> holder = new Holder<Map<Short, Float>>();
            proxy.out_int16_float_map(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_int16_float_map failed");
                return;
            }
            else {
                System.err.println("Call out_int16_float_map success. value: " + holder.value);
            }
        }

        {
            Holder<Set<List<Integer>>> holder = new Holder<Set<List<Integer>>>();
            proxy.out_int_vec_set(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call out_int_vec_set failed");
                return;
            }
            else {
                System.err.println("Call out_int_vec_set success. value: " + holder.value);
            }
        }

        {
            BooleanHolder holder = new BooleanHolder(true);
            proxy.all_boolean(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_boolean failed");
                return;
            }
            else {
                System.err.println("Call all_boolean success. value: " + holder.value);
            }
        }

        {
            byte b = 22;
            ByteHolder holder = new ByteHolder(b);
            proxy.all_int8(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_int8 failed");
                return;
            }
            else {
                System.err.println("Call all_int8 success. value: " + holder.value);
            }
        }

        {
            short s = 22;
            ShortHolder holder = new ShortHolder(s);
            proxy.all_int16(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_int16 failed");
                return;
            }
            else {
                System.err.println("Call all_int16 success. value: " + holder.value);
            }
        }

        {
            IntHolder holder = new IntHolder(22);
            proxy.all_int32(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_int32 failed");
                return;
            }
            else {
                System.err.println("Call all_int32 success. value: " + holder.value);
            }
        }

        {
            LongHolder holder = new LongHolder(22);
            proxy.all_int64(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_int64 failed");
                return;
            }
            else {
                System.err.println("Call all_int64 success. value: " + holder.value);
            }
        }

        {
            StringHolder holder = new StringHolder("jack");
            proxy.all_string(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_string failed");
                return;
            }
            else {
                System.err.println("Call all_string success. value: " + holder.value);
            }
        }

        {
            StringHolder holder = new StringHolder("ddd");
            proxy.all_binary(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_binary failed");
                return;
            }
            else {
                System.err.println("Call all_binary success. value: " + holder.value);
            }
        }

        {
            FloatHolder holder = new FloatHolder(4.4f);
            proxy.all_float(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_float failed");
                return;
            }
            else {
                System.err.println("Call all_float success. value: " + holder.value);
            }
        }

        {
            Person person = new Person();
            person.setName("tom");
            person.setAge(44);

            PersonHolder holder = new PersonHolder(person);
            proxy.all_person(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_person failed");
                return;
            }
            else {
                System.err.println("Call all_person success. value: " + holder.value);
            }
        }

        {
            List<Integer> list = new ArrayList<Integer>();
            list.add(666);
            list.add(777);
            list.add(888);

            Holder<List<Integer>> holder = new Holder<List<Integer>>(list);
            proxy.all_int32_seq(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_int32_seq failed");
                return;
            }
            else {
                System.err.println("Call all_int32_seq success. value: " + holder.value);
            }
        }

        {
            Set<Integer> set = new HashSet<Integer>();
            set.add(666);
            set.add(777);
            set.add(888);

            Holder<Set<Integer>> holder = new Holder<Set<Integer>>(set);
            proxy.all_int32_set(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_int32_set failed");
                return;
            }
            else {
                System.err.println("Call all_int32_set success. value: " + holder.value);
            }
        }

        {
            List<Person> list = new ArrayList<Person>();
            Person jack = new Person();
            jack.setName("jack1");
            jack.setAge(33);

            list.add(jack);

            Person mery = new Person();
            mery.setName("mery1");
            mery.setAge(44);

            list.add(mery);

            Holder<List<Person>> holder = new Holder<List<Person>>(list);
            proxy.all_person_seq(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_person_seq failed");
                return;
            }
            else {
                System.err.println("Call all_person_seq success. value: " + holder.value);
            }
        }

        {
            Map<Integer, Person> map = new HashMap<Integer, Person>();
            Person jack = new Person();
            jack.setName("jack1");
            jack.setAge(33);

            map.put(new Integer(1), jack);

            Person mery = new Person();
            mery.setName("mery1");
            mery.setAge(44);

            map.put(new Integer(2), mery);

            Holder<Map<Integer, Person>> holder = new Holder<Map<Integer, Person>>(map);
            proxy.all_int32_person_map(holder);
            if (0 != proxy.getErrno()) {
                System.err.println("Call all_int32_person_map failed");
                return;
            }
            else {
                System.err.println("Call all_int32_person_map success. value: " + holder.value);
            }
        }

        System.err.println(be_health.value);
        System.err.println(be_used.value);
        System.err.println(i8.value);
        System.err.println(i16.value);
        System.err.println(i32.value);
        System.err.println(i64.value);
        System.err.println(str.value);
        System.err.println(bin.value);
        System.err.println(f.value);

        {
            boolean value = true;
            proxy.send_bool(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_bool failed");
                return;
            }
            else {
                System.err.println("Call send_bool success. value: " + value);
            }
        }

        {
            byte value = 8;
            proxy.send_int8(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_int8 failed");
                return;
            }
            else {
                System.err.println("Call send_int8 success. value: " + value);
            }
        }

        {
            short value = 16;
            proxy.send_int16(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_int16 failed");
                return;
            }
            else {
                System.err.println("Call send_int16 success. value: " + value);
            }
        }

        {
            int value = 32;
            proxy.send_int32(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_int32 failed");
                return;
            }
            else {
                System.err.println("Call send_int32 success. value: " + value);
            }
        }

        {
            long value = 64;
            proxy.send_int64(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_int64 failed");
                return;
            }
            else {
                System.err.println("Call send_int64 success. value: " + value);
            }
        }

        {
            String value = "ccc";
            proxy.send_string(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_string failed");
                return;
            }
            else {
                System.err.println("Call send_string success. value: " + value);
            }
        }

        {
            String value = "ccc";
            proxy.send_binary(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_binary failed");
                return;
            }
            else {
                System.err.println("Call send_binary success. value: " + value);
            }
        }

        {
            float value = 8.8f;
            proxy.send_float(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_float failed");
                return;
            }
            else {
                System.err.println("Call send_float success. value: " + value);
            }
        }

        {
            Person value = new Person();
            value.setName("xxx");
            value.setAge(88);

            proxy.send_person(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_person failed");
                return;
            }
            else {
                System.err.println("Call send_person success. value: " + value);
            }
        }

        {
            List<Person> value = new ArrayList<Person>();

            Person p1 = new Person();
            p1.setName("xxx");
            p1.setAge(88);

            value.add(p1);

            proxy.send_persons(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_persons failed");
                return;
            }
            else {
                System.err.println("Call send_persons success. value: " + value);
            }
        }

        {
            List<Integer> value = new ArrayList<Integer>();

            value.add(new Integer(1));
            value.add(new Integer(2));

            proxy.send_int32_sequence(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_int32_sequence failed");
                return;
            }
            else {
                System.err.println("Call send_int32_sequence success. value: " + value);
            }
        }

        {
            Set<Person> value = new HashSet<Person>();

            Person p1 = new Person();
            p1.setName("xxx");
            p1.setAge(88);

            value.add(p1);

            proxy.send_persons2(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_persons2 failed");
                return;
            }
            else {
                System.err.println("Call send_persons2 success. value: " + value);
            }
        }

        {
            Map<Person, Person> value = new HashMap<Person, Person>();

            Person p1 = new Person();
            p1.setName("xxx");
            p1.setAge(88);

            Person p2 = new Person();
            p2.setName("yyy");
            p2.setAge(99);

            value.put(p1, p2);

            proxy.send_persons3(value);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_persons3 failed");
                return;
            }
            else {
                System.err.println("Call send_persons3 success. value: " + value);
            }
        }

        {
            List<Set<Integer>> list = new ArrayList<Set<Integer>>();

            Set<Integer> s1 = new HashSet<Integer>();
            s1.add(1);
            s1.add(2);
            list.add(s1);

            Set<Integer> s2 = new HashSet<Integer>();
            s2.add(4);
            s2.add(5);
            s2.add(6);
            list.add(s2);

            proxy.send_int32_set_seq(list);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_int32_set_seq failed");
                return;
            }
            else {
                System.err.println("Call send_int32_set_seq success. value: " + list);
            }
        }

        {
            Set<List<Person>> set = new HashSet<List<Person>>();

            List<Person> s1 = new ArrayList<Person>();
            Person jack = new Person();
            jack.setName("jack");
            jack.setAge(23);
            s1.add(jack);

            set.add(s1);

            List<Person> s2 = new ArrayList<Person>();
            Person mery = new Person();
            mery.setName("mery");
            mery.setAge(33);
            s2.add(mery);
            set.add(s2);

            proxy.send_person_vec_set(set);
            if (0 != proxy.getErrno()) {
                System.err.println("Call send_person_vec_set failed");
                return;
            }
            else {
                System.err.println("Call send_person_vec_set success. value: " + set);
            }
        }

        {
            Citizen citizen = new Citizen();
            citizen.setName("jack");
            citizen.setAge(32);
            citizen.setGender(Gender.FEMALE);

            Address address = new Address();
            address.setCity("taiwan");
            address.setRoad("namlu");
            address.setNumber(10);

            citizen.setAddress(address);

            List<String> children = new ArrayList<String>();
            children.add("kiki");
            children.add("ffff");

            citizen.setChildren(children);

            Set<Integer> xxx = new HashSet<Integer>();
            xxx.add(33);
            xxx.add(34);
            xxx.add(35);

            citizen.setXxx(xxx);

            Map<Byte, Boolean> kkk = new HashMap<Byte, Boolean>();
            kkk.put(new Byte("0"), new Boolean(true));

            citizen.setKkk(kkk);

            CitizenHolder outs = new CitizenHolder();
            CitizenHolder alls = new CitizenHolder();
            alls.value = citizen;

            Citizen ret = proxy.test_citizen(citizen, outs, alls);
            if (0 != proxy.getErrno()) {
                System.err.println("Call test_citizen failed");
                return;
            }
            else {
                System.err.println("Call test_citizen success.");
                System.err.println("outs.name:" + outs.value.getName());
                System.err.println("outs.age:" + outs.value.getAge());
                System.err.println("outs.gender:" + outs.value.getGender());
                System.err.println("outs.value.address:" + outs.value.getAddress().getCity()
                        + " " + outs.value.getAddress().getRoad()
                        + " " + outs.value.getAddress().getNumber());
                System.err.println(outs.value.getChildren());
                System.err.println(outs.value.getXxx());
                System.err.println(outs.value.getKkk());

                System.err.println("alls.name:" + alls.value.getName());
                System.err.println("alls.age:" + alls.value.getAge());
                System.err.println("alls.gender:" + alls.value.getGender());
                System.err.println("alls.value.address:" + alls.value.getAddress().getCity()
                        + " " + alls.value.getAddress().getRoad()
                        + " " + alls.value.getAddress().getNumber());
                System.err.println(alls.value.getChildren());
                System.err.println(alls.value.getXxx());
                System.err.println(alls.value.getKkk());

                System.err.println("ret.name:" + ret.getName());
                System.err.println("ret.age:" + ret.getAge());
                System.err.println("ret.gender:" + ret.getGender());
                System.err.println("ret.address:" + ret.getAddress().getCity()
                        + " " + ret.getAddress().getRoad()
                        + " " + ret.getAddress().getNumber());
                System.err.println(ret.getChildren());
                System.err.println(ret.getXxx());
                System.err.println(ret.getKkk());

            }
        }
    }
}
