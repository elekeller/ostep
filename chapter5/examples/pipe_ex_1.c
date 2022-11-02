// pipe_ex_1.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd[2], nbytes;
    pid_t childpid;
    char string[] = "Hello new Process!\n";
    char readbuffer[80];

    pipe(fd);

    if ((childpid = fork()) == -1)
    {
        fprintf("fork");
        exit(1);
    }

    if (childpid == 0) // child
    {
        close(fd[1]);
        nbytes = read(fd[0], readbuffer, sizeof(string) + 1);
    }
    return 0;
}