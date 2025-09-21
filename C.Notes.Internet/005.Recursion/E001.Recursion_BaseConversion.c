/* Convert a positive decimal number to Binary, Octal, or Hexadecimal using recursion. */

#include <stdio.h>
#include <stdlib.h> // We need this header for the `exit()` function.

// This is the function prototype. It tells the compiler about our `convert` function,
// which takes an integer `num` and an integer `base` and doesn't return a value.
void convert(int, int);

int main()
{
    // `num` stores the decimal number from the user.
    // `choice` stores the user's menu selection.
    // `base` stores the number system's base (2 for binary, 8 for octal, 16 for hexadecimal).
    int num, choice, base;

    // The `while(1)` loop creates an infinite loop, allowing the user to
    // perform multiple conversions without restarting the program.
    while (1)
    {
        // Displaying the menu options to the user.
        printf("Select conversion: \n\n");
        printf("1. Decimal to binary. \n");
        printf("2. Decimal to octal. \n");
        printf("3. Decimal to hexadecimal. \n");
        printf("4. Exit. \n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice); // The FIX: Added `&` to pass the address of `choice`.

        // The `switch` statement executes different code blocks based on the user's `choice`.
        switch (choice)
        {
            case 1:
                base = 2;
                break; // Exit the switch, but not the loop.

            case 2:
                base = 8;
                break;

            case 3:
                base = 16;
                break;

            case 4:
                printf("Exiting...\n");
                exit(0); // Exit the program.

            default:
                printf("Invalid choice. Please try again.\n\n");
                continue; // Skip the rest of the loop and go back to the start.
        }

        // We only ask for the number if the choice was valid (1, 2, or 3).
        printf("Enter a positive number: ");
        scanf("%d", &num); // The FIX: Added `&` to pass the address of `num`.

        printf("Result = ");
        
        // This is a small bug fix: if the user enters 0, we print 0 and then call convert.
        if (num == 0) {
            printf("0");
        } else {
            // We call our `convert` function with the number and the chosen base.
            convert(num, base);
        }

        printf("\n\n"); // Print newlines for clean output.
    }
    return 0;
}

// This function converts a number to a different base using **recursion**.
// Recursion is a function that calls itself. Think of a stack of tasks:
// We perform an operation, then we put a new, smaller task on top of the stack, and repeat.
// Once a task can't be broken down further, we start completing them one by one.
void convert(int num, int base)
{
    int rem;

    // This is our **base case**. It tells the function when to stop calling itself.
    // When `num` becomes 0, there are no more digits to convert, so we stop.
    if (num == 0)
    {
        return;
    }
    else
    {
        // This is the **recursive step**. We break the problem down into a smaller part.
        // We get the remainder (`rem`) which is our digit, then we call `convert`
        // again with `num / base`.
        rem = num % base;
        convert(num / base, base);

        // The magic happens here: the printing is done **after** the recursive call.
        // This ensures the digits are printed in the correct order (most significant first).
        if (base == 16 && rem >= 10)
        {
            // For hexadecimal, remainders from 10 to 15 are represented by letters A-F.
            // We use ASCII math to convert the number to its corresponding letter.
            printf("%c", rem + 55); // 10 + 55 = 65 (ASCII for 'A').
        }
        else
        {
            // For all other cases (binary, octal, or hex digits 0-9), we print the number.
            printf("%d", rem);
        }
    }
}