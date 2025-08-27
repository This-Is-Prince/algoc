#include <stdio.h>

int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return sum(n - 1) + n;
    }
}

int sumLoop(int n) {
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += i;
    }
    
    return s;
}

int main(int argc, const char* argv[]) {
    int s = sum(10);
    printf("%d\n", s);
    
    s = sumLoop(9);
    printf("%d\n", s);
    return 0;
}
