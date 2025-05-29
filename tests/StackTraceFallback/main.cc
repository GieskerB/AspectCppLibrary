#include "../prettier_tests.hh"
#include <stdexcept>

void foo() {
	throw std::runtime_error("foo-err");
}

void foobar () {foo();}

void bar () {foobar();}

[[acp::fallback]]void barfoo () {bar();}

void foofoo () {barfoo();}

void barbar(){foofoo();}

int main() {
	acp::test::print_pretty_start("Stack Trace Fallback Test", "Tests correct behaviour of fallback advice");

	barbar();

	acp::test::print_pretty_end();
	return 0;
}
