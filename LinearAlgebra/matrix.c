#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix *eyeMat(int dim) {
    // add check for dim > 0
    Matrix *id = zeroMat(dim, dim);
    id->domain_dim = dim;
    id->range_dim = dim;

    for (int i = 0; i < dim; i++) {
        *(id->entries + i * (dim + 1)) = 1.0;
    }

    return id;
}

Matrix *zeroMat(int domain_dim, int range_dim) {
    // add check for domain_dim > 0 and range_dim > 0
    Matrix *pmat;
    pmat = (Matrix *)malloc(sizeof(Matrix));
    pmat->domain_dim = domain_dim;
    pmat->range_dim = range_dim;

    pmat->entries = (double *)calloc(domain_dim * range_dim, sizeof(double));  // set to zero
    // memset(&(pmat -> entries), 0.0, sizeof(double) * sizeof(pmat -> entries));
    return pmat;
}

void swapRows(Matrix *p, int row1, int row2) {
    int n = p->domain_dim;
    int m = p->range_dim;
    double temp;
    if ((0 < row1 && row1 <= n) && (0 < row2 && row2 <= n) && row1 != row2) {
        int r1 = row1 - 1;
        int r2 = row2 - 1;
        for (int i = 0; i < m; i++) {
            temp = (p->entries)[r1 * m + i];
            (p->entries)[r1 * m + i] = (p->entries)[r2 * m + i];
            (p->entries)[r2 * m + i] = temp;
        }
        return;
    }
}
void swapCols(Matrix *p, int col1, int col2) {
    int n = p->domain_dim;
    int m = p->range_dim;
    double temp;
    if ((0 < col1 && col1 <= m) && (0 < col2 && col2 <= m) && col1 != col2) {
        int c1 = col1 - 1;
        int c2 = col2 - 1;
        for (int i = 0; i < n; i++) {
            temp = (p->entries)[c1 + n * i];
            (p->entries)[c1 + i * n] = (p->entries)[c2 + n * i];
            (p->entries)[c2 + i * n] = temp;
        }
        return;
    }
}
void displayMat(Matrix *pmat) {
    printf("{");
    fflush(stdout);
    for (int i = 0; i < pmat->domain_dim; i++) {
        if (i > 0) {
            printf(",\n ");
            fflush(stdout);
        }
        printf("{");
        fflush(stdout);
        for (int j = 0; j < pmat->range_dim; j++) {
            if (j > 0) {
                printf(", ");
                fflush(stdout);
            }
            printf("%6.2f", *(pmat->entries + i * (pmat->range_dim) + j));
            fflush(stdout);
        }
        printf("}");
        fflush(stdout);
    }
    printf("}\n");
    fflush(stdout);
    return;
}

void setEntry(Matrix *p, int row, int col, double val) {
    int n = p->domain_dim;
    int m = p->range_dim;
    if ((0 < row && row <= p->domain_dim) && (0 < col && col <= p->range_dim)) {
        int r = row - 1;
        int c = col - 1;
        (p->entries)[r * (p->range_dim) + c] = val;
        return;
    }
}

inline bool compareDim(Matrix *p, Matrix *q) {
    return (p->domain_dim == q->domain_dim) && (p->range_dim == q->range_dim);
}

inline bool isSquare(Matrix *p) {
    return (p->domain_dim == p->range_dim);
}

inline bool commute(Matrix *p, Matrix *q) {
    return (p->range_dim == q->domain_dim);
}

inline bool isLowerTriangular(Matrix *p) {
    if (isSquare(p)) {
        int n = p->domain_dim;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((p->entries)[i * n + j] != 0) {
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

bool isUpperTriangular(Matrix *p) {
    if (isSquare(p)) {
        int n = p->domain_dim;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((p->entries)[i * n + j] != 0) {
                    return false;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

bool isDiagonalMat(Matrix *p) {
    return (isUpperTriangular(p) && isLowerTriangular(p));
}

double trace(Matrix *pmat) {
    double tr = 0.0;
    int m = pmat->range_dim;
    // need to add check to make sure matrix is not empty matrix
    for (int i = 0; i < pmat->domain_dim; i++) {
        tr += (pmat->entries)[i * (m + 1)];
    }
    return tr;
}

double multiplicativeTrace(Matrix *p) {
    if (isSquare(p)) {
        double mtr = 1.0;
        for (int i = 0; i < p->domain_dim; i++) {
            mtr *= (p->entries)[i * (1 + p->domain_dim)];
        }
        return mtr;
    } else {
        return 0.0;  // need to add asserts or errors or something in these parts
    }
}
double determinant(Matrix *p) {
    double det;
    if (isSquare(p)) {
        if (isLowerTriangular(p) || isUpperTriangular(p)) {
            return multiplicativeTrace(p);
        }
        if (p->domain_dim == 1) {
            return (p->entries)[0];
        } else if (p->domain_dim == 2) {
            double a, b, c, d;
            a = (p->entries)[0];
            b = (p->entries)[1];
            c = (p->entries)[2];
            d = (p->entries)[3];
            return (a * d - b * c);
        } else {
            // something recursive for sure (leibniz?)
            return 0.0;
        }

    } else {
        // someting to add here
        return 0.0;
    }
}

Matrix *flatten(Matrix *p) {
    // need to add check if cannot be flattened or something
    
    // int n = p->domain_dim;
    // int m = p->range_dim;

    // Matrix *flat = zeroMat(1, n * m);

    // for (int i = 0; i < n * m; i++) {
    //     (flat->entries)[i] = (p->entries)[i];
    // }

    int nm = (p->domain_dim) * (p->range_dim);

    Matrix *flat = zeroMat(1, nm);
    double* flatEntries = (flat->entries);
    double* pEntries = (p->entries);

    while (--nm >= 0){
        flatEntries[nm] = pEntries[nm];
    }

    return flat;
}