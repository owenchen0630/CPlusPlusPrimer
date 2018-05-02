//实现了简单的公式计算器 接受括号 +-*、/ 能自主判断运算顺序
#include <stack>
using std::stack;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int do_comput(string formula) {
	int pos = 0;
	int res = 0;
	vector<int> pos_a;
	string numbers = "1234567890";
	vector<int> nums;
	while ((pos = formula.find_first_not_of(numbers, pos)) != string::npos) {
		pos_a.push_back(pos);
		pos++;
	}
	if (pos_a.size() == 0) return stoi(formula);
	for (int i = 0;i < pos_a.size();i++) {
		if (i == 0) {
			string num = formula.substr(0, pos_a[i]);
			nums.push_back(stoi(num));
		}
		else {
			string num = formula.substr(pos_a[i - 1] + 1, pos_a[i] - pos_a[i - 1] - 1);
			nums.push_back(stoi(num));
		}
		if (i == pos_a.size() - 1) {
			string num = formula.substr(pos_a[i] + 1, formula.size() - pos_a[i] - 1);
			nums.push_back(stoi(num));
		}
	}
	for (int i = 0;i < pos_a.size();i++) {
		if (formula[pos_a[i]] == '*') {
			nums[i] *= nums[i + 1];
			nums.erase(nums.begin() + i + 1);
			pos_a.erase(pos_a.begin() + i);
			i--;
		}
		else if (formula[pos_a[i]] == '/') {
			nums[i] /= nums[i + 1];
			nums.erase(nums.begin() + i + 1);
			pos_a.erase(pos_a.begin() + i);
			i--;
		}
	}
	res += nums[0];
	if (nums.size() == 1) return res;
	for (int i = 0;i < pos_a.size();i++) {
		if (formula[pos_a[i]] == '+') {
			res += nums[i + 1];
		}
		if (formula[pos_a[i]] == '-') {
			res -= nums[i + 1];
		}
	}
	return res;
}

int comput(string input) {
	int res = 0;
	int l_flag = 0;
	stack<char> progressList;
	for (char i : input) {
		progressList.push(i);
		if (i == '(') l_flag++;
		if (i == ')' && l_flag > 0) {
			progressList.pop();
			string formula = "";
			while (progressList.top() != '(') {
				formula += progressList.top();
				progressList.pop();
			}
			progressList.pop();
			reverse(formula.begin(), formula.end());
			int cr = do_comput(formula);
			string s_cr = std::to_string(cr);
			for (char i : s_cr) {
				progressList.push(i);
			}
		}
		if (i == ')' && l_flag == 0) {
			std::cout << "(!=)" << endl;
			return -1;
		}
	}
	string formula = "";
	while (progressList.size() != 0) {
		formula += progressList.top();
		progressList.pop();
	}
	reverse(formula.begin(), formula.end());
	res = do_comput(formula);
	return res;
}


int main() {
	string input;
	std::getline(cin, input);
	int res = comput(input);
	cout << res << endl;
	system("pause");
	return 0;
}