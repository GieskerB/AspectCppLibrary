``LoggingMsgBuilder`` (Interface)
=================================

**Brief Description:** This interface defines the methods for building log messages.

**Detailed Description:**

    It is used by the logging aspects to create log messages before and after function execution.

*In file* ``src/util/logging_msg_builder.hh``

.. _logging_msg_builder_hh_build_after_msg:

``build_after_msg`` (Function)
------------------------------

**Brief Description:** A function to build a log message specifically for the AfterLoggingAspect.

**Detailed Description:**

    @param signature The signature of the function being logged.
    @param output The output string where the built message will be stored.


.. _logging_msg_builder_hh_build_before_msg:

``build_before_msg`` (Function)
-------------------------------

**Brief Description:** A function to build a log message specifically for the BeforeLoggingAspect.

**Detailed Description:**

    @param signature The signature of the function being logged.
    @param output The output string where the built message will be stored.


.. _logging_msg_builder_hh_build_msg:

``build_msg`` (Function)
------------------------

**Brief Description:** A function to build a general log message.

**Detailed Description:**

    @param log_type The type of log message (e.g., "INFO", "ERROR", etc.).
    @param msg The message to log.
    @param output The output string where the built message will be stored.


