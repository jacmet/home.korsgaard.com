Garage door controller

HW is Wemos D1 mini
(https://github.com/arendst/Sonoff-Tasmota/wiki/Wemos-D1-Mini) running
Tasmota with a IBA-7612 (http://www.mjicka.com/Manual/7612.pdf)
RFID/keypad controller, two MC-38 magnetic NC switches
(https://www.belchip.by/sitedocs/31153.pdf) for the door open/close
sensors and a relay to trigger the open/close action. As the keypad
controller uses 12V, a Wemos DC power shield is used to power the
Wemos from 12V as well.

The NO output of the door relay of the keypad is connected to GPIO14,
the alarm relay is connected to GPIO13, both pulling the signal to
ground. Each are configured as buttons in Tasmota.

The door open/closed magnetic switches are connected to GPIO5 and
GPIO12, both pulling the signal to ground. Each are configured as
switches in Tasmota.

The relay control is connected to GPIO15. The relay output is
connected in parallel with the garage door open/close button.

The door state is handled by a rule:

on switch3#state=0 do publish2 stat/sonoff-garage/DOOR OPENING endon
on switch3#state=1 do publish2 stat/sonoff-garage/DOOR CLOSED endon
on switch4#state=0 do publish2 stat/sonoff-garage/DOOR CLOSING endon
on switch4#state=1 do publish2 stat/sonoff-garage/DOOR OPEN endon
