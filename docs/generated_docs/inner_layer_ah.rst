``InnerLayer``
=======================
..
	(Aspect)

**Brief Description:** This aspect defines an inner layer pointcut for this library.

**Detailed Description:**

    Alongside the two other classes outer- and middle layer these classes provide
    a simple way of ordering aspect in the weaving process. Imagine the "core" to
    be the original function and then all aspects inheriting from MiddleLayer are
    weaved before the other two. Within all aspects from the same layer is no
    further order.

*In file* ``src/core/inner_layer.ah``

