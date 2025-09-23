#include <stdio.h>

// This is the function prototype. It tells the compiler about the `sumOfDigits` function,
// which takes an integer and returns an integer.
int sumOfDigits(int n);

int main()
{
    // Declares an integer `n` to store the number from the user, and `result` to store the sum.
    int n, result;

    printf("Enter a number: ");
    // FIX: The `scanf` format specifier is now `%d` to match the integer variable `n`.
    scanf("%d", &n);

    // Calls the `sumOfDigits` function to compute the sum.
    result = sumOfDigits(n);

    // Prints the final result.
    printf("The sum of digits in %d is %d\n", n, result);

    return 0;
}

// This function calculates the sum of the digits of a number using recursion.
int sumOfDigits(int n)
{
    // The **base case**. This is the most crucial part of recursion.
    // It's the stopping condition. If the number has only one digit (i.e., `n / 10` is 0),
    // we simply return that digit, as there's nothing left to add.
    if (n / 10 == 0)
        return n;

    // The **recursive step**. This is where the magic happens.
    // We add the last digit (`n % 10`) to the sum of the remaining digits (`sumOfDigits(n / 10)`).
    // The function keeps calling itself with a smaller number (`n / 10` effectively removes the last digit)
    // until it hits the base case.
    return (n % 10 + sumOfDigits(n / 10));
}