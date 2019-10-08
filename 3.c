#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>
#define MAXVAL 999
#define NOVALUE 9999
#define MAXDEGREES 90
#define eps 1e-6
#define toRads 3.14159265 / 180
#define toDegs 180 / 3.14159265
#define INIT 0

// #include "tasks.h"
void initMem(double *a, double *b, double *c, double *q, int *arraySize){
    a = (double *)malloc(sizeof(double));
    b = (double *)malloc(sizeof(double));
    c = (double *)malloc(sizeof(double));
    q = (double *)malloc(sizeof(double));
    *arraySize = 1;
    return;
}

void makeMemory(double *a, double *b, double *c, double *q, int *arraySize)
{   
    *arraySize = *arraySize + 1;

    a = (double *)realloc(a, (*arraySize)*sizeof(double));
    b = (double *)realloc(b, (*arraySize)*sizeof(double));
    c = (double *)realloc(c, (*arraySize)*sizeof(double));
    q = (double *)realloc(q, (*arraySize)*sizeof(double));
    
    return;
}

int readValues(char *filename, double *a, double *b, double *c, double *q, int* arraySize)
{
    printf("%s", filename);
    FILE *fp = fopen(filename, "r");
    //Get rid of first line
    char *temp = (char *)malloc(sizeof(char) * 100);
    temp[99] = '\0';
    fscanf(fp, "%s\n", temp);
    free(temp);

    
    


    //Make memory for one more value of all vectors
    initMem(a, b, c, q, arraySize);
    
    while ()
    {
        /* code */
    }
    

    fclose(fp);
}

int main(int argc, char *argv[])
{

    //Create veriables for data structs - the input and output matrixes
    double *a = NULL;
    double *b = NULL;
    double *c = NULL;
    double *q = NULL;
    double *xOut = NULL;

    int *arraySize = (int *)malloc(sizeof(int));
    *arraySize = 0;

    //read in the values
    readValues(argv[1], a, b, c, q, arraySize);

    //Allocate memory for data structs
    //Put the data in

    //Create variables/memory for new a* and q* values

    //calculate the a* and q* values

    //calculate the x values

    //Output the x values

    //Free all the memory
    free(a);
    free(b);
    free(c);
    free(q);
    free(arraySize);

    return 1;
}