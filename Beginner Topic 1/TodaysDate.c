#include <stdio.h> // For input/output functions like printf
#include <time.h>  // For time-related functions (time, localtime, time_t, struct tm)

/**
 * @brief Main function to get and display the current local date.
 *
 * This program uses functions from the <time.h> library to retrieve the
 * current system time and format it into a readable date string.
 */
int main()
{
    time_t currentTime;       // Stores the current calendar time (seconds since epoch)
    struct tm *localTime;     // Pointer to a structure holding broken-down time components

    // Get the current time in seconds since the Epoch (Jan 1, 1970).
    currentTime = time(NULL);

    // Convert the calendar time to a local time structure.
    // This populates 'localTime' with year, month, day, hour, minute, second, etc.
    localTime = localtime(&currentTime);

    // Extract day, month, and year components from the 'struct tm'.
    // tm_mday: Day of the month (1-31)
    // tm_mon: Month (0-11, so add 1 for 1-12)
    // tm_year: Years since 1900 (so add 1900 to get actual year)
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;

    // Print the formatted date as MM/DD/YYYY.
    // %02d ensures two digits with leading zero if needed (e.g., 01 for January).
    // %04d ensures four digits for the year.
    printf("Today's date is: %02d/%02d/%04d\n", month, day, year);

    return 0; // Indicates successful program execution
}
