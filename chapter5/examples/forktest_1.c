// forktest_1.c

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Before fork()\n");

    int rs = fork();

    if (rs < 0)
    {
        printf("fork failed :\\\n");
    }
    else if (rs == 0)
    {
        printf("I am the child (pid: %d)\n", getpid());
    }
    else
    {
        printf("I am the parent of %d (pid: %d)\n", rs, getpid());
    }
    return 0;
}