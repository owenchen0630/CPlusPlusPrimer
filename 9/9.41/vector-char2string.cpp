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

int main() {
	vector<char> vc = {'A','B','C','D','E'};
	string s(vc.begin(),vc.end());
	cout << s << endl;
	system("pause");
	return 0;
}