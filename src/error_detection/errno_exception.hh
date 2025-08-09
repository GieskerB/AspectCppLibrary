#ifndef __ACP__ERRNO_EXCEPTION_HH__
#define __ACP__ERRNO_EXCEPTION_HH__
#include <string>
#include <cerrno>
#include <cstring>
#include <stdexcept>

#include "../core/custom_to_string.hh"

namespace acp {

    /**
     * \exception ErrnoException
     * \brief ErrnoException is an exception that is thrown within the ErrorCodeConverterAspect when
     * a function call sets errno to a non-zero value.
     * \file /src/error_detection/errno_exception.hh
     */
	class ErrnoException : public std::runtime_error {

		std::string _msg;
		const unsigned int _errno;

		void create_message() {
            char buffer[12];
            acp::to_string(buffer, _errno, sizeof(buffer));
            _msg.clear();
			_msg.append("A function call set errno to a non zero value:");
			_msg.append(buffer);
			_msg.append(" which means: <");
			_msg.append(std::runtime_error::what());
			_msg.append(">");
		}

	public:
		ErrnoException() = delete;

        /**
         * \constructor Constructor
         * \brief Construct a new ErrnoException object with the given error number.
         *
         * It will create a message based on the error number using std::strerror.
         *
         * \param err is the error number that was set by a std-lib function.
         */
		ErrnoException(unsigned int err): std::runtime_error(std::strerror(err)), _errno(err) {
			create_message();
		}

        /**
         * \function what
         * \brief Overridden std::runtime_error::what() function to return the error message.
         */
		const char* what() const noexcept override {
			return _msg.c_str();
		}

        /**
         * \function get_errno
         * \brief Returns the error number relevant to this exception.
         */
		unsigned int get_errno() const {
			return _errno;
		}

	};
}

#endif // __ACP__ERRNO_EXCEPTION_HH__
