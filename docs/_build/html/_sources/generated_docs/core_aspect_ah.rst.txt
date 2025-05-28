``CoreAspect`` (Aspect)
=======================

**Brief Description:** CoreAspect is the base aspect for all aspects in this ACP library.

**Detailed Description:**

    CoreAspect defines various pointcuts that are used throught this library.
    Some of them are virtual and can be overridden by derived aspects to structure the
    implementation of the aspects. The others are meant to be useful pointcuts for a
    more user oriented usage of the ACP library.


.. _/src/core/core_aspect_ah_``default_where``:

``default_where`` (Pointcut)
----------------------------

**Brief Description:** A virtual placeholder for the default pointcut implementation of each aspect


.. _/src/core/core_aspect_ah_``everywhere``:

``everywhere`` (Pointcut)
-------------------------

**Brief Description:** Matches all functions in the whole project.

**Detailed Description:**

    This pointcut matches all functions. It is ment be used with causion as it
    describes literally every functions and therefore can lead to performance issues.


.. _/src/core/core_aspect_ah_``ignore``:

``ignore`` (Pointcut)
---------------------

**Brief Description:** A virtual placeholder for the pointcut that descibes which join points

**Detailed Description:**

    should be ignored by the aspect.
    It is recommended to use and extend a pointcut definition like with:
    "% <AspectName>::...::%(...)" || "% acp::...::%(...)"


.. _/src/core/core_aspect_ah_``main_func``:

``main_func`` (Pointcut)
------------------------

**Brief Description:** Matches every possible agrument variant of the c++ main function.


.. _/src/core/core_aspect_ah_``operators``:

``operators`` (Pointcut)
------------------------

**Brief Description:** Mathes every operator or conversion function in the whole project.


.. _/src/core/core_aspect_ah_``where``:

``where`` (Pointcut)
--------------------

**Brief Description:** A virtual placeholder for the pointcut that is used used in the main

**Detailed Description:**

    advice of each aspect.
    This pointcut is can be overridden by derived aspects if they want to change it
    form the default implementation.
    The default implementation is the default_where() pointcut.


