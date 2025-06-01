#include <stdio.h>   // For printf, duh! Our program's mic.
#include <unistd.h>  // For sleep() to chill between outputs, keep the flow smooth.

/**
 * @brief ✨ C Constants: The Unchanging Vibes of Your Code
 *
 * @analog Imagine you're building a super cool app, and some things just
 * never change. Like your birthdate, or the speed of light, or that one friend
 * who's always late. In C, these unchanging values are called **constants**.
 *
 * This program is your guide to:
 * - What constants are: Values that are fixed and can't be altered during runtime.
 * - Different types of constants: How C represents whole numbers, decimals, single characters, and entire phrases directly in your code.
 *
 * %-17d in printf as a formatting instruction for how your numbers should show up on the screen. It's like 
 * telling your social media post exactly how much space it needs and where it should sit. 
 * 
 * %: This is just the signal that says, "Hey, a formatting instruction is coming right after me!"
 * 
 * -: This little dash is the left-align button. Imagine you're putting text in a box. Without the -, your number would stick to the right side of the box (padded on the left). With the -, it sticks to the left side of the box (padded on the right). It's all about that clean alignment!
 * 
 * 17: This number sets the minimum width for your output. It's like saying, "Make sure this number takes up at least 17 character spaces, even if the number itself is shorter." If your number is shorter than 17 characters, printf will add spaces to fill up the remaining spots.
 * 
 * d: This is the type specifier. It tells printf that you're about to print a signed decimal integer (a whole number, positive or negative).
 * 
 * Print this integer, make sure it takes up at least 17 character spaces, and if it's shorter, add spaces to the right side to fill up the space.
 * 
 * Keeps everything lined up inside the table. 
 * 
 */

int main() {
    printf("=============================================================\n");
    printf("C Constants: The Unchanging Vibes of Your Code ✨\n");
    printf("=============================================================\n");
    sleep(1);

    printf("\n--- What are Constants? ---\n");
    printf("    @analog: Think of them as the 'facts' or 'fixed data' in your code.\n");
    printf("    Once you write them, they don't change. They're hardcoded values.\n");
    printf("    Like your favorite number, or a specific phrase you always use.\n");
    sleep(2);

    printf("\n--- Let's meet the squad of C Constants! ---\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("| Type                 | Example           | Vibe Check / Explanation                                |\n");
    printf("|----------------------|-------------------|-------------------------------------------------------|\n");
    sleep(1);

    // --- Integer Constant ---
    printf("| Integer Constant     | %-17d | A whole number, no decimals. Like your age, or how many followers you got.      |\n", 42);
    sleep(1);

    // --- Real Constant (Floating-Point) ---
    printf("| Real Constant        | %-17.5lf | A number with a decimal point. Think your GPA, or how much that limited-edition drop costs. |\n", 3.14159);
    sleep(1);

    // --- Octal Constant ---
    printf("| Octal Constant       | %-17o | An integer in base 8. Kinda old-school, starts with a '0'. Like a secret code from the 80s. |\n", 0754); // 0754 is 492 in decimal
    sleep(1);

    // --- Decimal Constant ---
    printf("| Decimal Constant     | %-17d | Just your regular numbers, how we count every day. The default vibe.            |\n", 123);
    sleep(1);

    // --- Hexadecimal Constant ---
    printf("| Hexadecimal Constant | %-17x | An integer in base 16. Super common for colors (like #FF00FF) or memory addresses. Starts with '0x'. |\n", 0x1A); // 0x1A is 26 in decimal
    sleep(1);

    // --- Character Constant ---
    printf("| Character Constant   | %-17c | A single letter, number, or symbol. Always in single quotes. Like one emoji.      |\n", 'A');
    sleep(1);

    // --- String Constant ---
    printf("| String Constant      | %-17s | A whole word or sentence. Always in double quotes. Like a full text message.     |\n", "Hello, World!");
    printf("---------------------------------------------------------------------------------------------------\n");
    sleep(2);

    printf("\n--- Quick Recap & Vibe Check ---\n");
    printf("    Constants are the unchanging truths in your code. They're literally written into the program!\n");
    printf("    Knowing them helps you understand how C handles different types of fixed data.\n");
    printf("    Keep those vibes consistent, and your code will be on point! 💯\n");
    sleep(2);

    printf("=============================================================\n");
    printf("That's the lowdown on C Constants! You're leveling up! 🚀\n");
    printf("=============================================================\n");

    return 0; // Program finished successfully. Peace out! ✌️
}
