#include "binaryOps.h"
#include "unaryOps.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Matrix *id = eyeMat(2);
    int m = id -> range_dim;
    *(id -> entries + 1 * m + 1) = 3.0;
    printf("%f", *(id -> entries + 0 * m + 0));
    printf("\n");
    fflush(stdout);
    printf("%f", *((id -> entries) + 0 * m + 1));
    printf("\n");
    fflush(stdout);
    printf("%f", *((id -> entries) + 1 * m + 0));
    printf("\n");
    fflush(stdout);
    printf("%f", *((id -> entries) + 1 * m + 1));
    printf("\n");
    fflush(stdout);
    return 0;
}