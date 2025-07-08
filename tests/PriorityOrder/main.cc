#include "../prettier_tests.hh"

void foo() {}

int main() {

	acp::test::print_pretty_start("PriorityOrder","Testing the hierarchical order implementation with Low, Medium, High");

	foo();

	acp::test::print_pretty_end();

	return 0;
}
