#include<utility>
#include<algorithm>
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<memory>
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Foo {
public:
	Foo(const vector<int> &vi) :data(vi) {}
	Foo sorted() && ;
	Foo sorted() const &;
	Foo retVal() { return *this; }
	Foo &retFoo() { return *this; }
	std::ostream& print(std::ostream&);
private:
	vector<int> data;
};

Foo Foo::sorted() && {
	std::sort(this->data.begin(), this->data.end());
	return *this;
}

//version 1
//Foo Foo::sorted() const & {
//	Foo newfoo(*this);
//	std::sort(newfoo.data.begin(), newfoo.data.end());
//	return newfoo;
//}

//version 2 wrong!
//Foo Foo::sorted() const & {
//	Foo newfoo(*this);
//	return newfoo.sorted();
//}

//version 3
Foo Foo::sorted() const & {
	return Foo(*this).sorted();
}

std::ostream& Foo::print(std::ostream& os) {
	for (auto i : data) {
		os << i << " ";
	}
	return os;
}

int main() {
	vector<int> vi{ 9,8,7,6,5,4,3,2,1 };
	Foo f(vi);
	f.retFoo().sorted().print(cout) << endl;
	f.retVal().sorted().print(cout) << endl;
	f.print(cout) << endl;
	system("pause");
	return 0;
}