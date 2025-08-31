#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    
    int A[10];
    int *p, *q;
    int size = 5;
    
    p = malloc(size * sizeof(int));
    q = p;
    for (int i = 0; i < size; ++i) {
        p[i] = i + 1;
    }
    
    for (int i = 0; i < size; ++i) {
        printf("%d,", p[i]);
    }
    
    printf("\n");
    
    size = 10;
    
    p = realloc(p, size * sizeof(int));
    
    q[0] = 33333;
    for (int i = 0; i < size; ++i) {
        printf("%d,", p[i]);
    }
    
    
    
    return 0;
}
