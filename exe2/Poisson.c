#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) 
{
    // check if the amount of args is valid
    if (argc != 3) 
    {
        printf("Error\n");
        return 1;
    }
    //take the args k and 𝜆 to k and gimel(aka 𝜆)
    long double gimel = strtold(argv[1], NULL);// argv[1] = 𝜆 
    long k = strtol(argv[2], NULL, 10); //argv[2] = k

    // px(k) = (e^(-𝜆) * 𝜆^k) / k! calc the probability of poisson by using math.h
    long double probability = (expf(-gimel) * powl(gimel, k)) / tgammal(k + 1);
    //expf(x) = e^(x) (long double)  powl(x,y) = x^y (long double)  tgammal(k+1) = k!(long double)
    // print the probability
    printf("%.18Lf\n", probability);
    //%.18LF print 18 digits after 0. in long double
    return 0;  
}