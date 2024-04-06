// Este programa crea una tuberia y conecta a dos procesos mediante esta tuberia. Como los procesos se
// obtienen mediante exec, en este caso es necesario usar redireccion de entrada-salida para los procesos
// invocados. Para este fin se utiliza dup.
//

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int fd[2];

int main(void)
{

	pipe(&fd[0]);
	if(fork())
	{
		//padre
		close(0);
		dup(fd[0]);
		execl("/usr/bin/grep", "/usr/bin/grep", "fd", NULL);
	}
	else
	{
		//hijo
		close(1);
		dup(fd[1]);
		execl("/usr/bin/cat", "/usr/bin/cat", "/home/marcelo/SO2024/ej5.c", NULL);
	}
}
