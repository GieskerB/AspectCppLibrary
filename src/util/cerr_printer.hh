#ifndef __ACP__INTERFACE_CERR_PRINTER_HH__
#define __ACP__INTERFACE_CERR_PRINTER_HH__

#include "printer.hh"
#include <ostream>

namespace acp {

class CerrPrinter: public Printer {

public:

	CerrPrinter() = default;
	virtual ~CerrPrinter() {}

	inline void print(const std::string& msg) const override{
		std::cerr << msg;
	}

	inline void print(const char* msg) const override{
		std::cerr << msg;
	}

	inline void print(const char msg) const override{
		std::cerr << msg;
	}

};

}

#endif // __ACP__INTERFACE_CERR_PRINTER_HH__
