#include <algorithm>
#include <numeric>
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

int main() {
	vector<int> vi = { 1,2,3,4,5,6,7,8,9 };
	fill_n(vi.begin(), vi.size(), 0);
	for (int i : vi) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}