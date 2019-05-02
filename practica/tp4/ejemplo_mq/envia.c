#include "commons.h"

int main(){
  
   char * mensaje="HOLA MUNDO\0";
	mq_atributos.mq_flags = 0;
   mq_atributos.mq_maxmsg = 1;
  	mq_atributos.mq_msgsize = sizeof(char)*strlen(mensaje); 
   mq_atributos.mq_curmsgs = 1;

	mqd = mq_open("/mq_ejemplo", O_CREAT | O_RDWR, 0666, &mq_atributos);		

	if(mqd == (mqd_t) -1){
		perror("mq_open");
		exit (-1);
	}

  	if(mq_send(mqd, mensaje, mq_atributos.mq_msgsize, 1) == -1)
		perror("mq_send");

   return 0;
   
   mq_close(mqd);
   mq_unlink("/mq_ejemplo");
}

