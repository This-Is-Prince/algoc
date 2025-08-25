#include <stdio.h>
#include <stdbool.h>

void swapByValue(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void passByValue(bool run) {
    if (!run) {
        return;
    }

    int a, b;
    a = 10;
    b = 20;

    printf("Before swap using pass by value: a = %d, b = %d\n", a, b);

    swapByValue(a, b);

    printf("After swap using pass by value: a = %d, b = %d\n", a, b);

    printf("\n\n");
}

void swapByAddress(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void passByAddress(bool run) {
    if (!run) {
        return;
    }

    int a, b;
    a = 10;
    b = 20;

    printf("Before swap using pass by address: a = %d, b = %d\n", a, b);

    swapByAddress(&a, &b);

    printf("After swap using pass by address: a = %d, b = %d\n", a, b);

    printf("\n\n");
}

int main() {

    passByValue(true);

    passByAddress(true);

    return 0;
}