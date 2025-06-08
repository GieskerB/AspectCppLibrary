#ifndef __CUSTOM_TO_STRING_HH__
#define __CUSTOM_TO_STRING_HH__

#include <cstdio>

namespace acp {

    inline void to_string(char* output, int value, size_t size) {
        // There is currently a but within the AspectC++ weaver: When retuning a string in a function on
        // which a after advice is applied, the AspectC++ weaver will not correctly handle the return value.
        // The beginning of the string is not correctly set, which leads to a unreadable characters in the stirng.
        // This is a workaround to avoid the issue. A user of this library could define a after advice action upon
        // std::to_string, which would then cause errors throughout this library.
        std::snprintf(output ,size, "%d", value);
    }

}

#endif // __CUSTOM_TO_STRING_HH__
