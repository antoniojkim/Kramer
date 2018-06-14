#include "unaryOps.h"
#include "binaryOps.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Matrix *p = zeroMat(2, 1);
    (p -> entries)[0] = 2.0;
    (p -> entries)[1] = 1.0;
    displayMat(p);
    Matrix *q = zeroMat(1, 2);
    (q -> entries)[0] = -1.0;
    (q -> entries)[1] = 8.0;
    displayMat(q);
    Matrix *r = mul(p, q);
    displayMat(r);

    return 0;
}