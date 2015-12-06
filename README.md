Userspace driver for Logitech G710+
===================================

This project provides a userspace driver to support the G keys and M keys on the
Logitech G710+ keyboard. The default Linux driver does not recognize the
behavior of the G and M keys, nor does it send the necessary feature reports to
control the LEDs on the keyboard, as these are controlled by Vendor Usage pages.

Design
======

The keyboard itself works fine under Linux, with the exception of the G & M
keys. These keys are reported in the second interface, which is exposed by
hidraw. Sending or requesting feature reports and monitoring this hidraw
interface provides enough information that a userspace application can interpret
the report and inject the necessary input events via uinput.
