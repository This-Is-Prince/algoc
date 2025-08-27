#include <stdio.h>

void funA(int);
void funB(int);

void funA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funB(n - 1);
    }
}

void funB(int n) {
    if (n > 1) {
        printf("%d ", n);
        funA(n / 2);
    }
}

int main(int argc, const char* argv[]) {
    
    funA(20);
    
    return 0;
}
