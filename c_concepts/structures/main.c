#include <stdio.h>

struct Rectangle {
    int length;
    int breadth;
    char x;
};

int main() {

    struct Rectangle r1 = {10, 5, 'A'};

    printf("%lu", sizeof(r1));

    
    return 0;
}