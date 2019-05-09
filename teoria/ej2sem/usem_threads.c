/* usem_threads.c */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <errno.h>

/* En este ejemplo se ve como dos hilos pueden sincronizar sus acciones utilizando semaforos.
 * Ademas, se usa un unnamed semaphore (semaforo sin nombre), aprovechando el hecho que se cuenta con
 * memoria compartida (en variables globales, o en el heap).
 * Por lo tanto, los hilos pueden usar semaforos (con o sin nombre) para sincronizar sus acciones y
 * acceder ordenadamente a los datos compartidos (memoria compartida).
 *
 * Para probar este ejemplo debe contar con los archivos usem_threads.c y Makefile en una carpeta.
 *
 * Compilar con:
 * 
 * make
 * 
 * Ejecutar con:
 * 
 * ./usem_threads
 * 
 * 
 */

sem_t s1, s2;

void *thread1_code(void *arg)
{
	sem_wait(&s1);
	printf("A\n");
	sem_post(&s2);
	printf("B\n");
	sem_wait(&s1);
	sem_post(&s2);
	sem_wait(&s1);
	printf("C\n");
	sem_post(&s2);
	printf("D\n");
	sem_post(&s2);
	sem_wait(&s1);
	sem_wait(&s1);
	printf("E\n");
	sem_post(&s2);

	pthread_exit((void *) 0);
}

void *thread2_code(void *arg)
{
	sem_wait(&s2);
	printf("1\n");
	sem_post(&s1);
	sem_wait(&s2);
	printf("2\n");
	sem_post(&s1);
	sem_wait(&s2);
	printf("3\n");
	sem_post(&s1);
	sem_wait(&s2);
	printf("4\n");
	sem_post(&s1);
	sem_wait(&s2);
	printf("5\n");
	sem_post(&s1);

	pthread_exit((void *) 0);
}

int main(void)
{
	int retval;
	pthread_t hilos[256];

	if(sem_init(&s1, 0, 2) == -1)
		perror("sem_init(s1)");

	if(sem_init(&s2, 0, 0) == -1)
		perror("sem_init(s2)");

	printf("Presione <ENTER> para continuar\n");
	getchar();

	retval = pthread_create(&hilos[0], NULL, &thread1_code, NULL);
	if(retval != 0)
		exit(1);
	retval = pthread_create(&hilos[1], NULL, &thread2_code, NULL);
	if(retval != 0)
		exit(1);
	pthread_join(hilos[0], NULL);
	pthread_join(hilos[1], NULL);
	printf("Fin del experimento\n");
}

