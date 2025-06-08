#ifndef __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
#define __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>

#include "stack_trace_msg_builder.hh"
#include "custom_to_string.hh"

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
    public:

        DefaultStackTraceMsgBuilder() = default;
        virtual ~DefaultStackTraceMsgBuilder() {}

        /**
         * \advice build_msg
         * \see :ref:`StackTraceMsgBuilder::build_msg <stack_trace_msg_builder_hh_build_msg>`
         */
        virtual void build_msg(const char* signature, const char* file,
                                    int line, std::string& result) const override {
            char buffer[12];
            acp::to_string(buffer, line, sizeof(buffer));
            result.clear();
            result.append("at ");
            result.append(signature);
            result.append(" in (");
            result.append(file);
            result.append(":");
            result.append(buffer);
            result.append(")\n");
        }

    };

}  // namespace acp

#endif  // __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
