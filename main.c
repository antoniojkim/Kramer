#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    Matrix *id = eyeMat(2);
    displayMat(id);
    return 0;
}