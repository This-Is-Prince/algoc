//
//  main.c
//  dsa
//
//  Created by Prince on 30/09/25.
//

#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "stringsadt.h"
#include "linkedlistadt.h"
#include "trees.h"

int main(int argc, const char * argv[]) {
    RunArray(false);
    RunStringADT(false);
    RunLinkedlistADT(false);
    RunTrees(true);
    
    return EXIT_SUCCESS;
}
