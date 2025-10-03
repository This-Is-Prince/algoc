//
//  stack.h
//  dsa
//
//  Created by Prince on 03/10/25.
//

#include <stdbool.h>

typedef struct SNode SNode;
typedef struct Stack Stack;

Stack* NewStack(void);
bool IsEmpty(Stack*);
void Push(Stack*, Node*);
Node* Pop(Stack*);
