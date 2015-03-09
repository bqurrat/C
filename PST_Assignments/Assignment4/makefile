all: main

main: random.o hw4.o main.o
	gcc -Wall random.o hw4.o main.o -o main

random.o: random.c
	gcc -Wall -c random.c

hw4.o: hw4.c
	gcc -Wall -c hw4.c

main.o: main.c
	gcc -Wall -c main.c
	
clean:
	rm *.o main


