#include <stdio.h>   // For printf, scanf, getchar - our program's mic and ear.
#include <stdlib.h>  // For exit() - if we need to bail out gracefully.
#include <math.h>    // For fmod() - because sometimes you need decimal remainders.
#include <stdbool.h> // For bool, true, false - keeping our logic clean and readable.
#include <unistd.h>  // For sleep() - to chill between outputs, keep the flow smooth.

/**
 * @brief ♾️ The Infinite Vibe Calculator: C Edition
 *
 * @analog Imagine your program is a super chill DJ, and this calculator is its
 * infinite set. You pick a vibe (operation), drop some numbers, and the DJ
 * (your program) keeps the party going, letting you use the last result as the
 * starting point for the next calculation. It's an endless math jam session!
 *
 * This calculator will show you:
 * - **Unary vs. Binary Operators:** What's the difference between a solo act and a duo?
 * - **Basic Arithmetic:** Addition, subtraction, multiplication, division.
 * - **Modulo Magic:** Finding remainders for whole numbers.
 * - **Floating-Point Modulo:** Yes, you *can* find remainders with decimals!
 * - **Robust Input:** No crashing our party with bad input, fam!
 *
 * Let's get this math party started! 🚀
 */

// --- Function Prototypes: The "Promises" to the Compiler ---
// (These tell the compiler, "Hey, these functions are coming later, trust me! It's like a sneak peek for the compiler, fam.")
void clear_input_buffer();
double get_double_input(const char* prompt);
int get_integer_input(const char* prompt);

// --- Calculator Operation Functions ---
void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void floating_point_modulus();

// --- Global Variable for Infinite Calculation ---
// @analog: This is like the DJ's current track. It holds the last result,
// ready to be mixed into the next song. It starts at 0.0 for a fresh start.
double last_result = 0.0;

/**
 * @brief Clears the standard input buffer.
 *
 * @analog Flushes the toilet after use to keep things clean for the next input.
 * Essential after `scanf` to prevent leftover characters (like the newline
 * from pressing Enter) from messing up next inputs. No cap.
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
 * @analog This is the bouncer for your decimal numbers. It's chill with numbers
 * like 3.14 or 99.99. Anything else? "Nah, that's not a number, try again."
 * Keeps the vibes right for floating-point calculations.
 */
double get_double_input(const char* prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1) { // %lf for double
        printf("Invalid input! Please enter a number. Fr fr. 🚫\n");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

/**
 * @brief Prompts for and reads an integer value from the user.
 * @param prompt The message to display to the user.
 * @return The valid integer entered by the user.
 *
 * @analog This is like a bouncer for your input. It won't let anything through
 * unless it's a legit whole number. If you try to sneak in text, it's like, "Nah, fam,
 * that's not gonna fly. Try again!" It keeps asking until you give it what it wants.
 */
int get_integer_input(const char* prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) { // %d for integer
        printf("Invalid input! Please enter an integer. No cap. 🚫\n");
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

/**
 * @brief Main function: The Calculator's Command Center.
 *
 * @analog This is your main control panel. It shows you the menu of operations
 * (add, subtract, etc.) and waits for you to pick what you want to do.
 * It's always running, ready for your next command, until you decide to peace out.
 *
 * @note In C, there can only be ONE `main` function, and it should always return `int`.
 * If you see `double main()`, that's a red flag! The compiler will only pick one,
 * and the other one will be ignored, leading to unpredictable vibes. Keep it `int main()`.
 */
int main()
{
    int main_choice;
    bool running = true; // Our calculator is always on, until we say otherwise

    printf("---------------------------------------------\n");
    printf("WELCOME TO THE INFINITE VIBE CALCULATOR! ♾️\n");
    printf("---------------------------------------------\n");
    printf("Your last result is always ready to be the first number in your next calculation!\n");
    printf("Current Vibe (Last Result): %.2lf\n", last_result);
    sleep(2);

    // --- Unary vs. Binary Operators: The Solo vs. Duo Act ---
    printf("\n--- Unary vs. Binary Operators: The Solo vs. Duo Act 🎤 ---\n");
    printf("    @analog: Think of operators as performers.\n");
    printf("    - **Unary Operators:** Solo artists! They operate on ONE operand.\n");
    printf("      Example: `-x` (unary minus, flips the sign of x). It's like a DJ flipping a track to reverse it.\n");
    printf("    - **Binary Operators:** Dynamic Duos! They operate on TWO operands.\n");
    printf("      Example: `x + y` (addition), `a * b` (multiplication). It's like two DJs mixing beats.\n");
    int x = 10;
    int y = 5;
    printf("    Unary minus: -%d is %d\n", x, -x);
    printf("    Binary addition: %d + %d is %d\n", x, y, x + y);
    printf("    Operand: The data you're working on (e.g., 2, 3, or 'x', 'y').\n");
    sleep(2);

    while (running) // Keep the calculator running until user exits
    {
        printf("\n---------------------------------------------\n");
        printf("Current Vibe (Last Result): %.2lf\n", last_result);
        printf("What math vibe do you wanna drop? (1-7):\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%) - Whole Numbers Only!\n");
        printf("6. Decimal Modulus (fmod) - For Floats/Doubles!\n");
        printf("7. Exit Calculator 🚪\n"); // Added exit option
        printf("---------------------------------------------\n");
        printf("Your choice: ");

        main_choice = get_integer_input(""); // Use our robust input function

        // Now, let's switch it up based on your choice!
        switch(main_choice)
        {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                modulus();
                break;
            case 6:
                floating_point_modulus();
                break;
            case 7:
                printf("\n---------------------------------------------\n");
                printf("Exiting The Infinite Vibe Calculator. Peace out! ✌️\n");
                printf("---------------------------------------------\n");
                running = false; // Set flag to false to exit the main loop
                break;
            default: // This default catches numbers outside 1-7
                printf("---------------------------------------------\n");
                printf("Invalid choice, fam! Pick a number between 1 and 7. 🤯\n");
                printf("---------------------------------------------\n");
                break;
        }
    }

    return 0; // Main tells the OS: "Mission accomplished, fam! ✅"
}

// --- Function Definitions: The Detailed Recipes ---

/**
 * @brief Performs addition.
 *
 * @analog You're stacking up your wins! You take the last result (or 0),
 * add a new number, and see your new total. Keep stacking!
 */
void addition()
{
    printf("\n---------------------------------------------\n");
    printf("Addition: Let's stack that bread! 🍞➕🍞\n");
    printf("---------------------------------------------\n");
    double num_to_add = get_double_input("Enter the number to add: ");
    last_result += num_to_add; // Add to the global last_result
    printf("New Vibe (Result): %.2lf ✨\n", last_result);
}

/**
 * @brief Performs subtraction.
 *
 * @analog You're managing your daily budget. You start with your current balance
 * (last result) and subtract an expense. See what's left!
 */
void subtraction()
{
    printf("\n---------------------------------------------\n");
    printf("Subtraction: Let's cut the fat from the budget! 💸\n");
    printf("---------------------------------------------\n");
    double num_to_subtract = get_double_input("Enter the number to subtract: ");
    last_result -= num_to_subtract; // Subtract from the global last_result
    printf("New Vibe (Result): %.2lf 📉\n", last_result);
}

/**
 * @brief Performs multiplication.
 *
 * @analog You're trying to multiply your gains! Take your current amount
 * (last result) and multiply it by a factor. Watch it grow!
 */
void multiplication()
{
    printf("\n---------------------------------------------\n");
    printf("Multiplication: Let's multiply our gains! 📈\n");
    printf("---------------------------------------------\n");
    double num_to_multiply = get_double_input("Enter the number to multiply by: ");
    last_result *= num_to_multiply; // Multiply the global last_result
    printf("New Vibe (Result): %.2lf 🚀\n", last_result);
}

/**
 * @brief Performs division.
 *
 * @analog You're sharing your pizza slices! Take your current slices
 * (last result) and divide them among friends. But no dividing by zero, fam!
 */
void division()
{
    printf("\n---------------------------------------------\n");
    printf("Division: Let's share those pizza slices! 🍕➗\n");
    printf("---------------------------------------------\n");
    double divisor = get_double_input("Enter the divisor (number of friends): ");
    if (divisor == 0) {
        printf("ERROR: Can't divide by zero, fam! That's a black hole. ⚫️\n");
    } else {
        last_result /= divisor; // Divide the global last_result
        printf("New Vibe (Result): %.2lf \n", last_result);
        printf("Each share is %.2lf. Yum! 😋\n", last_result);
    }
}

/**
 * @brief Performs modulus operation on integers.
 *
 * @analog You're counting out cookies for a party, but you only have bags that hold 5 cookies.
 * Modulus tells you how many cookies are *left over* after you fill as many full bags as possible.
 * It's all about the remainder, fam. No partial cookies in the bags!
 * @note Modulus operator (%) only works with whole numbers (integers).
 */
void modulus()
{
    printf("\n---------------------------------------------\n");
    printf("Modulus: What's left over after the party? 🎉 (Whole Numbers Only!)\n");
    printf("---------------------------------------------\n");
    // For modulus, we need integers. Convert last_result to int for this.
    int dividend = (int)last_result;
    int divisor = get_integer_input("Enter the divisor (cookies per bag): ");

    if (divisor == 0) {
        printf("ERROR: Can't do modulus by zero, fam! That's a no-go. 🤯\n");
    } else {
        int remainder = dividend % divisor;
        printf("If you put %d cookies into bags of %d, you'll have %d cookies LEFT OVER. 🍪\n", dividend, divisor, remainder);
        last_result = (double)remainder; // Update last_result with the remainder
        printf("New Vibe (Result): %.2lf\n", last_result);
    }
}

/**
 * @brief Performs floating-point modulus using fmod().
 *
 * @analog This is like finding the leftover change after paying with decimals.
 * You can get a decimal remainder! Super useful for things like wrapping angles
 * or timing in games.
 * @note Requires `<math.h>` for `fmod()`.
 */
void floating_point_modulus()
{
    printf("\n---------------------------------------------\n");
    printf("Decimal Modulus: Finding Leftover Change! 💰 (For Floats/Doubles!)\n");
    printf("---------------------------------------------\n");
    printf("We're checking for remainder after division with decimals. If the result is 0.0, that's the remainder.\n");
    double divisor = get_double_input("Enter the divisor (decimal number): ");

    if (divisor == 0.0) {
        printf("ERROR: Can't do decimal modulus by zero, fam! 🤯\n");
    } else {
        double remainder = fmod(last_result, divisor); // fmod for floating-point remainder
        printf("The remainder of %.2lf divided by %.2lf is: %.2lf\n", last_result, divisor, remainder);
        last_result = remainder; // Update last_result with the remainder
        printf("New Vibe (Result): %.2lf\n", last_result);
    }
}
