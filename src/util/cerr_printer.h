#pragma once

#include "printer.h"

class CerrPrinter : public Printer {

public:

	CerrPrinter() = default;
	virtual ~CerrPrinter();

	virtual void print(const std::string& msg) const override;

	virtual void print(const char* msg) const override;

	virtual void print(const char msg) const override;

};

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
