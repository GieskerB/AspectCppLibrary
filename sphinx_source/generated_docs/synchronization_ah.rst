``Synchronization``
============================
..
	(Aspect)

:doc:`Click here to see the source code <synchronization_ah_src>`

**Brief Description:** This aspect implements a thread execution for selected functions.

**Detailed Description:**

    By using an aspect which implements the thread controller interface, an thread exclusive execution
    per function is guaranteed. With the use of a mutex (at least for the two default thread controllers)
    any thread will wait until the previous one finished executing the function.
    There will be no performance loss, if the thread interface is not implemented, but this aspect sill used.

*In file* ``src/functionality/synchronization.ah``

.. _synchronization_ah_threadsafe_execution:

``threadsafe_execution`` (Aspect)
---------------------------------

**Brief Description:** This advice wraps the intended function execution in a mutex lock.


.. _synchronization_ah_acpignore_synchronized:

``acp::ignore_synchronized`` (Attribute)
----------------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.


.. _synchronization_ah_acpsynchronized:

``acp::synchronized`` (Attribute)
---------------------------------

**Brief Description:** Triggers an synchronized call to every marked join point.


.. _synchronization_ah_ignore:

``ignore`` (Pointcut)
---------------------


*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _synchronization_ah_where:

``where`` (Pointcut)
--------------------


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

