// vector.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct vector
{
    int length;
    int *values;
};

typedef struct vector vector;

vector create(int length)
{
    vector vec;
    vec.length = length;
    vec.values = (int *)calloc(length, sizeof(int));
    return vec;
}

void addentry(vector vec, int pos, int value)
{
    if (pos > vec.length)
    {
        printf("realloc()\n");
        vec.values = (int *)realloc(vec.values, pos * sizeof(int));
        for (int i = vec.length; i < pos; i++)
        {
            vec.values[i] = 0;
        }
        vec.length = pos;
    }
    vec.values[pos] = value;
}

int get(vector vec, int pos)
{
    if (0 > pos || pos > vec.length)
    {
        fprintf(stderr, "Index out of Bounds\n");
        return 0;
    }
    return vec.values[pos];
}

void printvec(vector vec)
{
    for (int i = 0; i < vec.length; i++)
    {
        printf("[%d] %d\n", i, vec.values[i]);
    }
}

void removevec(vector vec)
{
    vec.length = 0;
    free(vec.values);
}

int main(void)
{
    printf("### Vector app ###\n");
    printf("How many entries do you want to have? ");
    char *len = malloc(8 * sizeof(char));
    scanf("%s", len);
    vector v = create(atoi(len));
    free(len);

    for (int i = 0; i < v.length; i++)
    {
        char *buf = calloc(8, sizeof(char));
        printf("v[%d] = ", i);
        scanf("%s", buf);
        addentry(v, i, atoi(buf));
        free(buf);
    }

    printvec(v);
    removevec(v);
    return 0;
}