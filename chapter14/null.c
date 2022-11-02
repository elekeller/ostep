// null.c
#include <stdio.h>

int main(void)
{
    int *x = NULL;
    printf("%d", *x); // segmentation fault
    return 0;
}