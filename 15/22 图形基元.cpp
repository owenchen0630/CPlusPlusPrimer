#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Figure {
public:
	Figure(double, double);
protected:
	double xSize, ySize;
};

class Figure_2D : public Figure {
public:
	Figure_2D(double, double);
	virtual double area() = 0;
	virtual double perimeter() = 0;
};

class Figure_3D : public Figure {
	Figure_3D(double, double, double);
	virtual double cubage() = 0;
};

class Rectangle : public Figure_2D {
public:
	Rectangle(double, double);
	double area();
	double perimeter();
};

int main() {
	
	system("pause");
	return 0;
}
