``OfstreamPrinter``
===========================
..
	(Class)

**Brief Description:** OfstreamPrinter is a Printer implementation that prints messages to a std::ofstream.

**Detailed Description:**

    This class implements the Printer interface and provides methods to print messages
    to a specified output file stream (std::ofstream).

*In file* ``src/core/ofstream_printer.hh``

.. _ofstream_printer_hh_Constructor:

``Constructor`` (Constructor)
-----------------------------

**Brief Description:** Construct a new OfstreamPrinter object and open the output file stream.

**Parameters:**

    * ``filename``: is the name of the file to which messages will be printed.


.. _ofstream_printer_hh_Destructor:

``Destructor`` (Destructor)
---------------------------

**Brief Description:** Destroy the Ofstream Printer object and close the output file stream.


.. _ofstream_printer_hh_printc-string:

``print[c-string]`` (Function)
------------------------------


*See:* :ref:`Printer::print <printer_hh_printc-string>`

.. _ofstream_printer_hh_printchar:

``print[char]`` (Function)
--------------------------


*See:* :ref:`Printer::print <printer_hh_printchar>`

.. _ofstream_printer_hh_printstdstring:

``print[std::string]`` (Function)
---------------------------------


*See:* :ref:`Printer::print <printer_hh_printstdstring>`

