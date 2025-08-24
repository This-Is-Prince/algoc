#include <stdio.h>

int main() {
    int empty[5] = {0};
    
    int A[5];
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    printf("%zu\n", sizeof(A));
    printf("%d\n\n\n", A[1]);

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        printf("%d\n", i[A]);
    }

    printf("\n\n\n");

    for (int i = 0; i < sizeof(empty) / sizeof(empty[0]); i++) {
        printf("%d\n", i[empty]);
    }

    return 0;
}