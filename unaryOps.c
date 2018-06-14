#include "unaryOps.h"
#include <stdio.h>

double trace(Matrix *pmat){
    
    double tr = 0.0;
    int m = pmat -> range_dim;
    // need to add check to make sure matrix is not empty matrix
    for (int i = 0; i < pmat -> domain_dim; i++){
        tr += (pmat -> entries)[i * (m + 1)];
    }
    return tr;
}

double determinant(Matrix *p){

    double det;
    if (isSquare(p)){
        if (p -> domain_dim == 1){
            return (p -> entries)[0];
        }else if(p -> domain_dim == 2){
            double a, b, c, d;
            a = (p -> entries)[0];
            b = (p -> entries)[1];
            c = (p -> entries)[2];
            d = (p -> entries)[3];
            return (a * c - b * d);
        }else{
            // something recursive for sure
        }
        
    }
}