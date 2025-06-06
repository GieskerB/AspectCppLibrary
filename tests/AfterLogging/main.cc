#include "../prettier_tests.hh"

void foo() {
	std::cout << "FOO\n";
}

[[acp::after_logging]] void bar(){
	std::cout << "BAR\n";
}

void foobar() {
	std::cout << "FOOBAR\n";
}

[[acp::after_logging]] void baz() {
	std::cout << "BAZ\n";
}

[[acp::after_logging]]void qux() {
	std::cout << "QUX\n";
}


int main() {
	acp::test::print_pretty_start("AfterLogging Test", "Testing the after_logging attribute");
	acp::test::print_pretty_separator("Function foo");
	foo();
	acp::test::print_pretty_separator("Function bar");
	bar();
	acp::test::print_pretty_separator("Function foobar");
	foobar();
	acp::test::print_pretty_separator("Function baz");
	baz();
	acp::test::print_pretty_separator("Function qux");
	qux();
	acp::test::print_pretty_end();
	return 0;
}
