#ifndef __HEADER_BINARY
#define __HEADER_BINARY

#include "matrix.h"

Matrix * addMat(Matrix *, Matrix *);
Matrix * subMat(Matrix *, Matrix *);
Matrix * scaleMat(Matrix *, double);
Matrix * mulMat(Matrix *, Matrix *);

Matrix * convolveMat(Matrix *, Matrix *);

double dotMat(Matrix *p, Matrix *q);
#endif //__HEADER_BINARY