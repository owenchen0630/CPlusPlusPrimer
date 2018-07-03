#pragma once
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Quote {
	friend std::ostream& print(std::ostream&, Quote&);
public:
	Quote(const string &book = "", const double sales_price = 0.0) :bookNo(book), price(sales_price) {};
	Quote(const Quote &q) :bookNo(q.bookNo), price(q.price) {};
	Quote(Quote &&) = default;
	Quote& operator=(const Quote&);
	Quote& operator=(Quote&&) = default;
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
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
	if (this == &q) return *this;
	bookNo = q.bookNo;
	price = q.price;
	return *this;
}

class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string &book, double sales_price, size_t n, double disc_price)
		:Quote(book, sales_price), quantity(n), discount(disc_price) {
	}
	Disc_quote(const Disc_quote& dq) :Quote(dq), quantity(dq.quantity), discount(dq.discount) {}
	double net_price(size_t) const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote :public Disc_quote {
	friend std::ostream& print(std::ostream&, Quote&);
public:
	using Disc_quote::Disc_quote;
	Bulk_quote(const Bulk_quote& bq) :Disc_quote(bq) {}
	Bulk_quote& operator=(const Bulk_quote&);
	Bulk_quote& operator=(Bulk_quote&&) = default;
	Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
	~Bulk_quote() = default;
	double net_price(size_t) const;
};

double Bulk_quote::net_price(size_t n) const {
	if (n > quantity) return price * (1 - discount)*n;
	else return price * n;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote &bq) {
	if (this == &bq) return *this;
	Quote::operator=(bq);
	quantity = bq.quantity;
	discount = bq.discount;
	return *this;
}

std::ostream& print(std::ostream &os, Quote &q) {
	os << q.isbn() << " " << q.price;
	return os;
}

double print_total(std::ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}