``IntegerOverflowCheck``
=================================
..
	(Aspect)

:doc:`Click here to see the source code <integer_overflow_check_ah_src>`

**Brief Description:** Aspect that checks for null pointer dereferences.

**Detailed Description:**

    This aspect is used to detect an over- od underflow within one of the 10 standard (5 binary and all
    5 unary) integer addition and subtraction operators. In the case that such an over- or underflow will
    occur an exception will be triggered and the operation will not be performed.
    Make sure to use the '--builtin_operators' console argument when using this aspect

*In file* ``/src/bug_detection/integer_overflow_check.ah``

*See:* ``acp::OverflowException``

.. _integer_overflow_check_ah_acpignore_overflow_check:

``acp::ignore_overflow_check`` (Attribute)
------------------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.


.. _integer_overflow_check_ah_acpoverflow_check:

``acp::overflow_check`` (Attribute)
-----------------------------------

**Brief Description:** Triggers an integer over- /underflow check for all integer addition and subtraction

**Detailed Description:**

    This attribute marks a join point, on which the IntegerOverflowCheck aspect should be applied.


.. _integer_overflow_check_ah_ignore:

``ignore`` (Pointcut)
---------------------


*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _integer_overflow_check_ah_int_add_binary_check:

``int_add_binary_check`` (Advice)
---------------------------------

**Brief Description:** This advice checks for an overflow in the 'int += int' and 'int + int' operator.


.. _integer_overflow_check_ah_int_add_binary:

``int_add_binary`` (Pointcut)
-----------------------------

**Brief Description:** The set of all builtin binary integer addition join points.


.. _integer_overflow_check_ah_int_add_unary_check:

``int_add_unary_check`` (Advice)
--------------------------------

**Brief Description:** This advice checks for an overflow in the '+int' operator.


.. _integer_overflow_check_ah_int_add_unary_inc_check:

``int_add_unary_inc_check`` (Advice)
------------------------------------

**Brief Description:** This advice checks for an overflow in the '++int' and 'int++' operator.


.. _integer_overflow_check_ah_int_add_unary_inc:

``int_add_unary_inc`` (Pointcut)
--------------------------------

**Brief Description:** The set of all builtin integer increment join points.


.. _integer_overflow_check_ah_int_add_unary:

``int_add_unary`` (Pointcut)
----------------------------

**Brief Description:** The set of all builtin unary integer addition join points.


.. _integer_overflow_check_ah_int_sub_binary_check:

``int_sub_binary_check`` (Advice)
---------------------------------

**Brief Description:** This advice checks for an underflow in the 'int -= int' and 'int - int' operator.


.. _integer_overflow_check_ah_int_sub_binary:

``int_sub_binary`` (Pointcut)
-----------------------------

**Brief Description:** The set of all builtin binary integer subtraction join points.


.. _integer_overflow_check_ah_int_sub_unary_check:

``int_sub_unary_check`` (Advice)
--------------------------------

**Brief Description:** This advice checks for an underflow in the '--int' operator (spoiler: it cant happen :D).


.. _integer_overflow_check_ah_int_sub_unary_inc_check:

``int_sub_unary_inc_check`` (Advice)
------------------------------------

**Brief Description:** This advice checks for an underflow in the '--int' and 'int--' operator.


.. _integer_overflow_check_ah_int_sub_unary_inc:

``int_sub_unary_inc`` (Pointcut)
--------------------------------

**Brief Description:** The set of all builtin integer decrement join points.


.. _integer_overflow_check_ah_int_sub_unary:

``int_sub_unary`` (Pointcut)
----------------------------

**Brief Description:** The set of all builtin unary integer subtraction join points.


.. _integer_overflow_check_ah_where:

``where`` (Pointcut)
--------------------


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

