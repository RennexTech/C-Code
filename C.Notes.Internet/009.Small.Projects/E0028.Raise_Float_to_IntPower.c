#include <stdio.h>
#include <math.h> // Include this header for the abs() function
double power(double a, int n);

int main() {
    double a;
    int n;
    
    printf("Enter base : \n");
    scanf("%lf", &a);
    
    printf("Enter Exponent : \n");
    scanf("%d", &n);
    
    printf("%lf raised to power %d is %lf\n", a, n, power(a, n));
    
    return 0;
}

double power(double a, int n) {
    int i;
    double p = 1.0;
    
    // Any number raised to the power of 0 is 1. This is the base case.
    if (n == 0) {
        return 1.0;
    }
    
    // We use a loop to multiply the base 'a' by itself 'n' times.
    // The `abs(n)` ensures the loop runs for the absolute value of the exponent,
    // so it works for both positive and negative powers.
    for (i = 1; i <= abs(n); i++) {
        p = p * a;
    }
    
    // If the original exponent 'n' was positive, we just return the result 'p'.
    // If 'n' was negative, we return 1 divided by the result to get the correct value.
    if (n > 0) {
        return p;
    } else {
        return 1.0 / p;
    }
}