all: envia recibe

envia: envia.o
	gcc envia.o -o envia -lrt

envia.o: envia.c
	gcc -c envia.c -o envia.o

recibe: recibe.o
	gcc recibe.o -o recibe -lrt

recibe.o: recibe.c
	gcc -c recibe.c -o recibe.o

clean:
	rm envia recibe *.o
