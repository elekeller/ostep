// pipe.c

#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#include <fcntl.h>

int main(int argc, char **argv)
{
    int p1, p2;
    int fd[2];

    pipe(fd);

    p1 = fork();

    if (p1 < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (p1 == 0) // child:
    {                 //
        close(1);     // close stdin
        dup(fd[1]);   // duplicate
        close(fd[0]);
        close(fd[1]);

        char *ls[3];
        ls[0] = "/bin/ls";
        ls[1] = "ls";
        ls[2] = NULL;

        execvp(ls[0], ls[1]);
    }
    else           // parent:
    {              //
        wait(&p1); // wait for child
        p2 = fork();

        if (p2 < 0)
        {
            fprintf(stderr, "second fork failed");
            exit(1);
        }
        else if (p2 == 0)
        {
            close(0);
            dup(fd[0]);
            close(fd[0]);
            close(fd[1]);

            execl("/bin/sort", "sort", 0, (char *)0);
        }
        else
        {
            wait(NULL);
        }
        return 0;
    }
}