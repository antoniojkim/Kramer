#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix * eyeMat(int dim){

    Matrix mat, *pmat;
    pmat = &mat;
    double *p;
    p = (double *) malloc(sizeof(double) * dim * dim);
    pmat -> domain_dim = dim;
    pmat -> range_dim = dim;
    for (int i = 0; i < dim; i++){
            *(p + (i * dim) + i) = 1.0;
    }
    pmat -> entries = p;
    return pmat;
}

void displayMat(Matrix *pmat){
    int n = pmat -> domain_dim;
    int m = pmat -> range_dim;
    double * entries = pmat -> entries;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%f", *entries);
            entries += 1;
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
}
