#ifndef __HEADER__MATRIX
#define __HEADER__MATRIX

#include <stdbool.h>

typedef struct {
    int domain_dim;
    int range_dim;
    double * entries;
} Matrix;

void displayMat(Matrix *);

Matrix * randomMat(int domain_dim, int range_dim);
Matrix * eyeMat(int dim);
Matrix * zeroMat(int domain_dim, int range_dim);
Matrix * inputMat(int domain_dim, int range_dim);

Matrix * add(Matrix *, Matrix *);
Matrix * sub(Matrix *, Matrix *);
Matrix * scale(double, Matrix *);
Matrix * mul(Matrix *, Matrix *);
Matrix * transpose(Matrix *);
Matrix * convolution(Matrix *, Matrix *);

double trace(Matrix *);
double determinant(Matrix *);

bool compareDim(Matrix *, Matrix *);
bool isSquare(Matrix *);
#endif //__HEADER__MATRIX