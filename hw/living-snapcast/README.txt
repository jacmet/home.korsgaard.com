Living room Musicpd Player

Originally using openwrt on LL.iNet 6416A, configured in wifi client mode.

https://openwrt.org/toh/gl.inet/64xx

USB audio interface and mpd-mini musicpd package. Music files accessed
over NFS, which is mounted at bootup by /etc/rc.local and USB audio
card. Attiny power from internal connectors and reset controlled by
GPIO.


Replaced 2026/09 by esphome on a hifi-esp32s3 board:

https://lectronz.com/products/hifi-esp32

With the Attiny reset from the "ethernet reset" GPIO, available on
the w5500 connector (together with gnd/3v3).

Esphome config based on hifi-esp32-s3-idf-snapclient.yaml from:

https://github.com/sonocotta/esp32-audio-dock/commit/eb19d91eba79887761947d636086b4130583e620


Audio connected to Onkyo TX-SR307 receiver, which has an Onkyo RI
input for control. RI interface to a attiny85 "digispark" clone, with
simple Arduino code based on Onkyo-RI:

https://github.com/docbender/Onkyo-RI

Attiny85 triggered by toggling nReset (PB5) from GL.iNET GPIO 20, RI
cable connected to PB0 and 5V from internal GL.iNET connector.

The Attiny85 uses the Micronucleus bootloader:

https://github.com/micronucleus/micronucleus/

Which by default waits 6 seconds after reset for USB communication. To
speed up nReset logic, a custom build is used with ENTRY_POWER_ON
entry mode, so it only does this after a cold boot.

The nReset GPIO is triggered from a simple CGI script in
/www/cgi-bin/amp.
