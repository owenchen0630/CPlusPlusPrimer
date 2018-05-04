#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
using namespace std::placeholders;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include<sstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void elimDups(list<string> &ls) {
	ls.sort();
	for (string i : ls) {
		cout << i << " ";
	}
	cout << endl;
	ls.unique();
	for (string i : ls) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	string s = "the quick red fox jumps over the slow red turtle";
	std::istringstream is(s);
	std::istream_iterator<string> is_iter(is);
	std::istream_iterator<string> eof;
	list<string> ls;
	std:;copy(is_iter,eof, std::back_inserter(ls));
	elimDups(ls);
	system("pause");
	return 0;
}