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
#include <functional>

int main() {
	vector<int> v{ 1,2 };
	cout << (0 == std::count_if(v.begin(), v.end(), bind1st(std::modulus<int>(), 2))) << endl;
	system("pause");
	return 0;
}