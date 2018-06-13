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

Matrix * zeroMat(int domain_dim, int range_dim){

    Matrix mat, *pmat;
    pmat = &mat;
    pmat -> domain_dim = domain_dim;
    pmat -> range_dim = range_dim;
    // make sure when indexing, that n = domain_dim and m = range_dim proper indexing
    pmat -> entries = (double *) calloc(domain_dim * range_dim, sizeof(double));
    return pmat;

}

void displayMat(Matrix *pmat){
    double *entries = pmat -> entries;
    int n = pmat -> domain_dim;
    int m = pmat -> range_dim;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf(" %6.2f ", *(entries + (i * m) + j));
        }
        printf("\n");
        fflush(stdout);
    }
    fflush(stdout);
}
