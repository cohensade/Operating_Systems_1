#include <stdio.h>
#include "stack_over_flow.h"

int recursiveSum(int n) {
    // Base case: if n is 0, return 0
    if (n == 0) {
        return 0;
    }
    // Recursive case: return the sum of n and recursiveSum(n - 1)
    else {
        return n + recursiveSum(n - 1);
    }
    
}