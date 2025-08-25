#include <stdio.h>

int add(int a, int b) {
    int c;
    c = a + b;

    return c;
}


int main() {

    int a = 10, b = 15, sum;

    sum = add(a, b);

    printf("Sum of %d + %d = %d", a, b, sum);

    return 0;
}