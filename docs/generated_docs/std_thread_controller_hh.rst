``StdThreadController`` (Class)
===============================

**Brief Description:** Standard thread controller using std::mutex.

**Detailed Description:**

    This class implements the ThreadController interface using std::mutex for thread safety.
    It provides methods to acquire and release locks, and to get the unique identifier of the current thread.

*In file* ``src/util/std_thread_controller.hh``

.. _std_thread_controller_hh_acquire_lock:

``acquire_lock`` (Function)
---------------------------

*See:* :ref:`ThreadController::acquire_lock <thread_controller_hh_acquire_lock>`

.. _std_thread_controller_hh_get_id:

``get_id`` (Function)
---------------------

*See:* :ref:`ThreadController::get_id <thread_controller_hh_get_id>`

.. _std_thread_controller_hh_release_lock:

``release_lock`` (Function)
---------------------------

*See:* :ref:`ThreadController::release_lock <thread_controller_hh_release_lock>`

