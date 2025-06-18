#include "../prettier_tests.hh"

#include <pthread.h>
#include <iostream>
#include <unistd.h>

int counter = 0;

const int NUM_THREADS = 10;
const int INCREMENTS_PER_THREAD = 100000;

[[acp::synchronized]] void* thread_func(void* arg) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; ++i) {
		// Extra possibilities for errors!
        int value = counter;
		value = value +1;
        counter = value;
    }
    return nullptr;
}

int main() {

	acp::test::print_pretty_start("Synchronization","Tests the syncronization via mutex for a function");

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], nullptr, thread_func, nullptr);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], nullptr);
    }

    std::cout << "Total count: " << counter << '\n';

	acp::test::print_pretty_end();

    return 0;
}
