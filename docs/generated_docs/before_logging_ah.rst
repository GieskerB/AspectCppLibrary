``BeforeLogging`` (Aspect)
==========================

**Brief Description:** This aspect is used to log the execution of a function before it will execute.

**Detailed Description:**

    Similar to the `AfterLogging` aspect, this aspect logs the function signature - but only - before the function will execute.

*In file* ``src/functions/before_logging.ah``

.. _before_logging_ah_before_logging:

``before_logging`` (Attribute)
------------------------------

**Brief Description:** Functions with this attribute will be logged before their execution.


.. _before_logging_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _before_logging_ah_logging-advice:

``logging-advice`` (Advice)
---------------------------

**Brief Description:** This advice handles the logging behavior before the function executes.


.. _before_logging_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

