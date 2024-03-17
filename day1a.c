#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "advent.h"

int main(void)
{
    char input[UINT16_MAX];
    
    char *result = fgets(input, UINT16_MAX - 1, stdin);
    if (!result) {
        die("Failed reading input file");
    }

    int i = 0;
    int floor = 0;
    char curr = input[i];
    while(curr) {
        if (curr == '(') {
            floor++;
        } else if (curr == ')') {
            floor--;
        }
        curr = input[++i];
    }

    printf("floor: %d\n", floor);

    return EXIT_SUCCESS;
}
