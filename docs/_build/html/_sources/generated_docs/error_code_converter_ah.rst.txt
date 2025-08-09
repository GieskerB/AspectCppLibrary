``ErrorCodeConverter``
===============================
..
	(Aspect)

**Brief Description:** This aspect is used to convert error codes from standard library functions into exceptions.

**Detailed Description:**

    This advice checks if errno is set to a non-zero value after a function call and throws an
    exception with the current value of errno.

*In file* ``src/error_detection/error_code_converter.ah``

*See:* ``ErrnoException``

.. _error_code_converter_ah_acperr_code:

``acp::err_code`` (Attribute)
-----------------------------

**Brief Description:** Triggers an errno check after function calls.

**Detailed Description:**

    This attribute makes every join points with the annotated, on which the
    ErrorCodeConverter should be applied.


.. _error_code_converter_ah_acpignore_err_code:

``acp::ignore_err_code`` (Attribute)
------------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.


.. _error_code_converter_ah_errno_check:

``errno_check`` (Advice)
------------------------

**Brief Description:** This advice checks if errno is set to a non-zero value after the function call


.. _error_code_converter_ah_ignore:

``ignore`` (Pointcut)
---------------------


*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _error_code_converter_ah_where:

``where`` (Pointcut)
--------------------


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

