#include "binaryOps.h"
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a > b) ? b : a)
Polynomial * addPoly(Polynomial *p, Polynomial *q){

    double *pc = (p -> coeffs);
    double *qc = q -> coeffs;
    
    int max = max((p -> degree), (q -> degree));
    int min = min((p -> degree), (q -> degree));
    Polynomial *s = initPolyMem(max);

    for (int i = 0; i <= max; i++){
        if (i <= min){
            (s -> coeffs)[i] = (p -> coeffs)[i] + (q -> coeffs)[i];
        }
        else{
            (s -> coeffs)[i] = (p -> coeffs)[i];
        }
    }

    return s;

}

Polynomial * subPoly(Polynomial *p, Polynomial *q){

    return addPoly(p, scalePoly(q, -1.0));

}

Polynomial * scalePoly(Polynomial *p, double c){

    Polynomial *sp = initPolyMem((p -> degree));

    for (int i = 0; i <= (p -> degree); i++){
        (sp -> coeffs)[i] = (p -> coeffs)[i] * c;
    }

    return sp;
}