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

class numbered {
	friend void f(numbered);
public:
	numbered() { mysn = inisn++; }
	numbered(numbered &n) { mysn = inisn++; }
private:
	static int inisn;
	int mysn;
};
int numbered::inisn = 0;
void f(numbered s) { cout << s.mysn << endl; }

int main() {
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}