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
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Sales_data.h"

template <typename T> int compare(const T& lhs, const T& rhs) {
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}

int main() {
	cout << compare(1, 2) << endl;
	cout << compare(vector<int>{1, 2, 3, 4, 5}, vector<int>{2, 2, 3, 4, 5})<<endl;
	cout << compare(Sales_data("aaa", 10, 1), Sales_data("bbb", 10, 2))<<endl;
	system("pause");
	return 0;
}
