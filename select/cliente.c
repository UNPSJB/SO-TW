/*
    cliente
*/
#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
     
    //Crea socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("No se pudo crear socket");
    }
    puts("Socket creado");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Conecto a servidor remoto
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Conexión fallida. Error");
        return 1;
    }
     
    puts("Conectado...! \n");
     
    //mantengo comunicación
	while(1)
    {
        printf("Ingresar mensaje: ");
        scanf("%s" , message);
         
        //envio la data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Envio fallido");
            return 1;
        }
         
        //Recibo respuesta
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv fallido");
            break;
        }
         
        puts("Respuesta del servidor: ");
        puts(server_reply);
    }
     
    close(sock);
    return 0;
}