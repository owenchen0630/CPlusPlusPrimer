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
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <new>

shared_ptr<vector<int>> makeVector() {
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> writeVector(shared_ptr<vector<int>> spvi) {
	int i;
	while (cin >> i) {
		spvi->push_back(i);
	}
	return spvi;
}

void printVector(shared_ptr<vector<int>> spvi) {
	for (int i : *spvi) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	printVector(writeVector(makeVector()));
	system("pause");
	return 0;
}