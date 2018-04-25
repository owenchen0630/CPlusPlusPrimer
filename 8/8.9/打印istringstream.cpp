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

std::istream& func(std::istream& input) {
	std::string str;
	while (std::getline(input,str)) {
		std::cout << str << std::endl;
	}
	input.clear();
	return input;
}
int main() {
	string str("ABCDEF AAAA CCC 222");
	istringstream record(str);
	std::ifstream inputF("sstream");
	std::cout << "使用文件输入：" << std::endl;
	std::cout << func(inputF).good() << std::endl;
	std::cout << "使用istringstream输入：" << std::endl;
	std::cout << func(record).good() << std::endl;
	//std::cout << "使用cin输入：" << std::endl;//Ctrl+Z为结束符
	//std::cout << func(std::cin).good() << std::endl;
	system("pause");
	return 0;
}
