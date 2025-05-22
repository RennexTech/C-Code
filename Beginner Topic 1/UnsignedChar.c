#include <stdio.h>   // Standard input/output functions (printf)
#include <stdlib.h>  // Standard library (not strictly needed here)
#include <string.h>  // For string manipulation functions (strcpy)

/**
 * @brief Main function demonstrating 'char' and 'unsigned char' data types.
 *
 * This program illustrates how 'char' can store single characters,
 * how 'unsigned char' can store numerical values (ASCII codes),
 * and how character arrays (strings) are handled in C, including
 * important considerations for memory and the null terminator.
 */
int main()
{
    // --- Storing a string in a character array ---
    // "Hello World!" has 12 characters + 1 null terminator ('\0') = 13 bytes.
    // Array must be large enough to hold all characters PLUS the null terminator.
    char str[20]; // Allocated 20 bytes to safely hold "Hello World!" and more.
    strcpy(str, "Hello World!"); // Copies the string into the array.

    printf("The string stored is: %s\n", str);
    // sizeof(str) returns the total allocated size of the array, not the string length.
    printf("The size of the 'str' array (allocated memory) is: %zu bytes\n", sizeof(str));
    // strlen(str) returns the length of the string EXCLUDING the null terminator.
    printf("The actual length of the string 'Hello World!' is: %zu characters\n", strlen(str));

    // --- Storing a single character ---
    char letter = 'A'; // 'char' stores a single character.
    printf("The letter is: %c\n", letter);
    // 'sizeof(char)' is always 1 byte by definition.
    printf("The size of 'letter' (char) is: %zu bytes\n", sizeof(letter));

    // --- Storing numbers using 'unsigned char' ---
    // 'char' can also store small integer values (ASCII codes).
    // 'unsigned char' guarantees a range from 0 to 255.
    unsigned char number_ascii = 65; // 65 is the ASCII value for 'A'
    printf("The ASCII value %d corresponds to character: %c\n", number_ascii, number_ascii);
    printf("The size of 'number_ascii' (unsigned char) is: %zu bytes\n", sizeof(number_ascii));

    unsigned char max_val = 255; // Maximum value for an unsigned char
    printf("Max value for unsigned char: %u\n", max_val);

    // --- Key Concept: String Termination ---
    // C strings are null-terminated. This means a special character '\0' (ASCII 0)
    // marks the end of the string. Functions like printf(%s) and strlen rely on this.
    char example_null_term[] = {'H', 'i', '\0', 'X'}; // 'X' will not be printed by %s
    printf("Example null termination: %s\n", example_null_term); // Prints "Hi"

    return 0; // Indicates successful program execution.
}
