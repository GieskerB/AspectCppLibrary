#include "../prettier_tests.hh"

[[acp::cache]] int cache_me_if_you_can(int a, int b) {
	// Complex calculations:
	int c = a * a + 2 * a * b + b * b;
	return c;
}


int main() {

	std::cout << cache_me_if_you_can(3,4) << '\n';
	std::cout << cache_me_if_you_can(3,4) << '\n';
	std::cout << cache_me_if_you_can(5,5) << '\n';


	return 0;
}
