``AfterLogging`` (Aspect)
=========================

**Brief Description:** This aspect is used to log the execution of a function after it has completed.

**Detailed Description:**

    Similar to the `BeforeLogging` aspect, this aspect logs the function signature - but only - after the function has executed.

*In file* ``src/functions/after_logging.ah``

.. _after_logging_ah_after_logging:

``after_logging`` (Attribute)
-----------------------------

**Brief Description:** Functions with this attribute will be logged after their execution.


.. _after_logging_ah_default_where:

``default_where`` (Pointcut)
----------------------------

*See:* :ref:`CoreAspect::default_where <core_aspect_ah_default_where>`

.. _after_logging_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _after_logging_ah_logging-advice:

``logging-advice`` (Advice)
---------------------------

**Brief Description:** This advice handles the logging behavior after the function execution.


