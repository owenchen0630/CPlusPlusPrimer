#include<iostream>
#include"Sales_item.h"
using std::cout;
using std::cin;
using std::endl;
int main() {
	Sales_item total;
	if (cin >> total) {
		Sales_item trans;
		while (cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else {
		std::cerr << "No data?!" << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}