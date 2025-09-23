#include <stdio.h>

// This is the function prototype. It tells the compiler that a function named
// `summation` exists, which takes an integer and returns an integer.
int summation(int);

int main()
{
    int n1; // The number the user enters.
    int sum; // The variable to store the final sum.

    printf("Recursion: Calculate the sum of numbers from 1 to n.\n");
    printf("Input the last number of the range starting from 1: ");
    scanf("%d", &n1);

    // Call the `summation` function to get the sum of numbers from 1 to `n1`.
    sum = summation(n1);

    // Print the final result.
    printf("The sum of numbers from 1 to %d is: %d\n", n1, sum);

    return 0;
}

// This function calculates the sum of all numbers from 1 up to `n1` using recursion.
// **Recursion** is when a function calls itself. Think of it like a chain of requests.
int summation(int n1)
{
    // This is the **base case**. It's the condition that stops the recursion.
    // When the number `n1` becomes 0, we've reached the end of our range.
    // We return 0, as adding 0 to a sum doesn't change the value.
    if (n1 == 0) {
        return 0; // The FIX: Changed from `return 1;` to `return 0;`.
    }

    // This is the **recursive step**. This is where the magic happens.
    // The function returns the current number (`n1`) plus the result of a smaller,
    // identical problem: the sum of all numbers from 1 up to `n1 - 1`.
    // The function keeps calling itself with a smaller number until it hits the base case.
    return (n1 + summation(n1 - 1));
}