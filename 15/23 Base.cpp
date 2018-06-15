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

class Base {
public:
	virtual int fcn();
};
class D1 : public Base {
	int fcn(int);
	//若要覆盖Base::fcn(); int就必须去掉。
	virtual void f2();
};
class D2 : public D1 {
public:
	int fcn(int);
	int fcn();
	void f2();
};
int main() {
	
	system("pause");
	return 0;
}
