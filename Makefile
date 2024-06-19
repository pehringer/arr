build:
	gcc -fPIC -shared -I ./include ./src/arr.c -o arr.so

test: build
	gcc -I include ./arr.so ./tests/tests.c -o tests.bin
	./tests.bin
	rm tests.bin

