#ifndef __ACP__INTERFACE_PRINTER_HH__
#define __ACP__INTERFACE_PRINTER_HH__

#include <string>

namespace acp {

class Printer {

public:

	Printer() = default;
	virtual ~Printer() {};

	virtual void print(const std::string& msg) const = 0;
	virtual void print(const char* msg) const = 0;
	virtual void print(const char digit) const = 0;

};

}

#endif // __ACP__INTERFACE_PRINTER_HH__
