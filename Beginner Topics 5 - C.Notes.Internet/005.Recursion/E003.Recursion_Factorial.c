#include <stdio.h>

// This is the function prototype. It tells the compiler that we have a function
// called `factorial` that takes an integer (`n`) and returns a `long int`.
long int factorial(int n);

int main()
{
    // `n` is the number from the user. `fact` will hold the result.
    int n;

    // We ask the user to input a number.
    printf("Enter a number: \n");
    scanf("%d", &n);

    // This check is crucial for handling invalid input. Factorials are only defined
    // for non-negative integers.
    if (n < 0)
    {
        printf("No factorial of a negative number.\n");
    }
    else
    {
        // We call our `factorial` function and print the result.
        printf("Factorial of %d is %ld\n", n, factorial(n));
    }

    return 0;
}

// This function calculates the factorial of a number using recursion.
// A **factorial** is the product of all positive integers less than or equal to a given number.
// For example, 5! (five factorial) is 5 * 4 * 3 * 2 * 1 = 120.
long int factorial(int n)
{
    // This is the **base case**. It tells the recursion when to stop.
    // The factorial of 0 is 1, and this condition prevents an infinite loop.
    if (n == 0)
    {
        return 1;
    }
    // This is the **recursive step**. It's the core of the function.
    // Think of it as a set of nested requests. To find `5!`, we first ask for `4!`,
    // and to find `4!`, we ask for `3!`, and so on, until we hit the base case of `0!`.
    else
    {
        return n * factorial(n - 1);
    }
}

/*

The Analogy: A Set of Nested Questions ❓
Imagine you're trying to find the factorial of 4.

You ask: "What is 4!?"

The function answers: "I don't know yet, but I know it's 4 * (3!)." It then asks for 3!.

You ask: "What is 3!?"

The function answers: "I don't know, but it's 3 * (2!)." It asks for 2!.

You ask: "What is 2!?"

The function answers: "It's 2 * (1!)." It asks for 1!.

You ask: "What is 1!?"

The function answers: "It's 1 * (0!)." It asks for 0!.

You ask: "What is 0!?"

The function answers: "That's the base case! The answer is 1."

Now the answers start coming back up the chain:

1! = 1 * (the answer for 0!) = 1 * 1 = 1

2! = 2 * (the answer for 1!) = 2 * 1 = 2

3! = 3 * (the answer for 2!) = 3 * 2 = 6

4! = 4 * (the answer for 3!) = 4 * 6 = 24

This is exactly how the recursive function works behind the scenes, making it a very elegant solution to this problem.

*/