#include <string>
using std::string;
#include <list>
using std::list;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int ia[] = { 0,1,1,2,3,5,8,13,32,55,89 };
	vector<int> vi(ia,ia+(sizeof(ia)/sizeof(int)));
	list<int> li(ia, ia + (sizeof(ia) / sizeof(int)));
	auto vb = vi.begin();
	auto lb = li.begin();
	while (vb != vi.end()) {
		if (!(*vb % 2)) {
			vb = vi.erase(vb);
		}
		else vb++;
	}
	while (lb!=li.end()) {
		if (*lb % 2) {
			lb = li.erase(lb);
		}
		else lb++;
	}
	for (int i : vi) {
		cout << i << " ";
	}
	cout << endl;
	for (int i : li) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}