#include "../prettier_tests.hh"

#include <thread>

[[acp::profile]] int load_test() {
	for (int i = 0; i < 100; ++i) {
		// Simulate some work
		int x = i * i;
		if (x % 2 == 0) {
			x += 1;
		} else {
			x -= 1;
		}
	}

	return 0;
}

[[acp::profile]] void thread_worker() {
	for (int i = 0; i < 100000; ++i) {
		load_test();
	}
}

[[acp::profile]] int main() {
	std::thread t1(thread_worker);
	std::thread t2(thread_worker);

	t1.join();
	t2.join();

	return 0;
}
