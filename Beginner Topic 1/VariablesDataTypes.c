#include <stdio.h>   // Standard input/output functions (printf, fgets)
#include <stdlib.h>  // Standard library (not strictly needed here)
#include <string.h>  // For string manipulation (strcspn)

/**
 * @brief Clears the standard input buffer.
 *
 * Reads and discards characters from stdin until a newline or EOF.
 * Prevents leftover characters from affecting subsequent input calls.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Main function explaining C keywords and identifiers.
 *
 * This program defines what keywords and identifiers are in C,
 * and lists the rules for creating valid identifiers.
 */
int main()
{
    char user_answer[500]; // Buffer to store the user's answer

    printf("What is the difference between keyword and reserved words in C?\n");
    printf("(Type your answer and press Enter):\n");
    // Use fgets for safe input: reads up to sizeof(user_answer)-1 characters,
    // preventing buffer overflows.
    if (fgets(user_answer, sizeof(user_answer), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Indicate error
    }
    // Remove the trailing newline character that fgets might include.
    //This is safe preventing buffer overflows.
    user_answer[strcspn(user_answer, "\n")] = '\0';

    printf("\nYour answer: %s\n", user_answer);

    printf("\n------------------------------------------------\n");
    printf("Understanding C Keywords and Identifiers\n");
    printf("------------------------------------------------\n");

    // --- Keywords (often called Reserved Words) ---
    printf("\n--- Keywords (Reserved Words) ---\n");
    printf("Keywords are special words in C with predefined meanings.\n");
    printf("They are used by the compiler for specific purposes and cannot be used\n");
    printf("as names for variables, functions, or any other program elements.\n");
    printf("Examples: int, float, if, while, return.\n");

    // --- Identifiers ---
    printf("\n--- Identifiers ---\n");
    printf("Identifiers are names given to program elements like variables, functions,\n");
    printf("arrays, etc. You choose these names.\n");

    printf("\n--- Rules for C Identifiers ---\n");
    printf("1.  Must start with a letter (A-Z, a-z) or an underscore (_).\n");
    printf("2.  After the first character, can contain letters, digits (0-9), and underscores.\n");
    printf("3.  Cannot be a C keyword.\n");
    printf("4.  Are case-sensitive (e.g., 'myVar' and 'myvar' are different).\n");
    printf("5.  Cannot contain spaces or other special characters (like !, @, #, $).\n");
    printf("6.  While length can be arbitrary, only the first few characters (e.g., 31) might be significant to some compilers.\n");
    printf("7.  Choose meaningful names for readability and maintainability.\n");

    printf("\n------------------------------------------------\n");
    printf("Remember these rules for clear and correct C code!\n");
    printf("------------------------------------------------\n");

    return 0; // Indicates successful program execution
}
