``ErrorCodeConverter`` (Aspect)
===============================

**Brief Description:** This aspect is used to convert error codes from standard library functions into exceptions.

**Detailed Description:**

    It checks if errno is set to a non-zero value after a function call and throws an `acp::ErrnoException` with the current value of errno.
    It is recommended to use this aspect in conjunction with the StackTrace aspect to get a full stack trace.

*In file* ``src/error_detection/error_code_converter.ah``

.. _error_code_converter_ah_acperr_code:

``acp::err_code`` (Attribute)
-----------------------------

**Brief Description:** This attribute should be used to mark functions from which a function call is checked for errno.

**Detailed Description:**

    Due to some implementations restrictions with the AspectC++ compiler, this attribute is not used.


.. _error_code_converter_ah_errno_check:

``errno_check`` (Advice)
------------------------

**Brief Description:** Advice checks if errno is set to a non-zero value after the function call.

**Detailed Description:**

    If this conditions is met, it throws an `acp::ErrnoException` with the current value of errno.
    It is recommended to use this advice in conjunction with the StackTrace aspect to get a full stack trace.


.. _error_code_converter_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _error_code_converter_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

