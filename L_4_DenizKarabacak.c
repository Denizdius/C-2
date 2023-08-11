#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dydx(double x, double y) {
    // Write the derivative of y with respect to x  
    return 10 * x + y - 8;
}

double yx(double x) {
    // Write the exact solution for the given x
    return -10 * x - 2 + 3 * exp(x);
}

void euler(double (*dydx)(double, double), double *yEuler, double xFirst, double yFirst, double xLast, double stepSize) {
    // Implement Euler's method using eulers formula for the derivative of y with respect to x  it is only for fisrt order
    //and it s to faulty upcoming each steps

    int n = (int) ((xLast - xFirst) / stepSize);
    for (int i = 0; i < n; i++) {
        double x = xFirst + i * stepSize;
        yEuler[i+1] = yEuler[i] + stepSize * dydx(x, yEuler[i]);
    }
}

void midpoint(double (*dydx)(double, double), double *yMidPoint, double xFirst, double yFirst, double xLast, double stepSize) {
    // Implement the midpoint method which is used in the RK methods(RK2)
    //It works by approximating the solution curve with a series of parabolic segments. with  formula of midpoint rule 
    int n = (int) ((xLast - xFirst) / stepSize);
    for (int i = 0; i < n; i++) {
        double x = xFirst + i * stepSize;
        double k1 = dydx(x, yMidPoint[i]);
        double k2 = dydx(x + stepSize / 2, yMidPoint[i] + stepSize / 2 * k1);
        yMidPoint[i+1] = yMidPoint[i] + stepSize * k2;
    }
}

void RK3(double (*dydx)(double, double), double *yRK3, double xFirst, double yFirst, double xLast, double stepSize) {
    // Implement the 3rd order Runge-Kutta method.It works by estimating the slope of the tangent line to the solution curve at four different points within the current step
    //using the formula of RK3
    int n = (int) ((xLast - xFirst) / stepSize);
    for (int i = 0; i < n; i++) {
        double x = xFirst + i * stepSize;
        double k1 = dydx(x, yRK3[i]);
        double k2 = dydx(x + stepSize / 2, yRK3[i] + stepSize / 2 * k1);
        double k3 = dydx(x + stepSize, yRK3[i] - stepSize * k1 + 2 * stepSize * k2);
        yRK3[i+1] = yRK3[i] + stepSize / 6 * (k1 + 4 * k2 + k3);
    }
}

void RK4(double (*dydx)(double, double), double *yRK4, double xFirst, double yFirst, double xLast, double stepSize) {
    // Implement the 4th order Runge-Kutta method.It works by estimating the slope of the tangent line to the solution curve at four different points within the current step
    //using the formula of RK4
    int n = (int) ((xLast - xFirst) / stepSize);
    for (int i = 0; i < n; i++) {
        double x = xFirst + i * stepSize;
        double k1 = dydx(x, yRK4[i]);
        double k2 = dydx(x + stepSize / 2, yRK4[i] + stepSize / 2 * k1);
        double k3 = dydx(x + stepSize / 2, yRK4[i] + stepSize / 2 * k2);
        double k4 = dydx(x + stepSize, yRK4[i] + stepSize * k3);
        yRK4[i+1] = yRK4[i] + stepSize / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
    }
}

int main() {
    double x0, y0, xLast, stepSize;
    printf("Enter x0, y0, x_last, and step size: ");
    scanf("%lf %lf %lf %lf", &x0, &y0, &xLast, &stepSize);

    // Allocate memory for the solution arrays
    int n = (int) ((xLast - x0) / stepSize);
    double *yEuler = (double *) malloc((n+1) * sizeof(double));
    double *yMidPoint = (double *) malloc((n+1) * sizeof(double));
    double *yRK3 = (double *) malloc((n+1) * sizeof(double));
    double *yRK4 = (double *) malloc((n+1) * sizeof(double));

    // Set the initial values of the solution arrays
    yEuler[0] = y0;
    yMidPoint[0] = y0;
    yRK3[0] = y0;
    yRK4[0] = y0;

    // Compute the solutions using the different methods
    euler(dydx, yEuler, x0, y0, xLast, stepSize);
    midpoint(dydx, yMidPoint, x0, y0, xLast, stepSize);
    RK3(dydx, yRK3, x0, y0, xLast, stepSize);
    RK4(dydx, yRK4, x0, y0, xLast, stepSize);

    // Print the solutions
    printf("Step\tExact\t\tEuler             Midpoint     RK3\t      RK4\n");
    for (int i = 0; i <= n; i++) {
        double x = x0 + i * stepSize;
        printf("Step %d:\t%f\t%f\t%f\t%f\t%f\n", i, yx(x), yEuler[i], yMidPoint[i], yRK3[i], yRK4[i]);
    }

    // Free the memory allocated for the solution arrays
    free(yEuler);
    free(yMidPoint);
    free(yRK3);
    free(yRK4);

    return 0;
}
