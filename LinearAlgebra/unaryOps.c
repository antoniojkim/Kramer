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

double trace(Matrix *pmat){
    
    double tr = 0.0;
    int m = pmat -> range_dim;
    // need to add check to make sure matrix is not empty matrix
    for (int i = 0; i < pmat -> domain_dim; i++){
        tr += (pmat -> entries)[i * (m + 1)];
    }
    return tr;
}

double multiplicativeTrace(Matrix *p){
    if (isSquare(p)){
        double mtr = 1.0;
        for (int i = 0; i < p -> domain_dim; i++){
            mtr *= (p -> entries)[i * (1 + p -> domain_dim)];
        }
        return mtr;
    }else{
        return 0.0; // need to add asserts or errors or something in these parts
    }
}
double determinant(Matrix *p){

    double det;
    if (isSquare(p)){
        if (isLowerTriangular(p) || isUpperTriangular(p)){
            return multiplicativeTrace(p);
        }
        if (p -> domain_dim == 1){
            return (p -> entries)[0];
        }else if(p -> domain_dim == 2){
            double a, b, c, d;
            a = (p -> entries)[0];
            b = (p -> entries)[1];
            c = (p -> entries)[2];
            d = (p -> entries)[3];
            return (a * d - b * c);
        }else{
            // something recursive for sure (leibniz?)
            return 0.0;
        }
        
    }else{
        // someting to add here
        return 0.0;
    }
}