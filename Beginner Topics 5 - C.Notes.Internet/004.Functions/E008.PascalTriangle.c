#include <stdio.h>

// This is the function prototype for the `factorial` function. It takes an integer
// and returns a `long int`, which can store larger numbers than a standard `int`.
long int factorial(int n);

// This is the function prototype for `comb` (for combination). It takes two integers
// and returns a `long int`.
long int comb(int n, int r);

int main()
{
    int i, j, k;

    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &k);

    // This is the outer loop that handles the rows of the triangle.
    // It runs `k` times, once for each row.
    for (i = 0; i < k; i++)
    {
        // This inner loop prints the spaces to center the triangle.
        // The number of spaces decreases with each row.
        for (j = 0; j < k - i; j++)
        {
            printf("  "); // Print two spaces for alignment.
        }

        // This loop calculates and prints the numbers for the current row.
        // It runs from `j = 0` up to `i` (the row number).
        for (j = 0; j <= i; j++)
        {
            // We call our `comb` function to get the number for the current position.
            // `comb(i, j)` calculates "i choose j."
            printf("%5ld", comb(i, j));
        }

        // After each row, we print a newline character to move to the next line.
        printf("\n");
    }

    return 0;
}

// This function calculates the combination `n choose r`.
// It uses our `factorial` function to compute the values and then
// applies the formula $C(n,r) = n! / (r! * (n-r)!)$.
long int comb(int n, int r)
{
    long int c;
    c = factorial(n) / (factorial(r) * factorial(n - r));
    return c;
}

// This function calculates the factorial of a number.
// For example, factorial of 5 (5!) is `5 * 4 * 3 * 2 * 1`.
// We use a `long int` to avoid overflow, as factorials grow very quickly.
long int factorial(int n)
{
    // Our accumulator, `fact`, is set to 1.
    long int fact = 1;

    // The factorial of 0 is 1, by definition. We handle this as a base case.
    if (n == 0)
    {
        return 1;
    }

    // The FIX: The loop variable should be `n`, and the loop condition should be `n > 0`.
    // It's like multiplying the number by all the whole numbers down to 1.
    for (; n > 0; n--)
    {
        fact = fact * n;
    }

    return fact;
}

// Pascal's Triangle is a triangular array of binomial coefficients. 
// It starts with a 1 at the top, and each number below is the sum of the two numbers directly above it. 
