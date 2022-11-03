// printweirdarray.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = (int *)malloc(100 * sizeof(int));

    arr[3] = 3;
    printf("before free: %d\n", arr[3]);
    free(arr);
    printf("after free: %d\n", arr[3]);

    return 0;
}