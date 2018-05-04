#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<numeric>
#include<fstream>
#include"Sales_item.h"
using std::cout;
using std::cin;
using std::endl;


int main() {
	std::ifstream input_file("numbers.txt");
	std::ofstream output_odd("oddnumbers.txt");
	std::ofstream output_even("evennumbers.txt");
	std::istream_iterator<int> numbers_iter(input_file);
	std::istream_iterator<int> eof;
	std::ostream_iterator<int> odd_iter(output_odd, "\n");
	std::ostream_iterator<int> even_iter(output_even, " ");
	std::vector<int> numbers(numbers_iter,eof);
	auto odd_end = std::stable_partition(numbers.begin(), numbers.end(), [](int i) {return i % 2;});
	std::copy(numbers.begin(), odd_end, odd_iter);
	std::copy(odd_end, numbers.end(), even_iter);
	system("pause");
	return 0;
}