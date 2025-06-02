#include "../prettier_tests.hh"

[[acp::null_check]]int main() {

	double *a = new double(3.14);
	int *b = new int(69);
	std::string *c = new std::string("HI THERE");

	std::cout << "---\n";

	std::cout << "a: " << *a << "\n";
	std::cout << "b: " << *b << "\n";
	std::cout << "c: " << *c << "\n";

	std::cout << "---\n";

	int d = *b+2;
	double e = *a*2.5;

	char* f = nullptr;

	char g = *f;

	std::cout << "---\n";

	delete a;
	delete b;
	delete c;

	return 0;
}
