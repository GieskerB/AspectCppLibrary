#ifndef __ACP__INTERFACE_THREAD_CONTROLLER_HH__
#define __ACP__INTERFACE_THREAD_CONTROLLER_HH__

#include <functional>

namespace acp {

    /**
     * \interface ThreadController
     * \file src/util/thread_controller.hh
     * \brief Interface for thread control mechanisms.
     *
     * This interface provides methods for thread safety, including acquiring and releasing locks,
     * and getting the unique identifier for the current thread.
     *
     * To statically configure the thread controller at runtime, use an aspect that implements this interface.
     * Example being the `acp::std_thread_controller`.
     *
     */
    namespace thread_controller {
        /**
         * \function acquire_lock
         * \brief Acquire a lock for thread safety.
         *
         * This method should be called before accessing shared resources to ensure
         * that no other thread can modify them concurrently.
         */
        inline void acquire_global_lock() {}

        /**
         * \function release_lock
         * \brief Release the lock acquired by acquire_lock.
         *
         * This method should be called after finishing access to shared resources
         * to allow other threads to acquire the lock.
         */
        inline void release_global_lock(){}

        /**
         * \function synchronized_function_call
         * \brief Calls the argument given by the first argument with mutex exclusion.
         *
         * \param func and std::function which should be called.
         */
        inline void synchronized_function_call(const std::function<void()>& func) {
            func();
        }

        /**
         * \function get_id
         * \brief Get the unique identifier for the current thread.
         *
         * This method returns a unique identifier for the current thread, which can
         * be used for logging or debugging purposes.
         *
         * \return An integer representing the thread ID.
         */
        inline int get_id(){return 0;}

    };
}

#endif // __ACP__INTERFACE_THREAD_CONTROLLER_HH__
