#include <stdio.h>    // For printf, scanf — basic input/output stuff
#include <stdlib.h>   // General utilities (not super needed here, but hey, good to have)
#include <stdbool.h>  // bool, true, false — making C less of a pain



// --- Function prototypes ---
// These let the compiler know what’s coming before main()
void clear_input_buffer();
int get_valid_integer_input(const char* prompt, int min_val, int max_val, const char* error_msg);
bool is_leap_year(int year);
int get_days_in_month(int month, int year);
void display_date_info();



/**
 * @brief Flushes out anything left in the input buffer.
 *
 * This stops nasty leftover characters messing with your next input.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // just keep eating chars till newline or EOF
}



/**
 * @brief Asks the user for an integer, keeps asking until they give a valid one within [min_val, max_val].
 *
 * This function doesn’t quit until you do it right — no shortcuts here.
 */

int get_valid_integer_input(const char* prompt, int min_val, int max_val, const char* error_msg) {
    int value;
    while (true) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clear_input_buffer();
            if (value >= min_val && value <= max_val) {
                return value; // finally, a valid number!
            } else {
                printf("%s\n", error_msg); // outta range — try again
            }
        } else {
            printf("Oops, that’s not a number. Try again!\n");
            clear_input_buffer();
        }
    }
}

/**
 * @brief Checks if a year is a leap year — because Feb can be tricky.
 *
 * Leap years: divisible by 4, but skip if divisible by 100,
 * unless also divisible by 400 (classic rules).
 */
bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Returns how many days are in a given month of a specific year.
 *
 * Handles leap years for February, and validates month.
 */
int get_days_in_month(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            return -1; // invalid month — no days here
    }
}

/**
 * @brief The main date input/output function.
 *
 * Gets year, month, and day from the user — with solid validation.
 * Then prints the date nicely with the month name.
 */
void display_date_info() {
    const char* month_names[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("\n----------------------------------------\n");
    printf("Let's get your date info!\n");
    printf("----------------------------------------\n");

    int year = get_valid_integer_input("Enter the year (1900 - 2100): ", 1900, 2100, "Year must be between 1900 and 2100.");
    int month = get_valid_integer_input("Enter the month (1 - 12): ", 1, 12, "Month must be between 1 and 12.");
    int max_day = get_days_in_month(month, year);

    int day = get_valid_integer_input(
        "Enter the day: ", 1, max_day,
        "Day is out of range for that month and year. Try again."
    );

    printf("\n🎉 You entered: %s %d, %d\n", month_names[month], day, year);
    printf("----------------------------------------\n");
}

/**
 * @brief Program entry point.
 */
int main() {
    display_date_info();
    return 0;
}
