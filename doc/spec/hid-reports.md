HID Reports for Logitech G710+
==============================

The Logitech G710+ keyboard uses a number of reports in Vendor Usage pages that
can't be interpreted by the standard usbhid driver. This document lists the
known reports and characterizes them.

## Report ID 1

Report ID 1 is the standard keyboard report - all standard key presses are sent
through this report. If the G-keys are configured to behave as a standard key,
then those keypresses are also sent through this report. This report is sent
through interface 0, while all other reports are sent through interface 1.

## Report ID 2

This report is used for the media controls (Play/Pause, Stop, Next Track,
Previous Track, Volume Up, Volume Down and Mute). This is in a standard
Application Usage page, and doesn't need to be modified.

## Report ID 3

This report is used to report the status of the G, M, game mode and brightness
keys. The format is as follows (in binary):

    WASD Brightness ----------------------+
    Keys Brightness ---------------------+|
    Game Mode --------------------------+||
                                        |||
    M1 --------------------+            |||
    M2 -------------------+|            |||
    M3 ------------------+||            |||
    MR -----------------+|||            |||
                        ||||            |||
    G1 ---------------+ ||||            |||
    G2 --------------+| ||||            |||
    G3 -------------+|| ||||            |||
    G4 ------------+||| ||||            |||
    G5 ----------+ |||| ||||            |||
    G6 ---------+| |||| ||||            |||
                || |||| ||||            |||
    0000 0011 00-- ---- ---- 0000 0000 0---
    |-------|
    Report ID

## Report ID 4

This report is used as information when the game or brightness keys are pressed
and it gives the current state of the game key and the brightness settings.
Brightness is a value from 0x00 to 0x04, with 0x00 being the brightest setting
and 0x04 being off. Since the brightness can be controlled individually for the
WASD/arrow keys and the rest of the keyboard, the report has two entries for the
brightness setting. The format is as follows (in hex):

    04 XX XX XX 00 00 00 00
     |  |  |  | |---------|
     |  |  |  |           +-- Unused
     |  |  |  +-------------- Keyboard brightness (0x00 - 0x04)
     |  |  +----------------- WASD/arrow brightness (0x00 - 0x04)
     |  +-------------------- Game mode (0x00 - off, 0x01 - on)
     +----------------------- Report ID

## Report ID 5

Currently, the usage and format of this report is unknown.

## Report ID 6

This report is used typically in a SET_REPORT request to set the state of the
macro key LEDs. The format is as follows (in binary):

    0000 0110 ---- 0000
    |-------| ||||
    Report ID |||+-- M1 LED
              ||+--- M2 LED
              |+---- M3 LED
              +----- M4 LED

## Report ID 7

This report is used to control the brightness in a fine-grained manner. The
values are encoded in little-endian order and range from 0 to 8192 (0x0000 -
0x2000). The format is as follows:

    07 XX XX YY YY
     |  |  |  |  |
     |  |  |  +--+-- Keyboard brightness
     |  +--+-------- WASD/arrow brightness
     +-------------- Report ID

This brightness control is somewhat independent in that setting the brightness
via this report doesn't change the brightness reported in the 0-4 scale, but
using the brightness keys or report ID 8 will change the values in this report.

## Report ID 8

This report appears to be used to set the brightness states. As with report ID
4, this uses the same format for brightness values. The format is as follows (in
hex):

    08 XX XX 00
     |  |  |
     |  |  +-- Keyboard brightness (0x00 - 0x04)
     |  +----- WASD/arrow brightness (0x00 - 0x04)
     +-------- Report ID

## Report ID 9

This report seems to control the functionality of the G keys. By default, when
the keyboard is initialized, G1 through G6 reports keys 1 through 6
respectively on the default interface. This report can change the values
reported by the keys, or disable them from reporting anything on interface 0
altogether. The format is as follows (in hex):

    09 XX XX XX  XX XX XX 00  00 00 00 00  00 
     |  |  |  |   |  |  |
     |  |  |  |   |  |  +-- G6 report value (0x00 is disable)
     |  |  |  |   |  +----- G5 report value (0x00 is disable)
     |  |  |  |   +-------- G4 report value (0x00 is disable)
     |  |  |  +------------ G3 report value (0x00 is disable)
     |  |  +--------------- G2 report value (0x00 is disable)
     |  +------------------ G1 report value (0x00 is disable)
     +--------------------- Report ID

Therefore, to disable the G keys and control them solely through interface 1, it
seems sufficient to set the feature report with all zeroes. The values are as
described in the keyboard/keypad page in HID Usage Tables. This also means that
the G keys can be used with modifiers such as Shift.

## Report ID 128

Currently, the usage and format of this report is unknown.

