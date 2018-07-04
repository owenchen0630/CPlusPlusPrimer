#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
#include <map>
using std::map;
#include <set>
using std::set;
#include <sstream>
using std::istringstream;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;

class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(std::istream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};


TextQuery::TextQuery(std::istream &is) :file(new vector<string>) {
	string text;
	while (std::getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		string word;
		istringstream line(text);
		while (line >> word) {
			if (!wm[word]) wm[word].reset(new set<line_no>);
			wm[word]->insert(n);
		}
	}
}

class QueryResult {
	using line_no = vector<string>::size_type;
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {};
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end()) {
		return QueryResult(sought, nodata, file);
	}
	else return QueryResult(sought, loc->second, file);
}

std::ostream& print(std::ostream& os, const QueryResult &qr) {
	auto linesBegin = qr.lines->begin();
	os << "一共出现在了" << qr.lines->size() << "行中。" << endl;
	while (linesBegin != qr.lines->end()) {
		os << "(line " << *linesBegin << ") " << qr.file->at(*linesBegin) << endl;
		linesBegin++;
	}
	return os;
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

class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

class Query {
	friend Query operator~(const Query&);
	friend Query operator&(const Query&, const Query&);
	friend Query operator|(const Query&, const Query&);
public:
	Query(const string&);
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	string rep() const { return q->rep(); }
private:
	Query(shared_ptr<Query_base> query) :q(query) {}
	shared_ptr<Query_base> q;
};

class WordQuery :public Query_base {
	friend class Query;
	WordQuery(const string &s);
	QueryResult eval(const TextQuery &t) const {
		return t.query(query_word);
	}
	string rep() const { return query_word; }
	string query_word;
};

class NotQuery :public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query &q) :query(q) {}
	string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;
	Query query;
};
inline Query operator~(const Query &operand) {
	return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery :public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, const string &s) :lhs(l), rhs(r), opSym(s) {}
	string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	//BinaryQuery不定义eval，而是继承了Query_base的纯虚函数。因此BinaryQuery也是一个抽象基类，我们不能创建BinaryQuery类型的对象。
	Query lhs, rhs;
	string opSym;
};

class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

std::ostream& operator<<(std::ostream &os, const Query &query) {
	return os << query.rep();
}

 int main() {
	ifstream infile("what faith can do");
	runQueries(infile);
	return 0;
}