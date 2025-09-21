#include <stdio.h>
#include <stdlib.h>

// This function adds two numbers and returns the sum.
// It's the simplest use case: the function does its job and hands back the result.
int addition(int a, int b) {
    return a + b;
}

// This function divides two numbers but has a built-in safety check.
// The `if` statement is an "early return." It's like a bouncer at a club;
// if the condition (`b == 0`) is met, the function immediately kicks the process out
// and returns an error value before anything bad happens.
int division(int a, int b) {
    if (b == 0) {
        return 0; // Return 0 to signal an error
    }
    return a / b;
}

// This function uses a `switch` statement to pick a value to return.
// Think of it as a vending machine. You give it a choice, and it gives
// you a specific item (`return 10` or `return 20`) back. If you give
// it a wrong choice, it gives you a fallback item (`return -1`).
int getValue(int choice) {
    switch (choice) {
        case 1:
            return 10;
        case 2:
            return 20;
        default:
            return -1; // Return -1 for an invalid choice
    }
}

// This function is for adding two numbers, similar to the `addition` function.
int add(int a, int b) {
    return a + b;
}

// This function subtracts and includes an early return for an error.
int subtract(int a, int b) {
    // This is another safety check. If 'a' is zero, it's not allowed, so we print a message
    // and immediately exit with an error code before doing any calculations.
    if (a == 0) {
        printf("Enter a valid number, zero not allowed.\n");
        return 2; // Return 2 to signal that an invalid digit was entered.
    }
    return a - b;
}

// This function doesn't return any value; its return type is `void`.
// It just does something (like printing to the screen) and that's it.
// The `return;` statement here isn't necessary, but it can be used to
// exit the function early for clarity. It's like just saying "I'm out"
// without handing anything back.
void showMessage() {
    printf("Hey, jackie!\n");
    return;
}

// This block of code compares two dates.
// It uses a cascade of early returns to efficiently check the conditions.
// The logic is: "First, check the years. If they're different, we're done.
// If not, move on and check the months. If they're different, we're done.
// If not, check the days. If they're different, we're done.
// If we get all the way to the end, it means they were all the same, so we return 0."
int compareDates(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 < y2) {
        return 1;
    } else if (y1 > y2) {
        return -1;
    }

    if (m1 < m2) {
        return 1;
    } else if (m1 > m2) {
        return -1;
    }

    if (d1 < d2) {
        return 1;
    } else if (d1 > d2) {
        return -1;
    }

    return 0;
}

// This is a classic factorial function.
// It has a base case (`n == 0`) that uses an early return. This is crucial for
// making sure the function doesn't run forever when used with recursion.
// For example, 0! is 1, so if the input is 0, the function just returns 1 immediately.
long int factorial(int n) {
    int i;
    long int fact = 1;

    if (n == 0)
        return 1;

    for (i = n; i > 1; i--) {
        fact *= i;
    }

    return fact;
}

int main() {
    printf("--- Function Examples ---\n");
    printf("Addition (5 + 3) -> %d\n", addition(5, 3));
    printf("Division (10 / 2) -> %d\n", division(10, 2));
    printf("Division (10 / 0) -> %d\n", division(10, 0));
    printf("Get value (choice 1) -> %d\n", getValue(1));
    printf("Get value (choice 5) -> %d\n", getValue(5));
    printf("Subtraction (5 - 3) -> %d\n", subtract(5, 3));
    printf("Subtraction (0 - 3) -> %d\n", subtract(0, 3));
    
    printf("\n--- `void` Example ---\n");
    showMessage();

    printf("\n--- Date Comparison Example ---\n");
    printf("Comparing (2023/10/26) and (2023/10/25): %d\n", compareDates(2023, 10, 26, 2023, 10, 25));
    printf("Comparing (2024/01/01) and (2023/12/31): %d\n", compareDates(2024, 1, 1, 2023, 12, 31));

    printf("\n--- Factorial Example ---\n");
    printf("Enter a number to get its factorial: ");
    int num;
    scanf_s("%d", &num);
    if (num < 0) {
        printf("No factorial of a negative number.\n");
    } else {
        printf("Factorial of %d is %ld\n", num, factorial(num));
    }

    return 0; // Indicates successful execution
}
