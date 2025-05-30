#include <stdio.h>   // For input/output functions like printf, scanf
#include <stdlib.h>  // For general utilities (e.g., exit)
#include <math.h>    // For pow() and isinf()
#include <limits.h>  // For LLONG_MIN, LLONG_MAX

// --- Function Prototypes ---
void clear_input_buffer();

/**
 * @brief Clears the standard input buffer.
 *
 * Reads and discards characters from stdin until a newline or EOF.
 * Prevents leftover characters from affecting subsequent input calls.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Main function to calculate power and check for infinity.
 *
 * This program demonstrates using 'long long int' for large numbers,
 * calculates powers using 'pow()', and checks for infinite results
 * using 'isinf()' from <math.h>.
 */
int main()
{
    long long int base;     // Base number for power calculation
    long long int exponent; // Exponent for power calculation
    double result_power;    // Stores the result of pow(), which is a double

    // Display the min/max values for long long int from <limits.h>
    printf("The minimum value for long long int is: %lld\n", LLONG_MIN);
    printf("The maximum value for long long int is: %lld\n", LLONG_MAX);
    printf("\n");

    printf("-----------------------------------\n");
    printf("Power Calculator (Enter 0 for base to exit)\n");
    printf("-----------------------------------\n");

    // Loop indefinitely until user decides to exit
    while (1) {
        printf("Enter the base number: ");
        // Read base. Check for valid input.
        if (scanf("%lld", &base) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue; // Skip to next loop iteration
        }
        clear_input_buffer(); // Clear leftover newline

        // Exit condition: if base is 0, quit the program.
        if (base == 0) {
            printf("Exiting power calculator. Goodbye!\n");
            break; // Exit the loop
        }

        printf("Enter the exponent: ");
        // Read exponent. Check for valid input.
        if (scanf("%lld", &exponent) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue; // Skip to next loop iteration
        }
        clear_input_buffer(); // Clear leftover newline

        // Calculate power using pow() function.
        // pow() takes doubles and returns a double.
        result_power = pow((double)base, (double)exponent);

        // Check if the result is infinite using isinf().
        // isinf() returns a non-zero value if the argument is positive or negative infinity.
        if (isinf(result_power)) {
            printf("Result is too large (infinite) to be precisely represented.\n");
        } else {
            // Print the result if it's not infinite.
            // Use %lf for double.
            printf("The power is: %lf\n", result_power);
        }
        printf("\n"); // Add a newline for better spacing between calculations
    }

    return 0; // Program exits here
}
