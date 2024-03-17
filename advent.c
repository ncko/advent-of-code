#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "advent.h"

void die(const char *msg)
{
    if (errno) {
        perror(msg);
    } else {
        fprintf(stderr, "%s\n", msg);
    }
    
    exit(1);
}
