#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Matrix *id = eyeMat(2);
    Matrix *iid = eyeMat(2);
    displayMat(id);
    double tr = trace(iid);
    printf("trace: %f", tr);
    return 0;
}