#include "cerr_printer.h"
#include <iostream>

CerrPrinter::~CerrPrinter() {}

void CerrPrinter::print(const std::string& msg) const{
	std::cerr << msg;
}

void CerrPrinter::print(const char* msg) const {
	std::cerr << msg;
}

void CerrPrinter::print(const char msg) const {
	std::cerr << msg;
}
