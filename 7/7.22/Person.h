#pragma once
//#ifndef PERSON_H
//#define PERSON_H
#include <string>
class Person
{
	friend std::ostream &print(std::ostream &os, const Person &p);
	friend std::istream &read(std::istream &is, Person &p);
public:
	//构造函数
	Person() = default;
	Person(std::string &n, std::string &a) :name(n), address(a) {}
	Person(std::istream &is) { read(is, *this); }
	Person(std::string &n) :name(n) {}

	//获取name和address的成员函数应该是const的，因为这些成员函数不会修改对象。（而且const的成员函数能够对const Person类型使用更泛用）
	std::string get_name() const { return name; }
	std::string get_address() const { return address; }
private:
	std::string name;
	std::string address;
};
std::ostream &print(std::ostream &os, const Person &p);
std::istream &read(std::istream &is, Person &p);

std::istream &read(std::istream &is, Person &p) {
	is >> p.name >> p.address;
	return is;
}
std::ostream &print(std::ostream &os, const Person &p) {
	os << p.get_name() << " " << p.get_address();
	return os;
}

//#endif