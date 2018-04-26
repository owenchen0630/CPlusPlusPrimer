#include <string>
using std::string;
#include <list>
using std::list;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	char a[10] = "ABCGGDGDG";
	char b[10] = "ABCGGDGDG";
	char c[10] = "ABCGGDGDG";
	list<char*> lc{ a,b,c };
	vector<string> vs(lc.begin(),lc.end());

	for (int i = 0;i < vs.size();i++) {
		cout << vs[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}