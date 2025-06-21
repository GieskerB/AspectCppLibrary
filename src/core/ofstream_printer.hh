#ifndef __ACP__INTERFACE_OFSTREAM_PRINTER_HH__
#define __ACP__INTERFACE_OFSTREAM_PRINTER_HH__

#include "printer.hh"
#include <ofstream>

namespace acp {

/**
 * \class OfstreamPrinter
 * \file src/util/ofstream_printer.hh
 * \brief OfstreamPrinter is a Printer implementation that prints messages to a std::ofstream.
 *
 * This class implements the Printer interface and provides methods to print messages
 * to a specified output file stream (std::ofstream).
 */
class OfstreamPrinter: public Printer {

	std::ofstream _os;

public:

	/**
	 * \constructor Constructor
	 * \brief Construct a new OfstreamPrinter object and open the output file stream.
	 *
	 * \param filename is the name of the file to which messages will be printed.
	 * \throws std::runtime_error if the file cannot be opened.
	 */
	OfstreamPrinter(std::string filename) : _os(filename, std::ios::out | std::ios::app) {
		if (!_os.is_open()) {
			throw std::runtime_error("Failed to open output file");
		}
	};

	/**
	 * \destructor Destructor
	 * \brief Destroy the Ofstream Printer object and close the output file stream.
	 */
	virtual ~OfstreamPrinter() {
		if (_os.is_open()) {
			_os.close();
		}
	}

	/**
	 * \function print[std::string]
 	 * \see :ref:`Printer::print <printer_hh_printstdstring>`
	 */
	inline void print(const std::string& msg) const override{
		std::ostream << msg;
	}

	/**
	 * \function print[c-string]
 	 * \see :ref:`Printer::print <printer_hh_printc-string>`
	 */
	inline void print(const char* msg) const override{
		std::ostream << msg;
	}

	/**
	 * \function print[char]
 	 * \see :ref:`Printer::print <printer_hh_printchar>`
	 */
	inline void print(const char digit) const override{
		std::ostream << digit;
	}
};

}

#endif // __ACP__INTERFACE_OFSTREAM_PRINTER_HH__
