#
all: programa

programa: main.o salida.o calculadora.o
	gcc -o programa main.o salida.o calculadora.o

main.o: main.c funciones.h 
	gcc -c main.c

salida.o: salida.c funciones.h
	gcc -c salida.c

clean:
	rm -f programa *.o