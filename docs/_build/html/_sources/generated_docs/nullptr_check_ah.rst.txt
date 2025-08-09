``NullptrCheck``
=========================
..
	(Aspect)

**Brief Description:** Aspect that checks for null pointer dereferences.

**Detailed Description:**

    This aspect is used to detect an nullptr dereferencing, which would lead to a segfault.
    In the case that such an potential segfault an exception will be triggered and the
    dereferencing will not be performed.
    Unfortunately, it does not work with the -> operator, due to limitations in the AspectC++
    language and the way the builtin 'operator->' is defined.

*In file* ``/src/bug_detection/nullptr_check.ah``

*See:* ``acp::NullptrException``

.. _nullptr_check_ah_acpignore_null_check:

``acp::ignore_null_check`` (Attribute)
--------------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.


.. _nullptr_check_ah_acpnull_check:

``acp::null_check`` (Attribute)
-------------------------------

**Brief Description:** Triggers an nullptr check for all pointer dereferencing operators

**Detailed Description:**

    This attribute marks a join point, on which the Nullptrcheck aspect should be applied.


.. _nullptr_check_ah_dereferencing_pointer:

``dereferencing_pointer`` (Pointcut)
------------------------------------

**Brief Description:** The set of all builtin pointer dereferencing join points.


.. _nullptr_check_ah_ignore:

``ignore`` (Pointcut)
---------------------


*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _nullptr_check_ah_nullptr_check:

``nullptr_check`` (Advice)
--------------------------

**Brief Description:** This Advice checks if a pointer is null before dereferencing it.


.. _nullptr_check_ah_where:

``where`` (Pointcut)
--------------------


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

