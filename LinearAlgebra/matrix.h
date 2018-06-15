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
void setEntry(Matrix *, int row, int col, double val);

Matrix * randomMat(int domain_dim, int range_dim);
Matrix * eyeMat(int dim);
Matrix * zeroMat(int domain_dim, int range_dim);
Matrix * inputMat(int domain_dim, int range_dim);
void swapRows(Matrix *, int row1, int row2);
void swapCols(Matrix *, int col1, int col2);

bool compareDim(Matrix *, Matrix *);
bool isSquare(Matrix *);
// should probably find a more suitable name for this function
bool commute(Matrix *, Matrix *); // checks if two matrices can be multiplied
bool isUpperTriangular(Matrix *);
bool isLowerTriangular(Matrix *);
bool isDiagonalMat(Matrix *);

#endif //__HEADER__MATRIX