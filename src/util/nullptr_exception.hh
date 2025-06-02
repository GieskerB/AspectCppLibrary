#ifndef __ACP__INTERFACE_NULLPTR_EXCEPTION_HH__
#define __ACP__INTERFACE_NULLPTR_EXCEPTION_HH__

#include <stdexcept>
namespace acp {
/**
 * \class NullptrException
 * \brief Exception class for handling null pointer dereference errors.
 *
 * This class inherits from `std::runtime_error` and is used to indicate that a null pointer was dereferenced.
 */
class NullptrException : public std::runtime_error {
public:
    /**
     * \constructor Constructor
     * \brief Construct a new NullptrException object with a message indicating that a null pointer was dereferenced.
     */
    NullptrException() : std::runtime_error("Null pointer dereferenced") {}

    /**
     * \function what
     * \brief Overridden std::runtime_error::what() function to return the error message.
     */
    const char* what() const noexcept override {
        return std::runtime_error::what();
    }
};

}
#endif // __ACP__INTERFACE_NULLPTR_EXCEPTION_HH__
