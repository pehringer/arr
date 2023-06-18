#! /bin/bash

if [ $# -eq 0 ]; then
	echo "No argument supplied."
	echo "./build.sh [DATA_STRUCTURE_NAME]"
	exit 1
fi

if [ $1 = 'Array' ]; then
	gcc -shared -lm -I ./include ./src/CDS_Array.c -o ./bin/CDS_Array.so
	echo "Check bin directory."
elif [ $1 = 'Stack' ]; then
	gcc -shared -lm -I ./include ./src/CDS_Stack.c -o ./bin/CDS_Stack.so
	echo "Check bin directory."
else
	echo "Unknow command: $1"
fi
