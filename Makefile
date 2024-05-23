make: build test

build:
	gcc -shared -lm -I include src/arr.c -o arr.so

test:
	gcc -fsanitize=undefined -I include src/arr.c src/test.c src/testArr.c -o testArr.bin
	./testArr.bin
	rm testArr.bin

