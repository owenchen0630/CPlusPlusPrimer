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

void findAndReplace(string &s,string &oldVal,string &newVal){
	auto sb = s.begin();
	while (s.end() - sb > oldVal.size() - 1) {
		string s_temp(sb, sb + oldVal.size());
		if (s_temp == oldVal) {
			sb=s.erase(sb, sb+oldVal.size());
			sb=s.insert(sb, newVal.begin(), newVal.end());
			sb += newVal.size();
		}
		else sb++;
	}
}

void findAndReplace_2(string &s, string &oldVal, string &newVal) {
	int i = 0;
	while (i <= s.size() - oldVal.size()) {
		string s_temp = s.substr(i, oldVal.size());
		if (s_temp == oldVal) {
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size();
		}
		else i++;
	}
}
//use string iterator
void findAndReplace_3(string &s, string &oldVal, string &newVal) {
	int i = 0;
	while (sb < s.end() - oldVal.size() + 1) {
		string s_temp(sb, sb + oldVal.size());
		if (s_temp == oldVal) {
		    s.replace(i, oldVal.size(), newVal);
		    sb = s.begin() + i + newVal.size();
		    i += newVal.size();
		}
		else {
		    sb++;
		    i++;
		}
	    }
}

int main() {
	string s = "ABCDEFGHIJKBCBC";
	string oldVal = "BC";
	string newVal = "BigSea";
	findAndReplace_2(s, oldVal, newVal);
	cout << s << endl;
	system("pause");
	return 0;
}
