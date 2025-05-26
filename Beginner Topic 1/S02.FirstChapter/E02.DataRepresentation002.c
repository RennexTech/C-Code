//--------- FILE 005 ---------
 #include <stdio.h> // This is like importing your favorite video editor app; it gives you all the cool functions to script and edit videos, you don't need to know its architecture, just use it.
                    // printf, scanf, etc. — your console's love language
#include <stdlib.h>  // life support for general tasks (like memory management)
#include <limits.h>  // integer max/min values — helps you avoid overflows like a boss(e.g., INT_MAX, SHRT_MIN)
#include <float.h>   // float/double range — so you don't crash when dividing by 0.00000001(e.g., FLT_MAX, DBL_MIN)



/**
 * Let's flex some hardcore C format specifiers - C's resume on full display.
 *
 * Datatype is just a classification of data - integers, strings, floats, booleans, doubles, arrays etc. 
 *
 * They differ according to the programming langauge.
 * 
 * Computers reflect real life in that - Your wardrobe probably has some sneakers, hoodies, shirts, trousers.
 * 
 * All these serve a different purpose and you combine them to get your outfit of the day.
 * 
 * Similarly, you combine datatypes in your code to handle different forms of data and build up the program of the day that will trend on github. 
 *  
 * The function below prints the size and range for various integer and floating-point types
 * using their respective format specifiers and limits defined in <limits.h> and <float.h>.
 * 
 * That's too technical, we're basically breaking down how C handles different types of data(numbers, texts),
 * and how you as the programmer should tell the printf() function to display them correctly. 
 * 
 * Ever wondered how your phone knows your birthday and age is 18 or 18.5 or when you turn 19? 
 * 
 * That's basically google's computer checking the date your signed up with(datatype - int date, int month, int year),
 *  and sending a "happy birthday" to your phone - the exact day it arrives. 
 */

void format_specifiers() {
    // Table of common format specifiers
    printf("+--------+----------------------------------------+\n");
    printf("| Format | Description                            |\n");
    printf("+--------+-----------------------------------------+\n");
    printf("|   %%d  | A decimal integer                      |\n");
    printf("|   %%f  | A floating-point number                |\n");
    printf("|   %%e  | A floating-point number (scientific)   |\n");
    printf("|   %%g  | A floating-point number (shortest)     |\n");
    printf("|   %%lf | A double (long range floating point)   |\n");
    printf("|   %%h  | A short integer                        |\n");
    printf("|   %%o  | An octal integer                       |\n");
    printf("|   %%x  | A hexadecimal integer                  |\n");
    printf("|   %%i  | A decimal, octal, or hexadecimal int   |\n");
    printf("|   %%s  | A string                               |\n");
    printf("|   %%u  | An unsigned decimal integer            |\n");
    printf("+-------+----------------------------------------+\n");

    printf("\n");

    // Table of format specifiers with length modifiers
    printf("+---------+-------------------------------------------------------------+\n");
    printf("| Format  | Description                                                 |\n");
    printf("+---------+-------------------------------------------------------------+\n");
    printf("|   %%hd   | Short integer (signed)                                      |\n");
    printf("|   %%hu   | Short integer (unsigned)                                    |\n");
    printf("|   %%ld   | Long integer (signed)                                       |\n");
    printf("|   %%lu   | Long integer (unsigned)                                     |\n");
    printf("|   %%lld  | Long long integer (signed)                                  |\n");
    printf("|   %%llu  | Long long integer (unsigned)                                |\n");
    printf("|   %%Lf   | Long double                                                 |\n");
    printf("|   %%Le   | Long double (scientific notation)                           |\n");
    printf("|   %%Lg   | Long double (shortest representation)                       |\n");
    printf("+---------+-------------------------------------------------------------+\n");

    printf("\n");
    printf("Format Specifiers with Modifiers: Sizes and Ranges\n\n");

    // Demonstrates size and range for short int
    printf("%%hd: Short integer (signed)\n");
    printf("Size: %zu bytes\n", sizeof(short)); // %zu for size_t
    printf("Range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("\n");

    // Demonstrates size and range for unsigned short int
    printf("%%hu: Short integer (unsigned)\n");
    printf("Size: %zu bytes\n", sizeof(unsigned short));
    printf("Range: 0 to %u\n", USHRT_MAX);
    printf("\n");

    // Demonstrates size and range for long int
    printf("%%ld: Long integer (signed)\n");
    printf("Size: %zu bytes\n", sizeof(long));
    printf("Range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("\n");

    // Demonstrates size and range for unsigned long int
    printf("%%lu: Long integer (unsigned)\n");
    printf("Size: %zu bytes\n", sizeof(unsigned long));
    printf("Range: 0 to %lu\n", ULONG_MAX);
    printf("\n");

    // Demonstrates size and range for long long int
    printf("%%lld: Long long integer (signed)\n");
    printf("Size: %zu bytes\n", sizeof(long long));
    printf("Range: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("\n");

    // Demonstrates size and range for unsigned long long int
    printf("%%llu: Long long integer (unsigned)\n");
    printf("Size: %zu bytes\n", sizeof(unsigned long long));
    printf("Range: 0 to %llu\n", ULLONG_MAX);
    printf("\n");

    // Demonstrates size and range for float (printed as double by printf)
    printf("%%f, %%e, %%g: Floating-point number (float type, promoted to double for printf)\n");
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Range of float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("\n");

    // Demonstrates size and range for double
    printf("%%lf, %%e, %%g: Floating-point number (double type)\n");
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Range of double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("\n");

    // Demonstrates size and range for long double
    printf("%%Lf, %%Le, %%Lg: Long double\n");
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Range of long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    printf("\n");
}

/**
 * @brief Main function demonstrating basic C I/O functions and function calls.
 *
 * This program shows how to use printf, scanf, getchar, putchar, and puts.
 * It also illustrates the importance of declaring functions before they are called.
 */

int main() {
    // Table summarizing common I/O functions
    printf("+------------------+----------------------------------------------------+\n");
    printf("| Function         | Usage                                              |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| scanf            | Reads formatted input from user/file.              |\n");
    printf("|                  | Example: scanf(\"%%d\", &num);                      |\n");
    printf("|                  | Reads an integer into 'num'.                       |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| printf           | Formats and prints output to console.              |\n");
    printf("|                  | Example: printf(\"The answer is: %%d\\n\", num);     |\n");
    printf("|                  | Displays 'num' with a message.                     |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| getchar          | Reads a single character from input stream.        |\n");
    printf("|                  | Example: ch = getchar();                           |\n");
    printf("|                  | Reads a character into 'ch'.                       |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| putchar          | Writes a single character to output stream.        |\n");
    printf("|                  | Example: putchar('H');                             |\n");
    printf("|                  | Displays the character 'H'.                        |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| puts             | Writes a string to output, adds newline.           |\n");
    printf("|                  | Example: puts(\"Hello\");                            |\n");
    printf("|                  | Displays \"Hello\" then a newline.                   |\n");
    printf("+------------------+----------------------------------------------------+\n");

    printf("\n");

}

  
// No more 'date()' function hanging around like a ghosted text.
// We're defining 'format_specifiers' right here so 'main' knows what's up,
// kinda like tagging your friend in a story before they see it themselves.
void format_specifiers() {
    // This function is like a TikTok tutorial for data types.
    // It shows you how different kinds of info (numbers, letters, decimals)
    // need their own specific filters or hashtags to look right when you post 'em.
    // Think of it as making sure your pic isn't pixelated because you used the wrong export setting.

    printf("--- Data Type Display Settings (Format Specifiers) ---\n");

    int age = 21; // Like a number of followers, whole and counting.
    printf("My age is: %d\n", age); // %d is like saying, "Hey, this is a whole number, display it as such!"

    float price = 19.99f; // Like a price tag, it's got decimals.
    printf("The price is: %.2f\n", price); // %.2f is like saying, "Keep it two decimal places, no extra fluff!"

    char initial = 'J'; // Like a single emoji or initial.
    printf("My initial is: %c\n", initial); // %c is for single characters, like a quick reaction.

    double bigNumber = 123456789.123456; // Like a really, really long trending hashtag.
    printf("A big number: %lf\n", bigNumber); // %lf handles the really long decimal numbers.

    char name[] = "ByteBuddy"; // Like your username, a string of characters.
    printf("My username is: %s\n", name); // %s is for strings, displaying a whole word or phrase.

    printf("--------------------------------------------------\n");
}

int main() {
    // Think of 'main()' as the central feed on your social media,
    // where everything you post, share, or interact with gets orchestrated.
    // It's the starting point for your entire program.



    // --- Sending Out Short, Punchy Messages (Output Functions) ---

    // putchar: Like sending a single emoji or a quick 'seen' message.
    // It's super fast because it's just one character, no frills.
    putchar('a'); // Drops a single 'a' like it's hot.

    // puts: Imagine posting a quick status update. It's a whole line of text,
    // and it automatically hits 'Enter' for you, creating a new line.
    // So you don't have to manually press 'newline' like you would with some other functions.
    puts("This is a random statement. I'm using puts() to drop this message.");

    // printf: This is your ultimate content creation tool, like a fully featured tool.
    // You can combine text with dynamic data and do advanced formatting.
    // You get to decide when to hit 'Enter' or \n...
    // Super customizable, super powerful.
    printf("This is a random statement. I'm using printf() to display it, with full control.\n");

    printf("\n"); // Just a line break, like hitting 'Enter' twice for spacing in a caption.



    // --- Getting Input from the Squad (Input Functions) ---

    // getchar: This is like waiting for a direct message (DM) with just one character.
    // Maybe someone sends you a '👍' or '😂'. 'getchar()' is patiently waiting for that
    // single character input before it moves on. It's focused on getting just that one piece of info.
    char ch; // A variable to hold that incoming single character.
    
    printf("Enter a single character, fam: "); // Prompting for user input, like asking a question in your story.
    
    ch = getchar(); // Grabs that single character from the keyboard.
    
    printf("The character you entered is: %c\n", ch); // Shows off what you just got, like sharing the DM in a screenshot.

    printf("\n"); // Another aesthetic line break.

    // Calling the 'format_specifiers' function:
    // You wrote a void function above, it can't work on its own, so main calls him up.
    // main() tells him: Yoo, bro, do your part and when you finish I'll tell the OS to end the program.
    format_specifiers();

    return 0; // Program peace out! Like saying "Mission Accomplished" after a successful stream.
}

