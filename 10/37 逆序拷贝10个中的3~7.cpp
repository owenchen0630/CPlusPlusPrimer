#include<iostream>
#include<iterator>
using std::istream_iterator;
using std::ostream_iterator;
#include<vector>
using std::vector;
#include<list>
using std::list;
#include<algorithm>
#include<numeric>
#include<fstream>
#include<string>
using std::string;
#include"Sales_item.h"
using std::cout;
using std::cin;
using std::endl;


int main() {
	ostream_iterator<string> os_iter(cout, " ");
	vector<string> vs{ "a","b","c","d","e","f","g","h","i","j" };
	auto lsb = vs.crbegin();
	for (int i = 0;i < 3;i++) {
		lsb++;
	}
	auto lse = vs.crend();
	for (int i = 0;i < 2;i++) {
		lse--;
	}
	list<string> ls(lsb, lse);
	std::copy(ls.begin(), ls.end(), os_iter);
	cout << endl;
	system("pause");
	return 0;
}