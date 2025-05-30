#include <stdio.h>   // For printf, duh! Our program's mic.
#include <stdlib.h>  // For general utilities (like exit, if needed).
#include <math.h>    // For M_PI in the PI example (though we'll redefine it with #define).
#include <string.h>  // For string stuff, though not directly used in the examples.
#include <unistd.h>  // For sleep() to chill between outputs.

/**
 * 
 * @brief 🤫 C #define & Macros: The Code Shortcuts & Secret Switches
 *
 * @analog Imagine you're building a super cool app, and you keep typing the same
 * long phrase or calculation over and over. `#define` is like setting up a
 * **text shortcut** or a **secret code word** for that phrase or calculation.
 *
 * The **preprocessor** (the part of C that gets your code ready *before* it's actually
 * compiled) sees these shortcuts and literally swaps them out with the full text.
 * It's a simple find-and-replace, no brain cells involved!
 *
 * This guide will dive into:
 * - **Symbolic Constants:** Giving cool names to fixed values (like PI).
 * - **Function-like Macros:** Creating tiny code snippets that act like functions.
 * - **Conditional Compilation:** Building secret hideouts in your code that only show up when a certain "switch" is flipped.
 * - **Macro Tricks:** Some spicy moves like string concatenation.
 *
 * Macros can be powerful, but they're also a bit sus if not used carefully.
 * Let's vibe with them! 🚀
 * 
 */

// --- Macro Definitions: Our Shortcuts & Secret Codes ---





/**
 * @brief Macro: MAX(a,b) - Finds the larger of two values.
 *
 * @analog This is like asking your friends, "Who's got more followers, A or B?"
 * It instantly tells you the higher number.
 *
 * @note The extra parentheses `((a) > (b) ? (a) : (b))` are CRUCIAL!
 * They prevent unexpected behavior due to operator precedence.
 * Without them, `MAX(x + 1, y)` could become `x + 1 > y ? x + 1 : y`,
 * which might not be what you want if `x+1` is part of a larger expression.
 * Always wrap macro arguments in parentheses!
 */




#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief Macro: SQUARE(x) - Calculates the square of a number.
 *
 * @analog You're trying to figure out the area of a square room.
 * You just tell it the side length, and it instantly gives you the area.
 *
 * @note Again, the parentheses `((x) * (x))` are super important here!
 * If you just did `(x * x)`, and then called `SQUARE(5 + 2)`, it would become
 * `(5 + 2 * 5 + 2)` which is `5 + 10 + 2 = 17` (wrong!).
 * With `((x) * (x))`, it becomes `((5 + 2) * (5 + 2))` which is `(7 * 7) = 49` (correct!).
 */
#define SQUARE(x) ((x) * (x))





/**
 * @brief Macro: PI - Defines the mathematical constant Pi.
 *
 * @analog This is like having a sticky note with "Pi = 3.14159" on it.
 * Every time you write `PI`, the preprocessor just swaps it for `3.14159`.
 *
 * @note For actual constants, `const double PI_CONST = 3.14159;` is often preferred
 * in modern C because it gives you better type checking and debugging.
 * Macros are just text replacements.
 */
#define PI 3.14159





/**
 * @brief Macro: CONCAT(a,b) - Concatenates two tokens.
 *
 * @analog This is like smashing two words together without a space.
 * `CONCAT(hello, world)` literally becomes `helloworld`.
 * The `##` operator is the "smash together" button.
 */
#define CONCAT(a, b) a ## b





/**
 * @brief Macro: DEBUG_ENABLED - A switch to turn debugging prints on/off.
 *
 * @analog Imagine a secret "debug mode" button on your game controller.
 * If you press it (define `DEBUG_ENABLED`), all your cheat codes (debug messages)
 * show up. If you don't press it (comment out or don't define), they stay hidden.
 */
#define DEBUG_ENABLED // Uncomment this line to enable debugging messages!





/**
 * @brief Macro: DEBUG_PRINT(message) - Prints a debug message if DEBUG_ENABLED is on.
 *
 * @analog This is your "secret message" device. It only broadcasts the message
 * if the `DEBUG_ENABLED` switch is flipped ON. Otherwise, it's silent.
 */
#ifdef DEBUG_ENABLED // If DEBUG_ENABLED is defined...
    #define DEBUG_PRINT(message) printf("DEBUG: %s (from line %d in %s)\n", message, __LINE__, __FILE__)
#else // Otherwise (if DEBUG_ENABLED is NOT defined)...
    #define DEBUG_PRINT(message) // ...replace it with nothing! Poof!
#endif






/**
 * @brief Main function: Where all the macro magic happens! ✨
 *
 * @analog This is the main stage where we show off all our cool macro tricks.
 */
int main() {
    printf("=============================================================\n");
    printf("  C #define & Macros: The Code Shortcuts & Secret Switches 🤫\n");
    printf("=============================================================\n");
    sleep(1);

    // --- Demo 1: Function-like Macro (MAX) ---
    printf("\n--- Demo 1: MAX(a,b) - Who's got more followers? ---\n");
    int followers_a = 1000;
    int followers_b = 2500;
    int max_followers = MAX(followers_a, followers_b); // Preprocessor replaces this!
    printf("Follower count A: %d, Follower count B: %d\n", followers_a, followers_b);
    printf("The one with MAX followers is: %d (No cap!)\n", max_followers);
    sleep(2);

    // --- Demo 2: Function-like Macro (SQUARE) ---
    printf("\n--- Demo 2: SQUARE(x) - Area of a Square Room ---\n");
    int side_length = 7;
    int room_area = SQUARE(side_length); // Preprocessor replaces this!
    printf("Side length of room: %d\n", side_length);
    printf("Area of the room: %d (SQUARE macro doing its thing!)\n", room_area);
    sleep(2);

    // --- Demo 3: Symbolic Constant (PI) ---
    printf("\n--- Demo 3: PI - The Circle's Secret Number ---\n");
    double radius = 5.0;
    // The `PI` here gets replaced by `3.14159` before compilation.
    double circumference = 2 * PI * radius;
    printf("Radius of circle: %.2lf\n", radius);
    printf("Circumference (using PI macro): %.2lf\n", circumference);
    sleep(2);

    // --- Demo 4: Conditional Compilation (#ifdef DEBUG_ENABLED) ---
    printf("\n--- Demo 4: Conditional Compilation - Debug Mode Switch ---\n");
    // This code block only gets compiled if DEBUG_ENABLED is defined above!
    #ifdef DEBUG_ENABLED
        printf("DEBUG MODE IS ON! You're seeing secret messages. 🕵️‍♂️\n");
    #else
        printf("DEBUG MODE IS OFF. No secret messages here. 🤫\n");
    #endif // DEBUG_ENABLED
    sleep(2);

    // --- Demo 5: Using DEBUG_PRINT Macro ---
    printf("\n--- Demo 5: DEBUG_PRINT - Your Secret Message Device ---\n");
    int game_score = 150;
    DEBUG_PRINT("Game score is being updated."); // This will print only if DEBUG_ENABLED is on.
    game_score += 20;
    DEBUG_PRINT("Game score updated to 170.");
    printf("Current game score: %d\n", game_score);
    sleep(2);

    // --- Demo 6: String Concatenation (CONCAT) ---
    printf("\n--- Demo 6: String Concatenation (CONCAT) - Smashing Words! ---\n");
    // `CONCAT(my, Variable)` becomes `myVariable` during preprocessing.
    // This is useful for building variable names dynamically.
    int CONCAT(my, Variable) = 123; // This creates a variable named `myVariable`
    printf("Value of CONCAT(my, Variable) (which is 'myVariable'): %d\n", myVariable);
    sleep(2);

    // --- Demo 7: Disabling Code ---
    printf("\n--- Demo 7: Disabling Code - The Code Hideout ---\n");
    #define SECRET_FEATURE_ENABLED 0 // 0 means OFF, 1 means ON
    #if SECRET_FEATURE_ENABLED // If SECRET_FEATURE_ENABLED is 1 (true)...
        printf("Shhh! This is a super secret feature that got compiled! 🤫\n");
    #else
        printf("This secret feature is currently disabled and NOT compiled. No peeking! 👀\n");
    #endif // SECRET_FEATURE_ENABLED
    sleep(2);

    printf("\n=============================================================\n");
    printf("That's the lowdown on #define and Macros! Powerful, but use wisely.\n");
    printf("Keep coding, fam! You're leveling up! 🚀\n");
    printf("=============================================================\n");
    sleep(1);

    return 0; // Program finished successfully. Peace out! ✌️
}
