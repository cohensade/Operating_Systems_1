#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double poi(long double gimel, long  k){
    if (gimel<0 || k<0)
    {
        printf("Negative numbers\n");
        return -1;
    }
    
    // px(k) = (e^(-𝜆) * 𝜆^k) / k! calc the probability of poisson by using math.h
    long double probability = (expf(-gimel) * powl(gimel, k)) / tgammal(k + 1);
    //expf(x) = e^(x) (long double)  powl(x,y) = x^y (long double)  tgammal(k+1) = k!(long double)

    return probability;  
}