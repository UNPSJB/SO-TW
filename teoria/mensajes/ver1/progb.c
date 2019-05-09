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

	atributos.mq_flags = 0;
	atributos.mq_maxmsg = 10;
	atributos.mq_msgsize = sizeof(t_miestructura);
	atributos.mq_curmsgs= 0;

	mqd = mq_open("/mq_ver1", O_CREAT | O_RDWR, 0777, &atributos);
	if(mqd == (mqd_t) -1)
		perror("mq_open");

	printf("A\n");

	if(mq_receive(mqd, NULL, sizeof(t_miestructura), &prio) == -1)
		perror("mq_open");

	printf("B\n");
}

