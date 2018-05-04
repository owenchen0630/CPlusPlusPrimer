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
	std::istream_iterator<int> in_iter(cin);
	std::istream_iterator<int> eof;
	std::ostream_iterator<int> out_iter(cout, " ");
	vector<int> vi(in_iter, eof);//需手动输入终止符Ctrl+Z
	std::sort(vi.begin(), vi.end());
	std::unique_copy(vi.begin(), vi.end(), out_iter);
	cout << endl;
	system("pause");
	return 0;
}