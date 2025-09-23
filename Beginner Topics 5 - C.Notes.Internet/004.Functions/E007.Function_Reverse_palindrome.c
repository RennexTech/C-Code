#include <stdio.h>

// Function prototypes to tell the compiler about our functions.
// `reverse` will take a `long int` and return a `long int`.
// `ispalindrome` will take a `long int` and return an `int` (1 for true, 0 for false).
long int reverse(long int n);
int ispalindrome(long int num);

int main()
{
    // A `long int` is used to handle larger numbers, preventing overflow issues.
    long int num;

    printf("Enter a number: ");
    scanf("%ld", &num);

    // We call the `ispalindrome` function to check if the number is a palindrome.
    // Based on the `1` or `0` it returns, we print the appropriate message.
    if (ispalindrome(num))
    {
        printf("Number is a palindrome\n");
    }
    else
    {
        printf("Number is not a palindrome\n");
    }

    return 0;
}

// This function reverses a number.
// Think of it like taking a number written on a whiteboard, erasing the last digit,
// and then adding it to a new number being built in reverse order.
long int reverse(long int n)
{
    // `rev` will hold our reversed number, starting at 0.
    // `rem` will hold the remainder, which is the last digit.
    long int rev = 0, rem;

    // This `while` loop runs as long as the original number `n` is greater than 0.
    while (n > 0)
    {
        // 1. Get the last digit: The modulo operator `%` gives us the last digit of the number.
        rem = n % 10;

        // 2. Build the reversed number: We shift our current `rev` value to the left
        // by multiplying it by 10 and then add the new digit (`rem`).
        // For example, if `rev` is 12 and `rem` is 3, `rev` becomes `12 * 10 + 3 = 123`.
        rev = rev * 10 + rem;

        // 3. Remove the last digit from the original number: Integer division `n / 10`
        // effectively "chops off" the last digit.
        n = n / 10;
    }
    return rev;
}

// This function is the chief inspector, checks if a number is a palindrome by comparing it to its reversed version.
// A palindrome is a number (or word) that reads the same backward as it does forward.
int ispalindrome(long int num)
{
    // We call our `reverse` function, and if the original number is exactly the same as
    // its reversed version, it's a palindrome.
    // The `==` operator performs a comparison.
    if (num == reverse(num))
    {
        // If they match, we return 1 (true).
        return 1;
    }
    else
    {
        // If they don't match, we return 0 (false).
        return 0;
    }
}

/**
 * 
 * A palindrome is any sequence of characters (like a word or a number) that reads the same forwards and backward. 
 * Think of words like "level," "madam," or "racecar."  In this program, we are checking for number palindromes, such as 121, 12321, or 55.
 *  
 */