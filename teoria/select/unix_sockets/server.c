#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

int connection_handler(int connection_fd)
{
	int nbytes, i;
	char buffer[256];

	while(nbytes = read(connection_fd, buffer, 256))
	{
		buffer[nbytes] = 0;
		printf("Mensaje del cliente: %s\n", buffer);

		// Transformar texto a mayusculas
		for(i = 0; i < nbytes; ++i)
			buffer[i] = toupper(buffer[i]);
		buffer[nbytes] = 0;

		write(connection_fd, buffer, nbytes);
	}
	close(connection_fd);
	return 0;
}

int main(void)
{
	struct sockaddr_un address;
	int socket_fd, connection_fd;
	socklen_t address_length;
	pid_t child;

	socket_fd = socket(PF_UNIX, SOCK_STREAM, 0);
	if(socket_fd < 0)
	{
		printf("socket() fallo\n");
		return 1;
	}

	unlink("./demo_socket");

	/* poner a 0 la memoria */
	memset(&address, 0, sizeof(struct sockaddr_un));

	address.sun_family = AF_UNIX;
	sprintf(address.sun_path, "./demo_socket");

	if(bind(socket_fd,
			      (struct sockaddr *) &address,
			      sizeof(struct sockaddr_un)) != 0)
	{
		perror("bind()");
		return 1;
	}

	if(listen(socket_fd, 1) != 0)
	{
		perror("listen()");
		return 1;
	}
	// Espero file descriptors por cada cliente que se conecta
	while((connection_fd = accept(socket_fd,
			                            (struct sockaddr *) &address,
			                            &address_length)) > -1)
	{
		connection_handler(connection_fd);
		close(connection_fd);
	}

	close(socket_fd);
	unlink("./demo_socket");
	return 0;
}

