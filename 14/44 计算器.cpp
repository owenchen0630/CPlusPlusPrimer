#include <algorithm>
#include <numeric>
#include <iterator>
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
#include <functional>
#include <map>

int main() {
	string s;
	std::map<string, std::function<int(int, int)>> binops = {
		{"+",std::plus<int>()},
		{"-",std::minus<int>()},
		{"*",std::multiplies<int>()},
		{"/",std::divides<int>()},
		{"%",std::modulus<int>()}
	};
	cout << "输入算式或q（退出）：" << endl;
	while (std::getline(cin, s)) {
		if (s.compare("q") == 0) break;
		auto sb = s.begin();
		auto sign = s.find_first_of("+-*/%");
		string a_str(s, 0, sign);
		int a = std::stoi(a_str);
		string func_str(s, sign, 1);
		string b_str(s, sign + 1);
		int b = std::stoi(b_str);
		cout << binops[func_str](a, b) << endl;
		cout << "输入算式或q（退出）：" << endl;
	}
	system("pause");
	return 0;
}