#include <stdio.h>
#include <stdlib.h>
#include <math.h>//for fabs

#define E 0.001 //Macro for eplison value given in sheet 

double f(double x) {
    return 2 * x * x * x - 10 * x * x + 3 * x + 5;//function writed it is easier to do with pow function but that'fine!
}

int main() {
    double x0, x1, xn, error;//classic defination for al vabs
    int n, nmax;

    printf("\nEnter the value of initial guess x0: ");
    scanf("%lf", &x0);

    printf("\nEnter the value of initial guess x1: ");//Classical user typeing some info
    scanf("%lf", &x1);

    printf("\nEnter the value of maximum iteration number Nmax: ");
    scanf("%d", &nmax);

    for (n = 1; n <= nmax; n++) {

        xn = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));//Simplization of formula by f(xn) = 0

        error = fabs((xn - x1) / xn);//fabs for calculating abs val for float type or double 
        //Why we need absolute value ? Because negative eroors are erros too for this method like -%30 eroor percatage is a error  too.

        printf("Iteration %d: x%d = %lf, error = %lf\n", n, n, xn, error);////My additon for  the lab accutaly dont need 
        //Shows the step by step itterations 

        if (error < E) {
            printf("Solution found after %d iterations: %lf\n", n, xn);
            return 0;
        }

        x0 = x1;
        x1 = xn;
    }

    printf("Maximum iterations reached!\n");//Finish line  sentence
    return 0;
}
