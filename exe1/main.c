#include <stdio.h>
#include <signal.h>
#include "divide_by_zero.h"
#include "memory.h"
#include "stack_over_flow.h"


int main(){
    raise(SIGABRT);
    devideZero();
    accessUninitializedMemory();
    recursiveSum(30);
   

return 0;
}