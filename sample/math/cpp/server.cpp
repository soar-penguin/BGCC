#include <algorithm>
#include <bgcc.h>
#include "math.h"

using namespace bgcc;
using namespace math;
using namespace common;

class MathImpl : public Math {
public:
    virtual ~MathImpl() { }

    virtual void ping(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter ping");
        BGCC_TRACE("LXB", "Leave ping\n");
    }

    virtual AddResult add(
            int32_t a,
            int32_t b,
            int32_t & sum,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter add[a: %d, b: %d]", a, b);

        AddResult ret = AddResult::E_SUCCESS;
        int32_t s = a + b;

        if (a > 0 && b > 0 && s <= 0) {
            ret = AddResult::E_OVERFLOW;
        } else if (a < 0 && b < 0 && s >= 0) {
            ret = AddResult::E_DOWNFLOW;
        } else {
            sum = s;
        }

        BGCC_TRACE("LXB", "Leave add[ret: %s(%d), sum: %d]\n",
                ret.get_desc().c_str(), ret.get_value(), sum);
        return ret;
    }

    virtual bool get_boolean(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_boolean");
        bool ret = true;
        BGCC_TRACE("LXB", "Leave get_boolean[ret: %s]\n", ret? "true": "false");
        return ret;
    }

    virtual int8_t get_int8(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_int8");
        int8_t ret = 18;
        BGCC_TRACE("LXB", "Leave get_int8[ret: %d]\n", (int32_t)ret);
        return ret;
    }

    virtual int16_t get_int16(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_int16");
        int16_t ret = 116;
        BGCC_TRACE("LXB", "Leave get_int16[ret: %d]\n", ret);
        return ret;
    }

    virtual int32_t get_int32(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_int32");
        int32_t ret = 132;
        BGCC_TRACE("LXB", "Leave get_int32[ret: %d]\n", ret);
        return ret;
    }

    virtual int64_t get_int64(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_int64");
        int64_t ret = 164;
        BGCC_TRACE("LXB", "Leave get_int64[ret: %ld]\n", ret);
        return ret;
    }

    virtual float get_float(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_float");
        float ret = 13.3f;
        BGCC_TRACE("LXB", "Leave get_float[ret: %f]\n", ret);
        return ret;
    }

    virtual std::string get_string(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_string");
        std::string ret = "1 This is a string";
        BGCC_TRACE("LXB", "Leave get_string[ret: %s]\n", ret.c_str());
        return ret;
    }

    virtual std::string get_binary(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_binary");
        std::string ret = "1 This is a data";
        BGCC_TRACE("LXB", "Leave get_binary[ret: %s]\n", ret.c_str());
        return ret;
    }

    virtual void send_bool(
            b_t value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_boolean[value: %s]", value? "true": "false");
        BGCC_TRACE("LXB", "Leave send_boolean\n");
    }

    virtual void send_int8(
            i8_t value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_int8[value: %d]", (int32_t)value);
        BGCC_TRACE("LXB", "Leave send_int8\n");
    }

    virtual void send_int16(
            i16_t value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_int16[value: %d]", value);
        BGCC_TRACE("LXB", "Leave send_int16\n");
    }

    virtual void send_int32(
            i32_t value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_int32[value: %d]", value);
        BGCC_TRACE("LXB", "Leave send_int32\n");
    }

    virtual void send_int64(
            i64_t value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_int64[value: %ld]", value);
        BGCC_TRACE("LXB", "Leave send_int64\n");
    }

    virtual void send_float(
            f_t value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_float[value: %f]", value);
        BGCC_TRACE("LXB", "Leave send_float\n");
    }

    virtual void send_string(
            const s_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_string[value: %s]", value.c_str());
        BGCC_TRACE("LXB", "Leave send_string\n");
    }

    virtual void send_binary(
            const bin_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_binary[value: %s]", value.c_str());
        BGCC_TRACE("LXB", "Leave send_binary\n");
    }

    virtual void out_boolean(
            bool & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_boolean");
        value = true;
        BGCC_TRACE("LXB", "Leave out_boolean[value: %s]\n", value? "true": "false");
    }


    virtual void out_int8(
            int8_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_int8");
        value = 18;
        BGCC_TRACE("LXB", "Leave out_int8[value: %d]\n", (int32_t)value);
    }

    virtual void out_int16(
            int16_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_int16");
        value = 116;
        BGCC_TRACE("LXB", "Leave out_int16[value: %d]\n", value);
    }

    virtual void out_int32(
            int32_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_int32");
        value = 132;
        BGCC_TRACE("LXB", "Leave out_int32[value: %d]\n", value);
    }

    virtual void out_int64(
            int64_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_int64");
        value = 164;
        BGCC_TRACE("LXB", "Leave out_int64[value: %ld]\n", value);
    }

    virtual void out_float(
            float & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_float");
        value = 13.3f;
        BGCC_TRACE("LXB", "Leave out_float[value: %f]\n", value);
    }

    virtual void out_string(
            std::string & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_string");
        value = "1 This is a string";
        BGCC_TRACE("LXB", "Leave out_string[value: %s]\n", value.c_str());
    }

    virtual void out_binary(
            std::string & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_data");
        value = "1 This is a data";
        BGCC_TRACE("LXB", "Leave out_data[value: %s]\n", value.c_str());
    }

    virtual void all_boolean(
            bool & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_boolean[value: %s]", value? "true": "false");
        value = false;
        BGCC_TRACE("LXB", "Leave all_boolean[value: %s]\n", value? "true": "false");
    }

    virtual void all_int8(
            int8_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_int8[value: %d]", (int32_t)value);
        value = 18;
        BGCC_TRACE("LXB", "Leave all_int8[value: %d]\n", (int32_t)value);
    }

    virtual void all_int16(
            int16_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_int16[value: %d]", value);
        value = 116;
        BGCC_TRACE("LXB", "Leave all_int16[value: %d]\n", value);
    }

    virtual void all_int32(
            int32_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_int32[value: %d]", value);
        value = 132;
        BGCC_TRACE("LXB", "Leave all_int32[value: %d]\n", value);
    }

    virtual void all_int64(
            int64_t & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_int64[value: %ld]", value);
        value = 164;
        BGCC_TRACE("LXB", "Leave all_int64[value: %ld]\n", value);
    }

    virtual void all_float(
            float & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_float[value: %f]", value);
        value = 13.3f;
        BGCC_TRACE("LXB", "Leave all_float[value: %f]\n", value);
    }

    virtual void all_string(
            std::string & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_string[value: %s]", value.c_str());
        value = "1 This is a string";
        BGCC_TRACE("LXB", "Leave all_string[value: %s]\n", value.c_str());
    }

    virtual void all_binary(
            std::string & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_binary[value: %s]", value.c_str());
        value = "1 This is a data";
        BGCC_TRACE("LXB", "Leave all_binary[value: %s]\n", value.c_str());
    }

    virtual Color get_color(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_color");
        Color ret = Color::RED;
        BGCC_TRACE("LXB", "Leave get_color[ret: %s(%d)]\n", ret.get_desc().c_str(), ret.get_value());
        return ret;
    }

    virtual void send_color(
            const Color & color,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_color[color: %s(%d)]\n", color.get_desc().c_str(), color.get_value());
        BGCC_TRACE("LXB", "Leave send_color\n");
    }

    virtual void color_out_all(
            MyColor & color1,
            MyColor & color2,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter color_out_all[color1: %s(%d)]",
                color1.get_desc().c_str(), color1.get_value());
        color1 = Color::GREEN;
        color2 = Color::BLUE;
        BGCC_TRACE("LXB", "Leave color_out_all[color1: %s(%d), color2: %s(%d)]\n",
                color1.get_desc().c_str(), color1.get_value(),
                color2.get_desc().c_str(), color2.get_value());
    }

    virtual Person get_person(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_person");
        Person person;
        person.name = "1 Jack";
        person.age = 123;

        BGCC_TRACE("LXB", "Leave get_person[person.name: %s, person.age: %d]\n",
                person.name.c_str(), person.age);
        return person;
    }

    virtual void send_person(
            const MyPerson & person,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_person[person.name: %s, person.age: %d]",
                person.name.c_str(), person.age);
        BGCC_TRACE("LXB", "Leave send_person\n");
    }

    virtual void out_person(
            Person & person,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_person");
        person.name = "1 Jack";
        person.age = 123;

        BGCC_TRACE("LXB", "Leave out_person[person.name: %s, person.age: %d]\n",
                person.name.c_str(), person.age);
    }

    virtual void all_person(
            Person & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_person[person.name: %s, person.age: %d]\n",
                value.name.c_str(), value.age);
        value.name = "1 Jack";
        value.age = 123;

        BGCC_TRACE("LXB", "Leave all_person[person.name: %s, person.age: %d]\n",
                value.name.c_str(), value.age);
    }

    virtual std::vector<int32_t>  get_sequence(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_sequence");
        std::vector<int32_t> ret;
        ret.push_back(11);
        ret.push_back(12);
        ret.push_back(13);
        BGCC_TRACE("LXB", "Leave get_sequence\n");
        return ret;
    }

    virtual void send_int32_sequence(
            const std::vector<int32_t>  & numbers,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_int32_sequence");
        std::vector<int32_t>::const_iterator citr;
        for (citr = numbers.begin(); citr != numbers.end(); ++citr) {
            BGCC_TRACE("LXB", "\n%d", *citr);
        }
        BGCC_TRACE("LXB", "Leave send_int32_sequence\n");
    }

    virtual void out_seq(
            std::vector<int32_t>  & xxx,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_seq");
        xxx.push_back(11);
        xxx.push_back(12);
        xxx.push_back(13);
        BGCC_TRACE("LXB", "Leave out_seq\n");
    }

    virtual void all_int32_seq(
            std::vector<int32_t>  & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_int32_seq");
        std::vector<int32_t>::const_iterator citr;
        for (citr = value.begin(); citr != value.end(); ++citr) {
            BGCC_TRACE("LXB", "\n%d", *citr);
        }

        value.clear();
        value.push_back(11);
        value.push_back(12);
        value.push_back(13);
        BGCC_TRACE("LXB", "Leave all_int32_seq\n");
    }

    virtual std::set<std::string>  get_string_set(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_string_set");
        std::set<std::string> ret;
        ret.insert("1 first");
        ret.insert("1 second");
        ret.insert("1 third");
        BGCC_TRACE("LXB", "Leave get_string_set\n");
        return ret;
    }

    virtual void out_string_set(
            std::set<std::string>  & xxx,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_string_set");
        xxx.insert("1 first");
        xxx.insert("1 second");
        xxx.insert("1 third");
        BGCC_TRACE("LXB", "Leave out_string_set\n");
    }

    virtual std::map<int64_t, std::string>  get_int_str_map(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_int_str_map");
        std::map<int64_t, std::string> m;
        m.insert(std::make_pair(1, "1 first"));
        m.insert(std::make_pair(2, "1 second"));
        m.insert(std::make_pair(3, "1 third"));
        BGCC_TRACE("LXB", "Leave get_int_str_map\n");
        return m;
    }

    virtual void all_int32_set(
            std::set<int32_t>  & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_int32_set");
        std::set<int32_t>::const_iterator citr;
        for (citr = value.begin(); citr != value.end(); ++citr) {
            BGCC_TRACE("LXB", "%d", *citr);
        }

        value.clear();
        value.insert(11);
        value.insert(12);
        value.insert(13);
        BGCC_TRACE("LXB", "Leave all_int32_set\n");
    }

    virtual std::vector<std::set<bool> >  get_bool_set_sequence(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_bool_set_sequence");
        std::vector<std::set<bool> > v;

        std::set<bool> s;
        s.insert(true);
        s.insert(false);
        v.push_back(s);

        s.clear();
        s.insert(true);
        v.push_back(s);

        s.clear();
        s.insert(false);
        v.push_back(s);

        BGCC_TRACE("LXB", "Leave get_bool_set_sequence\n");
        return v;
    }

    virtual void send_int32_set_seq(
            const std::vector<std::set<int32_t> >  & xx,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_int32_set_seq");
        std::vector<std::set<int32_t> >::const_iterator citr;
        for (citr = xx.begin(); citr != xx.end(); ++citr) {
            const std::set<int32_t> & s = *citr;
            std::set<int32_t>::const_iterator inner_citr;
            for (inner_citr = s.begin(); inner_citr != s.end(); ++inner_citr) {
                BGCC_TRACE("LXB", "%d", *inner_citr);
            }
        }
        BGCC_TRACE("LXB", "Leave send_int32_set_seq\n");
    }

    virtual void out_int16_float_map(
            std::map<int16_t, float>  & xxx,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_int16_float_map");
        xxx.insert(std::make_pair(11, 1.1f));
        xxx.insert(std::make_pair(12, 1.2f));
        xxx.insert(std::make_pair(13, 1.3f));
        BGCC_TRACE("LXB", "Leave out_int16_float_map\n");
    }

    virtual void out_int_vec_set(
            std::set<std::vector<int32_t> >  & xxx,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter out_int_vec_set");

        std::vector<int32_t> v;
        v.push_back(11);
        v.push_back(12);
        v.push_back(13);
        xxx.insert(v);

        v.clear();
        v.push_back(14);
        v.push_back(15);
        v.push_back(16);
        xxx.insert(v);

        BGCC_TRACE("LXB", "Leave out_int_vec_set\n");
    }

    virtual std::vector<Person>  get_persons(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_persons");
        std::vector<Person> v;

        Person person;
        person.age = 10;
        person.name = "1 jack";
        v.push_back(person);

        person.age = 11;
        person.name = "1 mery";
        v.push_back(person);

        BGCC_TRACE("LXB", "Leave get_persons\n");
        return v;
    }

    virtual std::set<Person>  get_persons2(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_persons2");
        std::set<Person> s;

        Person person;
        person.age = 10;
        person.name = "1 jack";
        s.insert(person);

        person.age = 11;
        person.name = "1 mery";
        s.insert(person);

        BGCC_TRACE("LXB", "Leave get_persons2\n");
        return s;
    }

    virtual std::map<Person, Person>  get_persons3(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_persons3");
        std::map<Person, Person> m;

        Person jack;
        jack.age = 10;
        jack.name = "1 jack";

        Person mery;
        mery.age = 11;
        mery.name = "1 mery";

        m.insert(std::make_pair(jack, mery));
        m.insert(std::make_pair(mery, jack));
        BGCC_TRACE("LXB", "Leave get_persons3\n");
        return m;
    }

    virtual std::vector<std::set<Person> >  get_persons4(
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter get_persons4");
        std::vector<std::set<Person> > v;

        std::set<Person> s;

        Person person;

        person.age = 11;
        person.name = "--11--";
        s.insert(person);

        person.age = 12;
        person.name = "--12--";
        s.insert(person);

        v.push_back(s);

        s.clear();
        person.age = 13;
        person.name = "--13--";
        s.insert(person);

        person.age = 14;
        person.name = "--14--";
        s.insert(person);
        v.push_back(s);

        BGCC_TRACE("LXB", "Leave get_persons4\n");
        return v;
    }

    virtual void send_persons(
            const std::vector<Person>  & persons,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_persons");
        std::vector<Person>::const_iterator citr;
        for (citr = persons.begin(); citr != persons.end(); ++citr) {
            BGCC_TRACE("LXB", "%d %s", citr->age, citr->name.c_str());
        }
        BGCC_TRACE("LXB", "Leave send_persons\n");
    }

    virtual void send_persons2(
            const std::set<Person>  & persons,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_persons2");
        std::set<Person>::const_iterator citr;
        for (citr = persons.begin(); citr != persons.end(); ++citr) {
            BGCC_TRACE("LXB", "%d %s", citr->age, citr->name.c_str());
        }
        BGCC_TRACE("LXB", "Leave send_persons2\n");
    }

    virtual void send_persons3(
            const std::map<Person, Person>  & persons,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_persons3");
        std::map<Person, Person>::const_iterator citr;
        for (citr = persons.begin(); citr != persons.end(); ++citr) {
            BGCC_TRACE("LXB", "key:%d %s value:%d %s", citr->first.age, citr->first.name.c_str(),
                    citr->second.age, citr->second.name.c_str());
        }
        BGCC_TRACE("LXB", "Leave send_persons3\n");
    }

    virtual void send_person_vec_set(
            const std::set<std::vector<Person> >  & xxx,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter send_person_vec_set");
        std::set<std::vector<Person> >::const_iterator citr;
        for (citr = xxx.begin(); citr != xxx.end(); ++citr) {
            const std::vector<Person>& s = *citr;
            std::vector<Person>::const_iterator inner_citr;
            for (inner_citr = s.begin(); inner_citr != s.end(); ++inner_citr) {
                BGCC_TRACE("LXB", "%d %s", inner_citr->age, inner_citr->name.c_str());
            }
        }
        BGCC_TRACE("LXB", "Leave send_person_vec_set\n");
    }

    virtual void all_person_seq(
            std::vector<Person>  & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_person_seq");
        std::vector<Person>::const_iterator citr;
        for (citr = value.begin(); citr != value.end(); ++citr) {
            BGCC_TRACE("LXB", "%d %s", citr->age, citr->name.c_str());
        }

        value.clear();
        Person person;
        person.age = 11;
        person.name = "--11--";
        value.push_back(person);
        BGCC_TRACE("LXB", "Leave all_person_seq\n");
    }

    virtual void all_int32_person_map(
            std::map<int32_t, Person>  & value,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter all_int32_person_map");

        std::map<int32_t, Person>::const_iterator citr;
        for (citr = value.begin(); citr != value.end(); ++citr) {
            BGCC_TRACE("LXB", "%d %s %d", citr->first, citr->second.name.c_str(), citr->second.age);
        }

        value.clear();
        Person person;
        person.age = 11;
        person.name = "--11--";
        value.insert(std::make_pair(11, person));
        BGCC_TRACE("LXB", "Leave all_int32_person_map\n");
    }

    virtual std::vector<MyColor>  color_xx(
            const std::set<MyColor>  & color1,
            std::vector<MyColor>  & color2,
            std::map<MyColor, MyColor>  & color3,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter color_xx");
        {
            std::set<MyColor>::const_iterator citr;
            for (citr = color1.begin(); citr != color1.end(); ++citr) {
                BGCC_TRACE("LXB", "%d %s", citr->get_value(), citr->get_desc().c_str());
            }
        }

        color2.push_back(MyColor::RED);

        {
            std::map<MyColor, MyColor>::const_iterator citr;
            for (citr = color3.begin(); citr != color3.end(); ++ citr) {
                BGCC_TRACE("LXB", "key: %d %s, value: %d %s",
                        citr->first.get_value(), citr->first.get_desc().c_str(),
                        citr->second.get_value(), citr->second.get_desc().c_str());
            }

            color3.clear();
            Color green(Color::GREEN);
            Color blue(Color::BLUE);
            color3.insert(std::make_pair(green, blue));
        }
        BGCC_TRACE("LXB", "Leave color_xx\n");

        return color2;
    }

    virtual Citizen test_citizen(
            const Citizen & ins,
            Citizen & outs,
            Citizen & alls,
            const std::map<std::string, std::string>& ctx) {
        BGCC_TRACE("LXB", "Enter test_citizen");

        BGCC_TRACE("LXB", "ins: %s", ins.name.c_str());
        BGCC_TRACE("LXB", "ins: %d", ins.age);
        BGCC_TRACE("LXB", "ins: %s", ins.gender.get_desc().c_str());
        BGCC_TRACE("LXB", "ins.address: %s %s %d",
                ins.address.city.c_str(),
                ins.address.road.c_str(),
                ins.address.number);

        {
            std::vector<std::string>::const_iterator citr;
            for (citr = ins.children.begin(); citr != ins.children.end(); ++citr) {
                BGCC_TRACE("LXB", "ins.xxx--- %s", citr->c_str());
            }
        }

        BGCC_TRACE("LXB", "alls: %s", alls.name.c_str());
        BGCC_TRACE("LXB", "alls: %d", alls.age);
        BGCC_TRACE("LXB", "alls: %s", alls.gender.get_desc().c_str());
        BGCC_TRACE("LXB", "alls.address: %s %s %d",
                alls.address.city.c_str(),
                alls.address.road.c_str(),
                alls.address.number);
        
		Address address;
		address.city = "1 Beijing";
		address.road = "1 Xueyuan";
		address.number = 1222;

        std::map<int8_t, bool> m;
        m.insert(std::make_pair(8, true));

        outs.name = "1 outs";
        outs.age = 123;
        outs.gender = Gender::FEMALE;
        outs.address = address;
        outs.kkk = m;

        alls.name = "1 alls";
        alls.age = 134;
        alls.gender = Gender::FEMALE;
        alls.address = address;
        alls.kkk = m;

        BGCC_TRACE("LXB", "Leave test_citizen\n");

        return outs;
    }
};

Server* server;

void* server_func(void*) {
    SharedPointer<IProcessor> xp(
            new MathProcessor(
                SharedPointer<Math>(
                    new MathImpl)));

    ServiceManager sm;
    sm.add_service(xp);

    ThreadPool tp;
    tp.init(10);
    server = new Server(&sm, &tp, 8503);
    if (0 != server->serve()) {
        return 0;
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    log_open("bgcc.cfg");
    Thread t(server_func);
    t.start();

    return 0;
}
