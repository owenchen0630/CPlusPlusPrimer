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

class HasPtr {
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	void print() { cout << *ps << endl; }
private:
	string * ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &hp) {
	ps = new string(*hp.ps);
	i = hp.i;
}

HasPtr& HasPtr::operator=(const HasPtr& hp) {
	ps = new string(*hp.ps);
	i = hp.i;
	return *this;
}

int main() {
	HasPtr hp("aaaaa");
	HasPtr hp2(hp);
	HasPtr hp3 = hp2;
	hp2 = HasPtr("bbbb");
	hp2.print();
	hp.print();
	hp3.print();
	system("pause");
	return 0;
}