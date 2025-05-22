#include <stdio.h>
#include <stdlib.h> // For general utilities, not strictly needed for all examples here

int main() {
    /*
     * This program demonstrates fundamental control statements in C,
     * which dictate the flow of program execution. It covers conditional
     * statements (if, switch) and looping constructs (while, do-while, for),
     * along with flow modifiers (break, continue) and other related concepts.
     */

    int a = 10, b = 5, c = 20, d = 15, e = 25, f = 30;
    int value = 2; // For switch example
    int i, j;      // Loop counters
    int result;    // For ternary operator
    int *ptr = NULL; // For short-circuit evaluation example

    printf("--- if Statement ---\n");
    if (a > b) {
        printf("a is greater than b.\n");
    }

    printf("\n--- if-else Statement ---\n");
    if (a < b) {
        printf("a is less than b.\n");
    } else {
        printf("a is not less than b.\n");
    }

    printf("\n--- if-else if-else Statement ---\n");
    if (a > c) {
        printf("a is greater than c.\n");
    } else if (a == b) {
        printf("a is equal to b.\n");
    } else {
        printf("Neither condition was true.\n");
    }

    printf("\n--- switch Statement ---\n");
    switch (value) {
        case 1:
            printf("Value is 1.\n");
            break;
        case 2:
            printf("Value is 2.\n");
            break;
        default:
            printf("Value is something else.\n");
    }

    printf("\n--- while Loop ---\n");
    i = 0;
    while (i < 3) {
        printf("While loop iteration: %d\n", i);
        i++;
    }

    printf("\n--- do-while Loop ---\n");
    i = 0;
    do {
        printf("Do-while loop iteration: %d\n", i);
        i++;
    } while (i < 3);

    printf("\n--- for Loop ---\n");
    for (i = 0; i < 3; i++) {
        printf("For loop iteration: %d\n", i);
    }

    printf("\n--- break Statement ---\n");
    for (i = 0; i < 5; i++) {
        // 'break' is used to *immediately exit* the innermost loop.
        // Once 'break' is encountered, the loop's execution stops entirely,
        // and the program continues with the code *after* the loop.
        // Example: When i is 3, the loop terminates, and "Break loop iteration: 3" will not print.
        if (i == 3) {
            printf("Breaking loop at i = %d. Loop will now end completely.\n", i);
            break; // Exits the loop entirely
        }
        printf("Break loop iteration: %d\n", i);
    }

    printf("\n--- continue Statement ---\n");
    for (i = 0; i < 5; i++) {
        // 'continue' is used to *skip the rest of the current iteration*
        // and move directly to the next iteration of the loop.
        // The loop itself does *not* terminate; it just skips certain code
        // for a specific iteration.
        // Example: When i is 2, "Continue loop iteration: 2" will not print,
        // but the loop will continue for i = 3 and i = 4.
        if (i == 2) {
            printf("Skipping remaining code for i = %d. Moving to next iteration.\n", i);
            continue; // Skips current iteration, goes to next
        }
        printf("Continue loop iteration: %d\n", i);
    }

    printf("\n--- Nested Loops ---\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Outer i: %d, Inner j: %d\n", i, j);
        }
    }

    printf("\n--- Loop Labels (goto Statement) ---\n");
    // Generally avoid 'goto' for cleaner code.
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                printf("Jumping out of nested loops using goto.\n");
                goto exit_loops; // Jumps to the 'exit_loops' label
            }
            printf("Goto loop: i=%d, j=%d\n", i, j);
        }
    }
exit_loops:
    printf("Exited loops via goto.\n");

    printf("\n--- Switch Fallthrough ---\n");
    // Lack of 'break' causes execution to "fall through" to next case.
    switch (value) { // 'value' is still 2 from earlier
        case 1:
            printf("One ");
        case 2:
            printf("Two "); // This case is matched, and then it falls through
        case 3:
            printf("Three "); // This will also execute because of fallthrough
            break; // Exits the switch here
        default:
            printf("Default ");
    }
    printf("\n");

    printf("\n--- Ternary Operator ---\n");
    // Concise conditional assignment.
    result = (a > b) ? a : b;
    printf("Max of a and b is: %d\n", result);

    printf("\n--- Short-Circuit Evaluation (&&) ---\n");
    // 'ptr->data' is not evaluated if 'ptr' is NULL, preventing crash.
    if (ptr != NULL && ptr[0] > 0) { // Using ptr[0] instead of ptr->data for simplicity
        printf("This won't print if ptr is NULL.\n");
    } else {
        printf("Short-circuit prevented access to NULL ptr.\n");
    }

    printf("\n--- Short-Circuit Evaluation (||) ---\n");
    // 'c > d' is not evaluated if 'a < b' is true.
    if (a < b || c > d) {
        printf("One of the conditions is true.\n");
    }

    return 0;
}
