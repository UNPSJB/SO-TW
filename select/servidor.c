/*
    Servidor
*/
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
 
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
     
    //Crea socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("No se pudo crear socket");
    }
    puts("Socket creado");
     
    //Prepara estructura sockaddr_in
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bindeo
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //muestro mensaje de error
        perror("bind failed. Error");
			return 1;
    }
    puts("bind hecho");
     
    //Escucho
    listen(socket_desc , 3);
     
    //espero conexiones
    puts("Esperando por conexiones entrantes...");
    c = sizeof(struct sockaddr_in);
     
    //acepto conexines de clientes
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept fallido");
        return 1;
    }
    puts("Conexión aceptada");
     
    //Recibo un mensaje de un cliente
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    {
         printf("Recibí de un cliente: %s\n", client_message);
        //Envio una respuesta al cliente
        write(client_sock , client_message , strlen(client_message));
    }
     
    if(read_size == 0)
    {
        puts("Cliente desconectado");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv fallido");
    }
     
    return 0;
}
