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
	int i;
	cin >> i;
	auto f = [&]() mutable ->bool {if (i > 0) { i--; return true; } else return false;};
	(f()) ? cout << "输入不为零" : cout << "输入为零";
	cout << endl;
	cout << i << endl;
	system("pause");
	return 0;
}