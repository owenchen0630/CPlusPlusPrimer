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
bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}
bool longerThan5(const string &s) {
	return s.size() >= 5;
}
void elimDups(vector<string> &words) {
	auto end_partition = std::partition(words.begin(), words.end(), longerThan5);
	words.erase(end_partition, words.end());
}

int main() {
	vector<string> vs = { "aaa","aaa","bbb","aaa","bbb","ccc","777777" };
	elimDups(vs);
	for (string i : vs) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}