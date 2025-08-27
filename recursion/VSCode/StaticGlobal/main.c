#include <stdio.h>

int funWithStatic(int n) {
    static int x = 0;
    
    if (n > 0) {
        x++;
        int result = funWithStatic(n - 1) + x;
        return result;
    }
    
    return 0;
}

int fun(int n) {
    if (n > 0) {
        return fun(n - 1) + n;
    }
    
    return 0;
}

int main(int argc, const char* argv[]) {
    
    int r;
    r = fun(5);
    printf("%d\n", r);
    
    int r2;
    r2 = funWithStatic(5);
    printf("%d\n", r2);

    return 0;
}
