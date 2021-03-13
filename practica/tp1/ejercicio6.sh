#!/bin/bash
# shscript

	toggle="A"
	if [ "$1" = "-p" ]; then
		toggle="B"
  	fi
 	while read line
 	do
 		if [ "$toggle" = "A" ]; then
 			echo $line
 			toggle="B"
 		else
 			toggle="A"
 		fi
	done
