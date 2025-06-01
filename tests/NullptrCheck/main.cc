#include "../prettier_tests.hh"

int main() {

	double a = 3;
	double b = 4;

	double c = a * b;

	double* ptr = &c;

	std::cout << "Address of c: " << ptr << "\n";
	std::cout << "Value of c: " << *ptr << "\n";

	return 0;
}
