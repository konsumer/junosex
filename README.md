# Control Roland Alpha Juno 1, 2, 106 & MKS-50 with MIDI CC, instead of SysEx

All decent MIDI sequencers speak CC, but being able to speak SysEx particular to these synths is harder to come by.  This code, when placed on an ATMEGA8/168/328 will do the conversion for you, and allow your computer/ipad/sequencer to get romantic with your Juno.

There are 2 versions. One is a software implementation, and one is an Arduino-based version. I made several options for putitng it together in either form.

## Software Version

I made a CLI-version, and a GUI version.  The downloads for this project are the GUI version (same code in junosex.nw), or you can use software/junosex in the command-line. To install the CLI dependencies, run this, in the software directory:

    npm install


For the GUI, just download the version for your system, and run it, or download software/junosex.nw and drag it to [node-webkit] runtime.

## Hardware Version

The hardware version can be made with an Arduino and a [MIDI shield] or [MIDI breakout], or you can make it on a custom PCB with an ATMEGA chip, or a [cheap-o USB-to-MIDI adapter] and an ATMEGA328/Arduino.

The [Arduino MIDI Library] is required. I compiled the code in the Arduino IDE.

### Arduino

The arduino/shield route just requires that you put them together, and run the Arduino code (junosex.ino.) This should take about 5 minutes to complete.

### Custom PCB / ATMEGA

Follow the [schematic] to put it together. I will provide better instructions, later. I used [ArduinoISP] running on a [teensy] to program an [ATMEGA8]. I used a [resonator] to be cheap and lazy (rather than a crystal and 2 capacitors.)

If you want it to run on batteries, use a 9V battery and a [7805 regulator].

I made a full [parts list], for mouser, to build what is listed in the schematic. I just picked parts that are cheap and available. Feel free to choose replacements.

### [cheap-o USB-to-MIDI adapter]

If you are using a [cheap-o USB-to-MIDI adapter], you can open it up, and solder the wires direct to TX/RX, and use the power/ground from USB (inside adapter) to make it all simpler/cheaper.

## Modification

Feel free to modify. This thing is super-simple.

Some ideas:
* put RGB LEDs on PWM pins, for cool light-effects when different control messages are sent
* add knobs to change how CCs are interpreted, or set values directly
* Attach [wireless] to it for cheap, so you can hide your computer/sequencer.

[ATMEGA8]: http://www.mouser.com/ProductDetail/Atmel/ATMEGA8-16PU/?qs=7JStj%2fjQ2SHlSx6QootzDTUTMpkFcVaHHuOB6ZSDMnk%3d
[resonator]: http://www.mouser.com/Search/ProductDetail.aspx?R=HWZT-16.00MDvirtualkey52750000virtualkey815-HWZT-16.00MD
[ArduinoISP]: http://arduino.cc/en/Tutorial/ArduinoISP
[Arduino MIDI Library]: http://arduino.cc/playground/Main/MIDILibrary
[wireless]: http://www.sparkfun.com/products/10532
[teensy]: http://www.pjrc.com/store/teensy.html
[cheap-o USB-to-MIDI adapter]: https://www.google.com/search?q=midi+to+usb&tbm=shop&tbs=p_ord:p
[schematic]: https://github.com/konsumer/junosex/raw/master/schematic.png
[7805 regulator]: http://www.mouser.com/ProductDetail/ON-Semiconductor/MC7805CTG/?qs=%252b9%2fcbd0IE0RkDYggsVZtGe3PoqBzrkPO
[parts list]: http://www.mouser.com/ProjectManager/ProjectDetail.aspx?AccessID=fe0a4b4498
[MIDI shield]: https://www.sparkfun.com/products/9595
[MIDI breakout]: https://www.sparkfun.com/products/9598
[node-webkit]: https://github.com/rogerwang/node-webkit
