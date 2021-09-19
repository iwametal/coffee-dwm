#!/bin/sh

[ -z $1 ] && exit

barname=$1

if [ X"" = X"$(ps ax|grep "${barname}-complete"|grep -v grep)" ] ; then
	killall $barname.sh 2>&1 >/dev/null
else
	killall ${barname}-complete.sh 2>&1 >/dev/null
fi
