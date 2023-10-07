build: build_array build_stack build_queue

build_array:
	gcc -shared -lm -I ./include ./src/DS_Array.c -o ./bin/DS_Array.so

build_stack:
	gcc -shared -lm -I ./include ./src/DS_Stack.c -o ./bin/DS_Stack.so

build_queue:
	gcc -shared -lm -I ./include ./src/DS_Queue.c -o ./bin/DS_Queue.so

test: test_array test_stack test_queue

test_array:
	gcc -fsanitize=undefined -I ./include ./src/DS_Array.c ./test/Test.c ./test/ArrayTests.c -o ./bin/ArrayTests
	./bin/ArrayTests
	rm ./bin/ArrayTests

test_stack:
	gcc -fsanitize=undefined -I ./include ./src/DS_Stack.c ./test/Test.c ./test/StackTests.c -o ./bin/StackTests
	./bin/StackTests
	rm ./bin/StackTests

test_queue:
	gcc -fsanitize=undefined -I ./include ./src/DS_Queue.c ./test/Test.c ./test/QueueTests.c -o ./bin/QueueTests
	./bin/QueueTests
	rm ./bin/QueueTests
