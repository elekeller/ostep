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

vector *create(int length)
{
    vector *v = (vector *)malloc(sizeof(vector));
    v->length = length;
    v->values = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        v->values[i] = 0;
    }
    return v;
}

void addentry(vector *v, int pos, int value)
{
    if (pos > v->length)
    {
        v->values = (int *)realloc(v->values, pos * sizeof(int));
        for (int i = v->length; i < pos; i++)
        {
            v->values[i] = 0;
        }
        v->values[pos - 1] = value;
        v->length = pos;
    }
}

void printvec(vector *vec)
{
    for (int i = 0; i < vec->length; i++)
    {
        printf("[%d] %d\n", i, vec->values[i]);
    }
}

int main(int argc, char *argv[])
{
    vector *vec;
    int n;

    if (argc <= 1 || n <= 0)
    {
        printf("How many Entries do you want to have?\n");
        char *buf = (char *)malloc(strlen(argv[0]) * sizeof(char));
        scanf("%s", buf);
        n = atoi(buf);
        free(buf);
    }
    else
    {
        n = atoi(argv[1]);
    }

    vec = create(n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        char *buf = (char *)malloc(strlen(argv[0]) * sizeof(char));
        printf("[%d] ", i);
        scanf("%s", buf);
        vec->values[i] = atoi(buf);
        free(buf);
    }

    printf("How many entries do you want to add?\n");
    char *buf = (char *)malloc(strlen(argv[0]) * sizeof(char));
    scanf("%s", buf);
    if (atoi(buf) > 0)
    {
        int n = vec->length + 1;
        for (int i = n; i < n + atoi(buf); i++)
        {
            char *s = (char *)malloc(strlen(argv[0]) * sizeof(char));
            printf("[%d]: ", vec->length);
            scanf("%s", s);
            int z = atoi(s);
            addentry(vec, i, z);
            free(s);
        }
    }
    printf("\nHere's the final vector:\n");
    printvec(vec);
    free(buf);
    free(vec->values);
    free(vec);
}