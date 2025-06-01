#include <stdio.h>   // For printf, our program's mic.
#include <stdlib.h>  // For general utilities (not strictly needed here, but good to have).
#include <unistd.h>  // For sleep() to chill between outputs, keep the flow smooth.

/**
 * 
 * @brief ⚡ C Assignment Operators: Quick Ways to Handle Your Data
 *
 * @analog Imagine you're organizing your digital life – assigning tasks,
 * giving nicknames to files, or updating your high score. In C, assignment
 * operators are how you give values to your variables.
 *
 * This program is your guide to:
 * 1. Assignment Chaining: Giving the same vibe (value) to multiple variable all at once, like sending a group text.
 * 
 * 2. Compound Assignment Operators: Shortcuts for doing math and updating a variable in one slick move, like `x += 5` instead of `x = x + 5`.
 *
 * 
 */

int main() {
    printf("=============================================================\n");
    printf("  C Assignment Operators: Quick Ways to Handle Your Data! ⚡ \n");
    printf("=============================================================\n");
    sleep(1);

    // --- Part 1: Assignment Chaining - The Group Text Vibe ---
    printf("\n--- Part 1: Assignment Chaining - The Group Text Vibe 💬 ---\n");
    printf("    @analog: Sending the same message to all your friends at once.\n");
    printf("    You're giving multiple variables the exact same value in one line.\n");
    sleep(1);

    int x, y, z, f, g, h; // Declaring a squad of integer variables

    // x = y = z = f = g = h = 200;
    // This assigns 200 to 'h', then 'g' gets 200, then 'f', and so on, all the way to 'x'.
    // It works from right to left!
    x = y = z = f = g = h = 200;
    printf("    After `x = y = z = f = g = h = 200;`:\n");
    printf("    x is: %d\n", x);
    printf("    y is: %d\n", y);
    printf("    z is: %d\n", z);
    printf("    f is: %d\n", f);
    printf("    g is: %d\n", g);
    printf("    h is: %d\n", h);
    printf("    Everyone got the same initial vibe: 200! ✨\n");
    sleep(2);

    // --- Part 2: Compound Assignment Operators - The Math Shortcut ---
    printf("\n--- Part 2: Compound Assignment Operators - The Math Shortcut ➕➖ ---\n");
    printf("    @analog: Instead of saying 'My score is my score PLUS 10,' you just say 'My score += 10!'\n");
    printf("    It's a faster way to do an operation and update the variable in one go.\n");
    sleep(1);

    int score = 100;
    printf("    Initial score: %d\n", score);

    // score = score + 65; // The long way
    score += 65; // The shortcut way! (score = score + 65)
    printf("    After `score += 65;` (adding 65 to score): %d\n", score); // score is now 165
    sleep(1);

    int lives = 5;
    printf("    Initial lives: %d\n", lives);

    // lives = lives - 2; // The long way
    lives -= 2; // The shortcut way! (lives = lives - 2)
    printf("    After `lives -= 2;` (losing 2 lives): %d\n", lives); // lives is now 3
    sleep(1);

    int multiplier = 10;
    printf("    Initial multiplier: %d\n", multiplier);

    // multiplier = multiplier * 3; // The long way
    multiplier *= 3; // The shortcut way! (multiplier = multiplier * 3)
    printf("    After `multiplier *= 3;` (tripling multiplier): %d\n", multiplier); // multiplier is now 30
    sleep(1);

    int total_items = 25;
    printf("    Initial total items: %d\n", total_items);

    // total_items = total_items / 5; // The long way
    total_items /= 5; // The shortcut way! (total_items = total_items / 5)
    printf("    After `total_items /= 5;` (dividing items by 5): %d\n", total_items); // total_items is now 5
    sleep(1);

    int remainder_check = 17;
    printf("    Initial remainder check: %d\n", remainder_check);

    // remainder_check = remainder_check % 3; // The long way
    remainder_check %= 3; // The shortcut way! (remainder_check = remainder_check % 3)
    printf("    After `remainder_check %%= 3;` (finding remainder by 3): %d\n", remainder_check); // remainder_check is now 2
    sleep(2);

    printf("\n--- The Takeaway: Code Smart, Not Hard! 🔥 ---\n");
    printf("    Assignment chaining and compound operators make your code look cleaner,\n");
    printf("    and sometimes even run a tiny bit faster. It's all about efficiency, baby! 💯\n");
    sleep(2);

    printf("=============================================================\n");
    printf("You just mastered C Assignment Operators! Your code is leveling up! ⬆️\n");
    printf("=============================================================\n");

    return 0; // Program finished successfully. GG! 🎮
}
