#include <string>
using std::string;
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
#include "Sales_data.h"
#include "String.h"
#include "StrVec.h"
#include "StrBlob.h"

int main() {
	//Sales_data item_A("A", 1, 5);
	//Sales_data item_B("A", 2, 4);
	//Sales_data item_C = item_A + item_B;
	//Sales_data item_D;
	//cin >> item_D;
	//cout << item_C << endl;
	//cout << item_D << endl;
	//StrBlob sb1{ "bbbbc","bbbb","cccc" };
	//StrBlob sb2{ "bbbba","aaaa","dddd" };
	//cout << (sb1 < sb2) << endl;
	//StrBlobPtr sp1(sb1);
	//StrBlobPtr sp2(sb1, 1);
	//cout << (sp1 < sp2) << endl;
	//StrVec s1{ "aaa","bbbb","cccc" };
	//StrVec s2{ "aaa","bbbb","cccc" };
	//cout << (s1<=s2) << endl;
	String s1("aaaaaaaaa");
	String s2 = "aaaaaaaaa";
	cout << s1 << endl;
	cout << s2 << endl;
	cout << (s1 <= s2) << endl;
	system("pause");
	return 0;
}
