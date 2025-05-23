#include <stdio.h>  // Standard input/output library for printf, getchar, etc.
#include <stdlib.h> // Standard library (not strictly needed for this example)

/**
 * @brief Main function demonstrating basic C standard input/output functions.
 *
 * This program showcases how to use printf for output and getchar for single character input.
 */

int main()
{
    // Demonstrates printing a simple string to the console.
    printf("Hello world!\n");

    // --- getchar demonstration ---
    char ch_input_1; // Declare a character variable to store input
    printf("Enter the first character: "); // Prompt the user for input
    ch_input_1 = getchar(); // Reads a single character from the input stream
    printf("You entered: %c\n", ch_input_1); // Prints the character read

    // Consume the leftover newline character from the previous getchar input.
    // This is crucial when mixing getchar/scanf with subsequent getchar/fgets.
    // If not consumed, the next getchar might immediately read this newline.
    getchar(); // Reads and discards the newline character

    char ch_input_2; // Declare another character variable for a second input
    printf("Enter the second character: "); // Prompt for another character
    
    ch_input_2 = getchar(); // Reads the second character
    printf("You entered: %c\n", ch_input_2); // Prints the second character

    // --- printf demonstration ---
    int num = 42; // Declare and initialize an integer variable

    // Prints a formatted string, embedding the integer value using %d.
    printf("The answer is: %d\n", num);

    return 0; // Indicates successful program execution.
}
