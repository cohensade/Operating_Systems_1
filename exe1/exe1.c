#include <stdio.h>

#include "memory.h"
#include "stack_over_flow.h"
#include "divide_by_zero.h"


int main(){
     accessUninitializedMemory();
    recursiveSum(30000000);
    devideZero();
   

return 0;
}