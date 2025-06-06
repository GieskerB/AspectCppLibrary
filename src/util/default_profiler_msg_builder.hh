#ifndef __ACP__INTERFACE_DEAULT_PROFILER_MSG_BUILDER_HH__
#define __ACP__INTERFACE_DEAULT_PROFILER_MSG_BUILDER_HH__
#include "profiler_msg_builder.hh"

namespace acp {

    /**
     * \class DefaultProfilerMsgBuilder
     * \file src/util/default_profiler_msg_builder.hh
     * \brief Default implementation of the ProfilerMsgBuilder interface.
     *
     * This class implements the ProfilerMsgBuilder interface to provide
     * a default way of building profiling messages.
     */
    class DefaultProfilerMsgBuilder : public ProfilerMsgBuilder {
    public:

        DefaultProfilerMsgBuilder(){};
        virtual ~DefaultProfilerMsgBuilder() = default;

        /**
         * \advice build_msg
         * \see :ref:`ProfilerMsgBuilder::build_msg <profiler_msg_builder_hh_build_msg>`
         */
        virtual void build_msg(const acp::ProfilerData& data, std::string& output) const override {
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
