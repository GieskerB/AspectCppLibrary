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


.. _core_aspect_ah_inner_layer:

``inner_layer`` (Attribute)
---------------------------

**Brief Description:** This attributes defines a weaving order layer for aspects.

**Detailed Description:**

    Alongside the two other attributes outer- and middle_layer these attributes
    provide a simple way of ordering aspect in the weaving process. Imagine the
    "core" to be the original function and then all aspects annotated with
    acp::inner_layer are weaved before the other two. Within all aspects from the
    same layer is no further order.


.. _core_aspect_ah_middle_layer:

``middle_layer`` (Attribute)
----------------------------

**Brief Description:** This attributes defines a weaving order layer for aspects.

**Detailed Description:**

    Alongside the two other attributes outer- and inner_layer these attributes
    provide a simple way of ordering aspect in the weaving process. Imagine the
    "core" to be the original function and then all aspects annotated with
    acp::middle_layer are weaved between the other two. Within all aspects from the
    same layer is no further order.


.. _core_aspect_ah_ordering:

``ordering`` (Advice)
---------------------

**Brief Description:** This advice defines the order of the aspects in the weaving process.

**Detailed Description:**

    Naming of the layers is relative to the "distance" to the function which represents the core.
    In case of before advices the outer layer is weaved first, then the middle layer and finally the inner layer.
    For after advices this is the other way around and for around advice it is a capsulation with results in the
    same order as for the before and after advices combined.


.. _core_aspect_ah_outer_layer:

``outer_layer`` (Attribute)
---------------------------

**Brief Description:** This attributes defines a weaving order layer for aspects.

**Detailed Description:**

    Alongside the two other attributes middle- and inner_layer these attributes
    provide a simple way of ordering aspect in the weaving process. Imagine the
    "core" to be the original function and then all aspects annotated with
    acp::outer_layer are weaved after the other two. Within all aspects from the
    same layer is no further order.


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

