#include <stdio.h>    // For printf, fgets, getchar — our program's mic and ear.
#include <string.h>   // For strlen (to check string length) and strcspn (to clean up fgets input).
#include <limits.h>   // For integer limits (like SCHAR_MIN, SCHAR_MAX) — tells us the min/max numbers chars can hold.
#include <stdbool.h>  // For bool, true, false — making C less grumpy and more readable.
#include <unistd.h>   // For sleep() — to chill between outputs.

/**
 * @brief 🧠 C Fundamentals: Data, Text, and Naming Your Code
 *
 * @analog Imagine your computer's memory is a giant storage facility.
 * This program is your guide to understanding:
 * 
 * 1. What kind of "stuff" (data) you can put in those storage boxes.
 * (Single characters, whole words, numbers, etc.)
 * 
 * 2. How C handles those "boxes" of text. (Strings and their secrets)
 * 
 * 3. The rules for naming your "boxes" and "tools", so you don't
 * accidentally use C's secret, reserved words.
 *
 * We're gonna keep it real, with examples that make sense and comments
 * that hit different. Let's get this knowledge! 🚀
 */

/**
 * @brief Clears the standard input buffer.
 * @analog Flushes the toilet after use to keep things clean for the next input.
 * Essential after `scanf` or `fgets` to prevent leftover characters
 * (like the newline from pressing Enter) from messing up next inputs.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    printf("=============================================================\n");
    printf("  C Fundamentals: Data, Text, and Naming Your Code 🧠\n");
    printf("=============================================================\n");
    sleep(1);

    // --- Part 1: Characters & Strings (The Text Game) 📝 ---
    printf("\n--- Part 1: Characters & Strings (The Text Game) ---\n");
    printf("Let's talk about how C handles letters, emojis, and whole words.\n");
    sleep(1);

    // --- Single Character (`char`) ---
    printf("\n### Single Character (`char`): The Tiny Text Messenger\n");
    printf("    @analog: A sticky note. Holds one letter or a very small number.\n");
    char letter = 'A'; // A single character, enclosed in single quotes
    printf("    The letter is: '%c'\n", letter);
    printf("    Size of 'letter' (char): %zu bytes (super tiny!)\n", sizeof(letter));
    sleep(1);

    // --- Numbers using `unsigned char` (ASCII Values) ---
    printf("\n### Numbers as Characters (`unsigned char`): The Secret Code\n");
    printf("    @analog: A secret decoder ring. Each character has a hidden number (ASCII value).\n");
    printf("    'unsigned char' is like a 'char' but only for positive numbers (0-255).\n");
    unsigned char number_ascii = 65; // 65 is the ASCII value for 'A'
    printf("    The ASCII value %d corresponds to character: '%c'\n", number_ascii, number_ascii);
    printf("    Size of 'number_ascii' (unsigned char): %zu bytes\n", sizeof(number_ascii));
    printf("    Max value for unsigned char: %u (from %d to %d)\n", UCHAR_MAX, SCHAR_MIN, SCHAR_MAX); // Showing range
    sleep(1);

    // --- Strings (`char` arrays): Whole Words & Sentences ---
    printf("\n### Strings (`char` arrays): Whole Words & Sentences\n");
    printf("    @analog: A long scroll. A sequence of characters to make words or sentences.\n");
    char my_message[20]; // A char array big enough for 19 characters + the secret '\0'
    strcpy(my_message, "Hello World!"); // Copying text into our array. Need <string.h>!

    printf("    The string stored is: \"%s\"\n", my_message);
    // sizeof: Returns the total memory allocated for the array (20 bytes here).
    printf("    Size of the 'my_message' array (the box size): %zu bytes\n", sizeof(my_message));
    // strlen: Returns the actual number of characters in the string, *excluding* the '\0'.
    printf("    Actual length of the string \"Hello World!\" (characters): %zu\n", strlen(my_message));
    sleep(1);

    // --- Key Concept: Null Termination (`\0`) ---
    printf("\n### Key Concept: Null Termination (`\\0`): The String's Secret End Mark\n");
    printf("    @analog: A period at the end of a sentence. It tells C where the string *really* ends.\n");
    printf("    C strings are just arrays of characters that *must* end with a special character: '\\0' (the null terminator).\n");
    printf("    Functions like `printf(\"%%s\")` and `strlen()` rely on this '\\0' to know when to stop reading.\n");
    char example_null_term[] = {'H', 'i', '\0', 'X', 'Y', 'Z'}; // 'X', 'Y', 'Z' are ignored!
    printf("    Example null termination: \"%s\"\n", example_null_term); // Prints "Hi" because of '\0'
    sleep(2);

    // --- Part 2: C Keywords vs. Identifiers (Naming Your Code) 🏷️ ---
    printf("\n--- Part 2: C Keywords vs. Identifiers (Naming Your Code) ---\n");
    printf("Time to learn what names you can use and what names are off-limits.\n");
    sleep(1);

    // --- Keywords (Reserved Words) ---
    printf("\n### Keywords (Reserved Words): C's Secret Vocabulary\n");
    printf("    @analog: Special passwords or secret handshakes that only C understands.\n");
    printf("    These are words C has already claimed, like `int`, `if`, `while`, `return`.\n");
    printf("    You CANNOT use them as names for your variables, functions, or anything else.\n");
    printf("    Trying to use them is like trying to name your pet 'The' or 'And' — it just doesn't work.\n");
    sleep(2);

    // --- Identifiers (Your Custom Names) ---
    printf("\n### Identifiers: Your Custom Names for Code Stuff\n");
    printf("    @analog: The names you give to your pets, your friends, or your favorite gaming character.\n");
    printf("    These are the names YOU create for variables, functions, arrays, etc.\n");
    printf("    Choose meaningful names, fam! Like `playerScore` instead of `x`.\n");
    sleep(1);

    printf("\n### Rules for C Identifiers: The Naming Convention 📜\n");
    printf("    @analog: The rules for naming a baby. Gotta follow 'em!\n");
    printf("    1. Must start with a letter (A-Z, a-z) or an underscore (_). (No numbers first!)\n");
    printf("    2. After the first character, can contain letters, digits (0-9), and underscores.\n");
    printf("    3. Cannot be a C keyword. (No stealing C's secret words!)\n");
    printf("    4. Are case-sensitive (e.g., 'myVar' and 'myvar' are different. C is picky!)\n");
    printf("    5. Cannot contain spaces or other special characters (like !, @, #, $). (No weird symbols!)\n");
    printf("    6. While length can be arbitrary, only the first few characters might be significant to some compilers. (Keep it reasonably short, don't write a novel!)\n");
    printf("    7. Choose meaningful names for readability and maintainability. (Make it make sense, fam!)\n");
    sleep(2);

    // --- Interactive Part: Test Your Knowledge! ---
    printf("\n--- Test Your Knowledge: Keyword vs. Identifier! ---\n");
    printf("What's the difference between a keyword and a reserved word in C?\n");
    printf("(Type your answer and press Enter, no cap):\n");

    char user_answer[500]; // Buffer to store the user's answer

    // Use fgets for safe input: reads up to sizeof(user_answer)-1 characters,
    // preventing buffer overflows. It's the safe way to get a whole line, spaces included.
    if (fgets(user_answer, sizeof(user_answer), stdin) == NULL) {
        printf("Error reading input. My bad. 😬\n");
        return 1; // Indicate error, program out.
    }

    // Remove the trailing newline character that fgets always includes.
    // This is crucial for clean strings, especially if you're comparing them later.
    // `strcspn` finds the position of the first '\n', and we replace it with '\0'.
    user_answer[strcspn(user_answer, "\n")] = '\0';

    printf("\nYour answer: \"%s\"\n", user_answer);
    printf("------------------------------------------------\n");
    printf("You're on your way to mastering C! Keep learning and coding! 🚀\n");
    printf("------------------------------------------------\n");
    sleep(2);

    return 0; // Indicates successful program execution. Peace out! ✌️
}
