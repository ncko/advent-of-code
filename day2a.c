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
    int i, side1, side2, side3, smallest;
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
        side1 = 2 * dimensions[0] * dimensions[1];
        side2 = 2 * dimensions[1] * dimensions[2];
        side3 = 2 * dimensions[0] * dimensions[2];
        sides[0] = side1;
        sides[1] = side2;
        sides[2] = side3;
        smallest = min(sides, 3);
        total += side1 + side2 + side3 + (smallest / 2);
    }

    printf("%d\n", total);

    return EXIT_SUCCESS;
}
