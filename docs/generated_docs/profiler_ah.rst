``Profiler`` (Aspect)
=====================

**Brief Description:** This aspect is used to profile the execution time and call amount of functions and methods.

**Detailed Description:**

    In conjunction with this aspect use an aspect that provides a implementation for the
    acp::profiler_msg_builder::build_msg() method.


.. _profiler_ah_Constructor:

``Constructor`` (Constructor)
-----------------------------

**Brief Description:** This constructor initializes the profiler with a builder, printer and thread controller.


.. _profiler_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _profiler_ah_profile-advice:

``profile-advice`` (Advice)
---------------------------

**Brief Description:** This advice is executed around the execution of functions or methods marked with the profile attribute.

**Detailed Description:**

    It measures the execution time and call count of the function or method.
    It uses a static instance of acp::ProfilerData to store the profiling data.
    The profiling data is updated in a thread-safe manner using the ThreadController.


.. _profiler_ah_profile:

``profile`` (Attribute)
-----------------------

**Brief Description:** This attribute is used to mark functions, classes or namespaces that should be profiled.


.. _profiler_ah_register-advice:

``register-advice`` (Advice)
----------------------------

**Brief Description:** This advice is executed after the main function has finished executing and registers the

**Detailed Description:**

    summary function to be called at exit.
    Atexit will receive the result of the \see summary() function. it expects a function pointer to
    a function that returns void and takes no arguments and is not class bound. Using the atexit()
    function, the most amount of information can be gathered about the program before it exits.


.. _profiler_ah_simple_stat:

``simple_stat`` (Function)
--------------------------

**Brief Description:** This function prints the profiling data of all profiled functions and methods.


.. _profiler_ah_summary:

``summary`` (Function)
----------------------

**Brief Description:** This function returns a pointer to the simple_stat function.

**Detailed Description:**

    This function is virtual and can therefore be overridden by derived classes.
    It is used to provide the register-advice with a function pointer to be called at exit.


.. _profiler_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

