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
 * \brief DefaultStackTraceMsgBuilder is the default implementation of the StackTraceMsgBuilder interface.
 *
 * This class provides a method to build a formatted message for the stack trace.
 *
 */
class DefaultStackTraceMsgBuilder : public StackTraceMsgBuilder {

	constexpr static unsigned int BUFF_SIZE = 1024;

    int decimal_length(unsigned int v) const {
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

    virtual std::string build_msg(const char* signature, const char* file,
                                  int line) const override {

#if 0 // TODO: TOGGLE this to switch between buggy implementation and the correct one
        std::stringstream ss;
        ss << signature << " | " << file << " | " << line<< '\n';
        return ss.str();
# else
		char buf[BUFF_SIZE] = {0};

		const int sig_len = std::strlen(signature);
		const int file_len = std::strlen(file);
		const int line_len = decimal_length(line);
		const int total_len = 3 + sig_len + 5 + file_len + 1 + line_len + 2;

		if (total_len >= BUFF_SIZE) {
			return "Error: Buffer size is too small for the message.\n";
		}

		int remaining = BUFF_SIZE - 1; // Reserve space for null terminator
		char line_str[11] = {0};
		snprintf(line_str, decimal_length(line)+1, "%d", line);

		strncat(buf, "at ", remaining); remaining -= 3;
		strncat(buf, signature, remaining); remaining -= sig_len;
		strncat(buf, " in (", remaining); remaining -= 5;
		strncat(buf, file, remaining); remaining -= file_len;
		strncat(buf, ":", remaining); remaining -= 1;
		strncat(buf, line_str, remaining); remaining -= line_len;
		strncat(buf, ")\n", remaining);

		return buf;
#endif
	}

};

}  // namespace acp

#endif  // __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
