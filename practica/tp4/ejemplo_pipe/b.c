#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ARCHIVO_PIPE "MiPipe"

int main(void){
	int fd;
	char buffer[80];
	int leidos;

	
	//Abrir el pipe para lectura-escritura
	if ( (fd=open(ARCHIVO_PIPE,O_RDWR)) <0) {
		perror("Error open");
		exit(-1);
	}

	//leer del pipe
	leidos=read(fd,buffer,80);

	printf("\nMensaje recibido: %s\n", buffer);

	close(fd);
	
	return 0;
}