#include <stdio.h>


int c(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    
    return c(n - 1, r - 1) + c(n - 1, r);
}

int main(int argc, const char* argv[]) {
    
    printf("%d\n", c(5, 2));
    
    return 0;
}
