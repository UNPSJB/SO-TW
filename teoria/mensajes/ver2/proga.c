#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "comun.h"

int main(void)
{
	mqd_t mqd;
	struct mq_attr atributos;
	t_miestructura miestructura;

	atributos.mq_flags = 0;
	atributos.mq_maxmsg = 10;
	atributos.mq_msgsize = sizeof(t_miestructura);
	atributos.mq_curmsgs= 0;

	mqd = mq_open("/mq_ver2", O_CREAT | O_RDWR, 0777, &atributos);
	if(mqd == (mqd_t) -1)
		perror("mq_open");

	miestructura.val1 = 7;
	strncpy(miestructura.val2, "Hola Mundo!\n", 13);
	if(mq_send(mqd, (const char *) &miestructura, sizeof(t_miestructura), 3) == -1)
		perror("mq_open");
		
	miestructura.val1 = 11;
	strncpy(miestructura.val2, "Chau Mundo!\n", 13);
	if(mq_send(mqd, (const char *) &miestructura, sizeof(t_miestructura), 5) == -1)
		perror("mq_open");
		
}

