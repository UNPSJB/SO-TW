/* cons_shm.c */
/*
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <errno.h>
*/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>
#include "prod_cons.h"
#include <semaphore.h>

/* En este ejemplo se ve como dos procesos pueden compartir un espacio de memoria del tamaño de un entero. Aunque el tamaño podria ser cualquier otro y la forma de acceder a esa memoria compartida tambien queda a criterio del programador. Ver en conjunto con prod_shm.c
 * 
 * Compilar con:
 * 
 * gcc -lrt cons_shm.c -o cons_shm
 * gcc -lrt prod_shm.c -o prod_shm
 * 
 * Ejecutar con:
 * 
 * ./prod_shm
 * 
 * Y luego:
 * 
 * ./cons_shm
 * 
 */

void esperaOcupada(void)
{
	unsigned int delay;

	delay = 355350;
	while(delay--);
}

int main(void)
{
	int i, temp, fd;
	mi_buff_t *datos;
	sem_t *mutex;

	fd = shm_open("/primera_shm", O_RDWR | O_CREAT, 0700);
	mutex = sem_open("/primer_sem", O_RDWR | O_CREAT, 0700, 1);
	ftruncate(fd, sizeof(mi_buff_t));
	datos = (mi_buff_t *) mmap(NULL, sizeof(mi_buff_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	for(i = 0; i < 10000; ++i)
	{
		//sem_wait(mutex);
		temp = datos->i;
		--temp;
		esperaOcupada();
		datos->i = temp;
		//sem_post(mutex);
		esperaOcupada();
	}
	printf("(cons) datos->i = %d\n", datos->i);
}

