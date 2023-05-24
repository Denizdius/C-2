#include <stdio.h>
#include <math.h>

// Define the function to be solved
double f(double R, double T) {
    return 1/T - 1.1292e-3 - 2.3410e-4*log(R) - 8.7754e-8*pow(log(R), 3);
}

// Define the bisection function
void bisection(double a, double b, double T, double tol, int max_iter, double *R, int *iter) {
    // Initialize the iteration counter
    *iter = 0;
    
    // Check if the initial values bracket the root
    if (f(a, T)*f(b, T) >= 0) {
        printf("Error: initial values do not bracket the root\n");
        return;
    }
    
    // Perform the bisection method
    while ((b-a)/2 > tol && *iter < max_iter) {
        double c = (a+b)/2;0
        if (f(c, T) == 0) {
            *R = c;
            return;
        }
        else if (f(c, T)*f(a, T) < 0) {
            b = c;
        }
        else {
            a = c;
        }
        (*iter)++;
    }
    
    // Set the final value of R
    *R = (a+b)/2;
}

// Define the function to find the temperature for a given resistance value
double find_T(double R) {
    // Convert the resistance to natural log
    double ln_R = log(R);
    
    // Use the given equation to solve for T
    double T = 1/(1.1292e-3 + 2.3410e-4*ln_R + 8.7754e-8*pow(ln_R, 3));
    
    // Convert T to Celsius
    T = T - 273.15;
    
    return T;
}

// Define the main function
int main() {
    // Define the temperature values in Celsius
    double T_values[] = {-20, 0, 20, 100};
    
    // Define the initial values for the bisection method
    double a = 100;
    double b = 100000;
    
    // Set the tolerance and maximum number of iterations
    double tol = 0.01;
    int max_iter = 1000;
    
    // Iterate over the temperature values and find the corresponding resistance values
    for (int i = 0; i < 4; i++) {
        // Convert the temperature to Kelvin
        double T = T_values[i] + 273.15;
        
        // Initialize the variables for the bisection method
        double R;
        int iter;
        
        // Use the bisection method to find the resistance value
        bisection(a, b, T, tol, max_iter, &R, &iter);
        
        // Print the results
        printf("Temperature: %g C, Resistance: %g ohm, Iterations: %d\n", T_values[i], R, iter);
    }
    
    // Test the find_T function
    double R_test1 = 500;
    double R_test2 = 25000;
    double T_test1 = find_T(R_test1);
    double T_test2 = find_T(R_test2);
    printf("Temperature for R_test1 = %g ohm: %g C\n", R_test1, T_test1);
    printf("Temperature for R_test2 = %g ohm: %g C\n", R_test2, T_test2);
    
    return 0;
}
