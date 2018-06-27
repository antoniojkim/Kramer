#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Polynomial * initPolyMem(int n){
    // initializes a polynomial of degree n with zeros for all coefficients
    printf("hello");
    Polynomial *p;
    p -> degree = n;
    p -> coeffs = (double *) malloc((n + 1) * sizeof(double));
    return p;
}


double * roots(Polynomial *p){
    int n = p -> degree;
    double *roots;
    roots = (double *) malloc(sizeof(p -> degree) * sizeof(double));
    switch (n){
        case 1:{
            double m, c;
            c = (p -> coeffs)[0];
            m = (p -> coeffs)[1];
            roots[0] = -(c / m);
            break;
        }
        case 2:{
            double a, b, c, del;
            c = (p -> coeffs)[0];
            b = (p -> coeffs)[1];
            a = (p -> coeffs)[2];
            del = sqrt(pow(b, 2) - 4 * a * c);
            roots[0] = (-b + del) / (2 * a);
            roots[1] = (-b - del) / (2 * a);
            break;
        }
        case 3:
            // cubic formula
            break; 

        default:
            break;
    }

    return roots;
}