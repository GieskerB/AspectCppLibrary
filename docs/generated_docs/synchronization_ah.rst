``Synchronization``
============================
..
	(Aspect)

**Brief Description:** This aspect implements a thread execution for selected functions.

**Detailed Description:**

    By using an aspect which implements the thread controller interface, an thread exclusive execution
    per function is guaranteed. With the use of a mutex any thread will wait until the previous one
    finished executing the function.
    There will be no performance loss, if the thread interface is not implemented, but this aspect sill used.

*In file* ``src/functionality/synchronization.ah``

.. _synchronization_ah_threadsafe_execution:

``threadsafe_execution`` (Aspect)
---------------------------------

**Brief Description:** Wrapping the intended function execution in a mutex lock.


.. _synchronization_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _synchronization_ah_synchronized:

``synchronized`` (Attribute)
----------------------------

**Brief Description:** Any function with this attribute can only have one thread at a time executing it


.. _synchronization_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

