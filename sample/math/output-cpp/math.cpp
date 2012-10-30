#include "math.h"

namespace math {
    static std::vector<bool>  create_ss1() {
        std::vector<bool>  tmp_var1;

        tmp_var1.push_back(true);
        tmp_var1.push_back(false);
        tmp_var1.push_back(false);

        return tmp_var1;
    }
    const std::vector<bool>  ss1 = create_ss1();
    static std::vector<int32_t>  create_ss2() {
        std::vector<int32_t>  tmp_var2;

        tmp_var2.push_back(1);
        tmp_var2.push_back(2);
        tmp_var2.push_back(3);

        return tmp_var2;
    }
    const std::vector<int32_t>  ss2 = create_ss2();
    static std::vector<std::string>  create_ss3() {
        std::vector<std::string>  tmp_var3;

        tmp_var3.push_back("first");
        tmp_var3.push_back("second");

        return tmp_var3;
    }
    const std::vector<std::string>  ss3 = create_ss3();
    static std::vector<float>  create_ss4() {
        std::vector<float>  tmp_var4;

        tmp_var4.push_back(1.1f);
        tmp_var4.push_back(2.2f);
        tmp_var4.push_back(3.3f);

        return tmp_var4;
    }
    const std::vector<float>  ss4 = create_ss4();
    static std::vector<std::set<int32_t> >  create_tt1() {
        std::vector<std::set<int32_t> >  tmp_var5;

        std::set<int32_t>  tmp_var6;

        tmp_var6.insert(1);

        tmp_var5.push_back(tmp_var6);
        std::set<int32_t>  tmp_var7;

        tmp_var7.insert(2);

        tmp_var5.push_back(tmp_var7);
        std::set<int32_t>  tmp_var8;

        tmp_var8.insert(3);

        tmp_var5.push_back(tmp_var8);

        return tmp_var5;
    }
    const std::vector<std::set<int32_t> >  tt1 = create_tt1();
    static std::set<bool>  create_sk1() {
        std::set<bool>  tmp_var9;

        tmp_var9.insert(true);
        tmp_var9.insert(false);
        tmp_var9.insert(false);

        return tmp_var9;
    }
    const std::set<bool>  sk1 = create_sk1();
    static std::set<int32_t>  create_sk2() {
        std::set<int32_t>  tmp_var10;

        tmp_var10.insert(1);
        tmp_var10.insert(2);
        tmp_var10.insert(3);

        return tmp_var10;
    }
    const std::set<int32_t>  sk2 = create_sk2();
    static std::set<std::string>  create_sk3() {
        std::set<std::string>  tmp_var11;

        tmp_var11.insert("first");
        tmp_var11.insert("second");

        return tmp_var11;
    }
    const std::set<std::string>  sk3 = create_sk3();
    static std::set<float>  create_sk4() {
        std::set<float>  tmp_var12;

        tmp_var12.insert(1.1f);
        tmp_var12.insert(2.2f);
        tmp_var12.insert(3.3f);

        return tmp_var12;
    }
    const std::set<float>  sk4 = create_sk4();
    static std::set<std::vector<std::string> >  create_tt2() {
        std::set<std::vector<std::string> >  tmp_var13;

        std::vector<std::string>  tmp_var14;

        tmp_var14.push_back("first");

        tmp_var13.insert(tmp_var14);
        std::vector<std::string>  tmp_var15;

        tmp_var15.push_back("second");
        tmp_var15.push_back("third");

        tmp_var13.insert(tmp_var15);

        return tmp_var13;
    }
    const std::set<std::vector<std::string> >  tt2 = create_tt2();
    static std::map<int32_t, std::string>  create_sm1() {
        std::map<int32_t, std::string>  tmp_var16;

        tmp_var16.insert(std::make_pair(1, "first"));

        return tmp_var16;
    }
    const std::map<int32_t, std::string>  sm1 = create_sm1();
    static std::map<std::vector<int32_t> , std::set<std::string> >  create_tt3() {
        std::map<std::vector<int32_t> , std::set<std::string> >  tmp_var17;

        std::vector<int32_t>  tmp_var18;

        tmp_var18.push_back(1);

        std::set<std::string>  tmp_var19;

        tmp_var19.insert("first");

        tmp_var17.insert(std::make_pair(tmp_var18, tmp_var19));
        std::vector<int32_t>  tmp_var20;

        tmp_var20.push_back(2);

        std::set<std::string>  tmp_var21;

        tmp_var21.insert("second");

        tmp_var17.insert(std::make_pair(tmp_var20, tmp_var21));

        return tmp_var17;
    }
    const std::map<std::vector<int32_t> , std::set<std::string> >  tt3 = create_tt3();
    const b_t be_used = false;
    const bool be_health = true;
    const i8_t i8 = 8;
    const i16_t i16 = 16;
    const i32_t i32 = 32;
    const i64_t i64 = 64;
    const s_t str = "hello";
    const bin_t bin = "data";
    const f_t f = 3.3f;
    Person::Person() {
    }

    Person::~Person() {
    }

    bool Person::operator==(const Person& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (name != rhs.name) {
            return false;
        }
        if (age != rhs.age) {
            return false;
        }
        return true;
    }

    bool Person::operator!=(const Person& rhs) const {
        return !(*this == rhs);
    }

    bool Person::operator< (const Person& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (name < rhs.name) {
            return true;
        }
        else if (rhs.name < name) {
            return false;
        }

        if (age < rhs.age) {
            return true;
        }
        else if (rhs.age < age) {
            return false;
        }

        return false;
    }

    int32_t Person::read(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if(ret < 0) { return ret; }

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(name);
                if (ret < 0) { return ret; }
                break;
            case 2:
                ret = proto->readInt32(age);
                if (ret < 0) { return ret; }
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    int32_t Person::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(request + nread, request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(request + nread, request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(request + nread, request_len - nread, name);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readInt32(request + nread, request_len - nread, age);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t Person::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("Person");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("name", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(name);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("age", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(age);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct Color::desc_t Color::descs[] = {
        {Color::RED, "Color::RED"},
        {Color::GREEN, "Color::GREEN"},
        {Color::BLUE, "Color::BLUE"},
        {0, NULL}
    };

    Color::Color() : _value(RED) {
    }

    Color::Color(int32_t value) : _value(value) {
    }

    int32_t Color::get_value() const {
        return _value;
    }

    std::string Color::get_desc() const {
        const struct desc_t* ptr = Color::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool Color::operator==(int32_t value) const {
        return _value == value;
    }

    bool Color::operator!=(int32_t value) const {
        return _value != value;
    }

    bool Color::operator< (int32_t value) const {
        return _value < value;
    }

    bool Color::operator==(const Color& rhs) const {
        return _value == rhs.get_value();
    }

    bool Color::operator!=(const Color& rhs) const {
        return _value != rhs.get_value();
    }

    bool Color::operator< (const Color& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const Color& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const Color& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const Color& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const Color& e) {
        o << e.get_value();
        return o;
    }


    const struct Gender::desc_t Gender::descs[] = {
        {Gender::MALE, "Gender::MALE"},
        {Gender::FEMALE, "Gender::FEMALE"},
        {0, NULL}
    };

    Gender::Gender() : _value(MALE) {
    }

    Gender::Gender(int32_t value) : _value(value) {
    }

    int32_t Gender::get_value() const {
        return _value;
    }

    std::string Gender::get_desc() const {
        const struct desc_t* ptr = Gender::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool Gender::operator==(int32_t value) const {
        return _value == value;
    }

    bool Gender::operator!=(int32_t value) const {
        return _value != value;
    }

    bool Gender::operator< (int32_t value) const {
        return _value < value;
    }

    bool Gender::operator==(const Gender& rhs) const {
        return _value == rhs.get_value();
    }

    bool Gender::operator!=(const Gender& rhs) const {
        return _value != rhs.get_value();
    }

    bool Gender::operator< (const Gender& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const Gender& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const Gender& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const Gender& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const Gender& e) {
        o << e.get_value();
        return o;
    }

    Citizen::Citizen() {
    }

    Citizen::~Citizen() {
    }

    bool Citizen::operator==(const Citizen& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (name != rhs.name) {
            return false;
        }
        if (age != rhs.age) {
            return false;
        }
        if (gender != rhs.gender) {
            return false;
        }
        if (address != rhs.address) {
            return false;
        }
        if (children != rhs.children) {
            return false;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        if (kkk != rhs.kkk) {
            return false;
        }
        return true;
    }

    bool Citizen::operator!=(const Citizen& rhs) const {
        return !(*this == rhs);
    }

    bool Citizen::operator< (const Citizen& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (name < rhs.name) {
            return true;
        }
        else if (rhs.name < name) {
            return false;
        }

        if (age < rhs.age) {
            return true;
        }
        else if (rhs.age < age) {
            return false;
        }

        if (gender < rhs.gender) {
            return true;
        }
        else if (rhs.gender < gender) {
            return false;
        }

        if (address < rhs.address) {
            return true;
        }
        else if (rhs.address < address) {
            return false;
        }

        if (children < rhs.children) {
            return true;
        }
        else if (rhs.children < children) {
            return false;
        }

        if (xxx < rhs.xxx) {
            return true;
        }
        else if (rhs.xxx < xxx) {
            return false;
        }

        if (kkk < rhs.kkk) {
            return true;
        }
        else if (rhs.kkk < kkk) {
            return false;
        }

        return false;
    }

    int32_t Citizen::read(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if(ret < 0) { return ret; }

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(name);
                if (ret < 0) { return ret; }
                break;
            case 2:
                ret = proto->readInt32(age);
                if (ret < 0) { return ret; }
                break;
            case 3:
                int32_t ele_var22;
                ret = proto->readInt32(ele_var22);
                if (ret < 0) { return ret; }
                gender = ele_var22;
                break;
            case 4:
                ret = address.read(proto);
                if (ret < 0) { return ret; }
                break;
            case 5:
                children.clear();

                int32_t size_var23;
                bgcc::DataTypeID etype_var24;

                ret = proto->readListBegin(etype_var24, size_var23);
                if (ret < 0) { return ret; }

                children.reserve(size_var23);
                for(int32_t i = 0; i < size_var23; ++i) {
                    std::string value_var25;
                    ret = proto->readString(value_var25);
                    if (ret < 0) { return ret; }
                    children.push_back(value_var25);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 6:
                xxx.clear();

                int32_t size_var26;
                bgcc::DataTypeID etype_var27;

                ret = proto->readSetBegin(etype_var27, size_var26);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var26; ++i) {
                    i32_t value_var28;
                    ret = proto->readInt32(value_var28);
                    if (ret < 0) { return ret; }
                    xxx.insert(value_var28);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            case 7:
                kkk.clear();

                int32_t size_var29;
                bgcc::DataTypeID ktype_var30;
                bgcc::DataTypeID vtype_var31;

                ret = proto->readMapBegin(ktype_var30, vtype_var31, size_var29);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var29; ++i) {
                    int8_t key_var32;

                    ret = proto->readByte(key_var32);
                    if (ret < 0) { return ret; }

                    bool& value_var33 = kkk[key_var32];
                    ret = proto->readBool(value_var33);
                    if (ret < 0) { return ret; }
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    int32_t Citizen::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(request + nread, request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(request + nread, request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(request + nread, request_len - nread, name);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readInt32(request + nread, request_len - nread, age);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                int32_t ele_var34;
                ret = proto->readInt32(request + nread, request_len - nread, ele_var34);
                if (ret < 0) { return ret; }
                nread += ret;
                gender = ele_var34;
                break;
            case 4:
                ret = address.read(proto, request + nread, request_len - nread);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 5:
                children.clear();

                int32_t size_var35;
                bgcc::DataTypeID etype_var36;

                ret = proto->readListBegin(request + nread, request_len - nread, etype_var36, size_var35);
                if (ret < 0) { return ret; }
                nread += ret;

                children.reserve(size_var35);
                for(int32_t i = 0; i < size_var35; ++i) {
                    std::string value_var37;
                    ret = proto->readString(request + nread, request_len - nread, value_var37);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    children.push_back(value_var37);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 6:
                xxx.clear();

                int32_t size_var38;
                bgcc::DataTypeID etype_var39;
                ret = proto->readSetBegin(request + nread, request_len - nread, etype_var39, size_var38);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var38; ++i) {
                    i32_t value_var40;
                    ret = proto->readInt32(request + nread, request_len - nread, value_var40);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    xxx.insert(value_var40);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            case 7:
                kkk.clear();

                int32_t size_var41;
                bgcc::DataTypeID ktype_var42;
                bgcc::DataTypeID vtype_var43;

                ret = proto->readMapBegin(request + nread, request_len - nread, ktype_var42, vtype_var43, size_var41);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var41; ++i) {
                    int8_t key_var44;

                    ret = proto->readByte(request + nread, request_len - nread, key_var44);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    bool& value_var45 = kkk[key_var44];
                    ret = proto->readBool(request + nread, request_len - nread, value_var45);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t Citizen::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("Citizen");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("name", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(name);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("age", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(age);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("gender", bgcc::IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(gender.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("address", bgcc::IDSTRUCT, 4);
        if (ret < 0) { return ret; }
        ret = address.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("children", bgcc::IDLIST, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTR, children.size());
        if (ret < 0) { return ret; }
        std::vector<std::string> ::const_iterator citr_var46;
        for (citr_var46 = children.begin(); citr_var46 != children.end(); ++citr_var46) {
            ret = proto->writeString((*citr_var46));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, xxx.size());
        if (ret < 0) { return ret; }
        std::set<i32_t> ::const_iterator citr_var47;
        for (citr_var47 = xxx.begin(); citr_var47 != xxx.end(); ++citr_var47) {
            ret = proto->writeInt32((*citr_var47));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("kkk", bgcc::IDMAP, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDBYTE, bgcc::IDBOOL, kkk.size());
        if (ret < 0) { return ret; }
        std::map<int8_t, bool> ::const_iterator citr_var48;
        for (citr_var48 = kkk.begin(); citr_var48 != kkk.end(); ++citr_var48) {
            ret = proto->writeByte(citr_var48->first);
            if (ret < 0) { return ret; }
            ret = proto->writeBool(citr_var48->second);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct AddResult::desc_t AddResult::descs[] = {
        {AddResult::E_SUCCESS, "AddResult::E_SUCCESS"},
        {AddResult::E_OVERFLOW, "AddResult::E_OVERFLOW"},
        {AddResult::E_DOWNFLOW, "AddResult::E_DOWNFLOW"},
        {0, NULL}
    };

    AddResult::AddResult() : _value(E_SUCCESS) {
    }

    AddResult::AddResult(int32_t value) : _value(value) {
    }

    int32_t AddResult::get_value() const {
        return _value;
    }

    std::string AddResult::get_desc() const {
        const struct desc_t* ptr = AddResult::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool AddResult::operator==(int32_t value) const {
        return _value == value;
    }

    bool AddResult::operator!=(int32_t value) const {
        return _value != value;
    }

    bool AddResult::operator< (int32_t value) const {
        return _value < value;
    }

    bool AddResult::operator==(const AddResult& rhs) const {
        return _value == rhs.get_value();
    }

    bool AddResult::operator!=(const AddResult& rhs) const {
        return _value != rhs.get_value();
    }

    bool AddResult::operator< (const AddResult& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const AddResult& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const AddResult& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const AddResult& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const AddResult& e) {
        o << e.get_value();
        return o;
    }

    Math_ping_args::Math_ping_args() {
    }

    Math_ping_args::~Math_ping_args() {
    }

    bool Math_ping_args::operator==(const Math_ping_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_ping_args::operator!=(const Math_ping_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_ping_args::operator< (const Math_ping_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_ping_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_add_args::Math_add_args() {
    }

    Math_add_args::~Math_add_args() {
    }

    bool Math_add_args::operator==(const Math_add_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (a != rhs.a) {
            return false;
        }
        if (b != rhs.b) {
            return false;
        }
        return true;
    }

    bool Math_add_args::operator!=(const Math_add_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_add_args::operator< (const Math_add_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(a < rhs.a)) {
            return false;
        }
        if (!(b < rhs.b)) {
            return false;
        }
        return true;
    }

    int32_t Math_add_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt32(request + nread, request_len - nread, a);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt32(request + nread, request_len - nread, b);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_test_citizen_args::Math_test_citizen_args() {
    }

    Math_test_citizen_args::~Math_test_citizen_args() {
    }

    bool Math_test_citizen_args::operator==(const Math_test_citizen_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (ins != rhs.ins) {
            return false;
        }
        if (alls != rhs.alls) {
            return false;
        }
        return true;
    }

    bool Math_test_citizen_args::operator!=(const Math_test_citizen_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_test_citizen_args::operator< (const Math_test_citizen_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(ins < rhs.ins)) {
            return false;
        }
        if (!(alls < rhs.alls)) {
            return false;
        }
        return true;
    }

    int32_t Math_test_citizen_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = ins.read(proto, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = alls.read(proto, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_boolean_args::Math_get_boolean_args() {
    }

    Math_get_boolean_args::~Math_get_boolean_args() {
    }

    bool Math_get_boolean_args::operator==(const Math_get_boolean_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_boolean_args::operator!=(const Math_get_boolean_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_boolean_args::operator< (const Math_get_boolean_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_boolean_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int8_args::Math_get_int8_args() {
    }

    Math_get_int8_args::~Math_get_int8_args() {
    }

    bool Math_get_int8_args::operator==(const Math_get_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int8_args::operator!=(const Math_get_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int8_args::operator< (const Math_get_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int8_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int16_args::Math_get_int16_args() {
    }

    Math_get_int16_args::~Math_get_int16_args() {
    }

    bool Math_get_int16_args::operator==(const Math_get_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int16_args::operator!=(const Math_get_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int16_args::operator< (const Math_get_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int16_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int32_args::Math_get_int32_args() {
    }

    Math_get_int32_args::~Math_get_int32_args() {
    }

    bool Math_get_int32_args::operator==(const Math_get_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int32_args::operator!=(const Math_get_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int32_args::operator< (const Math_get_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int32_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int64_args::Math_get_int64_args() {
    }

    Math_get_int64_args::~Math_get_int64_args() {
    }

    bool Math_get_int64_args::operator==(const Math_get_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int64_args::operator!=(const Math_get_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int64_args::operator< (const Math_get_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int64_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_float_args::Math_get_float_args() {
    }

    Math_get_float_args::~Math_get_float_args() {
    }

    bool Math_get_float_args::operator==(const Math_get_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_float_args::operator!=(const Math_get_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_float_args::operator< (const Math_get_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_float_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_string_args::Math_get_string_args() {
    }

    Math_get_string_args::~Math_get_string_args() {
    }

    bool Math_get_string_args::operator==(const Math_get_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_string_args::operator!=(const Math_get_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_args::operator< (const Math_get_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_binary_args::Math_get_binary_args() {
    }

    Math_get_binary_args::~Math_get_binary_args() {
    }

    bool Math_get_binary_args::operator==(const Math_get_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_binary_args::operator!=(const Math_get_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_binary_args::operator< (const Math_get_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_binary_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_color_args::Math_get_color_args() {
    }

    Math_get_color_args::~Math_get_color_args() {
    }

    bool Math_get_color_args::operator==(const Math_get_color_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_color_args::operator!=(const Math_get_color_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_color_args::operator< (const Math_get_color_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_color_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_sequence_args::Math_get_sequence_args() {
    }

    Math_get_sequence_args::~Math_get_sequence_args() {
    }

    bool Math_get_sequence_args::operator==(const Math_get_sequence_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_sequence_args::operator!=(const Math_get_sequence_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_sequence_args::operator< (const Math_get_sequence_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_sequence_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_string_set_args::Math_get_string_set_args() {
    }

    Math_get_string_set_args::~Math_get_string_set_args() {
    }

    bool Math_get_string_set_args::operator==(const Math_get_string_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_string_set_args::operator!=(const Math_get_string_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_set_args::operator< (const Math_get_string_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_set_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int_str_map_args::Math_get_int_str_map_args() {
    }

    Math_get_int_str_map_args::~Math_get_int_str_map_args() {
    }

    bool Math_get_int_str_map_args::operator==(const Math_get_int_str_map_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int_str_map_args::operator!=(const Math_get_int_str_map_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int_str_map_args::operator< (const Math_get_int_str_map_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int_str_map_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_bool_set_sequence_args::Math_get_bool_set_sequence_args() {
    }

    Math_get_bool_set_sequence_args::~Math_get_bool_set_sequence_args() {
    }

    bool Math_get_bool_set_sequence_args::operator==(const Math_get_bool_set_sequence_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_bool_set_sequence_args::operator!=(const Math_get_bool_set_sequence_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_bool_set_sequence_args::operator< (const Math_get_bool_set_sequence_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_bool_set_sequence_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_person_args::Math_get_person_args() {
    }

    Math_get_person_args::~Math_get_person_args() {
    }

    bool Math_get_person_args::operator==(const Math_get_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_person_args::operator!=(const Math_get_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_person_args::operator< (const Math_get_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_person_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons_args::Math_get_persons_args() {
    }

    Math_get_persons_args::~Math_get_persons_args() {
    }

    bool Math_get_persons_args::operator==(const Math_get_persons_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons_args::operator!=(const Math_get_persons_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons_args::operator< (const Math_get_persons_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons2_args::Math_get_persons2_args() {
    }

    Math_get_persons2_args::~Math_get_persons2_args() {
    }

    bool Math_get_persons2_args::operator==(const Math_get_persons2_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons2_args::operator!=(const Math_get_persons2_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons2_args::operator< (const Math_get_persons2_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons2_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons3_args::Math_get_persons3_args() {
    }

    Math_get_persons3_args::~Math_get_persons3_args() {
    }

    bool Math_get_persons3_args::operator==(const Math_get_persons3_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons3_args::operator!=(const Math_get_persons3_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons3_args::operator< (const Math_get_persons3_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons3_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons4_args::Math_get_persons4_args() {
    }

    Math_get_persons4_args::~Math_get_persons4_args() {
    }

    bool Math_get_persons4_args::operator==(const Math_get_persons4_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons4_args::operator!=(const Math_get_persons4_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons4_args::operator< (const Math_get_persons4_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons4_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_bool_args::Math_send_bool_args() {
    }

    Math_send_bool_args::~Math_send_bool_args() {
    }

    bool Math_send_bool_args::operator==(const Math_send_bool_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_bool_args::operator!=(const Math_send_bool_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_bool_args::operator< (const Math_send_bool_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_bool_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBool(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int8_args::Math_send_int8_args() {
    }

    Math_send_int8_args::~Math_send_int8_args() {
    }

    bool Math_send_int8_args::operator==(const Math_send_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int8_args::operator!=(const Math_send_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int8_args::operator< (const Math_send_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int8_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readByte(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int16_args::Math_send_int16_args() {
    }

    Math_send_int16_args::~Math_send_int16_args() {
    }

    bool Math_send_int16_args::operator==(const Math_send_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int16_args::operator!=(const Math_send_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int16_args::operator< (const Math_send_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int16_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt16(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int32_args::Math_send_int32_args() {
    }

    Math_send_int32_args::~Math_send_int32_args() {
    }

    bool Math_send_int32_args::operator==(const Math_send_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int32_args::operator!=(const Math_send_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_args::operator< (const Math_send_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt32(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int64_args::Math_send_int64_args() {
    }

    Math_send_int64_args::~Math_send_int64_args() {
    }

    bool Math_send_int64_args::operator==(const Math_send_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int64_args::operator!=(const Math_send_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int64_args::operator< (const Math_send_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int64_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt64(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_float_args::Math_send_float_args() {
    }

    Math_send_float_args::~Math_send_float_args() {
    }

    bool Math_send_float_args::operator==(const Math_send_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_float_args::operator!=(const Math_send_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_float_args::operator< (const Math_send_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_float_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readFloat(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_string_args::Math_send_string_args() {
    }

    Math_send_string_args::~Math_send_string_args() {
    }

    bool Math_send_string_args::operator==(const Math_send_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_string_args::operator!=(const Math_send_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_string_args::operator< (const Math_send_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_string_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readString(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_binary_args::Math_send_binary_args() {
    }

    Math_send_binary_args::~Math_send_binary_args() {
    }

    bool Math_send_binary_args::operator==(const Math_send_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_binary_args::operator!=(const Math_send_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_binary_args::operator< (const Math_send_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_binary_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBinary(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_color_args::Math_send_color_args() {
    }

    Math_send_color_args::~Math_send_color_args() {
    }

    bool Math_send_color_args::operator==(const Math_send_color_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color != rhs.color) {
            return false;
        }
        return true;
    }

    bool Math_send_color_args::operator!=(const Math_send_color_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_color_args::operator< (const Math_send_color_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color < rhs.color)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_color_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    int32_t ele_var49;
                    ret = proto->readInt32(request + nread, request_len - nread, ele_var49);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color = ele_var49;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_person_args::Math_send_person_args() {
    }

    Math_send_person_args::~Math_send_person_args() {
    }

    bool Math_send_person_args::operator==(const Math_send_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (person != rhs.person) {
            return false;
        }
        return true;
    }

    bool Math_send_person_args::operator!=(const Math_send_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_args::operator< (const Math_send_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(person < rhs.person)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = person.read(proto, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int32_sequence_args::Math_send_int32_sequence_args() {
    }

    Math_send_int32_sequence_args::~Math_send_int32_sequence_args() {
    }

    bool Math_send_int32_sequence_args::operator==(const Math_send_int32_sequence_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (numbers != rhs.numbers) {
            return false;
        }
        return true;
    }

    bool Math_send_int32_sequence_args::operator!=(const Math_send_int32_sequence_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_sequence_args::operator< (const Math_send_int32_sequence_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(numbers < rhs.numbers)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_sequence_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    numbers.clear();

                    int32_t size_var50;
                    bgcc::DataTypeID etype_var51;

                    ret = proto->readListBegin(request + nread, request_len - nread, etype_var51, size_var50);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    numbers.reserve(size_var50);
                    for(int32_t i = 0; i < size_var50; ++i) {
                        int32_t value_var52;
                        ret = proto->readInt32(request + nread, request_len - nread, value_var52);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        numbers.push_back(value_var52);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_persons_args::Math_send_persons_args() {
    }

    Math_send_persons_args::~Math_send_persons_args() {
    }

    bool Math_send_persons_args::operator==(const Math_send_persons_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (persons != rhs.persons) {
            return false;
        }
        return true;
    }

    bool Math_send_persons_args::operator!=(const Math_send_persons_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons_args::operator< (const Math_send_persons_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(persons < rhs.persons)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    persons.clear();

                    int32_t size_var53;
                    bgcc::DataTypeID etype_var54;

                    ret = proto->readListBegin(request + nread, request_len - nread, etype_var54, size_var53);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    persons.reserve(size_var53);
                    for(int32_t i = 0; i < size_var53; ++i) {
                        Person value_var55;
                        ret = value_var55.read(proto, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        persons.push_back(value_var55);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_persons2_args::Math_send_persons2_args() {
    }

    Math_send_persons2_args::~Math_send_persons2_args() {
    }

    bool Math_send_persons2_args::operator==(const Math_send_persons2_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (persons != rhs.persons) {
            return false;
        }
        return true;
    }

    bool Math_send_persons2_args::operator!=(const Math_send_persons2_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons2_args::operator< (const Math_send_persons2_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(persons < rhs.persons)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons2_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    persons.clear();

                    int32_t size_var56;
                    bgcc::DataTypeID etype_var57;
                    ret = proto->readSetBegin(request + nread, request_len - nread, etype_var57, size_var56);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var56; ++i) {
                        Person value_var58;
                        ret = value_var58.read(proto, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        persons.insert(value_var58);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int32_set_seq_args::Math_send_int32_set_seq_args() {
    }

    Math_send_int32_set_seq_args::~Math_send_int32_set_seq_args() {
    }

    bool Math_send_int32_set_seq_args::operator==(const Math_send_int32_set_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xx != rhs.xx) {
            return false;
        }
        return true;
    }

    bool Math_send_int32_set_seq_args::operator!=(const Math_send_int32_set_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_set_seq_args::operator< (const Math_send_int32_set_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xx < rhs.xx)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_set_seq_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    xx.clear();

                    int32_t size_var59;
                    bgcc::DataTypeID etype_var60;

                    ret = proto->readListBegin(request + nread, request_len - nread, etype_var60, size_var59);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    xx.reserve(size_var59);
                    for(int32_t i = 0; i < size_var59; ++i) {
                        std::set<int32_t>  value_var61;
                        value_var61.clear();

                        int32_t size_var62;
                        bgcc::DataTypeID etype_var63;
                        ret = proto->readSetBegin(request + nread, request_len - nread, etype_var63, size_var62);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        for(int32_t i = 0; i < size_var62; ++i) {
                            int32_t value_var64;
                            ret = proto->readInt32(request + nread, request_len - nread, value_var64);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            value_var61.insert(value_var64);
                        }

                        ret = proto->readSetEnd();
                        if (ret < 0) { return ret; }
                        xx.push_back(value_var61);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_persons3_args::Math_send_persons3_args() {
    }

    Math_send_persons3_args::~Math_send_persons3_args() {
    }

    bool Math_send_persons3_args::operator==(const Math_send_persons3_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (persons != rhs.persons) {
            return false;
        }
        return true;
    }

    bool Math_send_persons3_args::operator!=(const Math_send_persons3_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons3_args::operator< (const Math_send_persons3_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(persons < rhs.persons)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons3_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    persons.clear();

                    int32_t size_var65;
                    bgcc::DataTypeID ktype_var66;
                    bgcc::DataTypeID vtype_var67;

                    ret = proto->readMapBegin(request + nread, request_len - nread, ktype_var66, vtype_var67, size_var65);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var65; ++i) {
                        Person key_var68;

                        ret = key_var68.read(proto, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        Person& value_var69 = persons[key_var68];
                        ret = value_var69.read(proto, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                    }

                    ret = proto->readMapEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_person_vec_set_args::Math_send_person_vec_set_args() {
    }

    Math_send_person_vec_set_args::~Math_send_person_vec_set_args() {
    }

    bool Math_send_person_vec_set_args::operator==(const Math_send_person_vec_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_send_person_vec_set_args::operator!=(const Math_send_person_vec_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_vec_set_args::operator< (const Math_send_person_vec_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_vec_set_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    xxx.clear();

                    int32_t size_var70;
                    bgcc::DataTypeID etype_var71;
                    ret = proto->readSetBegin(request + nread, request_len - nread, etype_var71, size_var70);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var70; ++i) {
                        std::vector<Person>  value_var72;
                        value_var72.clear();

                        int32_t size_var73;
                        bgcc::DataTypeID etype_var74;

                        ret = proto->readListBegin(request + nread, request_len - nread, etype_var74, size_var73);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        value_var72.reserve(size_var73);
                        for(int32_t i = 0; i < size_var73; ++i) {
                            Person value_var75;
                            ret = value_var75.read(proto, request + nread, request_len - nread);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            value_var72.push_back(value_var75);
                        }

                        ret = proto->readListEnd();
                        if (ret < 0) { return ret; }
                        xxx.insert(value_var72);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_boolean_args::Math_out_boolean_args() {
    }

    Math_out_boolean_args::~Math_out_boolean_args() {
    }

    bool Math_out_boolean_args::operator==(const Math_out_boolean_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_boolean_args::operator!=(const Math_out_boolean_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_boolean_args::operator< (const Math_out_boolean_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_boolean_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int8_args::Math_out_int8_args() {
    }

    Math_out_int8_args::~Math_out_int8_args() {
    }

    bool Math_out_int8_args::operator==(const Math_out_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int8_args::operator!=(const Math_out_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int8_args::operator< (const Math_out_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int8_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int16_args::Math_out_int16_args() {
    }

    Math_out_int16_args::~Math_out_int16_args() {
    }

    bool Math_out_int16_args::operator==(const Math_out_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int16_args::operator!=(const Math_out_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_args::operator< (const Math_out_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int32_args::Math_out_int32_args() {
    }

    Math_out_int32_args::~Math_out_int32_args() {
    }

    bool Math_out_int32_args::operator==(const Math_out_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int32_args::operator!=(const Math_out_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int32_args::operator< (const Math_out_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int32_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int64_args::Math_out_int64_args() {
    }

    Math_out_int64_args::~Math_out_int64_args() {
    }

    bool Math_out_int64_args::operator==(const Math_out_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int64_args::operator!=(const Math_out_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int64_args::operator< (const Math_out_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int64_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_float_args::Math_out_float_args() {
    }

    Math_out_float_args::~Math_out_float_args() {
    }

    bool Math_out_float_args::operator==(const Math_out_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_float_args::operator!=(const Math_out_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_float_args::operator< (const Math_out_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_float_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_string_args::Math_out_string_args() {
    }

    Math_out_string_args::~Math_out_string_args() {
    }

    bool Math_out_string_args::operator==(const Math_out_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_string_args::operator!=(const Math_out_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_args::operator< (const Math_out_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_binary_args::Math_out_binary_args() {
    }

    Math_out_binary_args::~Math_out_binary_args() {
    }

    bool Math_out_binary_args::operator==(const Math_out_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_binary_args::operator!=(const Math_out_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_binary_args::operator< (const Math_out_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_binary_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_person_args::Math_out_person_args() {
    }

    Math_out_person_args::~Math_out_person_args() {
    }

    bool Math_out_person_args::operator==(const Math_out_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_person_args::operator!=(const Math_out_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_person_args::operator< (const Math_out_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_person_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_seq_args::Math_out_seq_args() {
    }

    Math_out_seq_args::~Math_out_seq_args() {
    }

    bool Math_out_seq_args::operator==(const Math_out_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_seq_args::operator!=(const Math_out_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_seq_args::operator< (const Math_out_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_seq_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_string_set_args::Math_out_string_set_args() {
    }

    Math_out_string_set_args::~Math_out_string_set_args() {
    }

    bool Math_out_string_set_args::operator==(const Math_out_string_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_string_set_args::operator!=(const Math_out_string_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_set_args::operator< (const Math_out_string_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_set_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int16_float_map_args::Math_out_int16_float_map_args() {
    }

    Math_out_int16_float_map_args::~Math_out_int16_float_map_args() {
    }

    bool Math_out_int16_float_map_args::operator==(const Math_out_int16_float_map_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int16_float_map_args::operator!=(const Math_out_int16_float_map_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_float_map_args::operator< (const Math_out_int16_float_map_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_float_map_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int_vec_set_args::Math_out_int_vec_set_args() {
    }

    Math_out_int_vec_set_args::~Math_out_int_vec_set_args() {
    }

    bool Math_out_int_vec_set_args::operator==(const Math_out_int_vec_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int_vec_set_args::operator!=(const Math_out_int_vec_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int_vec_set_args::operator< (const Math_out_int_vec_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int_vec_set_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_boolean_args::Math_all_boolean_args() {
    }

    Math_all_boolean_args::~Math_all_boolean_args() {
    }

    bool Math_all_boolean_args::operator==(const Math_all_boolean_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_boolean_args::operator!=(const Math_all_boolean_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_boolean_args::operator< (const Math_all_boolean_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_boolean_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBool(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int8_args::Math_all_int8_args() {
    }

    Math_all_int8_args::~Math_all_int8_args() {
    }

    bool Math_all_int8_args::operator==(const Math_all_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int8_args::operator!=(const Math_all_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int8_args::operator< (const Math_all_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int8_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readByte(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int16_args::Math_all_int16_args() {
    }

    Math_all_int16_args::~Math_all_int16_args() {
    }

    bool Math_all_int16_args::operator==(const Math_all_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int16_args::operator!=(const Math_all_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int16_args::operator< (const Math_all_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int16_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt16(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_args::Math_all_int32_args() {
    }

    Math_all_int32_args::~Math_all_int32_args() {
    }

    bool Math_all_int32_args::operator==(const Math_all_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_args::operator!=(const Math_all_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_args::operator< (const Math_all_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt32(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int64_args::Math_all_int64_args() {
    }

    Math_all_int64_args::~Math_all_int64_args() {
    }

    bool Math_all_int64_args::operator==(const Math_all_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int64_args::operator!=(const Math_all_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int64_args::operator< (const Math_all_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int64_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt64(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_float_args::Math_all_float_args() {
    }

    Math_all_float_args::~Math_all_float_args() {
    }

    bool Math_all_float_args::operator==(const Math_all_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_float_args::operator!=(const Math_all_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_float_args::operator< (const Math_all_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_float_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readFloat(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_string_args::Math_all_string_args() {
    }

    Math_all_string_args::~Math_all_string_args() {
    }

    bool Math_all_string_args::operator==(const Math_all_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_string_args::operator!=(const Math_all_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_string_args::operator< (const Math_all_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_string_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readString(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_binary_args::Math_all_binary_args() {
    }

    Math_all_binary_args::~Math_all_binary_args() {
    }

    bool Math_all_binary_args::operator==(const Math_all_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_binary_args::operator!=(const Math_all_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_binary_args::operator< (const Math_all_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_binary_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBinary(request + nread, request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_seq_args::Math_all_int32_seq_args() {
    }

    Math_all_int32_seq_args::~Math_all_int32_seq_args() {
    }

    bool Math_all_int32_seq_args::operator==(const Math_all_int32_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_seq_args::operator!=(const Math_all_int32_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_seq_args::operator< (const Math_all_int32_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_seq_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var76;
                    bgcc::DataTypeID etype_var77;

                    ret = proto->readListBegin(request + nread, request_len - nread, etype_var77, size_var76);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    value.reserve(size_var76);
                    for(int32_t i = 0; i < size_var76; ++i) {
                        int32_t value_var78;
                        ret = proto->readInt32(request + nread, request_len - nread, value_var78);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value.push_back(value_var78);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_person_args::Math_all_person_args() {
    }

    Math_all_person_args::~Math_all_person_args() {
    }

    bool Math_all_person_args::operator==(const Math_all_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_args::operator!=(const Math_all_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_args::operator< (const Math_all_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = value.read(proto, request + nread, request_len - nread);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_set_args::Math_all_int32_set_args() {
    }

    Math_all_int32_set_args::~Math_all_int32_set_args() {
    }

    bool Math_all_int32_set_args::operator==(const Math_all_int32_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_set_args::operator!=(const Math_all_int32_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_set_args::operator< (const Math_all_int32_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_set_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var79;
                    bgcc::DataTypeID etype_var80;
                    ret = proto->readSetBegin(request + nread, request_len - nread, etype_var80, size_var79);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var79; ++i) {
                        int32_t value_var81;
                        ret = proto->readInt32(request + nread, request_len - nread, value_var81);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value.insert(value_var81);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_person_seq_args::Math_all_person_seq_args() {
    }

    Math_all_person_seq_args::~Math_all_person_seq_args() {
    }

    bool Math_all_person_seq_args::operator==(const Math_all_person_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_seq_args::operator!=(const Math_all_person_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_seq_args::operator< (const Math_all_person_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_seq_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var82;
                    bgcc::DataTypeID etype_var83;

                    ret = proto->readListBegin(request + nread, request_len - nread, etype_var83, size_var82);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    value.reserve(size_var82);
                    for(int32_t i = 0; i < size_var82; ++i) {
                        Person value_var84;
                        ret = value_var84.read(proto, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value.push_back(value_var84);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_person_map_args::Math_all_int32_person_map_args() {
    }

    Math_all_int32_person_map_args::~Math_all_int32_person_map_args() {
    }

    bool Math_all_int32_person_map_args::operator==(const Math_all_int32_person_map_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_person_map_args::operator!=(const Math_all_int32_person_map_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_person_map_args::operator< (const Math_all_int32_person_map_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_person_map_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var85;
                    bgcc::DataTypeID ktype_var86;
                    bgcc::DataTypeID vtype_var87;

                    ret = proto->readMapBegin(request + nread, request_len - nread, ktype_var86, vtype_var87, size_var85);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var85; ++i) {
                        int32_t key_var88;

                        ret = proto->readInt32(request + nread, request_len - nread, key_var88);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        Person& value_var89 = value[key_var88];
                        ret = value_var89.read(proto, request + nread, request_len - nread);
                        if (ret < 0) { return ret; }
                        nread += ret;
                    }

                    ret = proto->readMapEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_color_out_all_args::Math_color_out_all_args() {
    }

    Math_color_out_all_args::~Math_color_out_all_args() {
    }

    bool Math_color_out_all_args::operator==(const Math_color_out_all_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color1 != rhs.color1) {
            return false;
        }
        return true;
    }

    bool Math_color_out_all_args::operator!=(const Math_color_out_all_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_out_all_args::operator< (const Math_color_out_all_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color1 < rhs.color1)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_out_all_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    int32_t ele_var90;
                    ret = proto->readInt32(request + nread, request_len - nread, ele_var90);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color1 = ele_var90;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_color_xx_args::Math_color_xx_args() {
    }

    Math_color_xx_args::~Math_color_xx_args() {
    }

    bool Math_color_xx_args::operator==(const Math_color_xx_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color1 != rhs.color1) {
            return false;
        }
        if (color3 != rhs.color3) {
            return false;
        }
        return true;
    }

    bool Math_color_xx_args::operator!=(const Math_color_xx_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_xx_args::operator< (const Math_color_xx_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color1 < rhs.color1)) {
            return false;
        }
        if (!(color3 < rhs.color3)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_xx_args::read(bgcc::SharedPointer<bgcc::IProtocol> proto, char* request, int32_t request_len) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(request+nread, request_len-nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(request+nread, request_len-nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    color1.clear();

                    int32_t size_var91;
                    bgcc::DataTypeID etype_var92;
                    ret = proto->readSetBegin(request + nread, request_len - nread, etype_var92, size_var91);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var91; ++i) {
                        MyColor value_var93;
                        int32_t ele_var94;
                        ret = proto->readInt32(request + nread, request_len - nread, ele_var94);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var93 = ele_var94;
                        color1.insert(value_var93);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            case 3:
                {
                    color3.clear();

                    int32_t size_var95;
                    bgcc::DataTypeID ktype_var96;
                    bgcc::DataTypeID vtype_var97;

                    ret = proto->readMapBegin(request + nread, request_len - nread, ktype_var96, vtype_var97, size_var95);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var95; ++i) {
                        MyColor key_var98;

                        int32_t ele_var99;
                        ret = proto->readInt32(request + nread, request_len - nread, ele_var99);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        key_var98 = ele_var99;

                        MyColor& value_var100 = color3[key_var98];
                        int32_t ele_var101;
                        ret = proto->readInt32(request + nread, request_len - nread, ele_var101);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var100 = ele_var101;
                    }

                    ret = proto->readMapEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_ping_pargs::~Math_ping_pargs() {
    }

    int32_t Math_ping_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_ping_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_add_pargs::~Math_add_pargs() {
    }

    int32_t Math_add_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_add_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("a", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(a)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("b", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(b)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_test_citizen_pargs::~Math_test_citizen_pargs() {
    }

    int32_t Math_test_citizen_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_test_citizen_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("ins", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = (*(ins)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("alls", bgcc::IDSTRUCT, 3);
        if (ret < 0) { return ret; }
        ret = (*(alls)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_boolean_pargs::~Math_get_boolean_pargs() {
    }

    int32_t Math_get_boolean_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_boolean_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int8_pargs::~Math_get_int8_pargs() {
    }

    int32_t Math_get_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int16_pargs::~Math_get_int16_pargs() {
    }

    int32_t Math_get_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int32_pargs::~Math_get_int32_pargs() {
    }

    int32_t Math_get_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int64_pargs::~Math_get_int64_pargs() {
    }

    int32_t Math_get_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_float_pargs::~Math_get_float_pargs() {
    }

    int32_t Math_get_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_string_pargs::~Math_get_string_pargs() {
    }

    int32_t Math_get_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_binary_pargs::~Math_get_binary_pargs() {
    }

    int32_t Math_get_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_color_pargs::~Math_get_color_pargs() {
    }

    int32_t Math_get_color_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_color_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_sequence_pargs::~Math_get_sequence_pargs() {
    }

    int32_t Math_get_sequence_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_sequence_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_string_set_pargs::~Math_get_string_set_pargs() {
    }

    int32_t Math_get_string_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int_str_map_pargs::~Math_get_int_str_map_pargs() {
    }

    int32_t Math_get_int_str_map_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int_str_map_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_bool_set_sequence_pargs::~Math_get_bool_set_sequence_pargs() {
    }

    int32_t Math_get_bool_set_sequence_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_bool_set_sequence_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_person_pargs::~Math_get_person_pargs() {
    }

    int32_t Math_get_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons_pargs::~Math_get_persons_pargs() {
    }

    int32_t Math_get_persons_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons2_pargs::~Math_get_persons2_pargs() {
    }

    int32_t Math_get_persons2_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons2_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons3_pargs::~Math_get_persons3_pargs() {
    }

    int32_t Math_get_persons3_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons3_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons4_pargs::~Math_get_persons4_pargs() {
    }

    int32_t Math_get_persons4_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons4_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_bool_pargs::~Math_send_bool_pargs() {
    }

    int32_t Math_send_bool_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_bool_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int8_pargs::~Math_send_int8_pargs() {
    }

    int32_t Math_send_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int16_pargs::~Math_send_int16_pargs() {
    }

    int32_t Math_send_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int32_pargs::~Math_send_int32_pargs() {
    }

    int32_t Math_send_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int64_pargs::~Math_send_int64_pargs() {
    }

    int32_t Math_send_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_float_pargs::~Math_send_float_pargs() {
    }

    int32_t Math_send_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_string_pargs::~Math_send_string_pargs() {
    }

    int32_t Math_send_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_binary_pargs::~Math_send_binary_pargs() {
    }

    int32_t Math_send_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary((*(value)).c_str(), (*(value)).size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_color_pargs::~Math_send_color_pargs() {
    }

    int32_t Math_send_color_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_color_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(color)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_person_pargs::~Math_send_person_pargs() {
    }

    int32_t Math_send_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("person", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = (*(person)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int32_sequence_pargs::~Math_send_int32_sequence_pargs() {
    }

    int32_t Math_send_int32_sequence_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_sequence_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("numbers", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, (*(numbers)).size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var102;
        for (citr_var102 = (*(numbers)).begin(); citr_var102 != (*(numbers)).end(); ++citr_var102) {
            ret = proto->writeInt32((*citr_var102));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_persons_pargs::~Math_send_persons_pargs() {
    }

    int32_t Math_send_persons_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("persons", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, (*(persons)).size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var103;
        for (citr_var103 = (*(persons)).begin(); citr_var103 != (*(persons)).end(); ++citr_var103) {
            ret = (*citr_var103).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_persons2_pargs::~Math_send_persons2_pargs() {
    }

    int32_t Math_send_persons2_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons2_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("persons", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTRUCT, (*(persons)).size());
        if (ret < 0) { return ret; }
        std::set<Person> ::const_iterator citr_var104;
        for (citr_var104 = (*(persons)).begin(); citr_var104 != (*(persons)).end(); ++citr_var104) {
            ret = (*citr_var104).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int32_set_seq_pargs::~Math_send_int32_set_seq_pargs() {
    }

    int32_t Math_send_int32_set_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_set_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xx", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSET, (*(xx)).size());
        if (ret < 0) { return ret; }
        std::vector<std::set<int32_t> > ::const_iterator citr_var105;
        for (citr_var105 = (*(xx)).begin(); citr_var105 != (*(xx)).end(); ++citr_var105) {
            ret = proto->writeSetBegin(bgcc::IDINT32, (*citr_var105).size());
            if (ret < 0) { return ret; }
            std::set<int32_t> ::const_iterator citr_var106;
            for (citr_var106 = (*citr_var105).begin(); citr_var106 != (*citr_var105).end(); ++citr_var106) {
                ret = proto->writeInt32((*citr_var106));
                if (ret < 0) { return ret; }
            }
            ret = proto->writeSetEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_persons3_pargs::~Math_send_persons3_pargs() {
    }

    int32_t Math_send_persons3_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons3_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("persons", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDSTRUCT, bgcc::IDSTRUCT, (*(persons)).size());
        if (ret < 0) { return ret; }
        std::map<Person, Person> ::const_iterator citr_var107;
        for (citr_var107 = (*(persons)).begin(); citr_var107 != (*(persons)).end(); ++citr_var107) {
            ret = citr_var107->first.write(proto);
            if (ret < 0) { return ret; }
            ret = citr_var107->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_person_vec_set_pargs::~Math_send_person_vec_set_pargs() {
    }

    int32_t Math_send_person_vec_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_vec_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDLIST, (*(xxx)).size());
        if (ret < 0) { return ret; }
        std::set<std::vector<Person> > ::const_iterator citr_var108;
        for (citr_var108 = (*(xxx)).begin(); citr_var108 != (*(xxx)).end(); ++citr_var108) {
            ret = proto->writeListBegin(bgcc::IDSTRUCT, (*citr_var108).size());
            if (ret < 0) { return ret; }
            std::vector<Person> ::const_iterator citr_var109;
            for (citr_var109 = (*citr_var108).begin(); citr_var109 != (*citr_var108).end(); ++citr_var109) {
                ret = (*citr_var109).write(proto);
                if (ret < 0) { return ret; }
            }
            ret = proto->writeListEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_boolean_pargs::~Math_out_boolean_pargs() {
    }

    int32_t Math_out_boolean_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_boolean_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int8_pargs::~Math_out_int8_pargs() {
    }

    int32_t Math_out_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int16_pargs::~Math_out_int16_pargs() {
    }

    int32_t Math_out_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int32_pargs::~Math_out_int32_pargs() {
    }

    int32_t Math_out_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int64_pargs::~Math_out_int64_pargs() {
    }

    int32_t Math_out_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_float_pargs::~Math_out_float_pargs() {
    }

    int32_t Math_out_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_string_pargs::~Math_out_string_pargs() {
    }

    int32_t Math_out_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_binary_pargs::~Math_out_binary_pargs() {
    }

    int32_t Math_out_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_person_pargs::~Math_out_person_pargs() {
    }

    int32_t Math_out_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_seq_pargs::~Math_out_seq_pargs() {
    }

    int32_t Math_out_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_string_set_pargs::~Math_out_string_set_pargs() {
    }

    int32_t Math_out_string_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int16_float_map_pargs::~Math_out_int16_float_map_pargs() {
    }

    int32_t Math_out_int16_float_map_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_float_map_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int_vec_set_pargs::~Math_out_int_vec_set_pargs() {
    }

    int32_t Math_out_int_vec_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int_vec_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_boolean_pargs::~Math_all_boolean_pargs() {
    }

    int32_t Math_all_boolean_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_boolean_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int8_pargs::~Math_all_int8_pargs() {
    }

    int32_t Math_all_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int16_pargs::~Math_all_int16_pargs() {
    }

    int32_t Math_all_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_pargs::~Math_all_int32_pargs() {
    }

    int32_t Math_all_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int64_pargs::~Math_all_int64_pargs() {
    }

    int32_t Math_all_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_float_pargs::~Math_all_float_pargs() {
    }

    int32_t Math_all_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_string_pargs::~Math_all_string_pargs() {
    }

    int32_t Math_all_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_binary_pargs::~Math_all_binary_pargs() {
    }

    int32_t Math_all_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary((*(value)).c_str(), (*(value)).size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_seq_pargs::~Math_all_int32_seq_pargs() {
    }

    int32_t Math_all_int32_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, (*(value)).size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var110;
        for (citr_var110 = (*(value)).begin(); citr_var110 != (*(value)).end(); ++citr_var110) {
            ret = proto->writeInt32((*citr_var110));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_person_pargs::~Math_all_person_pargs() {
    }

    int32_t Math_all_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = (*(value)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_set_pargs::~Math_all_int32_set_pargs() {
    }

    int32_t Math_all_int32_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, (*(value)).size());
        if (ret < 0) { return ret; }
        std::set<int32_t> ::const_iterator citr_var111;
        for (citr_var111 = (*(value)).begin(); citr_var111 != (*(value)).end(); ++citr_var111) {
            ret = proto->writeInt32((*citr_var111));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_person_seq_pargs::~Math_all_person_seq_pargs() {
    }

    int32_t Math_all_person_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, (*(value)).size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var112;
        for (citr_var112 = (*(value)).begin(); citr_var112 != (*(value)).end(); ++citr_var112) {
            ret = (*citr_var112).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_person_map_pargs::~Math_all_int32_person_map_pargs() {
    }

    int32_t Math_all_int32_person_map_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_person_map_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDSTRUCT, (*(value)).size());
        if (ret < 0) { return ret; }
        std::map<int32_t, Person> ::const_iterator citr_var113;
        for (citr_var113 = (*(value)).begin(); citr_var113 != (*(value)).end(); ++citr_var113) {
            ret = proto->writeInt32(citr_var113->first);
            if (ret < 0) { return ret; }
            ret = citr_var113->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_color_out_all_pargs::~Math_color_out_all_pargs() {
    }

    int32_t Math_color_out_all_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_out_all_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color1", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(color1)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_color_xx_pargs::~Math_color_xx_pargs() {
    }

    int32_t Math_color_xx_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_xx_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color1", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, (*(color1)).size());
        if (ret < 0) { return ret; }
        std::set<MyColor> ::const_iterator citr_var114;
        for (citr_var114 = (*(color1)).begin(); citr_var114 != (*(color1)).end(); ++citr_var114) {
            ret = proto->writeInt32((*citr_var114).get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color3", bgcc::IDMAP, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDINT32, (*(color3)).size());
        if (ret < 0) { return ret; }
        std::map<MyColor, MyColor> ::const_iterator citr_var115;
        for (citr_var115 = (*(color3)).begin(); citr_var115 != (*(color3)).end(); ++citr_var115) {
            ret = proto->writeInt32(citr_var115->first.get_value());
            if (ret < 0) { return ret; }
            ret = proto->writeInt32(citr_var115->second.get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_ping_result::Math_ping_result() {
    }

    Math_ping_result::~Math_ping_result() {
    }

    bool Math_ping_result::operator==(const Math_ping_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_ping_result::operator!=(const Math_ping_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_ping_result::operator< (const Math_ping_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_ping_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_ping_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_add_result::Math_add_result() {
    }

    Math_add_result::~Math_add_result() {
    }

    bool Math_add_result::operator==(const Math_add_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (sum != rhs.sum) {
            return false;
        }
        return true;
    }

    bool Math_add_result::operator!=(const Math_add_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_add_result::operator< (const Math_add_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(sum < rhs.sum)) {
            return false;
        }
        return true;
    }

    int32_t Math_add_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_add_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sum", bgcc::IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(sum);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_test_citizen_result::Math_test_citizen_result() {
    }

    Math_test_citizen_result::~Math_test_citizen_result() {
    }

    bool Math_test_citizen_result::operator==(const Math_test_citizen_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (outs != rhs.outs) {
            return false;
        }
        if (alls != rhs.alls) {
            return false;
        }
        return true;
    }

    bool Math_test_citizen_result::operator!=(const Math_test_citizen_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_test_citizen_result::operator< (const Math_test_citizen_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(outs < rhs.outs)) {
            return false;
        }
        if (!(alls < rhs.alls)) {
            return false;
        }
        return true;
    }

    int32_t Math_test_citizen_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_test_citizen_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSTRUCT, 0);
        if (ret < 0) { return ret; }
        ret = return_value.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("outs", bgcc::IDSTRUCT, 2);
        if (ret < 0) { return ret; }
        ret = outs.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("alls", bgcc::IDSTRUCT, 3);
        if (ret < 0) { return ret; }
        ret = alls.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_boolean_result::Math_get_boolean_result() {
    }

    Math_get_boolean_result::~Math_get_boolean_result() {
    }

    bool Math_get_boolean_result::operator==(const Math_get_boolean_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_boolean_result::operator!=(const Math_get_boolean_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_boolean_result::operator< (const Math_get_boolean_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_boolean_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_boolean_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDBOOL, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int8_result::Math_get_int8_result() {
    }

    Math_get_int8_result::~Math_get_int8_result() {
    }

    bool Math_get_int8_result::operator==(const Math_get_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int8_result::operator!=(const Math_get_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int8_result::operator< (const Math_get_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDBYTE, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeByte(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int16_result::Math_get_int16_result() {
    }

    Math_get_int16_result::~Math_get_int16_result() {
    }

    bool Math_get_int16_result::operator==(const Math_get_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int16_result::operator!=(const Math_get_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int16_result::operator< (const Math_get_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT16, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int32_result::Math_get_int32_result() {
    }

    Math_get_int32_result::~Math_get_int32_result() {
    }

    bool Math_get_int32_result::operator==(const Math_get_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int32_result::operator!=(const Math_get_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int32_result::operator< (const Math_get_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int64_result::Math_get_int64_result() {
    }

    Math_get_int64_result::~Math_get_int64_result() {
    }

    bool Math_get_int64_result::operator==(const Math_get_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int64_result::operator!=(const Math_get_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int64_result::operator< (const Math_get_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT64, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_float_result::Math_get_float_result() {
    }

    Math_get_float_result::~Math_get_float_result() {
    }

    bool Math_get_float_result::operator==(const Math_get_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_float_result::operator!=(const Math_get_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_float_result::operator< (const Math_get_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDFLOAT, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_string_result::Math_get_string_result() {
    }

    Math_get_string_result::~Math_get_string_result() {
    }

    bool Math_get_string_result::operator==(const Math_get_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_string_result::operator!=(const Math_get_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_result::operator< (const Math_get_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSTR, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeString(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_binary_result::Math_get_binary_result() {
    }

    Math_get_binary_result::~Math_get_binary_result() {
    }

    bool Math_get_binary_result::operator==(const Math_get_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_binary_result::operator!=(const Math_get_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_binary_result::operator< (const Math_get_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDBIN, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary(return_value.c_str(), return_value.size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_color_result::Math_get_color_result() {
    }

    Math_get_color_result::~Math_get_color_result() {
    }

    bool Math_get_color_result::operator==(const Math_get_color_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_color_result::operator!=(const Math_get_color_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_color_result::operator< (const Math_get_color_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_color_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_color_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_sequence_result::Math_get_sequence_result() {
    }

    Math_get_sequence_result::~Math_get_sequence_result() {
    }

    bool Math_get_sequence_result::operator==(const Math_get_sequence_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_sequence_result::operator!=(const Math_get_sequence_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_sequence_result::operator< (const Math_get_sequence_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_sequence_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_sequence_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var116;
        for (citr_var116 = return_value.begin(); citr_var116 != return_value.end(); ++citr_var116) {
            ret = proto->writeInt32((*citr_var116));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_string_set_result::Math_get_string_set_result() {
    }

    Math_get_string_set_result::~Math_get_string_set_result() {
    }

    bool Math_get_string_set_result::operator==(const Math_get_string_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_string_set_result::operator!=(const Math_get_string_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_set_result::operator< (const Math_get_string_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSET, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTR, return_value.size());
        if (ret < 0) { return ret; }
        std::set<std::string> ::const_iterator citr_var117;
        for (citr_var117 = return_value.begin(); citr_var117 != return_value.end(); ++citr_var117) {
            ret = proto->writeString((*citr_var117));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int_str_map_result::Math_get_int_str_map_result() {
    }

    Math_get_int_str_map_result::~Math_get_int_str_map_result() {
    }

    bool Math_get_int_str_map_result::operator==(const Math_get_int_str_map_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int_str_map_result::operator!=(const Math_get_int_str_map_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int_str_map_result::operator< (const Math_get_int_str_map_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int_str_map_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int_str_map_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDMAP, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT64, bgcc::IDSTR, return_value.size());
        if (ret < 0) { return ret; }
        std::map<int64_t, std::string> ::const_iterator citr_var118;
        for (citr_var118 = return_value.begin(); citr_var118 != return_value.end(); ++citr_var118) {
            ret = proto->writeInt64(citr_var118->first);
            if (ret < 0) { return ret; }
            ret = proto->writeString(citr_var118->second);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_bool_set_sequence_result::Math_get_bool_set_sequence_result() {
    }

    Math_get_bool_set_sequence_result::~Math_get_bool_set_sequence_result() {
    }

    bool Math_get_bool_set_sequence_result::operator==(const Math_get_bool_set_sequence_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_bool_set_sequence_result::operator!=(const Math_get_bool_set_sequence_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_bool_set_sequence_result::operator< (const Math_get_bool_set_sequence_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_bool_set_sequence_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_bool_set_sequence_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSET, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<std::set<bool> > ::const_iterator citr_var119;
        for (citr_var119 = return_value.begin(); citr_var119 != return_value.end(); ++citr_var119) {
            ret = proto->writeSetBegin(bgcc::IDBOOL, (*citr_var119).size());
            if (ret < 0) { return ret; }
            std::set<bool> ::const_iterator citr_var120;
            for (citr_var120 = (*citr_var119).begin(); citr_var120 != (*citr_var119).end(); ++citr_var120) {
                ret = proto->writeBool((*citr_var120));
                if (ret < 0) { return ret; }
            }
            ret = proto->writeSetEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_person_result::Math_get_person_result() {
    }

    Math_get_person_result::~Math_get_person_result() {
    }

    bool Math_get_person_result::operator==(const Math_get_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_person_result::operator!=(const Math_get_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_person_result::operator< (const Math_get_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSTRUCT, 0);
        if (ret < 0) { return ret; }
        ret = return_value.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons_result::Math_get_persons_result() {
    }

    Math_get_persons_result::~Math_get_persons_result() {
    }

    bool Math_get_persons_result::operator==(const Math_get_persons_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons_result::operator!=(const Math_get_persons_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons_result::operator< (const Math_get_persons_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var121;
        for (citr_var121 = return_value.begin(); citr_var121 != return_value.end(); ++citr_var121) {
            ret = (*citr_var121).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons2_result::Math_get_persons2_result() {
    }

    Math_get_persons2_result::~Math_get_persons2_result() {
    }

    bool Math_get_persons2_result::operator==(const Math_get_persons2_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons2_result::operator!=(const Math_get_persons2_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons2_result::operator< (const Math_get_persons2_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons2_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons2_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSET, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTRUCT, return_value.size());
        if (ret < 0) { return ret; }
        std::set<Person> ::const_iterator citr_var122;
        for (citr_var122 = return_value.begin(); citr_var122 != return_value.end(); ++citr_var122) {
            ret = (*citr_var122).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons3_result::Math_get_persons3_result() {
    }

    Math_get_persons3_result::~Math_get_persons3_result() {
    }

    bool Math_get_persons3_result::operator==(const Math_get_persons3_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons3_result::operator!=(const Math_get_persons3_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons3_result::operator< (const Math_get_persons3_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons3_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons3_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDMAP, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDSTRUCT, bgcc::IDSTRUCT, return_value.size());
        if (ret < 0) { return ret; }
        std::map<Person, Person> ::const_iterator citr_var123;
        for (citr_var123 = return_value.begin(); citr_var123 != return_value.end(); ++citr_var123) {
            ret = citr_var123->first.write(proto);
            if (ret < 0) { return ret; }
            ret = citr_var123->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons4_result::Math_get_persons4_result() {
    }

    Math_get_persons4_result::~Math_get_persons4_result() {
    }

    bool Math_get_persons4_result::operator==(const Math_get_persons4_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons4_result::operator!=(const Math_get_persons4_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons4_result::operator< (const Math_get_persons4_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons4_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons4_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSET, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<std::set<Person> > ::const_iterator citr_var124;
        for (citr_var124 = return_value.begin(); citr_var124 != return_value.end(); ++citr_var124) {
            ret = proto->writeSetBegin(bgcc::IDSTRUCT, (*citr_var124).size());
            if (ret < 0) { return ret; }
            std::set<Person> ::const_iterator citr_var125;
            for (citr_var125 = (*citr_var124).begin(); citr_var125 != (*citr_var124).end(); ++citr_var125) {
                ret = (*citr_var125).write(proto);
                if (ret < 0) { return ret; }
            }
            ret = proto->writeSetEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_bool_result::Math_send_bool_result() {
    }

    Math_send_bool_result::~Math_send_bool_result() {
    }

    bool Math_send_bool_result::operator==(const Math_send_bool_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_bool_result::operator!=(const Math_send_bool_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_bool_result::operator< (const Math_send_bool_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_bool_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_bool_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int8_result::Math_send_int8_result() {
    }

    Math_send_int8_result::~Math_send_int8_result() {
    }

    bool Math_send_int8_result::operator==(const Math_send_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int8_result::operator!=(const Math_send_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int8_result::operator< (const Math_send_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int16_result::Math_send_int16_result() {
    }

    Math_send_int16_result::~Math_send_int16_result() {
    }

    bool Math_send_int16_result::operator==(const Math_send_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int16_result::operator!=(const Math_send_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int16_result::operator< (const Math_send_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int32_result::Math_send_int32_result() {
    }

    Math_send_int32_result::~Math_send_int32_result() {
    }

    bool Math_send_int32_result::operator==(const Math_send_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int32_result::operator!=(const Math_send_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_result::operator< (const Math_send_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int64_result::Math_send_int64_result() {
    }

    Math_send_int64_result::~Math_send_int64_result() {
    }

    bool Math_send_int64_result::operator==(const Math_send_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int64_result::operator!=(const Math_send_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int64_result::operator< (const Math_send_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_float_result::Math_send_float_result() {
    }

    Math_send_float_result::~Math_send_float_result() {
    }

    bool Math_send_float_result::operator==(const Math_send_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_float_result::operator!=(const Math_send_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_float_result::operator< (const Math_send_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_string_result::Math_send_string_result() {
    }

    Math_send_string_result::~Math_send_string_result() {
    }

    bool Math_send_string_result::operator==(const Math_send_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_string_result::operator!=(const Math_send_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_string_result::operator< (const Math_send_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_binary_result::Math_send_binary_result() {
    }

    Math_send_binary_result::~Math_send_binary_result() {
    }

    bool Math_send_binary_result::operator==(const Math_send_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_binary_result::operator!=(const Math_send_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_binary_result::operator< (const Math_send_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_color_result::Math_send_color_result() {
    }

    Math_send_color_result::~Math_send_color_result() {
    }

    bool Math_send_color_result::operator==(const Math_send_color_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_color_result::operator!=(const Math_send_color_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_color_result::operator< (const Math_send_color_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_color_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_color_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_person_result::Math_send_person_result() {
    }

    Math_send_person_result::~Math_send_person_result() {
    }

    bool Math_send_person_result::operator==(const Math_send_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_person_result::operator!=(const Math_send_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_result::operator< (const Math_send_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int32_sequence_result::Math_send_int32_sequence_result() {
    }

    Math_send_int32_sequence_result::~Math_send_int32_sequence_result() {
    }

    bool Math_send_int32_sequence_result::operator==(const Math_send_int32_sequence_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int32_sequence_result::operator!=(const Math_send_int32_sequence_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_sequence_result::operator< (const Math_send_int32_sequence_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_sequence_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_sequence_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_persons_result::Math_send_persons_result() {
    }

    Math_send_persons_result::~Math_send_persons_result() {
    }

    bool Math_send_persons_result::operator==(const Math_send_persons_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_persons_result::operator!=(const Math_send_persons_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons_result::operator< (const Math_send_persons_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_persons2_result::Math_send_persons2_result() {
    }

    Math_send_persons2_result::~Math_send_persons2_result() {
    }

    bool Math_send_persons2_result::operator==(const Math_send_persons2_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_persons2_result::operator!=(const Math_send_persons2_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons2_result::operator< (const Math_send_persons2_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons2_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons2_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int32_set_seq_result::Math_send_int32_set_seq_result() {
    }

    Math_send_int32_set_seq_result::~Math_send_int32_set_seq_result() {
    }

    bool Math_send_int32_set_seq_result::operator==(const Math_send_int32_set_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int32_set_seq_result::operator!=(const Math_send_int32_set_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_set_seq_result::operator< (const Math_send_int32_set_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_set_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_set_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_persons3_result::Math_send_persons3_result() {
    }

    Math_send_persons3_result::~Math_send_persons3_result() {
    }

    bool Math_send_persons3_result::operator==(const Math_send_persons3_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_persons3_result::operator!=(const Math_send_persons3_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons3_result::operator< (const Math_send_persons3_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons3_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons3_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_person_vec_set_result::Math_send_person_vec_set_result() {
    }

    Math_send_person_vec_set_result::~Math_send_person_vec_set_result() {
    }

    bool Math_send_person_vec_set_result::operator==(const Math_send_person_vec_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_person_vec_set_result::operator!=(const Math_send_person_vec_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_vec_set_result::operator< (const Math_send_person_vec_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_vec_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_vec_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_boolean_result::Math_out_boolean_result() {
    }

    Math_out_boolean_result::~Math_out_boolean_result() {
    }

    bool Math_out_boolean_result::operator==(const Math_out_boolean_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_boolean_result::operator!=(const Math_out_boolean_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_boolean_result::operator< (const Math_out_boolean_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_boolean_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_boolean_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int8_result::Math_out_int8_result() {
    }

    Math_out_int8_result::~Math_out_int8_result() {
    }

    bool Math_out_int8_result::operator==(const Math_out_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int8_result::operator!=(const Math_out_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int8_result::operator< (const Math_out_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int16_result::Math_out_int16_result() {
    }

    Math_out_int16_result::~Math_out_int16_result() {
    }

    bool Math_out_int16_result::operator==(const Math_out_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int16_result::operator!=(const Math_out_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_result::operator< (const Math_out_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int32_result::Math_out_int32_result() {
    }

    Math_out_int32_result::~Math_out_int32_result() {
    }

    bool Math_out_int32_result::operator==(const Math_out_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int32_result::operator!=(const Math_out_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int32_result::operator< (const Math_out_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int64_result::Math_out_int64_result() {
    }

    Math_out_int64_result::~Math_out_int64_result() {
    }

    bool Math_out_int64_result::operator==(const Math_out_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int64_result::operator!=(const Math_out_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int64_result::operator< (const Math_out_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_float_result::Math_out_float_result() {
    }

    Math_out_float_result::~Math_out_float_result() {
    }

    bool Math_out_float_result::operator==(const Math_out_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_float_result::operator!=(const Math_out_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_float_result::operator< (const Math_out_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_string_result::Math_out_string_result() {
    }

    Math_out_string_result::~Math_out_string_result() {
    }

    bool Math_out_string_result::operator==(const Math_out_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_string_result::operator!=(const Math_out_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_result::operator< (const Math_out_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_binary_result::Math_out_binary_result() {
    }

    Math_out_binary_result::~Math_out_binary_result() {
    }

    bool Math_out_binary_result::operator==(const Math_out_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_binary_result::operator!=(const Math_out_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_binary_result::operator< (const Math_out_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary(value.c_str(), value.size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_person_result::Math_out_person_result() {
    }

    Math_out_person_result::~Math_out_person_result() {
    }

    bool Math_out_person_result::operator==(const Math_out_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (person != rhs.person) {
            return false;
        }
        return true;
    }

    bool Math_out_person_result::operator!=(const Math_out_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_person_result::operator< (const Math_out_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(person < rhs.person)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("person", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = person.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_seq_result::Math_out_seq_result() {
    }

    Math_out_seq_result::~Math_out_seq_result() {
    }

    bool Math_out_seq_result::operator==(const Math_out_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_seq_result::operator!=(const Math_out_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_seq_result::operator< (const Math_out_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, xxx.size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var126;
        for (citr_var126 = xxx.begin(); citr_var126 != xxx.end(); ++citr_var126) {
            ret = proto->writeInt32((*citr_var126));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_string_set_result::Math_out_string_set_result() {
    }

    Math_out_string_set_result::~Math_out_string_set_result() {
    }

    bool Math_out_string_set_result::operator==(const Math_out_string_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_string_set_result::operator!=(const Math_out_string_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_set_result::operator< (const Math_out_string_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTR, xxx.size());
        if (ret < 0) { return ret; }
        std::set<std::string> ::const_iterator citr_var127;
        for (citr_var127 = xxx.begin(); citr_var127 != xxx.end(); ++citr_var127) {
            ret = proto->writeString((*citr_var127));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int16_float_map_result::Math_out_int16_float_map_result() {
    }

    Math_out_int16_float_map_result::~Math_out_int16_float_map_result() {
    }

    bool Math_out_int16_float_map_result::operator==(const Math_out_int16_float_map_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_int16_float_map_result::operator!=(const Math_out_int16_float_map_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_float_map_result::operator< (const Math_out_int16_float_map_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_float_map_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_float_map_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT16, bgcc::IDFLOAT, xxx.size());
        if (ret < 0) { return ret; }
        std::map<int16_t, float> ::const_iterator citr_var128;
        for (citr_var128 = xxx.begin(); citr_var128 != xxx.end(); ++citr_var128) {
            ret = proto->writeInt16(citr_var128->first);
            if (ret < 0) { return ret; }
            ret = proto->writeFloat(citr_var128->second);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int_vec_set_result::Math_out_int_vec_set_result() {
    }

    Math_out_int_vec_set_result::~Math_out_int_vec_set_result() {
    }

    bool Math_out_int_vec_set_result::operator==(const Math_out_int_vec_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_int_vec_set_result::operator!=(const Math_out_int_vec_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int_vec_set_result::operator< (const Math_out_int_vec_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int_vec_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int_vec_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDLIST, xxx.size());
        if (ret < 0) { return ret; }
        std::set<std::vector<int32_t> > ::const_iterator citr_var129;
        for (citr_var129 = xxx.begin(); citr_var129 != xxx.end(); ++citr_var129) {
            ret = proto->writeListBegin(bgcc::IDINT32, (*citr_var129).size());
            if (ret < 0) { return ret; }
            std::vector<int32_t> ::const_iterator citr_var130;
            for (citr_var130 = (*citr_var129).begin(); citr_var130 != (*citr_var129).end(); ++citr_var130) {
                ret = proto->writeInt32((*citr_var130));
                if (ret < 0) { return ret; }
            }
            ret = proto->writeListEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_boolean_result::Math_all_boolean_result() {
    }

    Math_all_boolean_result::~Math_all_boolean_result() {
    }

    bool Math_all_boolean_result::operator==(const Math_all_boolean_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_boolean_result::operator!=(const Math_all_boolean_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_boolean_result::operator< (const Math_all_boolean_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_boolean_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_boolean_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int8_result::Math_all_int8_result() {
    }

    Math_all_int8_result::~Math_all_int8_result() {
    }

    bool Math_all_int8_result::operator==(const Math_all_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int8_result::operator!=(const Math_all_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int8_result::operator< (const Math_all_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int16_result::Math_all_int16_result() {
    }

    Math_all_int16_result::~Math_all_int16_result() {
    }

    bool Math_all_int16_result::operator==(const Math_all_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int16_result::operator!=(const Math_all_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int16_result::operator< (const Math_all_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_result::Math_all_int32_result() {
    }

    Math_all_int32_result::~Math_all_int32_result() {
    }

    bool Math_all_int32_result::operator==(const Math_all_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_result::operator!=(const Math_all_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_result::operator< (const Math_all_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int64_result::Math_all_int64_result() {
    }

    Math_all_int64_result::~Math_all_int64_result() {
    }

    bool Math_all_int64_result::operator==(const Math_all_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int64_result::operator!=(const Math_all_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int64_result::operator< (const Math_all_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_float_result::Math_all_float_result() {
    }

    Math_all_float_result::~Math_all_float_result() {
    }

    bool Math_all_float_result::operator==(const Math_all_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_float_result::operator!=(const Math_all_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_float_result::operator< (const Math_all_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_string_result::Math_all_string_result() {
    }

    Math_all_string_result::~Math_all_string_result() {
    }

    bool Math_all_string_result::operator==(const Math_all_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_string_result::operator!=(const Math_all_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_string_result::operator< (const Math_all_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_binary_result::Math_all_binary_result() {
    }

    Math_all_binary_result::~Math_all_binary_result() {
    }

    bool Math_all_binary_result::operator==(const Math_all_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_binary_result::operator!=(const Math_all_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_binary_result::operator< (const Math_all_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary(value.c_str(), value.size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_seq_result::Math_all_int32_seq_result() {
    }

    Math_all_int32_seq_result::~Math_all_int32_seq_result() {
    }

    bool Math_all_int32_seq_result::operator==(const Math_all_int32_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_seq_result::operator!=(const Math_all_int32_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_seq_result::operator< (const Math_all_int32_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, value.size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var131;
        for (citr_var131 = value.begin(); citr_var131 != value.end(); ++citr_var131) {
            ret = proto->writeInt32((*citr_var131));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_person_result::Math_all_person_result() {
    }

    Math_all_person_result::~Math_all_person_result() {
    }

    bool Math_all_person_result::operator==(const Math_all_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_result::operator!=(const Math_all_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_result::operator< (const Math_all_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = value.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_set_result::Math_all_int32_set_result() {
    }

    Math_all_int32_set_result::~Math_all_int32_set_result() {
    }

    bool Math_all_int32_set_result::operator==(const Math_all_int32_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_set_result::operator!=(const Math_all_int32_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_set_result::operator< (const Math_all_int32_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, value.size());
        if (ret < 0) { return ret; }
        std::set<int32_t> ::const_iterator citr_var132;
        for (citr_var132 = value.begin(); citr_var132 != value.end(); ++citr_var132) {
            ret = proto->writeInt32((*citr_var132));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_person_seq_result::Math_all_person_seq_result() {
    }

    Math_all_person_seq_result::~Math_all_person_seq_result() {
    }

    bool Math_all_person_seq_result::operator==(const Math_all_person_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_seq_result::operator!=(const Math_all_person_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_seq_result::operator< (const Math_all_person_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, value.size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var133;
        for (citr_var133 = value.begin(); citr_var133 != value.end(); ++citr_var133) {
            ret = (*citr_var133).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_person_map_result::Math_all_int32_person_map_result() {
    }

    Math_all_int32_person_map_result::~Math_all_int32_person_map_result() {
    }

    bool Math_all_int32_person_map_result::operator==(const Math_all_int32_person_map_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_person_map_result::operator!=(const Math_all_int32_person_map_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_person_map_result::operator< (const Math_all_int32_person_map_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_person_map_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_person_map_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDSTRUCT, value.size());
        if (ret < 0) { return ret; }
        std::map<int32_t, Person> ::const_iterator citr_var134;
        for (citr_var134 = value.begin(); citr_var134 != value.end(); ++citr_var134) {
            ret = proto->writeInt32(citr_var134->first);
            if (ret < 0) { return ret; }
            ret = citr_var134->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_color_out_all_result::Math_color_out_all_result() {
    }

    Math_color_out_all_result::~Math_color_out_all_result() {
    }

    bool Math_color_out_all_result::operator==(const Math_color_out_all_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color1 != rhs.color1) {
            return false;
        }
        if (color2 != rhs.color2) {
            return false;
        }
        return true;
    }

    bool Math_color_out_all_result::operator!=(const Math_color_out_all_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_out_all_result::operator< (const Math_color_out_all_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color1 < rhs.color1)) {
            return false;
        }
        if (!(color2 < rhs.color2)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_out_all_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_out_all_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color1", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(color1.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color2", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(color2.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_color_xx_result::Math_color_xx_result() {
    }

    Math_color_xx_result::~Math_color_xx_result() {
    }

    bool Math_color_xx_result::operator==(const Math_color_xx_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (color2 != rhs.color2) {
            return false;
        }
        if (color3 != rhs.color3) {
            return false;
        }
        return true;
    }

    bool Math_color_xx_result::operator!=(const Math_color_xx_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_xx_result::operator< (const Math_color_xx_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(color2 < rhs.color2)) {
            return false;
        }
        if (!(color3 < rhs.color3)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_xx_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_xx_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<MyColor> ::const_iterator citr_var135;
        for (citr_var135 = return_value.begin(); citr_var135 != return_value.end(); ++citr_var135) {
            ret = proto->writeInt32((*citr_var135).get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color2", bgcc::IDLIST, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, color2.size());
        if (ret < 0) { return ret; }
        std::vector<MyColor> ::const_iterator citr_var136;
        for (citr_var136 = color2.begin(); citr_var136 != color2.end(); ++citr_var136) {
            ret = proto->writeInt32((*citr_var136).get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color3", bgcc::IDMAP, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDINT32, color3.size());
        if (ret < 0) { return ret; }
        std::map<MyColor, MyColor> ::const_iterator citr_var137;
        for (citr_var137 = color3.begin(); citr_var137 != color3.end(); ++citr_var137) {
            ret = proto->writeInt32(citr_var137->first.get_value());
            if (ret < 0) { return ret; }
            ret = proto->writeInt32(citr_var137->second.get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_ping_presult::~Math_ping_presult() {
    }

    int32_t Math_ping_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_add_presult::~Math_add_presult() {
    }

    int32_t Math_add_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                int32_t ele_var138;
                ret = proto->readInt32(ele_var138);
                if (ret < 0) { return ret; }
                (*(return_value)) = ele_var138;
                break;
            case 3:
                ret = proto->readInt32((*(sum)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_test_citizen_presult::~Math_test_citizen_presult() {
    }

    int32_t Math_test_citizen_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = (*(return_value)).read(proto);
                if (ret < 0) { return ret; }
                break;
            case 2:
                ret = (*(outs)).read(proto);
                if (ret < 0) { return ret; }
                break;
            case 3:
                ret = (*(alls)).read(proto);
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_boolean_presult::~Math_get_boolean_presult() {
    }

    int32_t Math_get_boolean_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readBool((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_int8_presult::~Math_get_int8_presult() {
    }

    int32_t Math_get_int8_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readByte((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_int16_presult::~Math_get_int16_presult() {
    }

    int32_t Math_get_int16_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readInt16((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_int32_presult::~Math_get_int32_presult() {
    }

    int32_t Math_get_int32_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readInt32((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_int64_presult::~Math_get_int64_presult() {
    }

    int32_t Math_get_int64_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readInt64((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_float_presult::~Math_get_float_presult() {
    }

    int32_t Math_get_float_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readFloat((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_string_presult::~Math_get_string_presult() {
    }

    int32_t Math_get_string_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readString((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_binary_presult::~Math_get_binary_presult() {
    }

    int32_t Math_get_binary_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readBinary((*(return_value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_color_presult::~Math_get_color_presult() {
    }

    int32_t Math_get_color_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                int32_t ele_var139;
                ret = proto->readInt32(ele_var139);
                if (ret < 0) { return ret; }
                (*(return_value)) = ele_var139;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_sequence_presult::~Math_get_sequence_presult() {
    }

    int32_t Math_get_sequence_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var140;
                bgcc::DataTypeID etype_var141;

                ret = proto->readListBegin(etype_var141, size_var140);
                if (ret < 0) { return ret; }

                (*(return_value)).reserve(size_var140);
                for(int32_t i = 0; i < size_var140; ++i) {
                    int32_t value_var142;
                    ret = proto->readInt32(value_var142);
                    if (ret < 0) { return ret; }
                    (*(return_value)).push_back(value_var142);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_string_set_presult::~Math_get_string_set_presult() {
    }

    int32_t Math_get_string_set_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var143;
                bgcc::DataTypeID etype_var144;

                ret = proto->readSetBegin(etype_var144, size_var143);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var143; ++i) {
                    std::string value_var145;
                    ret = proto->readString(value_var145);
                    if (ret < 0) { return ret; }
                    (*(return_value)).insert(value_var145);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_int_str_map_presult::~Math_get_int_str_map_presult() {
    }

    int32_t Math_get_int_str_map_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var146;
                bgcc::DataTypeID ktype_var147;
                bgcc::DataTypeID vtype_var148;

                ret = proto->readMapBegin(ktype_var147, vtype_var148, size_var146);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var146; ++i) {
                    int64_t key_var149;

                    ret = proto->readInt64(key_var149);
                    if (ret < 0) { return ret; }

                    std::string& value_var150 = (*(return_value))[key_var149];
                    ret = proto->readString(value_var150);
                    if (ret < 0) { return ret; }
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_bool_set_sequence_presult::~Math_get_bool_set_sequence_presult() {
    }

    int32_t Math_get_bool_set_sequence_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var151;
                bgcc::DataTypeID etype_var152;

                ret = proto->readListBegin(etype_var152, size_var151);
                if (ret < 0) { return ret; }

                (*(return_value)).reserve(size_var151);
                for(int32_t i = 0; i < size_var151; ++i) {
                    std::set<bool>  value_var153;
                    value_var153.clear();

                    int32_t size_var154;
                    bgcc::DataTypeID etype_var155;

                    ret = proto->readSetBegin(etype_var155, size_var154);
                    if (ret < 0) { return ret; }

                    for(int32_t i = 0; i < size_var154; ++i) {
                        bool value_var156;
                        ret = proto->readBool(value_var156);
                        if (ret < 0) { return ret; }
                        value_var153.insert(value_var156);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                    (*(return_value)).push_back(value_var153);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_person_presult::~Math_get_person_presult() {
    }

    int32_t Math_get_person_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = (*(return_value)).read(proto);
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_persons_presult::~Math_get_persons_presult() {
    }

    int32_t Math_get_persons_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var157;
                bgcc::DataTypeID etype_var158;

                ret = proto->readListBegin(etype_var158, size_var157);
                if (ret < 0) { return ret; }

                (*(return_value)).reserve(size_var157);
                for(int32_t i = 0; i < size_var157; ++i) {
                    Person value_var159;
                    ret = value_var159.read(proto);
                    if (ret < 0) { return ret; }
                    (*(return_value)).push_back(value_var159);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_persons2_presult::~Math_get_persons2_presult() {
    }

    int32_t Math_get_persons2_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var160;
                bgcc::DataTypeID etype_var161;

                ret = proto->readSetBegin(etype_var161, size_var160);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var160; ++i) {
                    Person value_var162;
                    ret = value_var162.read(proto);
                    if (ret < 0) { return ret; }
                    (*(return_value)).insert(value_var162);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_persons3_presult::~Math_get_persons3_presult() {
    }

    int32_t Math_get_persons3_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var163;
                bgcc::DataTypeID ktype_var164;
                bgcc::DataTypeID vtype_var165;

                ret = proto->readMapBegin(ktype_var164, vtype_var165, size_var163);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var163; ++i) {
                    Person key_var166;

                    ret = key_var166.read(proto);
                    if (ret < 0) { return ret; }

                    Person& value_var167 = (*(return_value))[key_var166];
                    ret = value_var167.read(proto);
                    if (ret < 0) { return ret; }
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_get_persons4_presult::~Math_get_persons4_presult() {
    }

    int32_t Math_get_persons4_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var168;
                bgcc::DataTypeID etype_var169;

                ret = proto->readListBegin(etype_var169, size_var168);
                if (ret < 0) { return ret; }

                (*(return_value)).reserve(size_var168);
                for(int32_t i = 0; i < size_var168; ++i) {
                    std::set<Person>  value_var170;
                    value_var170.clear();

                    int32_t size_var171;
                    bgcc::DataTypeID etype_var172;

                    ret = proto->readSetBegin(etype_var172, size_var171);
                    if (ret < 0) { return ret; }

                    for(int32_t i = 0; i < size_var171; ++i) {
                        Person value_var173;
                        ret = value_var173.read(proto);
                        if (ret < 0) { return ret; }
                        value_var170.insert(value_var173);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                    (*(return_value)).push_back(value_var170);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_bool_presult::~Math_send_bool_presult() {
    }

    int32_t Math_send_bool_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_int8_presult::~Math_send_int8_presult() {
    }

    int32_t Math_send_int8_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_int16_presult::~Math_send_int16_presult() {
    }

    int32_t Math_send_int16_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_int32_presult::~Math_send_int32_presult() {
    }

    int32_t Math_send_int32_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_int64_presult::~Math_send_int64_presult() {
    }

    int32_t Math_send_int64_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_float_presult::~Math_send_float_presult() {
    }

    int32_t Math_send_float_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_string_presult::~Math_send_string_presult() {
    }

    int32_t Math_send_string_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_binary_presult::~Math_send_binary_presult() {
    }

    int32_t Math_send_binary_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_color_presult::~Math_send_color_presult() {
    }

    int32_t Math_send_color_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_person_presult::~Math_send_person_presult() {
    }

    int32_t Math_send_person_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_int32_sequence_presult::~Math_send_int32_sequence_presult() {
    }

    int32_t Math_send_int32_sequence_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_persons_presult::~Math_send_persons_presult() {
    }

    int32_t Math_send_persons_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_persons2_presult::~Math_send_persons2_presult() {
    }

    int32_t Math_send_persons2_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_int32_set_seq_presult::~Math_send_int32_set_seq_presult() {
    }

    int32_t Math_send_int32_set_seq_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_persons3_presult::~Math_send_persons3_presult() {
    }

    int32_t Math_send_persons3_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_send_person_vec_set_presult::~Math_send_person_vec_set_presult() {
    }

    int32_t Math_send_person_vec_set_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_boolean_presult::~Math_out_boolean_presult() {
    }

    int32_t Math_out_boolean_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBool((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_int8_presult::~Math_out_int8_presult() {
    }

    int32_t Math_out_int8_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readByte((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_int16_presult::~Math_out_int16_presult() {
    }

    int32_t Math_out_int16_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt16((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_int32_presult::~Math_out_int32_presult() {
    }

    int32_t Math_out_int32_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt32((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_int64_presult::~Math_out_int64_presult() {
    }

    int32_t Math_out_int64_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt64((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_float_presult::~Math_out_float_presult() {
    }

    int32_t Math_out_float_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readFloat((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_string_presult::~Math_out_string_presult() {
    }

    int32_t Math_out_string_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readString((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_binary_presult::~Math_out_binary_presult() {
    }

    int32_t Math_out_binary_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBinary((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_person_presult::~Math_out_person_presult() {
    }

    int32_t Math_out_person_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = (*(person)).read(proto);
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_seq_presult::~Math_out_seq_presult() {
    }

    int32_t Math_out_seq_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var174;
                bgcc::DataTypeID etype_var175;

                ret = proto->readListBegin(etype_var175, size_var174);
                if (ret < 0) { return ret; }

                (*(xxx)).reserve(size_var174);
                for(int32_t i = 0; i < size_var174; ++i) {
                    int32_t value_var176;
                    ret = proto->readInt32(value_var176);
                    if (ret < 0) { return ret; }
                    (*(xxx)).push_back(value_var176);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_string_set_presult::~Math_out_string_set_presult() {
    }

    int32_t Math_out_string_set_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var177;
                bgcc::DataTypeID etype_var178;

                ret = proto->readSetBegin(etype_var178, size_var177);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var177; ++i) {
                    std::string value_var179;
                    ret = proto->readString(value_var179);
                    if (ret < 0) { return ret; }
                    (*(xxx)).insert(value_var179);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_int16_float_map_presult::~Math_out_int16_float_map_presult() {
    }

    int32_t Math_out_int16_float_map_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var180;
                bgcc::DataTypeID ktype_var181;
                bgcc::DataTypeID vtype_var182;

                ret = proto->readMapBegin(ktype_var181, vtype_var182, size_var180);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var180; ++i) {
                    int16_t key_var183;

                    ret = proto->readInt16(key_var183);
                    if (ret < 0) { return ret; }

                    float& value_var184 = (*(xxx))[key_var183];
                    ret = proto->readFloat(value_var184);
                    if (ret < 0) { return ret; }
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_out_int_vec_set_presult::~Math_out_int_vec_set_presult() {
    }

    int32_t Math_out_int_vec_set_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var185;
                bgcc::DataTypeID etype_var186;

                ret = proto->readSetBegin(etype_var186, size_var185);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var185; ++i) {
                    std::vector<int32_t>  value_var187;
                    value_var187.clear();

                    int32_t size_var188;
                    bgcc::DataTypeID etype_var189;

                    ret = proto->readListBegin(etype_var189, size_var188);
                    if (ret < 0) { return ret; }

                    value_var187.reserve(size_var188);
                    for(int32_t i = 0; i < size_var188; ++i) {
                        int32_t value_var190;
                        ret = proto->readInt32(value_var190);
                        if (ret < 0) { return ret; }
                        value_var187.push_back(value_var190);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                    (*(xxx)).insert(value_var187);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_boolean_presult::~Math_all_boolean_presult() {
    }

    int32_t Math_all_boolean_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBool((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_int8_presult::~Math_all_int8_presult() {
    }

    int32_t Math_all_int8_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readByte((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_int16_presult::~Math_all_int16_presult() {
    }

    int32_t Math_all_int16_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt16((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_int32_presult::~Math_all_int32_presult() {
    }

    int32_t Math_all_int32_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt32((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_int64_presult::~Math_all_int64_presult() {
    }

    int32_t Math_all_int64_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt64((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_float_presult::~Math_all_float_presult() {
    }

    int32_t Math_all_float_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readFloat((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_string_presult::~Math_all_string_presult() {
    }

    int32_t Math_all_string_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readString((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_binary_presult::~Math_all_binary_presult() {
    }

    int32_t Math_all_binary_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBinary((*(value)));
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_int32_seq_presult::~Math_all_int32_seq_presult() {
    }

    int32_t Math_all_int32_seq_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var191;
                bgcc::DataTypeID etype_var192;

                ret = proto->readListBegin(etype_var192, size_var191);
                if (ret < 0) { return ret; }

                (*(value)).reserve(size_var191);
                for(int32_t i = 0; i < size_var191; ++i) {
                    int32_t value_var193;
                    ret = proto->readInt32(value_var193);
                    if (ret < 0) { return ret; }
                    (*(value)).push_back(value_var193);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_person_presult::~Math_all_person_presult() {
    }

    int32_t Math_all_person_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = (*(value)).read(proto);
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_int32_set_presult::~Math_all_int32_set_presult() {
    }

    int32_t Math_all_int32_set_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var194;
                bgcc::DataTypeID etype_var195;

                ret = proto->readSetBegin(etype_var195, size_var194);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var194; ++i) {
                    int32_t value_var196;
                    ret = proto->readInt32(value_var196);
                    if (ret < 0) { return ret; }
                    (*(value)).insert(value_var196);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_person_seq_presult::~Math_all_person_seq_presult() {
    }

    int32_t Math_all_person_seq_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var197;
                bgcc::DataTypeID etype_var198;

                ret = proto->readListBegin(etype_var198, size_var197);
                if (ret < 0) { return ret; }

                (*(value)).reserve(size_var197);
                for(int32_t i = 0; i < size_var197; ++i) {
                    Person value_var199;
                    ret = value_var199.read(proto);
                    if (ret < 0) { return ret; }
                    (*(value)).push_back(value_var199);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_all_int32_person_map_presult::~Math_all_int32_person_map_presult() {
    }

    int32_t Math_all_int32_person_map_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var200;
                bgcc::DataTypeID ktype_var201;
                bgcc::DataTypeID vtype_var202;

                ret = proto->readMapBegin(ktype_var201, vtype_var202, size_var200);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var200; ++i) {
                    int32_t key_var203;

                    ret = proto->readInt32(key_var203);
                    if (ret < 0) { return ret; }

                    Person& value_var204 = (*(value))[key_var203];
                    ret = value_var204.read(proto);
                    if (ret < 0) { return ret; }
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_color_out_all_presult::~Math_color_out_all_presult() {
    }

    int32_t Math_color_out_all_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                int32_t ele_var205;
                ret = proto->readInt32(ele_var205);
                if (ret < 0) { return ret; }
                (*(color1)) = ele_var205;
                break;
            case 2:
                int32_t ele_var206;
                ret = proto->readInt32(ele_var206);
                if (ret < 0) { return ret; }
                (*(color2)) = ele_var206;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    Math_color_xx_presult::~Math_color_xx_presult() {
    }

    int32_t Math_color_xx_presult::read(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(fname);
        if (ret < 0) { return ret; }

        while(true) {
            ret = proto->readFieldBegin(fname, ftype, fid);
            if (ret < 0) { return ret; }

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var207;
                bgcc::DataTypeID etype_var208;

                ret = proto->readListBegin(etype_var208, size_var207);
                if (ret < 0) { return ret; }

                (*(return_value)).reserve(size_var207);
                for(int32_t i = 0; i < size_var207; ++i) {
                    MyColor value_var209;
                    int32_t ele_var210;
                    ret = proto->readInt32(ele_var210);
                    if (ret < 0) { return ret; }
                    value_var209 = ele_var210;
                    (*(return_value)).push_back(value_var209);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 2:
                (*(color2)).clear();

                int32_t size_var211;
                bgcc::DataTypeID etype_var212;

                ret = proto->readListBegin(etype_var212, size_var211);
                if (ret < 0) { return ret; }

                (*(color2)).reserve(size_var211);
                for(int32_t i = 0; i < size_var211; ++i) {
                    MyColor value_var213;
                    int32_t ele_var214;
                    ret = proto->readInt32(ele_var214);
                    if (ret < 0) { return ret; }
                    value_var213 = ele_var214;
                    (*(color2)).push_back(value_var213);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 3:
                (*(color3)).clear();

                int32_t size_var215;
                bgcc::DataTypeID ktype_var216;
                bgcc::DataTypeID vtype_var217;

                ret = proto->readMapBegin(ktype_var216, vtype_var217, size_var215);
                if (ret < 0) { return ret; }

                for(int32_t i = 0; i < size_var215; ++i) {
                    MyColor key_var218;

                    int32_t ele_var219;
                    ret = proto->readInt32(ele_var219);
                    if (ret < 0) { return ret; }
                    key_var218 = ele_var219;

                    MyColor& value_var220 = (*(color3))[key_var218];
                    int32_t ele_var221;
                    ret = proto->readInt32(ele_var221);
                    if (ret < 0) { return ret; }
                    value_var220 = ele_var221;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        return proto->readStructEnd();
    }

    MathProxy::MathProxy(
        bgcc::ServerInfo serverinfo,
        int32_t nprotocols,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, nprotocols, mgr, tryCount, tryInterval),
        _use_existing_socket(false) {
            _whoami = "global.math.Math";
    }

    MathProxy::MathProxy(const std::string& proxy_name) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, NULL, 5, 500),
        _proxy_name(proxy_name), _use_existing_socket(true) {
            _whoami = "global.math.Math";
    }

    void MathProxy::ping(bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("ping", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_ping(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_ping(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_ping(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "ping", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_ping_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_ping(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_ping_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "ping") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    AddResult MathProxy::add(int32_t a, int32_t b, int32_t& sum, bool last) {
        AddResult return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("add", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_add(a, b, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_add(sum, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_add(const int32_t& a, const int32_t& b, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "add", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_add_pargs pargs;
        pargs.a = &a;
        pargs.b = &b;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    AddResult MathProxy::recv_add(int32_t& sum, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        AddResult ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_add_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "add") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        presult.sum = &sum;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    Citizen MathProxy::test_citizen(const Citizen& ins, Citizen& outs, Citizen& alls, bool last) {
        Citizen return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("test_citizen", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_test_citizen(ins, alls, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_test_citizen(outs, alls, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_test_citizen(const Citizen& ins, const Citizen& alls, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "test_citizen", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_test_citizen_pargs pargs;
        pargs.ins = &ins;
        pargs.alls = &alls;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Citizen MathProxy::recv_test_citizen(Citizen& outs, Citizen& alls, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        Citizen ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_test_citizen_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "test_citizen") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        presult.outs = &outs;
        presult.alls = &alls;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    bool MathProxy::get_boolean(bool last) {
        bool return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_boolean", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_boolean(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_boolean(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_boolean(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_boolean_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    bool MathProxy::recv_get_boolean(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        bool ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_boolean_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_boolean") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    int8_t MathProxy::get_int8(bool last) {
        int8_t return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_int8", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_int8(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_int8(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_int8(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int8_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int8_t MathProxy::recv_get_int8(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int8_t ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_int8_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_int8") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    int16_t MathProxy::get_int16(bool last) {
        int16_t return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_int16", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_int16(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_int16(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_int16(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int16_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int16_t MathProxy::recv_get_int16(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int16_t ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_int16_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_int16") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    int32_t MathProxy::get_int32(bool last) {
        int32_t return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_int32", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_int32(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_int32(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_int32(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int32_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int32_t MathProxy::recv_get_int32(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_int32_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_int32") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    int64_t MathProxy::get_int64(bool last) {
        int64_t return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_int64", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_int64(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_int64(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_int64(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int64_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int64_t MathProxy::recv_get_int64(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int64_t ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_int64_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_int64") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    float MathProxy::get_float(bool last) {
        float return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_float", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_float(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_float(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_float(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_float_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    float MathProxy::recv_get_float(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        float ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_float_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_float") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::string MathProxy::get_string(bool last) {
        std::string return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_string", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_string(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_string(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_string(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_string_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::string MathProxy::recv_get_string(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::string ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_string_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_string") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::string MathProxy::get_binary(bool last) {
        std::string return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_binary", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_binary(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_binary(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_binary(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_binary_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::string MathProxy::recv_get_binary(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::string ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_binary_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_binary") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    Color MathProxy::get_color(bool last) {
        Color return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_color", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_color(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_color(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_color(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_color", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_color_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Color MathProxy::recv_get_color(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        Color ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_color_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_color") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<int32_t>  MathProxy::get_sequence(bool last) {
        std::vector<int32_t>  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_sequence", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_sequence(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_sequence(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_sequence(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_sequence_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<int32_t>  MathProxy::recv_get_sequence(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::vector<int32_t>  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_sequence_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_sequence") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::set<std::string>  MathProxy::get_string_set(bool last) {
        std::set<std::string>  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_string_set", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_string_set(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_string_set(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_string_set(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_string_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_string_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::set<std::string>  MathProxy::recv_get_string_set(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::set<std::string>  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_string_set_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_string_set") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::map<int64_t, std::string>  MathProxy::get_int_str_map(bool last) {
        std::map<int64_t, std::string>  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_int_str_map", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_int_str_map(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_int_str_map(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_int_str_map(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int_str_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int_str_map_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::map<int64_t, std::string>  MathProxy::recv_get_int_str_map(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::map<int64_t, std::string>  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_int_str_map_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_int_str_map") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<std::set<bool> >  MathProxy::get_bool_set_sequence(bool last) {
        std::vector<std::set<bool> >  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_bool_set_sequence", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_bool_set_sequence(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_bool_set_sequence(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_bool_set_sequence(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_bool_set_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_bool_set_sequence_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<std::set<bool> >  MathProxy::recv_get_bool_set_sequence(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::vector<std::set<bool> >  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_bool_set_sequence_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_bool_set_sequence") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    Person MathProxy::get_person(bool last) {
        Person return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_person", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_person(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_person(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_person(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_person_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Person MathProxy::recv_get_person(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        Person ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_person_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_person") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<Person>  MathProxy::get_persons(bool last) {
        std::vector<Person>  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_persons", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_persons(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_persons(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_persons(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<Person>  MathProxy::recv_get_persons(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::vector<Person>  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_persons_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_persons") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::set<Person>  MathProxy::get_persons2(bool last) {
        std::set<Person>  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_persons2", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_persons2(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_persons2(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_persons2(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons2", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons2_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::set<Person>  MathProxy::recv_get_persons2(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::set<Person>  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_persons2_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_persons2") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::map<Person, Person>  MathProxy::get_persons3(bool last) {
        std::map<Person, Person>  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_persons3", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_persons3(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_persons3(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_persons3(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons3", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons3_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::map<Person, Person>  MathProxy::recv_get_persons3(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::map<Person, Person>  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_persons3_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_persons3") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<std::set<Person> >  MathProxy::get_persons4(bool last) {
        std::vector<std::set<Person> >  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("get_persons4", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_get_persons4(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_get_persons4(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_get_persons4(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons4", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons4_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<std::set<Person> >  MathProxy::recv_get_persons4(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::vector<std::set<Person> >  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_get_persons4_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "get_persons4") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    void MathProxy::send_bool(b_t value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_bool", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_bool(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_bool(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_bool(const b_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_bool", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_bool_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_bool(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_bool_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_bool") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int8(i8_t value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_int8", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_int8(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_int8(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_int8(const i8_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int8_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int8(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_int8_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_int8") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int16(i16_t value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_int16", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_int16(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_int16(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_int16(const i16_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int16_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int16(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_int16_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_int16") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int32(i32_t value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_int32", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_int32(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_int32(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_int32(const i32_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int32(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_int32_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_int32") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int64(i64_t value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_int64", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_int64(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_int64(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_int64(const i64_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int64_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int64(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_int64_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_int64") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_float(f_t value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_float", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_float(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_float(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_float(const f_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_float_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_float(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_float_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_float") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_string(const s_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_string", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_string(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_string(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_string(const s_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_string_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_string(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_string_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_string") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_binary(const bin_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_binary", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_binary(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_binary(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_binary(const bin_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_binary_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_binary(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_binary_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_binary") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_color(const Color& color, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_color", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_color(color, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_color(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_color(const Color& color, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_color", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_color_pargs pargs;
        pargs.color = &color;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_color(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_color_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_color") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_person(const MyPerson& person, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_person", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_person(person, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_person(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_person(const MyPerson& person, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_person_pargs pargs;
        pargs.person = &person;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_person(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_person_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_person") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int32_sequence(const std::vector<int32_t> & numbers, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_int32_sequence", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_int32_sequence(numbers, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_int32_sequence(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_int32_sequence(const std::vector<int32_t> & numbers, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_sequence_pargs pargs;
        pargs.numbers = &numbers;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int32_sequence(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_int32_sequence_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_int32_sequence") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_persons(const std::vector<Person> & persons, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_persons", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_persons(persons, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_persons(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_persons(const std::vector<Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_persons(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_persons_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_persons") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_persons2(const std::set<Person> & persons, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_persons2", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_persons2(persons, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_persons2(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_persons2(const std::set<Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons2", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons2_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_persons2(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_persons2_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_persons2") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int32_set_seq(const std::vector<std::set<int32_t> > & xx, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_int32_set_seq", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_int32_set_seq(xx, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_int32_set_seq(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_int32_set_seq(const std::vector<std::set<int32_t> > & xx, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32_set_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_set_seq_pargs pargs;
        pargs.xx = &xx;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int32_set_seq(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_int32_set_seq_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_int32_set_seq") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_persons3(const std::map<Person, Person> & persons, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_persons3", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_persons3(persons, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_persons3(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_persons3(const std::map<Person, Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons3", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons3_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_persons3(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_persons3_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_persons3") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_person_vec_set(const std::set<std::vector<Person> > & xxx, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("send_person_vec_set", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_send_person_vec_set(xxx, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_send_person_vec_set(prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_send_person_vec_set(const std::set<std::vector<Person> > & xxx, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_person_vec_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_person_vec_set_pargs pargs;
        pargs.xxx = &xxx;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_person_vec_set(bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_send_person_vec_set_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "send_person_vec_set") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_boolean(bool& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_boolean", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_boolean(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_boolean(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_boolean(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_boolean_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_boolean(bool& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_boolean_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_boolean") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int8(int8_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_int8", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_int8(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_int8(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_int8(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int8_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int8(int8_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_int8_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_int8") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int16(int16_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_int16", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_int16(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_int16(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_int16(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int16_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int16(int16_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_int16_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_int16") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int32(int32_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_int32", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_int32(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_int32(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_int32(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int32_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int32(int32_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_int32_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_int32") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int64(int64_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_int64", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_int64(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_int64(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_int64(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int64_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int64(int64_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_int64_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_int64") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_float(float& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_float", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_float(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_float(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_float(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_float_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_float(float& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_float_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_float") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_string(std::string& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_string", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_string(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_string(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_string(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_string_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_string(std::string& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_string_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_string") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_binary(std::string& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_binary", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_binary(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_binary(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_binary(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_binary_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_binary(std::string& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_binary_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_binary") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_person(Person& person, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_person", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_person(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_person(person, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_person(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_person_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_person(Person& person, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_person_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_person") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.person = &person;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_seq(std::vector<int32_t> & xxx, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_seq", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_seq(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_seq(xxx, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_seq(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_seq_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_seq(std::vector<int32_t> & xxx, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_seq_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_seq") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.xxx = &xxx;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_string_set(std::set<std::string> & xxx, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_string_set", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_string_set(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_string_set(xxx, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_string_set(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_string_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_string_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_string_set(std::set<std::string> & xxx, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_string_set_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_string_set") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.xxx = &xxx;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int16_float_map(std::map<int16_t, float> & xxx, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_int16_float_map", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_int16_float_map(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_int16_float_map(xxx, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_int16_float_map(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int16_float_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int16_float_map_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int16_float_map(std::map<int16_t, float> & xxx, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_int16_float_map_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_int16_float_map") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.xxx = &xxx;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int_vec_set(std::set<std::vector<int32_t> > & xxx, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("out_int_vec_set", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_out_int_vec_set(__seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_out_int_vec_set(xxx, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_out_int_vec_set(int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int_vec_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int_vec_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int_vec_set(std::set<std::vector<int32_t> > & xxx, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_out_int_vec_set_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "out_int_vec_set") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.xxx = &xxx;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_boolean(bool& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_boolean", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_boolean(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_boolean(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_boolean(const bool& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_boolean_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_boolean(bool& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_boolean_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_boolean") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int8(int8_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_int8", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_int8(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_int8(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_int8(const int8_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int8_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int8(int8_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_int8_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_int8") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int16(int16_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_int16", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_int16(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_int16(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_int16(const int16_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int16_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int16(int16_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_int16_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_int16") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32(int32_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_int32", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_int32(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_int32(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_int32(const int32_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32(int32_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_int32_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_int32") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int64(int64_t& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_int64", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_int64(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_int64(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_int64(const int64_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int64_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int64(int64_t& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_int64_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_int64") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_float(float& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_float", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_float(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_float(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_float(const float& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_float_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_float(float& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_float_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_float") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_string(std::string& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_string", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_string(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_string(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_string(const std::string& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_string_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_string(std::string& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_string_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_string") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_binary(std::string& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_binary", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_binary(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_binary(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_binary(const std::string& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_binary_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_binary(std::string& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_binary_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_binary") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32_seq(std::vector<int32_t> & value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_int32_seq", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_int32_seq(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_int32_seq(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_int32_seq(const std::vector<int32_t> & value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_seq_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32_seq(std::vector<int32_t> & value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_int32_seq_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_int32_seq") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_person(Person& value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_person", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_person(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_person(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_person(const Person& value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_person_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_person(Person& value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_person_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_person") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32_set(std::set<int32_t> & value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_int32_set", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_int32_set(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_int32_set(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_int32_set(const std::set<int32_t> & value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_set_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32_set(std::set<int32_t> & value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_int32_set_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_int32_set") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_person_seq(std::vector<Person> & value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_person_seq", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_person_seq(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_person_seq(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_person_seq(const std::vector<Person> & value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_person_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_person_seq_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_person_seq(std::vector<Person> & value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_person_seq_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_person_seq") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32_person_map(std::map<int32_t, Person> & value, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("all_int32_person_map", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_all_int32_person_map(value, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_all_int32_person_map(value, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_all_int32_person_map(const std::map<int32_t, Person> & value, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_person_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_person_map_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32_person_map(std::map<int32_t, Person> & value, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_all_int32_person_map_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "all_int32_person_map") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.value = &value;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    void MathProxy::color_out_all(MyColor& color1, MyColor& color2, bool last) {
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return ;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("color_out_all", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_color_out_all(color1, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        recv_color_out_all(color1, color2, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return ;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return ;
    }

    void MathProxy::send_color_out_all(const MyColor& color1, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "color_out_all", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_color_out_all_pargs pargs;
        pargs.color1 = &color1;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_color_out_all(MyColor& color1, MyColor& color2, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_color_out_all_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "color_out_all") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.color1 = &color1;
        presult.color2 = &color2;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return;
    }

    std::vector<MyColor>  MathProxy::color_xx(const std::set<MyColor> & color1, std::vector<MyColor> & color2, std::map<MyColor, MyColor> & color3, bool last) {
        std::vector<MyColor>  return_value;
        int32_t __seqid = 0;
        int tryCount = 0;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prot;
        bgcc::SharedPointer<bgcc::BinaryProtocol> prottmp;
        bgcc::SharedPointer<bgcc::ClientSocket> client;
        bgcc::SharedPointer<bgcc::ServerPeerSocket> sock;
RECON:
        if (tryCount++ > _tryCount) {
            set_errno(bgcc::E_BGCC_OUT_MAX_TRY_COUNT);
            return return_value;
        }

        if (tryCount > 1) {
            bgcc::TimeUtil::safe_sleep_ms(_tryInterval);
        }

        if (_use_existing_socket) {
            sock = bgcc::ConnectionManager::get_instance()->get_connection(_proxy_name);
            if (sock.is_valid()) {
                prot = bgcc::SharedPointer<bgcc::BinaryProtocol>(new bgcc::BinaryProtocol(sock));
            }else {
                goto RECON;
            }
        }
        else {
            if (0 != _protocols.get(prot,10)) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
                goto RECON;
            }
        }

        __get_ticket_id("color_xx", __seqid, last, prot, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (last) { __seqid *= -1; }
        send_color_xx(color1, color3, __seqid, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        return_value = recv_color_xx(color2, color3, prot);
        if (get_errno() < 0) {
            if (!_use_existing_socket) {
                client = bgcc::SharedPointer<bgcc::ClientSocket>(
                    new bgcc::ClientSocket(_serverinfo.getIP(),_serverinfo.getPort()));
                if (client.is_valid()) {
                    client->open();
                }
                prottmp = bgcc::SharedPointer<bgcc::BinaryProtocol>(
                    new bgcc::BinaryProtocol(client));
                _protocols.put(prottmp);
            }
            else {
#ifndef _WIN32
                close(sock->get_socket());
#endif
            }
            goto RECON;
        }

        if (!_use_existing_socket) {
            if (0 != _protocols.put(prot)) {
                set_errno(-1);
                return return_value;
            }
        }
        else {
            bgcc::ConnectionManager::get_instance()->enroll(_proxy_name, sock->get_socket());
        }
        return return_value;
    }

    void MathProxy::send_color_xx(const std::set<MyColor> & color1, const std::map<MyColor, MyColor> & color3, int32_t seqid, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret_code = 0;

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "color_xx", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_color_xx_pargs pargs;
        pargs.color1 = &color1;
        pargs.color3 = &color3;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<MyColor>  MathProxy::recv_color_xx(std::vector<MyColor> & color2, std::map<MyColor, MyColor> & color3, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        std::vector<MyColor>  ret_val;
        int32_t ret_code;
        std::string fname;
        bgcc::MsgTypeID  msg_type;
        int32_t msg_seqid;

        Math_color_xx_presult presult;
        ret_code = proto->readMessageBegin(fname, msg_type, msg_seqid);
        if (ret_code < 0) { goto end;}

        if (msg_type == ::bgcc::EXCEPTION) {
            int32_t remote_code = 0;
            ret_code = proto->readInt32(remote_code);
            if (ret_code == 0) { ret_code = remote_code; }
            goto end;
        }

        if (msg_type != ::bgcc::REPLY) {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        if (fname != "color_xx") {
            ret_code = proto->skip(bgcc::IDSTRUCT);
            if (ret_code < 0) { goto end;}
            ret_code = proto->readMessageEnd();
            if (ret_code < 0) { goto end;}
        }

        presult.return_value = &ret_val;
        presult.color2 = &color2;
        presult.color3 = &color3;
        ret_code = presult.read(proto);
        if (ret_code < 0) { goto end;}
        ret_code = proto->readMessageEnd();
        if (ret_code < 0) { goto end;}
end:
        set_errno(ret_code);
        return ret_val;
    }

    MathProcessor::MathProcessor(bgcc::SharedPointer<Math> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["ping"] = &MathProcessor::do_ping;
        __fun_map["add"] = &MathProcessor::do_add;
        __fun_map["test_citizen"] = &MathProcessor::do_test_citizen;
        __fun_map["get_boolean"] = &MathProcessor::do_get_boolean;
        __fun_map["get_int8"] = &MathProcessor::do_get_int8;
        __fun_map["get_int16"] = &MathProcessor::do_get_int16;
        __fun_map["get_int32"] = &MathProcessor::do_get_int32;
        __fun_map["get_int64"] = &MathProcessor::do_get_int64;
        __fun_map["get_float"] = &MathProcessor::do_get_float;
        __fun_map["get_string"] = &MathProcessor::do_get_string;
        __fun_map["get_binary"] = &MathProcessor::do_get_binary;
        __fun_map["get_color"] = &MathProcessor::do_get_color;
        __fun_map["get_sequence"] = &MathProcessor::do_get_sequence;
        __fun_map["get_string_set"] = &MathProcessor::do_get_string_set;
        __fun_map["get_int_str_map"] = &MathProcessor::do_get_int_str_map;
        __fun_map["get_bool_set_sequence"] = &MathProcessor::do_get_bool_set_sequence;
        __fun_map["get_person"] = &MathProcessor::do_get_person;
        __fun_map["get_persons"] = &MathProcessor::do_get_persons;
        __fun_map["get_persons2"] = &MathProcessor::do_get_persons2;
        __fun_map["get_persons3"] = &MathProcessor::do_get_persons3;
        __fun_map["get_persons4"] = &MathProcessor::do_get_persons4;
        __fun_map["send_bool"] = &MathProcessor::do_send_bool;
        __fun_map["send_int8"] = &MathProcessor::do_send_int8;
        __fun_map["send_int16"] = &MathProcessor::do_send_int16;
        __fun_map["send_int32"] = &MathProcessor::do_send_int32;
        __fun_map["send_int64"] = &MathProcessor::do_send_int64;
        __fun_map["send_float"] = &MathProcessor::do_send_float;
        __fun_map["send_string"] = &MathProcessor::do_send_string;
        __fun_map["send_binary"] = &MathProcessor::do_send_binary;
        __fun_map["send_color"] = &MathProcessor::do_send_color;
        __fun_map["send_person"] = &MathProcessor::do_send_person;
        __fun_map["send_int32_sequence"] = &MathProcessor::do_send_int32_sequence;
        __fun_map["send_persons"] = &MathProcessor::do_send_persons;
        __fun_map["send_persons2"] = &MathProcessor::do_send_persons2;
        __fun_map["send_int32_set_seq"] = &MathProcessor::do_send_int32_set_seq;
        __fun_map["send_persons3"] = &MathProcessor::do_send_persons3;
        __fun_map["send_person_vec_set"] = &MathProcessor::do_send_person_vec_set;
        __fun_map["out_boolean"] = &MathProcessor::do_out_boolean;
        __fun_map["out_int8"] = &MathProcessor::do_out_int8;
        __fun_map["out_int16"] = &MathProcessor::do_out_int16;
        __fun_map["out_int32"] = &MathProcessor::do_out_int32;
        __fun_map["out_int64"] = &MathProcessor::do_out_int64;
        __fun_map["out_float"] = &MathProcessor::do_out_float;
        __fun_map["out_string"] = &MathProcessor::do_out_string;
        __fun_map["out_binary"] = &MathProcessor::do_out_binary;
        __fun_map["out_person"] = &MathProcessor::do_out_person;
        __fun_map["out_seq"] = &MathProcessor::do_out_seq;
        __fun_map["out_string_set"] = &MathProcessor::do_out_string_set;
        __fun_map["out_int16_float_map"] = &MathProcessor::do_out_int16_float_map;
        __fun_map["out_int_vec_set"] = &MathProcessor::do_out_int_vec_set;
        __fun_map["all_boolean"] = &MathProcessor::do_all_boolean;
        __fun_map["all_int8"] = &MathProcessor::do_all_int8;
        __fun_map["all_int16"] = &MathProcessor::do_all_int16;
        __fun_map["all_int32"] = &MathProcessor::do_all_int32;
        __fun_map["all_int64"] = &MathProcessor::do_all_int64;
        __fun_map["all_float"] = &MathProcessor::do_all_float;
        __fun_map["all_string"] = &MathProcessor::do_all_string;
        __fun_map["all_binary"] = &MathProcessor::do_all_binary;
        __fun_map["all_int32_seq"] = &MathProcessor::do_all_int32_seq;
        __fun_map["all_person"] = &MathProcessor::do_all_person;
        __fun_map["all_int32_set"] = &MathProcessor::do_all_int32_set;
        __fun_map["all_person_seq"] = &MathProcessor::do_all_person_seq;
        __fun_map["all_int32_person_map"] = &MathProcessor::do_all_int32_person_map;
        __fun_map["color_out_all"] = &MathProcessor::do_color_out_all;
        __fun_map["color_xx"] = &MathProcessor::do_color_xx;
    }

    int32_t MathProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0;
        bgcc::MsgTypeID mtype;
        int32_t seqid;
        std::string fname;
        int32_t nread = 0;
        ret = proto->readMessageBegin(request, request_len, fname, mtype, seqid);
        if (ret < 0) { return ret;}
        nread += ret;
        if (mtype != ::bgcc::CALL){
            return -1;
        }
        return do_function__( request+nread, request_len-nread, proto, fname, seqid);
    }

    std::string MathProcessor::get_name() const {
        return "global.math.Math";
    }

    int32_t MathProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request,request_len,proto ,fname,seqid);
        }
        if (seqid < 0){
            seqid *= -1;
            void* rdata = NULL;
            int32_t rsize = 0;
            bgcc::Transaction* SharedPtr = bgcc::Transaction::get_instance();
            int32_t ret_code = SharedPtr->retrieveDataCopyByTicketId(seqid, &rdata, rsize);
            if (0 == ret_code) {
                ret = proto->getTransport()->write((void*)rdata, rsize);
                free(rdata);
                if(ret != 0) {
                    ret = proto->writeMessageBegin("global.math.Math",fname, ::bgcc::EXCEPTION, seqid);
                    if(ret < 0) { return ret;}
                    ret = proto->writeInt32(0);
                    if(ret < 0) { return ret;}
                    ret = proto->writeMessageEnd();
                }
                return ret;
            }
        }
        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t MathProcessor::do_ping(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_ping_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_ping_result result;
        __intf->ping(map);
        ret = proto->writeMessageBegin("global.math.Math", "ping", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_add(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_add_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_add_result result;
        result.return_value = __intf->add(args.a, args.b, result.sum, map);
        ret = proto->writeMessageBegin("global.math.Math", "add", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_test_citizen(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_test_citizen_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_test_citizen_result result;
        result.return_value = __intf->test_citizen(args.ins, result.outs, args.alls, map);
        result.alls = args.alls;
        ret = proto->writeMessageBegin("global.math.Math", "test_citizen", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_boolean(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_boolean_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_boolean_result result;
        result.return_value = __intf->get_boolean(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_boolean", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_int8_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_int8_result result;
        result.return_value = __intf->get_int8(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_int16_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_int16_result result;
        result.return_value = __intf->get_int16(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_int32_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_int32_result result;
        result.return_value = __intf->get_int32(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_int64_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_int64_result result;
        result.return_value = __intf->get_int64(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_float_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_float_result result;
        result.return_value = __intf->get_float(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_string_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_string_result result;
        result.return_value = __intf->get_string(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_binary_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_binary_result result;
        result.return_value = __intf->get_binary(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_color(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_color_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_color_result result;
        result.return_value = __intf->get_color(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_color", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_sequence(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_sequence_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_sequence_result result;
        result.return_value = __intf->get_sequence(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_sequence", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_string_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_string_set_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_string_set_result result;
        result.return_value = __intf->get_string_set(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_string_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int_str_map(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_int_str_map_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_int_str_map_result result;
        result.return_value = __intf->get_int_str_map(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int_str_map", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_bool_set_sequence(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_bool_set_sequence_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_bool_set_sequence_result result;
        result.return_value = __intf->get_bool_set_sequence(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_bool_set_sequence", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_person_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_person_result result;
        result.return_value = __intf->get_person(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_persons_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_persons_result result;
        result.return_value = __intf->get_persons(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons2(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_persons2_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_persons2_result result;
        result.return_value = __intf->get_persons2(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons2", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons3(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_persons3_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_persons3_result result;
        result.return_value = __intf->get_persons3(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons3", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons4(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_get_persons4_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_get_persons4_result result;
        result.return_value = __intf->get_persons4(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons4", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_bool(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_bool_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_bool_result result;
        __intf->send_bool(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_bool", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_int8_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_int8_result result;
        __intf->send_int8(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_int16_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_int16_result result;
        __intf->send_int16(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_int32_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_int32_result result;
        __intf->send_int32(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_int64_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_int64_result result;
        __intf->send_int64(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_float_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_float_result result;
        __intf->send_float(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_string_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_string_result result;
        __intf->send_string(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_binary_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_binary_result result;
        __intf->send_binary(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_color(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_color_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_color_result result;
        __intf->send_color(args.color, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_color", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_person_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_person_result result;
        __intf->send_person(args.person, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int32_sequence(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_int32_sequence_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_int32_sequence_result result;
        __intf->send_int32_sequence(args.numbers, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int32_sequence", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_persons(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_persons_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_persons_result result;
        __intf->send_persons(args.persons, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_persons", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_persons2(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_persons2_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_persons2_result result;
        __intf->send_persons2(args.persons, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_persons2", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int32_set_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_int32_set_seq_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_int32_set_seq_result result;
        __intf->send_int32_set_seq(args.xx, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int32_set_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_persons3(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_persons3_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_persons3_result result;
        __intf->send_persons3(args.persons, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_persons3", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_person_vec_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_send_person_vec_set_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_send_person_vec_set_result result;
        __intf->send_person_vec_set(args.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_person_vec_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_boolean(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_boolean_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_boolean_result result;
        __intf->out_boolean(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_boolean", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_int8_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_int8_result result;
        __intf->out_int8(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_int16_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_int16_result result;
        __intf->out_int16(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_int32_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_int32_result result;
        __intf->out_int32(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_int64_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_int64_result result;
        __intf->out_int64(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_float_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_float_result result;
        __intf->out_float(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_string_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_string_result result;
        __intf->out_string(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_binary_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_binary_result result;
        __intf->out_binary(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_person_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_person_result result;
        __intf->out_person(result.person, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_seq_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_seq_result result;
        __intf->out_seq(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_string_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_string_set_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_string_set_result result;
        __intf->out_string_set(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_string_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int16_float_map(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_int16_float_map_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_int16_float_map_result result;
        __intf->out_int16_float_map(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int16_float_map", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int_vec_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_out_int_vec_set_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_out_int_vec_set_result result;
        __intf->out_int_vec_set(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int_vec_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_boolean(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_boolean_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_boolean_result result;
        __intf->all_boolean(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_boolean", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_int8_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_int8_result result;
        __intf->all_int8(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_int16_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_int16_result result;
        __intf->all_int16(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_int32_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_int32_result result;
        __intf->all_int32(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_int64_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_int64_result result;
        __intf->all_int64(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_float_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_float_result result;
        __intf->all_float(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_string_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_string_result result;
        __intf->all_string(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_binary_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_binary_result result;
        __intf->all_binary(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_int32_seq_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_int32_seq_result result;
        __intf->all_int32_seq(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_person_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_person_result result;
        __intf->all_person(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_int32_set_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_int32_set_result result;
        __intf->all_int32_set(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_person_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_person_seq_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_person_seq_result result;
        __intf->all_person_seq(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_person_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32_person_map(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_all_int32_person_map_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_all_int32_person_map_result result;
        __intf->all_int32_person_map(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32_person_map", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_color_out_all(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_color_out_all_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_color_out_all_result result;
        __intf->color_out_all(args.color1, result.color2, map);
        result.color1 = args.color1;
        ret = proto->writeMessageBegin("global.math.Math", "color_out_all", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_color_xx(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = (int32_t)ntohl(*(uint32_t*)request);
        std::string proxy_name(request+4, proxy_name_len);
        request += 4 + proxy_name_len;
        request_len -= (proxy_name_len+4);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map["PeerIP"] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map["PeerPort"] = strPort;
        }
        map["ProxyName"] = proxy_name;

        Math_color_xx_args args;
        ret = args.read(proto, request, request_len);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd(request, request_len);
        if (ret < 0) { return ret; }

        Math_color_xx_result result;
        result.return_value = __intf->color_xx(args.color1, result.color2, args.color3, map);
        result.color3 = args.color3;
        ret = proto->writeMessageBegin("global.math.Math", "color_xx", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        bgcc::BinaryProtocol* protoptr = (bgcc::BinaryProtocol*)proto.get();
        void *p;
        int32_t size;
        int32_t retcode = protoptr->getDataCopy(&p, size);
        if (retcode != 0) {
            int32_t body_size;
            body_size = (int32_t)htonl(size - 20);
            memcpy((uint8_t*)p+16, &body_size, 4);
            bgcc::Transaction::get_instance()->saveDataByTicketId(seqid, p, size);
            free(p);
        }
        ret = proto->writeMessageEnd();
        return ret;
    }

}


