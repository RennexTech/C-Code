#include <stdio.h>

// This is the function prototype. It tells the compiler about the `fib` function,
// which takes an integer `n` and returns an integer.
int fib(int n);

int main()
{
    // `nterms` will store the number of terms the user wants to see in the sequence.
    int nterms, i;

    printf("Enter the number of terms: ");
    scanf("%d", &nterms);

    // This `for` loop calls the `fib` function for each term, from 0 up to `nterms - 1`.
    for (i = 0; i < nterms; i++)
        printf("%d ", fib(i));

    printf("\n"); // Prints a newline for clean output.

    return 0;
}

// This function calculates the Nth term of the Fibonacci sequence using recursion.
// The **Fibonacci sequence** is a series of numbers where each number is the sum
// of the two preceding ones, usually starting with 0 and 1.
// The sequence looks like this: 0, 1, 1, 2, 3, 5, 8, 13, ...
// 
int fib(int n)
{
    // This is the **base case**. It's the most important part of recursion.
    // It tells the function when to stop. Without a base case, recursion runs forever.
    // We define the starting points of the sequence: `fib(0)` is 0 and `fib(1)` is 1.
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        // This is the **recursive step**. It's the magic of the Fibonacci sequence.
        // To find `fib(n)`, the function calls itself twice: once for `fib(n-1)`
        // and once for `fib(n-2)`. The sum of these two calls gives the answer.
        // For example, to find `fib(4)`, the function will call `fib(3)` and `fib(2)`.
        return (fib(n - 1) + fib(n - 2));
}


/*

The Analogy: The Russian Doll of Functions 🪆
Think of the fib function as a set of nested requests, like Russian dolls.

Imagine you ask the program to find fib(4).

Request 1: fib(4) is asked. It doesn't know the answer, so it breaks the problem down and asks for two smaller parts: fib(3) and fib(2).

Request 2 & 3: fib(3) is asked, which in turn asks for fib(2) and fib(1). fib(2) is also asked, which asks for fib(1) and fib(0).

The Base Case: Eventually, these requests get so small they hit the base cases: fib(0) and fib(1). These "dolls" aren't hollow; they have a number inside! fib(0) returns 0 and fib(1) returns 1.

The Unwinding: Once the base cases are hit, the answers start traveling back up the chain of requests, adding as they go.

fib(2) gets the answers for fib(1) (1) and fib(0) (0), and adds them to get 1.

fib(3) gets the answers for fib(2) (1) and fib(1) (1), and adds them to get 2.

Finally, fib(4) gets the answers for fib(3) (2) and fib(2) (1), and adds them to get the final result: 3.

This recursive process, where a problem is broken down into smaller, identical problems until a simple, solvable base case is reached, is the essence of this code.

*/