#include<iostream>
#include"Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
int main() {
	Sales_data total;
	if (read(cin,total)) {
		Sales_data trans;
		while (read(cin,trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total);
				cout << endl;
				total = trans;
			}
		}
		print(cout, total);
		cout << endl;
	}
	else {
		std::cerr << "No data?!" << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}