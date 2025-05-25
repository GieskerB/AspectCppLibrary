#ifndef __TEST__PRETTIER__TESTS_HH__
#define __TEST__PRETTIER__TESTS_HH__

#include <iostream>

namespace acp {
    namespace test {

        constexpr const int SEPARATOR_LENGTH = 100;
        constexpr const char BIG_SEPARATOR_CHAR = '=';
        constexpr const char SMALL_SEPARATOR_CHAR = '-';

        const std::string BIG_SEPARATOR(SEPARATOR_LENGTH, BIG_SEPARATOR_CHAR);
        const std::string SMALL_SEPARATOR(SEPARATOR_LENGTH, SMALL_SEPARATOR_CHAR);

        void print_pretty_start(const char* test_name, const char* test_message) {
            std::cout << test_name << ": " << test_message << '\n';
            std::cout << BIG_SEPARATOR << '\n';
        }

        void print_pretty_start(const char* test_name) {
            print_pretty_start(test_name, "");
        }

        void print_pretty_separator() { std::cout << SMALL_SEPARATOR << '\n'; }

        void print_pretty_separator(std::string message) {
            const int MSG_LEN = message.size();
            std::cout << SMALL_SEPARATOR_CHAR
                      << message;
            if (MSG_LEN < SEPARATOR_LENGTH - 1) {
                std::cout << std::string(SEPARATOR_LENGTH - 1 - MSG_LEN,
                                         SMALL_SEPARATOR_CHAR);
            }
            std::cout << '\n';
        }

        void print_pretty_end() { std::cout << BIG_SEPARATOR << '\n'; }

    }  // namespace test
}  // namespace acp

#endif
