#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        char *myargs[3];
        // myargs[0] = strdup("wc");   // program: "wc" (word count)
        // myargs[1] = strdup("p3.c");      // argument: file to count
        // execvp(myargs[0], myargs); // runs word count

        myargs[0] = strdup("./process");    // program: "./process" (word count)    ##################
        myargs[1] = strdup("1");            // argument: file to count              ##################
        myargs[2] = NULL;                   // marks end of array                   ### Process  1 ###
        execvp(myargs[0], myargs);          // runs word count                      ##################
        printf("this shouldn’t print out"); //                                      ##################
    }
    else
    { // parent goes down this path (main)
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
               rc, rc_wait, (int)getpid());
    }
    return 0;
}