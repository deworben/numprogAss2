#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>
#define MAXVAL 999
#define NOVALUE 9999
#define MAXDEGREES 90
#define eps 1e-6
#define toRads 3.14159265/180
#define toDegs 180/3.14159265
// #include "tasks.h"


double f(double M, double theta, double beta){

    double numerator = (pow(M, 2)) * pow(sin(beta), 2) - 1;
    double denominator = (pow(M, 2))*(1.4 + cos( 2 * beta)) + 2;

    return (2*(cos(beta)/sin(beta)) * ((numerator)/(denominator))) - tan(theta);
}

double derivative(double (*f)(double, double, double), double M, double theta, double x0)
{
    const double delta = eps; 
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(M, theta, x1);
    double y2 = f(M, theta, x2);
    return (y2 - y1) / (x2 - x1);
}

double absVal(double val){ return (val<0 ? -val:val);}


void runNewtonRaphson(double M, double theta, double* inVal){

    //The equation runs from 0-180 degrees. So make sure the algo goes through these points 

    double y = MAXVAL;
    double temp;
    double xVal = (*inVal);
    int counter = 0;

    while(absVal(y)>eps){
        if(counter>=50){
            *inVal = NOVALUE;
            return;
        }
        // printf("y now %lf, xVal now %lf\n", y, xVal);

        //if not, new bL = bL - f(bL)/f'(bL)
        temp = xVal - (f(M, theta, xVal)/derivative(f, M, theta, xVal));
        xVal = temp;

        //update y
        y = f(M, theta, xVal);
        counter++;
    }

    // printf("y now %lf, xVal now %lf\n", y, xVal);
    if((xVal<=0) || (xVal>90)){
        *inVal = NOVALUE;
    }

    *inVal = xVal;

    return;
}


void partb(double M, double thetaDegs, double* bL, double* bU, FILE * fp){
    double theta = thetaDegs; 
    for(;M<=8;M++){
        while (1){
            runNewtonRaphson(M, theta*toRads, bL);
            runNewtonRaphson(M, theta*toRads, bU);


            //what if only one value hits -> bL == bU
            if((*bL != NOVALUE) && (*bU != NOVALUE)){
                printf("\nInput guesses are theta=%lf degrees, M=%lf\nbL = %lf and %lf \n\n", theta, M, *bL*toDegs, *bU*toDegs );
                fprintf(fp, "%lf,%lf,%lf,%lf\n", M, theta, *bL*toDegs, *bU*toDegs );
                theta += 1;
            }else{
                printf("%lf degs is past max Val", theta);
                break;
            }
        }
        theta = thetaDegs;
    }
}
//the aim is to calculate the roots of the eqn using the newton raphson method
int main(int argc, char *argv[]) {

    // Safe variable creation
    double *bL = (double *)malloc(sizeof(double));
    if(bL == NULL){ exit(EXIT_FAILURE); }
    double *bU = (double *)malloc(sizeof(double));
    if(bU == NULL){ exit(EXIT_FAILURE); }
    FILE * fp = fopen("out_shock.csv", "w");
    if(fp == NULL){ exit(EXIT_FAILURE); }
    fprintf(fp, "M,theta,beta_lower,beta_upper\n");
    

    //setup variables
    double thetaDegs = 0;
    double M = 5.0;
    *bL = 0.01;
    *bU = 1.7;

    //run the functions
    //Part a
    // runNewtonRaphson(M, thetaDegs*toRads, bL);

    //part b and c
    M = 2; //, then 3, 4, 5, 6, 7, 8
    partb(M, thetaDegs, bL, bU, fp);
    

    fclose(fp);
    free(bL);
    free(bU);

	return 1;
}