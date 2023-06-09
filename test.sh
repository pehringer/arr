#! /bin/bash

if [ $# -eq 0 ]; then
	echo "No argument supplied."
	echo "./test.sh [DATA_STRUCTURE_NAME]"
	exit 1
fi

if [ $1 = 'Array' ]; then
	gcc -I ./include ./src/cds_Array.c ./test/Test.c ./test/ArrayTests.c -o ./bin/ArrayTests
	./bin/ArrayTests
	rm ./bin/ArrayTests
else
	echo "Unknow command: $1"
fi
