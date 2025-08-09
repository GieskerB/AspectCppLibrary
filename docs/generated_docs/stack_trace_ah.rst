``StackTrace``
=======================
..
	(Aspect)

**Brief Description:** This aspect is used to handle stack traces and print them when an uncaught exception occurs.

**Detailed Description:**

    This aspect collects the recent call history in the event of a thrown exception. When the exception is
    caught eventually or changes to a different one, the corrected data will be discarded.
    Upon an thrown exception reaching and leaving a join point marked with the acp::fallback attribute the
    stack trace will be printed.
    The message itself is shaped by the "build_msg()" function. You can replace its content easily by
    writing an aspect to replace it.
    The preferred printing device, which is provided to the constructor, is used to make an output.

*In file* ``src/error_handling/stack_trace.ah``

.. _stack_trace_ah_acpfallback:

``acp::fallback`` (Attribute)
-----------------------------

**Brief Description:** Triggers the printing of the stacktrace if a thrown exception leaves the scope of a join point.

**Detailed Description:**

    Specially recommended to use this attribute in multithreaded applications, because the standard fall-
    back function "main()"" is never reached for all but one thread.


.. _stack_trace_ah_acpignore_trace:

``acp::ignore_trace`` (Attribute)
---------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.
    Not recommend to use this, because of the same reason that the trace attribute is currently unused:
    By excluding join points from the stacktrace the resulting stacktrace will be incomplete.


.. _stack_trace_ah_acptrace:

``acp::trace`` (Attribute)
--------------------------

**Brief Description:** Triggers the appearance of a join point in the case of an uncaught exception in the stacktrace.

**Detailed Description:**

    Useless by default, since the aspect is applied to every join point by default.


.. _stack_trace_ah_build_msg:

``build_msg`` (Function)
------------------------

**Brief Description:** This methods is responsible for creating a well formatted stack trace message

**Detailed Description:**

    In case you want to change this, write an aspect which replaces this function with your
    own implementation. Use a around advice for that.

**Parameters:**

    * ``sign``: is the signature of the function that was called.
    * ``file``: is the name of the file where the function was called.
    * ``line``: is the line number where the function was called.
    * ``result``: is a reference to a string where the formatted message will be stored.


.. _stack_trace_ah_fallback-advice:

``fallback-advice`` (Advice)
----------------------------

**Brief Description:** This advice handles the StackTrace printing when an uncaught exception leaves the function of the pointcut.


.. _stack_trace_ah_fallback_func:

``fallback_func`` (Pointcut)
----------------------------

**Brief Description:** The set of all join points that are marked with the acp::fallback attribute plus the main function.


.. _stack_trace_ah_ignore:

``ignore`` (Pointcut)
---------------------


*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _stack_trace_ah_print_stack_trace:

``print_stack_trace`` (Function)
--------------------------------

**Brief Description:** This method handles everything related to printing the stack trace.

**Detailed Description:**

    In case a developer wants to change the way the stack trace is printed from the ground up,
    they can write an around advice for this function to replace its countent.

**Parameters:**

    * ``call_chain``: is a std::vector of strings that contains the call chain of the stack trace.
    * ``exception_msg``: is the message of the exception that was thrown.


.. _stack_trace_ah_stack-trace-builder-advice:

``stack-trace-builder-advice`` (Advice)
---------------------------------------

**Brief Description:** Advice handles the StackTrace building, in case of an thrown exception.


.. _stack_trace_ah_where:

``where`` (Pointcut)
--------------------


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

