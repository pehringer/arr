build:
	gcc -fPIC -shared -I ./include ./src/arr.c -o ./arr.so

test: build
	gcc -I ./include ./arr.so ./tests/tests.c -o ./tests.bin
	./tests.bin
	rm ./tests.bin

factorial: build
	gcc -I ./include ./arr.so ./examples/factorial.c -o ./factorial.bin
	./factorial.bin
	rm ./factorial.bin
