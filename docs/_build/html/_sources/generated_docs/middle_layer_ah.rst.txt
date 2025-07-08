``MiddleLayer``
========================
..
	(Aspect)

**Brief Description:** This aspect defines a middle layer pointcut for this library.

**Detailed Description:**

    Alongside the two other classes outer- and inner layer these classes provide
    a simple way of ordering aspect in the weaving process. Imagine the "core" to
    be the original function and then all aspects inheriting from MiddleLayer are
    weaved between OuterLayer and InnerLayer. Within all aspects from the same
    layer is no further order.

*In file* ``src/core/middle_layer.ah``

