#include <string>
using std::string;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::allocator;
#include <new>
#include <algorithm>
#include <utility>
#include "Sales_data.h"
int main() {
	Sales_data item_A("A", 1, 5);
	Sales_data item_B("A", 2, 4);
	Sales_data item_C = item_A + item_B;
	cout << item_C << endl;
	system("pause");
	return 0;
}
