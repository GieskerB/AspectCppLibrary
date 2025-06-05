#ifndef __ACP__INTERFACE_THREAD_CONTROLLER_HH__
#define __ACP__INTERFACE_THREAD_CONTROLLER_HH__

namespace acp {

    class ThreadController {
    public:
        ThreadController() {};
        virtual ~ThreadController() = default;

        virtual inline void acquire_lock() = 0;

        virtual inline void release_lock() = 0;

        virtual int get_id() const = 0;

    };
}

#endif // __ACP__INTERFACE_THREAD_CONTROLLER_HH__
