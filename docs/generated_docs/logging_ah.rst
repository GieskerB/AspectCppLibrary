``Logging``
====================
..
	(Aspect)

**Brief Description:** This aspect is used to log the execution of a function.

**Detailed Description:**

    With the default configuration of this aspect the function signature will be printed alongside the
    "action" relative to the function: Entering od leaving.
    This aspect supports three different attributes: acp::after_logging, acp::around_logging and
    acp::before_logging. Depending on the choosen attribute the logging happens at the expected point
    relative to the execution.
    The messages themself are shaped by the "build_msg()", "build_before_msg()" and "build_after_msg"
    function. You can replace its content easily by writing an aspect to replace it.
    The preferred printing device, which is provided to the constructor, is used to make an output.

*In file* ``src/functionality/logging.ah``

.. _logging_ah_acpafter_logging:

``acp::after_logging`` (Attribute)
----------------------------------

**Brief Description:** Triggers a join point signature logging after their execution.


.. _logging_ah_acparound_logging:

``acp::around_logging`` (Attribute)
-----------------------------------

**Brief Description:** Triggers a join point signature logging before and after their execution.


.. _logging_ah_acpbefore_logging:

``acp::before_logging`` (Attribute)
-----------------------------------

**Brief Description:** Triggers a join point signature logging before their execution.


.. _logging_ah_acpignore_logging:

``acp::ignore_logging`` (Attribute)
-----------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.


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

**Brief Description:** This advice handles the logging after the function executes.


.. _logging_ah_logging-advicearound:

``logging-advice[around]`` (Advice)
-----------------------------------

**Brief Description:** This advice handles the logging before and after the function executes.

**Detailed Description:**

    Notice that this advice uses the where join point which is by default set to acp::around:logging.


.. _logging_ah_logging-advicebefore:

``logging-advice[before]`` (Advice)
-----------------------------------

**Brief Description:** This advice handles the logging before the function executes.


.. _logging_ah_where:

``where`` (Pointcut)
--------------------

**Detailed Description:**

    This aspect comes with three different attributes all having a similar effect. This is not
    foreseen in the design idea of this library. Therefore, this aspect only has two always
    active attributes and only one "configurable": acp::around_logging.


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

