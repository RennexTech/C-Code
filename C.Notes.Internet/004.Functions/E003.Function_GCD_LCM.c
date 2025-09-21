#include <stdio.h>

// This is a function prototype. It tells the compiler about the `lcm_gcd` function
// before it's used. It says the function takes two integers and doesn't return anything.
void lcm_gcd(int, int);

// The correct signature for the main function is `int main()`.
int main()
{
    // We declare two integer variables to hold the numbers the user will input.
    int n1, n2;

    // This line prompts the user for input.
    printf("Enter two numbers:\n");

    // We read the two numbers from the user and store them in `n1` and `n2`.
    scanf("%d %d", &n1, &n2);

    // We call our `lcm_gcd` function, passing the two numbers to it.
    lcm_gcd(n1, n2);

    return 0; // Return 0 to indicate successful execution.
}

// This function calculates and prints the Least Common Multiple (LCM) and
// Greatest Common Divisor (GCD) of two numbers.
void lcm_gcd(int n1, int n2)
{
    // Our variables for the calculation.
    // `gcd` will store the greatest common divisor.
    // `lcm` will store the least common multiple.
    // `rem` will hold the remainder in our division.
    // `a` and `b` are temporary variables used in the Euclidean algorithm.
    int gcd, lcm, rem, a, b;

    // We first check which number is larger to prepare for the Euclidean algorithm.
    // The algorithm works by dividing the larger number by the smaller one.
    // We'll put the larger number in `a` and the smaller one in `b`.
    if (n1 > n2)
    {
        a = n1;
        b = n2;
    }
    else
    {
        a = n2;
        b = n1;
    }

    // This is the core of the GCD calculation, known as the **Euclidean algorithm**.
    // Think of it as a game of subtraction: we repeatedly find the remainder
    // of the larger number divided by the smaller one, and then repeat the process
    // with the smaller number and the remainder. The game ends when the remainder is 0.
    // The last non-zero remainder is the GCD.
    rem = a % b; // Get the initial remainder.
    while (rem != 0)
    {
        a = b;      // The smaller number becomes the new larger number.
        b = rem;    // The remainder becomes the new smaller number.
        rem = a % b; // Find the next remainder.
    }

    // The last non-zero value of `b` is our GCD.
    gcd = b;

    // We use a simple formula to calculate the LCM:
    // LCM = (n1 * n2) / GCD
    lcm = (n1 * n2) / gcd;

    // Finally, we print the results.
    printf("GCD of %d and %d = %d\n", n1, n2, gcd);
    printf("LCM of %d and %d = %d\n", n1, n2, lcm);
}


// Original code used void main() which isn't standard. It's usually int main()

// Master one tool before chasing the next. Fear of Missing out (FOMO) will ensure you never learn anything if you allow it. 

