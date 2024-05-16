#include <stdio.h>
#include "memory.h"



void accessUninitializedMemory() {
      int* uninitialized_ptr = (int*)0xdeadbeef;

    // קריאה מצביע שלא הוגדר
    printf("Uninitialized pointer: %d\n", *uninitialized_ptr);

}