#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

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

        myargs[0] = strdup("/bin/ls"); // program: "ls" (list directory)
        myargs[1] = strdup("bin");
        myargs[2] = NULL;
        execvp(myargs[0], myargs); // runs list directory
        // execl(myargs[0], myargs[1]);
        printf("this shouldn’t print out"); //
    }
    else
    { // parent goes down this path (main)
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
               rc, rc_wait, (int)getpid());
    }

    return 0;
}