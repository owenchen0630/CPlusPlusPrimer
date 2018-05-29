#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
	//友元声明
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &operator<<(std::ostream&, const Sales_data&);
	friend std::istream &operator>>(std::istream&, Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
public:
	//构造函数
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data() :Sales_data("", 0, 0) {} //默认构造函数
	explicit Sales_data(std::istream &is) :Sales_data() {}
	explicit Sales_data(const std::string &s) :Sales_data(s, 0, 0) {}
	Sales_data& operator+=(const Sales_data&);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//Sales_data 接口的非成员组成部分的声明
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif