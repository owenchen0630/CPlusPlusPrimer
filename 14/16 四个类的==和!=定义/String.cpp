#include "String.h"

allocator<char> String::alloc{};//使用前声明

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

String::String(String &&s) noexcept
	:elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
	cout << "run move construct!" << endl;
}

String& String::operator=(const String &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	cout << "run operator=!" << endl;
	return *this;
}

String& String::operator=(String &&s) noexcept {
	if (this != &s) {
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	cout << "run move operator=!" << endl;
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

std::ostream& operator<<(std::ostream &os, const String &s) {
	for (char &c : s) {
		os << c;
	}
	return os;
}

bool operator==(const String &lhs, const String &rhs) {
	if (lhs.size() != rhs.size()) return false;
	for (auto lb = lhs.begin(), rb = rhs.begin();lb != lhs.end(), rb != rhs.end();lb++, rb++)
		if (*lb != *rb) return false;
	return true;
}
bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}