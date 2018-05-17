#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::allocator;
#include <new>

class Employee {
	friend void print(const Employee&);
public:
	Employee() { idNo = iniNo++; }
	Employee(const string s) :name(s) { idNo = iniNo++; }
	Employee(Employee& e) { name = e.name; idNo = iniNo++; }
	Employee& operator=(Employee& e) { name = e.name; idNo = iniNo++; return *this; }
private:
	static int iniNo;
	string name;
	int idNo;
};
int Employee::iniNo = 0;
void print(const Employee &e) {
	cout << e.name << " " << e.idNo << endl;
}
int main() {
	Employee a;
	Employee b("cbg");
	Employee c(a);
	Employee d = b;
	print(a);
	print(b);
	print(c);
	print(d);
	system("pause");
	return 0;
}