Roomba IR control

HW is Wemos D1 mini
(https://github.com/arendst/Sonoff-Tasmota/wiki/Wemos-D1-Mini) running
Tasmota with a IR transmitter connected to GPIO4. It it installed into
the Roomba home base and powered from the Roomba power supply through
a buck converter.

The Roomba IR protocol is not understood by Tasmota, so it is sent in
raw mode.

All logic is controlled from Home Assistant.
