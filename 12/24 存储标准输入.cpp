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
	char *ps = new char[21];//存20个字符 1个'\0'
	int curr = 0;

	while (char c=getchar()) {
		if (c == '\n') break; // 回车表示输入结束
		ps[curr++] = c;
		if (curr == 20) { cout << "Full!" << endl; break; }
	}
	ps[curr] = 0;
	cout << ps << endl;
	delete [] ps;
	system("pause");
	return 0;
}