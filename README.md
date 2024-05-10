# Nava 909 Custom Firmware

## Description

This is a fork of the alternative Nava 909 firmware by sandormatyi which can be found [here](https://pages.github.com/](https://github.com/sandormatyi/Nava-909-firmware
). It has a couple additional features and minor fixes.

## New features

- 0-100 probability control per instrument per step for triggering
- A note ratcheting function which also operates per instrument per step.
- Fixed accent triggering bug caused by poor implementation of timing control of DEMUX INHIBIT signals for the instrument trigger and accent trigger 4051 ICs.
- Mild modifications of original codebase to improve adherence to software design principles.

## Setup the development environment

1) Open the project (`Nava_v1_028beta\Nava_v1_028beta.ino`)
2) Open `Preferences` and paste the following link into `Additional boards manager URLs`: https://mcudude.github.io/MightyCore/package_MCUdude_MightyCore_index.json
3) Open the `Board Manager`, search for `MightyCore` and download the package
4) Select the `ATmega1284` board
5) Open the `Library Manager` and install the `LiquidCrystal` library

## Compile and upload the firmware

Here is how I do it using MIDI SysEx:

1) Compile and export the source code (`Sketch/Export compiled Binary`). This creates a `build/MightyCore.avr.1284` directory inside your project directory where your compiled binaries are.
2) Open a command line interface at the root of the repository and execute the following command (I use Python 2.7 so it probably doesn't work with 3.x right off the bat):

`python tools/hex2sysex/hex2sysex.py -o Nava_v1_028beta/build/MightyCore.avr.1284/firmware.syx Nava_v1_028beta/build/MightyCore.avr.1284/Nava_v1_028beta.ino.with_bootloader.hex -s`

3) Open MIDI-OX, set the SysEx buffer size to 64 bytes
4) Turn on the Nava with the step buttons 1, 3 and 5 pressed
5) Send the `firmware.syx` file to the MIDI input of the Nava (this will take a couple minutes, you should see the step buttons showing the progress)
