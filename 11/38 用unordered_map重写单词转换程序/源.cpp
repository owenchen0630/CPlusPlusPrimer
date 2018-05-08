#include <sstream>
#include <utility>
using std::pair;
using std::make_pair;
#include <fstream>
using std::ifstream;
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
#include <unordered_map>
using std::unordered_map;
#include <set>
using std::set;
#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

const string &transform(const string &s, const unordered_map<string, string> &m) {
	//if (m.find(s) != m.end()) return m[s];//如果要使用下标操作，map不能为const
	auto ret = m.find(s);
	if (ret != m.end()) return ret->second;
	else return s;
}

unordered_map<string, string> buildMap(ifstream &map_file) {
	unordered_map<string, string> res;
	string key;
	string value;
	while (map_file >> key && std::getline(map_file, value)) {
		//value = value.substr(1);//跳过key和value之间的空格，getline会连空格一起获取。
		res.insert({ key,value.substr(1) });
	}
	return res;
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto transMap = buildMap(map_file);
	string line;
	while (std::getline(input, line)) {
		std::istringstream wordsInLine(line);
		string word;
		bool flag = true;
		while (wordsInLine >> word) {
			if (flag == true) {
				flag = false;
			}
			else {
				cout << " ";
			}
			cout << transform(word, transMap);
		}
		cout << endl;
	}
}

int main() {
	ifstream mapfile("rules.txt");
	ifstream input("text.txt");
	word_transform(mapfile, input);
	system("pause");
	return 0;
}

