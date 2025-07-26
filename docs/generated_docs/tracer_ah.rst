``Tracer``
===================
..
	(Aspect)

**Brief Description:** This aspect is used to trace the execution time and call amount of functions and methods.

**Detailed Description:**

    Creates a ordered list of all traced functions and methods. The list is printed after the
    execution of the main function.

*In file* ``src/understanding/tracer.ah``

.. _tracer_ah_Constructor:

``Constructor`` (Constructor)
-----------------------------

**Brief Description:** This constructor initializes the tracer with a builder, printer and thread controller.


.. _tracer_ah_build_msg:

``build_msg`` (Function)
------------------------

**Brief Description:** This function is responsible for creating a well formatted tracer message.

**Detailed Description:**

    In case you want to change this, write an aspect which replaces this function with your
    own implementation. Use a around advice for that.

**Parameters:**

    * ``data``: the tracing data to be used for building the message.
    * ``output``: reference to a string which will contain the output in the end.


.. _tracer_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _tracer_ah_register-advice:

``register-advice`` (Advice)
----------------------------

**Brief Description:** This advice is executed after the main function has finished executing and registers the

**Detailed Description:**

    summary function to be called at exit.
    Atexit will receive the result of the \see summary() function. it expects a function pointer to
    a function that returns void and takes no arguments and is not class bound. Using the atexit()
    function, the most amount of information can be gathered about the program before it exits.


.. _tracer_ah_simple_stat:

``simple_stat`` (Function)
--------------------------

**Brief Description:** This function prints the tracing data of all traced functions and methods.


.. _tracer_ah_summary:

``summary`` (Function)
----------------------

**Brief Description:** This function returns a pointer to the simple_stat function.

**Detailed Description:**

    This function is virtual and can therefore be overridden by derived classes.
    It is used to provide the register-advice with a function pointer to be called at exit.

**Returns:**

    * (In this case) A pointer to the simple_stat function, which prints the tracing data.


.. _tracer_ah_trace-advice:

``trace-advice`` (Advice)
-------------------------

**Brief Description:** This advice is executed around the execution of functions or methods marked with the trace attribute.

**Detailed Description:**

    It measures the execution timestamp of the function or method.
    It uses heap instances of acp::TracerData to store the tracing data.
    The tracing data is updated in a thread-safe manner using the ThreadController.


.. _tracer_ah_trace:

``trace`` (Attribute)
---------------------

**Brief Description:** This attribute is used to mark functions, classes or namespaces that should be traced.


.. _tracer_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

