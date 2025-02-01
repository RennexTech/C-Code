#include <stdio.h>
#include <stdlib.h>

/*
Explanation of Modifications with Escape Sequences:

printf("Basic = 1500\n");: This line remains unchanged. It prints "Basic = 1500" and ends with a newline character \n to move to the next line.

printf("\\t moves the cursor to the next tab stop. Similarly, we can use other escape sequences also. For example,");: In this line, we've used \\t to represent a backslash followed by the character t, which is the escape sequence for a horizontal tab. This allows us to display the text "'\t' moves the cursor to the next tab stop."

printf("\\b moves the cursor one position back, '\\r' moves the cursor to the beginning of the current line,");: Similar to the previous line, we've used \\b to represent a backslash followed by the character b, which is the escape sequence for a backspace. We've also used \\r to represent a carriage return, which moves the cursor to the beginning of the current line.

printf("and '\\a' alerts the user by a beep sound. '\\v' moves the cursor to the next vertical tab position (first\ncolumn of the next line), and '\\f' moves the cursor to the 'next page. '\\v' and '\\f' are effective only\nwhen the output is printed through a printer.");: This part of the text contains multiple escape sequences:

\\a represents the alert (beep) escape sequence.
\\v represents the vertical tab escape sequence.
\\f represents the form feed escape sequence.
The newline \n characters are retained to format the text into separate lines.
printf("If we want to print characters like single quotes ( ' ), double quotes ( \" ), or the backslash character\n( \\ ), then we have to precede them by a backslash character in the format string.");: In this line, we've used \' to represent a single quote, \" to represent a double quote, and \\ to represent a backslash.

printf("For example- printf(\"9 \\\\ I I \\\\ 1978\");\n");: Here, we've used \\\\ to represent two backslashes, and the entire example printf statement is enclosed in double quotes for clarity. The line ends with a newline character \n.

By using these escape sequences, we can print special characters and control characters accurately in C strings, ensuring that they are displayed correctly in the output.

*/



int main()
{
    printf("Basic = 1500\n");

    //tab is just like tab key on your keyboard
    printf("\\t moves the cursor to the next tab stop. Similarly we can use other escape sequences also. For example\n");
    printf("\\b moves the cursor one position back, '\\r' moves the cursor to the beginning of the current line\n");
    printf("and '\\a' alerts the user by a beep sound. '\\v' moves the cursor to the next vertical tab position (first\n");
    printf("column of the next line), and '\\f' moves the cursor to the 'next page. '\\v' and '\\f' are effective only\n");
    printf("when output is printed through a printer.\n");
    printf("If we want to print characters like single quotes ( ' ), double quotes ( \" ) or the backslash character\n");
    printf("( \\ ), then we have to precede them by a backslash character in the format string.\n");
    printf("For example- printf(\"9 \\\\ I I \\\\ 1978\");\n");
    printf("\n");
    printf("int b = 1500;\n");
    printf("float h = 200.50;\n");
    printf("char g = 'A';\n");
    printf("printf(\"Basic = %%d\\tHRA = %%f\\tGrade = %%c\\n\", b, h, g);\n");


    //Newline Character (\n): Inserts a newline character, moving the cursor to the beginning of the next line.
    printf("Line 1\nLine 2\n");
    //Tab Character (\t): Inserts a horizontal tab character, typically moving the cursor to the next tab stop.
    printf("Column 1\tColumn 2\n");
    //Backspace Character (\b): Moves the cursor one position back within the current line.
    printf("This is\b a backspace\n");
    //Carriage Return (\r): Moves the cursor to the beginning of the current line.
    printf("Overwrite this line.\r");
    //Alert or Beep (\a): Produces an audible alert (beep) on some systems.
    printf("Alert: \a\n");
    //Single Quote (\') and Double Quote (\"): To print single quotes or double quotes within a string, escape them with a backslash.
    printf("Single quote: \'\n");
    printf("Double quote: \"\n");
    //Backslash (\\): To print a literal backslash, escape it with another backslash.
    printf("This is a backslash: \\n");
    //Formatting Specifiers: When you want to include values within formatted strings (e.g., variables), you use format specifiers like %d, %f, %s, etc., which are replaced by the actual values when printing.
    int age = 30;
    printf("My age is %d years old.\n", age);


    /*

    These escape sequences and format specifiers allow you to control the appearance and content of text when you print it using functions like printf. They are essential for formatting output to make it more readable and meaningful to users.
    No, anything placed after a return statement, whether it's return 0, return 1, or any other value, will not be executed or printed to the screen.

    The return statement in C serves two primary purposes:

    It specifies the value that the function will return to its caller. For example, return 0 typically indicates that the program executed successfully, while return 1 or a non-zero value often indicates an error.

    It immediately exits the function, bypassing any code that appears after it in the same function. Once the return statement is encountered, the function terminates, and control is passed back to the caller.



    */

    printf("This will be printed.\n");
    return 0; // The program exits here
    printf("This will not be printed.\n"); // This line is not executed


}
