#ifndef __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__
#define __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__

#include <string>

namespace acp {

    /**
     * \interface LoggingMsgBuilder
     * \file src/util/logging_msg_builder.hh
     * \brief This interface defines the methods for building log messages.
     *
     * It is used by the logging aspects to create log messages before and after function execution.
     */
    class LoggingMsgBuilder {
    public:

        LoggingMsgBuilder() {};
        virtual ~LoggingMsgBuilder() = default;

        /**
         * \function build_msg
         * \brief A function to build a general log message.
         *
         * @param log_type The type of log message (e.g., "INFO", "ERROR", etc.).
         * @param msg The message to log.
         * @param output The output string where the built message will be stored.
         */
        virtual void build_msg(const std::string& log_type, const std::string& msg, std::string& output) const = 0;

        /**
         * \function build_before_msg
         * \brief A function to build a log message specifically for the BeforeLoggingAspect.
         *
         * @param signature The signature of the function being logged.
         * @param output The output string where the built message will be stored.
         */
        virtual void build_before_msg(const char* signature, std::string& output) const = 0;

        /**
         * \function build_after_msg
         * \brief A function to build a log message specifically for the AfterLoggingAspect.
         *
         * @param signature The signature of the function being logged.
         * @param output The output string where the built message will be stored.
         */
        virtual void build_after_msg(const char* signature, std::string& output) const = 0;

    };
}

#endif // __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__
