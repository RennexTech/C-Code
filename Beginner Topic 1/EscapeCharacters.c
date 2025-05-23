// 1 - This is the first file, the file number will tell you where you are in your studies.
// RULE 1: Go slowly, read slowly, you don't even need a text to speech app, code it yourself in codeblocks or vscode or vs community.


/*
*
* When you start building a house, you need hammers, saws, ironsheets from a hardware store, which has 
* almost all pre-made tools. So, we're telling the construction team(compiler), go fetch us some header files
* which we shall use to build our code. Fetch one stdio.h to help us in printing on the screen, like writing to a 
* whiteboard. Then fetch us stdlib.h for general utilities.
*
*/

#include <stdio.h> 
#include <stdlib.h> 


/**
 * Subtopic 1: C Escape Sequences & Format Specifiers – aka The Hidden Language of printf 🧙‍♂️ What the hell are those??
 * 
 * Your computer is a powerful printer, right? And we said printf is how you tell that printer what words to put on that page. 
 * 
 * Escape sequences are special instructions on how the words on that page are organized and where extra info should go eg send that to the newline(\n in C), tabs(\t), sounds(\a) etc. 
 * 
 * Format specifiers are also special instructions, but are used to inject dynamic data into your output. 
 * 
 * These two are usually used separately or combined, doesn't matter, but they both link back to one thing: 
 * 
 * => They make the `printf` statement super versatile (adapts to different kinds of output).
 * 
 * For example:
 *      - When you see `\a` (escape sequence), you're telling the computer: “Yo, play a beep sound.”
 *      - When you see `%s` (format specifier), you're telling the compiler: “Replace this with a string, like ‘Nick’.”
 * 
 */


int main()
{
    // Printer, write these exact words on the screen for me and move to the next line! \n is an escape character as we said.
    printf("Basic = 1500\n");



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
    printf("\\t moves the cursor to the next tab stop. Similarly we can use other escape sequences also. For example\n");
    printf("\\b moves the cursor one position back, '\\r' moves the cursor to the beginning of the current line\n");
    printf("and '\\a' alerts the user by a beep sound. '\\v' moves the cursor to the next vertical tab position (first\n");
    printf("column of the next line), and '\\f' moves the cursor to the 'next page. '\\v' and '\\f' are effective only\n");
    printf("when output is printed through a printer.\n");




    /*
     * To the next: 
     * 
     * JOHN: Okay, printf is a sentence the computer will write on the console, but since am writing double quotes or single quotes for strings,
     * how are we supposed to print a literal double quote on my screen?? Mr. C you have to explain this. 
     * 
     * MR.C - You add a backslash infront of it. [am out going to sleep, now go try that out for yourself...]
     *
     * JOHN: So, this only applies to backslashes, double quotes and single quotes. 
     * 
     * MR.C -
     */
    
    printf("If we want to print characters like single quotes ( ' ), double quotes ( \" ) or the backslash character\n");
    printf("( \\ ), then we have to precede them by a backslash character in the format string.\n");
    printf("This is an ordinary backslash that I want to see \\ I will see only one backslash.\n");
    printf("This double quote \" will be visible");
    
    
    /*
     * This is a specific example of the "double backslash" rule.
     * You're telling the robot to print "9 \\ I I \\ 1978".
     * For each `\` you see in the output, you had to type `\\` in the code,
     * so the robot knows you want a literal backslash and not a special command.
     */
    printf("For example- printf(\"9 \\\\ I I \\\\ 1978\");\n");
    printf("\n"); // This is just like pressing Enter on a typewriter to leave an empty line.

    /*
     * Think of these as different types of storage boxes.
     * An `int` variable like `b` is a box specifically designed
     * to hold whole numbers (like 1500).
     *
     * A `float` variable like `h` is a box for numbers that can have
     * decimal points (like 200.50).
     *
     * A `char` variable like `g` is a tiny box that can only hold a single
     * letter or symbol (like 'A').
     *
     * You declare these boxes to hold different kinds of information
     * that your program will work with.
     */
    int b = 1500;
    float h = 200.50;
    char g = 'A';

    /*
     * When you use `printf` and want to show the value from one of your
     * storage boxes (variables), you can't just put the box's name
     * directly into the sentence. You need a "placeholder" or a
     * "fill-in-the-blank" instruction.
     *
     * **Format specifiers** are those placeholders.
     * `%d` is like saying, "Put the whole number from an `int` box here."
     * `%f` is like saying, "Put the decimal number from a `float` box here."
     * `%c` is like saying, "Put the single character from a `char` box here."
     *
     * After the main message, you list the actual boxes you want to fill in,
     * and the robot knows to match them up with the placeholders.
     * So, `printf("...%d...%f...%c...", b, h, g);` is like saying,
     * "Say this sentence, but for the first blank, use the value from box `b`;
     * for the second, use the value from box `h`; and for the third, use the value from box `g`."
     */
    printf("printf(\"Basic = %%d\\tHRA = %%f\\tGrade = %%c\\n\", b, h, g);\n");

    /*
     * This is a practical demonstration of those "secret cursor commands"
     * (escape sequences) we talked about earlier.
     *
     * `printf("Line 1\nLine 2\n");`
     * This is like saying, "Write 'Line 1', then press the Enter key;
     * then write 'Line 2', and then press the Enter key again."
     * The `\n` acts like pressing Enter.
     *
     * `printf("Column 1\tColumn 2\n");`
     * This is like saying, "Write 'Column 1', then press the Tab key;
     * then write 'Column 2', and then press the Enter key."
     * The `\t` creates a neat, even space.
     *
     * `printf("This is\b a backspace\n");`
     * Imagine typing "This is " and then pressing the Backspace key once.
     * The `\b` makes the cursor go back one spot, effectively erasing the
     * last character typed (or moving the cursor over it).
     *
     * `printf("Overwrite this line.\rNew text\n");`
     * This is like typing "Overwrite this line." and then
     * suddenly taking your marker and moving it *all the way back*
     * to the beginning of that same line (`\r`). Then, when you
     * type "New text", it writes right over the start of the previous words.
     *
     * `printf("Alert: \a\n");`
     * This is like ringing a tiny bell. The `\a` (alert) typically makes
     * your computer emit a small beep sound.
     *
     * `printf("Single quote: \'\n");` and `printf("Double quote: \"\n");`
     * These show you how to tell the robot, "I literally want to print
     * the ' or the " character, even though they usually have special meanings."
     * You "escape" them with a backslash.
     *
     * `printf("This is a backslash: \\n");`
     * Here, you're explicitly telling the robot to print the characters `\` and `n`.
     * The `\\` makes sure the first `\` is treated as a regular character, not the start of a special command.
     */

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

    /*
     * Again, this demonstrates using a "fill-in-the-blank" (`%d`)
     * to put the value from your `age` storage box into your sentence.
     * `int age = 30;` is setting up a box named `age` and putting the number 30 inside.
     * Then, `printf("My age is %d years old.\n", age);` says,
     * "Say 'My age is', then put the number from the `age` box,
     * then say 'years old.', then move to the next line."
     */
    int age = 30;
    printf("My age is %d years old.\n", age);

    /*
     * Imagine your program is a recipe. The robot reads instructions
     * from top to bottom. The `return 0;` line is like the "END OF RECIPE"
     * instruction. As soon as the robot sees `return 0;`, it stops
     * whatever it's doing and says, "Okay, I'm done with this task!"
     * Any instructions written *after* `return 0;` are like lines
     * at the very bottom of a recipe *after* the "Enjoy your meal!"
     * instruction – the robot will never get to them because it's already
     * stopped working.
     */
    printf("This will be printed.\n");
    return 0; // Program exits here
    printf("This will not be printed.\n"); // This line is unreachable and will not be executed
}