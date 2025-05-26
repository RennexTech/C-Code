#include <stdio.h>  // Standard input/output library
#include <stdlib.h> // Standard library (not strictly needed for this example)

/**
 * @brief Structure to hold a C keyword and its concise description.
 */
typedef struct {
    const char* keyword;
    const char* description;
} CKeyword;

/**
 * @brief Main function to print the 32 C keywords and their descriptions.
 *
 * This program iterates through a predefined list of C keywords and displays
 * each keyword along with a brief explanation of its purpose.
 */

int main()
{
    // Array of CKeyword structs containing all 32 standard C keywords and their descriptions.
    CKeyword keywords[] = {
        {"auto", "Default storage for local variables; created on entry, destroyed on exit."},
        {"break", "Exits the current loop or 'switch' statement immediately."},
        {"case", "Defines a specific branch within a 'switch' statement."},
        {"char", "Declares a variable to hold a single character or small integer."},
        {"const", "Declares a variable whose value cannot be changed after initialization."},
        {"continue", "Skips the rest of the current loop iteration and moves to the next."},
        {"default", "Fallback case in a 'switch' statement if no other 'case' matches."},
        {"do", "Starts a 'do-while' loop; executes block at least once, then checks condition."},
        {"double", "Declares a double-precision floating-point number."},
        {"else", "Executes a block of code if the 'if' condition is false."},
        {"enum", "Defines a set of named integer constants (enumeration)."},
        {"extern", "Declares a variable or function defined in another file (external linkage)."},
        {"float", "Declares a single-precision floating-point number."},
        {"for", "Initiates a loop that executes a block of code a specific number of times."},
        {"goto", "Transfers control to a labeled statement (generally discouraged)."},
        {"if", "Executes a block of code if a given condition is true."},
        {"int", "Declares a variable to hold an integer value."},
        {"long", "Modifies 'int' to hold a larger range of integer values."},
        {"register", "Suggests storing a variable in a CPU register for faster access (compiler hint)."},
        {"return", "Specifies a function's return value and terminates its execution."},
        {"short", "Modifies 'int' to hold a smaller range of integer values."},
        {"signed", "Specifies an integer type can hold both positive and negative values."},
        {"sizeof", "Returns the size in bytes of a type or variable."},
        {"static", "For variables, retains value between function calls; for functions, limits scope to current file."},
        {"struct", "Defines a composite data type grouping variables of different types."},
        {"switch", "Allows branching to different code blocks based on a variable's value."},
        {"typedef", "Creates an alias (synonym) for a data type."},
        {"union", "Defines a data structure that stores different data types in the same memory location."},
        {"unsigned", "Specifies an integer type can hold only non-negative values."},
        {"void", "Indicates a function returns no value, or absence of a data type."},
        {"volatile", "Tells compiler a variable's value can change unexpectedly (e.g., by hardware)."},
        {"while", "Initiates a loop that executes a block of code as long as a condition is true."}
    };

    // Calculate the number of keywords in the array
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    printf("--------------------------------------------\n");
    printf("I will be printing the 32 C Keywords\n");
    printf("--------------------------------------------\n\n");

    // Loop through the array and print each keyword and its description
    for (int i = 0; i < num_keywords; i++) {
        printf("%2d. %s\n", i + 1, keywords[i].keyword); // Prints keyword number and name
        printf("    %s\n", keywords[i].description);     // Prints keyword description
        printf("--------------------------------------------\n\n"); // Separator for readability
    }

    printf("That's all you need to learn to use in C programming.\n");
    printf("--------------------------------------------\n");

    return 0; // Indicates successful program execution
}
