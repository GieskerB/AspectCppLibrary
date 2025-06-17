#include "../prettier_tests.hh"

#include <pthread.h>
#include <iostream>
#include <unistd.h>

int counter = 0;  // gemeinsame Variable, keine Synchronisation

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
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], nullptr, thread_func, nullptr);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], nullptr);
    }

    std::cout << "Endwert des Counters: " << counter << std::endl;
    std::cout << "Erwarteter Wert: " << NUM_THREADS * INCREMENTS_PER_THREAD << std::endl;

    if (counter != NUM_THREADS * INCREMENTS_PER_THREAD) {
        std::cout << "Race Condition erkannt! Synchronisation fehlt." << std::endl;
    } else {
        std::cout << "Kein Race Condition erkannt. Synchronisation scheint zu funktionieren." << std::endl;
    }

    return 0;
}
