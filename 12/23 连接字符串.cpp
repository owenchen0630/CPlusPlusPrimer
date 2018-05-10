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
#include <new>

char* combine(const char *s1, const char *s2) {
	char *pc = new char[strlen(s1) + strlen(s2) + 1];
	strcpy_s(pc, strlen(s1) + strlen(s2) + 1, s1);
	strcat_s(pc, strlen(s1) + strlen(s2) + 1, s2);
	return pc;
}

char* combine(const string s1, const string s2) {
	char *pc = new char[s1.size() + s2.size() + 1];
	strcpy_s(pc, s1.size() + s2.size() + 1, (s1 + s2).c_str());
	return pc;
}

int main() {
	const char *s1 = "AAAAA";
	const char *s2 = "BBBBB";
	char *s = combine(s1, s2);
	cout << s << endl;
	delete [] s;

	string str1 = "CCCCC";
	string str2 = "DDDDD";
	char *str = combine(str1, str2);
	cout << str << endl;
	delete[] str;
	system("pause");
	return 0;
}