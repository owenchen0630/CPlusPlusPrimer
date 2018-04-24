#include <iostream>
using std::istream;
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;

std::istream& func(vector<string> &vs, istream& input) {
	
	std::string str;
	while (input>>str) {
		vs.push_back(str);
	}
	return input;
}
int main() {
	vector<string> vs;
	ifstream inputF("sstream");
	func(vs, inputF);
	for (int i = 0;i < vs.size();i++) {
		cout << vs[i] << endl;
	}
	system("pause");
	return 0;
}