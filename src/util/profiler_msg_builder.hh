#ifndef __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__
#define __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__

#include <string>

namespace acp {

    class ProfilerMsgBuilder {
    public:

        ProfilerMsgBuilder(){};
        virtual ~ProfilerMsgBuilder() = default;
        
        /**
         * \function build
         * \brief Builds a profiling message.
         *
         * \param data ...
         * \param output reference to a string which will contain the output in the end.
         */
        virtual void build(const acp::ProfilerData& data, std::string& output) const = 0;
    };

}

#endif // __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__
