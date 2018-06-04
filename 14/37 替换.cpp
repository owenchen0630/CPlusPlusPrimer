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
class IsSame {
public:
	bool operator()(const string &a, const string &b) {
		return !a.compare(b);
	}

};
int main() {
	IsSame is;
	string s;
	vector<string> v;
	while (std::getline(cin, s)) {
		v.push_back(s);
	}
	for (auto vs : v)
		cout << vs << endl;
	cin.clear();
	cout << "ÊäÈëÒªÌæ»»µÄ×Ö·û" << endl;
	string st;
	cin >> st;
	cout << "ÊäÈëÌæ»»ºóµÄ×Ö·û" << endl;
	string sh;
	cin >> sh;
	for (int i = 0;i < v.size();i++) {
		if (is(v[i], st)) {
			v[i] = sh;
		}
	}
	for (auto vs : v)
		cout << vs << endl;
	system("pause");
	return 0;
}