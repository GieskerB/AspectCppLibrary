``CoreAspect``
=======================
..
	(Aspect)

**Brief Description:** CoreAspect is the base aspect for all aspects in this ACP library.

**Detailed Description:**

    CoreAspect defines base for all main aspects of this library. It ensures that all aspects
    have a where pointcut and an ignore pointcut.
    The where pointcut is used in the main advice of each aspect. It denotes on which join
    points (where the aspect should be applied).
    The ignore pointcut is used to define which join points should be ignored by the aspect.

*In file* ``src/core/core_aspect.ah``

.. _core_aspect_ah_ignore:

``ignore`` (Pointcut)
---------------------

**Brief Description:** A virtual placeholder for the pointcut that describes which join points

**Detailed Description:**

    should be ignored by the aspect.
    It is recommended to use and extend a pointcut definition like with:
    within("<AspectName>") || within("acp")


.. _core_aspect_ah_where:

``where`` (Pointcut)
--------------------

**Brief Description:** A virtual placeholder for the pointcut that is used used in the main

**Detailed Description:**

    advice of each aspect.
    This pointcut is can be overridden by derived aspects if they want to change it
    form the default implementation.
    The default implementation is the default_where() pointcut.

*In file* ``src/core/core_aspect.hh``

