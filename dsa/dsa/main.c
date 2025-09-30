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

int main(int argc, const char * argv[]) {
    RunArray(false);
    RunStringADT(false);
    RunLinkedlistADT(true);

    return EXIT_SUCCESS;
}
