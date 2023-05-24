#include <stdio.h>
#include <math.h>

const double D = 0.5;
const double L = 1.4;
const double LAMBDA = 3.6;
const double G = 9.81;
const double A = 2.28;
const double PI = acos(-1.0);

// Function prototypes
double f(double x);
double f_prime(double x);
double K();
double e_r(double x);
double degree_to_radian(double x);
double *tolerance_value_generator();
void newton_method(double x, double tolerance, double *root, int *iterations);

int main() {
    // Ask user for initial guess in degrees
    double x_degrees;
    printf("Enter initial guess in degrees (between 90 and 270): ");
    scanf("%lf", &x_degrees);
    while (x_degrees < 90 || x_degrees > 270) {
        printf("Invalid input. Enter initial guess in degrees (between 90 and 270): ");
        scanf("%lf", &x_degrees);
    }

    // Convert initial guess to radians
    double x = degree_to_radian(x_degrees);

    // Generate tolerance values
    double *tolerances = tolerance_value_generator();

    // Calculate roots for each tolerance value
    for (int i = 0; i < 6; i++) {
        double root;
        int iterations;
        newton_method(x, tolerances[i], &root, &iterations);
        printf("Tolerance: %.6e, Root: %.6f radians, er: %.6e, Iterations: %d\n", tolerances[i], root, e_r(root), iterations);
    }

    return 0;
}

// Define the function f(x)
double f(double x) {
    return D / 2.0 - (L / 2.0) * tan(x) + (A / 2.0) * sin(2.0 * x) - LAMBDA;
}

// Define the derivative of f(x)
double f_prime(double x) {
    return -(L / 2.0) * (1.0 / pow(cos(x), 2)) + A * cos(2.0 * x);
}

// Define the constant K
double K() {
    return G / (2.0 * pow(PI, 2) * D);
}

// Define the relative error function
double e_r(double x) {
    return fabs((x - atan((L / 2.0) * K() * tan(x) + LAMBDA / (2.0 * K()))) / x);
}

// Convert degrees to radians
double degree_to_radian(double x) {
    return x * PI / 180.0;
}

// Generate an array of tolerance values
double *tolerance_value_generator() {
    static double tolerance_values[6];
    double exponent = -6.0;
    for (int i = 0; i < 6; i++) {
        tolerance_values[i] = pow(10, exponent);
        exponent += 0.5;
    }
    return tolerance_values;


}

void newton_method(double x, double tolerance, double *root, int *iterations) {
    int i = 0;
    double f_value, f_prime_value, error;
    do {
        f_value = f(x);
        f_prime_value = f_prime(x);
        x = x - f_value / f_prime_value;
        error = fabs(f_value / f_prime_value);
        i++;
    } while (error > tolerance && i < 100);

    if (i == 100) {
        printf("The Newton-Raphson method did not converge within the maximum number of iterations.\n");
        *root = 0.0;
        *iterations = -1;
    } else {
        *root = x;
        *iterations = i;
    }
}
