#!/bin/bash

#WEATHER = ICON 69C

#ICON

rtnow="$(date | awk '{print $4}')"
tnow="${rtnow//[!0-9]/}"
 
rsset="$(curl -s wttr.in?format=%d)"
sset="${rsset//[!0-9]/}"

rsriz="$(curl -s wttr.in?format=%D)"
sriz="${rsriz//[!0-9]/}"

rwicon="$(curl -s wttr.in?format=%C)"
wicon="${rwicon//[[:blank:]]/}"
Clear="Clear"
Sunny="Sunny"

if [ $tnow -gt $sriz ] && [ $tnow -lt $sset ]
then
	icon="$(curl wttr.in?format=%c)"
elif [ $wicon == $Clear ] || [ $wicon == $Sunny ]
then
	MPHAZ="$(curl wttr.in?format=%M)"
	if [ $MPHAZ -lt 2 ]
	then
		icon="🌕"
	elif [ $MPHAZ -lt 7 ]
	then
		icon="🌖"
	elif [ $MPHAZ -lt 10 ]
	then
		icon="🌗"
	elif [ $MPHAZ -lt 13 ]
	then
		icon="🌘"
	elif [ $MPHAZ -lt 14 ]
	then
		icon="🌑"
	elif [ $MPHAZ == 14 ]
	then
		icon="🌚"
	elif [ $MPHAZ -lt 16 ]
	then
		icon="🌑"
	elif [ $MPHAZ -lt 20 ]
	then
		icon="🌒"
	elif [ $MPHAZ -lt 23 ]
	then	
		icon="🌓"
	elif [ $MPHAZ < 26 ]
	then
		icon="🌔"
	else
		icon="🌕"
	fi
else
	icon=""
fi

rctemp="$(curl -s 'wttr.in?m&format=%t')"
rftemp="$(curl -s 'wttr.in?format=%t')"


freeze="31"
ctemp="${rctemp//[!0-9]/}"
ftemp="${rftemp//[!0-9]/}"

if [ $ftemp -lt $freeze ]
then
	temp="- $ctemp"
else
	temp="$ctemp"
fi

printf " %s%s \\n" "$icon " "$temp"


