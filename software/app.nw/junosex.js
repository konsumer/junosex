$(function(){
    var midi = require('midi'), input = new midi.input(), output = new midi.output();

    var mapping = require('./mapping');
    var names = mapping.names, vals = mapping.vals, controls = mapping.controls;

    function updateDevices(){
        var i, c = output.getPortCount(), out = '';
        for(i = 0; i < c; i++) {
            if (output.getPortName(i) != "JunoSex"){
                out += '<option value=' + i + '>' + output.getPortName(i) + '</option>';
            }
        }
        $('#device').html(out);
    }
    updateDevices();
    $('#refresh').click(updateDevices);

    // handle device-selection UI
    $('#device').change(function(){
        var val = $(this).val();
        if (val){
            var devId = parseInt($(this).val(), 10);
            output.closePort();
            output.openPort(devId);
        }
    }).change();

    // handle midi input
    input.on('message', function(deltaTime, message) {
        if (message[0] > 175 && message[0] < 192){ // control message
            var d = ($('#type').val() == '106') ? 0 : 1;
            var channel = message[0]-176;
            var cc = message[1];
            var val = message[2];

            // find JUNO control that corresponds to this CC
            var j = -1;
            controls[d].forEach(function(v,i){
                if (v == cc){ j = i; }
            });
            if (j != -1){
                val = Math.floor((vals[d][j]/127) * val);
                $('#out').html(names[d][j] + ' (' + channel + '): ' + val);

                // send sysex for JUNO
                output.sendMessage([0xf0, 0x41, 0x32, channel, j, val, 0xf7]);
            }else{
                $('#out').html('Not Mapped  (' + channel + '): ' + [cc, val]);
            }
        }
        // in addition to sysex, passthrough all messages
        output.sendMessage(message);
    });

    // use localstorage to save select choices, and load when window loads
    $('select').change(function(){
        window.localStorage[this.id] = $(this).val();
    }).each(function(){
        if (window.localStorage[this.id]){
            $(this).val(window.localStorage[this.id]);
        }
    });

    // create virtual MIDI port
    input.openVirtualPort("JunoSex");
});
