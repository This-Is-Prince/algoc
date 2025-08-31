#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 2) + fibonacci(n - 1);
    }
}

int main(int argc, const char* argv[]) {
    printf("%d\n", fibonacci(7));
    return 0;
}
