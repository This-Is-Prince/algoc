//
//  array.c
//  dsa
//
//  Created by Prince on 30/09/25.
//

#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#include "array_declarations.h"
#include "2darray.h"
#include "static_dynamic_array.h"
#include "arrayadt.h"

void RunArray(bool run) {
    if (!run) {
        return;
    }
    
    printf("Array in C!\n");
    
    RunArrayDeclarations(true);
    Run2DArray(true);
    RunStaticDynamicArray(true);
    RunArrayADT(true);
}
