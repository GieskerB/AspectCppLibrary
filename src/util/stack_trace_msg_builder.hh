#ifndef __ACP__INTERFACE_STACK_TRACE_MSG_BUILDER_HH__
#define __ACP__INTERFACE_STACK_TRACE_MSG_BUILDER_HH__

#include <string>

namespace acp {

class StackTraceMsgBuilder {

public:

	StackTraceMsgBuilder() = default;
	virtual ~StackTraceMsgBuilder() {}

	virtual std::string build_msg(const char* sign, const char* file, int line) const = 0;

};

}

#endif // __ACP__INTERFACE_STACK_TRACE_MSG_BUILDER_HH__
