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
	vector<int> vi;
	for (int i = 0;i <= 50;i++) {
		vi.push_back(i);
		cout << vi.size() << " " << vi.capacity()<<endl;
	}
	system("pause");
	return 0;
}