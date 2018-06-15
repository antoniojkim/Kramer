#ifndef __HEADER_BINARY
#define __HEADER_BINARY

#include "matrix.h"

Matrix * add(Matrix *, Matrix *);
Matrix * sub(Matrix *, Matrix *);
Matrix * scale(Matrix *, double);
Matrix * mul(Matrix *, Matrix *);

Matrix * convolve(Matrix *, Matrix *);

double dot(Matrix *p, Matrix *q);
#endif //__HEADER_BINARY