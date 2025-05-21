#pragma once
#include <string>

class Printer {

public:

	Printer() = default;
	virtual ~Printer();

	virtual void print(const std::string& msg) const;
	virtual void print(const char* msg) const;
	virtual void print(const char digit) const;


};

Printer::~Printer() {

}

