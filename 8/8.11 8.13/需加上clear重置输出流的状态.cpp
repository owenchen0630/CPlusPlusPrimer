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

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {

	ifstream inputF("sstream");


	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(inputF, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
		record.clear();
	}

	for (int i = 0;i < people.size();i++) {
		cout << people[i].name << ": ";
		for (int j = 0;j < people[i].phones.size();j++) {
			cout << people[i].phones[j]<<" ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}