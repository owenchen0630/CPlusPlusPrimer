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
	list<int> orz{ 1,2,3,4,5,6,6,7,8,89,9,0 };
	deque<int> dd, sd;
	auto ob = orz.begin(), oe = orz.end();
	while (ob != oe) {
		if (*ob % 2 == 0) dd.push_back(*ob);
		else sd.push_back(*ob);
		ob++;
	}
	for (int i : dd) {
		cout << i << " ";
	}
	cout << endl;
	for (int i : sd) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}