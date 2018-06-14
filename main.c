#include "LinearAlgebra/unaryOps.h"
#include "LinearAlgebra/binaryOps.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
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
    Matrix *rt = transpose(r);
    displayMat(rt);
    printf("\n");
    (rt -> entries)[2] = 0.0;
    displayMat(rt);
    printf("%i\n", isLowerTriangular(rt));
    //(rt -> entries)[1] = 0.0;
    displayMat(rt);
    printf("%i\n", isUpperTriangular(rt));


    return 0;
}