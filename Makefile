make: build test

build:
	gcc -shared -lm -I ./include ./src/arr.c -o ./bin/arr.so

test:
	gcc -fsanitize=undefined -I ./include ./src/arr.c ./src/test.c ./src/testArr.c -o ./bin/testArr
	./bin/testArr
	rm ./bin/testArr

