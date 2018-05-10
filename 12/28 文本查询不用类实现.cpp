#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<fstream>
using std::ifstream;
#include<string>
using std::string;
#include<sstream>
using std::istringstream;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<set>
using std::set;
#include<memory>
using std::shared_ptr;

int main() {
	ifstream infile("what faith can do");
	vector<string> text;
	map<string, set<int>> m;
	string line;
	int line_no = 0;
	while (std::getline(infile, line)) {
		text.push_back(line);
		istringstream il(line);
		string word;
		while (il >> word) {
			m[word].insert(line_no);
		}
		line_no++;
	}
	while (true) {
		cout << "输入需要查询的单词，或输入q退出：";
		string word_t;
		cin >> word_t;
		if (word_t == "q") break;
		if (m[word_t].size() == 0) cout << "Not Find!" << endl;
		else {
			cout<< "一共出现在了" << m[word_t].size() << "行中。" << endl;
			for (auto n : m[word_t]) {
				cout << "(line " << n << ") " << text[n] << endl;
			}
		}
	}
	system("pause");
	return 0;
}