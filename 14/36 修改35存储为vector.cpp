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
	vector<string> operator()(std::istream &is) { 
		string s;
		while (std::getline(is, s)) {
			v.push_back(s);
		}return v;
	}
private:
	vector<string> v;
};
int main() {
	ReadString rs;
	vector<string> ss = rs(cin);
	for (auto s : ss) {
		cout << s << endl;
	}
	system("pause");
	return 0;
}