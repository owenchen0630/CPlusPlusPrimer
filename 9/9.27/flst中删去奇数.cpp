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
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	auto flb = flst.begin(), flbb = flst.before_begin();
	while (flb != flst.end()) {
		if (*flb % 2) {
			flb = flst.erase_after(flbb);
		}
		else {
			flbb = flb;
			flb++;
		}
	}
	for (int i : flst) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}