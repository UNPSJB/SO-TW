#Esto es un comentario

#Sintaxis de cada regla:
#objetivo: dependencias
#<tab> comandos

#Definicion de variables
BINARY=programa
OBJ = main.o salida.o calculadora.o
LIBS= funciones.h
FLAGS= -g -Wall

#expansion de variables definidas:
#con variables de entorno para referenciar al compilador:
all: $(BINARY)

programa: $(OBJ)
	$(CC) -o $(BINARY) $(OBJ)

main.o: main.c $(LIBS) 
	$(CC) -c $(FLAGS) main.c

salida.o: salida.c $(LIBS)
	$(CC) -c $(FLAGS) salida.c

calculadora.o: calculadora.c $(LIBS)
	$(CC) -c $(FLAGS) calculadora.c

clean:
	rm -rf $(BINARY) $(OBJ)

saludo:
	echo "Hola Mundo"
