``Singleton`` (Aspect)
======================

**Brief Description:** This aspect implements the Singleton design pattern.

**Detailed Description:**

    This aspect ensures that any class annotated with this specific attribute can have only
    one instance and provides a global access point to that instance. A static get_instance()
    method is provided to retrieve the instance, and construction of the singleton instance.
    When calling any constructor of a class annotated with this aspect, a runtime error will
    be thrown.

*In file* ``src/design_patterns/singleton.ah``

.. _singleton_ah_construction-prevention:

``construction-prevention`` (Advice)
------------------------------------

**Brief Description:** This advice prevents the construction of a singleton class directly.


.. _singleton_ah_ignore:

``ignore`` (Pointcut)
---------------------

*See:* :ref:`CoreAspect::ignore <core_aspect_ah_ignore>`

.. _singleton_ah_singleton-slice:

``singleton-slice`` (Advice)
----------------------------

**Brief Description:** This advice provides a class slice with all necessary methods and

**Detailed Description:**

    members to implement the Singleton design pattern.


.. _singleton_ah_singleton:

``singleton`` (Attribute)
-------------------------

**Brief Description:** This attribute is used to mark classes as singletons.


.. _singleton_ah_where:

``where`` (Pointcut)
--------------------

*See:* :ref:`CoreAspect::where <core_aspect_ah_where>`

