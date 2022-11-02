// read_time.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = open("file.txt", O_RDWR);        // try to open existing file
    if (fd < 0)                               // opening existing file failed
    {                                         //
        close(fd);                            //
        FILE *file = fopen("file.txt", "w");  // create new file
        if (file == NULL)                     //
        {                                     //
            fprintf(stderr, "open() failed"); // file creation failed
            exit(1);
        }
        fclose(file);
    }
    else
    {
        close(fd);
    }

    fd = open("file.txt", O_RDWR);
    char *buf = "Hello World";
    int size = strlen(buf);
    if (write(fd, (void *)buf, size) != size)
    {
        printf("write failed\n");
    }
    void *ptr = (void *)malloc(sizeof(char));

    struct timeval start_time, end_time;
    float cumm = 0;

    int n = 10;
    if (argc > 1 && atoi(argv[1]) > 0)
    {
        n = atoi(argv[1]);
    }

    for (int i = 0; i < n; i++)
    {
        gettimeofday(&start_time, NULL);

        read(fd, ptr, (size_t)0);

        gettimeofday(&end_time, NULL);

        float seconds = (float)end_time.tv_usec - (float)start_time.tv_usec;
        printf("actual time: %f\n", seconds);
        cumm += seconds;
    }

    printf("\nAverage time: %f\n", cumm / (float)n);

    close(fd);
    free(ptr);
    remove("file.txt");
}