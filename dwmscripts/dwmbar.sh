#!/bin/bash

# HDD | RAM | CPU | UPDATE | WEATHER | AUDIO | DATE

#HDD - dwmdisk.sh

#RAM - dwmram.sh

#CPU - dwmtemp.sh

#UPDATE - dwmupdate.sh

#WEATHER = ICON 69C - dwmweather.sh

#AUDIO - AINT WORKIN :(
#AMUTE="$(pacmd list-sinks | awk 'NR==73{print $2}')"
#if [ $AMUTE == "no" ]
#then
#	ATOKEN=":D"
#else
#	ATOKEN="M"
#fi

#DATE




while true; do
	dwmweather > /home/qwe/code/desktopenvironment/dwmscripts/dwmweather.txt
	dwmupdates > /home/qwe/code/desktopenvrionment/dwmscripts/dwmupdates.txt

	sleep 900s
done &

while true; do
	dwmdisk > /home/qwe/code/desktopenvironment/dwmscripts/dwmdisk.txt

	sleep 30s
done &

while true; do
	WEATHER=$(< /home/qwe/code/desktopenvironment/dwmscripts/dwmweather.txt)
	UPDATES=$(< /home/qwe/code/desktopenvironment/dwmscripts/dwmupdates.txt)
	TEMP=$(dwmtemp)
	RAM=$(dwmram)
	DISK=$(< /home/qwe/code/desktopenvironment/dwmscripts/dwmdisk.txt)
	DATE=$(date +%a\ %b%d\ %R)
	xsetroot -name " $DISK | $RAM | $TEMP | $UPDATES | $WEATHER | $DATE"
	sleep 2s
done &

