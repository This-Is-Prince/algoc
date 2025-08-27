#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    
    return factorial(n - 1) * n;
}

int main(int argc, const char* argv[]) {
    
    int f = factorial(5);
    
    printf("%d\n", f);
    
    return 0;
}
