Living room Musicpd Player

GL.iNet 6416A running OpenWrt, configured in wifi client mode.

https://openwrt.org/toh/gl.inet/64xx

USB audio interface and mpd-mini musicpd package. Music files accessed
over NFS, which is mounted at bootup by /etc/rc.local.

USB audio connected to Onkyo TX-SR307 receiver, which has an Onkyo RI
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
