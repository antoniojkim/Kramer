#ifndef __HEADER__STACK
#define __HEADER__STACK

#include <stdbool.h>
#include "node.h"

typedef struct{
    int size;
    struct Node * top;
} Stack;

Node * pop(Stack *);
void push(Stack *, int);
bool isEmpty(Stack *);
int size(Stack *);

#endif // __HEADER__STACK