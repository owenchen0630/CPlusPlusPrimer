#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
using namespace std::placeholders;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;

int main() {
	ifstream input_file("poem.txt");
	std::istream_iterator<string> it(input_file);
	std::istream_iterator<string> eof;
	std::ostream_iterator<string> output(cout," ");
	vector<string> vs;
	std::copy(it, eof, std::back_inserter(vs));
	std::copy(vs.begin(), vs.end(), output);
	cout << endl;
	cout << vs.size() << endl;
	system("pause");
	return 0;
}