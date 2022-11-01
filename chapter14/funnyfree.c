// funnyfree.c

#include <stdlib.h>

int main(void)
{
    int *i = malloc(5 * sizeof(int));
    free(i[2]);
    return 0;
}