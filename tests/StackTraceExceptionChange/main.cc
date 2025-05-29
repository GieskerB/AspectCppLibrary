#include "../prettier_tests.hh"
#include <stdexcept>

void except1() {
	throw std::runtime_error("except1-err");
}

void foo () {except1();}

void bar () {foo();}

void except2() {
	try {
		bar();
	} catch (std::runtime_error & e) {
		throw std::runtime_error("except2-err");
	}
}

void foobar () {except2();}

void barfoo () {foobar();}

int main() {
	acp::test::print_pretty_start("Stack Trace Test", "Tests for stack trace functionality when excpt. changes.");

	barfoo();

	acp::test::print_pretty_end();
	return 0;
}
