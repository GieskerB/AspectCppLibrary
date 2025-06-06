#ifndef __ACP__INTERFACE_P_THREAD_CONTROLLER_HH__
#define __ACP__INTERFACE_P_THREAD_CONTROLLER_HH__

#include <pthread.h>
#include <stdexcept>
#include "thread_controller.hh"

namespace acp {

    /**
     * \class PThreadController
     * \file src/util/p_thread_controller.hh
     * \brief Thread controller using pthreads for synchronization.
     *
     * This class implements the ThreadController interface using pthread mutexes for thread safety.
     * It provides methods to acquire and release locks, and to get the unique identifier of the current thread.
     */
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
        /**
	    * \function acquire_lock
 	    * \see :ref:`ThreadController::acquire_lock <thread_controller_hh_acquire_lock>`
	    */
        inline void acquire_lock() override {
            pthread_mutex_lock(&_mutex);
        }

        /**
	    * \function release_lock
 	    * \see :ref:`ThreadController::release_lock <thread_controller_hh_release_lock>`
	    */
        inline void release_lock() override {
            pthread_mutex_unlock(&_mutex);
        }

        /**
	    * \function get_id
 	    * \see :ref:`ThreadController::get_id <thread_controller_hh_get_id>`
	    */
        int get_id() const override  {
            // Convert pthread_t to int safely (platform-specific)
            auto id = pthread_self();
            return static_cast<int>(reinterpret_cast<uintptr_t>(id));
        }

    };
}

#endif // __ACP__INTERFACE_P_THREAD_CONTROLLER_HH__
