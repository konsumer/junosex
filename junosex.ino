/*

Adds CC messages to sysex params for Roland Alpha Juno 1, 2, 106 & MKS-50 Control

See here for info about available sysex params:
http://www.vintagesynth.com/roland/sysex.php

Hardware:

ATMEGA8/168/328 chip pins:

2 (RX) -> photocoupler -> midi-in       
3 (TX) -> midi-out
9 & 10 (OSC): 16MHz resonator
19 (D13) - optional status LED

*/

#include <MIDI.h>

// if you have a Roland Juno 106, uncomment this
//#define JUNO106

// param-count
#ifdef JUNO106
  #define PCOUNT 16
#else
  #define PCOUNT 36
#endif

// this is the map of midi controls to Sysex controls.
// key is midi CC#, val is Juno param #
byte control_map[127] = {0xFF};

// this is the list of scale vals for controls that are not 0..7F
// it's just a list of the "high" number
// key is Juno param #, val is top-number in scale
byte val_map[PCOUNT] = {0x7F};

// optional status indicator
#define LED_PIN 13

// generic iterator
byte i = 0;

// value to send to Juno param
byte val = 0;

// scale to use in sysex
float multiplier = 0;

void HandleControlChange (byte channel, byte number, byte value){      
  if (control_map[number] != 0xFF){
    // forward control message to sysex
    digitalWrite(LED_PIN, HIGH);
    
    // scale value to proper range
    multiplier = (val_map[control_map[number]]/127.0);
    val = multiplier * value;
    
    #ifdef JUNO106
      byte msg[5] = {0x41, 0x32, channel-1, control_map[number], val};
    #else
      byte msg[8] = {0x41, 0x36, channel-1, 0x23, 0x20, 0x01, control_map[number], val};
    #endif
    
    MIDI.sendSysEx(sizeof(msg), msg);
    digitalWrite(LED_PIN, LOW);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // setup mappings
  #ifdef JUNO106
  
    // LFO rate
    control_map[0x33] = 0x00;
    val_map[0x00] = 0x7F;
    
    // LFO delay
    control_map[0x31] = 0x01;
    val_map[0x01] = 0x7F;
    
    // DCO LFO modulation level
    control_map[0x21] = 0x02;
    val_map[0x02] = 0x7F;
    
    // DCO PWM modulation level
    control_map[0x25] = 0x03;
    val_map[0x03] = 0x7F;
    
    // Noise level
    control_map[0x20] = 0x04;
    val_map[0x04] = 0x7F;
    
    // VCF cutoff level
    control_map[0x74] = 0x05;
    val_map[0x05] = 0x7F;
    
    // VCF resonance level
    control_map[0x71] = 0x06;
    val_map[0x06] = 0x7F;
    
    // VCF ENV level
    control_map[0x75] = 0x07;
    val_map[0x07] = 0x7F;
    
    // VCF LFO modulation level
    control_map[0x33] = 0x08;
    val_map[0x08] = 0x7F;
    
    // VCF KYBD modulation level
    control_map[0x70] = 0x09;
    val_map[0x09] = 0x7F;
    
    // VCA level
    control_map[0x39] = 0x0a;
    val_map[0x0a] = 0x7F;
    
    // ENV attack rate
    control_map[0x73] = 0x0b;
    val_map[0x0b] = 0x7F;
    
    // ENV decay rate
    control_map[0x80] = 0x0c;
    val_map[0x0c] = 0x7F;
    
    // ENV sustain level
    control_map[0x76] = 0x0d;
    val_map[0x0d] = 0x7F;
    
    // ENV release rate
    control_map[0x72] = 0x0e;
    val_map[0x0e] = 0x7F;
    
    // Sub level
    control_map[0x77] = 0x0f;
    val_map[0x0f] = 0x7F;

  #else
    // DCO Env. Mode (0=Normal, 1=Inverted, 2=Normal-Dynamic, 3=Inv.-Dynamic)
    control_map[0x12] = 0x00;
    val_map[0x00] = 3;

    // VCF Env. Mode (0=Normal, 1=Inverted, 2=Normal-Dynamic, 3=Dynamic)
    control_map[0x13] = 0x01;
    val_map[0x01] = 3;

    // VCA Env. Mode (0=Normal, 1=Gate, 2=Normal-Dynamic, 3=Gate-Dynamic)
    control_map[0x14] = 0x02;
    val_map[0x02] = 3;

    // DCO Wave Pulse (0..3)
    control_map[0x15] = 0x03;
    val_map[0x03] = 3;

    // DCO Wave Saw (0..5)
    control_map[0x16] = 0x04;
    val_map[0x04] = 5;

    // DCO Wave Sub (0..5)
    control_map[0x17] = 0x05;
    val_map[0x05] = 5;

    // DCO Range (0=4', 1=8', 2=16', 3=32')
    control_map[0x18] = 0x06;
    val_map[0x06] = 3;

    // DCO Sub Level (0..3)
    control_map[0x19] = 0x07;
    val_map[0x07] = 3;

    // DCO Noise (0..3)
    control_map[0x20] = 0x08;
    val_map[0x08] = 3;

    // HPF Cutoff (0..3)
    control_map[0x81] = 0x09;
    val_map[0x09] = 3;

    // Chorus Switch (0=Off, 1=On)
    control_map[0x80] = 0x0A;
    val_map[0x0A] = 1;

    // DCO LFO Mod. (0..7F)
    control_map[0x21] = 0x0B;
    val_map[0x0B] = 0x7F;

    // DCO ENV Mod. (0..7F)
    control_map[0x22] = 0x0C;
    val_map[0x0C] = 0x7F;

    // DCO After Mod. (0..7F)
    control_map[0x23] = 0x0D;
    val_map[0x0D] = 0x7F;

    // DCO PWM Depth (0..7F)
    control_map[0x24] = 0x0E;
    val_map[0x0E] = 0x7F;

    // DCO PWM Rate (0..7F) 0 = Pulse Width Manual 1..7F = PW LFO Rate
    control_map[0x25] = 0x0F;
    val_map[0x0F] = 0x7F;

    // VCF Cutoff (0..7F)
    control_map[0x74] = 0x10;
    val_map[0x10] = 0x7F;

    // VCF Resonance (0..7F)
    control_map[0x71] = 0x11;
    val_map[0x11] = 0x7F;

    // VCF LFO Mod. (0..7F)
    control_map[0x26] = 0x12;
    val_map[0x12] = 0x7F;

    // VCF ENV Mod. (0..7F)
    control_map[0x27] = 0x13;
    val_map[0x13] = 0x7F;

    // VCF Key Follow (0..7F)
    control_map[0x28] = 0x14;
    val_map[0x14] = 0x7F;

    // VCF Aftertouch (0..7F)
    control_map[0x29] = 0x15;
    val_map[0x15] = 0x7F;

    // VCA Level (0..7F)
    control_map[0x39] = 0x16;
    val_map[0x16] = 0x7F;

    // VCA Aftertouch (0..7F)
    control_map[0x30] = 0x17;
    val_map[0x17] = 0x7F;

    // LFO Rate (0..7F)
    control_map[0x33] = 0x18;
    val_map[0x18] = 0x7F;

    // LFO Delay (0..7F)
    control_map[0x31] = 0x19;
    val_map[0x19] = 0x7F;

    // ENV T1 (0..7F) Attack Time
    control_map[0x73] = 0x1A;
    val_map[0x1A] = 0x7F;

    // ENV L1 (0..7F) Attack Level
    control_map[0x75] = 0x1B;
    val_map[0x1B] = 0x7F;

    // ENV T2 (0..7F) Break Time
    control_map[0x76] = 0x1C;
    val_map[0x1C] = 0x7F;

    // ENV L2 (0..7F) Break Level
    control_map[0x77] = 0x1D;
    val_map[0x1D] = 0x7F;

    // ENV T3 (0..7F) Decay Time
    control_map[0x80] = 0x1E;
    val_map[0x1E] = 0x7F;

    // ENV L3 (0..7F) Sustain Level
    control_map[0x79] = 0x1F;
    val_map[0x1F] = 0x7F;

    // ENV T4 (0..7F) Release Time
    control_map[0x72] = 0x20;
    val_map[0x20] = 0x7F;

    // ENV Key Follow (0..7F)
    control_map[0x82] = 0x21;
    val_map[0x21] = 0x7F;

    // Chorus Rate (0..7F)
    control_map[0x93] = 0x22;
    val_map[0x22] = 0x7F;

    // Bender Range (0..C)
    control_map[0x6] = 0x23;
    val_map[0x23] = 0xC;
  #endif
  
  // you could also listen on just one channel, if you have a lot of devices chatting CCs on other channels
  MIDI.begin();
  MIDI.setHandleControlChange(HandleControlChange);
  
  // blink LED to say "hello"
  for (i=0; i<4; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}

void loop() {
  MIDI.read();
}
