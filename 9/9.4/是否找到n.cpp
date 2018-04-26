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

bool find(vector<int>::iterator ibegin, vector<int>::iterator iend, int n) {
	while (ibegin != iend) {
		if (*ibegin == n) return true;
		ibegin++;
	}
	return false;
}

int main() {
	list<deque<int>> lq;
	int n;
	cout << "Çë²ÂÒ»¸öÊý×Ö£¨1~20£©£º";
	cin >> n;
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	cout << find(nums.begin(), nums.end(), n) << endl;
	system("pause");
	return 0;
}