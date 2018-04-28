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
	list<string> ds;
	string input;
	while (cin >> input) {
		ds.push_back(input);
	}
	auto dsb = ds.begin(), dse = ds.end();
	while (dsb != dse) {
		cout << *dsb << endl;
		dsb++;
	}
	system("pause");
	return 0;
}