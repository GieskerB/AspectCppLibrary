``DefaultProfiler`` (Aspect)
============================

**Brief Description:** DefaultProfiler is the default aspect for profiling in this ACP library.

**Detailed Description:**

    It uses the DefaultProfilerMsgBuilder and the CoutPrinter to create and print the messages.
    If the developer wants to use a different ProfilerMsgBuilder or Printer, they can create their own aspect that
    extends the original Profiler aspect.

*In file* ``src/understanding/default_profiler.ah``

