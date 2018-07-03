#pragma once
#include <set>
using std::multiset;
#include "Quote.h"
class Basket {
public:
	//Basket使用合成的默认构造函数和拷贝控制成员
	void add_item(const shared_ptr<Quote> &sale) {
		items.insert(sale);
	}
	double total_receipt(std::ostream&) const;
	void add_item(const Quote& sale) {
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale) {
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
private:
	static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

double Basket::total_receipt(std::ostream &os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin();iter != items.cend();iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}