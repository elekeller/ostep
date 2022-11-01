#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int pid = atoi(argv[1]);

    printf("##################\n");
    printf("##################\n");
    printf("### Process %2d ###\n", pid);
    printf("##################\n");
    printf("##################\n");

    return 0;
}