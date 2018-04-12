#include <unistd.h>
#include <stdio.h>

int fds[2];

int main(void)
{
        pipe(&fds[0]);
        if(fork()) {
                close(1);
                dup(fds[1]);
                execl("/bin/ls", "/bin/ls/", "/etc", NULL);
        } else {
                close(0);
                dup(fds[0]);
                execl("/bin/grep", "/bin/grep" ,"lst", NULL);
        }
}
