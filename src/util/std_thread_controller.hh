#ifndef __ACP__INTERFACE_STD_THREAD_CONTROLLER_HH__
#define __ACP__INTERFACE_STD_THREAD_CONTROLLER_HH__

#include <mutex>
#include <thread>
#include "thread_controller.hh"

namespace acp {

    /**
     * \class StdThreadController
     * \file src/util/std_thread_controller.hh
     * \brief Standard thread controller using std::mutex.
     *
     * This class implements the ThreadController interface using std::mutex for thread safety.
     * It provides methods to acquire and release locks, and to get the unique identifier of the current thread.
     */
    class StdThreadController: public ThreadController {

        mutable std::mutex _mutex;

        public:

        StdThreadController() {}
        virtual ~StdThreadController() = default;

        /**
	    * \function acquire_lock
 	    * \see :ref:`ThreadController::acquire_lock <thread_controller_hh_acquire_lock>`
	    */
        virtual inline void acquire_lock()  override {
            _mutex.lock();
        }

        /**
	    * \function release_lock
 	    * \see :ref:`ThreadController::release_lock <thread_controller_hh_release_lock>`
	    */
        virtual inline void release_lock() override {
            _mutex.unlock();
        }

        /**
	    * \function get_id
 	    * \see :ref:`ThreadController::get_id <thread_controller_hh_get_id>`
	    */
        int get_id() const override {
            std::hash<std::thread::id> hasher;
            return static_cast<int>(hasher(std::this_thread::get_id()));
        }
    };

}
#endif // __ACP__INTERFACE_STD_THREAD_CONTROLLER_HH__
