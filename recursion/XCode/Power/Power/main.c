#include <stdio.h>

int power(int m, int n) {
    if (n == 0) {
        return 1;
    }
    
    return power(m, n - 1) * m;
}

int main(int argc, const char * argv[]) {
    
    int p = power(2, 9);
    printf("%d\n", p);
    
    return 0;
}
