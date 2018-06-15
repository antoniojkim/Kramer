#include "LinearAlgebra/unaryOps.h"
#include "LinearAlgebra/binaryOps.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Matrix *id = eyeMat(10);
    displayMat(id);
    printf("\n");
    Matrix *p = zeroMat(2, 1);
    (p -> entries)[0] = 2.0;
    (p -> entries)[1] = 1.0;
    displayMat(p);
    printf("\n");
    Matrix *q = zeroMat(1, 2);
    (q -> entries)[0] = -1.0;
    (q -> entries)[1] = 8.0;
    displayMat(q);
    printf("\n");
    Matrix *r = mul(p, q);
    displayMat(r);
    printf("\n");
    swapRows(r, 1, 2);
    displayMat(r);
    printf("\n");
    swapCols(r, 1, 2);
    displayMat(r);
    printf("\n");
    return 0;
}