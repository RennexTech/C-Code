#include <stdio.h>   // For printf (our megaphone 📢) and other input/output.
#include <stdbool.h> // So we can say true/false instead of using crusty old 1/0.
#include <unistd.h>  // For sleep() to chill between outputs, keep the flow smooth.

/**
 * 
 * @brief 🚀 C Operators: The Action Words of Your Code!
 *
 * @analog Imagine your code is a construction crew. Operators are the tools
 * they use to build, move, and transform things (your data!).
 *
 * This program is your guide to understanding:
 * 1. Assignment Operators: How you give values to your variables, like
 * handing a specific tool to a worker.
 * 
 * 2. Operator Precedence: The "boss" of operations. Who gets to go first
 * in a complex task? (Think PEMDAS/BODMAS from math class).
 * 
 * 3. Operator Associativity: The "tie-breaker" when two tools have the
 * same priority. Do we work from left-to-right, or right-to-left?
 *
 * Mastering these concepts is fundamental for writing logical, predictable,
 * and bug-free C programs. Let's get to work! 🛠️
 * 
 */

int main() {
    printf("=============================================================\n");
    printf("✨ Welcome to Operator School: The C Action Words!✨\n");
    printf("=============================================================\n");
    sleep(1);

    // --- 1. ASSIGNMENT OPERATORS: The Setup Crew ---
    printf("\n--- 🔧 Assignment Operators: Getting Everyone Set Up! ---\n");
    printf("    @analog: Handing out initial gear to your gaming squad. Everyone gets the same starting score.\n");
    sleep(1);

    int x, y, z, f, g, h; // Declaring a squad of integer variables

    // Chained Assignment: x = y = z = f = g = h = 200;
    // This assigns 200 to 'h', then 'g' gets 200, then 'f', and so on, all the way to 'x'.
    // It works from right to left! Super efficient for initializing multiple variables.
    x = y = z = f = g = h = 200;
    printf("    All players starting with 200 XP like a fresh RPG party! 👾\n");
    printf("    x: %d, y: %d, z: %d, f: %d, g: %d, h: %d\n", x, y, z, f, g, h);
    sleep(2);

    // Compound Assignment Operators: The Power-Up Shortcuts!
    printf("\n    --- Compound Assignment Operators: The Power-Up Shortcuts! ⚡ ---\n");
    printf("    @analog: Instead of 'My score is my score PLUS 10,' you just say 'My score += 10!'\n");
    printf("    It's a faster way to do an operation and update the variable in one go.\n");
    sleep(1);

    printf("    Initial x: %d, Initial y: %d\n", x, y);

    x += 65; // x = x + 65; (x leveled up!)
    y += 64; // y = y + 64; (y almost caught up)
    printf("    x got boosted to: %d (x += 65)\n", x);
    printf("    y got boosted to: %d (y += 64)\n", y);
    sleep(2);

    // --- 2. OPERATOR PRECEDENCE: Who Gets to Go First? ---
    printf("\n--- ⚔️ Operator Precedence: Who Gets to Go First? ---\n");
    printf("    @analog: Like the rules in math class (PEMDAS/BODMAS). Multiplication and Division before Addition and Subtraction.\n");
    printf("    C has a strict order for operations. If you don't know it, your math will be off!\n");
    sleep(1);

    int a = 10, b = 5, c = 12; // Resetting values for clarity
    printf("    Current values: a=%d, b=%d, c=%d\n", a, b, c);

    // Math vs. Logic — who gets priority?
    // `a + b` (addition) has higher precedence than `<` (comparison).
    // So, `a + b` happens first, then the comparison.
    printf("\n    🧠 Does a + b < c? (a=%d, b=%d, c=%d)\n", a, b, c);
    bool logicBattle = a + b < c; // 10 + 5 = 15, then 15 < 12 = false
    printf("    Breakdown: Math goes first: (10 + 5) = 15 → Is 15 < 12? Nope.\n");
    printf("    Result: %s\n", logicBattle ? "TRUE ✅" : "FALSE ❌"); // Using ternary for concise output.
    sleep(2);

    // Math vs. Assignment
    // Multiplication (`*`) has higher precedence than compound assignment (`*=`).
    // Addition (`+`) has higher precedence than multiplication.
    x = 5; // Resetting x for this example
    printf("\n    📦 Expression: x *= a + b (x=5, a=10, b=5)\n");
    printf("    Breakdown: First do math inside parentheses: (a + b) = (10 + 5) = 15\n");
    printf("    Then multiply and assign: x = 5 * 15 → x = %d\n", x * (a + b)); // Showing the calculation
    x *= a + b; // x = x * (a + b)
    printf("    x is now: %d 🎯\n", x);
    sleep(2);

    // Relational vs. Logical
    // Relational operators (`<=`, `==`) have higher precedence than logical AND (`&&`).
    // So, comparisons happen first, then the logical AND.
    a = b = c = 10; // Resetting values
    printf("\n    🔍 Expression: a <= b && b == c (all 10)\n");
    printf("    Breakdown: a <= b → (10 <= 10) → TRUE\n");
    printf("               b == c → (10 == 10) → TRUE\n");
    bool check = (a <= b && b == c); // true && true = true
    printf("    Then: TRUE && TRUE → Result: %s\n", check ? "TRUE 💡" : "FALSE 🚫");
    sleep(2);


    
    // --- 3. OPERATOR ASSOCIATIVITY: The Tiebreaker in Drama Club ---
    printf("\n--- 🔁 Operator Associativity: The Tiebreaker in Drama Club ---\n");
    printf("    @analog: What happens when two tools have the exact same priority? Do we work left-to-right, or right-to-left?\n");
    printf("    This rule breaks ties when operators have the same precedence.\n");
    sleep(1);



    // Left-to-right example (Addition and Subtraction have same precedence, left-to-right associativity)
    printf("\n    📖 Left-to-right: 10 - 5 + 2\n");
    int leftToRight = 10 - 5 + 2; // (10 - 5) = 5, then 5 + 2 = 7
    printf("    Do it like reading: (10 - 5) → 5, then 5 + 2 → %d\n", leftToRight);
    sleep(2);
    // For '+' and '-' (which have the same precedence), C (and most languages)
    // reads them strictly from LEFT-TO-RIGHT.
    // C says : Hey bro, you see + and -? Same level. I ain’t picking favorites. Start from the left, march like a soldier. 👮‍♂️




    // Right-to-left example (Assignment operators have right-to-left associativity)
    printf("\n    🔗 Right-to-left: x = y = z = 300\n");
    int aa, bb, cc;
    aa = bb = cc = 300; // Assignment happens from right to left!
    printf("    Breakdown: cc = 300 (cc is 300)\n");
    printf("               bb = cc (bb is 300)\n");
    printf("               aa = bb (aa is 300)\n");
    printf("    Everyone’s now 300! 🧍🧍🧍\n");
    printf("    aa: %d, bb: %d, cc: %d\n", aa, bb, cc);
    sleep(2);

    printf("\n=============================================================\n");
    printf("🎉 Congrats, you now officially understand C operators without melting your brain.\n");
    printf("Go forth and write elite code. You're leveling up! 💻🚀\n");
    printf("=============================================================\n");
    sleep(1);

    return 0; // Program finished successfully. GG! 🎮
}
