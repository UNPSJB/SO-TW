/*
 * Ejemplo que escribe a shared memory el número 8
 * */
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* Constantes de modos*/
#include <fcntl.h>           /* Constantes O_* */
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int shm_fd;
	int *data;

	shm_fd = shm_open("/shm_ej1", O_RDWR | O_CREAT, 0777);
	ftruncate(shm_fd, sizeof(int));
	data = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	*data = 8; // Escribo 8 en memoria compartida
}

