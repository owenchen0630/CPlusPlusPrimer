#include<iostream>
#include"Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
int main() {
	Sales_data total;
	print(cout, total);
	cout << endl;
	Sales_data trans(cin);
	print(cout, trans);
	cout << endl;
	Sales_data item1("ABC", 2, 8);
	print(cout, item1);
	cout << endl;
	Sales_data item2("BBB");
	print(cout, item2);
	cout << endl;
	system("pause");
	return 0;
}
