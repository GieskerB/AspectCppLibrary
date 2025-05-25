#include "../prettier_tests.hh"

int main() {
	acp::test::print_pretty_start("Hello World Test", "This is a simple test to print 'Hello, World!'");
	acp::test::print_pretty_separator("Testing Correct Length of Separator");
	// This is the main functionality of the test.
	std::cout << "Hello, World!\n";
	acp::test::print_pretty_separator("Checking the printing of small separators under the condition that the message is longer than the length of the separator.");
	acp::test::print_pretty_end();

	return 0;
}
