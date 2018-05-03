#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
using namespace std::placeholders;
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
	vector<int> vi{ 9,9,9,9,9,8,8,8,1,1,2,2,2,2,3,4,5,6,7,8,9 };
	list<int> li;
	sort(vi.begin(), vi.end());
	std::unique_copy(vi.begin(), vi.end(), std::back_inserter(li));
	for (int i : li) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}