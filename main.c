#include "LinearAlgebra/unaryOps.h"
#include "LinearAlgebra/binaryOps.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Matrix *a = eyeMat(5);
    Matrix *b = zeroMat(5, 3);
    displayMat(a);
    printf("\n");
    displayMat(b);
    printf("\n");

    setEntry(a, 1, 2, 2);
    setEntry(a, 1, 3, 3);
    setEntry(a, 1, 4, 4);
    setEntry(a, 1, 5, 5);

    setEntry(a, 2, 1, 0);
    setEntry(a, 2, 3, 1);
    setEntry(a, 2, 4, 3);
    setEntry(a, 2, 5, 2);

    setEntry(a, 3, 1, 1);
    setEntry(a, 3, 2, 2);
    setEntry(a, 3, 4, 0);
    setEntry(a, 3, 5, 0);

    setEntry(a, 4, 1, 1);
    setEntry(a, 4, 2, 1);
    setEntry(a, 4, 3, 0);
    setEntry(a, 4, 5, -2);

    setEntry(a, 5, 1, 4);
    setEntry(a, 5, 2, 5);
    setEntry(a, 5, 3, -1);
    setEntry(a, 5, 4, 0);
    
    displayMat(a);
    printf("\n");
    
    setEntry(b, 1, 1, 1);
    setEntry(b, 1, 2, 1);
    setEntry(b, 1, 3, 1);

    setEntry(b, 2, 1, 1);
    setEntry(b, 2, 2, 0);
    setEntry(b, 2, 3, 1);

    setEntry(b, 3, 1, 1);
    setEntry(b, 3, 2, 0);
    setEntry(b, 3, 3, 1);

    setEntry(b, 4, 1, 1);
    setEntry(b, 4, 2, 0);
    setEntry(b, 4, 3, 1);

    setEntry(b, 5, 1, 1);
    setEntry(b, 5, 2, 1);
    setEntry(b, 5, 3, 1);

    displayMat(b);
    printf("\n");

    Matrix *ab = mul(a, b);
    printf("%d, %d\n", ab ->domain_dim, ab ->range_dim);
    displayMat(ab);
    printf("\n");

    Matrix *id = eyeMat(5);
    displayMat(id);
    printf("\n");
    
    Matrix *id12 = scale(id, 12);
    displayMat(id12);
    printf("\n");


    return 0;
}