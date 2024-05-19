#include <stdio.h>
#include <stdlib.h>
#include "maxsum.h"
int max(int a, int b){
    if(a >= b)
    {
        return a;
    }
    return b;
}

int maxSubArraySumN1(int arr[], int n)
{
int best = 0, sum = 0; //set best sum and current sum
for (int k = 0; k < n; k++) //iterate over the arr
{
sum = max(arr[k],sum + arr[k]); //calc sum max between arr[k], sum + arr[k]
best = max(best,sum); //take the best sum from best now and sum
}
printf("The max sum is: %d\n ", best);
return best;
}

int maxSubArraySumN2(int arr[], int n)
{
int best = 0; //set best for best sum
for (int a = 0; a < n; a++) 
{
int sum = 0; //set sum for current sum
for (int b = a; b < n; b++) //for each every index in the arr we will run until the end of arr and check the best sum
{
sum += arr[b]; //update sum
best = max(best,sum); //update best sum
}
}
printf("The max sum is: %d\n ", best);
return best;
}
int maxSubArraySumN3(int arr[], int n)
{
int best = 0;
for (int a = 0; a < n; a++) {
for (int b = a; b < n; b++) {
int sum = 0;
for (int k = a; k <= b; k++) {
sum += arr[k];
}
best = max(best,sum);
}
}
//cout << best << "\n";
printf("The max sum is: %d\n ", best);
return best;
}


int* random(int randomseed, int n) 
{
    srand(randomseed);
    int *arr = malloc(n * sizeof(int)); // dynamically allocate memory for the array
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 25; // generate random numbers between (-25, 74)
    }
    return arr; // return a pointer to the allocated memory
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid num of args\n");
        return 1;
    }
    
    int randomSeed = atoi(argv[1]); //rendom seed as requested
    int n = atoi(argv[2]); //length of the input
    int* arr = random(randomSeed, n);//create the random arr
    // for (int i = 0; i < n; i++)
    // {
    //     printf("  %d ", arr[i]); //print all the values of the arr
    // }
    maxSubArraySumN3(arr ,n); //calc the maxsub arr sum O(n^2)(the func print the sum)
    //maxSubArraySumN2(arr ,n); //calc the maxsub arr sum O(n^2)(the func print the sum)
    //maxSubArraySumN1(arr,n); //calc the maxsub arr sum (the func print the sum)

    free(arr);
}







