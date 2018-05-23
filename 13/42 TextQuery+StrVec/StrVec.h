#ifndef STRVEC_H
#define STRVEC_H
#include <utility>
#include <string>
using std::string;
#include <memory>
using std::uninitialized_copy;
using std::allocator;

class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<string>);
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
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

StrVec::StrVec(std::initializer_list<string>li) {
	auto newdata = alloc_n_copy(li.begin(), li.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &sv) {
	auto newdata = alloc_n_copy(sv.begin(), sv.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t n) {
	if (n > capacity())
		reallocate_n(n);
}

void StrVec::resize(size_t n, const string& s) {
	while (n > size())
		push_back(s);
	while (n < size())
		alloc.destroy(--first_free);
}

std::pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free;p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate() {
	auto newcapacity = size() ? size() * 2 : 1;
	reallocate_n(newcapacity);
}

void StrVec::reallocate_n(size_t n) {
	auto newdata = alloc.allocate(n);
	auto elem = elements;
	auto dest = newdata;
	for (size_t i = 0;i != size();i++)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

allocator<string> StrVec::alloc{};//static成员使用需要定义

#endif // !STRVEC_H
