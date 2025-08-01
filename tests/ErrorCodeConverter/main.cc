#include "../prettier_tests.hh"
#include "../../src/error_detection/errno_exception.hh"

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <fcntl.h>
#include <cerrno>
#include <string>

[[acp::err_code]]int main() {

	acp::test::print_pretty_start("ErrorCodeConverterAspect Tests",
										  "Testing various incorrect usages of standard library functions that set errno");

	acp::test::print_pretty_separator("Test no. 1:");

    try {
        std::ifstream file("/root/.bashrc");
        std::cout << "FAILED: error not concerted! Errno was: "<< errno <<" \n";
    } catch (const acp::ErrnoException& e) {
        std::cout << "Errno: " << e.get_errno() << "\n";
    }

	acp::test::print_pretty_separator("Test no. 2:");

   try {
       	std::ifstream file("this_file_definitely_does_not_exist.xyz");
        std::cout << "FAILED: error not concerted! Errno was: "<< errno <<" \n";
    } catch (const acp::ErrnoException& e) {
        std::cout << "Errno: " << e.get_errno() << "\n";
    }

	acp::test::print_pretty_separator("Test no. 3:");

    try {
        const char* filename = "temp_file_for_eexist.txt";

		// Schritt 1: Datei einmal erstellen
		int fd1 = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		close(fd1);

		int fd2 = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0644);
		if (fd2 != -1) {
			close(fd2);
		}
        std::cout << "FAILED: error not concerted! Errno was: "<< errno <<" \n";
    } catch (const acp::ErrnoException& e) {
        std::cout << "Errno: " << e.get_errno() << "\n";
    }

	acp::test::print_pretty_separator("Test no. 4:");

    try {
        size_t huge_size = 100LL * 1024 * 1024 * 1024; // 100 GB
		void* ptr = malloc(huge_size);
		if (ptr != nullptr) {
			free(ptr);
		}
        std::cout << "FAILED: error not concerted! Errno was: "<< errno <<" \n";
    } catch (const acp::ErrnoException& e) {
        std::cout << "Errno: " << e.get_errno() << "\n";
    }


	acp::test::print_pretty_separator("Test no. 5:");

  	try {
		int fd = open("temp_file_for_badf.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		close(fd);

		char buffer[10];
		ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

        std::cout << "FAILED: error not concerted! Errno was: "<< errno <<" \n";
	} catch (const acp::ErrnoException& e) {
        std::cout << "Errno: " << e.get_errno() << "\n";
    }

	acp::test::print_pretty_end();

    return 0;
}
