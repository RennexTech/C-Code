#include <stdio.h>   // Standard input/output functions (printf, scanf, getchar)
#include <math.h>    // For math functions like pow, sqrt
#include <stdlib.h>  // For exit() function

// --- Function Prototypes ---
// Declare all functions before main so the compiler knows about them.
void clear_input_buffer();
double get_double_input(const char* prompt);
int get_integer_input(const char* prompt);
void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void factorial();
void power();
void square();
void cube();
void squareroot();

/**
 * @brief Clears the standard input buffer.
 *
 * Reads and discards characters from stdin until a newline or EOF.
 * This is crucial after using scanf to prevent leftover characters
 * (like the newline from pressing Enter) from affecting subsequent input calls.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Prompts for and reads a double value from the user.
 * @param prompt Message to display to the user.
 * @return The valid double value entered by the user.
 */
double get_double_input(const char* prompt) {
    double value;
    printf("%s", prompt);
    // Loop until scanf successfully reads one double.
    while (scanf("%lf", &value) != 1) {
        printf("Invalid input. Please enter a number: ");
        clear_input_buffer(); // Clear invalid input from buffer
    }
    clear_input_buffer(); // Clear leftover newline
    return value;
}

/**
 * @brief Prompts for and reads an integer value from the user.
 * @param prompt Message to display to the user.
 * @return The valid integer value entered by the user.
 */
int get_integer_input(const char* prompt) {
    int value;
    printf("%s", prompt);
    // Loop until scanf successfully reads one integer.
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        clear_input_buffer(); // Clear invalid input from buffer
    }
    clear_input_buffer(); // Clear leftover newline
    return value;
}

/**
 * @brief Performs addition of two numbers.
 */
void addition() {
    printf("\n--- ADDITION ---\n");
    double num1 = get_double_input("Enter first number: ");
    double num2 = get_double_input("Enter second number: ");
    printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
}

/**
 * @brief Performs subtraction of two numbers.
 */
void subtraction() {
    printf("\n--- SUBTRACTION ---\n");
    double num1 = get_double_input("Enter first number: ");
    double num2 = get_double_input("Enter second number: ");
    printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
}

/**
 * @brief Performs multiplication of two numbers.
 */
void multiplication() {
    printf("\n--- MULTIPLICATION ---\n");
    double num1 = get_double_input("Enter first number: ");
    double num2 = get_double_input("Enter second number: ");
    printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
}

/**
 * @brief Performs division of two numbers, handles division by zero.
 */
void division() {
    printf("\n--- DIVISION ---\n");
    double num1 = get_double_input("Enter numerator: ");
    double num2 = get_double_input("Enter denominator: ");
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
    }
}

/**
 * @brief Performs modulus operation on two integers, handles modulus by zero.
 */
void modulus() {
    printf("\n--- MODULUS ---\n");
    int num1 = get_integer_input("Enter first integer: ");
    int num2 = get_integer_input("Enter second integer (divisor): ");
    if (num2 == 0) {
        printf("Error: Modulus by zero is not allowed.\n");
    } else {
        printf("Result: %d %% %d = %d\n", num1, num2, num1 % num2);
    }
}

/**
 * @brief Calculates the factorial of a non-negative integer.
 */
void factorial() {
    printf("\n--- FACTORIAL ---\n");
    int n = get_integer_input("Enter a non-negative integer: ");
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return;
    }
    long long result = 1; // Use long long for larger factorials
    for (int i = 1; i <= n; i++) {
        result *= i;  // result = result * i;
    }
    printf("Factorial of %d is %lld\n", n, result);
}

/**
 * @brief Calculates the power of a base number raised to an exponent.
 */
void power() {
    printf("\n--- POWER ---\n");
    double base = get_double_input("Enter the base number: ");
    double exponent = get_double_input("Enter the exponent: ");
    double result = pow(base, exponent);
    printf("Result: %.2lf ^ %.2lf = %.2lf\n", base, exponent, result);
}

/**
 * @brief Calculates the square of a number.
 */
void square() {
    printf("\n--- SQUARE ---\n");
    double num = get_double_input("Enter a number: ");
    double result = pow(num, 2);
    printf("Square of %.2lf is %.2lf\n", num, result);
}

/**
 * @brief Calculates the cube of a number.
 */
void cube() {
    printf("\n--- CUBE ---\n");
    double num = get_double_input("Enter a number: ");
    double result = pow(num, 3);
    printf("Cube of %.2lf is %.2lf\n", num, result);
}

/**
 * @brief Calculates the square root of a non-negative number.
 */
void squareroot() {
    printf("\n--- SQUARE ROOT ---\n");
    double num = get_double_input("Enter a non-negative number: ");
    if (num < 0) {
        printf("Error: Square root of a negative number is not real.\n");
    } else {
        double result = sqrt(num);
        printf("Square root of %.2lf is %.2lf\n", num, result);
    }
}

/**
 * @brief Main function for the console-based calculator.
 *
 * Displays a menu of operations and continuously prompts the user
 * for a choice until '0' is entered to quit.
 */
int main() {
    int choice;

    printf("\n\n--------------------------------------------------------------------------------\n");
    printf("                                C CONSOLE CALCULATOR\n");
    printf("--------------------------------------------------------------------------------\n");

    do {
        printf("\n--- MENU ---\n");
        printf("Enter '0' to QUIT\n");
        printf("1. ADDITION (+)\n");
        printf("2. SUBTRACTION (-)\n");
        printf("3. MULTIPLICATION (*)\n");
        printf("4. DIVISION (/)\n");
        printf("5. MODULUS (%%)\n");
        printf("6. POWER (^)\n");
        printf("7. FACTORIAL (!)\n");
        printf("8. SQUARE\n");
        printf("9. CUBE\n");
        printf("10. SQUARE ROOT\n");
        printf("--------------------------------------------------------------------------------\n");

        choice = get_integer_input("Enter the operation you want to do: ");

        printf("--------------------------------------------------------------------------------\n");
        switch (choice) {
            case 1: addition(); break;
            case 2: subtraction(); break;
            case 3: multiplication(); break;
            case 4: division(); break;
            case 5: modulus(); break;
            case 6: power(); break;
            case 7: factorial(); break;
            case 8: square(); break;
            case 9: cube(); break;
            case 10: squareroot(); break;
            case 0:
                printf("Exiting calculator. Goodbye!\n");
                exit(0); // Exit the program
            default:
                printf("Invalid operation. Please enter a number from 0 to 10.\n");
                break;
        }
        printf("--------------------------------------------------------------------------------\n");
    } while (choice != 0); // Loop until user chooses to quit

    return 0; // Program should exit via exit(0) for choice 0
}
