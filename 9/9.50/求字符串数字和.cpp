#include <string>
using std::string;
#include <list>
using std::list;
#include <forward_list>
using std::forward_list;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

float stringSum(vector<string> &vs) {
	float sum = 0;
	for (string s : vs) {
		sum += stof(s);
	}
	return sum;
}

int main() {
	vector<string> vs{ "12.222","22.1111" };
	cout << stringSum(vs) << endl;
	system("pause");
	return 0;
}