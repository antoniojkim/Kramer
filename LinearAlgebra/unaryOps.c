#include "unaryOps.h"
#include <stdio.h>


Matrix * transpose(Matrix *p){
    // check if p is not a (0, 0) matrix
    Matrix *transMat = zeroMat(p -> domain_dim, p -> range_dim);
    double a_ji;
    for (int i = 0; i < p -> domain_dim; i++){
        for (int j = 0; j < p -> range_dim; j++){
            a_ji = (p -> entries)[j * (p -> range_dim) + i];
            (transMat -> entries)[i * (p -> range_dim) + j] = a_ji;
        }
    }
    return transMat;
}   

