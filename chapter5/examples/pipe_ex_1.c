// pipe_ex_1.c

#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>

int main(void)
{
    int fd[2], nbytes;
    pid_t childpid;
    char string[] = "Hello new Process!\n";
    char readbuffer[80];

    pipe(fd);

    if ((childpid = fork()) == -1)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }

    if (childpid == 0) // child
    {
        close(fd[1]);
        nbytes = read(fd[0], readbuffer, sizeof(string) + 1);
        printf("Received string: %s", readbuffer);
        exit(0);
    }
    else
    {
        close(fd[0]);
        write(fd[1], string, strlen(string) +  1);
        wait(0); // wait for child(ren)
    }
    return 0;
}