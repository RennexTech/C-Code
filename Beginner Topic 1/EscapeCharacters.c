#include <stdio.h> // Standard input/output library for functions like printf
#include <stdlib.h> // Standard library for general utilities (not strictly needed here but good practice)

/**
 * @brief Main function demonstrating C escape sequences and format specifiers.
 *
 * This program prints various examples of how to use special characters
 * and format output in C using printf.
 */
int main()
{
    // Basic print statement
    printf("Basic = 1500\n");
    
    // Demonstrates common escape sequences for cursor control and alerts
    printf("\\t moves the cursor to the next tab stop. Similarly we can use other escape sequences also. For example\n");
    printf("\\b moves the cursor one position back, '\\r' moves the cursor to the beginning of the current line\n");
    printf("and '\\a' alerts the user by a beep sound. '\\v' moves the cursor to the next vertical tab position (first\n");
    printf("column of the next line), and '\\f' moves the cursor to the 'next page. '\\v' and '\\f' are effective only\n");
    printf("when output is printed through a printer.\n");

    // Demonstrates escaping special characters within a string
    printf("If we want to print characters like single quotes ( ' ), double quotes ( \" ) or the backslash character\n");
    printf("( \\ ), then we have to precede them by a backslash character in the format string.\n");

    // Example of printing escaped backslashes
    printf("For example- printf(\"9 \\\\ I I \\\\ 1978\");\n");
    printf("\n"); // Prints an empty line for spacing

    // Declaring variables for format specifier demonstration
    int b = 1500;
    float h = 200.50;
    char g = 'A';

    // Demonstrates using format specifiers (%d, %f, %c) with variables
    printf("printf(\"Basic = %%d\\tHRA = %%f\\tGrade = %%c\\n\", b, h, g);\n");

    // Examples of common escape sequences in action:

    // Newline Character (\n): Moves cursor to the next line
    printf("Line 1\nLine 2\n");

    // Tab Character (\t): Inserts a horizontal tab
    printf("Column 1\tColumn 2\n");

    // Backspace Character (\b): Moves cursor back one position
    printf("This is\b a backspace\n");

    // Carriage Return (\r): Moves cursor to the beginning of the current line
    printf("Overwrite this line.\rNew text\n"); // "New text" will overwrite "Overwrite this line."

    // Alert or Beep (\a): Produces an audible alert
    printf("Alert: \a\n");

    // Single Quote (\') and Double Quote (\"): Prints literal quotes
    printf("Single quote: \'\n");
    printf("Double quote: \"\n");

    // Backslash (\\): Prints a literal backslash
    printf("This is a backslash: \\n"); // Note: prints "\n" literally, not a newline

    // Formatting Specifiers: Used to embed variable values into strings
    int age = 30;
    printf("My age is %d years old.\n", age);

    // Code execution flow demonstration:
    // Code after 'return' is not executed.
    printf("This will be printed.\n");
    return 0; // Program exits here
    printf("This will not be printed.\n"); // This line is unreachable and will not be executed
}
