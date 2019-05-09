#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <errno.h>
#include <stdio.h>
#include "comun.h"

int main(void)
{
	mqd_t mqd;
	struct mq_attr atributos;
	unsigned int prio;
	t_miestructura miestructura;

	atributos.mq_flags = 0;
	atributos.mq_maxmsg = 10;
	atributos.mq_msgsize = sizeof(t_miestructura);
	atributos.mq_curmsgs= 0;

	mqd = mq_open("/mq_ver2", O_CREAT | O_RDWR, 0777, &atributos);
	if(mqd == (mqd_t) -1)
		perror("mq_open");

	printf("A\n");
	if(mq_receive(mqd, (char *) &miestructura, sizeof(t_miestructura), &prio) == -1)
		perror("mq_open");
	printf("prioridad = %d\n", prio);
	printf("miestructura.val1 = %d\n", miestructura.val1);
	printf("miestructura.val2 = %s\n", miestructura.val2);
	printf("B\n");

	if(mq_receive(mqd, (char *) &miestructura, sizeof(t_miestructura), &prio) == -1)
		perror("mq_open");
	printf("prioridad = %d\n", prio);
	printf("miestructura.val1 = %d\n", miestructura.val1);
	printf("miestructura.val2 = %s\n", miestructura.val2);
	printf("C\n");
		
}

