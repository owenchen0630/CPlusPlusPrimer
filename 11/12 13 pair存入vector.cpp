#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>
using std::pair;
using std::make_pair;
#include <functional>
using namespace std::placeholders;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <map>
using std::map;
#include<sstream>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<pair<string, int>> vp;
	string input;
	while (std::getline(cin,input)) {
		std::istringstream is(input);
		string s;
		int i;
		is >> s >> i;
		//vp.push_back(make_pair(s, i));
		//vp.push_back({ s,i });
		vp.push_back(pair<string, int>(s, i));
	}
	for (pair<string, int> p : vp) {
		cout << p.first << " " << p.second << endl;
	}
	system("pause");
	return 0;
}