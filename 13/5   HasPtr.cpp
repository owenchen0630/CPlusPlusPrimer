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
	HasPtr(HasPtr&);
	void print() { cout << *ps << endl; }
private:
	string * ps;
	int i;
};

HasPtr::HasPtr(HasPtr &hp) {
	ps = new string(*hp.ps);
	i = hp.i;
}

int main() {
	HasPtr hp("aaaaa");
	HasPtr hp2(hp);
	hp2 = HasPtr("bbbb");
	hp2.print();
	hp.print();
	system("pause");
	return 0;
}