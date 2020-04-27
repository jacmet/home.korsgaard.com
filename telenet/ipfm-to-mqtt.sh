#!/bin/sh
# find latest ipfm log and publish to MQTT in JSON format
set -e

IPFM_LOGS=/var/log/ipfm
MQTT_HOST=127.0.0.1
MQTT_TOPIC=telenet/per-host

LATEST=$(find $IPFM_LOGS -type f -printf '%T@ %p\n' | sort -rn | head -n1 | cut -f2 -d' ')

# massage to an easier parsable format using awk
# <total-1> <host-1>
# ..
# <total-n> <host-n>
# <total> total
# with total* in MB
#
# and finally convert to json

awk '/^[^#]/ { SUM += $4; HOST=$1; \
	       sub(/\.be\.48ers\.dk/, "", HOST); printf "%.2f %s\n", $4/1000000, HOST } \
	       END { printf "%.2f total\n", SUM/1000000 }' $LATEST | sort -nr | \
    jq --raw-input --slurp 'split("\n")[:-1]|map({key: (.|split(" ")[1]), value: (.|split(" ")[0])})|from_entries' | \
    mosquitto_pub -h $MQTT_HOST -t $MQTT_TOPIC -r -s
