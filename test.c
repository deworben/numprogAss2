#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>
#define MAXVAL 999
#define eps 1e-6
// #include "tasks.h"


void count2(int* counter){
   
    int temp = *counter;
    *counter = temp + 1;

    return;
}
void count(int* counter){
    count2(counter);

    printf("counter = %d\n", *counter);

    return;
}
int main(int argc, char *argv[]) {

    
    int* counter = (int *)malloc(sizeof(int));
    *counter = 0;
    while(1){
        count(counter);
    }


    return 1;
}