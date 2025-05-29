#include <stdio.h>  // For printf.
#include <unistd.h> // For sleep() on Unix-like systems. If on Windows, use <windows.h> and Sleep().

/*
 * 🔁 Pre vs Post Increment/Decrement - Real World Chaos Edition 🔁
 *
 * You’ve seen "x++" and "++x" before. Same with "x--" and "--x".
 * But what’s the real difference? And why does it matter?
 *
 * 📈 TLDR:
 * - post-increment (x++): Use now, add one after.
 * - pre-increment (++x): Add one now, then use.
 *
 * Same goes for decrement (x-- and --x).
 *
 * 🧠 Think of it like this:
 *
 * 1️⃣ MON.EY BONUS (IRL):
 * - x++: You buy your Starbucks ☕ first, then your bank deposits a bonus. Risky!
 * - ++x: You get that sweet paycheck 💰 before swiping the card. Smart move.
 *
 * 2️⃣ GAME LIVES (Gamer Edition 🎮):
 * - x--: You take the hit 🔥, then lose a life AFTER the animation. Looks fine until… 💀
 * - --x: Game deducts a life BEFORE showing the damage. Brutal.
 *
 * 3️⃣ CODE HACKS:
 * x = x + 1      ⟶  adds 1 after doing stuff (same as x++)
 * ++x            ⟶  adds 1 immediately, then continues
 * x++            ⟶  do the thing first, then increment
 *
 * BONUS: ++x vs x++ in expressions. This is where chaos begins...
 */

/**
 * @brief Demonstrates pre-increment (++x) and post-increment (x++).
 *
 * @analog Think of it like getting a bonus (incrementing a number).
 * - **Pre-increment (`++x`):** You get the bonus *before* you use the money.
 * (Update value FIRST, THEN use it in the expression.)
 * - **Post-increment (`x++`):** You use the money *then* you get the bonus.
 * (Use value FIRST, THEN update it.)
 */
void demonstrate_pre_post_increments() {
    printf("\n--- Pre- vs. Post-Increment/Decrement: When to Get That Bonus! 💰 ---\n");

    printf("\n🤑 Scenario 1: Post-Increment — Bonus comes *after* spending.\n");
    int x_post = 5;
    printf("Initial x_post: %d\n", x_post);
    // Real-world: You tell your friend you'll pay them $5 for a coffee (use value),
    // THEN you get a $1 bonus from your boss (x_post becomes 6).
    printf("Action: int y_post = x_post++;\n");
    int y_post = x_post++; // y_post gets 5, THEN x_post becomes 6
    printf("  You spent: $%d (y_post got the OLD value of x_post)\n", y_post); // prints 5
    printf("  After transaction, your balance (post-bonus): $%d (x_post is now updated)\n", x_post); // now 6
    printf("  TLDR: Use now (%d), add one after (becomes %d).\n", y_post, x_post);
    sleep(2);

    printf("\n💸 Scenario 2: Pre-Increment — Bonus comes *before* spending.\n");
    int x_pre = 5;
    printf("Initial x_pre: %d\n", x_pre);
    // Real-world: Your boss gives you a $1 bonus (x_pre becomes 6),
    // THEN you tell your friend you'll pay them $6 for a coffee (use new value).
    printf("Action: int y_pre = ++x_pre;\n");
    int y_pre = ++x_pre; // x_pre becomes 6, THEN y_pre gets 6
    printf("  You got the bonus first! New balance: $%d (x_pre is updated first)\n", x_pre); // now 6
    printf("  Then spent: $%d (y_pre got the NEW value of x_pre)\n", y_pre); // prints 6
    printf("  TLDR: Add one now (%d), then use (%d).\n", x_pre, y_pre);
    sleep(2);

    printf("\n--- Same vibe for decrement (subtracting a penalty or losing a life in a game): ---\n");

    printf("\n🔥 Post-Decrement: You take damage, THEN lose a life.\n");
    int x_post_dec = 5;
    printf("Initial x_post_dec (lives): %d\n", x_post_dec);
    // Real-world: You have 5 lives. You use one (y_post_dec gets 5),
    // THEN your lives count goes down to 4 (x_post_dec becomes 4).
    printf("Action: int y_post_dec = x_post_dec--;\n");
    int y_post_dec = x_post_dec--; // y_post_dec gets 5, THEN x_post_dec becomes 4
    printf("  Lives shown during damage: %d (y_post_dec got the OLD value)\n", y_post_dec); // still 5
    printf("  Lives after damage: %d (x_post_dec is now updated)\n", x_post_dec); // now 4
    printf("  TLDR: Use now (%d), subtract one after (becomes %d).\n", y_post_dec, x_post_dec);
    sleep(2);

    printf("\n💀 Pre-Decrement: Life drops BEFORE the hit lands.\n");
    int x_pre_dec = 5;
    printf("Initial x_pre_dec (lives): %d\n", x_pre_dec);
    // Real-world: You have 5 lives. Your lives count goes down to 4 (x_pre_dec becomes 4),
    // THEN you see you have 4 lives left (y_pre_dec gets 4).
    printf("Action: int y_pre_dec = --x_pre_dec;\n");
    int y_pre_dec = --x_pre_dec; // x_pre_dec becomes 4, THEN y_pre_dec gets 4
    printf("  Lives dropped instantly. Shown lives: %d (x_pre_dec is updated first)\n", x_pre_dec); // now 4
    printf("  Then shown lives: %d (y_pre_dec got the NEW value)\n", y_pre_dec); // prints 4
    printf("  TLDR: Subtract one now (%d), then use (%d).\n", x_pre_dec, y_pre_dec);
    sleep(2);

    printf("\n--- CODE HACKS: Simple Increment/Decrement Equivalents ---\n");
    int val_a = 10;
    printf("Initial val_a: %d\n", val_a);
    printf("val_a = val_a + 1;  // val_a becomes %d\n", val_a = val_a + 1); // Simple addition
    sleep(1);

    int val_b = 10;
    printf("Initial val_b: %d\n", val_b);
    printf("++val_b;            // val_b becomes %d (same as val_b = val_b + 1; when used alone)\n", ++val_b); // Pre-increment used alone
    sleep(1);

    int val_c = 10;
    printf("Initial val_c: %d\n", val_c);
    printf("val_c++;            // val_c becomes %d (same as val_c = val_c + 1; when used alone)\n", val_c++); // Post-increment used alone
    printf("  Note: When used alone on a line, x++ and ++x behave identically.\n");
    printf("  The difference only matters when they are part of a larger expression.\n");
    sleep(2);

    printf("\n--- COMBO EXPRESSION SCENARIO (Bonus: ++x vs x++ in expressions) ---\n");
    printf("🧪 Scenario 4: Expression Math — Let the madness begin.\n");

    int potions = 2;
    printf("Initial potions: %d\n", potions);

    printf("Action: int effect_power = 4 * (++potions * 2 + 3);\n");
    printf("  Let's break this down like a TikTok dance tutorial:\n");
    printf("  1. `++potions`: This is a PRE-increment. Potions becomes 3 *BEFORE* anything else in the expression uses its value.\n");
    printf("     So, potions is now: %d\n", potions + 1); // Showing what it will become
    potions = 2; // Resetting for the actual calculation
    // Here’s the real twist: ++potions becomes 3 BEFORE expression runs
    // So: 4 * (3*2 + 3) = 4 * (6 + 3) = 4 * 9 = 36
    int effect_power = 4 * (++potions * 2 + 3);
    printf("  2. Now, `(potions * 2)` becomes `(%d * 2)`, which is %d.\n", potions, potions * 2);
    printf("  3. Next, `(%d + 3)` becomes %d.\n", potions * 2, potions * 2 + 3);
    printf("  4. Finally, `4 * %d` becomes %d.\n", (potions * 2 + 3), 4 * (potions * 2 + 3));
    printf("Potions after pre-increment: %d\n", potions);    // 3
    printf("Effect power: %d\n\n", effect_power); // 36
    sleep(3);

    printf("Fun fact: If we had used potions++ instead (POST-increment):\n");
    int potions_post = 2;
    printf("Initial potions_post: %d\n", potions_post);
    printf("Action: int effect_power_post = 4 * (potions_post++ * 2 + 3);\n");
    printf("  1. `potions_post++`: This is a POST-increment. The *current* value of potions_post (2) is used in the expression *first*.\n");
    printf("     *Then*, after the expression is evaluated, potions_post increments to 3.\n");
    // If we had used potions++ instead, it would’ve calculated as:
    // 4 * (2*2 + 3) = 4 * (4 + 3) = 4 * 7 = 28 — then potions would become 3 after.
    int effect_power_post = 4 * (potions_post++ * 2 + 3);
    printf("  2. So, `(potions_post (old value) * 2)` becomes `(2 * 2)`, which is 4.\n");
    printf("  3. Next, `(4 + 3)` becomes 7.\n");
    printf("  4. Finally, `4 * 7` becomes 28.\n");
    printf("Potions_post after post-increment: %d\n", potions_post); // 3
    printf("Effect power (with post-increment): %d\n\n", effect_power_post); // 28
    sleep(3);

    printf("🏁 Game Over! You now know how to level up (or lose a life) *before or after* the action. ⚔️ Choose wisely.\n");

    return 0;
}
