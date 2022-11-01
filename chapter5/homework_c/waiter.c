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
        int p_1 = fork();
        int wait_child = wait(NULL);

        printf("wait_child = %d\n", wait_child);
    }
    else
    {
        int rc_wait = wait(NULL);

        printf("rc_wait = %d\n", rc_wait);
        printf("pid = %d, child_pid = %d\n", getpid(), p);
    }

    return 0;
}