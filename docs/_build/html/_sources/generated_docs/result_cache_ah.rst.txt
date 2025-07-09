``ResultCache``
========================
..
	(Aspect)

**Brief Description:** Caches the result of a function based on its arguments.

**Detailed Description:**

    Possibly reducing the execution time of functions that are called multiple times with the
    same arguments.

*In file* ``src/functionality/result_cache.ah``

.. _result_cache_ah_cache:

``cache`` (Attribute)
---------------------

**Brief Description:** Functions annotated with this attribute will be cached based on their arguments.

**Detailed Description:**

    Currently only primitive types and pointers to primitive types are supported.


.. _result_cache_ah_caching-advice:

``caching-advice`` (Advice)
---------------------------

**Brief Description:** Caches the result of a function based on its arguments.

**Detailed Description:**

    This advice will only be applied to functions that are annotated with the
    acp::cache attribute.


.. _result_cache_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _result_cache_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

