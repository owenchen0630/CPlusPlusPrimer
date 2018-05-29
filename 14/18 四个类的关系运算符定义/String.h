#pragma once
#ifndef STRING_H
#define STRING_H
#include <utility>
#include <memory>
using std::allocator;
#include <algorithm>
class String;
#include <iostream>
using std::cout;
using std::endl;

class String {
	friend std::ostream& print(std::ostream&, String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator>=(const String&, const String&);
	friend bool operator<(const String&, const String&);
	friend bool operator<=(const String&, const String&);
public:
	String() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String&);
	String(String&&) noexcept;
	String& operator=(const String&);
	String& operator=(String&&) noexcept;
	~String() { free(); }
	void push_back(const char&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
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

std::ostream& print(std::ostream&, String&);
std::ostream& operator<<(std::ostream&, const String&);



#endif // !STRING_H

