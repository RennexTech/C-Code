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

// Let's break this down in depth 

//🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢

#include <stdio.h> // Our trusty toolkit for printf (output) and scanf (input).
#include <limits.h> // Potentially useful for limits, though not directly used in the clear_input_buffer here, it's good to know.

// Forward declaration for clear_input_buffer.
// It's like telling the compiler, "Hey, there's a function named 'clear_input_buffer' coming later. Don't worry about it for now, just trust me."
void clear_input_buffer(); 

/**
 * @brief Prompts for and reads a double value from the user, ensuring valid numeric input.
 *
 * This function acts like a vigilant gatekeeper for your program's data. It will tirelessly
 * ask the user for a number until it gets one that truly makes sense as a floating-point value.
 * It's crucial for making your programs robust, preventing crashes, and providing a smooth
 * experience for the user, much like a well-designed API prevents malformed requests.
 *
 * @param prompt A friendly message (string) to display to the user, telling them what
 * kind of number you're expecting. For instance, "Enter a temperature: ".
 * This 'prompt' is like the clear instructions on a sophisticated machine's control panel.
 * @return The valid double value successfully entered by the user. This is the clean,
 * verified data that your program can now safely use.
 */
double get_double_input(const char* prompt) {
    double value; // This variable is our designated 'landing spot' for the number the user types.

    // First, we politely ask the user for their input.
    // Think of this as displaying a clear sign at an information kiosk.
    printf("%s", prompt);

    /*
     * 🚧 The Input Validation Loop: Our Digital Bouncer 🚧
     *
     * This 'while' loop is the heart of our input validation. It's like a bouncer at an exclusive club
     * (your program) checking IDs (the user's input). The bouncer's job is to ensure only valid
     * guests (correct numbers) get in. If someone tries to sneak in a non-numeric string (like "hello"
     * instead of "12.3"), the bouncer sends them back to the end of the line with a polite but firm
     * "Invalid input!" message.
     *
     * `scanf("%lf", &value)`:
     * - `scanf` is like the ID scanner. It tries to read a double-precision floating-point number (`%lf`).
     * - `&value` tells `scanf` *where* to store the number if it successfully reads one. It's like
     * pointing to the specific spot on the ID where the bouncer expects to see the age.
     * - The `!= 1` part is critical. `scanf` returns the number of items it successfully read.
     * If it successfully reads *one* double, it returns `1`. If it *fails* to read a double
     * (because the user typed text, for example), it returns `0`. So, `!= 1` means "if `scanf`
     * did NOT successfully read exactly one double, then something went wrong, and we need to loop again."
     */
    while (scanf("%lf", &value) != 1) {
        // Uh oh, invalid input detected!
        // This is our bouncer politely, but firmly, saying, "Sorry, your ID isn't valid here."
        printf("Invalid input. Please enter a number: ");
        
        /*
         * 🗑️ The Input Buffer Cleaner: Sweeping Up the Mess 🧹
         *
         * When a user types invalid input (like "hello" and then presses Enter), `scanf` reads "hello",
         * realizes it's not a number, and stops. But "hello" and the newline character ('\n')
         * from the Enter key *remain* in the keyboard's input buffer.
         *
         * If we don't clear this buffer, the *next* time `scanf` tries to read input, it will immediately
         * find "hello" again, fail again, and enter an infinite loop of "Invalid input." messages.
         *
         * `clear_input_buffer()` is like a diligent janitor. It goes into the input buffer
         * (which is conceptually like a waiting room for characters typed by the user) and
         * flushes out all the junk characters until it finds a newline character (`\n`) or
         * the end of the input stream. This ensures that `scanf` gets a fresh start on the next loop iteration.
         *
         * In reverse engineering, understanding how input buffers are handled (or mishandled!)
         * is key to finding vulnerabilities like buffer overflows or format string bugs.
         * This little function prevents such common pitfalls.
         */
        clear_input_buffer(); // Crucial: clear out the problematic input so scanf doesn't get stuck.
    }

    // After the valid number is read, there's often a lingering newline character ('\n')
    // in the buffer from the user pressing Enter. We clear it once more to prevent it
    // from affecting subsequent `scanf` or `fgets` calls later in the program.
    // It's like tidying up your workspace after a successful operation.
    clear_input_buffer(); 

    // Mission accomplished! We've got a clean, valid number.
    // Hand it over to the caller.
    return value;
}

/**
 * @brief Clears the standard input buffer.
 *
 * This function drains any leftover characters from the keyboard's input buffer,
 * specifically up to and including the newline character, or until the end of the file.
 * It's often used after `scanf` calls to prevent unexpected behavior in subsequent
 * input operations, especially when mixing `scanf` with `fgets` or when
 * dealing with invalid numeric input that leaves non-numeric characters behind.
 *
 * Imagine the input buffer as a conveyor belt carrying characters from your keyboard.
 * This function is like a sweep arm that pushes everything off the belt until it hits
 * the end marker (the newline character from hitting Enter, or the end of the belt itself).
 */
void clear_input_buffer() {
    int c; // 'c' will hold each character we read from the buffer.
    // Loop through the input stream, reading character by character.
    // `getchar()` reads one character at a time.
    // We continue as long as 'c' is not the newline character ('\n') AND
    // we haven't reached the end of the input stream (EOF - End Of File, a special marker).
    while ((c = getchar()) != '\n' && c != EOF) {
        // We don't do anything with 'c' here; we just read it and discard it.
        // It's like picking up litter and immediately throwing it away.
        // This loop effectively 'consumes' all the junk data.
    }
}

// Example usage:
int main() {
    double temp = get_double_input("Enter the current temperature in Celsius: ");
    printf("You entered a temperature of %.2f degrees Celsius.\n", temp);

    double price = get_double_input("Enter the price of an item: $");
    printf("The item costs $%.2f.\n", price);

    double pi_val = get_double_input("What's your best approximation for Pi? ");
    printf("Your Pi approximation: %.5f\n", pi_val);

    printf("\nInput handling mission complete! You've mastered robust user interaction.\n");

    return 0;
}

//🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢🟢



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
