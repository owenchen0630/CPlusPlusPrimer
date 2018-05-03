#include <algorithm>
#include <numeric>
#include <iterator>
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

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	for (string i : words) {
		cout << i << " ";
	}
	cout << endl;
	auto end_unique = std::unique(words.begin(), words.end());
	//此处words的size没变但是只能打印出4项，也就是说重复部分只有第一项能正常打印  ？？？为什么呢
	for (string i : words) {
		cout << i << " ";
	}
	cout << endl;
	words.erase(end_unique, words.end());
}

int main() {
	vector<string> vs = { "aaa","aaa","bbb","aaa","bbb","ccc" };
	elimDups(vs);
	for (string i : vs) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}