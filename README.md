# Nava 909 alternative firmware

Based on the 1.028b firmware by e-licktronics. This branch contains the source code of the original firmware. If you want to check out the additional features, switch to the `features` branch!

## Setup the development environment

I use Arduino IDE 2.0 for development, here is how I set it up:
* Open the project (`Nava_v1_028beta\Nava_v1_028beta.ino`)
* Open `Preferences` and paste the following link into `Additional boards manager URLs`: https://mcudude.github.io/MightyCore/package_MCUdude_MightyCore_index.json
* Open the `Board Manager`, search for `MightyCore` and download the package
* Select the `ATmega1284` board
* Open the `Library Manager` and install the `LiquidCrystal` library

You are now ready to develop and compile the project.

## Compile and upload the firmware

Here is how I do it using MIDI SysEx:

* Compile and export the source code (`Sketch/Export compiled Binary`). This creates a `build/MightyCore.avr.1284` directory inside your project directory where your compiled binaries are.
* Open a command line interface at the root of the repository and execute the following command (I use Python 2.7 so it probably doesn't work with 3.x right off the bat):

`python tools/hex2sysex/hex2sysex.py -o Nava_v1_028beta/build/MightyCore.avr.1284/firmware.syx Nava_v1_028beta/build/MightyCore.avr.1284/Nava_v1_028beta.ino.with_bootloader.hex -s`
* Open MIDI-OX, set the SysEx buffer size to 64 bytes
* Turn on the Nava with the step buttons 1, 3 and 5 pressed
* Send the `firmware.syx` file to the MIDI input of the Nava (this will take a couple minutes, you should see the step buttons showing the progress)