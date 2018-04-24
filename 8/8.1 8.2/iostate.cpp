#include <iostream>
#include <string>
#include <fstream>

std::istream& func(std::istream& input) {
	std::string str;
	while (input >> str) {
		std::cout << str << std::endl;
	}
	input.clear();
	return input;
}
int main() {
	std::ifstream inputF("sstream");
	std::cout << "使用文件输入：" << std::endl;
	std::cout << func(inputF).good() << std::endl;
	std::cout << "使用cin输入：" << std::endl;//Ctrl+Z为结束符
	std::cout<<func(std::cin).good()<<std::endl;
	system("pause");
	return 0;
}