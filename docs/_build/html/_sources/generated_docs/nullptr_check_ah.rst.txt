``NullptrCheck`` (Aspect)
=========================

**Brief Description:** Aspect that checks for null pointer dereferences.

**Detailed Description:**

    This aspect provides an advice to check if a pointer is null before dereferencing it.
    Unfortunately, it does not work with the -> operator, due to limitations in the AspectC++
    language and the way the builtin -> operator is defined.

*In file* ``/src/bug_detection/nullptr_check.ah``

.. _nullptr_check_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _nullptr_check_ah_nullptr_check:

``nullptr_check`` (Advice)
--------------------------

**Brief Description:** Advice checks if a pointer is null before dereferencing it.

**Detailed Description:**

    If the pointer is null, it throws a `acp::NullptrException` with a message indicating that
    a null pointer was dereferenced.


.. _nullptr_check_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

