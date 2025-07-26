#include "../prettier_tests.hh"

namespace [[acp::trace]] {
	void foo() {}
	void bar() {}
	void foobar() {}
	void barfoo() {}
}

int main() {

	acp::test::print_pretty_start("Tracer Test","This test checks if the Tracer aspect works as expected.");
	acp::test::print_pretty_separator("Calling Functions");
	bar();
	barfoo();
	bar();
	barfoo();
	foo();
	bar();
	foo();
	bar();
	foobar();
	bar();
	barfoo();
	foo();
	bar();
	barfoo();
	foo();
	bar();
	barfoo();
	bar();
	foo();
	bar();
	acp::test::print_pretty_end();

	return 0;
}
