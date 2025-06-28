``StackTraceMsgBuilder`` (Interface)
====================================

**Brief Description:** StackTraceMsgBuilder is an interface for creating a stack trace messages.

**Detailed Description:**

    This interface defines the method for creating a messages for the StackTrace-Aspect.

*In file* ``src/error_handling/stack_trace_msg_builder.hh``

.. _stack_trace_msg_builder_hh_build_msg:

``build_msg`` (Function)
------------------------

**Brief Description:** build_msg is a pure virtual function that builds a message for the stack trace.

**Parameters:**

    * ``sign``: is the signature of the function that was called.
    * ``file``: is the name of the file where the function was called.
    * ``line``: is the line number where the function was called.
    * ``result``: is a reference to a string where the formatted message will be stored.


