#include <stdio.h>   // For printf, our program's mic.
#include <unistd.h>  // For sleep() to chill between outputs.

/**
 * @brief 💰📉 C Increment & Decrement Operators: When to Get That Bonus/Penalty!
 *
 * @analog Imagine you're managing your game score or a countdown timer.
 * Sometimes you get a bonus point, sometimes a penalty. The big question is:
 * Do you get/lose the point *before* you use the value, or *after* you've already used it?
 * That's the whole vibe behind `++x`, `x++`, `--x`, and `x--`!
 *
 * This program will show you:
 * - **Pre-increment (`++x`):** Get the bonus *first*, then use the new score.
 * - **Post-increment (`x++`):** Use the current score *first*, then get the bonus.
 * - **Pre-decrement (`--x`):** Take the penalty *first*, then use the new count.
 * - **Post-decrement (`x--`):** Use the current count *first*, then take the penalty.
 *
 * The pre- and post-increment (++x and x++) and pre- and post-decrement (--x and x--) behavior is unique 
 * 
 * to these specific increment and decrement operators.
 * 
 * Other arithmetic operators like division (/), multiplication (*), addition (+), subtraction (-), and modulo (%)
 * 
 * do not have a pre- or post-version. For example, there's no such thing as //x or x%% or x** in C. 

 */

int main() {
    printf("=============================================================\n");
    printf("C Increment & Decrement Operators: Bonus/Penalty Vibe Check!💰📉\n");
    printf("=============================================================\n");
    sleep(1);

    // --- Pre-increment (`++x`): Bonus First, Then Use! ---
    printf("\n--- Pre-increment (`++x`): Bonus First, Then Use! ✨ ---\n");
    printf("    @analog: You get a bonus point *before* your score is announced for a challenge.\n");
    printf("    The variable updates its value *before* it's used in the expression.\n");
    sleep(1);

    int score_pre = 10;
    printf("    Initial score_pre: %d\n", score_pre);
    sleep(1);

    // ++score_pre: score_pre becomes 11. THEN, that new value (11) is used in printf.
    printf("    Calling `printf(\"New score: %%d\", ++score_pre);`\n");
    printf("    New score: %d (score_pre is now %d)\n", ++score_pre, score_pre); // Prints 11, score_pre is 11
    sleep(2);

    // --- Post-increment (`x++`): Use First, Then Bonus! ---
    printf("\n--- Post-increment (`x++`): Use First, Then Bonus! ⏳ ---\n");
    printf("    @analog: You use your current score for a challenge *then* you get a bonus point.\n");
    printf("    The variable's *original* value is used in the expression, *then* it updates.\n");
    sleep(1);

    int score_post = 10;
    printf("    Initial score_post: %d\n", score_post);
    sleep(1);

    // score_post++: The original value (10) is used in printf. THEN, score_post becomes 11.
    printf("    Calling `printf(\"Current score: %%d\", score_post++);`\n");
    printf("    Current score: %d (score_post is now %d)\n", score_post++, score_post); // Prints 10, score_post becomes 11
    printf("    (Notice it printed 10, but the variable is now 11! Sneaky!)\n");
    sleep(2);

    // --- Pre-decrement (`--x`): Penalty First, Then Use! ---
    printf("\n--- Pre-decrement (`--x`): Penalty First, Then Use! 📉 ---\n");
    printf("    @analog: You lose a life *before* your remaining lives are displayed on screen.\n");
    printf("    The variable updates its value *before* it's used in the expression.\n");
    sleep(1);

    int lives_pre = 3;
    printf("    Initial lives_pre: %d\n", lives_pre);
    sleep(1);

    // --lives_pre: lives_pre becomes 2. THEN, that new value (2) is used in printf.
    printf("    Calling `printf(\"Lives remaining: %%d\", --lives_pre);`\n");
    printf("    Lives remaining: %d (lives_pre is now %d)\n", --lives_pre, lives_pre); // Prints 2, lives_pre is 2
    sleep(2);

    // --- Post-decrement (`x--`): Use First, Then Penalty! ---
    printf("\n--- Post-decrement (`x--`): Use First, Then Penalty! ☠️ ---\n");
    printf("    @analog: Your current health is displayed *then* you take damage.\n");
    printf("    The variable's *original* value is used in the expression, *then* it updates.\n");
    sleep(1);

    int health_post = 100;
    printf("    Initial health_post: %d\n", health_post);
    sleep(1);

    // health_post--: The original value (100) is used in printf. THEN, health_post becomes 99.
    printf("    Calling `printf(\"Health before damage: %%d\", health_post--);`\n");
    printf("    Health before damage: %d (health_post is now %d)\n", health_post--, health_post); // Prints 100, health_post becomes 99
    printf("    (Printed 100, but the variable is now 99! Ouch!)\n");
    sleep(2);

    printf("\n--- Real-Life Use Cases: When to Pick Your Operator! ---\n");
    printf("    **`++x` or `--x` (Pre-):**\n");
    printf("    - Counting down a timer *before* showing the next second: `printf(\"Time: %%d\\n\", --countdown);`\n");
    printf("    - Iterating through an array *before* accessing the element (e.g., in a loop where the index needs to be updated first).\n");
    printf("    **`x++` or `x--` (Post-):**\n");
    printf("    - Logging a player's score *after* they finish a level: `printf(\"Level completed! Score: %%d\\n\", player_score++);`\n");
    printf("    - Assigning a unique ID and *then* incrementing the counter for the next ID: `new_id = counter++;`\n");
    sleep(2);

    printf("\n--- The Takeaway: Pay Attention to the 'When'! 🔥 ---\n");
    printf("    `++x` / `--x` (pre): Updates BEFORE use. Think of it as 'Get ready, then go!'\n");
    printf("    `x++` / `x--` (post): Updates AFTER use. Think of it as 'Go, then get ready!'\n");
    printf("    Choosing the right one makes your code clearer and bug-free. You got this! 💯\n");
    sleep(2);

    printf("=============================================================\n");
    printf("You just mastered C Increment & Decrement Operators! Keep leveling up! ⬆️\n");
    printf("=============================================================\n");

    return 0; // Program finished successfully. GG! 🎮
}
