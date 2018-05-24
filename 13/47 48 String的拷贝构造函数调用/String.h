#pragma once
#ifndef STRING_H
#define STRING_H
#include <utility>
#include <memory>
using std::allocator;
#include <algorithm>
class String;
std::ostream& print(std::ostream&, String&);

class String {
	friend std::ostream& print(std::ostream&, String&);
public:
	String() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String() { free(); }
	void push_back(const char&);
	size_t size() { return first_free - elements; }
	size_t capacity() { return cap - elements; }
	char *begin() const { return elements; }
	char *end() const { return first_free; }
private:
	static allocator<char> alloc;
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void reallocate();
	void reallocate_n(size_t);
	void free();
	char *elements;
	char *first_free;
	char *cap;
};

String::String(const char *c) {
	auto newdata = alloc_n_copy(c, c + strlen(c));
	elements = newdata.first;
	first_free = cap = newdata.second;
	cout << "run char* construct!" << endl;
}

String::String(const String &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	cout << "run copy construct!" << endl;
}

String& String::operator=(const String &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	cout << "run operator=!" << endl;
	return *this;
}

void String::push_back(const char &c) {
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
	auto data = alloc.allocate(e - b);
	return { data,std::uninitialized_copy(b,e,data) };
}

void String::reallocate() {
	auto newcapacity = (size()) ? size() * 2 : 1;
	reallocate_n(newcapacity);
}

void String::reallocate_n(size_t n) {
	auto newdata = alloc.allocate(n);
	auto elem = elements;
	auto dest = newdata;
	for (int i = 0;i != size();i++)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = newdata + n;

}

void String::free() {
	std::for_each(elements, first_free, [](char &c) {alloc.destroy(&c);});
	alloc.deallocate(elements, cap - elements);
}

std::ostream& print(std::ostream &os, String &s) {
	for (char &c : s) {
		os << c;
	}
	return os;
}

allocator<char> String::alloc{};
#endif // !STRING_H

