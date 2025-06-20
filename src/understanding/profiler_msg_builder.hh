#ifndef __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__
#define __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__

#include "profiler_data.hh"

#include <string>

namespace acp {

    /**
     * \interface ProfilerMsgBuilder
     * \file src/understanding/profiler_msg_builder.hh
     * \brief Interface for building profiling messages.
     */
    namespace profiler_msg_builder {
        /**
         * \function build_msg
         * \brief Builds a profiling message.
         *
         * \param data the profiling data to be used for building the message.
         * \param output reference to a string which will contain the output in the end.
         */
        inline void build_msg(const acp::ProfilerData& data, std::string& output){
            #warning "build_msg is not implemented in ProfilerMsgBuilder interface. Please implement with the use of an aspect"
        }
    };

}

#endif // __ACP__INTERFACE_PROFILER_MSG_BUILDER_HH__
