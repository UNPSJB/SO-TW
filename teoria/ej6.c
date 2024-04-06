// Estos dos procesos usan una tuberia sin invocar a exec, por lo tanto pueden usar el pipe directamente,
// sin redireccionar entrada ni salida y sin usar dup.
//

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int fd[2];
int c;

int main(void)
{

	pipe(&fd[0]);
	if(fork())
	{
		//padre
		while(read(0, &c, 1))
			write(fd[1], &c, 1);
		waitpid(-1, NULL, 0);
	}
	else
	{
		//hijo
		while(read(fd[0], &c, 1))
		{
			c = c - 1;
			write(1, &c, 1);
		}
	}
}
