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

int main() {
	Sales_data sd1("12345678",2,5), sd2("222222",3,5), sd3("111111", 3, 5);
	vector<Sales_data> vsd{ sd1,sd2,sd3 };
	stable_sort(vsd.begin(), vsd.end(), [](const Sales_data &s1, const Sales_data &s2) {return s1.isbn() < s2.isbn();});
	for (Sales_data i : vsd) {
		print(cout,i);
		cout << endl;
	}
	system("pause");
	return 0;
}