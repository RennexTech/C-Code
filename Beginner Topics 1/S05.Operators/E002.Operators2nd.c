#include <stdio.h>   // Standard Input/Output: This is your program's mic and speaker, gotta have it to talk!
#include <stdlib.h>  // Standard Library: Your general utility belt for random stuff, like converting text to numbers.

// --- Function Prototypes: The "Promises" to the Compiler ---
// (These tell the compiler, "Hey, these functions are coming later, trust me! It's like a sneak peek for the compiler, fam.")
void clear_input_buffer();
int get_integer_input(const char* prompt);
double get_double_input(const char* prompt);
void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void display_main_menu();

/**
 * @brief Clears the standard input buffer.
 *
 * @analog Imagine someone tried to shout their order at a drive-thru, but the mic
 * only picks up numbers. This function is like the attendant saying, "Hold up,
 * clear your throat, and speak clearly!" It gets rid of all the extra noise
 * until you hit Enter, so the next input is clean and doesn't mess up your next move.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Prompts the user for an integer input and validates it.
 * @param prompt The message to display to the user.
 * @return The valid integer entered by the user.
 *
 * @analog This is like a bouncer for your input. It won't let anything through
 * unless it's a legit whole number. If you try to sneak in text, it's like, "Nah, fam,
 * that's not gonna fly. Try again!" It keeps asking until you give it what it wants.
 */
int get_integer_input(const char* prompt) {
    int num;
    while (1) { // Loop until valid input is received, no cap.
        printf("%s", prompt);
        if (scanf("%d", &num) == 1) { // Checks if scanf successfully read ONE integer.
            clear_input_buffer(); // Clear any remaining characters in the buffer, keep it clean.
            return num;           // Return the valid integer, mission accomplished.
        } else {
            printf("Invalid input! Please enter a valid integer. No cap. 🚫\n");
            clear_input_buffer(); // Clear the invalid input from the buffer, don't let it mess up next time.
        }
    }
}

/**
 * @brief Prompts the user for a double input and validates it.
 * @param prompt The message to display to the user.
 * @return The valid double entered by the user.
 *
 * @analog This is the bouncer for your decimal numbers. It's chill with numbers
 * like 3.14 or 99.99. Anything else? "Nah, that's not a number, try again."
 * Keeps the vibes right for floating-point calculations.
 */
double get_double_input(const char* prompt) {
    double num;
    while (1) { // Loop until valid input is received, we're persistent.
        printf("%s", prompt);
        if (scanf("%lf", &num) == 1) { // Checks if scanf successfully read a double.
            clear_input_buffer(); // Clear any remaining characters in the buffer.
            return num;           // Return the valid double.
        } else {
            printf("Invalid input! Please enter a valid number. Fr fr. 🚫\n");
            clear_input_buffer(); // Clear the invalid input from the buffer.
        }
    }
}

/**
 * @brief Performs addition of multiple numbers.
 *
 * @analog Imagine you're stacking up your wins. You can add a bunch of wins,
 * see your current total, and then decide if you wanna keep adding to that streak
 * or start a fresh winning streak. It's all about accumulating those W's!
 */
void addition() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Addition: Let's stack that bread! 🍞➕🍞\n");
    printf("---------------------------------------------\n");

    double current_session_sum = 0.0;     // Sum for the current set of numbers you're adding
    double total_cumulative_sum = 0.0;    // The grand total across all your addition sessions
    int num_inputs_per_session;
    int choice_continue_session; // 1 for Yes, 2 for No
    int choice_reset_sum;        // 1 for Continue, 2 for New

    do {
        // Prompt for how many numbers to add in this session
        num_inputs_per_session = get_integer_input("How many numbers do you wanna add in this session? (Gotta be positive, fam): ");
        if (num_inputs_per_session <= 0) {
            printf("Nah, you gotta add at least one number. Try again. 🙄\n");
            continue; // Ask again, don't play games.
        }

        current_session_sum = 0.0; // Reset for the current session's sum, fresh start!

        printf("Drop %d numbers, one by one:\n", num_inputs_per_session);
        for (int i = 0; i < num_inputs_per_session; i++) {
            double num_val = get_double_input("Number: ");
            current_session_sum += num_val; // Stack 'em up!
        }

        total_cumulative_sum += current_session_sum; // Add current session's sum to the overall total

        printf("---------------------------------------------\n");
        printf("Current session's sum: %.2lf ✨\n", current_session_sum);
        printf("Your grand total so far: %.2lf 💰\n", total_cumulative_sum);
        printf("---------------------------------------------\n");

        // Ask to continue adding in this session
        printf("\nWanna add more numbers in this session?\n");
        printf("1. Yes, let's keep going!\n");
        printf("2. Nah, I'm good for now.\n");
        choice_continue_session = get_integer_input("Enter choice (1 or 2): ");

        if (choice_continue_session == 1) {
            // Ask if they want to continue from the last result or start a new addition
            printf("\nAlright, you wanna keep building on %.2lf or start a whole new session?\n", total_cumulative_sum);
            printf("1. Keep adding to the current total.\n");
            printf("2. New game, who dis? Reset total.\n");
            choice_reset_sum = get_integer_input("Enter choice (1 or 2): ");
            if (choice_reset_sum == 2) {
                total_cumulative_sum = 0.0; // Reset total sum if starting new, fresh start!
                printf("Total sum has been reset. New beginnings! ✨\n");
            } else if (choice_reset_sum != 1) {
                printf("Invalid choice. We'll just keep adding to the last total. Don't play yourself. 🙄\n");
            }
        } else if (choice_continue_session != 2) {
            printf("Invalid choice. We're heading back to the main menu. No cap. 🤷‍♀️\n");
            choice_continue_session = 2; // Force exit if invalid input, keep it moving.
        }

    } while (choice_continue_session == 1);

    printf("---------------------------------------------\n");
    printf("Exiting Addition. Back to the main menu. 🔙\n");
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs subtraction of two numbers.
 * @analog You're managing your daily budget. You start with some cash, and then
 * subtract expenses as they come up. This function helps you see how much you have left.
 */
void subtraction() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Subtraction: Let's cut the fat from the budget! 💸\n");
    printf("---------------------------------------------\n");
    double num1 = get_double_input("Enter your starting amount: ");
    double num2 = get_double_input("Enter the amount to subtract: ");
    printf("---------------------------------------------\n");
    printf("Result: %.2lf - %.2lf = %.2lf 📉\n", num1, num2, num1 - num2);
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs multiplication of two numbers.
 * @analog You're baking, and a recipe calls for doubling or tripling ingredients.
 * You take the base amount and multiply it by how many batches you're making.
 * This function helps you scale up!
 */
void multiplication() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Multiplication: Let's multiply our gains! 📈\n");
    printf("---------------------------------------------\n");
    double num1 = get_double_input("Enter the first number: ");
    double num2 = get_double_input("Enter the second number: ");
    printf("---------------------------------------------\n");
    printf("Result: %.2lf * %.2lf = %.2lf 🚀\n", num1, num2, num1 * num2);
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs division of two numbers, handling division by zero.
 * @analog You're splitting pizza slices among your friends. You take the total slices
 * and divide them by the number of friends. Gotta watch out for zero friends though,
 * that's a whole black hole situation!
 */
void division() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Division: Let's share those pizza slices! 🍕➗\n");
    printf("---------------------------------------------\n");
    double num1 = get_double_input("Enter the numerator (total slices): ");
    double num2 = get_double_input("Enter the denominator (number of friends): ");
    printf("---------------------------------------------\n");
    if (num2 == 0) {
        printf("ERROR: Can't divide by zero, fam! That's a black hole. ⚫️\n");
    } else {
        printf("Result: %.2lf / %.2lf = %.2lf \n", num1, num2, num1 / num2);
        printf("Each friend gets %.2lf slices. Yum! 😋\n", num1 / num2);
    }
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs modulus operation on two integers.
 *
 * @analog You're counting out cookies for a party, but you only have bags that hold 5 cookies.
 * Modulus tells you how many cookies are *left over* after you fill as many full bags as possible.
 * It's all about the remainder, fam. No partial cookies in the bags!
 * Note: Modulus operator (%) only works with whole numbers (integers).
 */
void modulus() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Modulus: What's left over after the party? 🎉\n");
    printf("---------------------------------------------\n");
    int num1 = get_integer_input("Enter the first integer (total cookies): ");
    int num2 = get_integer_input("Enter the second integer (cookies per bag): ");
    printf("---------------------------------------------\n");
    if (num2 == 0) {
        printf("ERROR: Can't do modulus by zero, fam! That's a no-go. 🤯\n");
    } else {
        printf("If you put %d cookies into bags of %d, you'll have %d cookies LEFT OVER. 🍪\n", num1, num2, num1 % num2);
    }
    printf("---------------------------------------------\n");
}

/**
 * @brief Displays the main calculator menu options.
 * @analog This is your calculator's main dashboard. It's got all the options
 * laid out, so you can easily pick your next move. Clean UI, no clutter.
 */
void display_main_menu() {
    printf("\n+---------------------------------------+\n");
    printf("|          C Console Calculator         |\n");
    printf("+---------------------------------------+\n");
    printf("| 1. Addition                           |\n");
    printf("| 2. Subtraction                        |\n");
    printf("| 3. Multiplication                     |\n");
    printf("| 4. Division                           |\n");
    printf("| 5. Modulus                            |\n");
    printf("| 6. Exit                               |\n");
    printf("+---------------------------------------+\n");
}

/**
 * @brief Main function to run the C calculator.
 *
 * @analog This is the ultimate command center. It keeps the calculator running,
 * showing you the menu and waiting for your choice. It's always on standby,
 * ready to perform calculations, until you decide to clock out and exit.
 */
int main() {
    int choice;

    do {
        display_main_menu(); // Show the menu, keep it fresh
        choice = get_integer_input("Enter your choice (1-6): "); // Get user's choice, validate that input!

        switch (choice) {
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
                printf("Thank you for using The Gen Z Calculator. Peace out! ✌️\n");
                printf("---------------------------------------------\n");
                break; // Exit the do-while loop
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 6. Don't play yourself. 🙄\n");
                break;
        }
    } while (choice != 6); // Continue looping until the user chooses to exit, no cap.

    return 0; // Indicate successful program termination: Main tells the OS 'Mission accomplished! ✅'
}
