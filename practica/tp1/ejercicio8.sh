#!/bin/bash
#
# shellscript

if [ $# -ne 1 ]; then
	echo "uso: $0 <patron> | -h"
	exit 1
fi

if [ $1 = "-h" ]; then
	echo "Texto explicativo."
	exit 0
fi

PATRON=$1

for i in `find ./ -name "*.[hc]"`
do
	echo "--------------"
	echo $i
	grep $PATRON $i
done
