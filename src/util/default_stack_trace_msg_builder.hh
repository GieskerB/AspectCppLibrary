#ifndef __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
#define __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>

#include "stack_trace_msg_builder.hh"

namespace acp {

class DefaultStackTraceMsgBuilder : public StackTraceMsgBuilder {
    // std::string generate_string(const char* sig, int sig_len, const char* file,
    //                             int file_len, unsigned int line,
    //                             int line_len) const {
    //     const std::string line_str = std::to_string(line);
    //     const int total_len = sig_len + 3 + file_len + 3 + line_len;
    //     std::string result(total_len + 1, '\0');
    //     int pos = 0;

    //     for (int i = 0; i < sig_len; ++i) {
    //         result.at(pos++) = sig[i];
    //     }

    //     result.at(pos++) = ' ';
    //     result.at(pos++) = '|';
    //     result.at(pos++) = ' ';

    //     for (int i = 0; i < file_len; ++i) {
    //         result.at(pos++) = file[i];
    //     }

    //     result.at(pos++) = ' ';
    //     result.at(pos++) = '|';
    //     result.at(pos++) = ' ';

    //     for (int i = 0; i < line_len; ++i) {
    //         result.at(pos++) = line_str[i];
    //     }

    //     return result;
    // }

    // int decimal_length(unsigned int v) const {
    //     if (v < 10) return 1;
    //     if (v < 100) return 2;
    //     if (v < 1000) return 3;
    //     if (v < 10000) return 4;
    //     if (v < 100000) return 5;
    //     if (v < 1000000) return 6;
    //     if (v < 10000000) return 7;
    //     if (v < 100000000) return 8;
    //     if (v < 1000000000) return 9;
    //     return 10;
    // }

   public:
    DefaultStackTraceMsgBuilder() = default;
    virtual ~DefaultStackTraceMsgBuilder() {}

    virtual std::string build_msg(const char* signature, const char* file,
                                  int line) const override {
        // return generate_string(signature, std::strlen(signature), file,
        //                        std::strlen(file), line, decimal_length(line));

        // std::stringstream ss;
        // ss << signature << " | " << file << " | " << line<< '\n';
        // return ss.str();


		const char* sig = "int main(int, char**)";
		const char* fil = "src/main.cc";
		const char* lin = "42";

	    // std::cout << signature<< '\n';

		std::string res {"aösdfjlasdjfö"};

	    // res += const_cast<char *>(signature);
	    // res += const_cast<char *>(file);

		char buf[256] = {0};
		strncpy(buf, signature, 255);
		res += buf;

	    // std::cout <<"DSMB: "<< (buf[0] == 'i') << '\n';

	    // res += lin;

		return res;
	}

};

}  // namespace acp

#endif  // __ACP__INTERFACE_DEFAULT_STACK_TRACE_MSG_BUILDER_HH__
