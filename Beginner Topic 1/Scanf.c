#include <stdio.h>   // For input/output functions like printf, scanf
#include <stdlib.h>  // For general utilities (not strictly needed here but good practice)
#include <stdbool.h> // For boolean type (true/false)

// --- Function Prototypes ---
// Declare functions before main so the compiler knows about them.
void clear_input_buffer();
int get_valid_integer_input(const char* prompt, int min_val, int max_val, const char* error_msg);
bool is_leap_year(int year);
int get_days_in_month(int month, int year);
void display_date_info();

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
 * @brief Prompts the user for an integer and validates it within a range.
 *
 * Loops until valid input (an integer within the specified min and max) is provided.
 */
int get_valid_integer_input(const char* prompt, int min_val, int max_val, const char* error_msg) {
    int value;
    while (true) { // Loop indefinitely until valid input
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) { // Successfully read an integer
            clear_input_buffer(); // Clear remaining input on the line
            if (value >= min_val && value <= max_val) {
                return value; // Valid input, return it
            } else {
                printf("%s\n", error_msg); // Display range error
            }
        } else { // scanf failed to read an integer
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer(); // Clear the invalid input
        }
    }
}

/**
 * @brief Checks if a given year is a leap year.
 *
 * @param year The year to check.
 * @return true if it's a leap year, false otherwise.
 */
bool is_leap_year(int year) {
    // Leap year rules: divisible by 4, but not by 100 unless also by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Calculates the number of days in a given month for a specific year.
 *
 * @param month The month (1-12).
 * @param year The year.
 * @return The number of days in the month, or -1 if month is invalid.
 */
int get_days_in_month(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: // February
            return is_leap_year(year) ? 29 : 28;
        default:
            return -1; // Invalid month
    }
}

/**
 * @brief Prompts the user for a date (day, month, year) and displays it.
 *
 * Includes robust input validation and handles leap years for day validation.
 */
void display_date_info() {
    // Array of month names (index 0 unused, for 1-based month numbers)
    const char* month_names[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int year;
    int month;
    int day;
    int max_day_for_month;

    printf("\n-----------------------------------\n");
    printf("Enter Date Information\n");
    printf("-----------------------------------\n");

    year = get_valid_integer_input("Enter the year (e.g., 2025): ", 1900, 2100, "Year must be between 1900 and 2100.");
    month = get_valid_integer_input("Enter the month (1-12): ", 1, 12, "Month must be between 1 and 12.");

    // Calculate max days for the entered month and year for precise day validation
    max_day_for_month = get_days_in_month(month, year);
    day = get_valid_integer_input("Enter the day (1-31): ", 1, max_day_for_month, "Day is invalid for the selected month/year.");

    printf("\nToday is %s %d, %d.\n", month_names[month], day, year);
    printf("-----------------------------------\n");
}

/**
 * @brief Main function to run the date information program.
 */
int main() {
    display_date_info(); // Call the function to get and display date
    return 0; // Indicate successful program termination
}
