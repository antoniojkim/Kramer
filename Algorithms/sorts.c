#include "sorts.h"
#include <stdio.h>

void swap(double *p, double *q){

    double temp = *p;
    *p = *q;
    *q = temp;

}

void bubbleSort(double p[], int len){
    
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            if (p[i] > p[j]){
                swap(&p[i], &p[j]);
            }
        }
    }
}