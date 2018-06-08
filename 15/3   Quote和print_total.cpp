#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <functional>
#include <map>

class Quote {
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote :public Quote {
	double net_price(size_t n) const { return n * price*0.95; }
};

double print_total(std::ostream &os, const Quote &item, const size_t n) {
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << item.net_price(n) << endl;
}
