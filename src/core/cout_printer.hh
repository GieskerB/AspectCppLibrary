#ifndef __ACP__INTERFACE_COUT_PRINTER_HH__
#define __ACP__INTERFACE_COUT_PRINTER_HH__

#include "printer.hh"
#include <ostream>

namespace acp {

/**
 * \class CoutPrinter
 * \file src/core/cout_printer.hh
 * \brief CoutPrinter is a Printer implementation that prints messages to std::cout.
 *
 * This class implements the Printer interface and provides methods to print messages
 * to the standard error output stream (std::cout).
 */
class CoutPrinter: public Printer {

public:

	CoutPrinter() = default;
	virtual ~CoutPrinter() {}

	/**
	 * \function print[std::string]
 	 * \see :ref:`Printer::print <printer_hh_printstdstring>`
	 */
	inline void print(const std::string& msg) const override{
		std::cout << msg;
	}

	/**
	 * \function print[c-string]
 	 * \see :ref:`Printer::print <printer_hh_printc-string>`
	 */
	inline void print(const char* msg) const override{
		std::cout << msg;
	}

	/**
	 * \function print[char]
 	 * \see :ref:`Printer::print <printer_hh_printchar>`
	 */
	inline void print(const char digit) const override{
		std::cout << digit;
	}
};

}

#endif // __ACP__INTERFACE_COUT_PRINTER_HH__
