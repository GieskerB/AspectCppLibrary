#ifndef __ACP__PROFILER_DATA_HH__
#define __ACP__PROFILER_DATA_HH__
#include <chrono>


namespace acp {

class ProfilerData {

public:

    static ProfilerData* &first () { static ProfilerData *data = 0; return data; }
    struct ProfilerData* p_next;
    unsigned int m_calls;
    std::chrono::nanoseconds m_exec_time;
    const char* m_signature;
    ProfilerData (const char* n) : m_calls{0}, m_exec_time{0L}, m_signature{n} {
        ProfilerData *head = first ();
        first () = this;
        p_next = head;
    }
};

}

#endif // __ACP__PROFILER_DATA_HH__
