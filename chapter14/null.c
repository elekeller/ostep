// null.c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = (int *)malloc(sizeof(int));

    if (x == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    x = NULL;
    printf("%d", *x); // segmentation fault
    return 0;
}