``DefaultBeforeLogging`` (Aspect)
=================================

**Brief Description:** This aspect is a default implementation of the `AfterLogging` aspect.

**Detailed Description:**

    In conjunction with this aspect use an aspect that provides a implementation for the
    acp::logging_msg_builder::build_before_msg() method.
    It uses the `CoutPrinter` to print the log message to the standard output.

*In file* ``src/functions/default_before_logging.ah``

