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
#include <sstream>
using std::istringstream;

std::istream& func(vector<string> &vs, istream& input) {

	std::string str;
	while (getline(input, str)) {
		vs.push_back(str);
	}
	return input;
}
int main() {
	vector<string> vs;
	ifstream inputF("sstream");
	func(vs, inputF);

	for (int i = 0;i < vs.size();i++) {
		istringstream record(vs[i]);
		string output;
		while (record >> output) {
			cout << output << endl;
		}
	}
	system("pause");
	return 0;
}