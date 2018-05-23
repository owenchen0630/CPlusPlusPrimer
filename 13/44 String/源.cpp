//#include <string>
//using std::string;
#include <vector>
using std::vector;
#include <set>
using std::set;
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
#include <algorithm>
#include <utility>
#include "String.h"
int main() {
	String s("aaaaaaa");
	String s2("cccccc");
	s.push_back('b');
	s = s2;
	print(cout, s) << endl;
	system("pause");
	return 0;
}
