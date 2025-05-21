#pragma once
#include "../util/stack_trace_msg_builder.h"

class DefaultStackTraceMsgBuilder : public StackTraceMsgBuilder {

public:

	DefaultStackTraceMsgBuilder() = default;
	virtual ~DefaultStackTraceMsgBuilder();

	virtual std::string build_msg(const char* sign, const char* file, int line) const override;

};

DefaultStackTraceMsgBuilder::~DefaultStackTraceMsgBuilder() {

}

std::string DefaultStackTraceMsgBuilder::build_msg(const char* sign, const char* file, int line) const{
		std::string err_msg { };
		err_msg += "at ";
		err_msg += sign; // implicit conversion to std::string
		err_msg += " in (";
		err_msg += file; // implicit conversion to std::string
		err_msg += ':';
		err_msg += std::to_string(line);
		err_msg += ")\n";
		return err_msg;
}
