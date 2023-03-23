#! /bin/bash
# 

if [ $# -lt 1 -o $# -gt 2 ]; then
	echo "Cantidad incorrecta de parámetros"
	exit 1
fi

if [ "$1" = "-" ]
	then
		for i in *
		do
            echo "1 for"
			grep "$2" $i > /dev/null || echo $i
		done
	else
		for i in *
		do
            echo "2 for"
			grep "$1" $i > /dev/null && echo $i
		done
fi
