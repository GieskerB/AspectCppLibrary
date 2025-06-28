``OverflowException`` (Exception)
=================================

**Brief Description:** Exception class for handling null pointer dereference errors.

**Detailed Description:**

    This class inherits from `std::runtime_error` and is used to indicate that a null pointer was dereferenced.

*In file* ``/src/bug_detection/overflow_exception.hh``

.. _overflow_exception_hh_Constructor:

``Constructor`` (Constructor)
-----------------------------

**Brief Description:** Construct a new OverflowException object with a message indicating location of the error.

**Parameters:**

    * ``sig``: is a c-string that indicates the signature of the function where the error occurred.
    * ``line``: is the line number where the error occurred.


.. _overflow_exception_hh_what:

``what`` (Function)
-------------------

**Brief Description:** Overridden std::runtime_error::what() function to return the error message.


