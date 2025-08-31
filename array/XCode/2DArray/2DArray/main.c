#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};
    
    int *B[3];
    int size = 4;
    B[0] = malloc(size * sizeof(int));
    B[1] = malloc(size * sizeof(int));
    B[2] = malloc(size * sizeof(int));
    
    int **C;
    C = malloc(3 * sizeof(int));
    C[0] = malloc(size * sizeof(int));
    C[1] = malloc(size * sizeof(int));
    C[2] = malloc(size * sizeof(int));
    
    return 0;
}
