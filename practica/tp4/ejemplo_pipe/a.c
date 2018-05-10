#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define ARCHIVO_PIPE "MiPipe"
#define MENSAJE "Hola proceso consumidor, te saluda proceso a"

int main(int argc, char *argv[]){
	int fd;

	mkfifo(ARCHIVO_PIPE,0666);

	//Intentar abrir para escritura el pipe con nombre
	if( (fd=open(ARCHIVO_PIPE,O_WRONLY)) <0) {
		perror("\nError en open");
		exit(-1);
	}

	//Escribir en el pipe el mensaje
	if( (write(fd,MENSAJE,strlen(MENSAJE)+1)) != strlen(MENSAJE)+1) {
		perror("\nError al escribir en el FIFO");
		exit(-1);
	}

	close(fd);
	return 0;
}