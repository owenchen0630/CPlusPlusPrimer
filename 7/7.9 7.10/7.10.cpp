#include<iostream>
#include"Person.h"
int main() {
	Person p1;
	Person p2;
	//if (read(read(std::cin, p1),p2)) 的作用是p1、p2都有 有效输入 则 执行控制体内容。
	if (read(read(std::cin, p1),p2)) {
		print(std::cout, p1);
		std::cout << std::endl;
		print(std::cout, p2);
		std::cout << std::endl;
	}
	else {
		std::cerr << "NoData?!" << std::endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}