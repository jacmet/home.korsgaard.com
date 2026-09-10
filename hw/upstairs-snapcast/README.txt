SNAPCAST Music upstairs

Originally using openwrt on a glinet GL-MT300N router, a USB soundcard and
a relay for the amplifier controlled by an Arduino pro mini which was
commanded by the glinet over a simple serial protocol.

Replaced 2026/09 by esphome on a hifi-esp32s3 board:

https://lectronz.com/products/hifi-esp32

With the relay controlled from the "ethernet reset" GPIO, available on
the w5500 connector (together with gnd/3v3).

Esphome config based on hifi-esp32-s3-idf-snapclient.yaml from:

https://github.com/sonocotta/esp32-audio-dock/commit/eb19d91eba79887761947d636086b4130583e620
