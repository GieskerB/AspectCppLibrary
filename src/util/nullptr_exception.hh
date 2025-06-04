#ifndef __ACP__INTERFACE_NULLPTR_EXCEPTION_HH__
#define __ACP__INTERFACE_NULLPTR_EXCEPTION_HH__

#include <stdexcept>
namespace acp {
    /**
     * \exception NullptrException
     * \brief Exception class for handling null pointer dereference errors.
     * \file /src/util/nullptr_exception.hh
     *
     * This class inherits from `std::runtime_error` and is used to indicate that a null pointer was dereferenced.
     */
    class NullptrException : public std::runtime_error {

        std::string _msg;

        void create_message(const char* sig, unsigned int line) {
            _msg = "Null pointer dereference in function: ";
            _msg += sig;
            _msg += " at line: ";
            _msg += std::to_string(line);
            _msg += ".";
		}

    public:
        /**
         * \constructor Constructor
         * \brief Construct a new NullptrException object with a message indicating location of the error.
         * \param sig is a c-string that indicates the signature of the function where the error occurred.
         * \param line is the line number where the error occurred.
         */
        NullptrException(const char* sig, unsigned int line):std::runtime_error("Null pointer dereference"), _msg("") {
            create_message(sig, line);
        }

        /**
         * \function what
         * \brief Overridden std::runtime_error::what() function to return the error message.
         */
        const char* what() const noexcept override {
            return _msg.c_str();
        }
    };

}
#endif // __ACP__INTERFACE_NULLPTR_EXCEPTION_HH__
