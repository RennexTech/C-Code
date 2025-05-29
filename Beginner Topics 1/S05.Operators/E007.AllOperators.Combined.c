//This is for beginners who don't understand how to do operations in C, so take it slow, its a bit heavy and long.
// All this is split into independent files.

#include <stdio.h>   // For printf, scanf - our program's mic and ear.
#include <stdlib.h>  // Standard library for general utilities (like exit, if we ever needed it, but we're chill).
#include <math.h>    // For M_PI (that's Pi!) and pow (for powers) in circle calculations.
#include <string.h>  // For strcspn in input handling (to keep our strings clean).
#include <stdbool.h> // For bool type (true/false) - makes C less grumpy.
#include <unistd.h>  // For sleep() - to chill between outputs, keep the flow smooth.

// --- Function Prototypes: The "Promises" to the Compiler ---
// (These tell the compiler, "Hey, these functions are coming later, trust me! It's like a sneak peek for the compiler, fam.")
void clear_input_buffer();
double get_double_input(const char* prompt);
int get_integer_input(const char* prompt);



// --- Operator Demonstration Function prototypes---
void demonstrate_undefined_behavior_with_increment();
void demonstrate_pre_post_increments();
void demonstrate_logical_operators_comparison();
void demonstrate_complex_arithmetic();
void demonstrate_comparison_logical();
void demonstrate_logical_ternary();
void demonstrate_operator_precedence();
void demonstrate_pre_post_mixed();
void demonstrate_invalid_increment();
void demonstrate_complex_expression_order();
void demonstrate_modulo_division();
void demonstrate_operator_precedence_complex();
void demonstrate_comma_operator();
void demonstrate_char_arithmetic();
void demonstrate_chained_assignment();
void demonstrate_variable_swap();
void demonstrate_ternary_operator();
void demonstrate_logical_assignment_side_effects();

// --- Beginner Exercises Solutions Functions ---
void convertCelsiusToFahrenheit();
void calculateCircleAreaPerimeter();
void convertDecimalToOctalHex();
void findRemainderByThree();
void sumOrDifferenceTernary();
void calculateSimpleInterest();
void calculateTotalPercentageMarks();


// ===================================================================================

/**
 * @brief Clears the standard input buffer.
 *
 * @analog Flushes the toilet after use to keep things clean for the next input.
 * Essential after `scanf` or `fgets` to prevent leftover characters
 * (like the newline from pressing Enter) from messing up next inputs. No cap.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


/**
 * @brief Prompts for and reads a double value from the user.
 * @param prompt Message to display to the user.
 * @return The valid double value entered by the user.
 *
 * @analog This is the bouncer(function/block of code that runs when called) for your decimal numbers. It's chill with numbers
 * like 3.14 or 99.99. Anything else? "Nah, that's not a number, try again."
 * Keeps the vibes right for floating-point calculations.
 */
double get_double_input(const char* prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1) {
        printf("Invalid input! Please enter a number. Fr fr. 🚫\n");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

// ===================================================================================


/**
 * @brief Prompts for and reads an integer value from the user.
 * @param prompt The message to display to the user.
 * @return The valid integer entered by the user.
 *
 * @analog This is like a bouncer(function) for your input. It won't let anything through
 * unless it's a legit whole number. If you try to sneak in text, it's like, "Nah, fam,
 * that's not gonna fly. Try again!" It keeps asking until you give it what it wants.
 */
int get_integer_input(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input! Please enter an integer. No cap. 🚫\n");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

// ===================================================================================


/**
 * @brief Demonstrates undefined behavior with post-increment/decrement.
 *
 * @analog This is like trying to change your outfit twice at the exact same millisecond
 * while looking in the mirror. The mirror (compiler) gets confused, and the final outfit
 * (variable value) could be anything! It's wild, unpredictable, and you should
 * NEVER rely on it. It's basically a bug waiting to happen.
 */
void demonstrate_undefined_behavior_with_increment() {
    printf("\n--- Undefined Behavior Example (DO NOT RELY ON THIS) ---\n");
    printf("This is where C gets spicy and unpredictable. 🌶️\n");
    int a = 10;
    printf("Initial 'a': %d\n", a);
    sleep(1);

    // 'a' is modified twice here within one line, without a "sequence point."
    // The C standard says this is UNDEFINED BEHAVIOR.
    // It means the compiler can do whatever it wants, and the result might change
    // every time you run it, or on different computers.
    a = a++ * a--; // 🤯 This is the spicy line!
    printf("Result of a = a++ * a--; (Undefined Behavior): %d\n", a);
    printf("Warning: The actual value of 'a' might be different on other compilers or runs. Don't do this IRL! 🙅‍♂️\n");
    sleep(2);
}

// ===================================================================================

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

    int x_post = 5;
    printf("Initial x_post: %d\n", x_post);
    int y_post = x_post++; // y_post gets 5, THEN x_post becomes 6
    printf("Post-increment (y = x++): y_post gets the old value (5), then x_post becomes %d. So, x_post = %d, y_post = %d\n", x_post, x_post, y_post);
    sleep(1);

    int x_pre = 5;
    printf("Initial x_pre: %d\n", x_pre);
    int y_pre = ++x_pre; // x_pre becomes 6, THEN y_pre gets 6
    printf("Pre-increment (y = ++x): x_pre becomes %d, then y_pre gets the new value (6). So, x_pre = %d, y_pre = %d\n", x_pre, x_pre, y_pre);
    sleep(1);

    printf("\nSame vibe for decrement (subtracting a penalty):\n");
    int x_post_dec = 5;
    printf("Initial x_post_dec: %d\n", x_post_dec);
    int y_post_dec = x_post_dec--; // y_post_dec gets 5, THEN x_post_dec becomes 4
    printf("Post-decrement (y = x--): y_post_dec gets the old value (5), then x_post_dec becomes %d. So, x_post_dec = %d, y_post_dec = %d\n", x_post_dec, x_post_dec, y_post_dec);
    sleep(1);

    int x_pre_dec = 5;
    printf("Initial x_pre_dec: %d\n", x_pre_dec);
    int y_pre_dec = --x_pre_dec; // x_pre_dec becomes 4, THEN y_pre_dec gets 4
    printf("Pre-decrement (y = --x): x_pre_dec becomes %d, then y_pre_dec gets the new value (4). So, x_pre_dec = %d, y_pre_dec = %d\n", x_pre_dec, x_pre_dec, y_pre_dec);
    sleep(1);

    printf("\nComplex pre-increment example (order matters!):\n");
    int a_val = 2;
    printf("Initial a_val: %d\n", a_val);
    // Let's break this down:
    // 1. `++a_val`: a_val becomes 3. (Pre-increment happens first)
    // 2. `(3 * 2)`: evaluates to 6.
    // 3. `(6 + 3)`: evaluates to 9.
    // 4. `4 * 9`: evaluates to 36.
    int result_x = 4 * (++a_val * 2 + 3);
    printf("Result of 4 * (++a_val * 2 + 3): a_val = %d, result_x = %d\n", a_val, result_x);
    sleep(2);
}


// ===================================================================================

/**
 * @brief Demonstrates logical AND (&&) and logical OR (||) operators.
 *
 * @analog Think of these as your decision-making superpowers:
 * - **Logical AND (`&&`):** Like saying "I'll go to the party if I have money `AND` my friends are going."
 * Both conditions MUST be true for the whole thing to be true. If the first one is false, it doesn't even check the second.
 * - **Logical OR (`||`):** Like saying "I'll eat pizza if it's pepperoni `OR` it's cheese."
 * Only ONE condition needs to be true for the whole thing to be true. If the first one is true, it doesn't even check the second.
 * These operators return `1` for true and `0` for false.
 */
void demonstrate_logical_operators_comparison() {
    printf("\n--- Logical Operators (&& and ||): Your Decision Superpowers! 🧠 ---\n");
    int a = 3, b = 4, c = 3, d = 4;
    int x_and, y_or;

    printf("Initial values: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    sleep(1);

    // Logical AND (&&): True if BOTH conditions are true
    // (3 == 5) is false, (4 == 7) is false. So, false && false = false (0)
    x_and = (a == 5) && (b == 7);
    printf("x = (a == 5) && (b == 7); -> x = %d (False, 'cause both are cap)\n", x_and);
    sleep(1);

    // Logical OR (||): True if AT LEAST ONE condition is true
    // (3 == 5) is false, (4 == 8) is false. So, false || false = false (0)
    y_or = (c == 5) || (d == 8);
    printf("y = (c == 5) || (d == 8); -> y = %d (False, 'cause both are cap)\n", y_or);
    sleep(1);

    // Reset variables for another example, let's get some true vibes
    a = 6, b = 9, c = 6, d = 10;
    printf("\nNew values: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    sleep(1);

    // (6 == 6) is true, (9 == 9) is true. So, true && true = true (1)
    x_and = (a == 6) && (b == 9);
    printf("x = (a == 6) && (b == 9); -> x = %d (True, 'cause both are real)\n", x_and);
    sleep(1);

    // (6 == 6) is true, (10 == 10) is true. So, true || true = true (1)
    y_or = (c == 6) || (d == 10);
    printf("y = (c == 6) || (d == 10); -> y = %d (True, 'cause both are real)\n", y_or);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates a complex arithmetic expression with logical NOT (!).
 *
 * @analog This is like a mind-bender puzzle! You gotta follow the strict order
 * of operations (precedence) and understand what `!` does to numbers.
 * `!` (Logical NOT) turns any non-zero number into `0` (false), and `0` into `1` (true).
 */
void demonstrate_complex_arithmetic() {
    printf("\n--- Complex Arithmetic Expression: The Mind Bender! 🤯 ---\n");
    int a = -3;
    printf("Initial 'a': %d\n", a);
    sleep(1);

    // Let's break down: a *= -a - a + !a;
    // 1. `!a`: Logical NOT of -3 (which is non-zero, so it's considered true). `!true` is `0` (false).
    // 2. `-a`: Negation of -3 is 3.
    // 3. The expression becomes: `a *= (3) - (-3) + (0)`
    // 4. `a *= 3 + 3 + 0`
    // 5. `a *= 6`
    // 6. `a = -3 * 6 = -18`
    a *= -a - a + !a;
    printf("Result of a *= -a - a + !a; : %d (Mind blown, right?)\n", a); // Expected: -18
    sleep(2);
}


// ===================================================================================

/**
 * @brief Demonstrates comparison and logical operators.
 *
 * @analog This is like a quick quiz where you're comparing values and then
 * combining those comparisons with "AND" or "OR" logic.
 */
void demonstrate_comparison_logical() {
    printf("\n--- Comparison and Logical Operators: Quick Quiz! ---\n");
    int a = 2, b = 1, c_res, d_res;
    printf("Initial: a=%d, b=%d\n", a, b);
    sleep(1);

    // c_res = a < b; // 2 < 1 is false. So, c_res = 0
    c_res = a < b;
    printf("c_res = (a < b); -> c_res=%d (False)\n", c_res);
    sleep(1);

    // d_res = (a > b) && (c_res < b);
    // (a > b) is (2 > 1), which is true (1).
    // (c_res < b) is (0 < 1), which is true (1).
    // true && true is true (1). So, d_res = 1
    d_res = (a > b) && (c_res < b);
    printf("d_res = (a > b) && (c_res < b); -> d_res=%d (True)\n", d_res);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates logical NOT and the ternary operator.
 *
 * @analog This is like a quick "if-else" shortcut.
 * - `!` (Logical NOT): Flips the truth. `!true` is `false`, `!false` is `true`.
 * - Ternary Operator (`condition ? value_if_true : value_if_false;`):
 * Like asking: "Is this true? If yes, do A. If no, do B." All in one line!
 */
void demonstrate_logical_ternary() {
    printf("\n--- Logical NOT and Ternary Operator: The Quick Flip & Shortcut! ---\n");
    int a = 9, b = 15, c = 16, e_res, f_res;
    printf("Initial: a=%d, b=%d, c=%d\n", a, b, c);
    sleep(1);

    // e_res = !(a < b && b < c);
    // (a < b) is (9 < 15), which is true.
    // (b < c) is (15 < 16), which is true.
    // (true && true) is true.
    // `!true` is false (0). So, e_res = 0.
    e_res = !(a < b && b < c);
    printf("e_res = !(a < b && b < c); -> e_res=%d (False, 'cause we flipped the truth!)\n", e_res);
    sleep(1);

    // f_res = (a > b) ? a - b : b - a;
    // (a > b) is (9 > 15), which is false.
    // So, we evaluate the `false` part: `b - a` (15 - 9 = 6).
    // f_res = 6.
    f_res = (a > b) ? a - b : b - a;
    printf("f_res = (a > b) ? a - b : b - a; -> f_res=%d (Ternary shortcut!)\n", f_res);
    sleep(2);
}

// ===================================================================================


/**
 * @brief Demonstrates operator precedence with mixed arithmetic.
 *
 * @analog This is like the "order of operations" you learned in math class (PEMDAS/BODMAS).
 * Multiplication and Division happen BEFORE Addition and Subtraction.
 * If you forget this, your math will be off!
 */
void demonstrate_operator_precedence() {
    printf("\n--- Operator Precedence: Math Class Rules! 📏 ---\n");
    int a = 5;
    printf("Initial 'a': %d\n", a);
    a = 6; // 'a' is now 6
    printf("New 'a' for calculation: %d\n", a);
    sleep(1);

    // a = a + 5 * a;
    // 1. `5 * a` (5 * 6) evaluates to 30. (Multiplication first!)
    // 2. `a + 30` (6 + 30) evaluates to 36.
    // 3. `a` becomes 36.
    a = a + 5 * a;
    printf("Result of a = a + 5 * a; -> a=%d (Multiplication first, always!)\n", a); // Expected: 36
    sleep(2);
}

// ===================================================================================


/**
 * @brief Demonstrates mixed pre- and post-increment/decrement.
 *
 * @analog This is like a tricky pop quiz on when you get your bonus (increment)
 * or penalty (decrement). Remember:
 * - `++a`: Bonus first, then use.
 * - `a--`: Use first, then penalty.
 * The order of `printf` also matters here!
 */
void demonstrate_pre_post_mixed() {
    printf("\n--- Mixed Pre/Post Increment/Decrement: The Pop Quiz! 🤯 ---\n");
    int a = 5, b = 5;
    printf("Initial a=%d, b=%d\n", a, b);
    sleep(1);

    // printf("%%d\t", ++a);
    // `++a`: 'a' becomes 6. Then print 6.
    printf("printf(\"%%d\\t\", ++a); -> %d\t", ++a);
    sleep(1);

    // printf("%%d\t", b--);
    // `b--`: Print 5. Then 'b' becomes 4.
    printf("printf(\"%%d\\t\", b--); -> %d\t", b--);
    sleep(1);

    // printf("%%d\\t\", a);
    // Print current 'a' (which is 6).
    printf("printf(\"%%d\\t\", a); -> %d\t", a);
    sleep(1);

    // printf("%%d\\n\", b);
    // Print current 'b' (which is 4).
    printf("printf(\"%%d\\n\", b); -> %d\n", b);
    sleep(1);

    printf("Final values: a=%d, b=%d\n", a, b);
    sleep(2);
}

// ===================================================================================


/**
 * @brief Demonstrates invalid increment/decrement operations (lvalue required).
 *
 * @analog This is like trying to change a fixed sign on a wall. You can't
 * increment or decrement a number that's just a value (like `8`) or a temporary
 * result (like `x + y`). You can only change things that are actual, modifiable
 * storage locations (variables). If you try, the compiler will be like, "Nah, fam,
 * that's a compile-time error!"
 */
void demonstrate_invalid_increment() {
    printf("\n--- Invalid Increment/Decrement Operations (Compile-time Errors) ---\n");
    printf("You can't increment/decrement just any value. It needs to be a variable!\n");
    int x = 0, y = 0, z = 0; // Initialize to avoid warnings, though not used in failing lines.
    sleep(1);

    printf("These lines are commented out because they will break your code at compile time:\n");
    printf("  // x = 8++;   // ERROR: 8 is a constant, not a variable. Can't change a fixed value.\n");
    printf("  // y = ++x++; // ERROR: You can't increment something that's already being incremented in the same spot. It's like double-tapping a button that's already pressed.\n");
    printf("  // z = (x + y)--; // ERROR: (x+y) is just a temporary result, not a variable you can modify.\n");
    printf("Increment/decrement operators must be used on actual, modifiable variables. Keep it real. 💯\n");
    sleep(2);
}

// ===================================================================================


/**
 * @brief Demonstrates a complex expression with operator precedence and side effects.
 *
 * @analog This is the ultimate mind-bender! When you have multiple `++` or `--`
 * on the *same variable* within a single expression, C says, "I don't guarantee
 * the order!" This leads to **UNDEFINED BEHAVIOR**. It's like throwing a bunch
 * of dice and expecting a specific outcome – it's random, and you can't trust it.
 * The result might be different every time, or on different compilers. AVOID THIS!
 */
void demonstrate_complex_expression_order() {
    printf("\n--- Complex Expression Order (Potential Undefined Behavior) ---\n");
    printf("Warning: This is where C gets chaotic! DO NOT REPLICATE IN REAL CODE. ⚠️\n");
    int a = 4, b = 8, c = 3, d = 9, z_res;
    printf("Initial: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    sleep(1);

    // This expression has UNDEFINED BEHAVIOR because 'a', 'b', 'c', 'd'
    // are modified multiple times within a single expression without "sequence points."
    // The order in which `a++`, `++b`, `c--`, `--d` are evaluated relative to each other
    // and relative to the arithmetic operations is NOT guaranteed by the C standard.
    // The result you see might be different on another compiler or even another run!
    z_res = a++ + ++b * c-- - --d; // Original had `--d` which is invalid. Fixed to `- --d`.
    printf("Result of z = a++ + ++b * c-- - --d; (Undefined Behavior): %d\n", z_res);
    printf("Final values: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    printf("Note: The result and final values may vary due to undefined behavior. It's like a glitch in the Matrix. 👾\n");
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates modulo and division operators with negative numbers.
 *
 * @analog This is like splitting your snacks (division) or finding leftovers (modulo).
 * - Division (`/`): For integers, it's whole number division (no decimals).
 * - Modulo (`%`): Gives you the remainder after division.
 * The sign of the modulo result depends on the *dividend* (the first number)!
 */
void demonstrate_modulo_division() {
    printf("\n--- Modulo and Division: Splitting Snacks & Finding Leftovers! 🍕 ---\n");
    int a = 14, b_res, c_res;
    printf("Initial 'a': %d\n", a);
    sleep(1);

    // a = a % -5;
    // 14 % -5 = 4. The sign of the result is the same as the dividend (14 is positive, so 4 is positive).
    a = a % -5;
    printf("a = a %% -5; -> a=%d (Remainder is 4, same sign as 14)\n", a);
    sleep(1);

    // b_res = a / 3;
    // a is now 4. 4 / 3 = 1 (integer division, no decimals)
    b_res = a / 3;
    printf("b_res = a / 3; -> b_res=%d (Integer division, no decimals!)\n", b_res);
    sleep(1);

    // c_res = a / 5 % 3;
    // 1. `a / 5` is `4 / 5`, which is `0` (integer division).
    // 2. `0 % 3` is `0`.
    // So, c_res = 0.
    c_res = a / 5 % 3;
    printf("c_res = a / 5 %% 3; -> c_res=%d (Order matters!)\n", c_res);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates complex operator precedence with potential division by zero.
 *
 * @analog This is another math puzzle where you REALLY need to remember the order
 * of operations. If you mess up, you could hit a "divide by zero" error, which is
 * like a program crash. We've fixed the original code to avoid that black hole!
 */
void demonstrate_operator_precedence_complex() {
    printf("\n--- Complex Operator Precedence: Avoiding Black Holes! ⚫️ ---\n");
    int a = 15, b = 13, c = 16, x_res, y_res;
    printf("Initial: a=%d, b=%d, c=%d\n", a, b, c);
    sleep(1);

    // x_res = a - 3 % 2 + c * 2 / 4 % 2 + b / 4;
    // Let's break it down by precedence (%, /, * before +, -):
    // 1. `3 % 2` -> 1
    // 2. `c * 2` -> `16 * 2` -> 32
    // 3. `32 / 4` -> 8
    // 4. `8 % 2` -> 0
    // 5. `b / 4` -> `13 / 4` -> 3 (integer division)
    // Now, put it back together: `x_res = a - 1 + 0 + 3`
    // `x_res = 15 - 1 + 0 + 3` -> `14 + 0 + 3` -> `17`
    x_res = a - 3 % 2 + c * 2 / 4 % 2 + b / 4;
    printf("x = a - 3 %% 2 + c * 2 / 4 %% 2 + b / 4; -> x_res=%d\n", x_res);
    sleep(1);

    // y_res = a = b + 5 - b + 9 / 3;
    // 1. `9 / 3` -> 3
    // 2. `b + 5 - b` -> `13 + 5 - 13` -> 5
    // 3. `a = 5 + 3` -> `a = 8`. (Assignment happens right-to-left, so 'a' gets 8)
    // 4. `y_res = a` -> `y_res = 8`.
    y_res = a = b + 5 - b + 9 / 3;
    printf("y = a = b + 5 - b + 9 / 3; -> y_res=%d (a is now %d)\n", y_res, a);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates the comma operator.
 *
 * @analog This is like doing a bunch of tiny tasks in one go, but only the
 * result of the *very last task* matters for the whole expression.
 * It evaluates expressions from left to right, but only the rightmost value is used.
 */
void demonstrate_comma_operator() {
    printf("\n--- Comma Operator: The Multi-Tasker! 📝 ---\n");
    int x, y, z, k = 10;
    printf("Initial k=%d\n", k);
    sleep(1);

    // k += (x = 5, y = x + 2, z = x + y);
    // 1. `x = 5`: x becomes 5.
    // 2. `y = x + 2`: y becomes 5 + 2 = 7.
    // 3. `z = x + y`: z becomes 5 + 7 = 12.
    // The entire expression `(x = 5, y = x + 2, z = x + y)` evaluates to the value of `z` (which is 12).
    // So, `k += 12` means `k = 10 + 12 = 22`.
    k += (x = 5, y = x + 2, z = x + y);
    printf("k += (x = 5, y = x + 2, z = x + y); -> x=%d, y=%d, z=%d, k=%d\n", x, y, z, k);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates arithmetic operations involving char and int.
 *
 * @analog Characters (`char`) are secretly just small numbers (their ASCII values).
 * So, when you do math with them, C treats them like numbers. It's like
 * adding a letter's secret code to another number.
 */
void demonstrate_char_arithmetic() {
    printf("\n--- Character Arithmetic: Secret Codes! 🤫 ---\n");
    int a = 9;
    char ch = 'A'; // ASCII for 'A' is 65
    printf("Initial: a=%d, ch='%c' (ASCII %d)\n", a, ch, ch);
    sleep(1);

    // a = a + ch + 24;
    // a = 9 + 65 (ASCII of 'A') + 24 = 98
    a = a + ch + 24;
    printf("After a = a + ch + 24;: a=%d\n", a);
    sleep(1);

    // When you print a number as a char (%c), it shows the character for that ASCII value.
    // 98 is ASCII for 'b'.
    printf("ch as int: %d, ch as char: %c\t", ch, ch);
    printf("a as int: %d, a as char: %c (98 is 'b'!) \n", a, a);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates chained assignments and compound assignments.
 *
 * @analog This is like a quick way to assign the same value to multiple variables
 * (`a = b = c = d = 4;`). Or, compound assignments are shortcuts like `a += b`
 * instead of `a = a + b`. It's all about writing less code for the same job!
 */
void demonstrate_chained_assignment() {
    printf("\n--- Chained and Compound Assignments: Shortcuts! ⚡ ---\n");
    int a, b, c, d;

    // Chained assignment: assigns 4 to d, then c, then b, then a. (Right to left!)
    a = b = c = d = 4;
    printf("Initial: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    sleep(1);

    // a *= b + 1; Equivalent to a = a * (b + 1)
    // a = 4 * (4 + 1) = 4 * 5 = 20
    a *= b + 1;
    printf("After a *= b + 1;: a=%d (Shortcut for a = a * (b + 1))\n", a);
    sleep(1);

    // c += d *= 3; This is a tricky one! Assignment operators have right-to-left associativity.
    // 1. `d *= 3` -> `d = d * 3` -> `d = 4 * 3 = 12`. (d is now 12)
    // 2. `c += 12` -> `c = c + 12` -> `c = 4 + 12 = 16`. (c is now 16)
    c += d *= 3;
    printf("After c += d *= 3;: c=%d, d=%d (Order matters here!)\n", c, d);
    sleep(2);
}


// ===================================================================================

/**
 * @brief Demonstrates swapping two integer variables using a temporary variable.
 *
 * @analog This is like swapping two items between two friends (A and B)
 * by using a third friend (Temp) as a temporary holder.
 * A gives to Temp, B gives to A, Temp gives to B. Simple, effective!
 */
void demonstrate_variable_swap() {
    printf("\n--- Variable Swapping: The Three-Way Handshake! 🤝 ---\n");
    int a = 5, b = 10, temp;
    printf("Before swap: a=%d, b=%d\n", a, b);
    sleep(1);

    // Swap values using a temporary variable
    temp = a; // Friend Temp holds A's item
    a = b;    // A gets B's item
    b = temp; // B gets Temp's item (which was A's original item)
    printf("After swap: a=%d, b=%d (Magic! ✨)\n", a, b);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates the ternary conditional operator.
 *
 * @analog This is your "if-else" shortcut for assigning a value.
 * Syntax: `condition ? value_if_true : value_if_false;`
 * It's like asking: "Is this condition true? If yes, use THIS value. Else, use THAT value."
 * All in one neat line!
 */
void demonstrate_ternary_operator() {
    printf("\n--- Ternary Conditional Operator: The Quick Decision Maker! 🤔 ---\n");
    int a = 10, b = 3, max_val;
    printf("Comparing %d and %d...\n", a, b);
    sleep(1);

    // If (a > b) is true, max_val = a. Else, max_val = b.
    max_val = (a > b) ? a : b; // 10 > 3 is true, so max_val = 10
    printf("Max of %d and %d is: %d (Ternary did the job!)\n", a, b, max_val);
    sleep(2);
}


// ===================================================================================


/**
 * @brief Demonstrates logical operators with assignment side effects.
 *
 * @analog This is where logical operators (`&&`, `||`) get a bit sneaky because
 * you're also assigning values *inside* the conditions. Remember **short-circuiting**:
 * - `&&`: If the first part is false, it stops and doesn't check the second part.
 * - `||`: If the first part is true, it stops and doesn't check the second part.
 * This means assignments in the skipped part won't happen!
 */
void demonstrate_logical_assignment_side_effects() {
    printf("\n--- Logical Operators with Assignment Side Effects: Sneaky Business! 🕵️‍♀️ ---\n");
    int a = 3, b = 4, c = 3, d = 4, x_res, y_res;
    printf("Initial: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    sleep(1);

    // x_res = (a = 5) && (b = 7);
    // 1. `(a = 5)`: 'a' becomes 5. This expression evaluates to 5 (non-zero, so true).
    // 2. `(b = 7)`: 'b' becomes 7. This expression evaluates to 7 (non-zero, so true).
    // 3. `true && true` is `true` (1). So, x_res = 1.
    x_res = (a = 5) && (b = 7);
    printf("After `x = (a = 5) && (b = 7);`: a=%d, b=%d, x_res=%d\n", a, b, x_res);
    sleep(1);

    // y_res = (c = 5) || (d = 8);
    // 1. `(c = 5)`: 'c' becomes 5. This expression evaluates to 5 (non-zero, so true).
    // 2. Since the first part of `||` is true, the second part `(d = 8)` is **NOT evaluated** (short-circuiting!).
    //    So, 'd' remains its original value (4).
    // 3. `true || ...` is `true` (1). So, y_res = 1.
    y_res = (c = 5) || (d = 8);
    printf("After `y = (c = 5) || (d = 8);`: c=%d, d=%d, y_res=%d (d didn't change!)\n", c, d, y_res);
    sleep(2);

    printf("\nLet's try another short-circuiting example:\n");
    a = 5; b = 4; // Resetting for clarity
    c = 5; d = 4; // Resetting for clarity
    printf("New initial: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    sleep(1);

    // x_res = (a == 6) && (b = 9);
    // 1. `(a == 6)`: (5 == 6) is false (0).
    // 2. Since the first part of `&&` is false, the second part `(b = 9)` is **NOT evaluated** (short-circuiting!).
    //    So, 'b' remains its original value (4).
    // 3. `false && ...` is `false` (0). So, x_res = 0.
    x_res = (a == 6) && (b = 9);
    printf("After `x = (a == 6) && (b = 9);`: a=%d, b=%d, x_res=%d (b didn't change!)\n", a, b, x_res);
    sleep(1);

    // y_res = (c == 6) || (d = 10);
    // 1. `(c == 6)`: (5 == 6) is false (0).
    // 2. Since the first part of `||` is false, the second part `(d = 10)` **IS evaluated**.
    //    'd' becomes 10.
    // 3. `false || true` is `true` (1). So, y_res = 1.
    y_res = (c == 6) || (d = 10);
    printf("After `y = (c == 6) || (d = 10);`: c=%d, d=%d, y_res=%d (d DID change!)\n", c, d, y_res);
    sleep(2);
}


// ===================================================================================


// --- Functions for "QUESTIONS ANSWERED" section ---

/**
 * @brief Converts Celsius to Fahrenheit.
 * @param celsius Temperature in Celsius.
 * @return Temperature in Fahrenheit.
 * @analog This is like translating temperature units for your international friends.
 * You give it the Celsius vibe, and it gives you the Fahrenheit vibe back.
 */
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

/**
 * @brief Prompts for Celsius, converts to Fahrenheit, and prints.
 * @analog Your personal weather app translator. You punch in the Celsius,
 * and it spits out the Fahrenheit so you know how to dress.
 */
void convertCelsiusToFahrenheit() {
    printf("\n--- Celsius to Fahrenheit Converter: Weather Vibe Check! ☀️ ---\n");
    double celsius = get_double_input("Enter temperature in Celsius: ");
    double fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit. Stay vibin'! 😎\n", celsius, fahrenheit);
    sleep(2);
}

// ===================================================================================


/**
 * @brief Calculates and prints the area and perimeter of a circle.
 * @analog You're planning a circular pizza party! This tells you how much
 * pizza crust you need (perimeter) and how much cheesy goodness is inside (area).
 */
void calculateCircleAreaPerimeter() {
    printf("\n--- Circle Area and Perimeter: Pizza Party Planning! 🍕 ---\n");
    double radius = get_double_input("Enter the radius of your pizza (e.g., 10 for 10 inches): ");
    double area = M_PI * pow(radius, 2); // M_PI is Pi from <math.h>, pow is for power (radius squared)
    double perimeter = 2 * M_PI * radius; // Also known as circumference
    printf("Area of your pizza: %.2lf square units (More cheese!)\n", area);
    printf("Perimeter (crust length): %.2lf units (More crust!)\n", perimeter);
    sleep(2);

}

// ===================================================================================


/**
 * @brief Converts a decimal number to its octal and hexadecimal representations.
 * @analog This is like translating a number into different secret codes.
 * - **Decimal:** How we usually count (base 10).
 * - **Octal:** Base 8 (uses digits 0-7).
 * - **Hexadecimal:** Base 16 (uses 0-9 and A-F). Super common in coding for memory addresses or colors!
 */
void convertDecimalToOctalHex() {
    printf("\n--- Decimal to Octal and Hexadecimal Converter: Secret Codes! 🤫 ---\n");
    int decimalNumber = get_integer_input("Enter a decimal number (e.g., 255): ");
    printf("Octal representation: %o (Base 8, uses 0-7)\n", decimalNumber); // %o for octal
    printf("Hexadecimal representation: %X (Base 16, uses 0-9, A-F)\n", decimalNumber); // %X for uppercase hex
    sleep(2);
}

// ===================================================================================


/**
 * @brief Accepts a number and prints its remainder when divided by 3.
 * @analog You're trying to split your friends into groups of 3 for a game.
 * This tells you how many friends are left over who don't fit into a full group.
 */
void findRemainderByThree() {
    printf("\n--- Remainder by 3: Leftovers from the Squad! 🎮 ---\n");
    int number = get_integer_input("Enter a number (total friends): ");
    int remainder = number % 3; // The '%' is the modulo operator
    printf("Remainder after dividing by 3: %d (That's how many friends are left out! 😔)\n", remainder);
    sleep(2);
}

// ===================================================================================


/**
 * @brief Accepts two numbers and prints their sum or difference using the ternary operator.
 * @analog This is a quick decision-maker: "If the first number is bigger, add them. Else, subtract them."
 * All in one line, no bulky `if-else` block needed!
 */
void sumOrDifferenceTernary() {
    printf("\n--- Sum or Difference (Ternary Operator): Quick Math Decisions! ---\n");
    int num1 = get_integer_input("Enter first number: ");
    int num2 = get_integer_input("Enter second number: ");
    // If num1 > num2 is true, result = num1 + num2. Else, result = num1 - num2.
    int result = (num1 > num2) ? num1 + num2 : num1 - num2;
    printf("Result (if first > second, then sum; else, difference): %d ✨\n", result);
    sleep(2);
}

// ===================================================================================


/**
 * @brief Calculates and prints simple interest.
 * @analog You're trying to figure out how much extra cash you'll get from your savings.
 * You plug in your initial money, the interest rate, and how long it sits, and it tells you the profit.
 */
void calculateSimpleInterest() {
    printf("\n--- Simple Interest Calculator: Stacking That Passive Income! 💸 ---\n");
    double principal = get_double_input("Enter principal amount (your initial money): ");
    double rate = get_double_input("Enter annual interest rate (in percentage, e.g., 5 for 5%%): ");
    double time = get_double_input("Enter time (in years): ");
    double simpleInterest = (principal * rate * time) / 100; // The formula!
    printf("Simple Interest earned: %.2lf (Get that bag! 💰)\n", simpleInterest);
    sleep(2);
}

// ===================================================================================


/**
 * @brief Accepts marks in five subjects and calculates total percentage.
 * @analog You're checking your report card! You input your marks for each subject,
 * and it tells you your overall percentage. Gotta know if you're passing or if it's
 * time to hit the books harder!
 */
void calculateTotalPercentageMarks() {
    printf("\n--- Total Percentage Marks: Report Card Vibe! 💯 ---\n");
    int marks[5]; // Array to hold marks for 5 subjects
    int totalMarks = 0;

    printf("Enter marks in five subjects (0-100, no cap):\n");
    for (int i = 0; i < 5; i++) {
        // Loop to get marks for each subject with validation
        marks[i] = get_integer_input("Subject %d: ", i + 1);
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Marks gotta be between 0 and 100, fam. Re-enter for Subject %d. 🙄\n", i + 1);
            i--; // Decrement 'i' to re-enter marks for the current subject
            continue; // Skip to next loop iteration to re-prompt
        }
        totalMarks += marks[i]; // Add to the grand total
    }

    float percentage = (float)totalMarks / 5; // Calculate percentage (cast to float for decimals!)
    printf("---------------------------------------------\n");
    printf("Your Total Percentage Marks: %.2f%% (How'd you do, fam?)\n", percentage);
    printf("---------------------------------------------\n");
    sleep(2);
}

// ===================================================================================


/**
 * @brief Main function to run various C operator demonstrations and exercises.
 *
 * @analog This is your ultimate C training ground! It's packed with demos
 * showing how different C operators work (like math, logic, and tricky stuff),
 * plus some common beginner programming challenges. Get ready to level up
 * your C game! 🎮✨
 */
int main()
{
    printf("--------------------------------------------------\n");
    printf("Welcome to C Operators & Beginner Exercises: The Vibe Check Edition! 🎮\n");
    printf("--------------------------------------------------\n");
    sleep(1);

    // --- Operator Demonstrations: Let's See How C Does Its Math! ---
    printf("\n\n--- Operator Demonstration Section: Unlocking C's Logic! 🔑 ---\n");
    printf("Get ready for some mind-bending C operator magic. Pay attention!\n");
    sleep(2);

    demonstrate_undefined_behavior_with_increment();
    demonstrate_pre_post_increments();
    demonstrate_logical_operators_comparison();
    demonstrate_complex_arithmetic();
    demonstrate_comparison_logical();
    demonstrate_logical_ternary();
    demonstrate_operator_precedence();
    demonstrate_pre_post_mixed();
    demonstrate_invalid_increment();
    demonstrate_complex_expression_order();
    demonstrate_modulo_division();
    demonstrate_operator_precedence_complex();
    demonstrate_comma_operator();
    demonstrate_char_arithmetic();
    demonstrate_chained_assignment();
    demonstrate_variable_swap();
    demonstrate_ternary_operator();
    demonstrate_logical_assignment_side_effects();

    // --- Beginner Exercises Solutions: Time to Apply What You Learned! ---
    printf("\n\n--------------------------------------------------\n");
    printf("--- Beginner Programming Exercises Solutions: Put Your Skills to the Test! 💪 ---\n");
    printf("--------------------------------------------------\n");
    sleep(2);

    convertCelsiusToFahrenheit();
    calculateCircleAreaPerimeter();
    convertDecimalToOctalHex();
    findRemainderByThree();
    sumOrDifferenceTernary();
    calculateSimpleInterest();
    calculateTotalPercentageMarks();

    printf("\n--------------------------------------------------\n");
    printf("End of Demonstrations and Exercises. You slayed! 🏆\n");
    printf("--------------------------------------------------\n");
    sleep(1);

    return 0; // Indicates successful program execution. Peace out! ✌️
}
