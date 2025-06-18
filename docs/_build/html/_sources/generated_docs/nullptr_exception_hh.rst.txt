``NullptrException`` (Exception)
================================

**Brief Description:** Exception class for handling null pointer dereference errors.

**Detailed Description:**

    This class inherits from `std::runtime_error` and is used to indicate that a null pointer was dereferenced.

*In file* ``/src/util/nullptr_exception.hh``

.. _nullptr_exception_hh_Constructor:

``Constructor`` (Constructor)
-----------------------------

**Brief Description:** Construct a new NullptrException object with a message indicating location of the error.


.. _nullptr_exception_hh_what:

``what`` (Function)
-------------------

**Brief Description:** Overridden std::runtime_error::what() function to return the error message.


