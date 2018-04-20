#include <string>

struct NoDefault
{
	NoDefault(int x) :n(x) {}
	int n;
};

struct C
{
	C(int x = 10) :n(x) {}
	NoDefault n;
};

int main() {
	C c;
	printf("%d\n", c.n);
	system("pause");
	return 0;
}