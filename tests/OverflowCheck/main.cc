#include "../prettier_tests.hh"

#include <limits>

[[acp::overflow_check]]void check() {
	int a = 3;
	int b = 4;

	a++;
	++b;

	a += b;

	b = a + a;

	int MIN = std::numeric_limits<int>::min();

	int c = +MIN;

}


int main() {

	acp::test::print_pretty_start("NullptrCheck Test", "Testing null pointer dereference handling");
	// without_null_check(); // Would result in segmentation fault ()
	check();
	acp::test::print_pretty_end();

	return 0;
}
