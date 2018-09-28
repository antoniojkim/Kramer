#include "binaryOps.h"
#include <stdlib.h>
#include <stdio.h>

Matrix * addMat(Matrix *p, Matrix *q){
    
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

Matrix * scaleMat(Matrix *p, double scalar){

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

Matrix * subMat(Matrix *p, Matrix *q){

    if (compareDim(p, q)){
        Matrix *qNeg = scaleMat(q, -1);
        return addMat(p, qNeg);
    }else{
        return zeroMat(1, 1);
    }
}

Matrix * mulMat(Matrix *p, Matrix *q){

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

        
        // Matrix *pmul = zeroMat(p -> domain_dim, q -> range_dim);

        // int n = pmul -> domain_dim;
        // int r = p -> range_dim;
        // int m = pmul -> range_dim;
        
        // int im = 0, ir = 0;
        // double * pmul_entries = pmul->entries;
        // double * p_entries = p->entries;
        // double * q_entries = q->entries;

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++){
        //         int km = 0;
        //         double sum = 0;
        //         for (int k = 0; k < r; k++){
        //             sum += p_entries[ir + k] * q_entries[km + j];
        //             km += m;
        //         }
        //         pmul_entries[im + j] = sum;
        //     }

        //     im += m;
        //     ir += r;
        // }
        // return pmul;
    }else{
        return zeroMat(1, 1);
    }
}

double dotMat(Matrix *p, Matrix *q){
    // once again need checks for errors or stupid code calls
    return (mulMat(p, q) -> entries)[0]; // returns first and only entry if dot product
}