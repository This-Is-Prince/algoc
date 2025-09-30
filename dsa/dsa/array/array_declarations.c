//
//  array_declarations.c
//  dsa
//
//  Created by Prince on 30/09/25.
//

#include <stdio.h>
#include <stdbool.h>
#include "array_declarations.h"

void RunArrayDeclarations(bool run) {
    if (!run) {
        return;
    }
    
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[5] = {2, 4, 6};
    int D[5] = {0};
    int E[] = {1, 2, 3, 4, 5, 6};
    
    for (int i = 0; i < 5; ++i) {
        printf("%u \n", &A[i]);
    }
}
