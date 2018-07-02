#ifndef __HEADER__POLY
#define __HEADER__POLY

#include <stdbool.h>

typedef struct {

    int degree;
    double *coeffs;

}Polynomial;

Polynomial * newPoly(int degree, double *coeffs);
Polynomial * randomPoly(int degree);
Polynomial * initPolyMem(int degree);

double * roots(Polynomial *);

bool isZeroPoly(Polynomial *);

#endif // __HEADER__POLY
