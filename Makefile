
all:
	gcc jsonparser.c -o jsonparser

clean:
	rm -f jsonparser.o
	rm -f jsonparser
