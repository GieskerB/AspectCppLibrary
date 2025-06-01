#include "../prettier_tests.hh"


[[acp::profile]] int test1() {
	// This test is a placeholder for the actual profiler test.
	// It should be replaced with real profiling code.
	return 0;
}

[[acp::profile]] int test2() {
	// This test is a placeholder for the actual profiler test.
	// It should be replaced with real profiling code.

	for (int i = 0; i < 1000000; ++i) {
		// Simulate some work
		int x = i * i;
		if (x % 2 == 0) {
			x += 1;
		} else {
			x -= 1;
		}
		test1();
	}

	return 0;
}

int main() {

	test2();

	return 0;
}
