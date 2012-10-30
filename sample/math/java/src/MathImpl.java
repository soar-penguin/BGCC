import bgcc.*;
import math.*;
import common.*;
import java.util.*;

public class MathImpl implements math.Math.Intf {

	public Citizen test_citizen(Citizen ins, CitizenHolder outs, CitizenHolder alls) {
		System.err.println("Enter test_citizen");
		System.err.println("ins.name:" + ins.getName());
		System.err.println("ins.age:" + ins.getAge());
		System.err.println("ins.gender:" + ins.getGender());
		System.err.println("ins.address:" + ins.getAddress().getCity()
				+ " " + ins.getAddress().getRoad()
				+ " " + ins.getAddress().getNumber());
		System.err.println("ins.children:" + ins.getChildren());
		System.err.println("ins.xxx:" + ins.getXxx());
		System.err.println("ins.kkk:" + ins.getKkk());

		System.err.println("alls.name:" + alls.value.getName());
		System.err.println("alls.age:" + alls.value.getAge());
		System.err.println("alls.gender:" + alls.value.getGender());
		System.err.println("alls.xxx:" + alls.value.getXxx());
		System.err.println("alls.kkk:" + alls.value.getKkk());

		Citizen citizen = new Citizen();
		citizen.setName("mery");
		citizen.setAge(3333);
		citizen.setGender(Gender.MALE);

		Address address = new Address();
		address.setCity("beijing");
		address.setRoad("xinhua");
		address.setNumber(100);

		citizen.setAddress(address);

		List<String> children = new ArrayList<String>();
		children.add("server kiki");
		children.add("server ffff");

		citizen.setChildren(children);

		Set<Integer> xxx = new HashSet<Integer>();
		xxx.add(33);
		xxx.add(34);
		xxx.add(35);

		citizen.setXxx(xxx);

		Map<Byte, Boolean> kkk = new HashMap<Byte, Boolean>();
		kkk.put(new Byte("0"), new Boolean(true));

		citizen.setKkk(kkk);

		outs.value = citizen;
		alls.value = citizen;
		System.err.println("Leave test_citizen\n");
		return citizen;
	}

	public void ping() {
		System.err.println("Enter ping");
		System.err.println("Leave ping\n");
	}

	public AddResult add(int a, int b, IntHolder sum) {
		System.err.println("Enter add[a: " + a + " b: " + b + "]");
		sum.value = a + b;
		System.err.println("Leave add[sum: " + sum.value + "]\n");
		return AddResult.E_SUCCESS;
	}

	public boolean get_boolean() {
		System.err.println("Enter get_boolean");
		System.err.println("Leave get_boolean\n");
		return false;
	}

	public byte get_int8() {
		System.err.println("Enter get_int8");
		System.err.println("Leave get_int8\n");
		return 8;
	}

	public short get_int16() {
		System.err.println("Enter get_int16");
		System.err.println("Leave get_int16\n");
		return 16;
	}

	public int get_int32() {
		System.err.println("Enter get_int32");
		System.err.println("Leave get_int32\n");
		return 100;
	}

	public long get_int64() {
		System.err.println("Enter get_int64");
		System.err.println("Leave get_int64\n");
		return 64;
	}

	public float get_float() {
		System.err.println("Enter get_float");
		System.err.println("Leave get_float\n");
		return 3.3f;
	}

	public java.lang.String get_string() {
		System.err.println("Enter get_string");
		System.err.println("Leave get_string\n");
		return "This is a string";
	}

	public java.lang.String get_binary() {
		System.err.println("Enter get_binary");
		System.err.println("Leave get_binary\n");
		return "This is binary, bla bla bla";
	}

	public Color get_color() {
		System.err.println("Enter get_color");
		System.err.println("Leave get_color\n");
		return Color.BLUE;
	}

	public List<Integer> get_sequence() {
		System.err.println("Enter get_sequence");
		ArrayList<Integer> seq = new ArrayList<Integer>();
		seq.add(3);
		seq.add(2);
		seq.add(1);
		System.err.println("Leave get_sequence\n");
		return seq;
	}

	public Set<String> get_string_set() {
		System.err.println("Enter get_string_set");
		Set<String> strs = new HashSet<String>();
		strs.add("bbb");
		strs.add("aaa");
		strs.add("ccc");
		System.err.println("Leave get_string_set\n");
		return strs;
	}

	public Map<Long, String> get_int_str_map() {
		System.err.println("Enter get_int_str_map");
		Map<Long, String> m = new HashMap<Long, String>();
		m.put(new Long(1), "first");
		m.put(new Long(2), "second");
		m.put(new Long(3), "third");
		System.err.println("Leave get_int_str_map\n");
		return m;
	}

	public List<Set<Boolean>> get_bool_set_sequence() {
		System.err.println("Enter get_bool_set_sequence");
		List<Set<Boolean>> ret = new ArrayList<Set<Boolean>>();
		
		HashSet<Boolean> s1 = new HashSet<Boolean>();
		s1.add(new Boolean(true));
		s1.add(new Boolean(false));
		ret.add(s1);

		HashSet<Boolean> s2 = new HashSet<Boolean>();
		s2.add(new Boolean(false));
		s2.add(new Boolean(false));
		ret.add(s2);

		System.err.println("Leave get_bool_set_sequence\n");
		return ret;
	}

	public Person get_person() {
		System.err.println("Enter get_person");
		Person person = new Person();
		person.setName("Jack");
		person.setAge(23);
		System.err.println("Leave get_person\n");
		return person;
	}

	public List<Person> get_persons() {
		System.err.println("Enter get_persons");
		List<Person> persons = new ArrayList<Person>();

		Person jack = new Person();
		jack.setName("Jack");
		jack.setAge(23);
		persons.add(jack);

		Person mery = new Person();
		mery.setName("Mery");
		mery.setAge(22);
		persons.add(mery);

		System.err.println("Leave get_persons\n");
		return persons;
	}

	public Set<Person> get_persons2() {
		System.err.println("Enter get_persons2");
		Set<Person> persons = new HashSet<Person>();

		Person jack = new Person();
		jack.setName("jack");
		jack.setAge(23);
		persons.add(jack);

		Person mery = new Person();
		mery.setName("mery");
		mery.setAge(33);
		persons.add(mery);

		System.err.println("Leave get_persons2\n");
		return persons;
	}

	public Map<Person, Person> get_persons3() {
		System.err.println("Enter get_persons3");
		Map<Person, Person> persons = new HashMap<Person, Person>();

		Person jack = new Person();
		jack.setName("jack");
		jack.setAge(23);

		Person mery = new Person();
		mery.setName("mery");
		mery.setAge(33);

		persons.put(jack, mery);
		persons.put(mery, jack);

		System.err.println("Leave get_persons3\n");
		return persons;
	}

	public List<Set<Person>> get_persons4() {
		System.err.println("Enter get_persons3");
		List<Set<Person>> persons = new ArrayList<Set<Person>>();

		HashSet<Person> s1 = new HashSet<Person>();
		Person jack = new Person();
		jack.setName("jack");
		jack.setAge(23);
		s1.add(jack);

		Person mery = new Person();
		mery.setName("mery");
		mery.setAge(33);
		s1.add(mery);

		persons.add(s1);

		HashSet<Person> s2 = new HashSet<Person>();
		jack.setName("jack");
		jack.setAge(23);
		s2.add(jack);

		mery.setName("mery");
		mery.setAge(33);
		s2.add(mery);

		persons.add(s2);

		System.err.println("Leave get_persons3\n");
		return persons;
	}

	public void send_bool(boolean value) {
		System.err.println("Enter send_bool");
		System.err.println(value);
		System.err.println("Leave send_bool\n");
	}

	public void send_int8(byte value) {
		System.err.println("Enter send_int8");
		System.err.println(value);
		System.err.println("Leave send_int8\n");
	}

	public void send_int16(short value) {
		System.err.println("Enter send_int16");
		System.err.println(value);
		System.err.println("Leave send_int16\n");
	}

	public void send_int32(int value) {
		System.err.println("Enter send_int32");
		System.err.println(value);
		System.err.println("Leave send_int32\n");
	}

	public void send_int64(long value) {
		System.err.println("Enter send_int64");
		System.err.println(value);
		System.err.println("Leave send_int64\n");
	}

	public void send_float(float value) {
		System.err.println("Enter send_float");
		System.err.println(value);
		System.err.println("Leave send_float\n");
	}

	public void send_string(java.lang.String value) {
		System.err.println("Enter send_string");
		System.err.println(value);
		System.err.println("Leave send_string\n");
	}

	public void send_binary(java.lang.String value) {
		System.err.println("Enter send_binary");
		System.err.println(value);
		System.err.println("Leave send_binary\n");
	}

	public void send_color(Color color) {
		System.err.println("Enter send_color");
		System.err.println(color);
		System.err.println("Leave send_color\n");
	}

	public void send_person(Person person) {
		System.err.println("Enter send_person");
		System.err.println("Person: ");
		System.err.println("name: " + person.getName());
		System.err.println("age: " + person.getAge());
		System.err.println("Leave send_person\n");
	}

	public void send_int32_sequence(List<Integer> numbers) {
		System.err.println("Enter send_int32_sequence");
		for (Integer i : numbers) {
			System.err.println(i);
		}
		System.err.println("Leave send_int32_sequence\n");
	}

	public void send_persons(List<Person> persons) {
		System.err.println("Enter send_persons");
		for (Person p : persons) {
			System.err.println("name: " + p.getName());
			System.err.println("age: " + p.getAge());
		}
		System.err.println("Leave send_persons\n");
	}

	public void send_persons2(Set<Person> persons) {
		System.err.println("Enter send_persons2");
		for (Iterator<Person> iterator = persons.iterator();
				iterator.hasNext(); ) {
			Person p = iterator.next();
			System.err.println("name: " + p.getName());
			System.err.println("age: " + p.getAge());
				}

		System.err.println("Leave send_persons2\n");
	}

	public void send_int32_set_seq(List<Set<Integer>> xx) {
		System.err.println("Enter send_int32_set_seq");
		System.err.println(xx);
		System.err.println("Leave send_int32_set_seq\n");
	}

	public void send_persons3(Map<Person, Person> persons) {
		System.err.println("Enter send_persons3");
		for (Person key : persons.keySet()) {
			System.err.println("key: " + key.getName() + ": " + key.getAge());
			System.err.println("value: " + persons.get(key).getName() + ": " + persons.get(key).getAge());
		}
		System.err.println("Leave send_persons3\n");
	}

	public void send_person_vec_set(Set<List<Person>> xxx) {
		System.err.println("Enter send_person_vec_set");
		for (List<Person> list : xxx) {
			for (Person person : list) {
				System.err.println(person.getName() + " " + person.getAge());
			}
		}
		System.err.println("Leave send_person_vec_set\n");
	}

	public void out_boolean(BooleanHolder value) {
		System.err.println("Enter out_boolean");
		value.value = true;
		System.err.println("Leave out_boolean\n");
	}

	public void out_int8(ByteHolder value) {
		System.err.println("Enter out_int8");
		value.value = 8;
		System.err.println("Leave out_int8\n");
	}

	public void out_int16(ShortHolder value) {
		System.err.println("Enter out_int16");
		value.value = 16;
		System.err.println("Leave out_int16\n");
	}

	public void out_int32(IntHolder value) {
		System.err.println("Enter out_int32");
		value.value = 32;
		System.err.println("Leave out_int32\n");
	}

	public void out_int64(LongHolder value) {
		System.err.println("Enter out_int64");
		value.value = 64;
		System.err.println("Leave out_int64\n");
	}

	public void out_string(StringHolder value) {
		System.err.println("Enter out_string");
		value.value = "hello, world";
		System.err.println("Leave out_string\n");
	}

	public void out_binary(StringHolder value) {
		System.err.println("Enter out_binary");
		value.value = "data \\a";
		System.err.println("Leave out_binary\n");
	}

	public void out_float(FloatHolder value) {
		System.err.println("Enter out_float");
		value.value = 3.3f;
		System.err.println("Leave out_float\n");
	}

	public void out_person(PersonHolder person) {
		System.err.println("Enter out_float");
		person.value = new Person();
		person.value.setName("jack");
		person.value.setAge(23);
		System.err.println("Leave out_float\n");
	}

	public void out_seq(Holder<List<Integer>> xxx) {
		System.err.println("Enter out_seq");
		List<Integer> list = new ArrayList<Integer>();
		list.add(10);
		list.add(20);
		list.add(30);

		xxx.value = list;
		System.err.println("Leave out_seq\n");
	}

	public void out_string_set(Holder<Set<String>> xxx) {
		System.err.println("Enter out_string_set");
		Set<String> set = new HashSet<String>();
		set.add("first");
		set.add("second");
		set.add("third");

		xxx.value = set;
		System.err.println("Leave out_string_set\n");
	}

	public void out_int16_float_map(Holder<Map<Short, Float>> xxx) {
		System.err.println("Enter out_int16_float_map");
		Map<Short, Float> map = new HashMap<Short, Float>();

		map.put(new Short("1"), new Float(1.1));
		map.put(new Short("2"), new Float(2.2));
		map.put(new Short("3"), new Float(3.3));

		xxx.value = map;
		System.err.println("Leave out_int16_float_map\n");
	}

	public void out_int_vec_set(Holder<Set<List<Integer>>> xxx) {
		System.err.println("Enter out_int_vec_set");
		Set<List<Integer>> set = new HashSet<List<Integer>>();

		List<Integer> list1 = new ArrayList<Integer>();
		list1.add(1);
		list1.add(2);
		list1.add(3);
		set.add(list1);

		List<Integer> list2 = new ArrayList<Integer>();
		list2.add(10);
		list2.add(20);
		list2.add(30);
		set.add(list2);

		xxx.value = set;
		System.err.println("Enter out_int_vec_set\n");
	}

	public void all_boolean(BooleanHolder value) {
		System.err.println("Enter all_boolean");
		System.err.println(value.value);
		value.value = false;
		System.err.println("Leave all_boolean\n");
	}

	public void all_int8(ByteHolder value) {
		System.err.println("Enter all_int8");
		System.err.println(value.value);
		value.value = 8;
		System.err.println("Leave all_int8\n");
	}

	public void all_int16(ShortHolder value) {
		System.err.println("Enter all_int16");
		System.err.println(value.value);
		value.value = 16;
		System.err.println("Leave all_int16\n");
	}

	public void all_int32(IntHolder value) {
		System.err.println("Enter all_int32");
		System.err.println(value.value);
		value.value = 32;
		System.err.println("Leave all_int32\n");
	}

	public void all_int64(LongHolder value) {
		System.err.println("Enter all_int64");
		System.err.println(value.value);
		value.value = 64;
		System.err.println("Leave all_int64\n");
	}

	public void all_string(StringHolder value) {
		System.err.println("Enter all_string");
		System.err.println(value.value);
		value.value = "hello, world";
		System.err.println("Leave all_string\n");
	}

	public void all_binary(StringHolder value) {
		System.err.println("Enter all_binary");
		System.err.println(value.value);
		value.value = "ddddd";
		System.err.println("Leave all_binary\n");
	}

	public void all_float(FloatHolder value) {
		System.err.println("Enter all_float");
		System.err.println(value.value);
		value.value = 3.3f;
		System.err.println("Leave all_float\n");
	}

	public void all_int32_seq(Holder<List<Integer>> value) {
		System.err.println("Enter all_int32_seq");
		System.err.println(value.value);

		List<Integer> list = new ArrayList<Integer>();
		list.add(1000);
		list.add(2000);
		list.add(3000);
		value.value = list; 
		System.err.println("Leave all_int32_seq\n");
	}

	public void all_person(PersonHolder value) {
		System.err.println("Enter all_float");
		Person person = value.value;

		System.err.println(person.getName() + " " + person.getAge());

		person.setName("mery");
		person.setAge(100);
		value.value = person;
		System.err.println("Leave all_float\n");
	}

	public void all_int32_set(Holder<Set<Integer>> value) {
		System.err.println("Enter all_int32_set");
		System.err.println(value.value);

		Set<Integer> set = new HashSet<Integer>();
		set.add(1000);
		set.add(2000);
		set.add(3000);
		value.value = set; 
		System.err.println("Leave all_int32_set\n");
	}

	public void all_person_seq(Holder<List<Person>> value) {
		System.err.println("Enter all_person_seq");
		for (Person person : value.value) {
			System.err.println(person.getName() + " " + person.getAge());
		}

		List<Person> list = new ArrayList<Person>();
		Person p = new Person();
		p.setName("jack");
		p.setAge(23);
		list.add(p);

		Person mery = new Person();
		mery.setName("mery");
		mery.setAge(33);
		list.add(mery);

		value.value = list;
		System.err.println("Leave all_person_seq\n");
	}

	public void all_int32_person_map(Holder<Map<Integer, Person>> value) {
		System.err.println("Enter all_int32_person_map");
		for (Integer key : value.value.keySet()) {
			System.err.println(key);
			Person person = value.value.get(key);
			System.err.println(person.getName() + " " + person.getAge());
		}

		Map<Integer, Person> map = new HashMap<Integer, Person>();
		Person person = new Person();
		person.setName("jack");
		person.setAge(22);
		map.put(new Integer(1), person);

		value.value = map;
		System.err.println("Leave all_int32_person_map\n");
	}

	public void color_out_all(ColorHolder color1, ColorHolder color2) {
		System.err.println("Enter color_out_all");
		System.err.println(color1.value);

		color1.value = Color.GREEN;
		color2.value = Color.BLUE;
		System.err.println("Leave color_out_all\n");
	}

	public List<Color> color_xx(Set<Color> color1, Holder<List<Color>> color2, Holder<Map<Color, Color>> color3) {
		System.err.println("Enter color_xx");

		System.err.println(color1);
		System.err.println(color3.value);

		List<Color> ret = new ArrayList<Color>();
		ret.add(Color.RED);
		ret.add(Color.GREEN);
		ret.add(Color.BLUE);

		color2.value = ret;
		
		Map<Color, Color> map = new HashMap<Color, Color>();
		map.put(Color.RED, Color.BLUE);
		color3.value = map;

		System.err.println("Enter color_xx\n");
		return ret;
	}
}







/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
