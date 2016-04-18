
all:
	gcc examples/simple.c -o simple_test

test:
	gcc examples/simple.c -o simple_test

clean:
	rm -f simple_test.o
	rm -f simple_test
	rm -f examples/simple
	rm -f examples/simple.o
