COMPILER = gcc -Wall -pedantic

oop: oop.o Object.o Sub_Object.o
	$(COMPILER) oop.o Object.o Sub_Object.o -o oop

oop.o: oop.c
	$(COMPILER) -c oop.c
Object.o: Object.h Object.c
	$(COMPILER) -c Object.c
Sub_Object.o: Sub_Object.h Sub_Object.c
	$(COMPILER) -c Sub_Object.c