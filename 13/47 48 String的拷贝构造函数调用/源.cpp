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

//观察到的问题：vector似乎完全是值拷贝，所以总会调用拷贝构造函数。
//而且vector不预设预留空间的话 会不断地重新分配空间导致 大量调用拷贝构造函数 效率极低

int main() {
	vector<String> vs;
	vs.reserve(100);
	String s1 = "aaaaaaa";
	String s2 = s1;
	vs.push_back(s2);
	s1 = s2;
	vs.push_back(s1);
	system("pause");
	return 0;
}
