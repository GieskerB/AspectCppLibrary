``PredefinedPointcuts``
====================================
..
	(Collection)

**Brief Description:** This file contains predefined pointcuts that can be used in aspects.

**Detailed Description:**

    These pointcuts are designed to match various types of functions in a C++ project.
    Its purpose is to provide a set of commonly used pointcuts that can be reused across
    different aspects. Further increasing the user friendliness of this library in the case
    a user wants to create their own aspects.

*In file* ``src/core/predefined_pointcuts.ah``

.. _predefined_pointcuts_ah_all_func:

``all_func`` (Pointcut)
-----------------------

**Brief Description:** Matches all functions in the whole project.


.. _predefined_pointcuts_ah_free_func:

``free_func`` (Pointcut)
------------------------

**Brief Description:** Matches all free functions in the whole project.

**Detailed Description:**

    Free functions are functions that are not part of a class or namespace.


.. _predefined_pointcuts_ah_getters:

``getters`` (Pointcut)
----------------------

**Brief Description:** Matches all getter functions in the whole project.


.. _predefined_pointcuts_ah_main_func:

``main_func`` (Pointcut)
------------------------

**Brief Description:** Matches every possible argument variant of the c++ main function.


.. _predefined_pointcuts_ah_none:

``none`` (Pointcut)
-------------------

**Brief Description:** Matches no join points.


.. _predefined_pointcuts_ah_returns_const:

``returns_const`` (Pointcut)
----------------------------

**Brief Description:** Matches all functions that return a const value.


.. _predefined_pointcuts_ah_returns_pointer:

``returns_pointer`` (Pointcut)
------------------------------

**Brief Description:** Matches all functions that return a pointer.


.. _predefined_pointcuts_ah_returns_primitive:

``returns_primitive`` (Pointcut)
--------------------------------

**Brief Description:** Matches all functions that return a primitive data type.


.. _predefined_pointcuts_ah_returns_reference:

``returns_reference`` (Pointcut)
--------------------------------

**Brief Description:** Matches all functions that return a reference.


.. _predefined_pointcuts_ah_returns_void:

``returns_void`` (Pointcut)
---------------------------

**Brief Description:** Matches all functions that return void.


.. _predefined_pointcuts_ah_setters:

``setters`` (Pointcut)
----------------------

**Brief Description:** Matches all setter functions in the whole project.


.. _predefined_pointcuts_ah_static_func:

``static_func`` (Pointcut)
--------------------------

**Brief Description:** Matches all static functions in the whole project.


