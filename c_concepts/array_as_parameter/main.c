#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void sizeofA_WhichIsSizeofPointer(int A[]) {
    // This will not giving us size of Array it is giving us size of pointer which is 8 / (size of int = 4) = result = 2
    printf("Size of A: %lu\n", sizeof(A) / sizeof(int));
}

void fun(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", A[i]);
    }

    printf("\n");
}

int* Array(int size) {
    int* array = (int*)malloc(sizeof(int) * size);

    if (array == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }

    return array;
}


void first(bool run) {

    if (!run) {
        return;
    }

    int A[] = {2, 4, 5, 8, 10};
    int n = sizeof(A) / sizeof(A[0]);

    sizeofA_WhichIsSizeofPointer(A);

    fun(A, n);

    // A = Array(10);

    // int* B = Array(10);
    
    // fun(B, 10);
}


int main () {

    first(true);


    return 0;
}