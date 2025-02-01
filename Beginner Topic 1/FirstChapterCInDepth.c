#include <stdio.h>
#include <stdlib.h>

int main()
{
    //newline
    printf("Hello world!\n");
    //including double quotes
    printf("She said \"hello!\"\n");
    //to include backslashes in a string
    printf("The file location is C:\\Users\\Program Files\n");
    //simulate the backspace using \b - erasing
    printf("5\b4\b3\b2\b1\b\n");
    //carriage return - move cursor to the beginning of the current line
    printf("Line 1\rLine 2");
    /* In this example, the first line "Line 1" is overwritten by "Line 2" because
    \r moves the cursor to the beginning of the line, and then "Line 2" is printed. */

    return 0;
}
