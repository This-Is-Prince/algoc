#include <stdio.h>

double e(int x, int n) {
    static double S = 1;
    if (n == 0) {
        return S;
    }
    
    S = 1 + ((double)x / (double)n) * S;
    
    return e(x, n - 1);
}

int main(int argc, const char* argv[]) {
    printf("%lf\n", e(1, 10));
    return 0;
}
