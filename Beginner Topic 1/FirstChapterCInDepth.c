#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library (not strictly needed here)

/**
 * @brief Main function demonstrating basic C escape sequences.
 *
 * This program showcases common escape sequences for formatting output.
 */
int main()
{
    // Prints "Hello world!" followed by a newline.
    printf("Hello world!\n");

    // Prints a string including double quotes.
    printf("She said \"hello!\"\n");

    // Prints a string with literal backslashes.
    printf("The file location is C:\\Users\\Program Files\n");

    // Simulates a countdown using backspace (\b).
    printf("5\b4\b3\b2\b1\b\n");

    // Demonstrates carriage return (\r) overwriting text.
    printf("Line 1\rLine 2\n"); // "Line 2" will overwrite "Line 1"

    return 0; // Indicates successful program execution
}
