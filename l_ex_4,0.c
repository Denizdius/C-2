#include <stdio.h>
#include <math.h>

// Define the function to be integrated
double f(double x, double a, double b, double c, double d, double e) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d; // Example: ax^3 + bx^2 + cx + d
}

// Trapezoidal rule implementation
double trapezoidal_rule(double a, double b, int n, double c, double d, double e) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a, c, d, e, 0, 0) + f(b, c, d, e, 0, 0));

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h, c, d, e, 0, 0);
    }

    return h * sum;
}

int main() {
    double a, b, c, d, e;
    double lower_limit, upper_limit;
    int num_trapezoids;

    printf("Enter the coefficients of a third-order polynomial function ax^3 + bx^2 + cx + d:\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    printf("d: ");
    scanf("%lf", &d);

    printf("Enter the lower limit of integration: ");
    scanf("%lf", &lower_limit);
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &upper_limit);
    printf("Enter the number of trapezoids to use: ");
    scanf("%d", &num_trapezoids);

    printf("The function to be integrated is: %lfx^3 + %lfx^2 + %lfx + %lf\n", a, b, c, d);

    double result = trapezoidal_rule(lower_limit, upper_limit, num_trapezoids, a, b, c, d, e);
    printf("The approximate integral of the function is: %lf\n", result);

    return 0;
}
