/* Find out the factorial of a number */

#include <stdio.h>
long int factorial(int n);

int main() {
    int n;
    printf("Enter a number : \n");
    scanf("%d", &n);

    // Factorials are only defined for non-negative integers.
    // We check for negative numbers first to avoid issues.
    if (n < 0) {
        printf("No factorial of negative number\n");
    } else {
        printf("Factorial of %d is %ld\n", n, factorial(n));
    }
    return 0;
}

// This function calculates the factorial iteratively.
long int factorial(int n) {
    int i;
    // We start with our result set to 1, because anything multiplied by 1 is itself.
    // This is also the correct result for the factorial of 0.
    long int fact = 1;

    // The factorial of 0 is a special case, so we handle it immediately.
    if (n == 0) {
        return 1;
    }

    // This loop starts from the number we entered and multiplies down to 2.
    // For 5!, it's like a chain reaction: 1 * 5, then * 4, then * 3...
    for (i = n; i > 1; i--) {
        fact = fact * i;
    }

    // Return the final product of all the numbers in the sequence.
    return fact;
}