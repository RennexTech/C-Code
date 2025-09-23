#include <stdio.h>

// This is the function prototype for `func`. It tells the compiler that we have
// a function called `func` that takes an integer `num` and another integer `b`,
// and doesn't return any value (`void`).
void func(int num, int b);

// This is the main function where the program begins execution.
int main(void)
{
    // Declare integer variables for the user's decimal number and their choice.
    int num, ch;

    // Prompt the user to enter a decimal number and read their input.
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Display the conversion options to the user.
    printf("1.Binary\n2.Octal\n3.Hexadecimal\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    // A `switch` statement is used to execute different code blocks based on the user's choice.
    switch (ch)
    {
    case 1:
        // If the user chooses 1, call `func` with `num` and a base of 2 (for binary).
        printf("Binary equivalent is: ");
        func(num, 2);
        break; // `break` exits the switch statement.

    case 2:
        // If the user chooses 2, call `func` with `num` and a base of 8 (for octal).
        printf("Octal equivalent is: ");
        func(num, 8);
        break;

    case 3:
        // If the user chooses 3, call `func` with `num` and a base of 16 (for hexadecimal).
        printf("Hexadecimal equivalent is: ");
        func(num, 16);
        break;
    }

    // Print a newline for a clean output.
    printf("\n");
    return 0;
}

// This function converts a decimal number to a number in a different base.
// `num` is the decimal number to convert, and `b` is the base to convert to (2, 8, or 16).
void func(int num, int b)
{
    // `rem` will hold the remainder of the division.
    // `i` is our counter for the array.
    // `arr` is a character array to store the digits of the converted number.
    int rem, i = 0;
    char arr[20];

    // The core conversion logic is performed in this `while` loop.
    // It continues as long as `num` is greater than 0.
    while (num > 0)
    {
        // Calculate the remainder when `num` is divided by the base `b`. This gives us the next digit.
        rem = num % b;

        // Update `num` by dividing it by the base.
        num = num / b;

        // This `if` block handles hexadecimal digits A-F.
        // If the remainder is a value from 10 to 15, we convert it to its
        // corresponding character ('A' for 10, 'B' for 11, etc.).
        if (rem > 9 && rem < 16)
            arr[i++] = rem - 10 + 'A';
        else
            // If the remainder is a single digit (0-9), we convert it to its character representation.
            arr[i++] = rem + '0';
    }

    // This loop prints the digits in the correct order.
    // The `while` loop generated the digits in reverse, so we iterate backwards to print them correctly.
    for (int j = i - 1; j >= 0; j--)
        printf("%c", arr[j]);
}