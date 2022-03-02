#!/bin/bash

hdd="$(df -h | awk 'NR==4{print $4}')"
icon=""
printf " %s%s \\n" "$icon " "$hdd"

