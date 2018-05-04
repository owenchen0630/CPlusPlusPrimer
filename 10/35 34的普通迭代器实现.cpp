#include<iostream>
#include<iterator>
using std::istream_iterator;
using std::ostream_iterator;
#include<vector>
using std::vector;
#include<algorithm>
#include<numeric>
#include<fstream>
#include<string>
using std::string;
#include"Sales_item.h"
using std::cout;
using std::cin;
using std::endl;


int main() {
	vector<string> vs{ "sdasdas","312312321","sdaweqweqw","poipoipoi" };
	auto vsb = vs.cbegin();
	auto vse = vs.cend();
	while (vse != vsb) {
		vse--;
		cout << *vse << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}