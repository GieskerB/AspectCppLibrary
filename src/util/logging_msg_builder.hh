#ifndef __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__
#define __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__

#include <string>

namespace acp {

    class LoggingMsgBuilder {
    public:

        LoggingMsgBuilder() {};
        virtual ~LoggingMsgBuilder() = default;

        virtual void build_msg(const std::string& log_type, const std::string& msg, std::string& output) const = 0;

        virtual void build_before_msg(const char* signature, std::string& output) const = 0;

        virtual void build_after_msg(const char* signature, std::string& output) const = 0;

    };
}

#endif // __ACP__INTERFACE__LOGGING_MSG_BUILDER_HH__
