#include <stdio.h>

int main() {

    int A[5];

    for (size_t i = 0; i < sizeof(A) / sizeof(int); ++i) {
        printf("%d, ", A[i]);
    }

    printf("\n");
    
    int B[5] = {2, 4, 6, 8, 10};

    for (size_t i = 0; i < sizeof(B) / sizeof(int); ++i) {
        printf("%d, ", B[i]);
    }

    printf("\n");
    
    int C[5] = {2, 4};
    
    for (size_t i = 0; i < sizeof(C) / sizeof(int); ++i) {
        printf("%d, ", C[i]);
    }

    printf("\n");
    
    int D[5] = {0};
        
    for (size_t i = 0; i < sizeof(D) / sizeof(int); ++i) {
        printf("%d, ", D[i]);
    }

    printf("\n");
    
    int E[] = {2, 4, 6, 8, 10};
    
    for (size_t i = 0; i < sizeof(E) / sizeof(int); ++i) {
        printf("%d, ", E[i]);
    }

    printf("\n");

    return 0;
}