// waitpid.c
// waiter.c

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int p = fork();

    if (p < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }
    else if (p == 0) // child
    {
        printf("I am the child\n");
        exit(0);
    }
    else
    {
        int status = 0;
        int rc_waitpid = waitpid(p, &status, WNOHANG);

        printf("rc_waitpid = %d\n", rc_waitpid);
    }

    return 0;
}