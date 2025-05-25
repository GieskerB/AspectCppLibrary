#include "../prettier_tests.hh"


void foo() {
	throw std::runtime_error("foo-err");
}

void foo1 (int a, int b) {
	foo();
}


void foo2 () {
	foo1(2,3);
}


void foo3 (const std::string str) {
	foo2();
}


void foo4 () {
	foo3("THIS IS A TEST STRING");
}

int main() {
	acp::test::print_pretty_start("Stack Trace Test", "Tests for stack trace functionality by throwing an exception caught and uncaught.");
	acp::test::print_pretty_separator("Testing Stack Trace with Caught Exception");

	try {
		foo2();
	}  catch (std::runtime_error & e) {
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	acp::test::print_pretty_separator("Testing Stack Trace with Uncaught Exception");

	foo4();

	acp::test::print_pretty_end();
	return 0;
}
