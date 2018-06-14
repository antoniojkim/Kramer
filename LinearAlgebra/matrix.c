#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix * eyeMat(int dim){
    
    // add check for dim > 0
    Matrix *id = zeroMat(dim, dim);
    id -> domain_dim = dim;
    id -> range_dim = dim;

    for (int i = 0; i < dim; i++){
        *(id -> entries + i * (dim + 1)) = 1.0;
    }

    return id;
    
}

Matrix * zeroMat(int domain_dim, int range_dim){

    // add check for domain_dim > 0 and range_dim > 0
    Matrix *pmat;
    pmat = (Matrix *) malloc(sizeof(Matrix));
    pmat -> domain_dim = domain_dim;
    pmat -> range_dim = range_dim;
    
    pmat -> entries = (double *) calloc(domain_dim * range_dim, sizeof(double)); // set to zero
    //memset(&(pmat -> entries), 0.0, sizeof(double) * sizeof(pmat -> entries));
    return pmat;

}

void displayMat(Matrix *pmat){
    
    for (int i = 0; i < pmat -> domain_dim; i++){
        for (int j = 0; j < pmat -> range_dim; j++){
            printf("%6.2f", *(pmat -> entries + i * (pmat -> range_dim) + j));
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
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

bool commute(Matrix *p, Matrix *q){

    if (p -> range_dim == q -> domain_dim){
        return true;
    }else{
        return false;
    }
}

bool isLowerTriangular(Matrix *p){

    if (isSquare(p)){
        int n = p -> domain_dim;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if ((p -> entries)[i * n + j] != 0){
                    return false;
                }
            }
        }
        return true;
    }else{
        return false;
    }
}

bool isUpperTriangular(Matrix *p){
    if (isSquare(p)){
        int n = p -> domain_dim;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                if ((p -> entries)[i * n + j] != 0){
                    return false;
                }
            }
        }
        return true;
    }else{
        return false;
    }
    
}

bool isDiagonalMat(Matrix *p){
    if (isUpperTriangular(p) && isLowerTriangular(p)){
        return true;
    }else{
        return false;
    }
}