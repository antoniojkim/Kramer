#include "binaryOps.h"
#include <stdlib.h>
#include <stdio.h>

Matrix * add(Matrix *p, Matrix *q){
    
    if (compareDim(p, q)){
        Matrix s, *ps;
        ps = &s;
        ps -> domain_dim = p -> domain_dim;
        ps -> range_dim = p -> range_dim;
        ps -> entries = p -> entries; // initialize to one of the matrices
        int m = ps -> range_dim;
        int index;
        for (int i = 0; i < p -> domain_dim; i++){
            for (int j = 0; j < p -> range_dim; j++){
                index = i * m + j;
                *(ps -> entries + index) = *(p -> entries + index) + *(q -> entries + index);
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

Matrix * scale(Matrix *p, double scalar){

    for (int i = 0; i < p -> domain_dim; i++){
        for (int j = 0; j < p -> range_dim; j++){
            *((p -> entries) + (i * (p -> range_dim)) + j) *= scalar;
        }
    }

    return p;

}