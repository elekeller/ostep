// data.c

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *data = (int *)malloc(100 * sizeof(int));

    if (data == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    data[100] = 0;

    // free(data);

    return 0;
}