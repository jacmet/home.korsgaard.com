IR receiver controller

HW is Wemos D1 mini
(https://github.com/arendst/Sonoff-Tasmota/wiki/Wemos-D1-Mini) running
Tasmota with a IR receiver connected to GPIO4 and a relay shield.
The relay control is connected to GPIO1. The relay output is
used to enable/disable the USB power output (lego lamp).

The IR receive logic is handled by a rule:

ON IrReceived#Hash=0x2FFEA610 DO POWER TOGGLE ENDON
ON IrReceived#Hash=0x67228B44 DO publish cmnd/sonoff-ir/PURPLE TOGGLE ENDON
ON IrReceived#Hash=0x78653B0E DO publish cmnd/sonoff-ir/RED TOGGLE ENDON

Where the hash values correspond to the values received from the nerf
"laser" guns in blue/purple/red mode.
