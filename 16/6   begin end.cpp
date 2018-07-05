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
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Sales_data.h"

template <typename T> int compare(const T& lhs, const T& rhs) {
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}

template <typename T, typename K> T find(T* iter_b, T* iter_e, K key) {
	while (iter_b != iter_e) {
		if (*iter_b == key) break;
		++iter_b;
	}
	return iter_b;
}

template <typename T, unsigned N> void print(T (&p)[N]) {
	for (auto i : p) {
		cout << i << " ";
	}
	cout << endl;
}

template <typename T, unsigned N> T* my_begin(T (&p)[N]) {
	return p;
}

template <typename T, unsigned N> T* my_end(T (&p)[N]) {
	return p+N;
}

int main() {
	vector<int> vi{ 1,2,3,4,5,6 };
	list<string> ls{ "aa","bb","cc","dd" };
	auto a = find(ls.begin(), ls.end(), "aa");
	if (a != ls.end()) cout << *a << endl;
	else cout << "NotFound" << endl;
	auto b = find(vi.begin(), vi.end(), 8);
	if (b != vi.end()) cout << *b << endl;
	else cout << "NotFound" << endl;
	int ip[10]{ 1,2,3,4,5,6,7,8,9,10 };
	print(ip); 
	char cp[3]{ 'a','b','c' };
	print(cp);
	cout << *(my_begin(ip)) << endl;
	cout << *(my_end(ip)-1) << endl;
	cout << *(my_begin(cp)) << endl;
	system("pause");
	return 0;
}
