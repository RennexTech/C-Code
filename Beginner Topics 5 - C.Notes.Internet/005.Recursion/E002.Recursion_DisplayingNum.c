#include <stdio.h>

// Function prototype for `display1`.
// It takes an integer and returns an integer.
int display1(int n);

// Function prototype for `display2`.
// It takes an integer and returns an integer.
int display2(int n);

int main()
{
    int n;

    printf("\nRecursion: Displaying numbers in a range.\n");
    printf("Input the last number of a range starting from 1: ");
    scanf("%d", &n);

    // We'll call `display1` and then print a newline for separation.
    printf("\nDisplaying numbers from %d down to 1 (using display1):\n", n);
    display1(n);
    printf("\n"); // A simple newline to clean up the output.

    // We'll call `display2` and then print a newline for separation.
    printf("\nDisplaying numbers from 1 up to %d (using display2):\n", n);
    display2(n);
    printf("\n");

    return 0;
}

// ## The Two Faces of Recursion

// The functions below both use **recursion**, which is a technique where a function
// calls itself. Think of it like a set of nested Russian dolls. You open one doll
// to find a smaller version inside, and you keep doing that until you find the
// smallest one. Once you open the smallest doll, you start closing them up, one by one.

// This function prints numbers in descending order.
// This is the "tail recursion" approach. The work (printing) is done *before*
// the recursive call. It's like a person walking down a staircase, shouting the
// step number as they go down.
int display1(int n)
{
    // This is the **base case**. It tells the function when to stop.
    // When `n` becomes 0, we've reached the end of our work, so we return.
    if (n == 0)
        return 0; // Return a simple value to end the function call.

    // This is the **recursive step**. We do the work here.
    // We print the current number `n`.
    printf("%d ", n);

    // We call the function again, passing `n - 1`.
    // This creates a new, smaller task.
    return display1(n - 1); // Pass the return value up the call stack.
}

// This function prints numbers in ascending order.
// This is the "head recursion" approach. The work (printing) is done *after*
// the recursive call. It's like a person walking down a staircase without speaking,
// then shouting the step number as they come back up.
int display2(int n)
{
    // This is the **base case**, same as before.
    if (n == 0)
        return 0; // The function stops here.

    // This is the **recursive step**. The work is delayed.
    // We first call the function with a smaller number (`n - 1`).
    // This pushes the current function call onto a stack, waiting for the
    // next call to finish.
    display2(n - 1);

    // The work happens here, on the way back up the call stack.
    // The smallest number is printed first, then the next, and so on.
    printf("%d ", n);

    return 0; // Return a simple value.
}