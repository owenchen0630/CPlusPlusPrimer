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
	vector<int> orz1{ 1,2,3,4,5,6,7,8,9 };
	list<int> orz2{ 1,2,3,4,5,6,7,8,9 };
	vector<double> trg1(orz1.cbegin(), orz1.cend());
	vector<double> trg2(orz2.cbegin(), orz2.cend());
	for (int i = 0;i < trg1.size();i++) {
		cout << trg1[i] << " ";
	}
	cout << endl;
	for (int i = 0;i < trg2.size();i++) {
		cout << trg2[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
