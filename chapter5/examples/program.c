#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        return 1;
    }

    int a = 10;

    int p = fork();

    if (p < 0)
    {
        fprintf(stderr, "fork failed");
        exit(0);
    }
    else if (p == 0)
    {
        printf("\nHello, I am the child. a = %d\n", a); // child, a = 5
        printf("now, I will change a to 5\n");
        a = 5;
        printf("a = %d\n", a);
    }
    else
    {
        printf("\nHello, I am the parent. a = %d\n", a); // parent, a = 5
        printf("now, I will change a to 20\n");
        a = 20;
        printf("a = %d\n", a);
    }

    return 0;
}