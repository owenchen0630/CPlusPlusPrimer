#include <algorithm>
#include <numeric>
#include <iterator>
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
#include <functional>
#include <map>

class Base {
public:
	void pub_mem() { cout << "1" << endl; }
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv :private Base {
	//private不影响派生类的访问权限
	int f1() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv :protected Base {
	int f2() const { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_public :public Pub_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_protected :public Prot_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_private :public Priv_Derv {
	void memfcn(Base &b) { b = *this; }
	//int use_base() { return prot_mem; }  //Priv_Derv的派生类的成员和友元不能访问Base的成员
};

int main() {
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_public dd1;
	Derived_from_private dd2;
	Derived_from_protected dd3;
	Base *p = &d1;
	p = &d2;
	p = &d3;
	p = &dd1;
	p = &dd2;
	p = &dd3;
	system("pause");
	return 0;
}
