#ifndef __ACP__INTERFACE_COUT_PRINTER_HH__
#define __ACP__INTERFACE_COUT_PRINTER_HH__

#include "printer.hh"
#include <ostream>

namespace acp {

/**
 * \class CoutPrinter
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
	 * \see Printer::print(const std::string& msg)
	 */
	inline void print(const std::string& msg) const override{
		std::cout << msg;
	}

	/**
	 * \function print[c-string]
	 * \see Printer::print(const char* msg)
	 */
	inline void print(const char* msg) const override{
		std::cout << msg;
	}

	/**
	 * \function print[char]
	 * \see Printer::print(const digit msg)
	 */
	inline void print(const char digit) const override{
		std::cout << digit;
	}
};

}

#endif // __ACP__INTERFACE_COUT_PRINTER_HH__
