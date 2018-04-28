#include <string>
using std::string;
#include <list>
using std::list;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<int> v1{ 1,2,3,4,5,6,7,8,9 };
	vector<int> v2{ 1,2,3,4,5,6,9 };
	cout << (v1 == v2) << endl;
	system("pause");
	return 0;
}