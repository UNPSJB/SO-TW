#!/bin/bash
#

if [ $# -gt 0 ]; then
	if [ $# -ne 1 -o $1 != "-h" ]; then
		echo "Forma de uso: $0 [-h]"
		exit 1
	fi

	for i in *
	do
		lfn=`echo $i | gawk ' {str = tolower($0);print str }'`
		if [ $lfn != $i ]; then
				mv $i $lfn
		fi
	done
else
	echo "Forma de uso: $0 [-h]"
	exit 1
fi

