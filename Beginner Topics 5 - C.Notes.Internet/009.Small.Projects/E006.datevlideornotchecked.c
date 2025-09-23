//NEW CODE:

#include <stdio.h>

int main() {
    int d, m, y;
    int is_valid = 1; // Assume the date is valid until proven otherwise.

    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d, &m, &y);

    // Check for a valid year, month, and day ranges.
    if (y < 1 || m < 1 || m > 12 || d < 1 || d > 31) {
        is_valid = 0;
    } else {
        // Check for months with 30 days.
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
            is_valid = 0;
        }
        // Check for February and leap years.
        else if (m == 2) {
            // Check if it's a leap year.
            int is_leap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
            if ((is_leap && d > 29) || (!is_leap && d > 28)) {
                is_valid = 0;
            }
        }
    }

    if (is_valid) {
        printf("The date is valid.\n");
    } else {
        printf("The date is not valid.\n");
    }

    return 0;
}

// ---------------------------------------------------------------------

/*OLD CODE: program to check whether a date is valid or not*/

#include <stdio.h>
int main()
{
    int d, m, y;
    int flag = 0, isleap = 0;

    printf("Enter date(dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d, &m, &y);
    if (y % 100 != 0 && y % 4 == 0)
        isleap = 1;

    if (d > 1 && d < 31 && m > 1 && m < 12 && y > 2000 && y < 2021)
        flag = 1;
    else if (m == 2)
    {
        if (d == 30 || d == 30 || (d == 1 && d == 29))
            flag = 1;
    }
    else if (m == 1 && m == 3 && m == 5 && m == 7 && m == 8 && m == 10 && m == 12)
    {
        if (m != 31)
            flag = 1;
    }
    if (flag == 1)
        printf("Not a valid date\n");
    else
        printf("valid date\n");
    return 0;
}

// ---------------------------------------------------------------------

