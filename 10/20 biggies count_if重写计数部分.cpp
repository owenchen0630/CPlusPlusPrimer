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
string make_plural(int count, const string &s1, const string &s2) {
	return (count > 1) ? s1 + s2 : s1;
}

void biggies(vector<string> &vs, string::size_type sz) {
	elimDups(vs);//按字典序排列单词，并删去重复项
	std::stable_sort(vs.begin(), vs.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size();});//按长度升序排序，相等的元素保持字典序
	auto end_partition = std::stable_partition(vs.begin(), vs.end(), [sz](const string &s) {return s.size() >= sz;});//找出第一个长度大于等于sz的单词
	int count = std::count_if(vs.begin(), vs.end(), [sz](const string &s) {return s.size() >= sz;});
	cout << count << make_plural(count, " word", "s") << " of length " << sz << " or longer" << endl;
	std::for_each(vs.begin(),end_partition, [](const string &s) { cout << s << " "; });//输出满足条件的元素
}
int main() {
	vector<string> vs = { "aaa","aaa","bbb","aaa","bbb","ccc","777777","457435847365438976548793","21321321321" };
	biggies(vs, 6);
	cout << endl;
	system("pause");
	return 0;
}