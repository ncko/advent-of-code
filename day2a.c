#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(const int nums[], const int count) {
    int min = nums[0];
    for (int i = 1; i < count; i++) {
        if (nums[i] < min) min = nums[i];
    }
    return min;
}

int main(int argc, char *argv[])
{
    char line[INT8_MAX];
    char *result;
    char *token;
    int i;
    int dimensions[] = { 0, 0, 0 };
    int sides[] = { 0, 0, 0 };
    int total = 0;

    while((result = fgets(line, INT8_MAX, stdin)))
    {
        i = 0;
        token = strtok(line, "x");
        while(token) {
            dimensions[i++] = atoi(token);
            token = strtok(NULL, "x");
        }
        sides[0] = dimensions[0] * dimensions[1];
        sides[1] = dimensions[1] * dimensions[2];
        sides[2] = dimensions[0] * dimensions[2];
        total += 2*sides[0] + 2*sides[1] + 2*sides[2] + min(sides, 3);
    }

    printf("%d\n", total);

    return EXIT_SUCCESS;
}
