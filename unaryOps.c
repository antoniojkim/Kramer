#include "unaryOps.h"
#include <stdio.h>

double trace(Matrix *pmat){
    // ths function is not working right
    double *entries = pmat -> entries;
    int n = pmat -> domain_dim;
    int m = pmat -> range_dim;
    double tr;

    if (isSquare(pmat)){
        for (int i = 0; i < n; i++){
            tr += *(entries + i * m + i);
        }
        return tr;
    }else{
        // how to make proper error messages
        printf("ERR: dimension mismatch!");
        return 0.0;
    }
}