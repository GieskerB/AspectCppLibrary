``ErrnoException`` (Exception)
==============================

**Brief Description:** ErrnoException is an exception that is thrown within the ErrorCodeConverterAspect when

**Detailed Description:**

    a function call sets errno to a non-zero value.

*In file* ``/src/error_detection/errno_exception.hh``

.. _errno_exception_hh_Constructor:

``Constructor`` (Constructor)
-----------------------------

**Brief Description:** Construct a new ErrnoException object with the given error number.

**Detailed Description:**

    It will create a message based on the error number using std::strerror.

**Parameters:**

    * ``err``: is the error number that was set by a std-lib function.


.. _errno_exception_hh_get_errno:

``get_errno`` (Function)
------------------------

**Brief Description:** Returns the error number relevant to this exception.


.. _errno_exception_hh_what:

``what`` (Function)
-------------------

**Brief Description:** Overridden std::runtime_error::what() function to return the error message.


