#ifndef __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
#define __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__

#include "stack_trace_msg_builder.hh"

namespace acp {

class DefaultStackTraceMsgBuilder : public StackTraceMsgBuilder {

public:

	DefaultStackTraceMsgBuilder() = default;
	virtual ~DefaultStackTraceMsgBuilder() {}

	virtual std::string build_msg(const char* sign, const char* file, int line) const override{
		std::string err_msg { };
		err_msg += "at ";
		err_msg += sign; // implicit conversion to std::string
		err_msg += " in (";
		err_msg += file; // implicit conversion to std::string
		err_msg += ':';
		err_msg += std::to_string(line);
		err_msg += ")\n";
		return err_msg;
	}

};

}

#endif // __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
