#ifndef __ACP__INTERFACE_STACK_TRACE_MSG_BUILDER_HH__
#define __ACP__INTERFACE_STACK_TRACE_MSG_BUILDER_HH__

#include <string>

namespace acp {

/**
 * \interface StackTraceMsgBuilder
 * \file src/util/stack_trace_msg_builder.hh
 * \brief StackTraceMsgBuilder is an interface for creating a stack trace messages.
 *
 * This interface defines the method for creating a messages for the StackTrace-Aspect.
 *
 */
class StackTraceMsgBuilder {

public:

	StackTraceMsgBuilder() = default;
	virtual ~StackTraceMsgBuilder() {}

	/**
	 * \function build_msg
	 * \brief build_msg is a pure virtual function that builds a message for the stack trace.
	 *
	 * \param sign is the signature of the function that was called.
	 * \param file is the name of the file where the function was called.
	 * \param line is the line number where the function was called.
	 * \param result is a reference to a string where the formatted message will be stored.
	 */
	virtual void build_msg(const char* sign, const char* file, int line, std::string& result) const = 0;

};

}

#endif // __ACP__INTERFACE_STACK_TRACE_MSG_BUILDER_HH__
