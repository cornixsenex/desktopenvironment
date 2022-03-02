#!/bin/bash

rtemp=$(sensors | awk 'NR==21{print $2}')
temp="${rtemp//[+]/}"
icon=

printf " %s%s \\n" "$icon " "$temp"
