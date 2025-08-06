// --------- FILE002 ---------
#include <stdio.h>
#include <stdlib.h> // Included for general utilities, though not strictly used in this specific printf example.


/**
 * Subtopic 1: C Escape Sequences & Format Specifiers – aka The Hidden Language of printf 🧙‍♂️ What the hell are those??
 *
 * Your computer is a powerful printer, right? And we said printf is how you tell that printer what words to put on that page.
 *
 * Escape sequences are special instructions on how the words on that page are organized and where extra info should go eg send that to the newline(\n in C), tabs(\t), sounds(\a) etc.
 *
 * Format specifiers(placeholders), are special instructions, but are used to inject dynamic data into your output.
 *
 * These two are usually used separately or combined, doesn't matter, but they both link back to one thing:
 *
 * => They make the `printf` statement super versatile (adapts to different kinds of output).
 *
 * For example:
 * - When you see `\a` (escape sequence), you're telling the computer: “Yo, play a beep sound.”
 * - When you see `%s` (format specifier), you're telling the compiler: “Replace this with a string, like ‘Nick’.”
 *
 */

int main()
{
    // Printer, write these exact words on the screen for me and move to the next line! \n is an escape character for newline as we said.
    printf("--- Demonstrating Escape Sequences and Format Specifiers ---\n\n");

    // Declare some variables(boxes holding data in memory - see image) to demonstrate format specifiers
    int item_quantity = 5;
    float unit_price = 12.75;
    char product_name[] = "Widgets";
    char initial = 'G';

    // Using a newline escape sequence and a string format specifier
    printf("Product: %s\n", product_name);

    // Using a tab escape sequence, an integer format specifier, and a newline escape sequence
    printf("Quantity:\t%d\n", item_quantity);

    // Using a float format specifier with precision
    printf("Unit Price:\t$%.2f\n", unit_price); // .2f ensures 2 decimal places

    // Calculate total and print using multiple format specifiers - placeholders
    float total_cost = item_quantity * unit_price;
    printf("Total Cost:\t$%.2f (calculated from %d units at $%.2f each)\n\n", total_cost, item_quantity, unit_price);


    /*
     * Look at your screen. It's a giant whiteboard. The cursor is the marker. You see it? Yes.
     *
     * Normally, after you write something, the marker just moves to the next spot and waits for a new letter or event like tab keypress.
     *
     * Sometimes, we want to control the marker's movement. C allows that using the escape sequences to make the cursor do unusual things.
     *
     * `\t` tells the marker, "Jump forward to the next predefined tab stop," just like pressing the Tab key on a keyboard, it
     * usually moves 4 or 8 or any number of spaces, according to your settings.
     *
     * `\b` is telling the marker, "Oops, go back one step!" which is essentially the backspace.
     *
     * `\r (carriage return)` is telling the marker, "Go all the way back to the very beginning of the current line, ready to write over anything that's already there."
     *
     * `\a` is telling the marker, "Make a little 'ding!' sound to get someone's attention."
     *
     * `\v` (vertical tab) and `\f` (form feed/new page) are advanced commands for a PHYSICAL printer.
     *
     */
    
    printf("Demonstrating specific escape sequences:\n");
    printf("1. Tab: Hello\tWorld!\n"); // \t example
    printf("2. Backspace: ABCDEF\b\bGH\n"); // \b example (removes EF, then prints GH)
    printf("3. Carriage Return: First part\rSecond part\n"); // \r example (Second part overwrites First part)
    printf("4. Alert: Beep! \a(You might hear a sound)\n"); // \a example
    printf("5. Vertical Tab & Form Feed (primarily for physical printers):\n");
    printf("   Line 1\vLine 2\n"); // \v example
    printf("   Page 1\fPage 2\n"); // \f example


    // Demonstrating printing a backslash and double quote
    printf("To print a backslash, use \\\\ e.g., C:\\Program Files\\WoMic\n");
    printf("To print a single or double quote, use a backslash infront of it \\\" (e.g., \"Hello, World!\")\n");


    // Demonstrating character format specifier
    printf("Your initial is: %c\n", initial);

    printf("\n--- End of Demonstration ---\n");

    return 0; // Indicate successful execution of the program
}
