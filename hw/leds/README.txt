LED strips controller

HW is Wemos D1 mini
(https://github.com/arendst/Sonoff-Tasmota/wiki/Wemos-D1-Mini) running
Tasmota with 8 LED chains driven through 2x 4 channel IRF540 modules
(https://www.amazon.com/Diymore-Channels-MOSFET-Button-Arduino/dp/B01MRQFYJN). Powered
from 5V, using a XL6009 boost converter
(https://www.openimpulse.com/blog/products-page/product-category/xl6009-dc-dc-step-converter-boost-converter/)
to provide the LED driving voltage.

Pin mapping is:

- GPIO16: Relay 1 (bathroom LEDs, 5V)
- GPIO4:  Relay 2 (stars 5)
- GPIO5:  Relay 3 (stars 4)
- GPIO3:  Relay 4 (stars 3)
- GPIO14: Relay 5 (stars 2)
- GPIO12: Relay 6 (stars 1)
- GPIO13: Relay 7 (back door)
- GPIO15: Relay 8 (stairs)
