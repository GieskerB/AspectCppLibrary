#ifndef __ACP__INTERFACE_P_THREAD_CONTROLLER_HH__
#define __ACP__INTERFACE_P_THREAD_CONTROLLER_HH__

#include <pthread.h>
#include <stdexcept>
#include "thread_controller.hh"

namespace acp {

    class PThreadController: public ThreadController {

        mutable pthread_mutex_t _mutex;

    public:

        PThreadController() {
            if (pthread_mutex_init(&_mutex, nullptr) != 0) {
                throw std::runtime_error("Failed to initialize pthread mutex");
            }
        }

        ~PThreadController() override {
            pthread_mutex_destroy(&_mutex);
        }

        inline void acquire_lock()  override {
            pthread_mutex_lock(&_mutex);
        }

        inline void release_lock()  override {
            pthread_mutex_unlock(&_mutex);
        }

        int get_id() const override  {
            // Convert pthread_t to int safely (platform-specific)
            auto id = pthread_self();
            return static_cast<int>(reinterpret_cast<uintptr_t>(id));
        }

    };
}

#endif // __ACP__INTERFACE_P_THREAD_CONTROLLER_HH__
