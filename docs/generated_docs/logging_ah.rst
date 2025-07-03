``Logging``
====================
..
	(Aspect)

**Brief Description:** This aspect is used to log the execution of a function.

**Detailed Description:**

    This aspect supports three different attributes: acp::after_logging, acp::around_logging and acp::before_logging.
    Depending on the choosen attribute the logging happens at the expected point relative to the execution
    Similar to the `AfterLogging` aspect, this aspect logs the function signature - but only - before the function will execute.

*In file* ``src/functionality/logging.ah``

.. _logging_ah_after_logging:

``after_logging`` (Attribute)
-----------------------------

**Brief Description:** Functions with this attribute will be logged after their execution.


.. _logging_ah_around_logging:

``around_logging`` (Attribute)
------------------------------

**Brief Description:** Functions with this attribute will be logged before and after their execution.


.. _logging_ah_before_logging:

``before_logging`` (Attribute)
------------------------------

**Brief Description:** Functions with this attribute will be logged before their execution.


.. _logging_ah_build_after_msg:

``build_after_msg`` (Function)
------------------------------

**Brief Description:** This function is responsible for creating a well formatted leaving logging message.

**Detailed Description:**

    In case you want to change this, write an aspect which replaces this function with your
    own implementation. Use a around advice for that.

**Parameters:**

    * ``signature``: The signature of the function being logged.
    * ``output``: The output string where the built message will be stored.


.. _logging_ah_build_before_msg:

``build_before_msg`` (Function)
-------------------------------

**Brief Description:** This function is responsible for creating a well formatted entering logging message.

**Detailed Description:**

    In case you want to change this, write an aspect which replaces this function with your
    own implementation. Use a around advice for that.

**Parameters:**

    * ``signature``: The signature of the function being logged.
    * ``output``: The output string where the built message will be stored.


.. _logging_ah_build_msg:

``build_msg`` (Function)
------------------------

**Brief Description:** This function is responsible for creating a well formatted general logging message.

**Detailed Description:**

    In case you want to change this, write an aspect which replaces this function with your
    own implementation. Use a around advice for that.

**Parameters:**

    * ``log_type``: The type of log message (e.g., "INFO", "ERROR", etc.).
    * ``msg``: The message to log.
    * ``output``: The output string where the built message will be stored.


.. _logging_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _logging_ah_logging-adviceafter:

``logging-advice[after]`` (Advice)
----------------------------------

**Brief Description:** This advice handles the logging behavior after the function executes.


.. _logging_ah_logging-advicearound:

``logging-advice[around]`` (Advice)
-----------------------------------

**Brief Description:** This advice handles the logging behavior before and after the function executes.


.. _logging_ah_logging-advicebefore:

``logging-advice[before]`` (Advice)
-----------------------------------

**Brief Description:** This advice handles the logging behavior before the function executes.


.. _logging_ah_where:

``where`` (Pointcut)
--------------------

**Detailed Description:**

    A little bonus for this aspect is that there are 3 attributes [after, around, before]
    Since, where can no be every attribute at once, the around_logging is the default
    implementation. However, separate advices for the remaining attributes is provided anyways.

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

