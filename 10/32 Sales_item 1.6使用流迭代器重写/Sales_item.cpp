#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<numeric>
#include"Sales_item.h"
using std::cout;
using std::cin;
using std::endl;

bool compareIsbn(const Sales_item &sd1, const Sales_item &sd2) {
	return sd1.isbn() < sd2.isbn();
}

int main() {
	Sales_item total;
	std::istream_iterator<Sales_item> in_iter(cin);
	std::istream_iterator<Sales_item> eof;
	std::vector<Sales_item> vsi(in_iter, eof);
	if (vsi.empty()) {
		std::cerr << "No data?!" << endl;
		return -1;
	}
	std::sort(vsi.begin(), vsi.end(), compareIsbn);
	auto vsib = vsi.begin();
	while (vsib != vsi.end()) {
		auto r = std::find_if(vsib, vsi.end(), [vsib](Sales_item &si) {return si.isbn() != vsib->isbn();});
		cout << std::accumulate(vsib+1, r, *vsib) << endl;
		vsib = r;
	}
	system("pause");
	return 0;
}