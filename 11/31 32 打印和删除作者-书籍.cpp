#include <sstream>
#include <utility>
using std::pair;
using std::make_pair;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;
using std::multimap;
#include <set>
using std::set;
#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

int main() {
	multimap<string, string> mss{ { "Gingko","book1" },{ "Gingko","book2" },{ "Gingko","book3" },{ "Gingko","book4" },{ "Timescapes","book1" } };
	for (auto m : mss) {
		cout << m.first << " " << m.second << endl;
	}
	string name;
	cin >> name;
	auto pos = mss.equal_range(name);
	while (pos.first != pos.second) {
		pos.first = mss.erase(pos.first);
	}
	for (auto m : mss) {
		cout << m.first << " " << m.second << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}

