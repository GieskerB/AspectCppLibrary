``OuterLayer``
======================
..
	(Class)

**Brief Description:** This class defines an outer layer "priority" for this library.

**Detailed Description:**

    Alongside the two other classes middle- and inner layer these classes provide
    a simple way of ordering aspect in the weaving process. Imagine the "core" to
    be the original function and then all aspects inheriting from OuterLayer are
    weaved at the very last. Within all aspects from the same layer is no further
    order.

*In file* ``src/core/outer_layer.ah``

