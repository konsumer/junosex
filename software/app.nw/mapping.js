// maps from JUNO ID to MIDI CC #
// JUNO106 is controls[0]
exports.controls = [
    [0x33,0x31,0x21,0x25,0x20,0x74,0x71,0x75,0x33,0x70,0x39,0x73,0x80,0x76,0x72,0x77],
    [0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x81,0x80,0x21,0x22,0x23,0x24,0x25,0x74,0x71,0x26,0x27,0x28,0x29,0x39,0x30,0x33,0x31,0x73,0x75,0x76,0x77,0x80,0x79,0x72,0x82,0x93,0x6]
];

// value-maps: 0-X
// JUNO106 is vals[0]
exports.vals = [
    [127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127],
    [3, 3, 3, 3, 5, 5, 3, 3, 3, 3, 1, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 12]
];

// JUNO param names
exports.names = [
    ["LFO rate","LFO delay","DCO LFO modulation level","DCO PWM modulation level","Noise level","VCF cutoff level","VCF resonance level","VCF ENV level","VCF LFO modulation level","VCF KYBD modulation level","VCA level","ENV attack rate","ENV decay rate","ENV sustain level","ENV release rate","Sub level"],
    ["DCO Env. Mode (0=Normal, 1=Inverted, 2=Normal-Dynamic, 3=Inv.-Dynamic)","VCF Env. Mode (0=Normal, 1=Inverted, 2=Normal-Dynamic, 3=Dynamic)","VCA Env. Mode (0=Normal, 1=Gate, 2=Normal-Dynamic, 3=Gate-Dynamic)","DCO Wave Pulse (0..3)","DCO Wave Saw (0..5)","DCO Wave Sub (0..5)","DCO Range (0=4', 1=8', 2=16', 3=32')","DCO Sub Level (0..3)","DCO Noise (0..3)","HPF Cutoff (0..3)","Chorus Switch (0=Off, 1=On)","DCO LFO Mod. (0..7F)","DCO ENV Mod. (0..7F)","DCO After Mod. (0..7F)","DCO PWM Depth (0..7F)","DCO PWM Rate (0..7F) 0 = Pulse Width Manual 1..7F = PW LFO Rate","VCF Cutoff (0..7F)","VCF Resonance (0..7F)","VCF LFO Mod. (0..7F)","VCF ENV Mod. (0..7F)","VCF Key Follow (0..7F)","VCF Aftertouch (0..7F)","VCA Level (0..7F)","VCA Aftertouch (0..7F)","LFO Rate (0..7F)","LFO Delay (0..7F)","ENV T1 (0..7F) Attack Time","ENV L1 (0..7F) Attack Level","ENV T2 (0..7F) Break Time","ENV L2 (0..7F) Break Level","ENV T3 (0..7F) Decay Time","ENV L3 (0..7F) Sustain Level","ENV T4 (0..7F) Release Time","ENV Key Follow (0..7F)","Chorus Rate (0..7F)","Bender Range (0..C)"]
];
