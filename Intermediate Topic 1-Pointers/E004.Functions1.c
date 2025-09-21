#include <stdio.h>
#include <stdlib.h> // For exit()

/*
 *
 * ## The Program's Blueprint: Understanding Functions
 *
 * Think of a program as a large-scale construction project. The `main()` function is the
 * lead architect. It doesn't do all the work itself; instead, it delegates tasks to
 * specialized teams, which we call **functions**.
 *
 * Each function has a specific job:
 * - A **declaration** (or prototype) is the architect's instruction to the compiler:
 * "There's a team called `first_function` that does something, and another team called
 * `second_function` that takes two integers and returns an integer."
 * The compiler needs this heads-up so it knows how to set up the call later.
 * This is why declarations are often put at the top, like a project's table of contents.
 *
 * - The **definition** is the actual work plan for that team—the step-by-step
 * instructions on how to perform the job. This is where the code logic lives.
 *
 *
 * Now, let's talk about the specific issue you saw with `scanf`. When you call `second_function(10, 2)`,
 * those values (`10` and `2`) are copied into the function's parameters, `num1` and `num2`.
 * But then, `scanf` comes along and overwrites those copies with whatever the user enters.
 * The original values in `main` are untouched, and the values you passed in are just gone.
 *
 * This is a fundamental concept in C called **pass-by-value**. The value is copied.
 * If you wanted to modify the original variables in `main`, you'd have to use **pass-by-reference**
 * with pointers, which is a whole other level of C magic.
 *
 */

// Function declarations: The project's table of contents.
// This tells the compiler what to expect later in the code.
void first_function();
int second_function(int num1, int num2);
int second_function_interactive();

int main() {
    printf("Hello world!\n");

    // The architect calls the 'first_function' team. It's a simple task.
    first_function();

    // Now, let's call the 'second_function' team. We'll use the original, intended
    // version that uses the arguments passed to it, just like your note suggested.
    // We are passing the values 10 and 2.
    int result_from_arguments = second_function(10, 2);

    printf("\n## Result from function using arguments (10 and 2):\n");
    if (result_from_arguments == -1) {
        printf("Error: Division by zero!\n");
    } else {
        printf("Result of division: %d\n", result_from_arguments);
    }
    printf("\n");

    // Let's also run the *interactive* version to demonstrate why it's a bit
    // clunky, just as you originally observed.
    printf("## Now calling the interactive function...\n");
    int result_from_user_input = second_function_interactive();

    if (result_from_user_input == -1) {
        printf("Error: Division by zero!\n");
    } else {
        printf("Result of division: %d\n", result_from_user_input);
    }

    return 0; // Return 0 to the OS, signaling success.
}


// Function definitions: The detailed work plans.

// A simple function that just does one thing and returns nothing.
void first_function() {
    printf("Hey, I'm the first function!\n");
}

/*
 * This is the corrected version of your function. It trusts the caller
 * to provide the numbers and doesn't ask for them again. This is more
 * predictable and is how most functions should operate.
 */
int second_function(int num1, int num2) {
    if (num2 == 0) {
        return -1; // Return a specific error code for division by zero.
    }

    return num1 / num2;
}

/*
 * This version of the function is what you originally had. It's interactive
 * and demonstrates the "overriding" of the passed-in arguments with `scanf`.
 * It's not necessarily "wrong," just a design choice.
 */
int second_function_interactive() {
    int num1, num2; // These are local variables; they are NOT the ones from main.

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (num2 == 0) {
        return -1;
    }

    return num1 / num2;
}
