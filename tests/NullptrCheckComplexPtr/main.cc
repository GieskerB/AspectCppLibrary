#include "../prettier_tests.hh"

#include <vector>
#include <string>

[[acp::null_check]] int main() {

	acp::test::print_pretty_start("NullptrCheck Test", "Testing null pointer dereference handling");
	std::vector<std::string>* null_vec = nullptr;
	std::string value = (*null_vec)[0];
	acp::test::print_pretty_end();

	return 0;
}
