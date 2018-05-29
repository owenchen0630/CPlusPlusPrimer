#include "StrVec.h"

allocator<string> StrVec::alloc{};//static成员使用需要定义

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

StrVec::StrVec(StrVec &&sv) noexcept
	:elements(sv.elements), first_free(sv.first_free), cap(sv.cap) {
	sv.elements = sv.first_free = sv.cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = std::move(rhs.elements);
		first_free = std::move(rhs.first_free);
		cap = std::move(rhs.cap);
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec& StrVec::operator=(const std::initializer_list<string> &li) {
	auto newdata = alloc_n_copy(li.begin(), li.end());
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
		std::for_each(elements, first_free, [](string &p) {alloc.destroy(&p);});
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

std::ostream& operator<<(std::ostream &os, const StrVec &s) {
	auto b = s.begin();
	while (b != s.end()) {
		os << *b << " ";
		b++;
	}
	return os;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
	if (lhs.size() != rhs.size()) return false;
	for (auto lb = lhs.begin(), rb = rhs.begin();lb != lhs.end() && rb != rhs.end();lb++, rb++)
		if (*lb != *rb) return false;
	return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs) {
	for (auto lb = lhs.begin(), rb = rhs.begin();lb != lhs.end() && rb != rhs.end();lb++, rb++) {
		if (*lb < *rb) return true;
		if (*lb > *rb) return false;
	}
	if (lhs.size() < rhs.size()) return true;
	else return false;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
	for (auto lb = lhs.begin(), rb = rhs.begin();lb != lhs.end() && rb != rhs.end();lb++, rb++) {
		if (*lb < *rb) return true;
		if (*lb > *rb) return false;
	}
	if (lhs.size() <= rhs.size()) return true;
	else return false;
}

bool operator>(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs <= rhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs < rhs);
}