#! /bin/bash

if [ $# -eq 0 ]; then
	echo "No argument supplied."
	echo "./test.sh [DATA_STRUCTURE_NAME]"
	exit 1
fi

if [ $1 = 'Array' ]; then
	gcc -fsanitize=undefined -I ./include ./src/DS_Array.c ./test/Test.c ./test/ArrayTests.c -o ./bin/ArrayTests
	./bin/ArrayTests
	rm ./bin/ArrayTests
elif [ $1 = 'Stack' ]; then
	gcc -fsanitize=undefined -I ./include ./src/DS_Stack.c ./test/Test.c ./test/StackTests.c -o ./bin/StackTests
	./bin/StackTests
	rm ./bin/StackTests
elif [ $1 = 'Queue' ]; then
	gcc -fsanitize=undefined -I ./include ./src/DS_Queue.c ./test/Test.c ./test/QueueTests.c -o ./bin/QueueTests
	./bin/QueueTests
	rm ./bin/QueueTests
else
	echo "Unknow command: $1"
fi
