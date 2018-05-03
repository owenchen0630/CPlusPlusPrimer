#include <algorithm>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<int> vi;
	int i;
	while (cin >> i) {
		vi.push_back(i);
	}
	cout << "5出现了" << std::count(vi.begin(), vi.end(), 5) << "次" << endl;
	system("pause");
	return 0;
}