#!/bin/sh

result=$(bluetoothctl info 00:14:BE:50:27:A2 | grep "Connected: yes")

if [[ $result ]]; then
	echo "🎧"
else
	echo "🔊"
fi
