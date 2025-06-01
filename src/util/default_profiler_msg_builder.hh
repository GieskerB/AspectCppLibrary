#ifndef __ACP__INTERFACE_DEAULT_PROFILER_MSG_BUILDER_HH__
#define __ACP__INTERFACE_DEAULT_PROFILER_MSG_BUILDER_HH__
#include "profiler_msg_builder.hh"

namespace acp {

    class DefaultProfilerMsgBuilder : public ProfilerMsgBuilder {
    public:

        DefaultProfilerMsgBuilder(){};
        virtual ~DefaultProfilerMsgBuilder() = default;

        /**
         * \function build
         * \brief Builds a profiling message.
         *
         * \param data
         * \param output reference to a string which will contain the output in the end.
         */
        virtual void build(const acp::ProfilerData& data, std::string& output) const override {
            output.clear();
            output.append(data.m_signature);
            output.append(": called ");
            output.append(std::to_string(data.m_calls));
            output.append(" times within ");
            output.append(std::to_string(data.m_exec_time.count()));
            output.append(" nanoseconds.\n");
        }
    };

}

#endif // __ACP__INTERFACE_DEAULT_PROFILER_MSG_BUILDER_HH__
