#include "stack.h"
#include <stdlib.h>

void push(Stack *s, int x){

    Node *newTop = (Node *) malloc(sizeof(Node));
    newTop -> cargo = x;
    newTop -> next = s -> top;
    s -> top = newTop;
    s -> size ++;

}

Node * pop(Stack *s){
    if (s -> size > 0){
        Node *top = s -> top;
        s -> top = top -> next;
        s -> size --;
        return top;
    }
}

int size(Stack *s){

    return s -> size;
}

bool isEmpty(Stack *s){

    if (s -> size == 0){

        return true;
    }
    return false;
}