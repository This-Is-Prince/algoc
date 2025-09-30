#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedListADT LinkedListADT;

struct Node {
    int value;
    Node* next;
};

struct LinkedListADT {
    Node* start_node;
};

LinkedListADT* CreateLinkedListADT(void) {
    LinkedListADT* ll = malloc(sizeof(LinkedListADT));
    ll->start_node = NULL;
    
    return ll;
}

void Display(LinkedListADT* ll) {
    if (ll == NULL) {
        return;
    }
    
    Node* cursor = ll->start_node;
    while (cursor != NULL) {
        printf("%d, ", cursor->value);
        cursor = cursor->next;
    }
    
    printf("\n");
}

Node* NewNode(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    
    return new_node;
}

void Append(LinkedListADT* ll, int value) {
    if (ll == NULL) {
        return;
    }
    
    Node* new_node = NewNode(value);
    
    if (ll->start_node == NULL) {
        ll->start_node = new_node;
        return;
    }
    
    Node* cursor = ll->start_node;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    
    cursor->next = new_node;
}

void AppendArray(LinkedListADT*ll, int values[], int len) {
    if (ll == NULL || len == 0) {
        return;
    }
    
    int idx = 0;
    
    if (ll->start_node == NULL) {
        ll->start_node = NewNode(values[idx++]);
    }
    
    Node* cursor = ll->start_node;
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
    
    for (int i = idx; i < len; i++) {
        cursor->next = NewNode(values[i]);
        cursor = cursor->next;
    }
}


int main(int argc, const char* argv[]) {
    LinkedListADT* ll = CreateLinkedListADT();
    Display(ll);
    
    int values[] = {1, 2, 3};
    AppendArray(ll, values, sizeof(values) / sizeof(int));
    Display(ll);
    
    printf("----------\n");
    
    return 0;
}
