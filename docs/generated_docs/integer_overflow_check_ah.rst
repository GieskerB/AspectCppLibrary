``IntegerOverflowCheck`` (Aspect)
=================================

**Brief Description:** Aspect that checks for null pointer dereferences.

**Detailed Description:**

    This aspect provides advices to check if an over- or underflow would occur, when performing
    addition or subtraction on integers. At the moment this check is performed for every standard int
    addition and subtraction operator (all 5 binary and all 5 unary).

*In file* ``/src/bug_detection/integer_overflow_check.ah``

.. _integer_overflow_check_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _integer_overflow_check_ah_int_add_binary_check:

``int_add_binary_check`` (Advice)
---------------------------------

**Brief Description:** checks for an overflow in the 'int += int' and 'int + int' operator.


.. _integer_overflow_check_ah_int_add_unary_check:

``int_add_unary_check`` (Advice)
--------------------------------

**Brief Description:** checks for an overflow in the '+int' operator.


.. _integer_overflow_check_ah_int_add_unary_inc_check:

``int_add_unary_inc_check`` (Advice)
------------------------------------

**Brief Description:** checks for an overflow in the '++int' and 'int++' operator.


.. _integer_overflow_check_ah_int_sub_binary_check:

``int_sub_binary_check`` (Advice)
---------------------------------

**Brief Description:** checks for an underflow in the 'int -= int' and 'int - int' operator.


.. _integer_overflow_check_ah_int_sub_unary_check:

``int_sub_unary_check`` (Advice)
--------------------------------

**Brief Description:** checks for an underflow in the '--int' operator (spoiler: it cant happen :D).


.. _integer_overflow_check_ah_int_sub_unary_inc_check:

``int_sub_unary_inc_check`` (Advice)
------------------------------------

**Brief Description:** checks for an underflow in the '--int' and 'int--' operator.


.. _integer_overflow_check_ah_overflow_check:

``overflow_check`` (Attribute)
------------------------------

**Brief Description:** For all integer addition and subtraction within any function / class / namespace

**Detailed Description:**

    annotated with this attribute an over- or underflow check will be performed. In case this
    happens, an exception will be thrown.


.. _integer_overflow_check_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

