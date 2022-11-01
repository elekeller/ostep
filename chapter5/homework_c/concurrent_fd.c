#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
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

    int p = fork();

    if (p < 0)
    {
        fprintf(stderr, "fork() failed");
        exit(1);
    }
    else if (p == 0)
    {
        char *text = "\nHello World says the child\n";
        int text_length = (strlen(text)) * sizeof(char);
        if (write(fd, text, text_length) != text_length)
        {
            fprintf(stderr, "child write failed");
            exit(1);
        }
    }
    else
    {
        char *text = "\nHello World says the parent\n";
        int text_length = (strlen(text)) * sizeof(char);

        if (write(fd, text, text_length) != text_length)
        {
            fprintf(stderr, "parent write failed");
            exit(1);
        }
    }

    close(fd);
    return 0;
}