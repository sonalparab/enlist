all: enlist.o
	gcc enlist.o -o enlist

enlist.o: enlist.c enlist.h
	gcc -c enlist.c

clean:
	rm *.o
	rm enlist

run: all
	./enlist
