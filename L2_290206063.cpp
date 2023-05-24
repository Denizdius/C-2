#include <stdio.h>
#include <math.h>

#define MAXSIZE 10

// Function to compute the value of a polynomial of degree n with coefficients a at x
float polysum(int n, float a[], float x) {
    float sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += a[i] * pow(x, n-i);
    }
    return sum;
}

// Function to find the root of a polynomial using the interval method
float interval_method(int n, float a[], float x1, float x2, float step) {
    int iter = 0;
    float x = x1;
    while (x <= x2) {
        float fx = polysum(n, a, x);
        printf("f(%g)=%g, f(%g)=%g, f(%g)=%g\n", x, fx, x+step/2, polysum(n, a, x+step/2), x+step, polysum(n, a, x+step));
        if (fx == 0) {
            printf("Interval method: Root found at x = %g after %d iterations\n", x, iter);
            return x;
        }
        if (fx * polysum(n, a, x+step) < 0) {
            // Change of sign, root is in the interval [x, x+step]
            float root = x + step/2;
            printf("Interval method: Root found at x = %g after %d iterations\n", root, iter);
            return root;
        }
        x += step;
        iter++;
    }
    printf("Interval method: Root not found after %d iterations\n", iter);
    return NAN;
}

// Function to find the root of a polynomial using the bisection method
float bisection_method(int n, float a[], float x1, float x2, float tol, int max_iter) {
    int iter = 0;
    while (iter < max_iter) {
        float x = (x1 + x2) / 2;
        float fx = polysum(n, a, x);
        printf("f(%g)=%g, f(%g)=%g, f(%g)=%g\n", x1, polysum(n, a, x1), x2, polysum(n, a, x2), x, fx);
        if (fabs(fx) < tol) {
            printf("Bisection method: Root found at x = %g after %d iterations\n", x, iter);
            return x;
        }
        if (fx * polysum(n, a, x1) < 0) {
            x2 = x;
        } else {
            x1 = x;
        }
        iter++;
    }
    printf("Bisection method: Root not found after %d iterations\n", iter);
    return NAN;
}

// Main function
int main() {
    int n;
    float a[MAXSIZE];
    float x1, x2, step;
    int max_iter;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients of the polynomial (in descending order of degree):\n");
    for (int i = 0; i <= n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }
    printf("Given polynomial is:");
    for (int i = n; i >= 0; i--) {
        printf("%+.2f*x^%d", a[i], i);
    }
    printf(" = 0\n");
    printf("Enter the interval to search for roots: ");
    scanf("%f %f", &x1, &x2);
    printf("Enter the step size for the interval method: ");
    scanf("%f", &step);
    printf("Enter the maximum number of iterations for the bisection method: ");
    scanf("%d", &max_iter);
    
    // Compute the tolerance level for the bisection method
    float tol = (x2 - x1) / pow(2, max_iter);
    
    // Find the root using the interval method
    float root_interval = interval_method(n, a, x1, x2, step);
    if (!isnan(root_interval)) {
        printf("Root found by interval method: %g\n", root_interval);
    }
    
    // Find the root using the bisection method
    float root_bisection = bisection_method(n, a, x1, x2, tol, max_iter);
    if (!isnan(root_bisection)) {
        printf("Root found by bisection method: %g\n", root_bisection);
    }
    
    return 0;
}
