#include <stdio.h>   // Standard input/output library: This is your program's mic and speaker, duh!
#include <stdlib.h>  // Standard library: For general utilities (not strictly needed here, but good to have).
#include <limits.h>  // Constants for integer limits: Tells us the min/max numbers integers can hold.
#include <float.h>   // Constants for floating-point limits: Tells us the min/max decimals can hold.
#include <stdbool.h> // bool, true, false: Making C less grumpy and more readable for boolean logic.
#include <unistd.h>  // For sleep() to chill between outputs.

/**
 * @brief 💅 C Data Types & Output Formatting: Getting Your Data to Look Right
 *
 * @analog Imagine your computer's memory is like a bunch of different-sized
 * storage containers. When you code, you're picking the right container
 * (data type) for your stuff (data).
 *
 * This program is all about:
 * 1. **What kind of containers C has** (`char`, `int`, `float`, `double`).
 * 2. **How big those containers are** (`sizeof`).
 * 3. **What kind of stuff (numbers) fits inside them** (value ranges).
 * 4. **How to make your data look good when you print it out** (formatting with `printf`).
 *
 * We'll see how to make sure your numbers aren't getting cut off, how to
 * control decimal places, and even how to add some extra space for that clean aesthetic.
 * Let's get this glow-up for your data! ✨
 */

int main()
{
    printf("=============================================================\n");
    printf("  C Data Types & Output Formatting: Getting Your Data to Look Right 💅\n");
    printf("=============================================================\n");
    sleep(1);

    // --- First Data Type: Character (char) ---
    printf("\n--- Char: The Tiny Text Messenger 💬 ---\n");
    printf("    @analog: A single sticky note. Holds one letter or a very small number.\n");
    char letter = 'a'; // Single characters use single quotes.
    printf("    This character is: '%c'\n", letter);
    printf("    Size of 'letter' (char): %zu bytes (super tiny!)\n", sizeof(letter));
    sleep(1);

    // --- Second Data Type: Integers (int) ---
    printf("\n--- Int: The Whole Number Squad 🔢 ---\n");
    printf("    @analog: Your everyday shoebox. For whole numbers, no decimals allowed.\n");
    int number1 = 399;
    int number2 = 5003;
    int sum;
    sum = number1 + number2; // Simple addition
    printf("    The sum of %d and %d is: %d\n", number1, number2, sum);
    sleep(1);

    // --- Integer Division Fun (or not!) ---
    printf("\n--- Integer Division: The No-Decimal Zone 🚫 ---\n");
    printf("    @analog: When you divide 7 cookies among 3 friends, everyone gets 2, and 1 is left over.\n");
    printf("    C's integer division only gives you the whole number part, no decimals!\n");
    float division_result;
    // (number1 / 9) is (399 / 9) which is 44 (as integer division).
    // Then 44 is converted to float and assigned to division_result.
    division_result = number1 / 9;
    printf("    399 / 9 (integer division) gives: %f (Notice it's 44.000000, not 44.333...)\n", division_result);
    sleep(1);

    // --- Double: The High-Precision Decimal Vibe ---
    printf("\n--- Double: The High-Precision Decimal Vibe 📈 ---\n");
    printf("    @analog: A jeweler's scale. For super precise decimals, like scientific data or money.\n");
    // Here, number2 (int) / 593 (int) will first do integer division (5003 / 593 = 8).
    // Then, 8 will be converted to double and assigned. This is a common pitfall!
    double majorMarks_pitfall;
    majorMarks_pitfall = number2 / 593;
    printf("    Your major grade after 593 exams is: %lf (Looks like 8.000000, 'cause of integer division first!)\n", majorMarks_pitfall);
    sleep(1);

    // To fix the above, make at least one operand a double/float:
    double majorMarks_fixed;
    majorMarks_fixed = (double)number2 / 593; // Cast number2 to double FIRST!
    printf("    Fixed major grade (with decimal precision): %lf (Now it's accurate!)\n", majorMarks_fixed);
    sleep(1);

    // --- Precision Formatting: How Many Decimals? ---
    printf("\n--- Precision Formatting: How Many Decimals You Want? 🎯 ---\n");
    printf("    @analog: Like telling your Instagram filter: 'Only show me 2 decimal places!'\n");
    double precision1 = 3.52523532452345235245243525232423432;
    // %.10lf: Prints a double with exactly 10 digits after the decimal point.
    printf("    Original double: %.20lf\n", precision1); // Show original for comparison
    printf("    Reduced double precision (%.10lf): %.10lf\n", precision1);
    sleep(1);

    float precision2 = 235.2323423423423423423423423423423234f; // 'f' suffix for float literal
    // %.7f: Prints a float with exactly 7 digits after the decimal point.
    printf("    Original float: %.15f\n", precision2); // Show original for comparison
    printf("    Reduced float precision (%.7f): %.7f\n", precision2);
    sleep(1);

    // --- Width Formatting: Minimum Space Occupied ---
    printf("\n--- Width Formatting: Minimum Space Occupied (The Aesthetic!) 🖼️ ---\n");
    printf("    @analog: Like telling your photo editor: 'Make sure this image is at least 7 pixels wide!'\n");
    printf("    The number *before* the dot (e.g., %7f) sets the MINIMUM total width.\n");
    printf("    If your number is shorter, it adds spaces before it for padding.\n");
    float precision3 = 235.2323423423423423423423423423423234f;
    // %7f: Minimum total width of 7 characters.
    // Since 235.23234234... is longer than 7, it will just print the number.
    printf("    Float (%.7f): %7f (No extra spaces, 'cause it's already wide enough)\n", precision3, precision3);
    sleep(1);

    double pie_val = 3.1453;
    // %10lf: Minimum total width of 10 characters.
    // 3.1453 is 6 characters long. So, it adds 4 spaces before it.
    printf("    The spaced version of pie (%%10lf): '%10lf' (See the spaces before it?)\n", pie_val);
    printf("    Compare with unspaced: '%lf'\n", pie_val);
    sleep(1);

    printf("    The number in the width specifier includes digits, decimal points, signs, and any padding spaces.\n");
    printf("    If you want leading zeros instead of spaces, use '%010lf' (e.g., '00003.145300').\n");
    printf("    Example with leading zeros: '%010.4lf'\n", pie_val); // 0-pad, 10 total width, 4 decimal places
    sleep(1);

    // --- Boolean Type: True/False Logic ---
    printf("\n--- Boolean Type: True/False Logic (The Vibe Check! ✅❌) ---\n");
    printf("    @analog: A light switch. It's either ON (true) or OFF (false).\n");
    printf("    In C, booleans aren't internally supported by default (like in Python).\n");
    printf("    You gotta import the header file `<stdbool.h>` to get `bool`, `true`, and `false`.\n");
    printf("    Under the hood, C still uses integers: `0` is `false`, and ANY non-zero number (even negative ones!) is `true`.\n");
    sleep(2);

    bool is_awake = true;  // Using 'true' from <stdbool.h>
    bool is_tired = false; // Using 'false' from <stdbool.h>
    int energy_level = -5; // Non-zero, so it's considered true in C logic

    printf("    Are you awake? %d (True is 1)\n", is_awake);
    printf("    Are you tired? %d (False is 0)\n", is_tired);
    printf("    Energy level: %d (In C, any non-zero number is TRUE!)\n", energy_level);
    sleep(1);

    if (is_awake && !is_tired) { // Using boolean logic
        printf("    You're awake and not tired! Time to code! 💻\n");
    } else {
        printf("    Maybe grab a coffee first. ☕\n");
    }

    printf("=============================================================\n");
    printf("That's the lowdown on C data types and getting your output to look just right!\n");
    printf("Keep practicing, fam! You're leveling up! 🚀\n");
    printf("=============================================================\n");
    sleep(1);

    return 0; // Program finished successfully. Peace out! ✌️
}
