//
//  trees.c
//  dsa
//
//  Created by Prince on 30/09/25.
//

#include <stdio.h>
#include <stdbool.h>
#include "trees.h"
#include "binarytreesadt.h"

void RunTrees(bool run) {
    if (!run) {
        return;
    }
    
    printf("Trees in C!\n");
    
    RunBinaryTreesADT(true);
}
