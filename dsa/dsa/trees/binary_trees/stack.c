//
//  stack.c
//  dsa
//
//  Created by Prince on 03/10/25.
//

#include <stdbool.h>
#include <stdlib.h>
#include "binarytreesadt.h"
#include "stack.h"

struct SNode {
    Node* value;
    SNode* down;
};

SNode* NewSNode(Node* v) {
    SNode* n = malloc(sizeof(SNode));
    
    n->value = v;
    n->down = NULL;
    
    return n;
};

struct Stack {
    SNode* top;
    SNode* bottom;
    size_t size;
};

Stack* NewStack(void) {
    Stack* s = malloc(sizeof(Stack));
    
    s->size = 0;
    s->top = NULL;
    s->bottom = NULL;

    return s;
}

bool IsEmpty(Stack* s) {
    if (s == NULL) {
        return true;
    }
    
    return s->size == 0;
};

void Push(Stack* s, Node* v) {
    if (s == NULL) {
        return;
    }
    
    SNode* sn = NewSNode(v);
    if (s->top == NULL) {
        s->top = sn;
    } else {
        s->bottom->down = sn;
    }
    
    s->bottom = sn;
    s->size++;
}

Node* Pop(Stack* s) {
    if (s == NULL || s->size == 0) {
        return NULL;
    }
    
    SNode* top = s->top;
    s->top = s->top->down;
    s->size--;
    
    if (s->size == 0) {
        s->bottom = NULL;
    }
    
    Node* node = top->value;
    free(top);
    
    return node;
}
