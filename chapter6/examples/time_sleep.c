// time_sleep.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sleeptime;
    if (argc == 1)
    {
        sleeptime = 0;
    }
    else
    {
        sleeptime = atoi(argv[1]);
    }
    printf("sleeptime = %d\n", sleeptime);
    struct timeval current_time;
    int start;
    gettimeofday(&current_time, NULL);
    start = (int)current_time.tv_sec;
    sleep(sleeptime);
    gettimeofday(&current_time, NULL);
    int seconds = (int)current_time.tv_sec - start;
    printf("actual time: %d\n", seconds);
}