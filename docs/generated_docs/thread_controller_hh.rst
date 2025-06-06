``ThreadController`` (Interface)
================================

**Brief Description:** Interface for thread control mechanisms.

**Detailed Description:**

    This interface defines the basic operations for thread control. Aspects can
    use this interface to manage ensure thread safety and synchronization.

*In file* ``src/util/thread_controller.hh``

.. _thread_controller_hh_acquire_lock:

``acquire_lock`` (Function)
---------------------------

**Brief Description:** Acquire a lock for thread safety.

**Detailed Description:**

    This method should be called before accessing shared resources to ensure
    that no other thread can modify them concurrently.


.. _thread_controller_hh_get_id:

``get_id`` (Function)
---------------------

**Brief Description:** Get the unique identifier for the current thread.

**Detailed Description:**

    This method returns a unique identifier for the current thread, which can
    be used for logging or debugging purposes.


.. _thread_controller_hh_release_lock:

``release_lock`` (Function)
---------------------------

**Brief Description:** Release the lock acquired by acquire_lock.

**Detailed Description:**

    This method should be called after finishing access to shared resources
    to allow other threads to acquire the lock.


