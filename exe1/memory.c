#include <stdio.h>
#include "memory.h"



void accessUninitializedMemory() {
    int arr[5]; // Array declaration without initialization

    // Attempt to access elements of the array without initializing it
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]); // Accessing uninitialized memory
    }
}