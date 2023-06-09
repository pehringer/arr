#! /bin/bash

if [ $# -eq 0 ]; then
	echo "No argument supplied."
	echo "./build.sh [DATA_STRUCTURE_NAME]"
	exit 1
fi

if [ $1 = 'Array' ]; then
	gcc -shared -lm -I ./include ./src/cds_Array.c -o ./bin/cds_Array.so
	echo "Check bin directory."
else
	echo "Unknow command: $1"
fi
