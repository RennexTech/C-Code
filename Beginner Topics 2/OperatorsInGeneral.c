#include <stdio.h>  // Gotta have this for printf (to show our vibes) and scanf (if we needed input).
#include <stdbool.h> // For using 'true' and 'false' instead of 1 and 0, makes logical stuff clearer.

/*
 * 🚀 C Operators: The Vibe Check Edition 🚀
 *
 * Alright, let's talk about how C understands your commands.
 * Operators are like the action verbs in C – they tell the program what to do with your data.
 * But just like in life, there's an order to things!
 *
 * We're gonna dive into:
 * 1. Assignment Operators: Giving values a glow-up.
 * 2. Precedence: Who gets to go first in the calculation queue?
 * 3. Associativity: When there's a tie, who breaks it?
 *
 * No cap, understanding these makes your code hit different. Let's get it! ✨
 * 
 */

int main() {
    printf("🎮 Welcome to the C Operator Playground! Let's get these vibes right. 🤙\n\n");

    // --- Section 1: Assignment Operators - The OG Setup Crew ---
    printf("--- Section 1: Assignment Operators - Setting the Scene ---\n");
    printf("These are how you give values to your variables. Simple as that.\n\n");

    // Assignment Chaining: Setting everyone's starting score in a game.
    // It reads from right to left, so 'h' gets 200, then 'g' gets what 'h' got, and so on.
    // Everyone starts on the same page!
    int x, y, z, f, g, h;
    printf("Scenario: Everyone starts with 200 points in our game. 💯\n");
    x = y = z = f = g = h = 200; // This is the chaining magic!
    printf("x: %d, y: %d, z: %d, f: %d, g: %d, h: %d\n", x, y, z, f, g, h);
    printf("See? All set to 200. Smooth. 😎\n\n");

    // Compound Assignment: The Shortcut Flex 💪
    // Instead of 'x = x + 65;', you can just say 'x += 65;'. It's quicker and cleaner.
    printf("Scenario: Leveling up! Adding some points to x and y.\n");
    int old_x = x; // Storing old value to show the change
    int old_y = y;
    x += 65; // This is the same as x = x + 65;
    y += 64; // This is the same as y = y + 64;
    printf("Old x: %d, New x (x += 65): %d\n", old_x, x);
    printf("Old y: %d, New y (y += 64): %d\n", old_y, y);
    printf("Compound assignments are like your favorite keyboard shortcuts – efficient!\n\n");


    // --- Section 2: Operator Precedence - Who Gets to Go First? ---
    printf("--- Section 2: Operator Precedence - The Hierarchy of Vibes ---\n");
    printf("Just like in math class, some operations happen before others.\n");
    printf("Think of it as who has the mic first in a group convo. 🎤\n\n");

    int a = 10, b = 5, c = 12; // Our sample numbers.

    // Example 1: Arithmetic (+) vs. Relational (<)
    // The '+' (addition) operator has higher precedence than '<' (less than).
    // So, 'a + b' happens *before* the comparison with 'c'.
    printf("Expression: x = a + b < c; (where a=10, b=5, c=12)\n");
    printf("  Breakdown: \n");
    printf("    1. 'a + b' evaluates first: %d + %d = %d\n", a, b, a + b); // 15
    printf("    2. Then, '%d < %d' evaluates: %d < %d is ", a + b, c, a + b, c); // 15 < 12 is false
    bool result1 = (a + b < c); // Using bool for clarity
    printf("%s\n", result1 ? "TRUE (1)" : "FALSE (0)");
    printf("  So, x will be: %d\n", result1);
    printf("  TLDR: Addition before comparison. Math before logic. 🧠\n\n");

    // Example 2: Arithmetic (+) vs. Compound Assignment (*=)
    // The '+' (addition) operator has higher precedence than '*=' (multiply and assign).
    // So, 'a + b' happens *before* the multiplication with 'x'.
    x = 5; // Resetting x for this example
    printf("Expression: x *= a + b; (where x=5, a=10, b=5)\n");
    printf("  Breakdown: \n");
    printf("    1. 'a + b' evaluates first: %d + %d = %d\n", a, b, a + b); // 15
    printf("    2. Then, 'x *= %d' evaluates: %d *= %d (which is %d * %d)\n", a + b, x, a + b, x, a + b); // 5 *= 15 (5 * 15)
    x *= (a + b); // Using parentheses for clarity, though not strictly needed due to precedence
    printf("  So, the new x will be: %d\n", x);
    printf("  TLDR: Calculate the right side first, then assign. 📝\n\n");

    // Example 3: Relational (<=, ==) vs. Logical (&&)
    // Relational operators (`<=`, `==`) have higher precedence than logical AND (`&&`).
    // So, `a <= b` and `b == c` are evaluated *before* the `&&` combines their results.
    a = 10, b = 10, c = 10; // New values for clarity
    printf("Expression: result = a <= b && b == c; (a=10, b=10, c=10)\n");
    printf("  Breakdown: \n");
    printf("    1. 'a <= b' evaluates: %d <= %d is %s\n", a, b, (a <= b) ? "TRUE" : "FALSE"); // 10 <= 10 is TRUE
    printf("    2. 'b == c' evaluates: %d == %d is %s\n", b, c, (b == c) ? "TRUE" : "FALSE"); // 10 == 10 is TRUE
    printf("    3. Then, 'TRUE && TRUE' evaluates to: %s\n", ((a <= b) && (b == c)) ? "TRUE" : "FALSE");
    bool result2 = (a <= b && b == c);
    printf("  So, result will be: %d\n", result2);
    printf("  TLDR: Comparisons happen before combining logic. Get your facts straight first! 🧐\n\n");


    // --- Section 3: Operator Associativity - The Tie-Breaker ---
    printf("--- Section 3: Operator Associativity - When There's a Tie ---\n");
    printf("If operators have the SAME precedence (like + and -), associativity decides the order.\n");
    printf("It's like reading a sentence: left-to-right or right-to-left. 📖\n\n");

    // Left-to-Right Associativity (most common for arithmetic)
    // Example: 10 - 5 + 2
    // The '-' and '+' have the same precedence, but they are left-to-right associative.
    printf("Expression: result = 10 - 5 + 2;\n");
    int val_lr = 10 - 5 + 2;
    printf("  Breakdown: \n");
    printf("    1. '10 - 5' evaluates first (left-to-right): %d\n", 10 - 5); // 5
    printf("    2. Then, '5 + 2' evaluates: %d\n", (10 - 5) + 2); // 7
    printf("  So, result is: %d\n", val_lr);
    printf("  TLDR: Read it like a book, left to right. ➡️\n\n");

    // Right-to-Left Associativity (common for assignments, unary operators)
    // We already saw this with assignment chaining: x = y = z = 200;
    // It evaluates from right to left (z=200, then y=z, then x=y).
    printf("Expression: x = y = z = 300; (Assignment chaining)\n");
    int val_rtl_x, val_rtl_y, val_rtl_z;
    val_rtl_x = val_rtl_y = val_rtl_z = 300;
    printf("  Breakdown: \n");
    printf("    1. 'z = 300' happens first. z is %d\n", val_rtl_z);
    printf("    2. Then, 'y = (result of z=300)' happens. y is %d\n", val_rtl_y);
    printf("    3. Finally, 'x = (result of y=z)' happens. x is %d\n", val_rtl_x);
    printf("  TLDR: Assignments go from right to left. ⬅️\n\n");


    printf("🏁 Mission accomplished! You've officially aced C operators. Go forth and code with confidence! 💻\n");

    return 0; // Program ended successfully, no cap.
}
