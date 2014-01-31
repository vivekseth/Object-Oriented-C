COMPILER = gcc -Wall -pedantic

oop: oop.o Object.o Person.o
	$(COMPILER) oop.o Object.o Person.o -o oop

oop.o: oop.c
	$(COMPILER) -c oop.c
Object.o: Object.h Object.c
	$(COMPILER) -c Object.c
Person.o: Person.h Person.c
	$(COMPILER) -c Person.c
clean: 
	rm oop.o
	rm Object.o
	rm Person.o
	rm oop