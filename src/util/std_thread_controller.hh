#ifndef __ACP__INTERFACE_STD_THREAD_CONTROLLER_HH__
#define __ACP__INTERFACE_STD_THREAD_CONTROLLER_HH__

#include <mutex>
#include <thread>
#include "thread_controller.hh"

namespace acp {

    class StdThreadController: public ThreadController {

        mutable std::mutex _mutex;

        public:

        StdThreadController() {}
        virtual ~StdThreadController() = default;

        virtual inline void acquire_lock()  override {
            _mutex.lock();
        }

        virtual inline void release_lock() override {
            _mutex.unlock();
        }

        int get_id() const override {
            std::hash<std::thread::id> hasher;
            return static_cast<int>(hasher(std::this_thread::get_id()));
        }
    };

}
#endif // __ACP__INTERFACE_STD_THREAD_CONTROLLER_HH__
