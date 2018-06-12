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
	virtual void debug() const;
private:
	string bookNo;
protected:
	double price = 0.0;
};

void Quote::debug() const {
	cout << "Quote:" << endl;
	cout << "bookNo = " << bookNo << endl;
	cout << "price = " << price << endl;
}

class Bulk_quote :public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string&,double, size_t, double);
	double net_price(size_t) const;
	void debug() const;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const string &book, double sales_price, size_t n, double disc_price)
	:Quote(book,sales_price),min_qty(n),discount(disc_price){}

double Bulk_quote::net_price(size_t n) const {
	if (n > min_qty)
		return n * (1 - discount)*price;
	else
		return n * price;
}

void Bulk_quote::debug() const {
	Quote::debug();
	cout << "Bulk_quote:" << endl;
	cout << "min_qty= " << min_qty << endl;
	cout << "discount = " << discount << endl;
}
double print_total(std::ostream &os, const Quote &item, const size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

class limited_promotion :public Quote {
public:
	limited_promotion() = default;
	limited_promotion(const string &book, double price, size_t n, double disc) :Quote(book, price), max_qty(n), discount(disc) {}
	double net_price(size_t) const;
	void debug() const;
private:
	size_t max_qty=0;
	double discount = 0.0;
};

double limited_promotion::net_price(size_t n) const {
	if (n > max_qty)
		return max_qty * (1 - discount)*price + (n - max_qty)*price;
	else 
		return max_qty * (1 - discount)*price;
}

void limited_promotion::debug() const {
	Quote::debug();
	cout << "Bulk_quote:" << endl;
	cout << "max_qty= " << max_qty << endl;
	cout << "discount = " << discount << endl;
}

int main() {
	Quote q("bbb", 3);
	Bulk_quote quote("aaa", 3, 6, 0.5);
	limited_promotion lp("cccc", 3, 6, 0.5);
	print_total(cout, q, 7);
	print_total(cout, quote, 7);
	print_total(cout, lp, 7);
	quote.debug();
	cout << endl;
	lp.debug();
	system("pause");
	return 0;
}