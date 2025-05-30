#ifndef __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
#define __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>

#include "stack_trace_msg_builder.hh"

namespace acp {

/**
 * \class DefaultStackTraceMsgBuilder
 * \file src/util/default_stack_trace_msg_builder.hh
 * \brief DefaultStackTraceMsgBuilder is the default implementation of the StackTraceMsgBuilder interface.
 *
 * This class provides a method to build a formatted message for the stack trace.
 *
 */
class DefaultStackTraceMsgBuilder : public StackTraceMsgBuilder {

    inline int decimal_length(unsigned int v) const {
        if (v < 10) return 1;
        if (v < 100) return 2;
        if (v < 1000) return 3;
        if (v < 10000) return 4;
        if (v < 100000) return 5;
        if (v < 1000000) return 6;
        if (v < 10000000) return 7;
        if (v < 100000000) return 8;
        if (v < 1000000000) return 9;
        return 10;
    }

public:

    DefaultStackTraceMsgBuilder() = default;
    virtual ~DefaultStackTraceMsgBuilder() {}

	/**
	 * \advice build_msg
	 * \see :ref:`StackTraceMsgBuilder::build_msg <stack_trace_msg_builder_hh_build_msg>`
	 */
    virtual void build_msg(const char* signature, const char* file,
                                  int line, std::string& result) const override {
		char line_str[12] = {0};
		snprintf(line_str, decimal_length(line)+1, "%d", line);

		result.clear();
		result += "at ";
		result += signature;
		result += " in (";
		result += file;
		result += ":";
		result += line_str;
		result += ")\n";
	}

};

}  // namespace acp

#endif  // __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
