PIR motion sensors

2 installations (ES/DK).

HW is Wemos D1 mini
(https://github.com/arendst/Sonoff-Tasmota/wiki/Wemos-D1-Mini-and-HC-SR501-PIR-Motion-Sensor)
running Tasmota with a SR501 PIR motion sensor connected to GPIO14 and
a rule to set a notification to pirweb through a HTTP GET whenever the
PIR sensor triggers:

switch1#state=1 do
  websend [motion.korsgaard.com] /add/{spain,denmark}
endon

Notice that switchmode1 must be set to 1.
