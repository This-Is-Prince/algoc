//
//  queue.h
//  dsa
//
//  Created by Prince on 01/10/25.
//

#include <stdbool.h>

typedef struct QNode QNode;
typedef struct Queue Queue;

Queue* NewQueue(void);
bool IsEmpty(Queue*);
void Enqueue(Queue*, Node*);
Node* Dequeue(Queue*);
