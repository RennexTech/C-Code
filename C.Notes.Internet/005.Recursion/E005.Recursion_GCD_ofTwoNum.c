/* Find the Greatest Common Divisor (GCD) */

#include <stdio.h>

// This is the function prototype for `GCD`. It tells the compiler about our function
// which takes two integers and returns an integer.
int GCD(int num1, int num2);

int main()
{
    // Declaring variables to hold the two numbers entered by the user.
    int num1, num2;

    // Prompting the user for input and reading the two positive integers.
    printf("Enter two positive integers: ");
    scanf("%d%d", &num1, &num2);

    // Calling the `GCD` function and printing the result.
    printf("The GCD of %d and %d is %d\n", num1, num2, GCD(num1, num2));

    return 0;
}

// This function calculates the GCD of two numbers using recursion.
// The **Greatest Common Divisor (GCD)** is the largest positive integer that
// divides both numbers without a remainder. 
int GCD(int num1, int num2)
{
    // This is the **base case**. It's the condition that stops the recursion.
    // The Euclidean algorithm says that the GCD of a number and 0 is the number itself.
    if (num2 == 0)
    {
        return num1;
    }

    // This is the **recursive step**. It's the magic behind the algorithm.
    // We call the `GCD` function again with the second number (`num2`) and the
    // remainder of the first number divided by the second (`num1 % num2`).
    // This process continues until the remainder becomes 0.
    return GCD(num2, num1 % num2);
}


/*

The Analogy: The Remainder Game 🎲

Imagine you have two numbers, say 48 and 18, and you want to find their GCD. Think of it as a game where you keep shrinking the numbers until you find the perfect one that fits into both.

Start: You have the pair (48, 18). You divide 48 by 18.

48÷18=2 with a remainder of 12.

New Pair: Your next pair is the old second number and the remainder: (18, 12). You divide 18 by 12.

18÷12=1 with a remainder of 6.

New Pair: Your new pair is (12, 6). You divide 12 by 6.

12÷6=2 with a remainder of 0.

End of Game: The remainder is 0! The game ends. The last non-zero number in the pair (the second number, which is now 6) is the GCD.

The code's return GCD(num2, num1 % num2); line perfectly captures this game, where num1 becomes the new num2, and num2 becomes the new remainder. This continues until num2 is 0, at which point the last num1 is the answer.

*/