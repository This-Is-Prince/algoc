//
//  binarytreesadt.c
//  dsa
//
//  Created by Prince on 30/09/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "binarytreesadt.h"
#include "queue.h"

struct Node {
    Node* left;
    Node* right;
    int value;
};

static Node* NewNode(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

struct BinaryTree {
    Node* root;
};

BinaryTree* NewBinaryTree(void) {
    BinaryTree* bt = malloc(sizeof(BinaryTree));
    bt->root = NULL;
    
    return bt;
}

void preOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    
    printf("%d, ", node->value);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void PreOrderTraversal(BinaryTree* bt) {
    if (bt == NULL || bt->root == NULL) {
        return;
    }
    
    printf("PreOrderTraversal!\n");
    preOrderTraversal(bt->root);
    printf("\n");
}

void inOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    
    inOrderTraversal(node->left);
    printf("%d, ", node->value);
    inOrderTraversal(node->right);
}

void InOrderTraversal(BinaryTree* bt) {
    if (bt == NULL || bt->root == NULL) {
        return;
    }
    
    printf("InOrderTraversal!\n");
    inOrderTraversal(bt->root);
    printf("\n");
}

void postOrderTraversal(Node* node) {
    if (node == NULL) {
        return;
    }
    
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d, ", node->value);
}

void PostOrderTraversal(BinaryTree* bt) {
    if (bt == NULL || bt->root == NULL) {
        return;
    }
    
    printf("PostOrderTraversal!\n");
    postOrderTraversal(bt->root);
    printf("\n");
}

void LevelOrderTraversal(BinaryTree* bt) {
    if (bt == NULL || bt->root == NULL) {
        return;
    }
    
    Queue* q = NewQueue();
    Node* node = bt->root;
    Enqueue(q, node);
    
    printf("LevelOrderTraversal!\n");
    
    while (!IsEmpty(q)) {
        node = Dequeue(q);
        if (node == NULL) {
            break;
        }
        
        printf("%d, ", node->value);
        if (node->left != NULL) {
            Enqueue(q, node->left);
        }
        if (node->right != NULL) {
            Enqueue(q, node->right);
        }
    }
    
    printf("\n");
}

void GenerateTreeFromArrayUsingQueue(BinaryTree* bt, int treeArray[], int size) {
    if (size == 0 || bt == NULL) {
        return;
    }
    
    if (treeArray[0] == INT_MIN) {
        return;
    }
    
    int idx = 0;
    
    Queue* q = NewQueue();
    Node* rootNode = NewNode(treeArray[idx++]);
    bt->root = rootNode;
    Enqueue(q, rootNode);
    
    while (!IsEmpty(q)) {
        Node* parentNode = Dequeue(q);
        if (parentNode == NULL) {
            break;
        }
        
        if (idx < size) {
            int v = treeArray[idx++];
            if (v != INT_MIN) {
                Node* node = NewNode(v);
                parentNode->left = node;
                Enqueue(q, node);
            }
        }
        
        if (idx < size) {
            int v = treeArray[idx++];
            if (v != INT_MIN) {
                Node* node = NewNode(v);
                parentNode->right = node;
                Enqueue(q, node);
            }
        }
    }
    
    free(q);
}

void RunBinaryTreesADT(bool run) {
    if (!run) {
        return;
    }
    
    BinaryTree* bt1 = NewBinaryTree();
    int treeArray1[] = {2, 4, 6, 8, 3, 9, 5};
    GenerateTreeFromArrayUsingQueue(bt1, treeArray1, sizeof(treeArray1) / sizeof(int));
    PreOrderTraversal(bt1);
    InOrderTraversal(bt1);
    LevelOrderTraversal(bt1);
    
    BinaryTree* bt2 = NewBinaryTree();
    int treeArray2[] = {5, 8, 6, INT_MIN, 9, 3, INT_MIN, INT_MIN, INT_MIN, 4, 2};
    GenerateTreeFromArrayUsingQueue(bt2, treeArray2, sizeof(treeArray2) / sizeof(int));
    PreOrderTraversal(bt2);
    InOrderTraversal(bt2);
    LevelOrderTraversal(bt2);
    
    BinaryTree* bt3 = NewBinaryTree();
    int treeArray3[] = {8, 3, 9, 7, INT_MIN, 6, 4, 5, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 2};
    GenerateTreeFromArrayUsingQueue(bt3, treeArray3, sizeof(treeArray3) / sizeof(int));
    LevelOrderTraversal(bt3);
    
    printf("----------\n");
}
