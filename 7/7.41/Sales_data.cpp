#include<iostream>
#include"Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
int main() {
	Sales_data total;
	Sales_data item1("s", 8, 8);
	Sales_data item2("ss");
	Sales_data item3(cin);
	system("pause");
	return 0;
}