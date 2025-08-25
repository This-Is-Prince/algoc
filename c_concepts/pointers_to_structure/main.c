#include <stdio.h>

struct Rectangle {
    int length;
    int breadth;
};

int main() {

    struct Rectangle r = {10, 5};
    printf("%d, %d\n", r.length, r.breadth);

    struct Rectangle* p = &r;
    printf("%d, %d", (*p).length, (*p).breadth);

    return 0;
}