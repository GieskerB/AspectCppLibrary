#include "../prettier_tests.hh"

[[acp::null_check]]void with_null_check() {
	acp::test::print_pretty_separator("With Null Check:");
	int *ptr = nullptr;
	int value = *ptr;
}

void without_null_check() {
	acp::test::print_pretty_separator("Without Null Check");
	int *ptr = nullptr;
	int value = *ptr;
}


int main() {

	acp::test::print_pretty_start("NullptrCheck Test", "Testing null pointer dereference handling");
	// without_null_check(); // Would result in segmentation fault ()
	with_null_check();
	acp::test::print_pretty_end();

	return 0;
}
