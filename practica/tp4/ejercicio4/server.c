#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#undef max
#define max(x,y) ((x) > (y) ? (x) : (y))

int connection_handler(int sfd)
{
	int nbytes, i;
	char buffer[256];

	nbytes = read(sfd, buffer, 256);
	buffer[nbytes] = 0;
	printf("Mensaje del cliente: %s\n", buffer);

	for(i = 0; i < nbytes; ++i)
		buffer[i] = toupper(buffer[i]);
	buffer[nbytes] = 0;

	write(sfd, buffer, nbytes);
	return 0;
}

int main(void)
{
	struct sockaddr_un address;
	int sfd, sfd1, sfd2;
	socklen_t address_length;
	fd_set rfds;
	int nfds, r;

	sfd = socket(PF_UNIX, SOCK_STREAM, 0);
	if(sfd < 0)
	{
		perror("socket()");
		exit(EXIT_FAILURE);
	}

	unlink("./demo_socket");

	/* poner a 0 la memoria */
	memset(&address, 0, sizeof(struct sockaddr_un));

	address.sun_family = AF_UNIX;
	sprintf(address.sun_path, "./demo_socket");

	if(bind(sfd, (struct sockaddr *) &address,
			      sizeof(struct sockaddr_un)) != 0)
	{
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	if(listen(sfd, 1) != 0)
	{
		perror("listen()");
		exit(EXIT_FAILURE);
	}

	sfd1 = accept(sfd, (struct sockaddr *) &address, &address_length);
	if(sfd1 == -1)
		perror("accept() 1");

	sfd2 = accept(sfd, (struct sockaddr *) &address, &address_length);
	if(sfd1 == -1)
		perror("accept() 2");

	nfds = max(sfd1, sfd2);
	while(1)
	{
		FD_ZERO(&rfds);
		FD_SET(sfd1, &rfds);
		FD_SET(sfd2, &rfds);

		r = select(nfds + 1, &rfds, NULL, NULL, NULL);

		if (r == -1 && errno == EINTR)
			continue;

		if (r == -1)
		{
			perror("select()");
			exit(EXIT_FAILURE);
		}

		if (FD_ISSET(sfd1, &rfds))
			connection_handler(sfd1);

		if (FD_ISSET(sfd2, &rfds))
			connection_handler(sfd2);
			
	}

	close(sfd1);
	close(sfd2);
	close(sfd);
	unlink("./demo_socket");
}

