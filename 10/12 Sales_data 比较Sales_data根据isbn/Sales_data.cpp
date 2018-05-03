#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<fstream>
using std::ifstream;
using std::ofstream;
#include<vector>
using std::vector;
#include<algorithm>
#include"Sales_data.h"

bool isSmaller(const Sales_data &sd1, const Sales_data &sd2) {
	return sd1.isbn() < sd2.isbn();
}

int main() {
	Sales_data sd1("12345678",2,5), sd2("222222",3,5), sd3("111111", 3, 5);
	vector<Sales_data> vsd{ sd1,sd2,sd3 };
	stable_sort(vsd.begin(), vsd.end(), isSmaller);
	for (Sales_data i : vsd) {
		print(cout,i);
		cout << endl;
	}
	system("pause");
	return 0;
}