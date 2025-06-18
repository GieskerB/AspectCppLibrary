#include "../prettier_tests.hh"

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <chrono>

void* threadFunc1(void* arg) {
    sleep(1);
    return nullptr;
}

void* threadFunc2(void* arg) {
    sleep(1);
    return nullptr;
}

int main() {

    acp::test::print_pretty_start("SynchronizationMultiFunction","Tests if mutex is exclusive per function or global");
    pthread_t t1, t2;

    auto start = std::chrono::high_resolution_clock::now();

    pthread_create(&t1, nullptr, threadFunc1, nullptr);
    pthread_create(&t2, nullptr, threadFunc2, nullptr);

    // Wait for both threads
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = end - start;

    if(elapsed.count() < 2) {
        std::cout << "Works\n";
    } else {
        std::cout << "Does not work\n";
    }
    acp::test::print_pretty_end();

    return 0;
}
