DSMR (P1) electricity monitoring

Using esphome on a esp32-c3 "super mini" board:
https://www.sudo.is/docs/esphome/boards/esp32c3supermini/

P1 pinout:
1: 5V        -> 5V input
2: RTS       -> 5V input
3: Data GND  -> GND
4: N/C
5: TX        -> GPIO10, 2K2 pullup to 3V3
6: Power GND -> GND

Baudrate is 115200bps. Port is through optocoupler, so inverted. The
esp32-c3 has inversion support on the input, so we only need a 2K2 pullup to
3V3. Power budget is quite limited (250mA), so add a 470uF cap between GND
and 5V.

Esphome config based on https://github.com/zuidwijk/dsmr/blob/main/slimmelezer-be.yaml
