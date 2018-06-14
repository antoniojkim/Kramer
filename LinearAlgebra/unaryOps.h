#ifndef __HEADER_UNARY
#define __HEADER_UNARY

#include "matrix.h"

Matrix * transpose(Matrix *);
Matrix * invert(Matrix *);

double trace(Matrix *);
double determinant(Matrix *);

#endif //__HEADER_UNARY