#ifndef __ACP__INTERFACE_COUT_PRINTER_HH__
#define __ACP__INTERFACE_COUT_PRINTER_HH__

#include "printer.hh"
#include <ostream>

namespace acp {

class CoutPrinter: public Printer {

public:

	CoutPrinter() = default;
	virtual ~CoutPrinter() {}

	inline void print(const std::string& msg) const override{
		std::cout << msg;
	}

	inline void print(const char* msg) const override{
		std::cout << msg;
	}

	inline void print(const char msg) const override{
		std::cout << msg;
	}

};

}

#endif // __ACP__INTERFACE_COUT_PRINTER_HH__
