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
class QueryResult;
class TextQuery {
public:
	TextQuery() {};
	TextQuery(std::istream &in);
	QueryResult query(string);
private:
	shared_ptr<vector<string>> text;
	map<string, shared_ptr<set<int>>> m;
};


TextQuery::TextQuery(std::istream &in) :text(new vector<string>) { 
	string s;
	string word;
	int lines = 0;
	while (std::getline(in, s)) {
		text->push_back(s);
		istringstream istr(s);
		while (istr >> word) {
			if (!m[word]) m[word].reset(new set<int>);
			m[word]->insert(lines);
		}
		lines++;
	}
}

class QueryResult {
	friend std::ostream& print(std::ostream&, QueryResult);
public:
	QueryResult(shared_ptr<vector<string>> pvs, string s, shared_ptr<set<int>> psi):text(pvs),word(s),lines(psi) {};
private:
	shared_ptr<vector<string>> text;
	string word;
	shared_ptr<set<int>> lines;
};

QueryResult TextQuery::query(string word) {
	if (!m[word]) m[word].reset(new set<int>);
	return { text,word,m[word] };
}

std::ostream& print(std::ostream& out, QueryResult qs) {
	auto linesBegin = qs.lines->begin();
	out << "一共出现在了" << qs.lines->size() << "行中。" << endl;
	while (linesBegin != qs.lines->end()) {
		out << "(line " << *linesBegin << ") " << qs.text->at(*linesBegin)<<endl;
		linesBegin++;
	}
	return out;
}

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "输入需要查询的单词，或输入q退出：";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;

	}
}
int main() {
	ifstream infile("what faith can do");
	runQueries(infile);
	system("pause");
	return 0;
}