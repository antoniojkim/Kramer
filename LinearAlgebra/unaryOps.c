#include "unaryOps.h"
#include <stdio.h>


Matrix * transpose(Matrix *p){
    // check if p is not a (0, 0) matrix
    
    // Matrix *transMat = zeroMat(p -> domain_dim, p -> range_dim);
    // double a_ji;
    // for (int i = 0; i < p -> domain_dim; i++){
    //     for (int j = 0; j < p -> range_dim; j++){
    //         a_ji = (p -> entries)[j * (p -> range_dim) + i];
    //         (transMat -> entries)[i * (p -> range_dim) + j] = a_ji;
    //     }
    // }


    int n = p -> domain_dim;
    int m = p -> range_dim;

    Matrix *transMat = zeroMat(n, p -> range_dim);
    double* transMatEntries = (transMat -> entries);
    double* pEntries = (p -> entries);
    
    int in = 0, jm = 0;

    for (int i = 0; i < n; i++){
        jm = 0;
        for (int j = 0; j < m; j++){
            transMatEntries[in + j] = pEntries[jm + i];
            jm += m;
        }
        in += n;
    }
    return transMat;
}   

