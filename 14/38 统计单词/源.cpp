#include<vector>
using std::vector;
#include<string>
using std::string;
#include<memory>
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class longAs {
public:
	bool operator()(const string &s, int n) {
		return s.size() == n;
	}
};
int main() {
	ifstream infile("what faith can do");
	string s;
	longAs la;
	vector<int> num(10,0);
	while (infile >> s) {
		for (int i = 1;i <= 10;i++) {
			if (la(s, i)) num[i]++;
		}
	}
	for (int i : num) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}