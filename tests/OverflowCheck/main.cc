#include "../prettier_tests.hh"

#include "../../src/util/overflow_exception.hh"

#include <limits>

[[acp::overflow_check]] int main() {

	acp::test::print_pretty_start("NullptrCheck Test", "Testing null pointer dereference handling");
	acp::test::print_pretty_separator("None problematic additions");
	int a = 2363422;
	int b = 673436;
	int max = std::numeric_limits<int>::max();
	int min = std::numeric_limits<int>::min();
	a++;
	++b;
	a += b;
	b = a + a;
	std::cout << "A: "<< a << ", B: " << b <<'\n';
	acp::test::print_pretty_separator("Binary Overflow");
	try {
		int c = max + b;
		std::cout << "No error found.\n";
	} catch (acp::OverflowException& e) {
		std::cout << e.what() << '\n';
	}
	acp::test::print_pretty_separator("Unary Increment Overflow");
	try {

		int c = max++;
		std::cout << "No error found.\n";
	} catch (acp::OverflowException& e) {
		std::cout << e.what() << '\n';
	}
	acp::test::print_pretty_separator("Unary Overflow");
	try {
		int c = +min;
		std::cout << "No error found.\n";
	} catch (acp::OverflowException& e) {
		std::cout << e.what() << '\n';
	}
	acp::test::print_pretty_end();

	return 0;
}
