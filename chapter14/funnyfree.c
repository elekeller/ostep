// funnyfree.c

#include <stdlib.h>

int main(void)
{
    int *i = malloc(5 * sizeof(int));

    if (i == NULL)
    {
        fprintf(stderr, "malloc failed\n");
    }

    free(i[2]);
    return 0;
}