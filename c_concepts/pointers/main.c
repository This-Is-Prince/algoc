#include <stdio.h>
#include <stdlib.h>

int main() {

    int a = 10;
    int *p;
    p = &a;

    printf("%p\n%p\n\n\n", p, &a);
    
    
    int A[5] = {2, 4, 6, 8, 10};
    int *P;
    P = &A[0];
    printf("%p\n%p\n\n\n", P, &A);

    return 0;
}