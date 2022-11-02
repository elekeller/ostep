// memory-user.c    *** LATEST VERSION ***

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>

#define MEGABYTE (1024 * 1024)

int finished(struct timeval, long);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "usage: ./memory-user size [mByte] time [sec]\n");
        exit(1);
    }

    int space = atoi(argv[1]) * MEGABYTE;
    int *mem = malloc(space);
    int size = (int)(space / (int)sizeof(int));

    struct timeval now;
    gettimeofday(&now, NULL);
    long time_till = atoi(argv[2]) + now.tv_sec;
    long time_since = 0;

    printf("PID: %d\n", getpid());

    while (finished(now, time_till) == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (mem[i] == 1)
            {
                mem[i] = 0;
            }
            else
            {
                mem[i] = 1;
            }
            if (finished(now, time_till) == 1)
            {
                break;
            }
        }
    }

    free(mem);
    return 0;
}

int finished(struct timeval now, long int time_till)
{
    gettimeofday(&now, NULL);
    if (time_till > now.tv_sec)
    {
        return 0;
    }
    return 1;
}