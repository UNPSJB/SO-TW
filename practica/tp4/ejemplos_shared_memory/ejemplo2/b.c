/* progb.c */

#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int shm_fd, i;
	int *data;

	shm_fd = shm_open("/shm_ej2", O_RDWR | O_CREAT, 0777);
	ftruncate(shm_fd, sizeof(int) * 10);
	data = mmap(NULL, sizeof(int) * 10, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	for(i = 0; i < 10; ++i)
		printf("data[%d] = %d\n", i, data[i]);
}

