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

vector<int>* makeVector() {
	return new vector<int>;
}

vector<int>* writeVector(vector<int>* pvi) {
	int i;
	while (cin >> i) {
		pvi->push_back(i);
	}
	return pvi;
}

vector<int>* printVector(vector<int>* pvi) {
	for (int i : *pvi) {
		cout << i << " ";
	}
	cout << endl;
    return pvi;
}
int main() {
	vector<int>* pvi = printVector(writeVector(makeVector()));
    delete pvi;
    pvi = nullptr;
	system("pause");
	return 0;
}