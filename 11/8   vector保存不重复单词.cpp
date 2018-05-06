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
#include <set>
using std::set;
#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;
#include <algorithm>

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	for (string i : words) {
		cout << i << " ";
	}
	cout << endl;
	auto end_unique = unique(words.begin(), words.end());
	//此处words的size没变但是只能打印出4项，也就是说重复部分只有第一项能正常打印  ？？？为什么呢
	for (string i : words) {
		cout << i << " ";
	}
	cout << endl;
	words.erase(end_unique, words.end());
}

int main() {
	vector<string> vs{ "aaa","aaa","bbb","aaa","bbb","ccc" };
	elimDups(vs);
	ostream_iterator<string> ois(cout, " ");
	std::copy(vs.begin(), vs.end(), ois);
	cout << endl;
	system("pause");
	return 0;
}
