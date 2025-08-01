#include "../prettier_tests.hh"

namespace [[acp::after_logging]] test1 {
	void foo() {}
	[[acp::ignore_everything]] void bar() {}
	void foobar() {}
}

class [[acp::after_logging]] test2 {
	public:

	static void foo() {}
	[[acp::ignore_logging]] static void bar() {}
	static void foobar() {}

};

int main() {
	acp::test::print_pretty_start("Ignore Attribute Test","Checks if join points are properly ignored");

	acp::test::print_pretty_separator("First test within a namespace using ignore everything");

	test1::foo();
	test1::bar();
	test1::foobar();

	acp::test::print_pretty_separator("Second test within a class using ignore logging");

	test2::foo();
	test2::bar();
	test2::foobar();

	acp::test::print_pretty_end();
}
