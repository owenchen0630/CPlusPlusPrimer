#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
using namespace std::placeholders;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<int> vi{ 1,2,3,4,5,6,7,8,9 };
	vector<int> vi_copy_1;
	deque<int> vi_copy_2;
	deque<int> vi_copy_3;
	copy(vi.begin(), vi.end(), std::back_inserter(vi_copy_1));
	copy(vi.begin(), vi.end(), std::front_inserter(vi_copy_2));
	copy(vi.begin(), vi.end(), std::inserter(vi_copy_3,vi_copy_3.begin()));

	for (int i : vi_copy_1) {
		cout << i << " ";
	}
	cout << endl;
	for (int i : vi_copy_2) {
		cout << i << " ";
	}
	cout << endl;
	for (int i : vi_copy_3) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}