#ifndef __ACP__INTERFACE_CERR_PRINTER_HH__
#define __ACP__INTERFACE_CERR_PRINTER_HH__

#include "printer.hh"
#include <ostream>

namespace acp {

/**
 * \class CerrPrinter
 * \file src/core/cerr_printer.hh
 * \brief CerrPrinter is a Printer implementation that prints messages to std::cerr.
 *
 * This class implements the Printer interface and provides methods to print messages
 * to the standard error output stream (std::cerr).
 */
class CerrPrinter: public Printer {

public:

	CerrPrinter() = default;
	virtual ~CerrPrinter() {}

	/**
	 * \function print[std::string]
 	 * \see :ref:`Printer::print <printer_hh_printstdstring>`
	 */
	inline void print(const std::string& msg) const override{
		std::cerr << msg;
	}

	/**
	 * \function print[c-string]
 	 * \see :ref:`Printer::print <printer_hh_printc-string>`
	 */
	inline void print(const char* msg) const override{
		std::cerr << msg;
	}

	/**
	 * \function print[char]
 	 * \see :ref:`Printer::print <printer_hh_printchar>`
	 */
	inline void print(const char digit) const override{
		std::cerr << digit;
	}

};

}

#endif // __ACP__INTERFACE_CERR_PRINTER_HH__
