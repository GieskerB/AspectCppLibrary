#pragma once
#include <string>

class StackTraceMsgBuilder {

public:

	StackTraceMsgBuilder() = default;
	virtual ~StackTraceMsgBuilder();

	virtual std::string build_msg(const char* sign, const char* file, int line) const;


};

StackTraceMsgBuilder::~StackTraceMsgBuilder() {

}
