#ifndef __ACP__INTERFACE_PRINTER_HH__
#define __ACP__INTERFACE_PRINTER_HH__

#include <string>

namespace acp {

/**
 * \interface Printer
 * \brief Printer is an interface for printing messages.
 *
 * This interface defines methods for printing messages of different types.
 *
 */
class Printer {

public:

	Printer() = default;
	virtual ~Printer() {};

	/**
	 * \function print[std::string]
	 * \brief print is a pure virtual function that prints a std::string message.
	 *
	 * \param msg is the message to be printed
	 */
	virtual void print(const std::string& msg) const = 0;

	/**
	 * \function print[c-string]
	 * \brief print is a pure virtual function that prints a c-string message.
	 *
	 * \param msg is the message to be printed
	 */
	virtual void print(const char* msg) const = 0;

	/**
	 * \function print[char]
	 * \brief print is a pure virtual function that prints a single char message.
	 *
	 * \param digit is the digit to be printed
	 */
	virtual void print(const char digit) const = 0;

};

}

#endif // __ACP__INTERFACE_PRINTER_HH__
