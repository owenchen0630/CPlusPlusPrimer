#include <string>
using std::string;
#include <list>
using std::list;
#include <forward_list>
using std::forward_list;
#include <deque>
using std::deque;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

struct MyData
{
	MyData() = default;
	MyData(string &data);
	unsigned year;
	unsigned month;
	unsigned day;
};

MyData::MyData(string &data) {
	string lorn = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	int pos = 0;
	vector<int> interval;
	while ((pos = data.find_first_not_of(lorn, pos)) != string::npos) {
		interval.push_back(pos);
		pos++;
	}
	string fs = data.substr(0, interval[0]);
	string ss = data.substr(interval[0] + 1, interval[1] - interval[0] - 1);
	string ts = data.substr(interval[1] + 1, data.size() - interval[1] - 1);
	if (fs.find_first_not_of("0123456789") != string::npos) {
		if (fs.compare(0, 3, "Jan") == 0) {
			month = 1;
		}
		if (fs.compare(0, 3, "Feb") == 0) {
			month = 2;
		}
		if (fs.compare(0, 3, "Mar") == 0) {
			month = 3;
		}
		if (fs.compare(0, 3, "Apr") == 0) {
			month = 4;
		}
		if (fs.compare(0, 3, "May") == 0) {
			month = 5;
		}
		if (fs.compare(0, 3, "Jun") == 0) {
			month = 6;
		}
		if (fs.compare(0, 3, "Jul") == 0) {
			month = 7;
		}
		if (fs.compare(0, 3, "Agu") == 0) {
			month = 8;
		}
		if (fs.compare(0, 3, "Sep") == 0) {
			month = 9;
		}
		if (fs.compare(0, 3, "Oct") == 0) {
			month = 10;
		}
		if (fs.compare(0, 3, "Nov") == 0) {
			month = 11;
		}
		if (fs.compare(0, 3, "Dec") == 0) {
			month = 12;
		}
		day = stoi(ss);
		year = stoi(ts);
	}
	else if (fs.size() <= 2) {
		month = stoi(fs);
		day = stoi(ss);
		year = stoi(ts);
	}
	else {
		year = stoi(fs);
		month = stoi(ss);
		day = stoi(ts);
	}
}
int main() {
	string data;
	std::getline(cin,data);
	MyData mydata(data);
	cout << mydata.year << " " << mydata.month << " " << mydata.day << endl;
	system("pause");
	return 0;
}