all: gcd
	./gcd

gcd: gcd.o
	gcc -o gcd gcd.o -g -Wall

gcd.o: gcd.c GNUmakefile
	gcc -c gcd.c -g -Wall -DX=25 -DY=15

clean:
	rm -f gcd gcd.o
