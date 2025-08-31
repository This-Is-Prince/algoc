#include <stdio.h>

double e(int x, int n) {
    static double p = 1, f = 1;
    double r = 0;
    
    if (n == 0) {
        return 1;
    } else {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        
        return r + (p / f);
    }
}

int main(int argc, const char* argv[]) {
    
    printf("%lf\n", e(4, 20));
    return 0;
}
