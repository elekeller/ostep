// hello_goodbye.c

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv)
{
    char *hello = "hello";
    char *gdbye = "goodbye";

    int pid = getpid();
    int p = fork();
    kill(pid, SIGTSTP); //                  // KILL
    printf("hello\b\b\b\b\b\b\b\b\n\n");
    if (p < 0)
    {
        fprintf(stderr, "fork failed");
        exit(1);
    }

    if (p != 0)
    {
        // sleep(1);                        // SLEEP
        printf("%s\n", gdbye);
    }
    else
    {

        printf("%s\n", hello);
        kill(pid, SIGCONT); //              // KILL
        // signal(SIGINT,)
    }

    return 0;
}