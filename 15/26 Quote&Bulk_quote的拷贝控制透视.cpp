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

class Quote {
	friend std::ostream& print(std::ostream&, Quote&);
public:
	Quote(const string &book = "", const double sales_price = 0.0) :bookNo(book), price(sales_price) { cout << "Quote constructor" << endl; };
	Quote(const Quote &q) :bookNo(q.bookNo), price(q.price) { cout << "Quote copy constructor" << endl; };
	Quote(Quote &&) = default;
	Quote& operator=(const Quote&);
	Quote& operator=(Quote&&) = default;
	virtual ~Quote() = default;
	string isbn() const {
		return bookNo;
	}
	virtual double net_price(size_t n) const {
		return n * price;
	}
private:
	string bookNo;
protected:
	double price = 0.0;
};

Quote& Quote::operator=(const Quote &q) {
	cout << "Quote = &" << endl;
	if (this == &q) return *this;
	bookNo = q.bookNo;
	price = q.price;
	return *this;
}

class Bulk_quote :public Quote {
	friend std::ostream& print(std::ostream&, Quote&);
public:
	Bulk_quote() = default;
	Bulk_quote(const string &s = "", double sales_price = 0.0, size_t n = 0, double disc = 0.0) :Quote(s, sales_price), min_qty(n), discount(disc) { cout << "Bulk_quote constructor" << endl; };
	Bulk_quote(const Bulk_quote &bq) :Quote(bq), min_qty(bq.min_qty), discount(bq.discount) { cout << "Bulk_quote copy constructor" << endl; }
	Bulk_quote& operator=(const Bulk_quote&);
	Bulk_quote& operator=(Bulk_quote&&) = default;
	~Bulk_quote() = default;
	double net_price(size_t) const;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

double Bulk_quote::net_price(size_t n) const {
	if (n > min_qty) return price * (1 - discount)*n;
	else return price * n;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote &bq) {
	if (this == &bq) return *this;
	Quote::operator=(bq);
	min_qty = bq.min_qty;
	discount = bq.discount;
	return *this;
}

std::ostream& print(std::ostream &os, Quote &q) {
	os << q.isbn() << " " << q.price;
	return os;
}



int main() {
	Quote q1("2222",3.3);
	Quote q2(q1);
	Bulk_quote bq1("2222", 3.3, 3, 0.3);
	Bulk_quote bq2(bq1);
	system("pause");
	return 0;
}
