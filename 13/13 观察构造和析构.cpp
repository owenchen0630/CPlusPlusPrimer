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
struct X {
	X() { cout << "X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(X&) { cout << "X& operator=(X&)" << endl; }
	~X() { cout << "~X()" << endl; }
};

void Foo(X) {}
void Foo2(X&) {}

int main() {
	//作用域
	{
		cout << "将它们作为非引用参数传递:" << endl;
		X x;
		Foo(x);
		cout << "将它们作为引用参数传递:" << endl;
		X y;
		Foo2(y);
		cout << "将它们动态分配:" << endl;
		X *z = new X;
		delete z;
		cout << "将它们存于容器中：" << endl;
		vector<X> vx(5);
		cout << "自选动作：" << endl;
		X c;
		X co(c);
		X coo = c;
		cout << "离开作用范围：" << endl;
	}
	system("pause");
	return 0;
}