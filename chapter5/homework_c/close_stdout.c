// close_stdout.c

#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <sys/wait.h>

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
        printf("Child1\n");
        close(STDOUT_FILENO);
        printf("Child2\n"); // doesn't work anymore
    }
    else
    {
        printf("Parent1\n");
        wait(NULL);
        printf("Parent2\n"); // close stdout doesn't affect parent
    }
    return 0;
}