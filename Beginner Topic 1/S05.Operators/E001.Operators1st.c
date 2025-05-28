/**
 * 
 * Alright, my G! You wanna build a calculator that's not just functional but also 
 * 
 * speaks the language of the streets (our streets, that is)? Say less! 
 * 
 * We're gonna take that robotic code and inject some serious personality, 
 * 
 * real-life analogies, and make it beginner-friendly while keeping it clean.
 * 
 * No more goto to functions, my guys! That's like trying to teleport mid-sentence in a convo – super confusing. 
 * 
 * We'll use proper loops and return statements to keep the flow smooth.
 * 
 * Here’s your fully revamped calculator code!

 */

#include <stdio.h>   // Standard Input/Output: This is your program's mic and speaker, gotta have it to talk!
#include <stdlib.h>  // Standard Library: Your general utility belt for random stuff, like converting text to numbers.
#include <stdbool.h> // For 'bool', 'true', 'false': Makes your logic super clear, no more guessing if 0 means false!

/**
 * ---
 * ## The Vibe Check Calculator 🚀
 *
 * Yo, welcome to your first real C project: a calculator!
 * This ain't just about math; it's about making your code clean, readable,
 * and easy to vibe with. We're gonna build functions for each operation,
 * make sure inputs are valid (no crashing our app, fam!), and keep the flow smooth.
 *
 * Remember:
 * - Functions on top (Prototypes): We'll list our function "promises" here so `main` knows what's coming.
 * - `main` function: This is the main stage, where the whole show starts.
 * - **Functions below `main` (Definitions):** This is where each function's detailed recipe lives.
 *
 * Let's get this bread (and calculate it)! 💰
 *
 */

// --- Function Prototypes: The "Promises" to the Compiler ---
// (These tell the compiler, "Hey, these functions are coming later, trust me!")

/**
 * @brief Handles the addition operation.
 *
 * @analog Imagine you're at a party, and you're the designated "snack counter."
 * You keep adding up snacks as people bring them, and then tell everyone the total.
 * You can do this multiple times, but each time, it's a fresh count.
 */
void addition();

/**
 * @brief Handles the subtraction operation.
 *
 * @analog You're managing your daily budget. You start with some cash, and then
 * subtract expenses as they come up.
 */
void subtraction();

/**
 * @brief Handles the multiplication operation.
 *
 * @analog You're baking, and a recipe calls for doubling or tripling ingredients.
 * You take the base amount and multiply it by how many batches you're making.
 */
void multiplication();

/**
 * @brief Handles the division operation.
 *
 * @analog You're splitting pizza slices among your friends. You take the total slices
 * and divide them by the number of friends. Gotta watch out for zero friends though!
 */
void division();

/**
 * @brief Handles the modulus operation.
 *
 * @analog You're counting out cookies for a party, but you only have bags that hold 5 cookies.
 * Modulus tells you how many cookies are *left over* after you fill as many full bags as possible.
 * It's all about the remainder, fam.
 */
void modulus();

/**
 * @brief Clears the input buffer (stdin) after invalid input.
 *
 * @analog Imagine someone tried to shout their order at a drive-thru, but the mic
 * only picks up numbers. This function is like the attendant saying, "Hold up,
 * clear your throat, and speak clearly!" It gets rid of all the extra noise
 * until you hit Enter, so the next input is clean.
 *
 * @param None
 * @return void
 */
void clear_input_buffer();

/**
 * @brief Main function: The Calculator's Command Center.
 *
 * @analog This is your main control panel. It shows you the menu of operations
 * (add, subtract, etc.) and waits for you to pick what you want to do.
 * It's always running, ready for your next command, until you decide to peace out.
 */
int main()
{
    int choice;
    bool running = true; // Our calculator is always on, until we say otherwise

    while (running) // Keep the calculator running until user exits
    {
        printf("\n---------------------------------------------\n");
        printf("What operation do you want to do? Enter your choice (1 to 6):\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit Calculator 🚪\n"); // Added exit option
        printf("---------------------------------------------\n");
        printf("Your choice: ");

        // Input validation for main menu choice
        // scanf("%d", &choice) == 1: Checks if scanf successfully read ONE integer.
        // choice >= 1 && choice <= 6: Checks if the integer is within the valid range.
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 6)
        {
            printf("---------------------------------------------\n");
            printf("Vibe check: Passed! Proceeding with choice %d.\n", choice);
            printf("---------------------------------------------\n");
            clear_input_buffer(); // Clear any leftover newline
        }
        else
        {
            printf("---------------------------------------------\n");
            printf("Invalid input, fam! Please enter a number between 1 and 6. 🤦‍♂️\n");
            printf("---------------------------------------------\n");
            clear_input_buffer(); // Crucial: Clear the bad input from the buffer
            continue; // Skip the rest of this loop and show the menu again
        }

        // Now, let's switch it up based on your choice!
        switch(choice)
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
                printf("\n---------------------------------------------\n");
                printf("Exiting The Gen Z Calculator. Peace out! ✌️\n");
                printf("---------------------------------------------\n");
                running = false; // Set flag to false to exit the main loop
                break;
            default: // This 'default' should ideally not be hit if input validation is solid
                printf("---------------------------------------------\n");
                printf("Something went sideways! Invalid choice. 🤯\n");
                printf("---------------------------------------------\n");
                break;
        }
    }

    return 0; // Main tells the OS: "Mission accomplished, fam! ✅"
}

// --- Function Definitions: The Detailed Recipes ---

void clear_input_buffer() {
    // This loop reads and discards characters from the input buffer
    // until it finds a newline character ('\n') or the end-of-file (EOF).
    // It's like clearing out all the junk someone typed after their actual input.
    while (getchar() != '\n' && getchar() != EOF);
}

void addition()
{
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Welcome to Addition: Let's stack that bread! 🍞➕🍞\n");
    printf("---------------------------------------------\n");

    double num1, num2; // Using double for flexibility with numbers
    char continue_choice;

    do {
        printf("Enter the first number: ");
        if (scanf("%lf", &num1) != 1) { // %lf for double
            printf("---------------------------------------------\n");
            printf("Invalid input! That's not a number, fam. Try again. �\n");
            printf("---------------------------------------------\n");
            clear_input_buffer();
            continue; // Skip to next iteration of do-while loop
        }
        clear_input_buffer(); // Clear newline after number input

        printf("Enter the second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("---------------------------------------------\n");
            printf("Invalid input! That's not a number, fam. Try again. 🚫\n");
            printf("---------------------------------------------\n");
            clear_input_buffer();
            continue; // Skip to next iteration of do-while loop
        }
        clear_input_buffer(); // Clear newline after number input

        double sum = num1 + num2;
        printf("---------------------------------------------\n");
        printf("The sum of %.2lf and %.2lf is: %.2lf ✨\n", num1, num2, sum);
        printf("---------------------------------------------\n");

        printf("Wanna add more? (Y/N): ");
        scanf(" %c", &continue_choice); // Space before %c to consume any leftover whitespace
        clear_input_buffer();

    } while (continue_choice == 'Y' || continue_choice == 'y');

    printf("Alright, back to the main menu. 🔙\n");
}

void subtraction()
{
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Welcome to Subtraction: Let's cut the fat from the budget! 💸\n");
    printf("---------------------------------------------\n");

    double num1, num2;
    char continue_choice;

    do {
        printf("Enter the first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input! Not a number. Try again. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        printf("Enter the second number (to subtract): ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input! Not a number. Try again. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        double difference = num1 - num2;
        printf("---------------------------------------------\n");
        printf("The difference between %.2lf and %.2lf is: %.2lf 📉\n", num1, num2, difference);
        printf("---------------------------------------------\n");

        printf("Wanna subtract more? (Y/N): ");
        scanf(" %c", &continue_choice);
        clear_input_buffer();

    } while (continue_choice == 'Y' || continue_choice == 'y');

    printf("Alright, back to the main menu. 🔙\n");
}

void multiplication()
{
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Welcome to Multiplication: Let's multiply our gains! 📈\n");
    printf("---------------------------------------------\n");

    double num1, num2;
    char continue_choice;

    do {
        printf("Enter the first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input! Not a number. Try again. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        printf("Enter the second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input! Not a number. Try again. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        double product = num1 * num2;
        printf("---------------------------------------------\n");
        printf("The product of %.2lf and %.2lf is: %.2lf 🚀\n", num1, num2, product);
        printf("---------------------------------------------\n");

        printf("Wanna multiply more? (Y/N): ");
        scanf(" %c", &continue_choice);
        clear_input_buffer();

    } while (continue_choice == 'Y' || continue_choice == 'y');

    printf("Alright, back to the main menu. 🔙\n");
}

void division()
{
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Welcome to Division: Let's share those pizza slices! 🍕➗\n");
    printf("---------------------------------------------\n");

    double num1, num2;
    char continue_choice;

    do {
        printf("Enter the dividend (total slices): ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input! Not a number. Try again. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        printf("Enter the divisor (number of friends): ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input! Not a number. Try again. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (num2 == 0) {
            printf("---------------------------------------------\n");
            printf("ERROR: Can't divide by zero, fam! That's a black hole. ⚫️\n");
            printf("---------------------------------------------\n");
        } else {
            double quotient = num1 / num2;
            printf("---------------------------------------------\n");
            printf("%.2lf divided by %.2lf is: %.2lf \n", num1, num2, quotient);
            printf("Each friend gets %.2lf slices. 😋\n", quotient);
            printf("---------------------------------------------\n");
        }

        printf("Wanna divide more? (Y/N): ");
        scanf(" %c", &continue_choice);
        clear_input_buffer();

    } while (continue_choice == 'Y' || continue_choice == 'y');

    printf("Alright, back to the main menu. 🔙\n");
}

void modulus()
{
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Welcome to Modulus: What's left over after the party? 🎉\n");
    printf("---------------------------------------------\n");

    int num1, num2; // Modulus typically works with integers
    char continue_choice;

    do {
        printf("Enter the first integer (total cookies): ");
        if (scanf("%d", &num1) != 1) {
            printf("Invalid input! Please enter a whole number. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        printf("Enter the second integer (cookies per bag): ");
        if (scanf("%d", &num2) != 1) {
            printf("Invalid input! Please enter a whole number. 🚫\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        if (num2 == 0) {
            printf("---------------------------------------------\n");
            printf("ERROR: Can't divide by zero for modulus, fam! 🤯\n");
            printf("---------------------------------------------\n");
        } else {
            int remainder = num1 % num2;
            printf("---------------------------------------------\n");
            printf("If you put %d cookies into bags of %d, you'll have %d cookies LEFT OVER. 🍪\n", num1, num2, remainder);
            printf("---------------------------------------------\n");
        }

        printf("Wanna do more modulus? (Y/N): ");
        scanf(" %c", &continue_choice);
        clear_input_buffer();

    } while (continue_choice == 'Y' || continue_choice == 'y');

    printf("Alright, back to the main menu. 🔙\n");
}
�