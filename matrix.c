#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix * eyeMat(int dim){

    Matrix *pmat;
    double *pe;
    
    pmat = zeroMat(dim, dim);
    pe = pmat -> entries;
    for (int i = 0; i < dim; i++){
            *(pe + i * (dim + 1)) = 1.0;
    }
    
    return pmat;
}

Matrix * zeroMat(int domain_dim, int range_dim){

    Matrix *pmat;
    pmat = (Matrix *) malloc(sizeof(Matrix));
    pmat -> domain_dim = domain_dim;
    pmat -> range_dim = range_dim;
    
    pmat -> entries = (double *) calloc(domain_dim * range_dim, sizeof(double));
    //memset(&(pmat -> entries), 0.0, sizeof(double) * sizeof(pmat -> entries));
    return pmat;

}

void displayMat(Matrix *pmat){
    double *entries = pmat -> entries;
    int n = pmat -> domain_dim;
    int m = pmat -> range_dim;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf(" %6.2f", *entries);
            entries += 1;
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
    fflush(stdout);
    return;
}

bool compareDim(Matrix *p, Matrix *q){

    if ((p -> domain_dim == q -> domain_dim) && (p -> range_dim == q -> range_dim)){
            return true;
        }
    else
    {
        return false;
    }
}

// works
bool isSquare(Matrix *p){

    if (p -> domain_dim == p -> range_dim){
        return true;
    }else{
        return false;
    }
}