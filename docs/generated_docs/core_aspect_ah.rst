``CoreAspect`` (Aspect)
=======================

**Brief Description:** CoreAspect is the base aspect for all aspects in this ACP library.

**Detailed Description:**

    CoreAspect defines various pointcuts that are used throughout this library.
    Some of them are virtual and can be overridden by derived aspects to structure the
    implementation of the aspects. The others are meant to be useful pointcuts for a
    more user oriented usage of the ACP library.

*In file* ``src/core/core_aspect.ah``

.. _core_aspect_ah_ignore:

``ignore`` (Pointcut)
---------------------

**Brief Description:** A virtual placeholder for the pointcut that describes which join points

**Detailed Description:**

    should be ignored by the aspect.
    It is recommended to use and extend a pointcut definition like with:
    "% <AspectName>::...::%(...)" || "% acp::...::%(...)"


.. _core_aspect_ah_where:

``where`` (Pointcut)
--------------------

**Brief Description:** A virtual placeholder for the pointcut that is used used in the main

**Detailed Description:**

    advice of each aspect.
    This pointcut is can be overridden by derived aspects if they want to change it
    form the default implementation.
    The default implementation is the default_where() pointcut.


