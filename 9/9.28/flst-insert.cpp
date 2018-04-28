#include <string>
using std::string;
#include <list>
using std::list;
#include <forward_list>
using std::forward_list;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	forward_list<string> flst = { "aaaa","bbbb","cccc","dddd" };
	string s1 = "aaaa", s2 = "0000";
	auto flb = flst.begin();
	while (flb != flst.end()) {
		auto flbb = flb;
		if (*flb == s1) {
			flst.insert_after(flb, s2);
			break;
		}
		else {
			flb++;
		}
		if (flb == flst.end()) flst.insert_after(flbb, s2);
	}
	for (string i : flst) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}