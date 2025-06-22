#ifndef __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__
#define __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__

#include <string>

namespace acp {

    /**
     * \interface LoggingMsgBuilder
     * \file src/functionality/logging_msg_builder.hh
     * \brief This interface defines the methods for building log messages.
     *
     * It is used by the logging aspects to create log messages before and after function execution.
     */
    namespace logging_msg_builder {

        /**
         * \function build_msg
         * \brief A function to build a general log message.
         *
         * \param log_type The type of log message (e.g., "INFO", "ERROR", etc.).
         * \param msg The message to log.
         * \param output The output string where the built message will be stored.
         */
        inline void build_msg(const std::string& log_type, const std::string& msg, std::string& output) {
            #warning "build_msg is not implemented in LoggingMsgBuilder interface. Please implement with the use of an aspect"
        };

        /**
         * \function build_before_msg
         * \brief A function to build a log message specifically for the BeforeLoggingAspect.
         *
         * \param signature The signature of the function being logged.
         * \param output The output string where the built message will be stored.
         */
        inline void build_before_msg(const char* signature, std::string& output) {
            #warning "build_before_msg is not implemented in LoggingMsgBuilder interface. Please implement with the use of an aspect"
        }

        /**
         * \function build_after_msg
         * \brief A function to build a log message specifically for the AfterLoggingAspect.
         *
         * \param signature The signature of the function being logged.
         * \param output The output string where the built message will be stored.
         */
        inline void build_after_msg(const char* signature, std::string& output) {
            #warning "build_after_msg is not implemented in LoggingMsgBuilder interface. Please implement with the use of an aspect"
        }

    };
}

#endif // __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__
