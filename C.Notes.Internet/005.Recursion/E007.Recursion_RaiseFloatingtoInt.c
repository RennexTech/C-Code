#include <stdio.h>

// This is the function prototype for `power`. It tells the compiler that we have a
// function that takes a floating-point number (`a`) and an integer (`n`), and
// returns a floating-point number.
float power(float a, int n);

int main()
{
    // `a` is our base number, and `n` is the exponent (the power we want to raise it to).
    // `p` will store the final result.
    float a, p;
    int n;

    printf("Enter the base and exponent (a and n): ");
    scanf("%f%d", &a, &n);

    p = power(a, n);

    // Finally, we print the result.
    printf("%f raised to the power of %d is %f\n", a, n, p);

    return 0;
}

// This function calculates the power of a number using recursion.
// It's like a chain of multiplication requests.
float power(float a, int n)
{
    // This is the **base case**. It's the condition that stops the recursion.
    // Any number raised to the power of 0 is 1. This is where the chain of
    // recursive calls ends.
    if (n == 0)
        return 1;
    
    // **Handling Negative Exponents**
    // The recursive approach for positive exponents doesn't work for negative ones.
    // For a negative exponent, we use the rule: a⁻ⁿ = 1 / aⁿ.
    // For example, 2⁻³ = 1 / 2³.
    if (n < 0)
        return 1 / power(a, -n);

    // This is the **recursive step**. It's the core of the function.
    // To find `aⁿ`, the function asks for `aⁿ⁻¹` and then multiplies it by `a`.
    // It's a series of self-replicating requests.
    return (a * power(a, n - 1));
}

