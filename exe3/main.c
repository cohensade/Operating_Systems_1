#include "Poisson.h"
#include <stdio.h>

int main(){
  printf("poi(2,1) = " "%.18Lf\n", poi(2,1));

  printf("poi(2,10) = " "%.18Lf\n", poi(2,10));

  printf("poi(2,2) = " "%.18Lf\n", poi(2,2));

  printf("poi(3,3) = " "%.18Lf\n", poi(3,3));

  printf("poi(100,3) = " "%.18Lf\n", poi(100,3));

    return 0;
}