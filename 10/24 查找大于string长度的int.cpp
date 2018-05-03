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
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool isLongerThanString(int i, const string &s) {
	return i > s.size();
}
int main() {
	vector<int> vi{ 1,2,3,4,5,6,7,8,9 };
	string s = "aaaaa";
	auto first_longer = find_if(vi.begin(), vi.end(), bind(isLongerThanString, _1, s));
	cout << *first_longer << endl;
	system("pause");
	return 0;
}