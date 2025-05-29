#include "../prettier_tests.hh"
#include <stdexcept>

#include "functions_a.hh"
#include "functions_b.hh"

void foofoo () {barfoo();}

void barbar(){foofoo();}

int main() {
	acp::test::print_pretty_start("Stack Trace Fallback Test", "Tests correct output when stack trace tracks multiple files.");

	barbar();

	acp::test::print_pretty_end();
	return 0;
}
