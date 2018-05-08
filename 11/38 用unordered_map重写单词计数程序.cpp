#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
using namespace std::placeholders;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <map>
using std::map;
#include <unordered_map>
using std::unordered_map;
#include<sstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	string s = "the quick red fox jumps over the slow red turtle";
	std::istringstream is(s);
	string word;
	unordered_map<string, size_t> word_count;
	while (is >> word) {
		word_count[word]++;
	}
	for (auto i : word_count) {
		cout << "单词 " << i.first << " 出现了 " << i.second << " 次！" << endl;
	}
	system("pause");
	return 0;
}