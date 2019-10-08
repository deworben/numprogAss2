#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>
#define MAXVAL 999
#define eps 1e-6
// #include "tasks.h"


double derivative(double (*f)(double), double x0)
{
    const double delta = 1.0e-6; // or similar
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

double f(double x){
    return x*x;
}

int main(int argc, char *argv[]) {

    printf("hello man %lf", derivative(f, 10));


    return 1;
}