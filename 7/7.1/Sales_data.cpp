#include<iostream>
#include"Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
int main() {
	Sales_data total;
	float price;
	if (cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold*price;
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold*price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				cout << total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<" "<<total.revenue/total.units_sold << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << endl;
	}
	else {
		std::cerr << "No data?!" << endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}