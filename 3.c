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

typedef struct data{
    double* a;
    double* b;
    double* c;
    double* q;
    double* x;
}data_t;



void makeMemory(data_t* inputData, int* arraySize)
{   
    int temp = *arraySize+1;
    *arraySize = temp;

    printf("size = %d\n", *arraySize);

    inputData->a = (double *)realloc(inputData->a, (temp)*sizeof(double));
    inputData->b = (double *)realloc(inputData->b, (temp)*sizeof(double));
    inputData->c = (double *)realloc(inputData->c, (temp)*sizeof(double));
    inputData->q = (double *)realloc(inputData->q, (temp)*sizeof(double));
    

    return;
}

void readValues(char *filename, data_t* inputData, int* arraySize)
{
    printf("%s\n", filename);
    FILE *fp = fopen(filename, "r");

    // Get rid of first line
    char *temp = (char *)malloc(sizeof(char) * 100);
    temp[99] = '\0';
    fscanf(fp, "%s\n", temp);
    free(temp);

    
    printf("startsas%d\n", *arraySize);

    while (1)
    {
        if(fscanf(fp, "%lf,%lf,%lf,%lf ", &((inputData->a)[(*arraySize)-1]),&((inputData->b)[(*arraySize)-1]),&((inputData->c)[(*arraySize)-1]),&((inputData->q)[(*arraySize)-1])) == EOF){
            printf("get out!\n");
            *arraySize = (*arraySize)-1;
            break;
        }
        printf("%lf,%lf,%lf,%lf\n", ((inputData->a)[(*arraySize)-1]),((inputData->b)[(*arraySize)-1]),((inputData->c)[(*arraySize)-1]),((inputData->q)[(*arraySize)-1]));
        makeMemory(inputData, arraySize);     
    }
    
    printf("Finished reading with arraySize = %d", *arraySize);
    fclose(fp);
    return;
}

void findAQ(data_t* inputData, data_t* outputData, int* arraySize){
    printf("\n");

    
    (outputData->a)[0] = (inputData->a)[0];
    (outputData->q)[0] = (inputData->q)[0];

    printf("%lf, %lf, %lf, %lf\n\n", (inputData->a)[0], (inputData->b)[0], (inputData->c)[0], (inputData->q)[0]);
    
    for(int i=1; i<(*arraySize); i++){
        
        printf("%lf, %lf, %lf, %lf\n", (inputData->a)[i], (inputData->b)[i], (inputData->c)[i], (inputData->q)[i]);
        

    }
    return;
}

int main(int argc, char *argv[])
{
    //Create veriables for data structs - the input and output matrixes
    data_t* inputData = (data_t *)malloc(sizeof(data_t));
    inputData->a = (double *)malloc(sizeof(double));
    inputData->b = (double *)malloc(sizeof(double));
    inputData->c = (double *)malloc(sizeof(double));
    inputData->q = (double *)malloc(sizeof(double));
 

    double *xOut = NULL;

    int* arraySize = (int *)malloc(sizeof(int));
    *arraySize = 1;

    //read in the values
    //Allocate memory for data structs
    //Put the data in
    readValues(argv[1], inputData, arraySize);

    //Create variables/memory for new a* and q* values
    data_t* outputData = (data_t *)malloc(sizeof(data_t));
    outputData->a = (double *)malloc((*arraySize)*sizeof(double));
    outputData->q = (double *)malloc((*arraySize)*sizeof(double));
    findAQ(inputData, outputData, arraySize);

    //calculate the a* and q* values

    //calculate the x values

    //Output the x values

    //Free all the memory
    free(inputData->a);
    free(inputData->b);
    free(inputData->c);
    free(inputData->q);
    free(inputData);
    free(arraySize);

    return 1;
}