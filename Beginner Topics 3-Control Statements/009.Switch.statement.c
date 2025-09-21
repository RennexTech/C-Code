#include <stdio.h>

int main() {
    int user_input = 0;

    // This is the core of the whole thing.
    // Analogy: Imagine you're at a train station with a bunch of platforms.
    // The `switch` statement is like the information booth. You give it
    // your ticket (`user_input`), and it looks at the number to tell you
    // exactly which platform (or `case`) you need to go to.
    switch (user_input) {

        // This is a specific path, or "platform 1."
        // The program checks: "Does the user's ticket number match '1'?"
        // If it does, the program jumps to this specific block of code.
        case 1:
            printf("You chose option 1. Executing Block A1.\n");
            // The code you want to run for this specific case would go here.
            break;
            // The `break` statement is crucial.
            // Analogy: After your train leaves the platform, you don't need
            // to check every other platform in the station. `break` is the
            // command to immediately exit the `switch` statement and move on
            // to the rest of the program, so you don't accidentally run
            // the code for the next case.

        // This is "platform 2." Same logic as before.
        case 2:
            printf("You chose option 2. Executing Block A2.\n");
            break;

        // You can have as many of these `case` statements as you need.
        // It's a clean way to handle multiple, distinct choices
        // without using a bunch of messy `if-else if` statements.
        case 3:
            printf("You chose option 3. Executing Block A3.\n");
            break;

        // This is the "default" platform.
        // Analogy: This is the customer service desk. If your ticket number
        // doesn't match any of the platforms, the information booth
        // automatically sends you here. It's the fallback for when no
        // other `case` matches the `switch` expression.
        default:
            printf("Invalid choice. Executing Block D.\n");
            break;
    }

    printf("Exiting the switch statement.\n");
    return 0;
}
