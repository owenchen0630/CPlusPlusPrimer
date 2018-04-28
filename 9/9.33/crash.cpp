#include <string>
using std::string;
#include <list>
using std::list;
#include <forward_list>
using std::forward_list;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	list<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto vb = vi.begin();
	while (vb != vi.end()) {
		++vb;
		vi.insert(vb, 42);//不赋值给vb，此步完成后vb指向上一部指向的元素（本该报错），但vs2017通过可能是编译器导致的不同结果
		++vb;
	}
	for (int i : vi) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}