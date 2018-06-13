#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Matrix *id = eyeMat(2);
    Matrix *iid = eyeMat(2);
    Matrix *sum = add(id, iid);
    displayMat(sum);
    return 0;
}