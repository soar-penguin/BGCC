/***************************************************************************
 * 
 * Copyright (c) 2011 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/



/**
 * @file client.cpp
 * @author liuxupeng(liuxupeng@baidu.com)
 * @date 2012/3/23 16:23:12
 * @version $Revision$ 
 * @brief demo client
 *  
 **/

#include <iostream>
#include <iomanip>
#include <limits.h>

#include <bgcc.h>
using namespace bgcc;

#include "math.h"
using namespace math;
using namespace common;

int main()
{

	log_open("bgcc.cfg");
	ServerInfo serverInfo("localhost", 8503);
	MathProxy proxy(serverInfo);

	proxy.ping();

	if (proxy.get_errno() != 0) {
		std::cerr << "Call proxy.ping failed" << std::endl;
		return 0;
	} else {
		std::cerr << "Call proxy.ping success" << std::endl;
	}

	int32_t a = 24;
	int32_t b = 8;
	int32_t sum;

	proxy.add(a, b, sum);
	if (proxy.get_errno() != 0) {
		std::cout << "Call proxy.add failed" << std::endl;
		return 0;
	} else {
		std::cout << a << "+" << b << "=" << sum << std::endl;
	}

	{
		Citizen citizen;
		citizen.name = "jack";
		citizen.age = 23;
		citizen.gender = Gender::MALE;
		Address address;
		address.city = "Beijing";
		address.road = "Xueyuan";
		address.number = 222;

		std::vector<std::string> v;
		v.push_back("first");
		v.push_back("second");
		v.push_back("third");
		citizen.children = v;

		citizen.xxx.insert(1);
		citizen.xxx.insert(2);
		citizen.xxx.insert(3);

		citizen.address = address;

		Citizen outs;

		Citizen alls;
		alls.name = "alls";
		alls.age = 34;
		alls.gender = Gender::MALE;
		alls.address = address;

		Citizen ret = proxy.test_citizen(citizen, outs, alls);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.test_citizen failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.test_citizen success." << std::endl;
			std::cout << "outs.name:" << outs.name << "\n";
			std::cout << "alls.name:" << alls.name << "\n";
			std::cout << "reutrn.name:" << ret.name << "\n";
			std::cout << "outs.age:" << outs.age << "\n";
			std::cout << "alls.age:" << alls.age << "\n";
			std::cout << "reutrn.age:" << ret.age << "\n";
			std::cout << "outs.gender:" << outs.gender.get_desc() << "\n";
			std::cout << "alls.gender:" << alls.gender.get_desc() << "\n";
			std::cout << "reutrn.gender:" << ret.gender.get_desc() << "\n";
			std::cout << "ret.address: "
					<< ret.address.city << " "
					<< ret.address.road << " "
					<< ret.address.number << std::endl;
			std::cout << "outs.address: "
					<< outs.address.city << " "
					<< outs.address.road << " "
					<< outs.address.number << std::endl;
			std::cout << "alls.address: "
					<< alls.address.city << " "
					<< alls.address.road << " "
					<< alls.address.number << std::endl;

			{
				std::map<int8_t, bool>::const_iterator citr;
				for (citr = alls.kkk.begin(); citr != alls.kkk.end(); ++citr) {
					std::cout << (int32_t)citr->first << " " << citr->second << std::endl;
				}
			}
		}
	}

	{
		Color color = proxy.get_color();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_color failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_color success: color: " << color << std::endl;
		}
	}

	{
		proxy.send_color(Color::RED);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_color failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.senc_color success" << std::endl;;
		}
	}

	{
		Color out_color;
		Color all_color(Color::RED);

		proxy.color_out_all(all_color, out_color);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.color_out_all failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.color_out_all success." << std::endl;;
			std::cout << "out_color: " << out_color.get_desc()  << std::endl;;
			std::cout << "all_color: " << all_color.get_desc()  << std::endl;;
		}
	}

	{
		std::string str;
		str = proxy.get_string();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_string failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_string success: string: " << str << std::endl;
		}
	}

	{
		bool b = true;
		b = proxy.get_boolean();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_boolean failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_boolean success: boolean: " << std::boolalpha << b << std::endl;
		}
	}

	{
		int8_t i8;
		i8 = proxy.get_int8();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_i8 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_i8 success: int8_t: " << (int32_t)i8 << std::endl;
		}
	}

	{
		int16_t i16;
		i16 = proxy.get_int16();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_i16 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_i16 success: int16_t: " << (int32_t)i16 << std::endl;
		}
	}

	{
		int32_t number = 8;
		number = proxy.get_int32();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_int32 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_int32 success: number: " << number << std::endl;
		}
	}

	{
		int64_t i64;
		i64 = proxy.get_int64();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_i64 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_i64 success: int64_t: " << i64 << std::endl;
		}
	}

	{
		float f;
		f = proxy.get_float();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_float failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_float success: float: " << f << std::endl;
		}
	}

	{
		std::string str;
		str = proxy.get_binary();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_binary failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_binary success: binary: " << str << std::endl;
		}
	}

	{
		std::vector<int32_t> vec;
		vec = proxy.get_sequence();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_sequence failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_sequence success: elements: " << std::endl;
			std::vector<int32_t>::const_iterator citr;
			for (citr = vec.begin(); citr != vec.end(); ++citr) {
				std::cout << *citr << " ";
			}
			std::cout << std::endl;
		}
	}

	{
		std::set<std::string> strs;
		strs = proxy.get_string_set();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_string_set failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_string_set success: elements: " << std::endl;
			std::set<std::string>::const_iterator citr;
			for (citr = strs.begin(); citr != strs.end(); ++citr) {
				std::cout << *citr << " ";
			}
			std::cout << std::endl;
		}
	}

	{
		std::map<int64_t, std::string> m;
		m = proxy.get_int_str_map();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_int_str_map failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_int_str_map success: elements: " << std::endl;
			std::map<int64_t, std::string>::const_iterator citr;
			for (citr = m.begin(); citr != m.end(); ++citr) {
				std::cout << citr->first << " " << citr->second << "\n";
			}
			std::cout << std::endl;
		}
	}

	{
		std::vector<std::set<bool> > bool_set_vec;
		bool_set_vec = proxy.get_bool_set_sequence();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_bool_set_sequence failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_bool_set_sequence success: elements: " << std::endl;
			std::vector<std::set<bool> >::const_iterator itr1;
			for (itr1 = bool_set_vec.begin(); itr1 != bool_set_vec.end(); ++itr1) {
				const std::set<bool>& s = *itr1;
				std::set<bool>::const_iterator itr2;

				for (itr2 = s.begin(); itr2 != s.end(); ++itr2) {
					std::cout << *itr2 << " ";
				}
				std::cout << std::endl;
			}
		}
	}

	{
		Person person;
		person = proxy.get_person();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_person failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_person success: person: " << std::endl;
			std::cout << "person.name: " << person.name << "\n";
			std::cout << "person.age: " << person.age << std::endl;
		}
	}

	{
		std::vector<Person> persons;
		persons = proxy.get_persons();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_persons failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_persons success: persons: " << std::endl;

			std::vector<Person>::const_iterator citr;
			for (citr = persons.begin(); citr != persons.end(); ++citr) {
				std::cout << "person.name: " << citr->name << "\n";
				std::cout << "person.age: " << citr->age << std::endl;
			}
		}
	}

	{
		std::set<Person> persons;
		persons = proxy.get_persons2();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_persons2 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_persons2 success: persons: " << std::endl;

			std::set<Person>::const_iterator citr;
			for (citr = persons.begin(); citr != persons.end(); ++citr) {
				std::cout << "person.name: " << citr->name << "\n";
				std::cout << "person.age: " << citr->age << std::endl;
			}
		}
	}

	{
		std::map<Person, Person> m;
		m = proxy.get_persons3();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_persons3 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_persons3 success: elements: " << std::endl;
			std::map<Person, Person>::const_iterator citr;
			for (citr = m.begin(); citr != m.end(); ++citr) {
				std::cout << citr->first.name << " " << citr->first.age<< "\t";
				std::cout << citr->second.name << " " << citr->second.age<< "\n";
			}
			std::cout << std::endl;
		}
	}

	{
		std::vector<std::set<Person> > person_set_vec;
		person_set_vec = proxy.get_persons4();
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.get_persons4 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.get_persons4 success: elements: " << std::endl;
			std::vector<std::set<Person> >::const_iterator itr1;
			for (itr1 = person_set_vec.begin(); itr1 != person_set_vec.end(); ++itr1) {
				const std::set<Person>& s = *itr1;
				std::set<Person>::const_iterator itr2;
				for (itr2 = s.begin(); itr2 != s.end(); ++itr2) {
					std::cout << itr2->name << " " << itr2->age << "\t";
				}
				std::cout << std::endl;
			}
		}

	}

	{
		bool value = true;
		proxy.send_bool(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_bool failed with value = " << value << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_bool success" << std::endl;
		}

		value = false;
		proxy.send_bool(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_bool failed with value = " << value << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_bool success" << std::endl;
		}
	}

	{
		int8_t value = 8;
		proxy.send_int8(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_int8 failed with value = " << (int32_t)value << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_int8 success" << std::endl;
		}
	}

	{
		int16_t value = 16;
		proxy.send_int16(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_int16 failed with value = " << (int32_t)value << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_int16 success" << std::endl;
		}
	}

	{
		int32_t value = 32;
		proxy.send_int32(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_int32 failed with value = " << (int32_t)value << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_int32 success" << std::endl;
		}
	}

	{
		int64_t value = 64;
		proxy.send_int64(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_int64 failed with value = " << (int64_t)value << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_int64 success" << std::endl;
		}
	}

	{
		std::string str = "hello, world";
		proxy.send_string(str);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_string failed with string = " << str << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_string success" << std::endl;
		}
	}

	{
		std::string str = "This is binary data \a";
		proxy.send_binary(str);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_binary failed with string = " << str << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_binary success" << std::endl;
		}
	}

	{
		std::vector<int32_t> vec;
		vec.push_back(1);
		vec.push_back(2);

		proxy.send_int32_sequence(vec);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_int32_sequence failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_int32_sequence success" << std::endl;
		}
	}

	{
		Person person;
		person.name = "jack";
		person.age = 3;
		proxy.send_person(person);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_person failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_person success" << std::endl;
		}
	}

	{
		std::vector<Person> persons;
		Person jack;
		jack.name = "jack";
		jack.age = 23;

		persons.push_back(jack);

		Person mery;
		mery.name = "Mery";
		mery.age = 34;

		persons.push_back(mery);

		proxy.send_persons(persons);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_persons failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_persons success" << std::endl;
		}
	}

	{
		std::set<Person> persons;
		Person jack;
		jack.name = "jack";
		jack.age = 23;

		persons.insert(jack);

		Person mery;
		mery.name = "Mery";
		mery.age = 34;

		persons.insert(mery);

		proxy.send_persons2(persons);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_persons2 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_persons2 success" << std::endl;
		}
	}

	{

		std::vector<std::set<int32_t> > v;

		std::set<int32_t> s1;
		s1.insert(3);
		s1.insert(2);
		s1.insert(1);

		v.push_back(s1);

		std::set<int32_t> s2;
		s2.insert(4);
		s2.insert(5);
		s2.insert(6);

		v.push_back(s2);
		proxy.send_int32_set_seq(v);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_int32_set_seq failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_int32_set_seq success" << std::endl;
		}
	}

	{
		std::map<Person, Person> p2p;

		Person jack;
		jack.name = "jack";
		jack.age = 33;

		Person mery;
		mery.name = "mery";
		mery.age = 23;

		p2p.insert(std::make_pair(jack, mery));
		p2p.insert(std::make_pair(mery, jack));

		proxy.send_persons3(p2p);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_persons3 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_person3 success" << std::endl;
		}
	}

	{
		std::set<std::vector<Person> > s;

		Person jack;
		jack.name = "jack";
		jack.age = 33;

		Person mery;
		mery.name = "mery";
		mery.age = 23;

		std::vector<Person> v1;
		v1.push_back(jack);
		v1.push_back(mery);

		s.insert(v1);

		std::vector<Person> v2;
		v2.push_back(mery);
		v2.push_back(jack);

		s.insert(v2);

		proxy.send_person_vec_set(s);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.send_person_vec_set failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.send_person_vec_set success" << std::endl;
		}
	}

	{
		bool value;
		proxy.out_boolean(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_boolean failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_boolean success value: " << std::boolalpha << value << std::endl;
		}
	}

	{
		int8_t value;
		proxy.out_int8(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_int8 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_int8 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		int16_t value;
		proxy.out_int16(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_int16 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_int16 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		int32_t value;
		proxy.out_int32(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_int32 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_int32 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		int64_t value;
		proxy.out_int64(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_int64 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_int64 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		std::string value;
		proxy.out_string(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_string failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_string success value: " << value << std::endl;
		}
	}

	{
		std::string value;
		proxy.out_binary(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_binary failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_binary success value: " << value << std::endl;
		}
	}

	{
		float value;
		proxy.out_float(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_float failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_float success value: " << value << std::endl;
		}
	}

	{
		std::vector<int32_t> v;
		proxy.out_seq(v);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_seq failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_seq success values: " << std::endl;
			std::vector<int32_t>::const_iterator citr;
			for (citr = v.begin(); citr != v.end(); ++citr) {
				std::cout << *citr << " ";
			}
			std::cout << std::endl;
		}
	}

	{
		std::set<std::string> v;
		proxy.out_string_set(v);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_string_set failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_string_set success values: " << std::endl;
			std::set<std::string>::const_iterator citr;
			for (citr = v.begin(); citr != v.end(); ++citr) {
				std::cout << *citr << " ";
			}
			std::cout << std::endl;
		}
	}

	{
		std::map<int16_t, float> m;
		proxy.out_int16_float_map(m);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_int16_float_map failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_int16_float_map success values: " << std::endl;
			std::map<int16_t, float>::const_iterator citr;
			for (citr = m.begin(); citr != m.end(); ++citr) {
				std::cout << citr->first << " " << citr->second << "\n";
			}
			std::cout << std::endl;
		}
	}

	{
		std::set<std::vector<int32_t> > s;
		proxy.out_int_vec_set(s);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_int_vec_set failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_int_vec_set success values: " << std::endl;
			std::set<std::vector<int32_t> >::const_iterator itr1;
			for (itr1 = s.begin(); itr1 != s.end(); ++itr1) {
				const std::vector<int32_t>& v = *itr1;
				std::vector<int32_t>::const_iterator itr2;
				for (itr2 = v.begin(); itr2 != v.end(); ++itr2) {
					std::cout << *itr2 << " ";
				}
				std::cout << std::endl;
			}
		}
	}

	{
		bool value = false;
		proxy.all_boolean(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_boolean failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_boolean success value: " << std::boolalpha << value << std::endl;
		}
	}

	{
		int8_t value = 8;
		proxy.all_int8(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_int8 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_int8 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		int16_t value = 16;
		proxy.all_int16(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_int16 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_int16 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		int32_t value = 32;
		proxy.all_int32(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_int32 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_int32 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		int64_t value = 64;
		proxy.all_int64(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_int64 failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_int64 success value: " << (int32_t)value << std::endl;
		}
	}

	{
		std::string value = "This is a string";
		proxy.all_string(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_string failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_string success value: " << value << std::endl;
		}
	}

	{
		std::string value = "This is a data";
		proxy.all_binary(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_binary failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_binary success value: " << value << std::endl;
		}
	}

	{
		float value = 3.3f;
		proxy.all_float(value);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_float failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_float success value: " << value << std::endl;
		}
	}

	{
		std::vector<int32_t> numbers;
		numbers.push_back(123);
		numbers.push_back(456);
		numbers.push_back(789);

		proxy.all_int32_seq(numbers);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_int32_seq failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_int32_seq success values: " << std::endl;
			std::vector<int32_t>::const_iterator citr;
			for (citr = numbers.begin(); citr != numbers.end(); ++citr) {
				std::cout << *citr << " ";
			}
			std::cout << std::endl;
		}
	}

	{
		Person person;
		proxy.out_person(person);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.out_person failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.out_person success: person: " << std::endl;
			std::cout << "person.name: " << person.name << "\n";
			std::cout << "person.age: " << person.age << std::endl;
		}
	}

	{
		Person person;
		person.name = "jack";
		person.age = 101;
		proxy.all_person(person);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_person failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_person success: person: " << std::endl;
			std::cout << "person.name: " << person.name << "\n";
			std::cout << "person.age: " << person.age << std::endl;
		}
	}

	{
		std::set<int32_t> numbers;
		numbers.insert(123);
		numbers.insert(456);
		numbers.insert(789);

		proxy.all_int32_set(numbers);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_int32_set failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_int32_set success values: " << std::endl;
			std::set<int32_t>::const_iterator citr;
			for (citr = numbers.begin(); citr != numbers.end(); ++citr) {
				std::cout << *citr << " ";
			}
			std::cout << std::endl;
		}
	}

	{
		std::vector<Person> persons;
		Person person;
		person.name = "jack";
		person.age = 101;
		persons.push_back(person);

		person.name = "mery";
		person.age = 100;
		persons.push_back(person);
		
		proxy.all_person_seq(persons);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_person_seq failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_person_seq success: persons: " << std::endl;

			std::vector<Person>::const_iterator citr;
			for (citr = persons.begin(); citr != persons.end(); ++citr) {
				std::cout << "person.name: " << citr->name << "\n";
				std::cout << "person.age: " << citr->age << std::endl;
			}
		}
	}

	{
		std::map<int32_t, Person> m;
		Person person;
		person.name = "jack";
		person.age = 23;
		m.insert(std::make_pair(1, person));

		person.name = "mery";
		person.age = 22;
		m.insert(std::make_pair(2, person));

		proxy.all_int32_person_map(m);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.all_int32_person_map failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.all_int32_person_map success: values: " << std::endl;
			std::map<int32_t, Person>::const_iterator citr;
			for (citr = m.begin(); citr != m.end(); ++citr) {
				std::cout << citr->first << " " << citr->second.name << " " << citr->second.age << "\n";
			}
			std::cout << std::endl;
		}
	}

	{
		std::vector<Color> ret;
		std::vector<Color> outs;
		std::set<Color> ins;
		std::map<Color, Color> alls;

		ins.insert(Color::RED);
		alls.insert(std::make_pair(Color(Color::BLUE), Color(Color::RED)));
		alls.insert(std::make_pair(Color(Color::RED), Color(Color::GREEN)));

		ret = proxy.color_xx(ins, outs, alls);
		if (proxy.get_errno() != 0) {
			std::cout << "Call proxy.color_xx failed" << std::endl;
			return 0;
		} else {
			std::cout << "Call proxy.color_xx success: values: " << std::endl;
			{
				std::vector<Color>::const_iterator citr;
				for (citr = ret.begin(); citr != ret.end(); ++citr) {
					std::cout << citr->get_value() << " " << citr->get_desc() << std::endl;
				}
			}

			{
				std::vector<Color>::const_iterator citr;
				for (citr = outs.begin(); citr != outs.end(); ++citr) {
					std::cout << citr->get_value() << " " << citr->get_desc() << std::endl;
				}
			}

			{
				std::map<Color, Color>::const_iterator citr;
				for (citr = alls.begin(); citr != alls.end(); ++citr) {
					std::cout << "key: " << citr->first.get_value() << " " << citr->first.get_desc() <<
						" value: " << citr->second.get_value() << " " << citr->second.get_desc() << std::endl;
				}
			}
		}
	}

	return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
