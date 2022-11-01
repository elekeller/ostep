// threads.c

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int counter = 0; // shared counter
int loops;                // limit

/*
 * worker increments the value of the shared counter by 1 till it reaches the limit
 */
void *worker(void *arg)
{
    int i;
    for (i = 0; i < loops; i++)
    {
        counter++;
    }
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./threads <value>\n");
        exit(1); // terminates the calling process immediately with status 1
    }

    loops = atoi(argv[1]); // integer from argv[1] is set as limit
    pthread_t p1, p2;      // pthread_t is a data type for a thread
    printf("Initial value: %d\n", counter);

    // creates two worker-threads
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    // threads are like functions running within the same memory space as other functions
    Pthread.join(p1, NULL);
    Pthread.join(p2, NULL);
    printf("Final value     : %d\n", counter);
    return 0;
}