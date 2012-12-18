# Control Roland Alpha Juno 1, 2, 106 & MKS-50 with MIDI CC, instead of SysEx

All decent MIDI sequencers speak CC, but being able to speak SysEx particular to these synths is harder to come by.  This code, when placed on an ATMEGA8/168/328 will do the conversion for you, and allow your computer/ipad/sequencer to get romantic with your Juno.

There are 2 versions. One is a software implementation, and one is an Arduino-based version. I made several options for putting it together in either form.

## Software Version

I  made a CLI-version, and a GUI version.

### command-line

To install the CLI dependencies, run this, in the software directory:

    npm install

You can get help with:

    ./junosex --help

### GUI

I only tested this on Mac, so that is the only platform I included, but the process should be fairly similar. For Mac, just extract software/JunoSex-mac.zip, and run. For other platforms, you can run `npm install` to build MIDI, put the contents of junosex.nw (make package.json be in root) into a zip file and change the extension to `.nw`, which should make it run if you have the [node-webkit] runtime installed. They also have some info on building a stand-alone app on their site.

The build process is the same as CLI, using the software/junosex.nw directory and the [node-webkit] runtime for your system. I had to use `nw-gyp` to make it build the MIDI library for 32bit (a current limitation of [node-webkit]: Mac requires 32bit versions of everything.) but Mac-peeps should be covered with premade zipfile.

## Hardware Version

The hardware version can be made with an Arduino and a [MIDI shield] or [MIDI breakout], or you can make it on a custom PCB with an ATMEGA chip, or a [cheap-o USB-to-MIDI adapter] and an ATMEGA/Arduino.

The [Arduino MIDI Library] is required. I compiled the code in the Arduino IDE.

### Arduino

The arduino/shield route just requires that you put them together, and run the Arduino code (junosex.ino.) This should take about 5 minutes to complete.

### Custom PCB / ATMEGA

Follow the [schematic] to put it together. I will provide better instructions, later. I used [ArduinoISP] running on a [teensy] to program an [ATMEGA8]. I used a [resonator] to be cheap and lazy (rather than a crystal and 2 capacitors.)

If you want it to run on batteries, use a 9V battery and a [7805 regulator].

I made a full [parts list], for mouser, to build what is listed in the schematic. I just picked parts that are cheap and available. Feel free to choose replacements.

### [cheap-o USB-to-MIDI adapter]

If you are using a [cheap-o USB-to-MIDI adapter], you can open it up, and solder the wires direct to TX/RX, and use the power/ground from USB (inside adapter) to make it all simpler/cheaper.

### Modification

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
