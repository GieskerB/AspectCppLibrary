#ifndef __ACP__INTERFACE_OFSTREAM_PRINTER_HH__
#define __ACP__INTERFACE_OFSTREAM_PRINTER_HH__

#include "printer.hh"
#include <ofstream>

namespace acp {

class OfstreamPrinter: public Printer {

	std::ofstream _os;

public:

	OfstreamPrinter(std::string filename) : _os(filename, std::ios::out | std::ios::app) {
		if (!_os.is_open()) {
			throw std::runtime_error("Failed to open output file");
		}
	};
	virtual ~OfstreamPrinter() {
		if (_os.is_open()) {
			_os.close();
		}
	}

	inline void print(const std::string& msg) const override{
		std::ofstream << msg;
	}

	inline void print(const char* msg) const override{
		std::ofstream << msg;
	}

	inline void print(const char msg) const override{
		std::ofstream << msg;
	}

};

}

#endif // __ACP__INTERFACE_OFSTREAM_PRINTER_HH__
