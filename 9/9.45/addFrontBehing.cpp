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

string addFrontBehind(string name,string &frontT,string &behindT) {
	name.insert(name.begin(), frontT.begin(), frontT.end());
	name.append(behindT);
	return name;
}

int main() {
	string s = "ABCDEFGHIJKBCBC";
	string oldVal = "BC";
	string newVal = "BigSea";
	string name = "Gingko";
	string frontT = "Mr.";
	string behindT = "VIP";
	findAndReplace_2(s, oldVal, newVal);
	string fullName = addFrontBehind(name, frontT, behindT);
	cout << s << endl;
	cout << name<<endl;
	cout << fullName << endl;
	system("pause");
	return 0;
}