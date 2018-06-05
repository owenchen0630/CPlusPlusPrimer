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

class ShorterThan {
public:
	bool operator()(const string &s1, const string &s2) const {
		return s1.size() < s2.size();
	}

};
class LongerThan {
public:
	LongerThan(const size_t n) :sz(n) {}
	bool operator()(const string &s) {
		return s.size() > sz;
	}
private:
	size_t sz;
};
void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	for (string i : words) {
		cout << i << " ";
	}
	cout << endl;
	auto end_unique = std::unique(words.begin(), words.end());

	for (string i : words) {
		cout << i << " ";
	}
	cout << endl;
	words.erase(end_unique, words.end());
}
string make_plural(int count, const string &s1, const string &s2) {
	return (count > 1) ? s1 + s2 : s1;
}

void biggies(vector<string> &vs, string::size_type sz) {
	elimDups(vs);//按字典序排列单词，并删去重复项
	std::stable_sort(vs.begin(), vs.end(), ShorterThan());//按长度升序排序，相等的元素保持字典序
	auto first_find = std::find_if(vs.begin(), vs.end(), LongerThan(sz));//找出第一个长度大于等于sz的单词
	int count = vs.end() - first_find;//计算有多少元素满足条件
	cout << count << make_plural(count, " word", "s") << " of length " << sz << " or longer" << endl;
	std::for_each(first_find, vs.end(), [](const string &s) { cout << s << " "; });//输出满足条件的元素
}
int main() {
	vector<string> vs = { "aaa","aaa","bbb","aaa","bbb","ccc","777777","457435847365438976548793","21321321321" };
	biggies(vs, 5);
	cout << endl;
	system("pause");
	return 0;
}