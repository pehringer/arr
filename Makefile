build:
	gcc -fPIC -shared -I include src/arr.c -o arr.so

test: build
	gcc -Wl,-rpath=. -I include -L . src/arr.c tests/tests.c -o tests.bin
	./tests.bin
	rm tests.bin

