#include "../prettier_tests.hh"

#include <iostream>
#include <cstdint>

int alter_result = 0;

[[acp::cache]] double all_primitive_types(char c, unsigned char uc, int i, unsigned int ui, short s, unsigned short us,
								   long l, unsigned long ul, long long ll, unsigned long long ull, float f, double d,
								   bool b) {

	return static_cast<double>(c) + static_cast<double>(uc) + static_cast<double>(i) +
		   static_cast<double>(ui) + static_cast<double>(s) + static_cast<double>(us) +
		   static_cast<double>(l) + static_cast<double>(ul) + static_cast<double>(ll) +
		   static_cast<double>(ull) + f + d + (b ? 1.0 : 0.0) + static_cast<double>(alter_result++);
	// use alter_result to change the result on each call if cache does not hit.

}

// For testing pointer types
[[acp::cache]] double all_primitive_ptr_types(char* c, unsigned char* uc, int* i, unsigned int* ui, short* s, unsigned short* us,
								   long* l, unsigned long* ul, long long* ll, unsigned long long* ull, float* f, double* d,
								   bool* b) {

	return static_cast<double>(*c) + static_cast<double>(*uc) + static_cast<double>(*i) +
		   static_cast<double>(*ui) + static_cast<double>(*s) + static_cast<double>(*us) +
		   static_cast<double>(*l) + static_cast<double>(*ul) + static_cast<double>(*ll) +
		   static_cast<double>(*ull) + *f + *d + (*b ? 1.0 : 0.0);

}

int main() {

	char c = 65;
    unsigned char uc = 200;
    int i = -10;
    unsigned int ui = 25;
    short s = 50;
    unsigned short us = 100;
    long l = 1000;
    unsigned long ul = 5000;
    long long ll = -100000LL;
    unsigned long long ull = 1000000ULL;
    float f = 3.14f;
    double d = 2.718;
    bool b = true;


	acp::test::print_pretty_start("ResultCache Test","Checks correct functionality of the ResultCache aspect");

	acp::test::print_pretty_separator("Call function first time.");
    double result = all_primitive_types(c, uc, i, ui, s, us, l, ul, ll, ull, f, d, b);
    // double result_ptr = all_primitive_ptr_types(&c, &uc, &i, &ui, &s, &us, &l, &ul, &ll, &ull, &f, &d, &b);

	std::cout << "Result of all_primitive_types: " << result << std::endl;


	acp::test::print_pretty_separator("Call function second time. Result should not change!");
	std::cout << "Altered result: " << all_primitive_types(c, uc, i, ui, s, us, l, ul, ll, ull, f, d, b) << std::endl;

    acp::test::print_pretty_end();

    return 0;
}
