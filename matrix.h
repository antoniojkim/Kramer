#ifndef __HEADER__MATRIX
#define __HEADER__MATRIX

#include <stdbool.h>

typedef struct {
    int domain_dim;
    int range_dim;
    double * entries;
} Matrix;

void displayMat(Matrix *);
void clearMat(Matrix *); // for memory purposes

Matrix * randomMat(int domain_dim, int range_dim);
Matrix * eyeMat(int dim);
Matrix * zeroMat(int domain_dim, int range_dim);
Matrix * inputMat(int domain_dim, int range_dim);

bool compareDim(Matrix *, Matrix *);
bool isSquare(Matrix *);
// should probably find a more suitable name for this function
bool commute(Matrix *, Matrix *); // checks if two matrices can be multiplied

#endif //__HEADER__MATRIX