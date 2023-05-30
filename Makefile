Build_Array:
	@gcc -shared -lm -I ./include ./src/cds_Array.c -o ./bin/cds_Array.so
	@echo "Check bin directory."

Test_Array:
	@gcc -I ./include ./src/cds_Array.c ./test/Test.c ./test/ArrayTests.c -o ./bin/ArrayTests
	@./bin/ArrayTests
	@rm ./bin/ArrayTests
