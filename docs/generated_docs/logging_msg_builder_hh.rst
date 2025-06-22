``LoggingMsgBuilder`` (Interface)
=================================

**Brief Description:** This interface defines the methods for building log messages.

**Detailed Description:**

    It is used by the logging aspects to create log messages before and after function execution.

*In file* ``src/functionality/logging_msg_builder.hh``

.. _logging_msg_builder_hh_build_after_msg:

``build_after_msg`` (Function)
------------------------------

**Brief Description:** A function to build a log message specifically for the AfterLoggingAspect.

**Parameters:**

    * ``signature``: The signature of the function being logged.
    * ``output``: The output string where the built message will be stored.


.. _logging_msg_builder_hh_build_before_msg:

``build_before_msg`` (Function)
-------------------------------

**Brief Description:** A function to build a log message specifically for the BeforeLoggingAspect.

**Parameters:**

    * ``signature``: The signature of the function being logged.
    * ``output``: The output string where the built message will be stored.


.. _logging_msg_builder_hh_build_msg:

``build_msg`` (Function)
------------------------

**Brief Description:** A function to build a general log message.

**Parameters:**

    * ``log_type``: The type of log message (e.g., "INFO", "ERROR", etc.).
    * ``msg``: The message to log.
    * ``output``: The output string where the built message will be stored.


