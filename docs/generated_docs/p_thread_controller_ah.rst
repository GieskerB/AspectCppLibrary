``PThreadController``
==============================
..
	(Aspect)

**Brief Description:** Thread controller using pthreads for synchronization.

**Detailed Description:**

    This class implements the ThreadController interface using pthread mutexes for thread safety.
    It provides methods to acquire and release locks, and to get the unique identifier of the current thread.

*In file* ``src/core/p_thread_controller.hh``

.. _p_thread_controller_ah_acquire_lock:

``acquire_lock`` (Advice)
-------------------------

*See:* :ref:`acp::thread_controller::acquire_lock <thread_controller_hh_acquire_lock>`

.. _p_thread_controller_ah_get_id:

``get_id`` (Advice)
-------------------

*See:* :ref:`acp::thread_controller::get_id <thread_controller_hh_get_id>`

.. _p_thread_controller_ah_release_lock:

``release_lock`` (Advice)
-------------------------

*See:* :ref:`acp::thread_controller::release_lock <thread_controller_hh_release_lock>`

.. _p_thread_controller_ah_synchronized_advice:

``synchronized_advice`` (Advice)
--------------------------------

*See:* :ref:`acp::thread_controller::synchronized_function_call <thread_controller_hh_synchronized_function_call>`

