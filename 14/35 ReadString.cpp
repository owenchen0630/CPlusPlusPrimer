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
class ReadString {
public:
	ReadString(const string& str="") :s(str) {};
	string operator()(std::istream &is) { std::getline(is, s);return s; }
private:
	string s;
};
int main() {
	ReadString rs;
	string ss = rs(cin);
	cout << ss << endl;
	system("pause");
	return 0;
}