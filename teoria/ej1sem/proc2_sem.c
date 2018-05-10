/* proc2_sem.c */
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <errno.h>

/* En este ejemplo se ve como dos procesos pueden sincronizar sus acciones utilizando semaforos.
 * Si bien no comparten datos en memoria, sus acciones estan sincronizadas.
 *
 * Para probar este ejemplo debe contar con los archivos proc1_sem.c, proc2_sem.c y Makefile en una carpeta.
 *
 * Compilar con:
 * 
 * make
 * 
 * Ejecutar con:
 * 
 * ./proc1_sem &
 * 
 * Y luego:
 * 
 * ./proc2_sem
 * 
 * Alternativamente se pueden ejecutar ambos procesos con la siguiente invocacion
 *
 * ./proc1_sem & ./proc2_sem
 *
 * (o en el orden inverso)
 *
 * DESAFIO: Modificar uno o ambos programas (tal vez también la inicializacion de los semaforos) de tal forma
 * que al ejecutarlos se vea en pantalla:
 *
 * A
 * 1
 * B
 * 2
 * C
 * 3
 * D
 * 4
 * E
 * 5
 *
 */

int main(void)
{
	sem_t *s1, *s2;

	if((s1 = sem_open("/s1", O_CREAT, 0700, 2)) == SEM_FAILED)
		perror("sem_open(s1)");

	if((s2 = sem_open("/s2", O_CREAT, 0700, 0)) == SEM_FAILED)
		perror("sem_open(s2)");

	sem_wait(s2);
	printf("1\n");
	sem_post(s1);
	sem_wait(s2);
	printf("2\n");
	sem_post(s1);
	sem_wait(s2);
	printf("3\n");
	sem_post(s1);
	sem_wait(s2);
	printf("4\n");
	sem_post(s1);
	sem_wait(s2);
	printf("5\n");
	sem_post(s1);
}

