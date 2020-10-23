#!/bin/sh
# get telenet usage and publish to MQTT

MQTT_HOST=127.0.0.1
MQTT_TOPIC=telenet/usage
MQTT_DELTA_TOPIC=telenet/delta
DOCKER=telenet-usage:latest

TRIES=3
USED=
while [ -z "$USED" -a "$TRIES" != "0" ]; do
    USED=$(docker run --rm $DOCKER $*)
    sleep 1
    TRIES=$(( TRIES - 1 ))
done
[ -n "$USED" ] || exit 1

PREV=$(mosquitto_sub -h $MQTT_HOST -C 1 -t $MQTT_TOPIC 2>/dev/null || echo 0)
DELTA=$(echo $USED $PREV | awk '{ if ($1 >= $2) print $1 - $2; else print $1 }')

mosquitto_pub -h $MQTT_HOST -t $MQTT_TOPIC -r -m "$USED"
mosquitto_pub -h $MQTT_HOST -t $MQTT_DELTA_TOPIC -r -m "$DELTA"
