#ifndef __ACP__INTERFACE__DEFAULT_LOGGING_MSG_BUILDER_HH__
#define __ACP__INTERFACE__DEFAULT_LOGGING_MSG_BUILDER_HH__

#include "logging_msg_builder.hh"

namespace acp {

    /**
     * \class DefaultLoggingMsgBuilder
     * \file src/util/default_logging_msg_builder.hh
     * \brief This class is a default implementation of the `LoggingMsgBuilder` interface.
     *
     * It provides a simple way to build log messages with a specific format.
     *
     */
    class DefaultLoggingMsgBuilder : public LoggingMsgBuilder {
    public:
        DefaultLoggingMsgBuilder() {};
        virtual ~DefaultLoggingMsgBuilder() = default;

        /**
         * \function build_msg
         * \see :ref:`LoggingMsgBuilder::build_msg <logging_msg_builder_hh_build_msg>`
         */
        virtual void build_msg(const std::string& log_type, const std::string& msg, std::string& output) const {
                output.clear();
            if (log_type.empty()) {
                output.append(msg);
            } else if (msg.empty()) {
                output.append("[");
                output.append(log_type);
                output.append("]");
            } else {
                output.append("[");
                output.append(log_type);
                output.append("] ");
                output.append(msg);
            }
        }

        /**
         * \function build_before_msg
         * \see :ref:`LoggingMsgBuilder::build_before_msg <logging_msg_builder_hh_build_before_msg>`
         */
        virtual void build_before_msg(const char* signature, std::string& output) const {
            output.clear();
            output.append("[Entering]");
            output.append(signature);
        }

        /**
         * \function build_after_msg
         * \see :ref:`LoggingMsgBuilder::build_after_msg <logging_msg_builder_hh_build_after_msg>`
         */
        virtual void build_after_msg(const char* signature, std::string& output) const {
            output.clear();
            output.append("[Leaving]");
            output.append(signature);
        }
    };

} // namespace acp

#endif // __ACP__INTERFACE__DEFAULT_LOGGING_MSG_BUILDER_HH__
