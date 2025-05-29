``StackTrace`` (Aspect)
=======================

**Brief Description:** This aspect is used to handle stack traces and print them when an uncaught exception occurs.

**Detailed Description:**

    This aspect uses the acp::StackTraceMsgBuilder to build the messages for the stack trace and the
    acp::printer to print them.
    By default this aspect will always trigger when an uncaught exception would leave the main function.


.. _/src/error_handling/stack_trace_ah_``acp::fallback``:

``acp::fallback`` (Attribute)
-----------------------------

**Brief Description:** This attribute is used to mark functions that should be used to trigger the stacktrace

**Detailed Description:**

    in case this function does not catch an exception.


.. _/src/error_handling/stack_trace_ah_``acp::trace``:

``acp::trace`` (Attribute)
--------------------------

**Brief Description:** This attribute is used to mark functions that should be traced for stack traces.

**Detailed Description:**

    This attribute is not necessary by default, since the aspect acts globally from the beginning.
    But it can be used, if the developer wants to limit the stack trace to specific functions.
    Then they have to disable the global pointcut first.


.. _/src/error_handling/stack_trace_ah_``default_where``:

``default_where`` (Pointcut)
----------------------------


.. _/src/error_handling/stack_trace_ah_``fallback-advice``:

``fallback-advice`` (Advice)
----------------------------

**Brief Description:** Advice handles the StackTrace printing when an uncaught exception leaves the function of the pointcut.


.. _/src/error_handling/stack_trace_ah_``fallback_func``:

``fallback_func`` (Pointcut)
----------------------------

**Brief Description:** This pointcut matches all functions that are marked with the acp::fallback attribute.

**Detailed Description:**

    Any functions marked with this attribute or the main function will trigger the stack trace to
    be printed if an uncaught exception leaves the function.


.. _/src/error_handling/stack_trace_ah_``ignore``:

``ignore`` (Pointcut)
---------------------


.. _/src/error_handling/stack_trace_ah_``print_stack_trace``:

``print_stack_trace`` (Function)
--------------------------------

**Brief Description:** this function handles everything related to printing the stack trace.

**Detailed Description:**

    In case a developer wants to change the way the stack trace is printed from the ground up,
    they can write an around advice for this function to replace its countent.
    @param call_chain is a std::vector of strings that contains the call chain of the stack trace.
    @param exception_msg is the message of the exception that was thrown.


.. _/src/error_handling/stack_trace_ah_``stack-trace-builder-advice``:

``stack-trace-builder-advice`` (Advice)
---------------------------------------

**Brief Description:** Advice handles the StackTrace building, in case of an thrown exception.


