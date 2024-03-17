#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) 
{
    return *(int*) a - *(int*) b;
}


int main(int argc, char *argv[])
{
    char line[INT8_MAX];
    char *result;
    char *token;
    int i;
    int dimensions[] = { 0, 0, 0 };
    int total = 0;

    while((result = fgets(line, INT8_MAX, stdin)))
    {
        i = 0;
        token = strtok(line, "x");
        while(token) {
            dimensions[i++] = atoi(token);
            token = strtok(NULL, "x");
        }

        qsort(dimensions, sizeof(dimensions) / sizeof(int), sizeof(int), cmpfunc);
        total += dimensions[0] * 2 + dimensions[1] * 2;
        total += dimensions[0] * dimensions[1] * dimensions[2];
    }

    printf("Feet of ribbon: %d\n", total);

    return EXIT_SUCCESS;
}
