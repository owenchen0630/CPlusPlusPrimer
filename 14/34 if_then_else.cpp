#include<vector>
using std::vector;
#include<string>
using std::string;
#include<memory>
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class if_then_else {
public:
	int operator()(bool c, const int a, const int b) {
		return c ? a : b;
	}
private:

};
int main() {
	if_then_else chose;
	cout << chose(true, 1, 2) << endl;
	system("pause");
	return 0;
}