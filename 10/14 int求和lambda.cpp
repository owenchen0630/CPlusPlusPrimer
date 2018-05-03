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

int main() {
	auto f = [](int a, int b) {return a + b;};
	cout << f(2, 3) << endl;
	system("pause");
	return 0;
}