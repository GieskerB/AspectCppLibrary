``Profiler``
=====================
..
	(Aspect)

:doc:`Click here to see the source code <profiler_ah_src>`

**Brief Description:** This aspect is used to profile the execution time and call amount of functions and methods.

**Detailed Description:**

    Creates a grouped list by signature name of all profiled functions and methods. The list is printed
    after the execution of the main function.
    The list entries themself are shaped by the "build_msg()" function. You can replace its content
    easily by writing an aspect to replace it.
    The preferred printing device, which is provided to the constructor, is used to make an output.

*In file* ``src/understanding/profiler.ah``

.. _profiler_ah_Constructor:

``Constructor`` (Constructor)
-----------------------------

**Brief Description:** This constructor initializes the profiler with a builder, printer and thread controller.


.. _profiler_ah_acpignore_profile:

``acp::ignore_profile`` (Attribute)
-----------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    ()
    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.


.. _profiler_ah_acpprofile:

``acp::profile`` (Attribute)
----------------------------

**Brief Description:** This attribute is used to mark join points that should be profiled.


.. _profiler_ah_build_msg:

``build_msg`` (Function)
------------------------

**Brief Description:** This function is responsible for creating a well formatted profiler message.

**Detailed Description:**

    In case you want to change this, write an aspect which replaces this function with your
    own implementation. Use a around advice for that.

**Parameters:**

    * ``data``: the profiling data to be used for building the message.
    * ``output``: reference to a string which will contain the output in the end.


.. _profiler_ah_ignore:

``ignore`` (Pointcut)
---------------------


*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _profiler_ah_profile-advice:

``profile-advice`` (Advice)
---------------------------

**Brief Description:** This advice collects relevant data and stores it for later use.

**Detailed Description:**

    It measures the execution time and call count of the function or method.
    It uses a static instance of acp::ProfilerData to store the profiling data.
    The profiling data is updated in a thread-safe manner using the ThreadController.


*See:* ``acp::ProfilerData``

.. _profiler_ah_register-advice:

``register-advice`` (Advice)
----------------------------

**Brief Description:** This advice registers the summary function to at_exit to delay the printing as much as possible.

**Detailed Description:**

    Atexit will receive the result of the function. it expects a function pointer to
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

**Returns:**

    * (In this case) A pointer to the simple_stat function, which prints the profiling data.


.. _profiler_ah_where:

``where`` (Pointcut)
--------------------


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

