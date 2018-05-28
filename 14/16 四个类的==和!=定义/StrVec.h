#pragma once
#ifndef STRVEC_H
#define STRVEC_H
#include <utility>
#include <string>
using std::string;
#include <memory>
using std::uninitialized_copy;
using std::allocator;
#include <algorithm>

class StrVec {
	friend std::ostream& operator<<(std::ostream&, const StrVec&);
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<string>);
	StrVec(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec &operator=(const StrVec&);
	StrVec &operator=(StrVec&&) noexcept;
	~StrVec() { free(); }
	void push_back(const string&);
	void reserve(size_t);
	void resize(size_t, const string& s = "");
	string& at(size_t n) { return *(elements + n); }
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
private:
	static allocator<string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	void reallocate_n(size_t);
	string *elements;//首指针
	string *first_free;//指向最后一个实际元素之后
	string *cap;//指向分配内存尾后位置
};

std::ostream& operator<<(std::ostream&, const StrVec&);


#endif // !STRVEC_H
