``DefaultStackTrace`` (Aspect)
==============================

**Brief Description:** DefaultStackTrace is the default aspect for stack traces in this ACP library.

**Detailed Description:**

    It uses the default implementation of the StackTraceMsgBuilder and the CerrPrinter to create and print any messages
    If the developer wants to use a different StackTraceMsgBuilder or Printer, they can create their own aspect that
    extends the original StackTrace aspect.

*In file* ``src/error_handling/default_stack_trace.ah``

