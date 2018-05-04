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
#include<sstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	string s = "the quick red fox jumps over the slow red turtle";
	string s2 = "the quick red fox! jumps? over# the slow red turtle Then The reD FOX JUMPS on thE back Of tHe SloW REd Turtle";
	std::istringstream is(s2);
	string word;
	map<string, size_t> word_count;
	while (is >> word) {
		auto word_b = word.begin();
		while (word_b != word.end()) {
			if (*word_b < 'a' && *word_b >= 'A') {
				*word_b = *word_b - 'A' + 'a';
				word_b++;
			}
			else if (*word_b<'A' || *word_b>'z') {
				word_b = word.erase(word_b);
			}
			else word_b++;
		}
		for (char &i : word) {
			
			if (i < 'a' && i >= 'A') {
				i = i - 'A' + 'a';
			}
			if (i<'A' || i>'z') {
				
			}
		}
		word_count[word]++;
	}
	for (auto i : word_count) {
		cout << "单词 " << i.first << " 出现了 " << i.second << " 次！" << endl;
	}
	system("pause");
	return 0;
}