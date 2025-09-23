// This program counts the number of even and odd integers entered by a user.

#include <stdio.h>

// A macro, `#define SIZE 10`, is like giving a name to the number 10.
// We use it so that if we ever want to change the size of our array,
// we only need to change this one line. It makes the code cleaner and easier to maintain.
#define SIZE 10

int main()
{
    // Our main variables.
    // `arr[SIZE]` is an array that can hold 10 integers.
    // `even` and `odd` are our counters, initialized to 0. We'll use them to keep
    // a tally of the even and odd numbers we find.
    int arr[SIZE], even = 0, odd = 0;

    // The `for` loop is a powerful tool for repetition. This loop will execute 10 times,
    // once for each slot in our array, from index `0` to `9`.
    for (int i = 0; i < SIZE; i++)
    {
        // We're asking the user to type in a number. The `arr[%d]` part of the prompt
        // tells the user which element we're currently asking for, like a numbered checklist.
        printf("Enter a value for arr[%d]: ", i);
        
        // The `scanf` function reads the integer the user types. The `&arr[i]` is a crucial part;
        // it provides the **memory address** of the current array slot so that `scanf` knows
        // exactly where to place the number.
        scanf("%d", &arr[i]);

        // This `if-else` block performs the core logic of the program.
        // `arr[i] % 2` uses the **modulo operator (%)**, which calculates the remainder of a division.
        // If a number divided by 2 has a remainder of 0, it's an even number.
        if (arr[i] % 2 == 0)
            // If the number is even, we increment our `even` counter.
            even++;
        else
            // Otherwise, it must be an odd number, so we increment the `odd` counter.
            odd++;
    }

    // Once the loop is finished and we've checked all 10 numbers, we print the final results.
    printf("Even Number = %d, Odd Number = %d\n", even, odd);

    return 0;
}