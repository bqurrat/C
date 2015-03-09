all: main

data.o: data.c data.h
	gcc -Wall -c -g data.c

linkedList.o: linkedList.c linkedList.h 
	gcc -Wall -c -g linkedList.c

main.o: main.c
	gcc -Wall -c -g main.c

main: data.o linkedList.o main.o
	gcc -Wall -g data.o linkedList.o main.o -o main

clean:
	rm -f *.o *~ main
