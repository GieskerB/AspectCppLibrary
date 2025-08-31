Aspect C++ Library
==================

*Bachelor thesis by Bjarne Giesker in 2025*. *Supervised by
Prof. Dr-Ing. Olaf Spinczyk and Dr.-Ing. Christoph Borchert*.

Idea
----

Aspect-Oriented Programming (AOP) is a relatively lesser-known
programming paradigm that efficiently implements crosscutting concerns
within a software project in a maintainable and readable manner.

AspectC++ is currently the only AOP language extension for C++ that
enables the usage of this paradigm in C++. Since learning a new paradigm
alongside a (somewhat) new language can be time-consuming and sometimes
frustrating, many developers tend to shy away from it and fail to give
it a proper try.

With this library, I aim to reduce the steep learning curve upfront by
providing an implementation for the most common crosscutting concerns as
so-called aspects.

Installation
------------

AspectC++
~~~~~~~~~

Install AspectC++ (ACP) for your current operating system from
`here <https://www.aspectc.org/Download.php>`__. ACP comes with two
different executables: ac++ and ag++.

ac++ is the aspect weaver that converts C++ source code into augmented
source code, which contains the aspects and their implementations.

ag++ executes ac++ and also translates the generated source code using
the local g++ compiler.

This Library
~~~~~~~~~~~~

Clone this GitHub repository and move the library folder to your desired
location. Done!

Implementation
~~~~~~~~~~~~~~

When executing ac++ or ag++ (the latter is recommended), you need to add
certain command-line flags. The two most important flags are
``-p | --path`` and ``-a | --aspect_header``. You always need to provide
the ``src`` directory of this library with ``-p`` as a project path to
use its aspects and specify with the ``-a`` argument which aspect from
the library you want to use. The last argument is optional but highly
recommended because, without it, every aspect from the library will be
applied by the weaver. The documentation contains the file path for each
aspect.

Each aspect is configurable to a certain degree using interfaces. To use
the standard implementation for each aspect, no AspectC++ knowledge is
required. If you want to change the default implementation within the
scope of the interfaces, that is also possible with minimal effort:
Simply create an aspect within a .ah file in your project directory and
inherit from the base implementation of the aspect you want to modify.
The syntax is nearly identical to C++; just swap the class keyword with
aspect. Finally, you need to provide the constructor with your own
implementation of the interfaces from this library.
