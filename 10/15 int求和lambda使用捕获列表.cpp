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
	int i = 2;
	auto f = [i](int b) {return i + b;};
	cout << f(3) << endl;
	system("pause");
	return 0;
}