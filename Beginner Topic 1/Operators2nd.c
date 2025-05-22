//The revamped version for the first version with Doxygen-style Comments.

#include <stdio.h>  // Standard input/output library for printf, scanf, getchar, etc.
#include <stdlib.h> // Standard library for general utilities (e.g., exit, though not used here)

// --- Function Prototypes ---
// Declare functions before main so the compiler knows about them.
// This allows main to call them even if their full definition is below main.
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
 * This function reads and discards characters from stdin until a newline character
 * or EOF is encountered. Essential after using scanf to prevent leftover characters
 * (like the newline from pressing Enter) from affecting subsequent input calls.
 */

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Prompts the user for an integer input and validates it.
 * @param prompt The message to display to the user.
 * @return The valid integer entered by the user.
 */

int get_integer_input(const char* prompt) {
    int num;
    while (1) { // Loop until valid input is received
        printf("%s", prompt);
        if (scanf("%d", &num) == 1) { // Check if scanf successfully read an integer
            clear_input_buffer(); // Clear any remaining characters in the buffer
            return num;           // Return the valid integer
        } else {
            printf("Invalid input! Please enter a valid integer.\n");
            clear_input_buffer(); // Clear the invalid input from the buffer
        }
    }
}

/**
 * @brief Prompts the user for a double input and validates it.
 * @param prompt The message to display to the user.
 * @return The valid double entered by the user.
 */

double get_double_input(const char* prompt) {
    double num;
    while (1) { // Loop until valid input is received
        printf("%s", prompt);
        if (scanf("%lf", &num) == 1) { // Check if scanf successfully read a double
            clear_input_buffer(); // Clear any remaining characters in the buffer
            return num;           // Return the valid double
        } else {
            printf("Invalid input! Please enter a valid number.\n");
            clear_input_buffer(); // Clear the invalid input from the buffer
        }
    }
}

/**
 * @brief Performs addition of multiple numbers.
 *
 * Allows the user to add a specified number of inputs, with an option
 * to continue adding to the current total or start a new sum.
 */

void addition() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Addition.\n");
    printf("---------------------------------------------\n");

    double current_sum = 0.0; // Sum for the current set of numbers
    double total_cumulative_sum = 0.0; // Sum across multiple addition sessions
    int num_inputs;
    int choice_continue_session; // 1 for Yes, 2 for No
    int choice_reset_sum;        // 1 for Continue, 2 for New

    do {
        // Prompt for how many numbers to add in this session
        num_inputs = get_integer_input("How many numbers do you want to add in this session? ");
        if (num_inputs <= 0) {
            printf("Please enter a positive number of inputs.\n");
            continue; // Ask again
        }

        current_sum = 0.0; // Reset for the current session's sum

        printf("Enter %d numbers:\n", num_inputs);
        for (int i = 0; i < num_inputs; i++) {
            double num_val = get_double_input("Number: ");
            current_sum += num_val;
        }

        total_cumulative_sum += current_sum; // Add current session's sum to overall total

        printf("Current session sum: %.2lf\n", current_sum);
        printf("Total cumulative sum: %.2lf\n", total_cumulative_sum);

        // Ask to continue adding in this session
        printf("\nDo you want to add more numbers in this session?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        choice_continue_session = get_integer_input("Enter choice (1 or 2): ");

        if (choice_continue_session == 1) {
            // Ask if they want to continue from the last result or start a new addition
            printf("\nDo you want to continue from the last total or start a new addition?\n");
            printf("1. Continue from last total (%.2lf)\n", total_cumulative_sum);
            printf("2. Start a new addition (reset total)\n");
            choice_reset_sum = get_integer_input("Enter choice (1 or 2): ");
            if (choice_reset_sum == 2) {
                total_cumulative_sum = 0.0; // Reset total sum if starting new
                printf("Total sum has been reset.\n");
            }
        } else if (choice_continue_session != 2) {
            printf("Invalid choice. Exiting addition session.\n");
            choice_continue_session = 2; // Force exit if invalid
        }

    } while (choice_continue_session == 1);

    printf("---------------------------------------------\n");
    printf("Exiting Addition.\n");
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs subtraction of two numbers.
 */

void subtraction() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Subtraction.\n");
    printf("---------------------------------------------\n");
    double num1 = get_double_input("Enter the first number: ");
    double num2 = get_double_input("Enter the second number: ");
    printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs multiplication of two numbers.
 */

void multiplication() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Multiplication.\n");
    printf("---------------------------------------------\n");
    double num1 = get_double_input("Enter the first number: ");
    double num2 = get_double_input("Enter the second number: ");
    printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs division of two numbers, handling division by zero.
 */

void division() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Division.\n");
    printf("---------------------------------------------\n");
    double num1 = get_double_input("Enter the numerator: ");
    double num2 = get_double_input("Enter the denominator: ");
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
    }
    printf("---------------------------------------------\n");
}

/**
 * @brief Performs modulus operation on two integers.
 *
 * Note: Modulus operator (%) only works with integer types.
 */

void modulus() {
    printf("\n---------------------------------------------\n");
    printf("Welcome to Modulus.\n");
    printf("---------------------------------------------\n");
    int num1 = get_integer_input("Enter the first integer (dividend): ");
    int num2 = get_integer_input("Enter the second integer (divisor): ");
    if (num2 == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
    } else {
        printf("Result: %d %% %d = %d\n", num1, num2, num1 % num2);
    }
    printf("---------------------------------------------\n");
}

/**
 * @brief Displays the main calculator menu options.
 */

void display_main_menu() {
    printf("\n+---------------------------------------+\n");
    printf("|          C Console Calculator         |\n");
    printf("+---------------------------------------+\n");
    printf("| 1. Addition                           |\n");
    printf("| 2. Subtraction                        |\n");
    printf("| 3. Multiplication                     |\n");
    printf("| 4. Division                           |\n");
    printf("| 5. Modulus                            |\n");
    printf("| 6. Exit                               |\n");
    printf("+---------------------------------------+\n");
}

/**
 * @brief Main function to run the C calculator.
 *
 * Presents a menu of arithmetic operations and calls the respective functions
 * based on user choice, allowing multiple operations until the user exits.
 */

int main() {
    int choice;

    do {
        display_main_menu(); // Show the menu
        choice = get_integer_input("Enter your choice (1-6): "); // Get user's choice

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
                printf("Thank you for using the calculator. Goodbye!\n");
                printf("---------------------------------------------\n");
                break; // Exit the do-while loop
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 6.\n");
                break;
        }
    } while (choice != 6); // Continue looping until the user chooses to exit

    return 0; // Indicate successful program termination
}
