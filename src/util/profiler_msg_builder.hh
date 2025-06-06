#ifndef __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__
#define __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__

#include <string>

namespace acp {

    /**
     * \interface ProfilerMsgBuilder
     * \file src/util/profiler_msg_builder.hh
     * \brief Interface for building profiling messages.
     */
    class ProfilerMsgBuilder {
    public:

        ProfilerMsgBuilder(){};
        virtual ~ProfilerMsgBuilder() = default;

        /**
         * \function build_msg
         * \brief Builds a profiling message.
         *
         * \param data the profiling data to be used for building the message.
         * \param output reference to a string which will contain the output in the end.
         */
        virtual void build_msg(const acp::ProfilerData& data, std::string& output) const = 0;
    };

}

#endif // __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__
