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

Matrix * add(Matrix *p, Matrix *q){
    
    if (compareDim(p, q)){
        Matrix s, *ps;
        ps = &s;
        ps -> domain_dim = p -> domain_dim;
        ps -> range_dim = p -> range_dim;
        ps -> entries = p -> entries; // initialize to one of the matrices
        for (int i = 0; i < p -> domain_dim; i++){
            for (int j = 0; j < p -> range_dim; j++){
                *(ps -> entries) = *(p -> entries) + *(q -> entries);
                (p -> entries)++;
                (q -> entries)++;
                (ps -> entries)++;
            }
        }

        return ps;
    }else{

        printf("Error dimension mismatch!\n");
        fflush(stdout);
        Matrix *err;
        return err;
    }

}

void displayMat(Matrix *pmat){
    double *entries = pmat -> entries;
    int n = pmat -> domain_dim;
    int m = pmat -> range_dim;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf(" %6.2f ", *(entries + (i * m) + j));
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
    fflush(stdout);
}

double trace(Matrix *pmat){
    // ths function is not working right
    double *entries = pmat -> entries;
    int n = pmat -> domain_dim;
    int m = pmat -> range_dim;
    double tr;

    if (isSquare(pmat)){
        for (int i = 0; i < n; i++){
            tr += *(entries + i * n + i);
        }
        return tr;
    }else{
        // how to make proper error messages
        printf("ERR: dimension mismatch!");
        return 0.0;
    }



}

bool compareDim(Matrix *p, Matrix *q){

    if ((p -> domain_dim == q -> domain_dim) 
        && 
        (p -> range_dim == q -> range_dim)){
            return true;
        }
    else
    {
        return false;
    }
}

bool isSquare(Matrix *p){

    if (p -> domain_dim == p -> range_dim){
        return true;
    }else{
        return false;
    }
}