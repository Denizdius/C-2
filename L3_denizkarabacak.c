#include <stdio.h>
#include <math.h>

// Define the four functions eaisly
double f1(double x) {
    return 40 / (1000 * exp(-0.1 * x) + 1);
}

double f2(double x) {
    return 20 + 20 * sin((x - 15) / 10); //after conversations with mr.okan i decided to add +20  this function
}

double f3(double x) {
     return 2000 / (20 * sqrt(2 * M_PI)) * exp(-pow(x - 60, 2) / 800);
}

double f4(double x) {
    return 2 * M_PI * x * ((40 / (100 * exp(-0.1 * x) + 1)) - (40 / (1000 * exp(-0.1 * x) + 1)));//Must use M_PI instead of pi or eroor ?
}

// Define the three numerical integration methods

//The function then calculates the width of each subint h, 
//and uses a loop to calculate the sum of the function values at the midpoint of each subint multip by the width of the subint. 
//The function then returns the sum multiplied by h. 
double rectangle(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

//The function then calculates the width of each subint h,
// and uses a loop to calculate the sum of the function values at the endpoints of each subinterval multip  by the width of the subint..
//The function then returns the sum multiplied by h/2.

double trapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * (f(a) / 2 + sum + f(b) / 2);
}


//The function then calculates the width of each subint h,
// and uses two loops to calculate the sum of the function values at the endpoints and midpoints of each pair of subint. 
//The function then uses these values to calculate the area under a parabolic curve that passes through the three points defined by the endpoints and midpoint of each pair of subint. 
//The function then returns the sum of these areas multip by h/3.

double simpsons(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 1; i < n; i += 2) {
        sum1 += f(a + i * h);
    }
    for (int i = 2; i < n; i += 2) {
        sum2 += f(a + i * h);
    }
    return h / 3 * (f(a) + 4 * sum1 + 2 * sum2 + f(b));
}

// Define the main function
int main() {
    double a = 0;
    double b = 120;
    int n = 100;

    // Calculate area under curve for f1 using all three methods
    double f1_rect = rectangle(f1, a, b, n);
    double f1_trap = trapezoidal(f1, a, b, n);
    double f1_simp = simpsons(f1, a, b, n);

    // Calculate area under curve for f2 using all three methods
    double f2_rect = rectangle(f2, a, b, n);
    double f2_trap = trapezoidal(f2, a, b, n);
    double f2_simp = simpsons(f2, a, b, n);

    // Calculate area under curve for f3 using all three methods
    double f3_rect = rectangle(f3, a, b, n);
    double f3_trap = trapezoidal(f3, a, b, n);
    double f3_simp = simpsons(f3, a, b, n);

    // Calculate volume for f4 using all three methods
    double f4_rect = rectangle(f4, a, b, n);
    double f4_trap = trapezoidal(f4, a, b, n);
    double f4_simp = simpsons(f4, a, b, n);

    // Print the results
    printf("\n");
    printf("Area under curve for f1:\n");
    printf("Rectangular method: %lf\n", f1_rect);
    printf("Trapezoidal method: %lf\n", f1_trap);
    printf("Simpson's rule: %lf\n", f1_simp);
    printf("\n");

    printf("Area under curve for f2:\n");
    printf("Rectangular method: %lf\n", f2_rect);
    printf("Trapezoidal method: %lf\n", f2_trap);
    printf("Simpson's rule: %lf\n", f2_simp);
    printf("\n");

    printf("Area under curve for f3:\n");
    printf("Rectangular method: %lf\n", f3_rect);
    printf("Trapezoidal method: %lf\n", f3_trap);
    printf("Simpson's rule: %lf\n", f3_simp);
    printf("\n");

    printf("Volume of f4:\n");
    printf("Rectangular method: %lf\n", f4_rect);
    printf("Trapezoidal method: %lf\n", f4_trap);
    printf("Simpson's rule: %lf\n", f4_simp);
    printf("\n");

    return 0;
}
