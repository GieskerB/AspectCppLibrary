#ifndef __ACP__INTERFACE_THREAD_CONTROLLER_HH__
#define __ACP__INTERFACE_THREAD_CONTROLLER_HH__

namespace acp {

    /**
     * \interface ThreadController
     * \file src/util/thread_controller.hh
     * \brief Interface for thread control mechanisms.
     *
     * This interface defines the basic operations for thread control. Aspects can
     * use this interface to manage ensure thread safety and synchronization.
     *
     */
    class ThreadController {
    public:
        ThreadController() {};
        virtual ~ThreadController() = default;

        /**
         * \function acquire_lock
         * \brief Acquire a lock for thread safety.
         *
         * This method should be called before accessing shared resources to ensure
         * that no other thread can modify them concurrently.
         */
        virtual inline void acquire_lock() = 0;

        /**
         * \function release_lock
         * \brief Release the lock acquired by acquire_lock.
         *
         * This method should be called after finishing access to shared resources
         * to allow other threads to acquire the lock.
         */
        virtual inline void release_lock() = 0;

        /**
         * \function get_id
         * \brief Get the unique identifier for the current thread.
         *
         * This method returns a unique identifier for the current thread, which can
         * be used for logging or debugging purposes.
         *
         * \return An integer representing the thread ID.
         */
        virtual int get_id() const = 0;

    };
}

#endif // __ACP__INTERFACE_THREAD_CONTROLLER_HH__
