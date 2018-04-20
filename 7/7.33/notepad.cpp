#include <iostream>
#include "notepad.h"
int main() {
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << std::endl;
	std::cout << myScreen.size() <<std::endl;
	myScreen.display(std::cout);
	std::cout << std::endl;
	system("pause");
	return 0;
}