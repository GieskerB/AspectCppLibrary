#ifndef __ACP__TRACER_DATA_HH__
#define __ACP__TRACER_DATA_HH__
#include <chrono>

namespace acp {

    /**
     * \class TracerData
     * \file src/understanding/tracer_data.hh
     * \brief This class is used to store tracing data for functions.
     *
     * It keeps track of the number of calls and the total execution time.
     * By using a linked list, it allows for easy accumulation of tracing
     * data across multiple function calls.
     *
     */
    class TracerData {

        inline static auto static_start_time() {
           static auto m_start_time = std::chrono::high_resolution_clock::now();
           return m_start_time;
        }

    public:
        TracerData* p_next;
        std::chrono::nanoseconds m_timestamp;
        const char* m_signature;

        static TracerData* &first () {
             static TracerData *data = nullptr;
             return data;
        }

        TracerData (const char* n) : m_signature{n}{
            TracerData *head = first ();
            first () = this;
            m_timestamp = std::chrono::high_resolution_clock::now() - static_start_time();
            p_next = head;
        }

        ~TracerData() {
            if(p_next) {
                delete p_next;
                p_next = nullptr;
            }
        }
    };

}

#endif // __ACP__TRACER_DATA_HH__
