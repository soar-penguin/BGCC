#ifndef _BIDL2SL_MATH_H_
#define _BIDL2SL_MATH_H_

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bgcc.h>

#include "address.h"
namespace math {
    typedef bool b_t;
    extern const std::vector<bool>  ss1;
    extern const std::vector<int32_t>  ss2;
    extern const std::vector<std::string>  ss3;
    extern const std::vector<float>  ss4;
    extern const std::vector<std::set<int32_t> >  tt1;
    extern const std::set<bool>  sk1;
    extern const std::set<int32_t>  sk2;
    extern const std::set<std::string>  sk3;
    extern const std::set<float>  sk4;
    extern const std::set<std::vector<std::string> >  tt2;
    extern const std::map<int32_t, std::string>  sm1;
    extern const std::map<std::vector<int32_t> , std::set<std::string> >  tt3;
    extern const b_t be_used;
    extern const bool be_health;
    typedef int8_t i8_t;
    extern const i8_t i8;
    typedef int16_t i16_t;
    extern const i16_t i16;
    typedef int32_t i32_t;
    extern const i32_t i32;
    typedef int64_t i64_t;
    extern const i64_t i64;
    typedef std::string s_t;
    extern const s_t str;
    typedef std::string bin_t;
    extern const bin_t bin;
    typedef float f_t;
    extern const f_t f;
    class Person {
    public:
        Person();
        ~Person();

        std::string name;
        int32_t age;

        bool operator==(const Person& rhs) const;
        bool operator!=(const Person& rhs) const;
        bool operator< (const Person& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    typedef Person MyPerson;

    class Color {
    public:
        enum {
            RED = 0,
            GREEN = 1,
            BLUE = 2
        };

        Color();
        Color(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const Color& rhs) const;
        bool operator==(const Color& rhs) const;
        bool operator< (const Color& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const Color&);
    bool operator!=(int32_t value, const Color&);
    bool operator< (int32_t value, const Color&);
    std::ostream& operator<<(std::ostream& o, const Color&);

    typedef Color MyColor;

    class Gender {
    public:
        enum {
            MALE = 0,
            FEMALE = 1
        };

        Gender();
        Gender(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const Gender& rhs) const;
        bool operator==(const Gender& rhs) const;
        bool operator< (const Gender& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const Gender&);
    bool operator!=(int32_t value, const Gender&);
    bool operator< (int32_t value, const Gender&);
    std::ostream& operator<<(std::ostream& o, const Gender&);

    typedef std::vector<std::string>  Children;
    class Citizen {
    public:
        Citizen();
        ~Citizen();

        std::string name;
        int32_t age;
        Gender gender;
        common::Address address;
        Children children;
        std::set<i32_t>  xxx;
        std::map<int8_t, bool>  kkk;

        bool operator==(const Citizen& rhs) const;
        bool operator!=(const Citizen& rhs) const;
        bool operator< (const Citizen& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto);
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };


    class AddResult {
    public:
        enum {
            E_SUCCESS = 0,
            E_OVERFLOW = 1,
            E_DOWNFLOW = 2
        };

        AddResult();
        AddResult(int32_t value);

        int32_t get_value() const;
        std::string get_desc() const;

        bool operator==(int32_t value) const;
        bool operator!=(int32_t value) const;
        bool operator< (int32_t value) const;
        bool operator!=(const AddResult& rhs) const;
        bool operator==(const AddResult& rhs) const;
        bool operator< (const AddResult& rhs) const;

    private:
        int32_t _value;

        static const struct desc_t {
            int32_t value;
            const char* desc;
        } descs[];
    };
    bool operator==(int32_t value, const AddResult&);
    bool operator!=(int32_t value, const AddResult&);
    bool operator< (int32_t value, const AddResult&);
    std::ostream& operator<<(std::ostream& o, const AddResult&);

    class Math : public bgcc::Shareable {
    public:
        virtual ~Math() { }

        virtual void ping(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual AddResult add(
            int32_t a,
            int32_t b,
            int32_t & sum,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual Citizen test_citizen(
            const Citizen & ins,
            Citizen & outs,
            Citizen & alls,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual bool get_boolean(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual int8_t get_int8(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual int16_t get_int16(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual int32_t get_int32(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual int64_t get_int64(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual float get_float(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::string get_string(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::string get_binary(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual Color get_color(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::vector<int32_t>  get_sequence(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::set<std::string>  get_string_set(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::map<int64_t, std::string>  get_int_str_map(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::vector<std::set<bool> >  get_bool_set_sequence(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual Person get_person(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::vector<Person>  get_persons(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::set<Person>  get_persons2(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::map<Person, Person>  get_persons3(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::vector<std::set<Person> >  get_persons4(
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_bool(
            b_t value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_int8(
            i8_t value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_int16(
            i16_t value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_int32(
            i32_t value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_int64(
            i64_t value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_float(
            f_t value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_string(
            const s_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_binary(
            const bin_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_color(
            const Color & color,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_person(
            const MyPerson & person,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_int32_sequence(
            const std::vector<int32_t>  & numbers,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_persons(
            const std::vector<Person>  & persons,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_persons2(
            const std::set<Person>  & persons,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_int32_set_seq(
            const std::vector<std::set<int32_t> >  & xx,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_persons3(
            const std::map<Person, Person>  & persons,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void send_person_vec_set(
            const std::set<std::vector<Person> >  & xxx,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_boolean(
            bool & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_int8(
            int8_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_int16(
            int16_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_int32(
            int32_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_int64(
            int64_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_float(
            float & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_string(
            std::string & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_binary(
            std::string & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_person(
            Person & person,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_seq(
            std::vector<int32_t>  & xxx,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_string_set(
            std::set<std::string>  & xxx,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_int16_float_map(
            std::map<int16_t, float>  & xxx,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void out_int_vec_set(
            std::set<std::vector<int32_t> >  & xxx,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_boolean(
            bool & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_int8(
            int8_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_int16(
            int16_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_int32(
            int32_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_int64(
            int64_t & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_float(
            float & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_string(
            std::string & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_binary(
            std::string & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_int32_seq(
            std::vector<int32_t>  & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_person(
            Person & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_int32_set(
            std::set<int32_t>  & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_person_seq(
            std::vector<Person>  & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void all_int32_person_map(
            std::map<int32_t, Person>  & value,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual void color_out_all(
            MyColor & color1,
            MyColor & color2,
            const std::map<std::string, std::string>& ctx) = 0;

        virtual std::vector<MyColor>  color_xx(
            const std::set<MyColor>  & color1,
            std::vector<MyColor>  & color2,
            std::map<MyColor, MyColor>  & color3,
            const std::map<std::string, std::string>& ctx) = 0;

    };

    class Math_ping_args {
    public:
        Math_ping_args();
        virtual ~Math_ping_args();

        bool operator==(const Math_ping_args& rhs) const;
        bool operator!=(const Math_ping_args& rhs) const;
        bool operator< (const Math_ping_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_add_args {
    public:
        Math_add_args();
        virtual ~Math_add_args();

        int32_t a;
        int32_t b;

        bool operator==(const Math_add_args& rhs) const;
        bool operator!=(const Math_add_args& rhs) const;
        bool operator< (const Math_add_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_test_citizen_args {
    public:
        Math_test_citizen_args();
        virtual ~Math_test_citizen_args();

        Citizen ins;
        Citizen alls;

        bool operator==(const Math_test_citizen_args& rhs) const;
        bool operator!=(const Math_test_citizen_args& rhs) const;
        bool operator< (const Math_test_citizen_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_boolean_args {
    public:
        Math_get_boolean_args();
        virtual ~Math_get_boolean_args();

        bool operator==(const Math_get_boolean_args& rhs) const;
        bool operator!=(const Math_get_boolean_args& rhs) const;
        bool operator< (const Math_get_boolean_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_int8_args {
    public:
        Math_get_int8_args();
        virtual ~Math_get_int8_args();

        bool operator==(const Math_get_int8_args& rhs) const;
        bool operator!=(const Math_get_int8_args& rhs) const;
        bool operator< (const Math_get_int8_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_int16_args {
    public:
        Math_get_int16_args();
        virtual ~Math_get_int16_args();

        bool operator==(const Math_get_int16_args& rhs) const;
        bool operator!=(const Math_get_int16_args& rhs) const;
        bool operator< (const Math_get_int16_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_int32_args {
    public:
        Math_get_int32_args();
        virtual ~Math_get_int32_args();

        bool operator==(const Math_get_int32_args& rhs) const;
        bool operator!=(const Math_get_int32_args& rhs) const;
        bool operator< (const Math_get_int32_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_int64_args {
    public:
        Math_get_int64_args();
        virtual ~Math_get_int64_args();

        bool operator==(const Math_get_int64_args& rhs) const;
        bool operator!=(const Math_get_int64_args& rhs) const;
        bool operator< (const Math_get_int64_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_float_args {
    public:
        Math_get_float_args();
        virtual ~Math_get_float_args();

        bool operator==(const Math_get_float_args& rhs) const;
        bool operator!=(const Math_get_float_args& rhs) const;
        bool operator< (const Math_get_float_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_string_args {
    public:
        Math_get_string_args();
        virtual ~Math_get_string_args();

        bool operator==(const Math_get_string_args& rhs) const;
        bool operator!=(const Math_get_string_args& rhs) const;
        bool operator< (const Math_get_string_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_binary_args {
    public:
        Math_get_binary_args();
        virtual ~Math_get_binary_args();

        bool operator==(const Math_get_binary_args& rhs) const;
        bool operator!=(const Math_get_binary_args& rhs) const;
        bool operator< (const Math_get_binary_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_color_args {
    public:
        Math_get_color_args();
        virtual ~Math_get_color_args();

        bool operator==(const Math_get_color_args& rhs) const;
        bool operator!=(const Math_get_color_args& rhs) const;
        bool operator< (const Math_get_color_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_sequence_args {
    public:
        Math_get_sequence_args();
        virtual ~Math_get_sequence_args();

        bool operator==(const Math_get_sequence_args& rhs) const;
        bool operator!=(const Math_get_sequence_args& rhs) const;
        bool operator< (const Math_get_sequence_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_string_set_args {
    public:
        Math_get_string_set_args();
        virtual ~Math_get_string_set_args();

        bool operator==(const Math_get_string_set_args& rhs) const;
        bool operator!=(const Math_get_string_set_args& rhs) const;
        bool operator< (const Math_get_string_set_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_int_str_map_args {
    public:
        Math_get_int_str_map_args();
        virtual ~Math_get_int_str_map_args();

        bool operator==(const Math_get_int_str_map_args& rhs) const;
        bool operator!=(const Math_get_int_str_map_args& rhs) const;
        bool operator< (const Math_get_int_str_map_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_bool_set_sequence_args {
    public:
        Math_get_bool_set_sequence_args();
        virtual ~Math_get_bool_set_sequence_args();

        bool operator==(const Math_get_bool_set_sequence_args& rhs) const;
        bool operator!=(const Math_get_bool_set_sequence_args& rhs) const;
        bool operator< (const Math_get_bool_set_sequence_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_person_args {
    public:
        Math_get_person_args();
        virtual ~Math_get_person_args();

        bool operator==(const Math_get_person_args& rhs) const;
        bool operator!=(const Math_get_person_args& rhs) const;
        bool operator< (const Math_get_person_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_persons_args {
    public:
        Math_get_persons_args();
        virtual ~Math_get_persons_args();

        bool operator==(const Math_get_persons_args& rhs) const;
        bool operator!=(const Math_get_persons_args& rhs) const;
        bool operator< (const Math_get_persons_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_persons2_args {
    public:
        Math_get_persons2_args();
        virtual ~Math_get_persons2_args();

        bool operator==(const Math_get_persons2_args& rhs) const;
        bool operator!=(const Math_get_persons2_args& rhs) const;
        bool operator< (const Math_get_persons2_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_persons3_args {
    public:
        Math_get_persons3_args();
        virtual ~Math_get_persons3_args();

        bool operator==(const Math_get_persons3_args& rhs) const;
        bool operator!=(const Math_get_persons3_args& rhs) const;
        bool operator< (const Math_get_persons3_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_get_persons4_args {
    public:
        Math_get_persons4_args();
        virtual ~Math_get_persons4_args();

        bool operator==(const Math_get_persons4_args& rhs) const;
        bool operator!=(const Math_get_persons4_args& rhs) const;
        bool operator< (const Math_get_persons4_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_bool_args {
    public:
        Math_send_bool_args();
        virtual ~Math_send_bool_args();

        b_t value;

        bool operator==(const Math_send_bool_args& rhs) const;
        bool operator!=(const Math_send_bool_args& rhs) const;
        bool operator< (const Math_send_bool_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_int8_args {
    public:
        Math_send_int8_args();
        virtual ~Math_send_int8_args();

        i8_t value;

        bool operator==(const Math_send_int8_args& rhs) const;
        bool operator!=(const Math_send_int8_args& rhs) const;
        bool operator< (const Math_send_int8_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_int16_args {
    public:
        Math_send_int16_args();
        virtual ~Math_send_int16_args();

        i16_t value;

        bool operator==(const Math_send_int16_args& rhs) const;
        bool operator!=(const Math_send_int16_args& rhs) const;
        bool operator< (const Math_send_int16_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_int32_args {
    public:
        Math_send_int32_args();
        virtual ~Math_send_int32_args();

        i32_t value;

        bool operator==(const Math_send_int32_args& rhs) const;
        bool operator!=(const Math_send_int32_args& rhs) const;
        bool operator< (const Math_send_int32_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_int64_args {
    public:
        Math_send_int64_args();
        virtual ~Math_send_int64_args();

        i64_t value;

        bool operator==(const Math_send_int64_args& rhs) const;
        bool operator!=(const Math_send_int64_args& rhs) const;
        bool operator< (const Math_send_int64_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_float_args {
    public:
        Math_send_float_args();
        virtual ~Math_send_float_args();

        f_t value;

        bool operator==(const Math_send_float_args& rhs) const;
        bool operator!=(const Math_send_float_args& rhs) const;
        bool operator< (const Math_send_float_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_string_args {
    public:
        Math_send_string_args();
        virtual ~Math_send_string_args();

        s_t value;

        bool operator==(const Math_send_string_args& rhs) const;
        bool operator!=(const Math_send_string_args& rhs) const;
        bool operator< (const Math_send_string_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_binary_args {
    public:
        Math_send_binary_args();
        virtual ~Math_send_binary_args();

        bin_t value;

        bool operator==(const Math_send_binary_args& rhs) const;
        bool operator!=(const Math_send_binary_args& rhs) const;
        bool operator< (const Math_send_binary_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_color_args {
    public:
        Math_send_color_args();
        virtual ~Math_send_color_args();

        Color color;

        bool operator==(const Math_send_color_args& rhs) const;
        bool operator!=(const Math_send_color_args& rhs) const;
        bool operator< (const Math_send_color_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_person_args {
    public:
        Math_send_person_args();
        virtual ~Math_send_person_args();

        MyPerson person;

        bool operator==(const Math_send_person_args& rhs) const;
        bool operator!=(const Math_send_person_args& rhs) const;
        bool operator< (const Math_send_person_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_int32_sequence_args {
    public:
        Math_send_int32_sequence_args();
        virtual ~Math_send_int32_sequence_args();

        std::vector<int32_t>  numbers;

        bool operator==(const Math_send_int32_sequence_args& rhs) const;
        bool operator!=(const Math_send_int32_sequence_args& rhs) const;
        bool operator< (const Math_send_int32_sequence_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_persons_args {
    public:
        Math_send_persons_args();
        virtual ~Math_send_persons_args();

        std::vector<Person>  persons;

        bool operator==(const Math_send_persons_args& rhs) const;
        bool operator!=(const Math_send_persons_args& rhs) const;
        bool operator< (const Math_send_persons_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_persons2_args {
    public:
        Math_send_persons2_args();
        virtual ~Math_send_persons2_args();

        std::set<Person>  persons;

        bool operator==(const Math_send_persons2_args& rhs) const;
        bool operator!=(const Math_send_persons2_args& rhs) const;
        bool operator< (const Math_send_persons2_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_int32_set_seq_args {
    public:
        Math_send_int32_set_seq_args();
        virtual ~Math_send_int32_set_seq_args();

        std::vector<std::set<int32_t> >  xx;

        bool operator==(const Math_send_int32_set_seq_args& rhs) const;
        bool operator!=(const Math_send_int32_set_seq_args& rhs) const;
        bool operator< (const Math_send_int32_set_seq_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_persons3_args {
    public:
        Math_send_persons3_args();
        virtual ~Math_send_persons3_args();

        std::map<Person, Person>  persons;

        bool operator==(const Math_send_persons3_args& rhs) const;
        bool operator!=(const Math_send_persons3_args& rhs) const;
        bool operator< (const Math_send_persons3_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_send_person_vec_set_args {
    public:
        Math_send_person_vec_set_args();
        virtual ~Math_send_person_vec_set_args();

        std::set<std::vector<Person> >  xxx;

        bool operator==(const Math_send_person_vec_set_args& rhs) const;
        bool operator!=(const Math_send_person_vec_set_args& rhs) const;
        bool operator< (const Math_send_person_vec_set_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_boolean_args {
    public:
        Math_out_boolean_args();
        virtual ~Math_out_boolean_args();


        bool operator==(const Math_out_boolean_args& rhs) const;
        bool operator!=(const Math_out_boolean_args& rhs) const;
        bool operator< (const Math_out_boolean_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_int8_args {
    public:
        Math_out_int8_args();
        virtual ~Math_out_int8_args();


        bool operator==(const Math_out_int8_args& rhs) const;
        bool operator!=(const Math_out_int8_args& rhs) const;
        bool operator< (const Math_out_int8_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_int16_args {
    public:
        Math_out_int16_args();
        virtual ~Math_out_int16_args();


        bool operator==(const Math_out_int16_args& rhs) const;
        bool operator!=(const Math_out_int16_args& rhs) const;
        bool operator< (const Math_out_int16_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_int32_args {
    public:
        Math_out_int32_args();
        virtual ~Math_out_int32_args();


        bool operator==(const Math_out_int32_args& rhs) const;
        bool operator!=(const Math_out_int32_args& rhs) const;
        bool operator< (const Math_out_int32_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_int64_args {
    public:
        Math_out_int64_args();
        virtual ~Math_out_int64_args();


        bool operator==(const Math_out_int64_args& rhs) const;
        bool operator!=(const Math_out_int64_args& rhs) const;
        bool operator< (const Math_out_int64_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_float_args {
    public:
        Math_out_float_args();
        virtual ~Math_out_float_args();


        bool operator==(const Math_out_float_args& rhs) const;
        bool operator!=(const Math_out_float_args& rhs) const;
        bool operator< (const Math_out_float_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_string_args {
    public:
        Math_out_string_args();
        virtual ~Math_out_string_args();


        bool operator==(const Math_out_string_args& rhs) const;
        bool operator!=(const Math_out_string_args& rhs) const;
        bool operator< (const Math_out_string_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_binary_args {
    public:
        Math_out_binary_args();
        virtual ~Math_out_binary_args();


        bool operator==(const Math_out_binary_args& rhs) const;
        bool operator!=(const Math_out_binary_args& rhs) const;
        bool operator< (const Math_out_binary_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_person_args {
    public:
        Math_out_person_args();
        virtual ~Math_out_person_args();


        bool operator==(const Math_out_person_args& rhs) const;
        bool operator!=(const Math_out_person_args& rhs) const;
        bool operator< (const Math_out_person_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_seq_args {
    public:
        Math_out_seq_args();
        virtual ~Math_out_seq_args();


        bool operator==(const Math_out_seq_args& rhs) const;
        bool operator!=(const Math_out_seq_args& rhs) const;
        bool operator< (const Math_out_seq_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_string_set_args {
    public:
        Math_out_string_set_args();
        virtual ~Math_out_string_set_args();


        bool operator==(const Math_out_string_set_args& rhs) const;
        bool operator!=(const Math_out_string_set_args& rhs) const;
        bool operator< (const Math_out_string_set_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_int16_float_map_args {
    public:
        Math_out_int16_float_map_args();
        virtual ~Math_out_int16_float_map_args();


        bool operator==(const Math_out_int16_float_map_args& rhs) const;
        bool operator!=(const Math_out_int16_float_map_args& rhs) const;
        bool operator< (const Math_out_int16_float_map_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_out_int_vec_set_args {
    public:
        Math_out_int_vec_set_args();
        virtual ~Math_out_int_vec_set_args();


        bool operator==(const Math_out_int_vec_set_args& rhs) const;
        bool operator!=(const Math_out_int_vec_set_args& rhs) const;
        bool operator< (const Math_out_int_vec_set_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_boolean_args {
    public:
        Math_all_boolean_args();
        virtual ~Math_all_boolean_args();

        bool value;

        bool operator==(const Math_all_boolean_args& rhs) const;
        bool operator!=(const Math_all_boolean_args& rhs) const;
        bool operator< (const Math_all_boolean_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_int8_args {
    public:
        Math_all_int8_args();
        virtual ~Math_all_int8_args();

        int8_t value;

        bool operator==(const Math_all_int8_args& rhs) const;
        bool operator!=(const Math_all_int8_args& rhs) const;
        bool operator< (const Math_all_int8_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_int16_args {
    public:
        Math_all_int16_args();
        virtual ~Math_all_int16_args();

        int16_t value;

        bool operator==(const Math_all_int16_args& rhs) const;
        bool operator!=(const Math_all_int16_args& rhs) const;
        bool operator< (const Math_all_int16_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_int32_args {
    public:
        Math_all_int32_args();
        virtual ~Math_all_int32_args();

        int32_t value;

        bool operator==(const Math_all_int32_args& rhs) const;
        bool operator!=(const Math_all_int32_args& rhs) const;
        bool operator< (const Math_all_int32_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_int64_args {
    public:
        Math_all_int64_args();
        virtual ~Math_all_int64_args();

        int64_t value;

        bool operator==(const Math_all_int64_args& rhs) const;
        bool operator!=(const Math_all_int64_args& rhs) const;
        bool operator< (const Math_all_int64_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_float_args {
    public:
        Math_all_float_args();
        virtual ~Math_all_float_args();

        float value;

        bool operator==(const Math_all_float_args& rhs) const;
        bool operator!=(const Math_all_float_args& rhs) const;
        bool operator< (const Math_all_float_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_string_args {
    public:
        Math_all_string_args();
        virtual ~Math_all_string_args();

        std::string value;

        bool operator==(const Math_all_string_args& rhs) const;
        bool operator!=(const Math_all_string_args& rhs) const;
        bool operator< (const Math_all_string_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_binary_args {
    public:
        Math_all_binary_args();
        virtual ~Math_all_binary_args();

        std::string value;

        bool operator==(const Math_all_binary_args& rhs) const;
        bool operator!=(const Math_all_binary_args& rhs) const;
        bool operator< (const Math_all_binary_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_int32_seq_args {
    public:
        Math_all_int32_seq_args();
        virtual ~Math_all_int32_seq_args();

        std::vector<int32_t>  value;

        bool operator==(const Math_all_int32_seq_args& rhs) const;
        bool operator!=(const Math_all_int32_seq_args& rhs) const;
        bool operator< (const Math_all_int32_seq_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_person_args {
    public:
        Math_all_person_args();
        virtual ~Math_all_person_args();

        Person value;

        bool operator==(const Math_all_person_args& rhs) const;
        bool operator!=(const Math_all_person_args& rhs) const;
        bool operator< (const Math_all_person_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_int32_set_args {
    public:
        Math_all_int32_set_args();
        virtual ~Math_all_int32_set_args();

        std::set<int32_t>  value;

        bool operator==(const Math_all_int32_set_args& rhs) const;
        bool operator!=(const Math_all_int32_set_args& rhs) const;
        bool operator< (const Math_all_int32_set_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_person_seq_args {
    public:
        Math_all_person_seq_args();
        virtual ~Math_all_person_seq_args();

        std::vector<Person>  value;

        bool operator==(const Math_all_person_seq_args& rhs) const;
        bool operator!=(const Math_all_person_seq_args& rhs) const;
        bool operator< (const Math_all_person_seq_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_all_int32_person_map_args {
    public:
        Math_all_int32_person_map_args();
        virtual ~Math_all_int32_person_map_args();

        std::map<int32_t, Person>  value;

        bool operator==(const Math_all_int32_person_map_args& rhs) const;
        bool operator!=(const Math_all_int32_person_map_args& rhs) const;
        bool operator< (const Math_all_int32_person_map_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_color_out_all_args {
    public:
        Math_color_out_all_args();
        virtual ~Math_color_out_all_args();

        MyColor color1;

        bool operator==(const Math_color_out_all_args& rhs) const;
        bool operator!=(const Math_color_out_all_args& rhs) const;
        bool operator< (const Math_color_out_all_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_color_xx_args {
    public:
        Math_color_xx_args();
        virtual ~Math_color_xx_args();

        std::set<MyColor>  color1;
        std::map<MyColor, MyColor>  color3;

        bool operator==(const Math_color_xx_args& rhs) const;
        bool operator!=(const Math_color_xx_args& rhs) const;
        bool operator< (const Math_color_xx_args& rhs) const;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len);
    };

    class Math_ping_pargs {
    public:
        virtual ~Math_ping_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_add_pargs {
    public:
        virtual ~Math_add_pargs();

        const int32_t* a;
        const int32_t* b;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_test_citizen_pargs {
    public:
        virtual ~Math_test_citizen_pargs();

        const Citizen* ins;
        const Citizen* alls;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_boolean_pargs {
    public:
        virtual ~Math_get_boolean_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int8_pargs {
    public:
        virtual ~Math_get_int8_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int16_pargs {
    public:
        virtual ~Math_get_int16_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int32_pargs {
    public:
        virtual ~Math_get_int32_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int64_pargs {
    public:
        virtual ~Math_get_int64_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_float_pargs {
    public:
        virtual ~Math_get_float_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_string_pargs {
    public:
        virtual ~Math_get_string_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_binary_pargs {
    public:
        virtual ~Math_get_binary_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_color_pargs {
    public:
        virtual ~Math_get_color_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_sequence_pargs {
    public:
        virtual ~Math_get_sequence_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_string_set_pargs {
    public:
        virtual ~Math_get_string_set_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int_str_map_pargs {
    public:
        virtual ~Math_get_int_str_map_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_bool_set_sequence_pargs {
    public:
        virtual ~Math_get_bool_set_sequence_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_person_pargs {
    public:
        virtual ~Math_get_person_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons_pargs {
    public:
        virtual ~Math_get_persons_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons2_pargs {
    public:
        virtual ~Math_get_persons2_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons3_pargs {
    public:
        virtual ~Math_get_persons3_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons4_pargs {
    public:
        virtual ~Math_get_persons4_pargs();

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_bool_pargs {
    public:
        virtual ~Math_send_bool_pargs();

        const b_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int8_pargs {
    public:
        virtual ~Math_send_int8_pargs();

        const i8_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int16_pargs {
    public:
        virtual ~Math_send_int16_pargs();

        const i16_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_pargs {
    public:
        virtual ~Math_send_int32_pargs();

        const i32_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int64_pargs {
    public:
        virtual ~Math_send_int64_pargs();

        const i64_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_float_pargs {
    public:
        virtual ~Math_send_float_pargs();

        const f_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_string_pargs {
    public:
        virtual ~Math_send_string_pargs();

        const s_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_binary_pargs {
    public:
        virtual ~Math_send_binary_pargs();

        const bin_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_color_pargs {
    public:
        virtual ~Math_send_color_pargs();

        const Color* color;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_person_pargs {
    public:
        virtual ~Math_send_person_pargs();

        const MyPerson* person;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_sequence_pargs {
    public:
        virtual ~Math_send_int32_sequence_pargs();

        const std::vector<int32_t> * numbers;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons_pargs {
    public:
        virtual ~Math_send_persons_pargs();

        const std::vector<Person> * persons;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons2_pargs {
    public:
        virtual ~Math_send_persons2_pargs();

        const std::set<Person> * persons;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_set_seq_pargs {
    public:
        virtual ~Math_send_int32_set_seq_pargs();

        const std::vector<std::set<int32_t> > * xx;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons3_pargs {
    public:
        virtual ~Math_send_persons3_pargs();

        const std::map<Person, Person> * persons;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_person_vec_set_pargs {
    public:
        virtual ~Math_send_person_vec_set_pargs();

        const std::set<std::vector<Person> > * xxx;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_boolean_pargs {
    public:
        virtual ~Math_out_boolean_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int8_pargs {
    public:
        virtual ~Math_out_int8_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int16_pargs {
    public:
        virtual ~Math_out_int16_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int32_pargs {
    public:
        virtual ~Math_out_int32_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int64_pargs {
    public:
        virtual ~Math_out_int64_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_float_pargs {
    public:
        virtual ~Math_out_float_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_string_pargs {
    public:
        virtual ~Math_out_string_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_binary_pargs {
    public:
        virtual ~Math_out_binary_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_person_pargs {
    public:
        virtual ~Math_out_person_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_seq_pargs {
    public:
        virtual ~Math_out_seq_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_string_set_pargs {
    public:
        virtual ~Math_out_string_set_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int16_float_map_pargs {
    public:
        virtual ~Math_out_int16_float_map_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int_vec_set_pargs {
    public:
        virtual ~Math_out_int_vec_set_pargs();


        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_boolean_pargs {
    public:
        virtual ~Math_all_boolean_pargs();

        const bool* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int8_pargs {
    public:
        virtual ~Math_all_int8_pargs();

        const int8_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int16_pargs {
    public:
        virtual ~Math_all_int16_pargs();

        const int16_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_pargs {
    public:
        virtual ~Math_all_int32_pargs();

        const int32_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int64_pargs {
    public:
        virtual ~Math_all_int64_pargs();

        const int64_t* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_float_pargs {
    public:
        virtual ~Math_all_float_pargs();

        const float* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_string_pargs {
    public:
        virtual ~Math_all_string_pargs();

        const std::string* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_binary_pargs {
    public:
        virtual ~Math_all_binary_pargs();

        const std::string* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_seq_pargs {
    public:
        virtual ~Math_all_int32_seq_pargs();

        const std::vector<int32_t> * value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_person_pargs {
    public:
        virtual ~Math_all_person_pargs();

        const Person* value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_set_pargs {
    public:
        virtual ~Math_all_int32_set_pargs();

        const std::set<int32_t> * value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_person_seq_pargs {
    public:
        virtual ~Math_all_person_seq_pargs();

        const std::vector<Person> * value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_person_map_pargs {
    public:
        virtual ~Math_all_int32_person_map_pargs();

        const std::map<int32_t, Person> * value;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_color_out_all_pargs {
    public:
        virtual ~Math_color_out_all_pargs();

        const MyColor* color1;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_color_xx_pargs {
    public:
        virtual ~Math_color_xx_pargs();

        const std::set<MyColor> * color1;
        const std::map<MyColor, MyColor> * color3;

        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_ping_result {
    public:
        Math_ping_result();
        virtual ~Math_ping_result();

        bool operator==(const Math_ping_result& rhs) const;
        bool operator!=(const Math_ping_result& rhs) const;
        bool operator< (const Math_ping_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_add_result {
    public:
        Math_add_result();
        virtual ~Math_add_result();

        AddResult return_value;
        int32_t sum;

        bool operator==(const Math_add_result& rhs) const;
        bool operator!=(const Math_add_result& rhs) const;
        bool operator< (const Math_add_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_test_citizen_result {
    public:
        Math_test_citizen_result();
        virtual ~Math_test_citizen_result();

        Citizen return_value;
        Citizen outs;
        Citizen alls;

        bool operator==(const Math_test_citizen_result& rhs) const;
        bool operator!=(const Math_test_citizen_result& rhs) const;
        bool operator< (const Math_test_citizen_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_boolean_result {
    public:
        Math_get_boolean_result();
        virtual ~Math_get_boolean_result();

        bool return_value;
        bool operator==(const Math_get_boolean_result& rhs) const;
        bool operator!=(const Math_get_boolean_result& rhs) const;
        bool operator< (const Math_get_boolean_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int8_result {
    public:
        Math_get_int8_result();
        virtual ~Math_get_int8_result();

        int8_t return_value;
        bool operator==(const Math_get_int8_result& rhs) const;
        bool operator!=(const Math_get_int8_result& rhs) const;
        bool operator< (const Math_get_int8_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int16_result {
    public:
        Math_get_int16_result();
        virtual ~Math_get_int16_result();

        int16_t return_value;
        bool operator==(const Math_get_int16_result& rhs) const;
        bool operator!=(const Math_get_int16_result& rhs) const;
        bool operator< (const Math_get_int16_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int32_result {
    public:
        Math_get_int32_result();
        virtual ~Math_get_int32_result();

        int32_t return_value;
        bool operator==(const Math_get_int32_result& rhs) const;
        bool operator!=(const Math_get_int32_result& rhs) const;
        bool operator< (const Math_get_int32_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int64_result {
    public:
        Math_get_int64_result();
        virtual ~Math_get_int64_result();

        int64_t return_value;
        bool operator==(const Math_get_int64_result& rhs) const;
        bool operator!=(const Math_get_int64_result& rhs) const;
        bool operator< (const Math_get_int64_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_float_result {
    public:
        Math_get_float_result();
        virtual ~Math_get_float_result();

        float return_value;
        bool operator==(const Math_get_float_result& rhs) const;
        bool operator!=(const Math_get_float_result& rhs) const;
        bool operator< (const Math_get_float_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_string_result {
    public:
        Math_get_string_result();
        virtual ~Math_get_string_result();

        std::string return_value;
        bool operator==(const Math_get_string_result& rhs) const;
        bool operator!=(const Math_get_string_result& rhs) const;
        bool operator< (const Math_get_string_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_binary_result {
    public:
        Math_get_binary_result();
        virtual ~Math_get_binary_result();

        std::string return_value;
        bool operator==(const Math_get_binary_result& rhs) const;
        bool operator!=(const Math_get_binary_result& rhs) const;
        bool operator< (const Math_get_binary_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_color_result {
    public:
        Math_get_color_result();
        virtual ~Math_get_color_result();

        Color return_value;
        bool operator==(const Math_get_color_result& rhs) const;
        bool operator!=(const Math_get_color_result& rhs) const;
        bool operator< (const Math_get_color_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_sequence_result {
    public:
        Math_get_sequence_result();
        virtual ~Math_get_sequence_result();

        std::vector<int32_t>  return_value;
        bool operator==(const Math_get_sequence_result& rhs) const;
        bool operator!=(const Math_get_sequence_result& rhs) const;
        bool operator< (const Math_get_sequence_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_string_set_result {
    public:
        Math_get_string_set_result();
        virtual ~Math_get_string_set_result();

        std::set<std::string>  return_value;
        bool operator==(const Math_get_string_set_result& rhs) const;
        bool operator!=(const Math_get_string_set_result& rhs) const;
        bool operator< (const Math_get_string_set_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int_str_map_result {
    public:
        Math_get_int_str_map_result();
        virtual ~Math_get_int_str_map_result();

        std::map<int64_t, std::string>  return_value;
        bool operator==(const Math_get_int_str_map_result& rhs) const;
        bool operator!=(const Math_get_int_str_map_result& rhs) const;
        bool operator< (const Math_get_int_str_map_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_bool_set_sequence_result {
    public:
        Math_get_bool_set_sequence_result();
        virtual ~Math_get_bool_set_sequence_result();

        std::vector<std::set<bool> >  return_value;
        bool operator==(const Math_get_bool_set_sequence_result& rhs) const;
        bool operator!=(const Math_get_bool_set_sequence_result& rhs) const;
        bool operator< (const Math_get_bool_set_sequence_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_person_result {
    public:
        Math_get_person_result();
        virtual ~Math_get_person_result();

        Person return_value;
        bool operator==(const Math_get_person_result& rhs) const;
        bool operator!=(const Math_get_person_result& rhs) const;
        bool operator< (const Math_get_person_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons_result {
    public:
        Math_get_persons_result();
        virtual ~Math_get_persons_result();

        std::vector<Person>  return_value;
        bool operator==(const Math_get_persons_result& rhs) const;
        bool operator!=(const Math_get_persons_result& rhs) const;
        bool operator< (const Math_get_persons_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons2_result {
    public:
        Math_get_persons2_result();
        virtual ~Math_get_persons2_result();

        std::set<Person>  return_value;
        bool operator==(const Math_get_persons2_result& rhs) const;
        bool operator!=(const Math_get_persons2_result& rhs) const;
        bool operator< (const Math_get_persons2_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons3_result {
    public:
        Math_get_persons3_result();
        virtual ~Math_get_persons3_result();

        std::map<Person, Person>  return_value;
        bool operator==(const Math_get_persons3_result& rhs) const;
        bool operator!=(const Math_get_persons3_result& rhs) const;
        bool operator< (const Math_get_persons3_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons4_result {
    public:
        Math_get_persons4_result();
        virtual ~Math_get_persons4_result();

        std::vector<std::set<Person> >  return_value;
        bool operator==(const Math_get_persons4_result& rhs) const;
        bool operator!=(const Math_get_persons4_result& rhs) const;
        bool operator< (const Math_get_persons4_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_bool_result {
    public:
        Math_send_bool_result();
        virtual ~Math_send_bool_result();


        bool operator==(const Math_send_bool_result& rhs) const;
        bool operator!=(const Math_send_bool_result& rhs) const;
        bool operator< (const Math_send_bool_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int8_result {
    public:
        Math_send_int8_result();
        virtual ~Math_send_int8_result();


        bool operator==(const Math_send_int8_result& rhs) const;
        bool operator!=(const Math_send_int8_result& rhs) const;
        bool operator< (const Math_send_int8_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int16_result {
    public:
        Math_send_int16_result();
        virtual ~Math_send_int16_result();


        bool operator==(const Math_send_int16_result& rhs) const;
        bool operator!=(const Math_send_int16_result& rhs) const;
        bool operator< (const Math_send_int16_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_result {
    public:
        Math_send_int32_result();
        virtual ~Math_send_int32_result();


        bool operator==(const Math_send_int32_result& rhs) const;
        bool operator!=(const Math_send_int32_result& rhs) const;
        bool operator< (const Math_send_int32_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int64_result {
    public:
        Math_send_int64_result();
        virtual ~Math_send_int64_result();


        bool operator==(const Math_send_int64_result& rhs) const;
        bool operator!=(const Math_send_int64_result& rhs) const;
        bool operator< (const Math_send_int64_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_float_result {
    public:
        Math_send_float_result();
        virtual ~Math_send_float_result();


        bool operator==(const Math_send_float_result& rhs) const;
        bool operator!=(const Math_send_float_result& rhs) const;
        bool operator< (const Math_send_float_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_string_result {
    public:
        Math_send_string_result();
        virtual ~Math_send_string_result();


        bool operator==(const Math_send_string_result& rhs) const;
        bool operator!=(const Math_send_string_result& rhs) const;
        bool operator< (const Math_send_string_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_binary_result {
    public:
        Math_send_binary_result();
        virtual ~Math_send_binary_result();


        bool operator==(const Math_send_binary_result& rhs) const;
        bool operator!=(const Math_send_binary_result& rhs) const;
        bool operator< (const Math_send_binary_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_color_result {
    public:
        Math_send_color_result();
        virtual ~Math_send_color_result();


        bool operator==(const Math_send_color_result& rhs) const;
        bool operator!=(const Math_send_color_result& rhs) const;
        bool operator< (const Math_send_color_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_person_result {
    public:
        Math_send_person_result();
        virtual ~Math_send_person_result();


        bool operator==(const Math_send_person_result& rhs) const;
        bool operator!=(const Math_send_person_result& rhs) const;
        bool operator< (const Math_send_person_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_sequence_result {
    public:
        Math_send_int32_sequence_result();
        virtual ~Math_send_int32_sequence_result();


        bool operator==(const Math_send_int32_sequence_result& rhs) const;
        bool operator!=(const Math_send_int32_sequence_result& rhs) const;
        bool operator< (const Math_send_int32_sequence_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons_result {
    public:
        Math_send_persons_result();
        virtual ~Math_send_persons_result();


        bool operator==(const Math_send_persons_result& rhs) const;
        bool operator!=(const Math_send_persons_result& rhs) const;
        bool operator< (const Math_send_persons_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons2_result {
    public:
        Math_send_persons2_result();
        virtual ~Math_send_persons2_result();


        bool operator==(const Math_send_persons2_result& rhs) const;
        bool operator!=(const Math_send_persons2_result& rhs) const;
        bool operator< (const Math_send_persons2_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_set_seq_result {
    public:
        Math_send_int32_set_seq_result();
        virtual ~Math_send_int32_set_seq_result();


        bool operator==(const Math_send_int32_set_seq_result& rhs) const;
        bool operator!=(const Math_send_int32_set_seq_result& rhs) const;
        bool operator< (const Math_send_int32_set_seq_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons3_result {
    public:
        Math_send_persons3_result();
        virtual ~Math_send_persons3_result();


        bool operator==(const Math_send_persons3_result& rhs) const;
        bool operator!=(const Math_send_persons3_result& rhs) const;
        bool operator< (const Math_send_persons3_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_person_vec_set_result {
    public:
        Math_send_person_vec_set_result();
        virtual ~Math_send_person_vec_set_result();


        bool operator==(const Math_send_person_vec_set_result& rhs) const;
        bool operator!=(const Math_send_person_vec_set_result& rhs) const;
        bool operator< (const Math_send_person_vec_set_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_boolean_result {
    public:
        Math_out_boolean_result();
        virtual ~Math_out_boolean_result();

        bool value;

        bool operator==(const Math_out_boolean_result& rhs) const;
        bool operator!=(const Math_out_boolean_result& rhs) const;
        bool operator< (const Math_out_boolean_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int8_result {
    public:
        Math_out_int8_result();
        virtual ~Math_out_int8_result();

        int8_t value;

        bool operator==(const Math_out_int8_result& rhs) const;
        bool operator!=(const Math_out_int8_result& rhs) const;
        bool operator< (const Math_out_int8_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int16_result {
    public:
        Math_out_int16_result();
        virtual ~Math_out_int16_result();

        int16_t value;

        bool operator==(const Math_out_int16_result& rhs) const;
        bool operator!=(const Math_out_int16_result& rhs) const;
        bool operator< (const Math_out_int16_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int32_result {
    public:
        Math_out_int32_result();
        virtual ~Math_out_int32_result();

        int32_t value;

        bool operator==(const Math_out_int32_result& rhs) const;
        bool operator!=(const Math_out_int32_result& rhs) const;
        bool operator< (const Math_out_int32_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int64_result {
    public:
        Math_out_int64_result();
        virtual ~Math_out_int64_result();

        int64_t value;

        bool operator==(const Math_out_int64_result& rhs) const;
        bool operator!=(const Math_out_int64_result& rhs) const;
        bool operator< (const Math_out_int64_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_float_result {
    public:
        Math_out_float_result();
        virtual ~Math_out_float_result();

        float value;

        bool operator==(const Math_out_float_result& rhs) const;
        bool operator!=(const Math_out_float_result& rhs) const;
        bool operator< (const Math_out_float_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_string_result {
    public:
        Math_out_string_result();
        virtual ~Math_out_string_result();

        std::string value;

        bool operator==(const Math_out_string_result& rhs) const;
        bool operator!=(const Math_out_string_result& rhs) const;
        bool operator< (const Math_out_string_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_binary_result {
    public:
        Math_out_binary_result();
        virtual ~Math_out_binary_result();

        std::string value;

        bool operator==(const Math_out_binary_result& rhs) const;
        bool operator!=(const Math_out_binary_result& rhs) const;
        bool operator< (const Math_out_binary_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_person_result {
    public:
        Math_out_person_result();
        virtual ~Math_out_person_result();

        Person person;

        bool operator==(const Math_out_person_result& rhs) const;
        bool operator!=(const Math_out_person_result& rhs) const;
        bool operator< (const Math_out_person_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_seq_result {
    public:
        Math_out_seq_result();
        virtual ~Math_out_seq_result();

        std::vector<int32_t>  xxx;

        bool operator==(const Math_out_seq_result& rhs) const;
        bool operator!=(const Math_out_seq_result& rhs) const;
        bool operator< (const Math_out_seq_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_string_set_result {
    public:
        Math_out_string_set_result();
        virtual ~Math_out_string_set_result();

        std::set<std::string>  xxx;

        bool operator==(const Math_out_string_set_result& rhs) const;
        bool operator!=(const Math_out_string_set_result& rhs) const;
        bool operator< (const Math_out_string_set_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int16_float_map_result {
    public:
        Math_out_int16_float_map_result();
        virtual ~Math_out_int16_float_map_result();

        std::map<int16_t, float>  xxx;

        bool operator==(const Math_out_int16_float_map_result& rhs) const;
        bool operator!=(const Math_out_int16_float_map_result& rhs) const;
        bool operator< (const Math_out_int16_float_map_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int_vec_set_result {
    public:
        Math_out_int_vec_set_result();
        virtual ~Math_out_int_vec_set_result();

        std::set<std::vector<int32_t> >  xxx;

        bool operator==(const Math_out_int_vec_set_result& rhs) const;
        bool operator!=(const Math_out_int_vec_set_result& rhs) const;
        bool operator< (const Math_out_int_vec_set_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_boolean_result {
    public:
        Math_all_boolean_result();
        virtual ~Math_all_boolean_result();

        bool value;

        bool operator==(const Math_all_boolean_result& rhs) const;
        bool operator!=(const Math_all_boolean_result& rhs) const;
        bool operator< (const Math_all_boolean_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int8_result {
    public:
        Math_all_int8_result();
        virtual ~Math_all_int8_result();

        int8_t value;

        bool operator==(const Math_all_int8_result& rhs) const;
        bool operator!=(const Math_all_int8_result& rhs) const;
        bool operator< (const Math_all_int8_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int16_result {
    public:
        Math_all_int16_result();
        virtual ~Math_all_int16_result();

        int16_t value;

        bool operator==(const Math_all_int16_result& rhs) const;
        bool operator!=(const Math_all_int16_result& rhs) const;
        bool operator< (const Math_all_int16_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_result {
    public:
        Math_all_int32_result();
        virtual ~Math_all_int32_result();

        int32_t value;

        bool operator==(const Math_all_int32_result& rhs) const;
        bool operator!=(const Math_all_int32_result& rhs) const;
        bool operator< (const Math_all_int32_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int64_result {
    public:
        Math_all_int64_result();
        virtual ~Math_all_int64_result();

        int64_t value;

        bool operator==(const Math_all_int64_result& rhs) const;
        bool operator!=(const Math_all_int64_result& rhs) const;
        bool operator< (const Math_all_int64_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_float_result {
    public:
        Math_all_float_result();
        virtual ~Math_all_float_result();

        float value;

        bool operator==(const Math_all_float_result& rhs) const;
        bool operator!=(const Math_all_float_result& rhs) const;
        bool operator< (const Math_all_float_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_string_result {
    public:
        Math_all_string_result();
        virtual ~Math_all_string_result();

        std::string value;

        bool operator==(const Math_all_string_result& rhs) const;
        bool operator!=(const Math_all_string_result& rhs) const;
        bool operator< (const Math_all_string_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_binary_result {
    public:
        Math_all_binary_result();
        virtual ~Math_all_binary_result();

        std::string value;

        bool operator==(const Math_all_binary_result& rhs) const;
        bool operator!=(const Math_all_binary_result& rhs) const;
        bool operator< (const Math_all_binary_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_seq_result {
    public:
        Math_all_int32_seq_result();
        virtual ~Math_all_int32_seq_result();

        std::vector<int32_t>  value;

        bool operator==(const Math_all_int32_seq_result& rhs) const;
        bool operator!=(const Math_all_int32_seq_result& rhs) const;
        bool operator< (const Math_all_int32_seq_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_person_result {
    public:
        Math_all_person_result();
        virtual ~Math_all_person_result();

        Person value;

        bool operator==(const Math_all_person_result& rhs) const;
        bool operator!=(const Math_all_person_result& rhs) const;
        bool operator< (const Math_all_person_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_set_result {
    public:
        Math_all_int32_set_result();
        virtual ~Math_all_int32_set_result();

        std::set<int32_t>  value;

        bool operator==(const Math_all_int32_set_result& rhs) const;
        bool operator!=(const Math_all_int32_set_result& rhs) const;
        bool operator< (const Math_all_int32_set_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_person_seq_result {
    public:
        Math_all_person_seq_result();
        virtual ~Math_all_person_seq_result();

        std::vector<Person>  value;

        bool operator==(const Math_all_person_seq_result& rhs) const;
        bool operator!=(const Math_all_person_seq_result& rhs) const;
        bool operator< (const Math_all_person_seq_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_person_map_result {
    public:
        Math_all_int32_person_map_result();
        virtual ~Math_all_int32_person_map_result();

        std::map<int32_t, Person>  value;

        bool operator==(const Math_all_int32_person_map_result& rhs) const;
        bool operator!=(const Math_all_int32_person_map_result& rhs) const;
        bool operator< (const Math_all_int32_person_map_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_color_out_all_result {
    public:
        Math_color_out_all_result();
        virtual ~Math_color_out_all_result();

        MyColor color1;
        MyColor color2;

        bool operator==(const Math_color_out_all_result& rhs) const;
        bool operator!=(const Math_color_out_all_result& rhs) const;
        bool operator< (const Math_color_out_all_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_color_xx_result {
    public:
        Math_color_xx_result();
        virtual ~Math_color_xx_result();

        std::vector<MyColor>  return_value;
        std::vector<MyColor>  color2;
        std::map<MyColor, MyColor>  color3;

        bool operator==(const Math_color_xx_result& rhs) const;
        bool operator!=(const Math_color_xx_result& rhs) const;
        bool operator< (const Math_color_xx_result& rhs) const;
        int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_ping_presult {
    public:
        virtual ~Math_ping_presult();

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_add_presult {
    public:
        virtual ~Math_add_presult();

        AddResult* return_value;
        int32_t* sum;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_test_citizen_presult {
    public:
        virtual ~Math_test_citizen_presult();

        Citizen* return_value;
        Citizen* outs;
        Citizen* alls;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_boolean_presult {
    public:
        virtual ~Math_get_boolean_presult();

        bool* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int8_presult {
    public:
        virtual ~Math_get_int8_presult();

        int8_t* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int16_presult {
    public:
        virtual ~Math_get_int16_presult();

        int16_t* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int32_presult {
    public:
        virtual ~Math_get_int32_presult();

        int32_t* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int64_presult {
    public:
        virtual ~Math_get_int64_presult();

        int64_t* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_float_presult {
    public:
        virtual ~Math_get_float_presult();

        float* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_string_presult {
    public:
        virtual ~Math_get_string_presult();

        std::string* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_binary_presult {
    public:
        virtual ~Math_get_binary_presult();

        std::string* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_color_presult {
    public:
        virtual ~Math_get_color_presult();

        Color* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_sequence_presult {
    public:
        virtual ~Math_get_sequence_presult();

        std::vector<int32_t> * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_string_set_presult {
    public:
        virtual ~Math_get_string_set_presult();

        std::set<std::string> * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_int_str_map_presult {
    public:
        virtual ~Math_get_int_str_map_presult();

        std::map<int64_t, std::string> * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_bool_set_sequence_presult {
    public:
        virtual ~Math_get_bool_set_sequence_presult();

        std::vector<std::set<bool> > * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_person_presult {
    public:
        virtual ~Math_get_person_presult();

        Person* return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons_presult {
    public:
        virtual ~Math_get_persons_presult();

        std::vector<Person> * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons2_presult {
    public:
        virtual ~Math_get_persons2_presult();

        std::set<Person> * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons3_presult {
    public:
        virtual ~Math_get_persons3_presult();

        std::map<Person, Person> * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_get_persons4_presult {
    public:
        virtual ~Math_get_persons4_presult();

        std::vector<std::set<Person> > * return_value;
        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_bool_presult {
    public:
        virtual ~Math_send_bool_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int8_presult {
    public:
        virtual ~Math_send_int8_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int16_presult {
    public:
        virtual ~Math_send_int16_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_presult {
    public:
        virtual ~Math_send_int32_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int64_presult {
    public:
        virtual ~Math_send_int64_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_float_presult {
    public:
        virtual ~Math_send_float_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_string_presult {
    public:
        virtual ~Math_send_string_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_binary_presult {
    public:
        virtual ~Math_send_binary_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_color_presult {
    public:
        virtual ~Math_send_color_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_person_presult {
    public:
        virtual ~Math_send_person_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_sequence_presult {
    public:
        virtual ~Math_send_int32_sequence_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons_presult {
    public:
        virtual ~Math_send_persons_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons2_presult {
    public:
        virtual ~Math_send_persons2_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_int32_set_seq_presult {
    public:
        virtual ~Math_send_int32_set_seq_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_persons3_presult {
    public:
        virtual ~Math_send_persons3_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_send_person_vec_set_presult {
    public:
        virtual ~Math_send_person_vec_set_presult();


        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_boolean_presult {
    public:
        virtual ~Math_out_boolean_presult();

        bool* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int8_presult {
    public:
        virtual ~Math_out_int8_presult();

        int8_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int16_presult {
    public:
        virtual ~Math_out_int16_presult();

        int16_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int32_presult {
    public:
        virtual ~Math_out_int32_presult();

        int32_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int64_presult {
    public:
        virtual ~Math_out_int64_presult();

        int64_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_float_presult {
    public:
        virtual ~Math_out_float_presult();

        float* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_string_presult {
    public:
        virtual ~Math_out_string_presult();

        std::string* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_binary_presult {
    public:
        virtual ~Math_out_binary_presult();

        std::string* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_person_presult {
    public:
        virtual ~Math_out_person_presult();

        Person* person;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_seq_presult {
    public:
        virtual ~Math_out_seq_presult();

        std::vector<int32_t> * xxx;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_string_set_presult {
    public:
        virtual ~Math_out_string_set_presult();

        std::set<std::string> * xxx;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int16_float_map_presult {
    public:
        virtual ~Math_out_int16_float_map_presult();

        std::map<int16_t, float> * xxx;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_out_int_vec_set_presult {
    public:
        virtual ~Math_out_int_vec_set_presult();

        std::set<std::vector<int32_t> > * xxx;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_boolean_presult {
    public:
        virtual ~Math_all_boolean_presult();

        bool* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int8_presult {
    public:
        virtual ~Math_all_int8_presult();

        int8_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int16_presult {
    public:
        virtual ~Math_all_int16_presult();

        int16_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_presult {
    public:
        virtual ~Math_all_int32_presult();

        int32_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int64_presult {
    public:
        virtual ~Math_all_int64_presult();

        int64_t* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_float_presult {
    public:
        virtual ~Math_all_float_presult();

        float* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_string_presult {
    public:
        virtual ~Math_all_string_presult();

        std::string* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_binary_presult {
    public:
        virtual ~Math_all_binary_presult();

        std::string* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_seq_presult {
    public:
        virtual ~Math_all_int32_seq_presult();

        std::vector<int32_t> * value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_person_presult {
    public:
        virtual ~Math_all_person_presult();

        Person* value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_set_presult {
    public:
        virtual ~Math_all_int32_set_presult();

        std::set<int32_t> * value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_person_seq_presult {
    public:
        virtual ~Math_all_person_seq_presult();

        std::vector<Person> * value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_all_int32_person_map_presult {
    public:
        virtual ~Math_all_int32_person_map_presult();

        std::map<int32_t, Person> * value;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_color_out_all_presult {
    public:
        virtual ~Math_color_out_all_presult();

        MyColor* color1;
        MyColor* color2;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class Math_color_xx_presult {
    public:
        virtual ~Math_color_xx_presult();

        std::vector<MyColor> * return_value;
        std::vector<MyColor> * color2;
        std::map<MyColor, MyColor> * color3;

        int32_t read(bgcc::SharedPointer<bgcc::IProtocol> proto) const;
    };

    class MathProxy : public bgcc::BaseProxy {
    public:
        MathProxy(
            bgcc::ServerInfo serverinfo,
            int32_t nprotocols = 1,
            bgcc::ServiceManager* mgr = NULL,
            int32_t tryCount = 5,
            int32_t tryInterval = 500);

        MathProxy(const std::string& proxy_name);

        void ping(
            bool last = false);

        AddResult add(
            int32_t a,
            int32_t b,
            int32_t& sum,
            bool last = false);

        Citizen test_citizen(
            const Citizen& ins,
            Citizen& outs,
            Citizen& alls,
            bool last = false);

        bool get_boolean(
            bool last = false);

        int8_t get_int8(
            bool last = false);

        int16_t get_int16(
            bool last = false);

        int32_t get_int32(
            bool last = false);

        int64_t get_int64(
            bool last = false);

        float get_float(
            bool last = false);

        std::string get_string(
            bool last = false);

        std::string get_binary(
            bool last = false);

        Color get_color(
            bool last = false);

        std::vector<int32_t>  get_sequence(
            bool last = false);

        std::set<std::string>  get_string_set(
            bool last = false);

        std::map<int64_t, std::string>  get_int_str_map(
            bool last = false);

        std::vector<std::set<bool> >  get_bool_set_sequence(
            bool last = false);

        Person get_person(
            bool last = false);

        std::vector<Person>  get_persons(
            bool last = false);

        std::set<Person>  get_persons2(
            bool last = false);

        std::map<Person, Person>  get_persons3(
            bool last = false);

        std::vector<std::set<Person> >  get_persons4(
            bool last = false);

        void send_bool(
            b_t value,
            bool last = false);

        void send_int8(
            i8_t value,
            bool last = false);

        void send_int16(
            i16_t value,
            bool last = false);

        void send_int32(
            i32_t value,
            bool last = false);

        void send_int64(
            i64_t value,
            bool last = false);

        void send_float(
            f_t value,
            bool last = false);

        void send_string(
            const s_t& value,
            bool last = false);

        void send_binary(
            const bin_t& value,
            bool last = false);

        void send_color(
            const Color& color,
            bool last = false);

        void send_person(
            const MyPerson& person,
            bool last = false);

        void send_int32_sequence(
            const std::vector<int32_t> & numbers,
            bool last = false);

        void send_persons(
            const std::vector<Person> & persons,
            bool last = false);

        void send_persons2(
            const std::set<Person> & persons,
            bool last = false);

        void send_int32_set_seq(
            const std::vector<std::set<int32_t> > & xx,
            bool last = false);

        void send_persons3(
            const std::map<Person, Person> & persons,
            bool last = false);

        void send_person_vec_set(
            const std::set<std::vector<Person> > & xxx,
            bool last = false);

        void out_boolean(
            bool& value,
            bool last = false);

        void out_int8(
            int8_t& value,
            bool last = false);

        void out_int16(
            int16_t& value,
            bool last = false);

        void out_int32(
            int32_t& value,
            bool last = false);

        void out_int64(
            int64_t& value,
            bool last = false);

        void out_float(
            float& value,
            bool last = false);

        void out_string(
            std::string& value,
            bool last = false);

        void out_binary(
            std::string& value,
            bool last = false);

        void out_person(
            Person& person,
            bool last = false);

        void out_seq(
            std::vector<int32_t> & xxx,
            bool last = false);

        void out_string_set(
            std::set<std::string> & xxx,
            bool last = false);

        void out_int16_float_map(
            std::map<int16_t, float> & xxx,
            bool last = false);

        void out_int_vec_set(
            std::set<std::vector<int32_t> > & xxx,
            bool last = false);

        void all_boolean(
            bool& value,
            bool last = false);

        void all_int8(
            int8_t& value,
            bool last = false);

        void all_int16(
            int16_t& value,
            bool last = false);

        void all_int32(
            int32_t& value,
            bool last = false);

        void all_int64(
            int64_t& value,
            bool last = false);

        void all_float(
            float& value,
            bool last = false);

        void all_string(
            std::string& value,
            bool last = false);

        void all_binary(
            std::string& value,
            bool last = false);

        void all_int32_seq(
            std::vector<int32_t> & value,
            bool last = false);

        void all_person(
            Person& value,
            bool last = false);

        void all_int32_set(
            std::set<int32_t> & value,
            bool last = false);

        void all_person_seq(
            std::vector<Person> & value,
            bool last = false);

        void all_int32_person_map(
            std::map<int32_t, Person> & value,
            bool last = false);

        void color_out_all(
            MyColor& color1,
            MyColor& color2,
            bool last = false);

        std::vector<MyColor>  color_xx(
            const std::set<MyColor> & color1,
            std::vector<MyColor> & color2,
            std::map<MyColor, MyColor> & color3,
            bool last = false);

    private:
        void send_ping(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_ping(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_add(
            const int32_t& a,
            const int32_t& b,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        AddResult recv_add(
            int32_t& sum,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_test_citizen(
            const Citizen& ins,
            const Citizen& alls,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        Citizen recv_test_citizen(
            Citizen& outs,
            Citizen& alls,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_boolean(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        bool recv_get_boolean(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_int8(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        int8_t recv_get_int8(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_int16(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        int16_t recv_get_int16(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_int32(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        int32_t recv_get_int32(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_int64(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        int64_t recv_get_int64(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_float(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        float recv_get_float(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_string(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::string recv_get_string(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_binary(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::string recv_get_binary(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_color(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        Color recv_get_color(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_sequence(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::vector<int32_t>  recv_get_sequence(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_string_set(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::set<std::string>  recv_get_string_set(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_int_str_map(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::map<int64_t, std::string>  recv_get_int_str_map(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_bool_set_sequence(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::vector<std::set<bool> >  recv_get_bool_set_sequence(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_person(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        Person recv_get_person(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_persons(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::vector<Person>  recv_get_persons(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_persons2(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::set<Person>  recv_get_persons2(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_persons3(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::map<Person, Person>  recv_get_persons3(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_get_persons4(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::vector<std::set<Person> >  recv_get_persons4(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_bool(
            const b_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_bool(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_int8(
            const i8_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_int8(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_int16(
            const i16_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_int16(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_int32(
            const i32_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_int32(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_int64(
            const i64_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_int64(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_float(
            const f_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_float(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_string(
            const s_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_string(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_binary(
            const bin_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_binary(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_color(
            const Color& color,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_color(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_person(
            const MyPerson& person,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_person(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_int32_sequence(
            const std::vector<int32_t> & numbers,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_int32_sequence(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_persons(
            const std::vector<Person> & persons,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_persons(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_persons2(
            const std::set<Person> & persons,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_persons2(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_int32_set_seq(
            const std::vector<std::set<int32_t> > & xx,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_int32_set_seq(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_persons3(
            const std::map<Person, Person> & persons,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_persons3(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_send_person_vec_set(
            const std::set<std::vector<Person> > & xxx,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_send_person_vec_set(
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_boolean(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_boolean(
            bool& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_int8(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_int8(
            int8_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_int16(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_int16(
            int16_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_int32(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_int32(
            int32_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_int64(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_int64(
            int64_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_float(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_float(
            float& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_string(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_string(
            std::string& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_binary(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_binary(
            std::string& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_person(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_person(
            Person& person,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_seq(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_seq(
            std::vector<int32_t> & xxx,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_string_set(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_string_set(
            std::set<std::string> & xxx,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_int16_float_map(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_int16_float_map(
            std::map<int16_t, float> & xxx,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_out_int_vec_set(
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_out_int_vec_set(
            std::set<std::vector<int32_t> > & xxx,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_boolean(
            const bool& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_boolean(
            bool& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_int8(
            const int8_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_int8(
            int8_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_int16(
            const int16_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_int16(
            int16_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_int32(
            const int32_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_int32(
            int32_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_int64(
            const int64_t& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_int64(
            int64_t& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_float(
            const float& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_float(
            float& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_string(
            const std::string& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_string(
            std::string& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_binary(
            const std::string& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_binary(
            std::string& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_int32_seq(
            const std::vector<int32_t> & value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_int32_seq(
            std::vector<int32_t> & value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_person(
            const Person& value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_person(
            Person& value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_int32_set(
            const std::set<int32_t> & value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_int32_set(
            std::set<int32_t> & value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_person_seq(
            const std::vector<Person> & value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_person_seq(
            std::vector<Person> & value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_all_int32_person_map(
            const std::map<int32_t, Person> & value,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_all_int32_person_map(
            std::map<int32_t, Person> & value,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_color_out_all(
            const MyColor& color1,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void recv_color_out_all(
            MyColor& color1,
            MyColor& color2,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        void send_color_xx(
            const std::set<MyColor> & color1,
            const std::map<MyColor, MyColor> & color3,
            int32_t seqid,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        std::vector<MyColor>  recv_color_xx(
            std::vector<MyColor> & color2,
            std::map<MyColor, MyColor> & color3,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

    private:
        std::string _proxy_name;
        bool _use_existing_socket;
    };

    class MathProcessor : public bgcc::BaseProcessor {
    public:
        MathProcessor(bgcc::SharedPointer<Math> intf);

        virtual ~MathProcessor(){ }

        virtual int32_t process(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto);

        virtual std::string get_name() const;

    protected:
        virtual int32_t do_function__(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            const std::string& fname, int32_t seqid);

        bgcc::SharedPointer<Math> __intf;

    private:
        int32_t do_ping(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_add(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_test_citizen(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_boolean(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_int8(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_int16(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_int32(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_int64(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_float(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_string(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_binary(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_color(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_sequence(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_string_set(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_int_str_map(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_bool_set_sequence(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_person(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_persons(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_persons2(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_persons3(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_get_persons4(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_bool(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_int8(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_int16(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_int32(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_int64(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_float(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_string(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_binary(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_color(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_person(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_int32_sequence(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_persons(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_persons2(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_int32_set_seq(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_persons3(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_send_person_vec_set(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_boolean(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_int8(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_int16(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_int32(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_int64(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_float(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_string(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_binary(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_person(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_seq(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_string_set(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_int16_float_map(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_out_int_vec_set(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_boolean(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_int8(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_int16(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_int32(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_int64(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_float(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_string(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_binary(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_int32_seq(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_person(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_int32_set(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_person_seq(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_all_int32_person_map(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_color_out_all(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        int32_t do_color_xx(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        typedef int32_t (MathProcessor::* do_function_ptr)(
            char* request,
            int32_t request_len,
            bgcc::SharedPointer<bgcc::IProtocol> proto,
            int32_t seqid);

        std::map<std::string, do_function_ptr> __fun_map;
    };
}


#endif
