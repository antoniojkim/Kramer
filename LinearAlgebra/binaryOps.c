#include "binaryOps.h"
#include <stdlib.h>
#include <stdio.h>

Matrix * add(Matrix *p, Matrix *q){
    
    if (compareDim(p, q)){
        int n = p -> domain_dim;
        int m = p -> range_dim;
        Matrix *sum = zeroMat(n, m);
        double e_ij;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                e_ij = (p -> entries)[i * m + j] + (q -> entries)[i * m + j];
                (sum -> entries)[i * m + j] = e_ij;
            }
        }
        return sum;
    }else{
        return zeroMat(1, 1);
    }
    
}

Matrix * scale(Matrix *p, double scalar){

    Matrix *scaledMat = zeroMat(p -> domain_dim, p -> range_dim);
    if (scalar == 0){
        return scaledMat;
    }else if (scalar == 1){
        return p;
    }else{
        int n = p -> domain_dim;
        int m = p -> range_dim;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                (scaledMat -> entries)[i * m + j] = scalar * (p -> entries)[i * m + j];
            }
        }
        return scaledMat;
    }
}

Matrix * sub(Matrix *p, Matrix *q){

    if (compareDim(p, q)){
        Matrix *qNeg = scale(q, -1);
        return add(p, qNeg);
    }else{
        return zeroMat(1, 1);
    }
}

Matrix * mul(Matrix *p, Matrix *q){

    if (commute(p, q)){

        Matrix *pmul = zeroMat(p -> domain_dim, q -> range_dim);

        int n = pmul -> domain_dim;
        int r = p -> range_dim;
        int m = pmul -> range_dim;
        int ij, ik, kj;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int k = 0; k < r; k++){
                    (pmul -> entries)[i * m + j] += ((p -> entries)[i * r + k] * (q -> entries)[k * m + j]);
                }
            }
        }
        return pmul;
    }else{
        return zeroMat(1, 1);
    }
}