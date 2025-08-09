``ResultCache``
========================
..
	(Aspect)

**Brief Description:** This aspect caches the result of a function based on its arguments.

**Detailed Description:**

    To potentially reduce runtime this aspects checks a result cache per join point to see if the same inputs
    were inserted previously. In that case simple return the value from the cache instead of recalculation it.
    Make sure to only use this aspect on functions there the output is only dependent on the arguments and
    nothing more like global or member variables.
    Unfortunately, it does only work is all operators are standard primitive data types, due to limitations
    in the AspectC++ language. It is currently not possible to get the type of each parameter directly which
    is necessary for correct hasing.

*In file* ``src/functionality/result_cache.ah``

.. _result_cache_ah_acpcache:

``acp::cache`` (Attribute)
--------------------------

**Brief Description:** Triggers a cache usage for marked join points.

**Detailed Description:**

    This attribute makes a join points, for which a result cache should be used.


.. _result_cache_ah_acpignore_cache:

``acp::ignore_cache`` (Attribute)
---------------------------------

**Brief Description:** This attribute can be used to exclude certain join points form being affected by this aspect.

**Detailed Description:**

    If a scope already is annotated with this aspect's attribute, individual join points within can be
    excluded with this attribute.


.. _result_cache_ah_caching-advice:

``caching-advice`` (Advice)
---------------------------

**Brief Description:** This advice caches the result of a function based on its arguments.


.. _result_cache_ah_ignore:

``ignore`` (Pointcut)
---------------------


*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _result_cache_ah_where:

``where`` (Pointcut)
--------------------


*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

