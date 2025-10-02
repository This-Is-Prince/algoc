//
//  queue.c
//  dsa
//
//  Created by Prince on 01/10/25.
//

#include <stdbool.h>
#include <stdlib.h>
#include "binarytreesadt.h"
#include "queue.h"

struct QNode {
    Node* value;
    QNode* next;
};

QNode* NewQNode(Node* v) {
    QNode* n = malloc(sizeof(QNode));
    
    n->value = v;
    n->next = NULL;

    return n;
};

struct Queue {
    QNode* start_node;
    QNode* last_node;
    size_t size;
};

Queue* NewQueue(void) {
    Queue* q = malloc(sizeof(Queue));
    
    q->size = 0;
    q->start_node = NULL;
    q->last_node = NULL;
    
    return q;
}

bool IsEmpty(Queue* q) {
    if (q == NULL) {
        return true;
    }
    
    return q->size == 0;
}

void Enqueue(Queue* q, Node* v) {
    if (q == NULL) {
        return;
    }
    
    QNode* qn = NewQNode(v);
    if (q->start_node == NULL) {
        q->start_node = qn;
    } else {
        q->last_node->next = qn;
    }
    
    q->last_node = qn;
    q->size++;
}

Node* Dequeue(Queue* q) {
    if (q == NULL || q->size == 0) {
        return NULL;
    }
    
    QNode* first = q->start_node;
    q->start_node = q->start_node->next;
    q->size--;
    
    Node* node = first->value;
    free(first);
    
    return node;
}
