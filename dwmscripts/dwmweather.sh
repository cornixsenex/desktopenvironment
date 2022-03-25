#!/bin/bash

#WEATHER = ICON 69C

#ICON

rtnow="$(date | awk '{print $4}')"
tnow="${rtnow//[!0-9]/}"
 
rsset="$(curl wttr.in/94133?format=%d)"
sset="${rsset//[!0-9]/}"

rsriz="$(curl wttr.in/94133?format=%D)"
sriz="${rsriz//[!0-9]/}"

rwicon="$(curl wttr.in/94133?format=%C)"
wicon="${rwicon//[[:blank:]]/}"
#Weather Types
Clear="Clear"
Sunny="Sunny"

Fog="Fog"
Overcast="Overcast"
Mist="Mist"


fmoon1=""
fmoon2=""
fmoon3=""

Thunderstorminvicinity="Thunderstorminvicinity"

if [ $tnow -gt $sriz ] && [ $tnow -lt $sset ]
then
	if [ "$wicon" = "$Fog" -o "$wicon" = "$Overcast" -o "$wicon" = "$Thunderstorminvicinity" -o "$wicon" = "$Mist" ]	
	then
		icon=""
	elif [ "$wicon" = "$Sunny" -o "$wicon" = "$Clear" ]
	then
		icon=""
	else
		icon="$(curl wttr.in/94133?format=%c)"
	fi
elif [ $wicon == $Clear ] || [ $wicon == $Sunny ]
then
	MPHAZ="$(curl wttr.in/94133?format=%M)"
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
		icon=""
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

##Temperature - I'm using darksky to get the temperature because wttr.in has some issue rn...I opened an issue on their github and if/when it gets fixed I'll go back to using it but for now I need to know the temperature outside

curl https://darksky.net/forecast/37.7794,-122.4184/si10/en > darksky.html

EX="$(cat darksky.html | grep 'summary swap')"

temp="$(echo $EX | digitextractor)"

rm darksky.html





#rctemp="$(curl -s 'wttr.in?m&format=%t')"
#rftemp="$(curl -s 'wttr.in?format=%t')"
#
#
#freeze="31"
#ctemp="${rctemp//[!0-9]/}"
#ftemp="${rftemp//[!0-9]/}"
#
#if [ $ftemp -lt $freeze ]
#then
#	temp="- $ctemp"
#else
#	temp="$ctemp"
#fi

printf " %s%s \\n" "$icon " "$temp"


