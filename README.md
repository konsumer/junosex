# Control Roland Alpha Juno 1, 2, 106 & MKS-50 with MIDI CC, instead of SysEx

All decent MIDI sequencers speak CC, but being able to speak SysEx particular to these synths is harder to come by.  This code, when placed on an ATMEGA8/168/328 will do the conversion for you, and allow your computer/ipad/sequencer to get romantic with your Juno.

The [Arduino MIDI Library] is required.

## Hardware

Follow the schematic to put it together. I will provide better instructions, later. I used [ArduinoISP] running on a [teensy] to program an [ATMEGA8]. I used a [resonator] to be cheap and lazy (rather than a crystal and 2 capacitors.)


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
